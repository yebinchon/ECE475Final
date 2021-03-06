// Modified by Princeton University on June 9th, 2015
// ========== Copyright Header Begin ==========================================
//
// OpenSPARC T1 Processor File: bw_r_dct.v
// Copyright (c) 2006 Sun Microsystems, Inc.  All Rights Reserved.
// DO NOT ALTER OR REMOVE COPYRIGHT NOTICES.
//
// The above named program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public
// License version 2 as published by the Free Software Foundation.
//
// The above named program is distributed in the hope that it will be
// useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public
// License along with this work; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
//
// ========== Copyright Header End ============================================
////////////////////////////////////////////////////////////////////////
/*
 //  Module Name:  bw_r_dct.v
 //  Description:
 //    Contains the RTL for the icache and dcache tag blocks.
 //    This is a 1RW 512 entry X 33b macro, with 132b rd and 132b wr,
 //    broken into 4 33b segments with its own write enable.
 //    Address and Control inputs are available the stage before
 //    array access, which is referred to as "_x".  Write data is
 //    available in the same stage as the write to the ram, referred
 //    to as "_y".  Read data is also read out and available in "_y".
 //
 //            X       |      Y
 //     index          |  ram access
 //     index sel      |  write_tag
 //     rd/wr req      |     -> read_tag
 //     way enable     |
 */

// /home/aning/ta_ece475/openpiton/piton/verif/env/manycore/devices.xml



////////////////////////////////////////////////////////////////////////
// Local header file includes / local defines
////////////////////////////////////////////////////////////////////////

`ifdef SIM_FPGA_SYN_SRAM_DCACHE_TAG // simulation flag
`define PITON_PROTO
`endif

`ifdef FPGA_FORCE_SRAM_DCACHE_TAG
`undef PITON_PROTO
`endif

//PITON_PROTO enables all FPGA related modifications
`ifdef PITON_PROTO
`define FPGA_SYN_DCT
`else
`define SRAM_DCACHE_TAG
`endif

`ifdef FPGA_SYN_DCT

module bw_r_dct(
  // rdtag_w0_y, rdtag_w1_y, rdtag_w2_y, rdtag_w3_y, 
  rdtag_y, so, rclk, se,
//`else
//module bw_r_dct_orig(rdtag_w0_y, rdtag_w1_y, rdtag_w2_y, rdtag_w3_y, so, rclk, se,
//`endif
   si, reset_l, sehold, rst_tri_en, index0_x, index1_x, index_sel_x,
   dec_wrway_x, rdreq_x, wrreq_x, 
  // wrtag_w0_y, wrtag_w1_y, wrtag_w2_y,
   // wrtag_w3_y, wrtag_w0_x, wrtag_w1_x, wrtag_w2_x,
  // wrtag_w3_x, 

  wrtag_x, wrtag_y,
  adj,

  // sram wrapper interface
  sramid,
  srams_rtap_data,
  rtap_srams_bist_command,
  rtap_srams_bist_data
  );

   input       rclk;
   input       se;
   input       si;
   input       reset_l;
   input       sehold;
   input       rst_tri_en;
   input [`L1D_SET_IDX_MASK]     index0_x;
   input [`L1D_SET_IDX_MASK]     index1_x;
   input       index_sel_x;
   input [`L1D_WAY_COUNT-1:0]    dec_wrway_x;
   input       rdreq_x;
   input       wrreq_x;
   input [`L1D_TAG_REAL_WIDTH-1:0]      wrtag_y;
  input [`L1D_TAG_REAL_WIDTH-1:0]    wrtag_x;
   input [`L1D_WAY_COUNT-1:0]    adj;

  // sram wrapper interface
  output [`SRAM_WRAPPER_BUS_WIDTH-1:0] srams_rtap_data;
  // dummy output for the reference model
  assign srams_rtap_data = 4'b0;
  input  [`BIST_OP_WIDTH-1:0] rtap_srams_bist_command;
  input  [`SRAM_WRAPPER_BUS_WIDTH-1:0] rtap_srams_bist_data;
  input  [`BIST_ID_WIDTH-1:0] sramid;
  wire unused = rtap_srams_bist_command
                | rtap_srams_bist_data
                | sramid;

   wire   [`L1D_TAG_REAL_WIDTH-1:0]      rdtag_w0_y;
   wire   [`L1D_TAG_REAL_WIDTH-1:0]      rdtag_w1_y;
   wire   [`L1D_TAG_REAL_WIDTH-1:0]      rdtag_w2_y;
   wire   [`L1D_TAG_REAL_WIDTH-1:0]      rdtag_w3_y;
  output  [`L1D_TAG_ARRAY_REAL_WIDTH-1:0]    rdtag_y;
   output         so;

   wire        clk;
   reg   [`L1D_SET_IDX_MASK]     index_y;
   reg         rdreq_y;
   reg         wrreq_y;
   reg   [`L1D_WAY_COUNT-1:0]    dec_wrway_y;
   wire  [`L1D_SET_IDX_MASK]     index_x;
   wire  [`L1D_WAY_COUNT-1:0]    we;

      reg [131:0]  rdtag_sa_y; //for error_inject XMR

   assign clk = rclk;
   assign index_x = (index_sel_x ? index1_x : index0_x);
    assign we = ({4 {((wrreq_y & reset_l) & (~rst_tri_en))}} & dec_wrway_y);

   always @(posedge clk) begin
     if (~sehold) begin
       rdreq_y <= rdreq_x;
       wrreq_y <= wrreq_x;
       index_y <= index_x;
       dec_wrway_y <= dec_wrway_x;
     end
   end

  // trin: used?
   bw_r_dct_array ictag_ary_00(
      .we   (we[0]),
      .clk  (clk),
        .way (2'b00),
      .rd_data(rdtag_w0_y),
      .wr_data(wrtag_y),
      .addr (index_y),
        .dec_wrway_y (dec_wrway_y));

   bw_r_dct_array ictag_ary_01(
      .we   (we[1]),
      .clk  (clk),
        .way (2'b01),
      .rd_data(rdtag_w1_y),
      .wr_data(wrtag_y),
      .addr (index_y),
        .dec_wrway_y (dec_wrway_y));

   bw_r_dct_array ictag_ary_10(
      .we   (we[2]),
      .clk  (clk),
        .way(2'b10),
      .rd_data(rdtag_w2_y),
      .wr_data(wrtag_y),
      .addr (index_y),
        .dec_wrway_y (dec_wrway_y));

   bw_r_dct_array ictag_ary_11(
      .we   (we[3]),
      .clk  (clk),
        .way(2'b11),
      .rd_data(rdtag_w3_y),
      .wr_data(wrtag_y),
      .addr (index_y),
        .dec_wrway_y (dec_wrway_y));

   assign rdtag_y = {rdtag_w3_y,rdtag_w2_y,rdtag_w1_y,rdtag_w0_y};
endmodule

module bw_r_dct_array(we, clk, rd_data, wr_data, addr,dec_wrway_y,way);

input we;
input clk;
input [`L1D_TAG_REAL_WIDTH-1:0] wr_data;
input [`L1D_SET_IDX_MASK] addr;
input [`L1D_WAY_COUNT-1:0] dec_wrway_y;
input [1:0] way;
output [`L1D_TAG_REAL_WIDTH-1:0] rd_data;
reg [`L1D_TAG_REAL_WIDTH-1:0] rd_data;

reg   [`L1D_TAG_REAL_WIDTH-1:0]      array[511:0] /* synthesis syn_ramstyle = block_ram  syn_ramstyle = no_rw_check */ ;
integer i;

initial begin
// `ifdef DO_MEM_INIT
//     // Add the memory init file in the database
//     $readmemb("/import/dtg-data11/sandeep/niagara/design/sys/iop/srams/rtl/mem_init_dct.txt",array);
// `endif
  // Tri: nonsynthesizable
  for (i = 0; i < 511; i = i + 1)
  begin
    array[i] = 33'b0;
  end
end

   always @(negedge clk) begin
     if (we)
          begin
              array[addr] <= wr_data;
          end
     else
          rd_data <= array[addr];
   end
endmodule

`endif

`ifdef SRAM_DCACHE_TAG
module bw_r_dct(
  // rdtag_w0_y, rdtag_w1_y, rdtag_w2_y, 
  rdtag_y, 
  // rdtag_w3_y, 
  so, rclk, se,
  si, reset_l, sehold, rst_tri_en, index0_x, index1_x, index_sel_x,
  dec_wrway_x, rdreq_x, wrreq_x, 

  wrtag_x, wrtag_y,
  // wrtag_w0_y, wrtag_w1_y, wrtag_w2_y,
  // wrtag_w3_y, wrtag_w0_x, wrtag_w1_x, wrtag_w2_x,
  // wrtag_w3_x, 
  adj,

  // sram wrapper interface
  sramid,
  srams_rtap_data,
  rtap_srams_bist_command,
  rtap_srams_bist_data
  );

  input     rclk;
  input     se;
  input     si;
  input     reset_l;
  input     sehold;
  input     rst_tri_en;
  input [`L1D_SET_IDX_MASK]   index0_x;
  input [`L1D_SET_IDX_MASK]   index1_x;
  input     index_sel_x;
  input [`L1D_WAY_COUNT-1:0]   dec_wrway_x;
  input     rdreq_x;
  input     wrreq_x;

  input [`L1D_TAG_REAL_WIDTH-1:0]    wrtag_y;
  input [`L1D_TAG_REAL_WIDTH-1:0]    wrtag_x;
  input [`L1D_WAY_COUNT-1:0]   adj;


  // sram wrapper interface
  output [`SRAM_WRAPPER_BUS_WIDTH-1:0] srams_rtap_data;
  input  [`BIST_OP_WIDTH-1:0] rtap_srams_bist_command;
  input  [`SRAM_WRAPPER_BUS_WIDTH-1:0] rtap_srams_bist_data;
  input  [`BIST_ID_WIDTH-1:0] sramid;

  output  [`L1D_TAG_ARRAY_REAL_WIDTH-1:0]    rdtag_y;
  output      so;

  wire      clk;
  wire  [`L1D_SET_IDX_MASK]   index_x;
  reg   [`L1D_SET_IDX_MASK]   index_y;
  wire  [`L1D_WAY_COUNT-1:0]   we;
  reg           wrreq_y;
  reg           rdreq_y;

  reg [131:0]  rdtag_sa_y; //for error_inject XMR

  assign clk = rclk;
  assign index_x = (index_sel_x ? index1_x : index0_x);
  assign we = ({`L1D_WAY_COUNT {((wrreq_x & reset_l) & (~rst_tri_en))}} & dec_wrway_x);

  // wire [131:0] write_bus_x = {wrtag_x,wrtag_x,wrtag_x,wrtag_x};
  // wire [131:0] write_bus_mask_x = {{33{we[3]}}, {33{we[2]}}, {33{we[1]}}, {33{we[0]}}};

  wire [`L1D_TAG_REAL_WIDTH*`L1D_WAY_COUNT-1:0] write_bus_x = {`L1D_WAY_COUNT{wrtag_x}};
  wire [`L1D_TAG_REAL_WIDTH*`L1D_WAY_COUNT-1:0] write_bus_mask_x;
  
  assign write_bus_mask_x[`L1D_TAG_REAL_ARRAY_WAY0_MASK] = {`L1D_TAG_REAL_WIDTH{we[0]}};


  assign write_bus_mask_x[`L1D_TAG_REAL_ARRAY_WAY1_MASK] = {`L1D_TAG_REAL_WIDTH{we[1]}};


  assign write_bus_mask_x[`L1D_TAG_REAL_ARRAY_WAY2_MASK] = {`L1D_TAG_REAL_WIDTH{we[2]}};


  assign write_bus_mask_x[`L1D_TAG_REAL_ARRAY_WAY3_MASK] = {`L1D_TAG_REAL_WIDTH{we[3]}};




  always @ (posedge rclk)
  begin
    index_y <= index_x;
    wrreq_y <= wrreq_x;
    rdreq_y <= rdreq_x;
  end

  wire  [`L1D_TAG_ARRAY_REAL_WIDTH-1:0]    rdtag_y;

sram_l1d_tag cache
(
  .MEMCLK(rclk),
    .RESET_N(reset_l),
  .CE(wrreq_x | rdreq_x),
  .A(index_x),
  .DIN(write_bus_x),
  .BW(write_bus_mask_x),
  .RDWEN(~wrreq_x),
  .DOUT(rdtag_y),

  // .BIST_COMMAND(rtap_srams_bist_command),
  // .BIST_DIN(rtap_srams_bist_data),
  // .BIST_DOUT(sram_dcache_w01_rtap_data),
  // .SRAMID(`BIST_ID_L1_DCACHE_W01)
  .BIST_COMMAND(rtap_srams_bist_command),
  .BIST_DIN(rtap_srams_bist_data),
  .BIST_DOUT(srams_rtap_data),
  .SRAMID(sramid)
);

  // assign rdtag_y = {rdtag_w3_y, rdtag_w2_y, rdtag_w1_y, rdtag_w0_y};




endmodule

`endif // IBM TAG

`ifdef SIM_FPGA_SYN_SRAM_DCACHE_TAG // simulation flag
`undef PITON_PROTO
`endif

`ifdef FPGA_FORCE_SRAM_DCACHE_TAG
`define PITON_PROTO
`endif

