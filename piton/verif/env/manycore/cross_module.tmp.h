// Modified by Princeton University on June 9th, 2015
/*
* ========== Copyright Header Begin ==========================================
*
* OpenSPARC T1 Processor File: cross_module.h
* Copyright (c) 2006 Sun Microsystems, Inc.  All Rights Reserved.
* DO NOT ALTER OR REMOVE COPYRIGHT NOTICES.
*
* The above named program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public
* License version 2 as published by the Free Software Foundation.
*
* The above named program is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
* General Public License for more details.
*
* You should have received a copy of the GNU General Public
* License along with this work; if not, write to the Free Software
* Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
*
* ========== Copyright Header End ============================================
*/

`ifndef CROSS_MODULE_H
`define CROSS_MODULE_H



`define MONITOR_SIGNAL                 155
`define FLOAT_X                        154
`define FLOAT_I                        153
`define REG_WRITE_BACK                 152
`define PLI_QUIT                1    /* None */
`define PLI_SSTEP               2    /* %1 th id */
`define PLI_READ_TH_REG         3    /* %1 th id, %2 win num, %3 reg num */
`define PLI_READ_TH_CTL_REG     4    /* %1 th id, %2 reg num */
`define PLI_READ_TH_FP_REG_I    5    /* %1 th id, %2 reg num */
`define PLI_READ_TH_FP_REG_X    6    /* %1 th id, %2 reg num */
`define PLI_RTL_DATA            7
`define PLI_RTL_CYCLE           8
`define PLI_WRITE_TH_XCC_REG    9
`define PLI_FORCE_TRAP_TYPE            15
`define PLI_RESET_TLB_ENTRY     16
`define PLI_RETRY               30
`define PLI_WRITE_TH_REG_HI     10
`define PLI_WRITE_TH_REG        11
`define PLI_WRITE_TH_CTL_REG    12    /* %1 th id, %2 reg num, %3-%10 value */
`define CMD_BUFSIZE 10240

//define all cross module

// trin: defines for jtag test bench

`ifdef JTAG_TB_XMODULE
    `define TOP_MOD     jtag_testbench_top.helper
    `define SIM_TOP     jtag_testbench_top.helper
    `define TOP_MOD_INST `TOP_MOD
`else
    `define TOP_MOD     cmp_top
    `define SIM_TOP     cmp_top
    `define TOP_MOD_INST `TOP_MOD.system
// TODO: Alexey: use PITON_PROTO define ?
//`define TOP_MOD      fpga_top.cmp_top
`endif

//`define SIM_TOP fpga_top.cmp_top

    // `define TOP_SHELL    cmp_top_shell
`define CHIP         `TOP_MOD_INST.chip
`define CHIP_INT_CLK `CHIP.clk_muxed
`define TOP_DESIGN   `TOP_MOD.chip
`define FAKE_IOB     `TOP_MOD.system.chipset.chipset_impl.ciop_fake_iob
// `define TOP_MEMORY   `TOP_MOD.cmp

`define JTAG_CTAP    `CHIP.jtag_port.ctap
`define MONITOR_PATH `TOP_MOD.monitor
`define PC_CMP       `TOP_MOD.monitor.pc_cmp
`define SAS_SEND     `TOP_MOD.sas_tasks.send_cmd
`define SAS_DEF      `TOP_MOD.sas_tasks.sas_def
`define SAS_TASKS    `TOP_MOD.sas_tasks
`define CPX_INVALID_TIME 1000

// Note that the belows were generated through the template file and pyhp


    `define TILE0            `CHIP.tile0
    `define ARIANE_CORE0     `TILE0.g_ariane_core.core.ariane
    `define SPARC_CORE0      `TILE0.g_sparc_core.core
    `define PICO_CORE0       `TILE0.g_picorv32_core.core
    `define CCX_TRANSDUCER0  `TILE0.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER0 `TILE0.g_picorv32_core.pico_l15_transducer
    `define L15_TOP0         `TILE0.l15.l15
    `define L15_PIPE0        `TILE0.l15.l15.pipeline
    `define DMBR0            `TILE0.dmbr_ins
    `define L2_TOP0          `TILE0.l2
    `define SPARC_REG0       `SPARC_CORE0.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH0       `SPARC_CORE0.sparc0.ffu.ffu
`else
    `define FLOATPATH0       `SPARC_CORE0.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH0         `SPARC_CORE0.sparc0.tlu.tlu
    `define DTLBPATH0        `SPARC_CORE0.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH0         `SPARC_CORE0.sparc0.tlu
    `define DTLBPATH0        `SPARC_CORE0.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH0         `SPARC_CORE0.sparc0
`ifndef RTL_SPU
    `define ICVPATH0         `SPARC_CORE0.sparc0.ifu.ifu.icv
    `define IFUPATH0         `SPARC_CORE0.sparc0.ifu.ifu
    `define TNUM0S           `SPARC_CORE0.sparc0.ifu.ifu.swl
    `define TPC0S            `SPARC_CORE0.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH0         `SPARC_CORE0.sparc0.ifu.icv
    `define IFUPATH0         `SPARC_CORE0.sparc0.ifu
    `define TNUM0S           `SPARC_CORE0.sparc0.ifu.swl
    `define TPC0S            `SPARC_CORE0.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH0         `SPARC_CORE0.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH0         `SPARC_CORE0.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH0         `SPARC_CORE0.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH0         `SPARC_CORE0.sparc0.ifu.fdp
`endif
    `define ALUPATH0         `SPARC_CORE0.sparc0.exu.exu.alu
    `define SPCPATH0         `SPARC_CORE0.sparc0
    `define REGPATH0         `SPARC_CORE0.sparc0.exu.exu.irf.irf
    `define CCRPATH0         `SPARC_CORE0.sparc0.exu.exu.ecl.ccr
    `define EXUPATH0         `SPARC_CORE0.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH0          `SPARC_CORE0.sparc0.tlu.tlu.tcl
    `define TS0PATH0         `SPARC_CORE0.sparc0.tlu.tlu.tsa0
    `define TS1PATH0         `SPARC_CORE0.sparc0.tlu.tlu.tsa1
    `define INTPATH0         `SPARC_CORE0.sparc0.tlu.tlu.intdp
    `define ASIPATH0         `SPARC_CORE0.sparc0.lsu.lsu.dctl
    `define ASIDPPATH0       `SPARC_CORE0.sparc0.lsu.lsu.dctldp
    `define ICTPATH0         `SPARC_CORE0.sparc0.ifu.ifu.ict
    `define DCACHE0          `SPARC_CORE0.sparc0.lsu.lsu.dcache
    `define INSTPATH0        `SPARC_CORE0.sparc0.ifu.ifu.fcl
    `define PCPATH0          `SPARC_CORE0.sparc0.ifu.ifu
    `define DVLD0            `SPARC_CORE0.sparc0.lsu.lsu.dva
    `define DTAG0            `SPARC_CORE0.sparc0.lsu.lsu.dtag
    `define SDTAG0           `SPARC_CORE0.sparc0.lsu.lsu.dtag
    `define SDVLD0           `SPARC_CORE0.sparc0.lsu.lsu.dva
    `define FFUPATH0         `SPARC_CORE0.sparc0.ffu.ffu
    `define TLU_HYPER0       `SPARC_CORE0.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP0           `SPARC_CORE0.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH0        `SPARC_CORE0.sparc0.ifu.ifu.itlb
`else
    `define TLPATH0          `SPARC_CORE0.sparc0.tlu.tcl
    `define TS0PATH0         `SPARC_CORE0.sparc0.tlu.tsa0
    `define TS1PATH0         `SPARC_CORE0.sparc0.tlu.tsa1
    `define INTPATH0         `SPARC_CORE0.sparc0.tlu.intdp
    `define ASIPATH0         `SPARC_CORE0.sparc0.lsu.dctl
    `define ASIDPPATH0       `SPARC_CORE0.sparc0.lsu.dctldp
    `define ICTPATH0         `SPARC_CORE0.sparc0.ifu.ict
    `define DCACHE0          `SPARC_CORE0.sparc0.lsu.dcache
    `define INSTPATH0        `SPARC_CORE0.sparc0.ifu.fcl
    `define PCPATH0          `SPARC_CORE0.sparc0.ifu
    `define DVLD0            `SPARC_CORE0.sparc0.lsu.dva
    `define DTAG0            `SPARC_CORE0.sparc0.lsu.dtag
    `define SDTAG0           `SPARC_CORE0.sparc0.lsu.dtag
    `define SDVLD0           `SPARC_CORE0.sparc0.lsu.dva
    `define FFUPATH0         `SPARC_CORE0.sparc0.ffu
    `define TLU_HYPER0       `SPARC_CORE0.sparc0.tlu.tlu_hyperv
    `define IFQDP0           `SPARC_CORE0.sparc0.ifu.ifqdp
    `define ITLBPATH0        `SPARC_CORE0.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH0    `SPARC_CORE0.sparc0.cfg_asi

    `define PITON_CORE0_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc0_inst_done
`ifdef RTL_SPARC0
    `define PITON_CORE0_PC_W0     `PCPATH0.fdp.pc_w
`else
    `define PITON_CORE0_PC_W0     `TOP_MOD.monitor.pc_cmp.spc0_phy_pc_w
`endif

    

    `define TILE1            `CHIP.tile1
    `define ARIANE_CORE1     `TILE1.g_ariane_core.core.ariane
    `define SPARC_CORE1      `TILE1.g_sparc_core.core
    `define PICO_CORE1       `TILE1.g_picorv32_core.core
    `define CCX_TRANSDUCER1  `TILE1.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER1 `TILE1.g_picorv32_core.pico_l15_transducer
    `define L15_TOP1         `TILE1.l15.l15
    `define L15_PIPE1        `TILE1.l15.l15.pipeline
    `define DMBR1            `TILE1.dmbr_ins
    `define L2_TOP1          `TILE1.l2
    `define SPARC_REG1       `SPARC_CORE1.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH1       `SPARC_CORE1.sparc0.ffu.ffu
`else
    `define FLOATPATH1       `SPARC_CORE1.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH1         `SPARC_CORE1.sparc0.tlu.tlu
    `define DTLBPATH1        `SPARC_CORE1.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH1         `SPARC_CORE1.sparc0.tlu
    `define DTLBPATH1        `SPARC_CORE1.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH1         `SPARC_CORE1.sparc0
`ifndef RTL_SPU
    `define ICVPATH1         `SPARC_CORE1.sparc0.ifu.ifu.icv
    `define IFUPATH1         `SPARC_CORE1.sparc0.ifu.ifu
    `define TNUM1S           `SPARC_CORE1.sparc0.ifu.ifu.swl
    `define TPC1S            `SPARC_CORE1.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH1         `SPARC_CORE1.sparc0.ifu.icv
    `define IFUPATH1         `SPARC_CORE1.sparc0.ifu
    `define TNUM1S           `SPARC_CORE1.sparc0.ifu.swl
    `define TPC1S            `SPARC_CORE1.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH1         `SPARC_CORE1.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH1         `SPARC_CORE1.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH1         `SPARC_CORE1.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH1         `SPARC_CORE1.sparc0.ifu.fdp
`endif
    `define ALUPATH1         `SPARC_CORE1.sparc0.exu.exu.alu
    `define SPCPATH1         `SPARC_CORE1.sparc0
    `define REGPATH1         `SPARC_CORE1.sparc0.exu.exu.irf.irf
    `define CCRPATH1         `SPARC_CORE1.sparc0.exu.exu.ecl.ccr
    `define EXUPATH1         `SPARC_CORE1.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH1          `SPARC_CORE1.sparc0.tlu.tlu.tcl
    `define TS0PATH1         `SPARC_CORE1.sparc0.tlu.tlu.tsa0
    `define TS1PATH1         `SPARC_CORE1.sparc0.tlu.tlu.tsa1
    `define INTPATH1         `SPARC_CORE1.sparc0.tlu.tlu.intdp
    `define ASIPATH1         `SPARC_CORE1.sparc0.lsu.lsu.dctl
    `define ASIDPPATH1       `SPARC_CORE1.sparc0.lsu.lsu.dctldp
    `define ICTPATH1         `SPARC_CORE1.sparc0.ifu.ifu.ict
    `define DCACHE1          `SPARC_CORE1.sparc0.lsu.lsu.dcache
    `define INSTPATH1        `SPARC_CORE1.sparc0.ifu.ifu.fcl
    `define PCPATH1          `SPARC_CORE1.sparc0.ifu.ifu
    `define DVLD1            `SPARC_CORE1.sparc0.lsu.lsu.dva
    `define DTAG1            `SPARC_CORE1.sparc0.lsu.lsu.dtag
    `define SDTAG1           `SPARC_CORE1.sparc0.lsu.lsu.dtag
    `define SDVLD1           `SPARC_CORE1.sparc0.lsu.lsu.dva
    `define FFUPATH1         `SPARC_CORE1.sparc0.ffu.ffu
    `define TLU_HYPER1       `SPARC_CORE1.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP1           `SPARC_CORE1.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH1        `SPARC_CORE1.sparc0.ifu.ifu.itlb
`else
    `define TLPATH1          `SPARC_CORE1.sparc0.tlu.tcl
    `define TS0PATH1         `SPARC_CORE1.sparc0.tlu.tsa0
    `define TS1PATH1         `SPARC_CORE1.sparc0.tlu.tsa1
    `define INTPATH1         `SPARC_CORE1.sparc0.tlu.intdp
    `define ASIPATH1         `SPARC_CORE1.sparc0.lsu.dctl
    `define ASIDPPATH1       `SPARC_CORE1.sparc0.lsu.dctldp
    `define ICTPATH1         `SPARC_CORE1.sparc0.ifu.ict
    `define DCACHE1          `SPARC_CORE1.sparc0.lsu.dcache
    `define INSTPATH1        `SPARC_CORE1.sparc0.ifu.fcl
    `define PCPATH1          `SPARC_CORE1.sparc0.ifu
    `define DVLD1            `SPARC_CORE1.sparc0.lsu.dva
    `define DTAG1            `SPARC_CORE1.sparc0.lsu.dtag
    `define SDTAG1           `SPARC_CORE1.sparc0.lsu.dtag
    `define SDVLD1           `SPARC_CORE1.sparc0.lsu.dva
    `define FFUPATH1         `SPARC_CORE1.sparc0.ffu
    `define TLU_HYPER1       `SPARC_CORE1.sparc0.tlu.tlu_hyperv
    `define IFQDP1           `SPARC_CORE1.sparc0.ifu.ifqdp
    `define ITLBPATH1        `SPARC_CORE1.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH1    `SPARC_CORE1.sparc0.cfg_asi

    `define PITON_CORE1_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc1_inst_done
`ifdef RTL_SPARC1
    `define PITON_CORE1_PC_W1     `PCPATH1.fdp.pc_w
`else
    `define PITON_CORE1_PC_W1     `TOP_MOD.monitor.pc_cmp.spc1_phy_pc_w
`endif

    

    `define TILE2            `CHIP.tile2
    `define ARIANE_CORE2     `TILE2.g_ariane_core.core.ariane
    `define SPARC_CORE2      `TILE2.g_sparc_core.core
    `define PICO_CORE2       `TILE2.g_picorv32_core.core
    `define CCX_TRANSDUCER2  `TILE2.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER2 `TILE2.g_picorv32_core.pico_l15_transducer
    `define L15_TOP2         `TILE2.l15.l15
    `define L15_PIPE2        `TILE2.l15.l15.pipeline
    `define DMBR2            `TILE2.dmbr_ins
    `define L2_TOP2          `TILE2.l2
    `define SPARC_REG2       `SPARC_CORE2.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH2       `SPARC_CORE2.sparc0.ffu.ffu
`else
    `define FLOATPATH2       `SPARC_CORE2.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH2         `SPARC_CORE2.sparc0.tlu.tlu
    `define DTLBPATH2        `SPARC_CORE2.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH2         `SPARC_CORE2.sparc0.tlu
    `define DTLBPATH2        `SPARC_CORE2.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH2         `SPARC_CORE2.sparc0
`ifndef RTL_SPU
    `define ICVPATH2         `SPARC_CORE2.sparc0.ifu.ifu.icv
    `define IFUPATH2         `SPARC_CORE2.sparc0.ifu.ifu
    `define TNUM2S           `SPARC_CORE2.sparc0.ifu.ifu.swl
    `define TPC2S            `SPARC_CORE2.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH2         `SPARC_CORE2.sparc0.ifu.icv
    `define IFUPATH2         `SPARC_CORE2.sparc0.ifu
    `define TNUM2S           `SPARC_CORE2.sparc0.ifu.swl
    `define TPC2S            `SPARC_CORE2.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH2         `SPARC_CORE2.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH2         `SPARC_CORE2.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH2         `SPARC_CORE2.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH2         `SPARC_CORE2.sparc0.ifu.fdp
`endif
    `define ALUPATH2         `SPARC_CORE2.sparc0.exu.exu.alu
    `define SPCPATH2         `SPARC_CORE2.sparc0
    `define REGPATH2         `SPARC_CORE2.sparc0.exu.exu.irf.irf
    `define CCRPATH2         `SPARC_CORE2.sparc0.exu.exu.ecl.ccr
    `define EXUPATH2         `SPARC_CORE2.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH2          `SPARC_CORE2.sparc0.tlu.tlu.tcl
    `define TS0PATH2         `SPARC_CORE2.sparc0.tlu.tlu.tsa0
    `define TS1PATH2         `SPARC_CORE2.sparc0.tlu.tlu.tsa1
    `define INTPATH2         `SPARC_CORE2.sparc0.tlu.tlu.intdp
    `define ASIPATH2         `SPARC_CORE2.sparc0.lsu.lsu.dctl
    `define ASIDPPATH2       `SPARC_CORE2.sparc0.lsu.lsu.dctldp
    `define ICTPATH2         `SPARC_CORE2.sparc0.ifu.ifu.ict
    `define DCACHE2          `SPARC_CORE2.sparc0.lsu.lsu.dcache
    `define INSTPATH2        `SPARC_CORE2.sparc0.ifu.ifu.fcl
    `define PCPATH2          `SPARC_CORE2.sparc0.ifu.ifu
    `define DVLD2            `SPARC_CORE2.sparc0.lsu.lsu.dva
    `define DTAG2            `SPARC_CORE2.sparc0.lsu.lsu.dtag
    `define SDTAG2           `SPARC_CORE2.sparc0.lsu.lsu.dtag
    `define SDVLD2           `SPARC_CORE2.sparc0.lsu.lsu.dva
    `define FFUPATH2         `SPARC_CORE2.sparc0.ffu.ffu
    `define TLU_HYPER2       `SPARC_CORE2.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP2           `SPARC_CORE2.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH2        `SPARC_CORE2.sparc0.ifu.ifu.itlb
`else
    `define TLPATH2          `SPARC_CORE2.sparc0.tlu.tcl
    `define TS0PATH2         `SPARC_CORE2.sparc0.tlu.tsa0
    `define TS1PATH2         `SPARC_CORE2.sparc0.tlu.tsa1
    `define INTPATH2         `SPARC_CORE2.sparc0.tlu.intdp
    `define ASIPATH2         `SPARC_CORE2.sparc0.lsu.dctl
    `define ASIDPPATH2       `SPARC_CORE2.sparc0.lsu.dctldp
    `define ICTPATH2         `SPARC_CORE2.sparc0.ifu.ict
    `define DCACHE2          `SPARC_CORE2.sparc0.lsu.dcache
    `define INSTPATH2        `SPARC_CORE2.sparc0.ifu.fcl
    `define PCPATH2          `SPARC_CORE2.sparc0.ifu
    `define DVLD2            `SPARC_CORE2.sparc0.lsu.dva
    `define DTAG2            `SPARC_CORE2.sparc0.lsu.dtag
    `define SDTAG2           `SPARC_CORE2.sparc0.lsu.dtag
    `define SDVLD2           `SPARC_CORE2.sparc0.lsu.dva
    `define FFUPATH2         `SPARC_CORE2.sparc0.ffu
    `define TLU_HYPER2       `SPARC_CORE2.sparc0.tlu.tlu_hyperv
    `define IFQDP2           `SPARC_CORE2.sparc0.ifu.ifqdp
    `define ITLBPATH2        `SPARC_CORE2.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH2    `SPARC_CORE2.sparc0.cfg_asi

    `define PITON_CORE2_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc2_inst_done
`ifdef RTL_SPARC2
    `define PITON_CORE2_PC_W2     `PCPATH2.fdp.pc_w
`else
    `define PITON_CORE2_PC_W2     `TOP_MOD.monitor.pc_cmp.spc2_phy_pc_w
`endif

    

    `define TILE3            `CHIP.tile3
    `define ARIANE_CORE3     `TILE3.g_ariane_core.core.ariane
    `define SPARC_CORE3      `TILE3.g_sparc_core.core
    `define PICO_CORE3       `TILE3.g_picorv32_core.core
    `define CCX_TRANSDUCER3  `TILE3.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER3 `TILE3.g_picorv32_core.pico_l15_transducer
    `define L15_TOP3         `TILE3.l15.l15
    `define L15_PIPE3        `TILE3.l15.l15.pipeline
    `define DMBR3            `TILE3.dmbr_ins
    `define L2_TOP3          `TILE3.l2
    `define SPARC_REG3       `SPARC_CORE3.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH3       `SPARC_CORE3.sparc0.ffu.ffu
`else
    `define FLOATPATH3       `SPARC_CORE3.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH3         `SPARC_CORE3.sparc0.tlu.tlu
    `define DTLBPATH3        `SPARC_CORE3.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH3         `SPARC_CORE3.sparc0.tlu
    `define DTLBPATH3        `SPARC_CORE3.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH3         `SPARC_CORE3.sparc0
`ifndef RTL_SPU
    `define ICVPATH3         `SPARC_CORE3.sparc0.ifu.ifu.icv
    `define IFUPATH3         `SPARC_CORE3.sparc0.ifu.ifu
    `define TNUM3S           `SPARC_CORE3.sparc0.ifu.ifu.swl
    `define TPC3S            `SPARC_CORE3.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH3         `SPARC_CORE3.sparc0.ifu.icv
    `define IFUPATH3         `SPARC_CORE3.sparc0.ifu
    `define TNUM3S           `SPARC_CORE3.sparc0.ifu.swl
    `define TPC3S            `SPARC_CORE3.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH3         `SPARC_CORE3.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH3         `SPARC_CORE3.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH3         `SPARC_CORE3.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH3         `SPARC_CORE3.sparc0.ifu.fdp
`endif
    `define ALUPATH3         `SPARC_CORE3.sparc0.exu.exu.alu
    `define SPCPATH3         `SPARC_CORE3.sparc0
    `define REGPATH3         `SPARC_CORE3.sparc0.exu.exu.irf.irf
    `define CCRPATH3         `SPARC_CORE3.sparc0.exu.exu.ecl.ccr
    `define EXUPATH3         `SPARC_CORE3.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH3          `SPARC_CORE3.sparc0.tlu.tlu.tcl
    `define TS0PATH3         `SPARC_CORE3.sparc0.tlu.tlu.tsa0
    `define TS1PATH3         `SPARC_CORE3.sparc0.tlu.tlu.tsa1
    `define INTPATH3         `SPARC_CORE3.sparc0.tlu.tlu.intdp
    `define ASIPATH3         `SPARC_CORE3.sparc0.lsu.lsu.dctl
    `define ASIDPPATH3       `SPARC_CORE3.sparc0.lsu.lsu.dctldp
    `define ICTPATH3         `SPARC_CORE3.sparc0.ifu.ifu.ict
    `define DCACHE3          `SPARC_CORE3.sparc0.lsu.lsu.dcache
    `define INSTPATH3        `SPARC_CORE3.sparc0.ifu.ifu.fcl
    `define PCPATH3          `SPARC_CORE3.sparc0.ifu.ifu
    `define DVLD3            `SPARC_CORE3.sparc0.lsu.lsu.dva
    `define DTAG3            `SPARC_CORE3.sparc0.lsu.lsu.dtag
    `define SDTAG3           `SPARC_CORE3.sparc0.lsu.lsu.dtag
    `define SDVLD3           `SPARC_CORE3.sparc0.lsu.lsu.dva
    `define FFUPATH3         `SPARC_CORE3.sparc0.ffu.ffu
    `define TLU_HYPER3       `SPARC_CORE3.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP3           `SPARC_CORE3.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH3        `SPARC_CORE3.sparc0.ifu.ifu.itlb
`else
    `define TLPATH3          `SPARC_CORE3.sparc0.tlu.tcl
    `define TS0PATH3         `SPARC_CORE3.sparc0.tlu.tsa0
    `define TS1PATH3         `SPARC_CORE3.sparc0.tlu.tsa1
    `define INTPATH3         `SPARC_CORE3.sparc0.tlu.intdp
    `define ASIPATH3         `SPARC_CORE3.sparc0.lsu.dctl
    `define ASIDPPATH3       `SPARC_CORE3.sparc0.lsu.dctldp
    `define ICTPATH3         `SPARC_CORE3.sparc0.ifu.ict
    `define DCACHE3          `SPARC_CORE3.sparc0.lsu.dcache
    `define INSTPATH3        `SPARC_CORE3.sparc0.ifu.fcl
    `define PCPATH3          `SPARC_CORE3.sparc0.ifu
    `define DVLD3            `SPARC_CORE3.sparc0.lsu.dva
    `define DTAG3            `SPARC_CORE3.sparc0.lsu.dtag
    `define SDTAG3           `SPARC_CORE3.sparc0.lsu.dtag
    `define SDVLD3           `SPARC_CORE3.sparc0.lsu.dva
    `define FFUPATH3         `SPARC_CORE3.sparc0.ffu
    `define TLU_HYPER3       `SPARC_CORE3.sparc0.tlu.tlu_hyperv
    `define IFQDP3           `SPARC_CORE3.sparc0.ifu.ifqdp
    `define ITLBPATH3        `SPARC_CORE3.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH3    `SPARC_CORE3.sparc0.cfg_asi

    `define PITON_CORE3_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc3_inst_done
`ifdef RTL_SPARC3
    `define PITON_CORE3_PC_W3     `PCPATH3.fdp.pc_w
`else
    `define PITON_CORE3_PC_W3     `TOP_MOD.monitor.pc_cmp.spc3_phy_pc_w
`endif

    

    `define TILE4            `CHIP.tile4
    `define ARIANE_CORE4     `TILE4.g_ariane_core.core.ariane
    `define SPARC_CORE4      `TILE4.g_sparc_core.core
    `define PICO_CORE4       `TILE4.g_picorv32_core.core
    `define CCX_TRANSDUCER4  `TILE4.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER4 `TILE4.g_picorv32_core.pico_l15_transducer
    `define L15_TOP4         `TILE4.l15.l15
    `define L15_PIPE4        `TILE4.l15.l15.pipeline
    `define DMBR4            `TILE4.dmbr_ins
    `define L2_TOP4          `TILE4.l2
    `define SPARC_REG4       `SPARC_CORE4.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH4       `SPARC_CORE4.sparc0.ffu.ffu
`else
    `define FLOATPATH4       `SPARC_CORE4.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH4         `SPARC_CORE4.sparc0.tlu.tlu
    `define DTLBPATH4        `SPARC_CORE4.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH4         `SPARC_CORE4.sparc0.tlu
    `define DTLBPATH4        `SPARC_CORE4.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH4         `SPARC_CORE4.sparc0
`ifndef RTL_SPU
    `define ICVPATH4         `SPARC_CORE4.sparc0.ifu.ifu.icv
    `define IFUPATH4         `SPARC_CORE4.sparc0.ifu.ifu
    `define TNUM4S           `SPARC_CORE4.sparc0.ifu.ifu.swl
    `define TPC4S            `SPARC_CORE4.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH4         `SPARC_CORE4.sparc0.ifu.icv
    `define IFUPATH4         `SPARC_CORE4.sparc0.ifu
    `define TNUM4S           `SPARC_CORE4.sparc0.ifu.swl
    `define TPC4S            `SPARC_CORE4.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH4         `SPARC_CORE4.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH4         `SPARC_CORE4.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH4         `SPARC_CORE4.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH4         `SPARC_CORE4.sparc0.ifu.fdp
`endif
    `define ALUPATH4         `SPARC_CORE4.sparc0.exu.exu.alu
    `define SPCPATH4         `SPARC_CORE4.sparc0
    `define REGPATH4         `SPARC_CORE4.sparc0.exu.exu.irf.irf
    `define CCRPATH4         `SPARC_CORE4.sparc0.exu.exu.ecl.ccr
    `define EXUPATH4         `SPARC_CORE4.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH4          `SPARC_CORE4.sparc0.tlu.tlu.tcl
    `define TS0PATH4         `SPARC_CORE4.sparc0.tlu.tlu.tsa0
    `define TS1PATH4         `SPARC_CORE4.sparc0.tlu.tlu.tsa1
    `define INTPATH4         `SPARC_CORE4.sparc0.tlu.tlu.intdp
    `define ASIPATH4         `SPARC_CORE4.sparc0.lsu.lsu.dctl
    `define ASIDPPATH4       `SPARC_CORE4.sparc0.lsu.lsu.dctldp
    `define ICTPATH4         `SPARC_CORE4.sparc0.ifu.ifu.ict
    `define DCACHE4          `SPARC_CORE4.sparc0.lsu.lsu.dcache
    `define INSTPATH4        `SPARC_CORE4.sparc0.ifu.ifu.fcl
    `define PCPATH4          `SPARC_CORE4.sparc0.ifu.ifu
    `define DVLD4            `SPARC_CORE4.sparc0.lsu.lsu.dva
    `define DTAG4            `SPARC_CORE4.sparc0.lsu.lsu.dtag
    `define SDTAG4           `SPARC_CORE4.sparc0.lsu.lsu.dtag
    `define SDVLD4           `SPARC_CORE4.sparc0.lsu.lsu.dva
    `define FFUPATH4         `SPARC_CORE4.sparc0.ffu.ffu
    `define TLU_HYPER4       `SPARC_CORE4.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP4           `SPARC_CORE4.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH4        `SPARC_CORE4.sparc0.ifu.ifu.itlb
`else
    `define TLPATH4          `SPARC_CORE4.sparc0.tlu.tcl
    `define TS0PATH4         `SPARC_CORE4.sparc0.tlu.tsa0
    `define TS1PATH4         `SPARC_CORE4.sparc0.tlu.tsa1
    `define INTPATH4         `SPARC_CORE4.sparc0.tlu.intdp
    `define ASIPATH4         `SPARC_CORE4.sparc0.lsu.dctl
    `define ASIDPPATH4       `SPARC_CORE4.sparc0.lsu.dctldp
    `define ICTPATH4         `SPARC_CORE4.sparc0.ifu.ict
    `define DCACHE4          `SPARC_CORE4.sparc0.lsu.dcache
    `define INSTPATH4        `SPARC_CORE4.sparc0.ifu.fcl
    `define PCPATH4          `SPARC_CORE4.sparc0.ifu
    `define DVLD4            `SPARC_CORE4.sparc0.lsu.dva
    `define DTAG4            `SPARC_CORE4.sparc0.lsu.dtag
    `define SDTAG4           `SPARC_CORE4.sparc0.lsu.dtag
    `define SDVLD4           `SPARC_CORE4.sparc0.lsu.dva
    `define FFUPATH4         `SPARC_CORE4.sparc0.ffu
    `define TLU_HYPER4       `SPARC_CORE4.sparc0.tlu.tlu_hyperv
    `define IFQDP4           `SPARC_CORE4.sparc0.ifu.ifqdp
    `define ITLBPATH4        `SPARC_CORE4.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH4    `SPARC_CORE4.sparc0.cfg_asi

    `define PITON_CORE4_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc4_inst_done
`ifdef RTL_SPARC4
    `define PITON_CORE4_PC_W4     `PCPATH4.fdp.pc_w
`else
    `define PITON_CORE4_PC_W4     `TOP_MOD.monitor.pc_cmp.spc4_phy_pc_w
`endif

    

    `define TILE5            `CHIP.tile5
    `define ARIANE_CORE5     `TILE5.g_ariane_core.core.ariane
    `define SPARC_CORE5      `TILE5.g_sparc_core.core
    `define PICO_CORE5       `TILE5.g_picorv32_core.core
    `define CCX_TRANSDUCER5  `TILE5.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER5 `TILE5.g_picorv32_core.pico_l15_transducer
    `define L15_TOP5         `TILE5.l15.l15
    `define L15_PIPE5        `TILE5.l15.l15.pipeline
    `define DMBR5            `TILE5.dmbr_ins
    `define L2_TOP5          `TILE5.l2
    `define SPARC_REG5       `SPARC_CORE5.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH5       `SPARC_CORE5.sparc0.ffu.ffu
`else
    `define FLOATPATH5       `SPARC_CORE5.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH5         `SPARC_CORE5.sparc0.tlu.tlu
    `define DTLBPATH5        `SPARC_CORE5.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH5         `SPARC_CORE5.sparc0.tlu
    `define DTLBPATH5        `SPARC_CORE5.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH5         `SPARC_CORE5.sparc0
`ifndef RTL_SPU
    `define ICVPATH5         `SPARC_CORE5.sparc0.ifu.ifu.icv
    `define IFUPATH5         `SPARC_CORE5.sparc0.ifu.ifu
    `define TNUM5S           `SPARC_CORE5.sparc0.ifu.ifu.swl
    `define TPC5S            `SPARC_CORE5.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH5         `SPARC_CORE5.sparc0.ifu.icv
    `define IFUPATH5         `SPARC_CORE5.sparc0.ifu
    `define TNUM5S           `SPARC_CORE5.sparc0.ifu.swl
    `define TPC5S            `SPARC_CORE5.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH5         `SPARC_CORE5.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH5         `SPARC_CORE5.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH5         `SPARC_CORE5.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH5         `SPARC_CORE5.sparc0.ifu.fdp
`endif
    `define ALUPATH5         `SPARC_CORE5.sparc0.exu.exu.alu
    `define SPCPATH5         `SPARC_CORE5.sparc0
    `define REGPATH5         `SPARC_CORE5.sparc0.exu.exu.irf.irf
    `define CCRPATH5         `SPARC_CORE5.sparc0.exu.exu.ecl.ccr
    `define EXUPATH5         `SPARC_CORE5.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH5          `SPARC_CORE5.sparc0.tlu.tlu.tcl
    `define TS0PATH5         `SPARC_CORE5.sparc0.tlu.tlu.tsa0
    `define TS1PATH5         `SPARC_CORE5.sparc0.tlu.tlu.tsa1
    `define INTPATH5         `SPARC_CORE5.sparc0.tlu.tlu.intdp
    `define ASIPATH5         `SPARC_CORE5.sparc0.lsu.lsu.dctl
    `define ASIDPPATH5       `SPARC_CORE5.sparc0.lsu.lsu.dctldp
    `define ICTPATH5         `SPARC_CORE5.sparc0.ifu.ifu.ict
    `define DCACHE5          `SPARC_CORE5.sparc0.lsu.lsu.dcache
    `define INSTPATH5        `SPARC_CORE5.sparc0.ifu.ifu.fcl
    `define PCPATH5          `SPARC_CORE5.sparc0.ifu.ifu
    `define DVLD5            `SPARC_CORE5.sparc0.lsu.lsu.dva
    `define DTAG5            `SPARC_CORE5.sparc0.lsu.lsu.dtag
    `define SDTAG5           `SPARC_CORE5.sparc0.lsu.lsu.dtag
    `define SDVLD5           `SPARC_CORE5.sparc0.lsu.lsu.dva
    `define FFUPATH5         `SPARC_CORE5.sparc0.ffu.ffu
    `define TLU_HYPER5       `SPARC_CORE5.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP5           `SPARC_CORE5.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH5        `SPARC_CORE5.sparc0.ifu.ifu.itlb
`else
    `define TLPATH5          `SPARC_CORE5.sparc0.tlu.tcl
    `define TS0PATH5         `SPARC_CORE5.sparc0.tlu.tsa0
    `define TS1PATH5         `SPARC_CORE5.sparc0.tlu.tsa1
    `define INTPATH5         `SPARC_CORE5.sparc0.tlu.intdp
    `define ASIPATH5         `SPARC_CORE5.sparc0.lsu.dctl
    `define ASIDPPATH5       `SPARC_CORE5.sparc0.lsu.dctldp
    `define ICTPATH5         `SPARC_CORE5.sparc0.ifu.ict
    `define DCACHE5          `SPARC_CORE5.sparc0.lsu.dcache
    `define INSTPATH5        `SPARC_CORE5.sparc0.ifu.fcl
    `define PCPATH5          `SPARC_CORE5.sparc0.ifu
    `define DVLD5            `SPARC_CORE5.sparc0.lsu.dva
    `define DTAG5            `SPARC_CORE5.sparc0.lsu.dtag
    `define SDTAG5           `SPARC_CORE5.sparc0.lsu.dtag
    `define SDVLD5           `SPARC_CORE5.sparc0.lsu.dva
    `define FFUPATH5         `SPARC_CORE5.sparc0.ffu
    `define TLU_HYPER5       `SPARC_CORE5.sparc0.tlu.tlu_hyperv
    `define IFQDP5           `SPARC_CORE5.sparc0.ifu.ifqdp
    `define ITLBPATH5        `SPARC_CORE5.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH5    `SPARC_CORE5.sparc0.cfg_asi

    `define PITON_CORE5_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc5_inst_done
`ifdef RTL_SPARC5
    `define PITON_CORE5_PC_W5     `PCPATH5.fdp.pc_w
`else
    `define PITON_CORE5_PC_W5     `TOP_MOD.monitor.pc_cmp.spc5_phy_pc_w
`endif

    

    `define TILE6            `CHIP.tile6
    `define ARIANE_CORE6     `TILE6.g_ariane_core.core.ariane
    `define SPARC_CORE6      `TILE6.g_sparc_core.core
    `define PICO_CORE6       `TILE6.g_picorv32_core.core
    `define CCX_TRANSDUCER6  `TILE6.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER6 `TILE6.g_picorv32_core.pico_l15_transducer
    `define L15_TOP6         `TILE6.l15.l15
    `define L15_PIPE6        `TILE6.l15.l15.pipeline
    `define DMBR6            `TILE6.dmbr_ins
    `define L2_TOP6          `TILE6.l2
    `define SPARC_REG6       `SPARC_CORE6.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH6       `SPARC_CORE6.sparc0.ffu.ffu
`else
    `define FLOATPATH6       `SPARC_CORE6.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH6         `SPARC_CORE6.sparc0.tlu.tlu
    `define DTLBPATH6        `SPARC_CORE6.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH6         `SPARC_CORE6.sparc0.tlu
    `define DTLBPATH6        `SPARC_CORE6.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH6         `SPARC_CORE6.sparc0
`ifndef RTL_SPU
    `define ICVPATH6         `SPARC_CORE6.sparc0.ifu.ifu.icv
    `define IFUPATH6         `SPARC_CORE6.sparc0.ifu.ifu
    `define TNUM6S           `SPARC_CORE6.sparc0.ifu.ifu.swl
    `define TPC6S            `SPARC_CORE6.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH6         `SPARC_CORE6.sparc0.ifu.icv
    `define IFUPATH6         `SPARC_CORE6.sparc0.ifu
    `define TNUM6S           `SPARC_CORE6.sparc0.ifu.swl
    `define TPC6S            `SPARC_CORE6.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH6         `SPARC_CORE6.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH6         `SPARC_CORE6.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH6         `SPARC_CORE6.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH6         `SPARC_CORE6.sparc0.ifu.fdp
`endif
    `define ALUPATH6         `SPARC_CORE6.sparc0.exu.exu.alu
    `define SPCPATH6         `SPARC_CORE6.sparc0
    `define REGPATH6         `SPARC_CORE6.sparc0.exu.exu.irf.irf
    `define CCRPATH6         `SPARC_CORE6.sparc0.exu.exu.ecl.ccr
    `define EXUPATH6         `SPARC_CORE6.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH6          `SPARC_CORE6.sparc0.tlu.tlu.tcl
    `define TS0PATH6         `SPARC_CORE6.sparc0.tlu.tlu.tsa0
    `define TS1PATH6         `SPARC_CORE6.sparc0.tlu.tlu.tsa1
    `define INTPATH6         `SPARC_CORE6.sparc0.tlu.tlu.intdp
    `define ASIPATH6         `SPARC_CORE6.sparc0.lsu.lsu.dctl
    `define ASIDPPATH6       `SPARC_CORE6.sparc0.lsu.lsu.dctldp
    `define ICTPATH6         `SPARC_CORE6.sparc0.ifu.ifu.ict
    `define DCACHE6          `SPARC_CORE6.sparc0.lsu.lsu.dcache
    `define INSTPATH6        `SPARC_CORE6.sparc0.ifu.ifu.fcl
    `define PCPATH6          `SPARC_CORE6.sparc0.ifu.ifu
    `define DVLD6            `SPARC_CORE6.sparc0.lsu.lsu.dva
    `define DTAG6            `SPARC_CORE6.sparc0.lsu.lsu.dtag
    `define SDTAG6           `SPARC_CORE6.sparc0.lsu.lsu.dtag
    `define SDVLD6           `SPARC_CORE6.sparc0.lsu.lsu.dva
    `define FFUPATH6         `SPARC_CORE6.sparc0.ffu.ffu
    `define TLU_HYPER6       `SPARC_CORE6.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP6           `SPARC_CORE6.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH6        `SPARC_CORE6.sparc0.ifu.ifu.itlb
`else
    `define TLPATH6          `SPARC_CORE6.sparc0.tlu.tcl
    `define TS0PATH6         `SPARC_CORE6.sparc0.tlu.tsa0
    `define TS1PATH6         `SPARC_CORE6.sparc0.tlu.tsa1
    `define INTPATH6         `SPARC_CORE6.sparc0.tlu.intdp
    `define ASIPATH6         `SPARC_CORE6.sparc0.lsu.dctl
    `define ASIDPPATH6       `SPARC_CORE6.sparc0.lsu.dctldp
    `define ICTPATH6         `SPARC_CORE6.sparc0.ifu.ict
    `define DCACHE6          `SPARC_CORE6.sparc0.lsu.dcache
    `define INSTPATH6        `SPARC_CORE6.sparc0.ifu.fcl
    `define PCPATH6          `SPARC_CORE6.sparc0.ifu
    `define DVLD6            `SPARC_CORE6.sparc0.lsu.dva
    `define DTAG6            `SPARC_CORE6.sparc0.lsu.dtag
    `define SDTAG6           `SPARC_CORE6.sparc0.lsu.dtag
    `define SDVLD6           `SPARC_CORE6.sparc0.lsu.dva
    `define FFUPATH6         `SPARC_CORE6.sparc0.ffu
    `define TLU_HYPER6       `SPARC_CORE6.sparc0.tlu.tlu_hyperv
    `define IFQDP6           `SPARC_CORE6.sparc0.ifu.ifqdp
    `define ITLBPATH6        `SPARC_CORE6.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH6    `SPARC_CORE6.sparc0.cfg_asi

    `define PITON_CORE6_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc6_inst_done
`ifdef RTL_SPARC6
    `define PITON_CORE6_PC_W6     `PCPATH6.fdp.pc_w
`else
    `define PITON_CORE6_PC_W6     `TOP_MOD.monitor.pc_cmp.spc6_phy_pc_w
`endif

    

    `define TILE7            `CHIP.tile7
    `define ARIANE_CORE7     `TILE7.g_ariane_core.core.ariane
    `define SPARC_CORE7      `TILE7.g_sparc_core.core
    `define PICO_CORE7       `TILE7.g_picorv32_core.core
    `define CCX_TRANSDUCER7  `TILE7.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER7 `TILE7.g_picorv32_core.pico_l15_transducer
    `define L15_TOP7         `TILE7.l15.l15
    `define L15_PIPE7        `TILE7.l15.l15.pipeline
    `define DMBR7            `TILE7.dmbr_ins
    `define L2_TOP7          `TILE7.l2
    `define SPARC_REG7       `SPARC_CORE7.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH7       `SPARC_CORE7.sparc0.ffu.ffu
`else
    `define FLOATPATH7       `SPARC_CORE7.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH7         `SPARC_CORE7.sparc0.tlu.tlu
    `define DTLBPATH7        `SPARC_CORE7.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH7         `SPARC_CORE7.sparc0.tlu
    `define DTLBPATH7        `SPARC_CORE7.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH7         `SPARC_CORE7.sparc0
`ifndef RTL_SPU
    `define ICVPATH7         `SPARC_CORE7.sparc0.ifu.ifu.icv
    `define IFUPATH7         `SPARC_CORE7.sparc0.ifu.ifu
    `define TNUM7S           `SPARC_CORE7.sparc0.ifu.ifu.swl
    `define TPC7S            `SPARC_CORE7.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH7         `SPARC_CORE7.sparc0.ifu.icv
    `define IFUPATH7         `SPARC_CORE7.sparc0.ifu
    `define TNUM7S           `SPARC_CORE7.sparc0.ifu.swl
    `define TPC7S            `SPARC_CORE7.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH7         `SPARC_CORE7.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH7         `SPARC_CORE7.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH7         `SPARC_CORE7.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH7         `SPARC_CORE7.sparc0.ifu.fdp
`endif
    `define ALUPATH7         `SPARC_CORE7.sparc0.exu.exu.alu
    `define SPCPATH7         `SPARC_CORE7.sparc0
    `define REGPATH7         `SPARC_CORE7.sparc0.exu.exu.irf.irf
    `define CCRPATH7         `SPARC_CORE7.sparc0.exu.exu.ecl.ccr
    `define EXUPATH7         `SPARC_CORE7.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH7          `SPARC_CORE7.sparc0.tlu.tlu.tcl
    `define TS0PATH7         `SPARC_CORE7.sparc0.tlu.tlu.tsa0
    `define TS1PATH7         `SPARC_CORE7.sparc0.tlu.tlu.tsa1
    `define INTPATH7         `SPARC_CORE7.sparc0.tlu.tlu.intdp
    `define ASIPATH7         `SPARC_CORE7.sparc0.lsu.lsu.dctl
    `define ASIDPPATH7       `SPARC_CORE7.sparc0.lsu.lsu.dctldp
    `define ICTPATH7         `SPARC_CORE7.sparc0.ifu.ifu.ict
    `define DCACHE7          `SPARC_CORE7.sparc0.lsu.lsu.dcache
    `define INSTPATH7        `SPARC_CORE7.sparc0.ifu.ifu.fcl
    `define PCPATH7          `SPARC_CORE7.sparc0.ifu.ifu
    `define DVLD7            `SPARC_CORE7.sparc0.lsu.lsu.dva
    `define DTAG7            `SPARC_CORE7.sparc0.lsu.lsu.dtag
    `define SDTAG7           `SPARC_CORE7.sparc0.lsu.lsu.dtag
    `define SDVLD7           `SPARC_CORE7.sparc0.lsu.lsu.dva
    `define FFUPATH7         `SPARC_CORE7.sparc0.ffu.ffu
    `define TLU_HYPER7       `SPARC_CORE7.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP7           `SPARC_CORE7.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH7        `SPARC_CORE7.sparc0.ifu.ifu.itlb
`else
    `define TLPATH7          `SPARC_CORE7.sparc0.tlu.tcl
    `define TS0PATH7         `SPARC_CORE7.sparc0.tlu.tsa0
    `define TS1PATH7         `SPARC_CORE7.sparc0.tlu.tsa1
    `define INTPATH7         `SPARC_CORE7.sparc0.tlu.intdp
    `define ASIPATH7         `SPARC_CORE7.sparc0.lsu.dctl
    `define ASIDPPATH7       `SPARC_CORE7.sparc0.lsu.dctldp
    `define ICTPATH7         `SPARC_CORE7.sparc0.ifu.ict
    `define DCACHE7          `SPARC_CORE7.sparc0.lsu.dcache
    `define INSTPATH7        `SPARC_CORE7.sparc0.ifu.fcl
    `define PCPATH7          `SPARC_CORE7.sparc0.ifu
    `define DVLD7            `SPARC_CORE7.sparc0.lsu.dva
    `define DTAG7            `SPARC_CORE7.sparc0.lsu.dtag
    `define SDTAG7           `SPARC_CORE7.sparc0.lsu.dtag
    `define SDVLD7           `SPARC_CORE7.sparc0.lsu.dva
    `define FFUPATH7         `SPARC_CORE7.sparc0.ffu
    `define TLU_HYPER7       `SPARC_CORE7.sparc0.tlu.tlu_hyperv
    `define IFQDP7           `SPARC_CORE7.sparc0.ifu.ifqdp
    `define ITLBPATH7        `SPARC_CORE7.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH7    `SPARC_CORE7.sparc0.cfg_asi

    `define PITON_CORE7_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc7_inst_done
`ifdef RTL_SPARC7
    `define PITON_CORE7_PC_W7     `PCPATH7.fdp.pc_w
`else
    `define PITON_CORE7_PC_W7     `TOP_MOD.monitor.pc_cmp.spc7_phy_pc_w
`endif

    

    `define TILE8            `CHIP.tile8
    `define ARIANE_CORE8     `TILE8.g_ariane_core.core.ariane
    `define SPARC_CORE8      `TILE8.g_sparc_core.core
    `define PICO_CORE8       `TILE8.g_picorv32_core.core
    `define CCX_TRANSDUCER8  `TILE8.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER8 `TILE8.g_picorv32_core.pico_l15_transducer
    `define L15_TOP8         `TILE8.l15.l15
    `define L15_PIPE8        `TILE8.l15.l15.pipeline
    `define DMBR8            `TILE8.dmbr_ins
    `define L2_TOP8          `TILE8.l2
    `define SPARC_REG8       `SPARC_CORE8.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH8       `SPARC_CORE8.sparc0.ffu.ffu
`else
    `define FLOATPATH8       `SPARC_CORE8.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH8         `SPARC_CORE8.sparc0.tlu.tlu
    `define DTLBPATH8        `SPARC_CORE8.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH8         `SPARC_CORE8.sparc0.tlu
    `define DTLBPATH8        `SPARC_CORE8.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH8         `SPARC_CORE8.sparc0
`ifndef RTL_SPU
    `define ICVPATH8         `SPARC_CORE8.sparc0.ifu.ifu.icv
    `define IFUPATH8         `SPARC_CORE8.sparc0.ifu.ifu
    `define TNUM8S           `SPARC_CORE8.sparc0.ifu.ifu.swl
    `define TPC8S            `SPARC_CORE8.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH8         `SPARC_CORE8.sparc0.ifu.icv
    `define IFUPATH8         `SPARC_CORE8.sparc0.ifu
    `define TNUM8S           `SPARC_CORE8.sparc0.ifu.swl
    `define TPC8S            `SPARC_CORE8.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH8         `SPARC_CORE8.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH8         `SPARC_CORE8.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH8         `SPARC_CORE8.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH8         `SPARC_CORE8.sparc0.ifu.fdp
`endif
    `define ALUPATH8         `SPARC_CORE8.sparc0.exu.exu.alu
    `define SPCPATH8         `SPARC_CORE8.sparc0
    `define REGPATH8         `SPARC_CORE8.sparc0.exu.exu.irf.irf
    `define CCRPATH8         `SPARC_CORE8.sparc0.exu.exu.ecl.ccr
    `define EXUPATH8         `SPARC_CORE8.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH8          `SPARC_CORE8.sparc0.tlu.tlu.tcl
    `define TS0PATH8         `SPARC_CORE8.sparc0.tlu.tlu.tsa0
    `define TS1PATH8         `SPARC_CORE8.sparc0.tlu.tlu.tsa1
    `define INTPATH8         `SPARC_CORE8.sparc0.tlu.tlu.intdp
    `define ASIPATH8         `SPARC_CORE8.sparc0.lsu.lsu.dctl
    `define ASIDPPATH8       `SPARC_CORE8.sparc0.lsu.lsu.dctldp
    `define ICTPATH8         `SPARC_CORE8.sparc0.ifu.ifu.ict
    `define DCACHE8          `SPARC_CORE8.sparc0.lsu.lsu.dcache
    `define INSTPATH8        `SPARC_CORE8.sparc0.ifu.ifu.fcl
    `define PCPATH8          `SPARC_CORE8.sparc0.ifu.ifu
    `define DVLD8            `SPARC_CORE8.sparc0.lsu.lsu.dva
    `define DTAG8            `SPARC_CORE8.sparc0.lsu.lsu.dtag
    `define SDTAG8           `SPARC_CORE8.sparc0.lsu.lsu.dtag
    `define SDVLD8           `SPARC_CORE8.sparc0.lsu.lsu.dva
    `define FFUPATH8         `SPARC_CORE8.sparc0.ffu.ffu
    `define TLU_HYPER8       `SPARC_CORE8.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP8           `SPARC_CORE8.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH8        `SPARC_CORE8.sparc0.ifu.ifu.itlb
`else
    `define TLPATH8          `SPARC_CORE8.sparc0.tlu.tcl
    `define TS0PATH8         `SPARC_CORE8.sparc0.tlu.tsa0
    `define TS1PATH8         `SPARC_CORE8.sparc0.tlu.tsa1
    `define INTPATH8         `SPARC_CORE8.sparc0.tlu.intdp
    `define ASIPATH8         `SPARC_CORE8.sparc0.lsu.dctl
    `define ASIDPPATH8       `SPARC_CORE8.sparc0.lsu.dctldp
    `define ICTPATH8         `SPARC_CORE8.sparc0.ifu.ict
    `define DCACHE8          `SPARC_CORE8.sparc0.lsu.dcache
    `define INSTPATH8        `SPARC_CORE8.sparc0.ifu.fcl
    `define PCPATH8          `SPARC_CORE8.sparc0.ifu
    `define DVLD8            `SPARC_CORE8.sparc0.lsu.dva
    `define DTAG8            `SPARC_CORE8.sparc0.lsu.dtag
    `define SDTAG8           `SPARC_CORE8.sparc0.lsu.dtag
    `define SDVLD8           `SPARC_CORE8.sparc0.lsu.dva
    `define FFUPATH8         `SPARC_CORE8.sparc0.ffu
    `define TLU_HYPER8       `SPARC_CORE8.sparc0.tlu.tlu_hyperv
    `define IFQDP8           `SPARC_CORE8.sparc0.ifu.ifqdp
    `define ITLBPATH8        `SPARC_CORE8.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH8    `SPARC_CORE8.sparc0.cfg_asi

    `define PITON_CORE8_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc8_inst_done
`ifdef RTL_SPARC8
    `define PITON_CORE8_PC_W8     `PCPATH8.fdp.pc_w
`else
    `define PITON_CORE8_PC_W8     `TOP_MOD.monitor.pc_cmp.spc8_phy_pc_w
`endif

    

    `define TILE9            `CHIP.tile9
    `define ARIANE_CORE9     `TILE9.g_ariane_core.core.ariane
    `define SPARC_CORE9      `TILE9.g_sparc_core.core
    `define PICO_CORE9       `TILE9.g_picorv32_core.core
    `define CCX_TRANSDUCER9  `TILE9.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER9 `TILE9.g_picorv32_core.pico_l15_transducer
    `define L15_TOP9         `TILE9.l15.l15
    `define L15_PIPE9        `TILE9.l15.l15.pipeline
    `define DMBR9            `TILE9.dmbr_ins
    `define L2_TOP9          `TILE9.l2
    `define SPARC_REG9       `SPARC_CORE9.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH9       `SPARC_CORE9.sparc0.ffu.ffu
`else
    `define FLOATPATH9       `SPARC_CORE9.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH9         `SPARC_CORE9.sparc0.tlu.tlu
    `define DTLBPATH9        `SPARC_CORE9.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH9         `SPARC_CORE9.sparc0.tlu
    `define DTLBPATH9        `SPARC_CORE9.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH9         `SPARC_CORE9.sparc0
`ifndef RTL_SPU
    `define ICVPATH9         `SPARC_CORE9.sparc0.ifu.ifu.icv
    `define IFUPATH9         `SPARC_CORE9.sparc0.ifu.ifu
    `define TNUM9S           `SPARC_CORE9.sparc0.ifu.ifu.swl
    `define TPC9S            `SPARC_CORE9.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH9         `SPARC_CORE9.sparc0.ifu.icv
    `define IFUPATH9         `SPARC_CORE9.sparc0.ifu
    `define TNUM9S           `SPARC_CORE9.sparc0.ifu.swl
    `define TPC9S            `SPARC_CORE9.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH9         `SPARC_CORE9.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH9         `SPARC_CORE9.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH9         `SPARC_CORE9.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH9         `SPARC_CORE9.sparc0.ifu.fdp
`endif
    `define ALUPATH9         `SPARC_CORE9.sparc0.exu.exu.alu
    `define SPCPATH9         `SPARC_CORE9.sparc0
    `define REGPATH9         `SPARC_CORE9.sparc0.exu.exu.irf.irf
    `define CCRPATH9         `SPARC_CORE9.sparc0.exu.exu.ecl.ccr
    `define EXUPATH9         `SPARC_CORE9.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH9          `SPARC_CORE9.sparc0.tlu.tlu.tcl
    `define TS0PATH9         `SPARC_CORE9.sparc0.tlu.tlu.tsa0
    `define TS1PATH9         `SPARC_CORE9.sparc0.tlu.tlu.tsa1
    `define INTPATH9         `SPARC_CORE9.sparc0.tlu.tlu.intdp
    `define ASIPATH9         `SPARC_CORE9.sparc0.lsu.lsu.dctl
    `define ASIDPPATH9       `SPARC_CORE9.sparc0.lsu.lsu.dctldp
    `define ICTPATH9         `SPARC_CORE9.sparc0.ifu.ifu.ict
    `define DCACHE9          `SPARC_CORE9.sparc0.lsu.lsu.dcache
    `define INSTPATH9        `SPARC_CORE9.sparc0.ifu.ifu.fcl
    `define PCPATH9          `SPARC_CORE9.sparc0.ifu.ifu
    `define DVLD9            `SPARC_CORE9.sparc0.lsu.lsu.dva
    `define DTAG9            `SPARC_CORE9.sparc0.lsu.lsu.dtag
    `define SDTAG9           `SPARC_CORE9.sparc0.lsu.lsu.dtag
    `define SDVLD9           `SPARC_CORE9.sparc0.lsu.lsu.dva
    `define FFUPATH9         `SPARC_CORE9.sparc0.ffu.ffu
    `define TLU_HYPER9       `SPARC_CORE9.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP9           `SPARC_CORE9.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH9        `SPARC_CORE9.sparc0.ifu.ifu.itlb
`else
    `define TLPATH9          `SPARC_CORE9.sparc0.tlu.tcl
    `define TS0PATH9         `SPARC_CORE9.sparc0.tlu.tsa0
    `define TS1PATH9         `SPARC_CORE9.sparc0.tlu.tsa1
    `define INTPATH9         `SPARC_CORE9.sparc0.tlu.intdp
    `define ASIPATH9         `SPARC_CORE9.sparc0.lsu.dctl
    `define ASIDPPATH9       `SPARC_CORE9.sparc0.lsu.dctldp
    `define ICTPATH9         `SPARC_CORE9.sparc0.ifu.ict
    `define DCACHE9          `SPARC_CORE9.sparc0.lsu.dcache
    `define INSTPATH9        `SPARC_CORE9.sparc0.ifu.fcl
    `define PCPATH9          `SPARC_CORE9.sparc0.ifu
    `define DVLD9            `SPARC_CORE9.sparc0.lsu.dva
    `define DTAG9            `SPARC_CORE9.sparc0.lsu.dtag
    `define SDTAG9           `SPARC_CORE9.sparc0.lsu.dtag
    `define SDVLD9           `SPARC_CORE9.sparc0.lsu.dva
    `define FFUPATH9         `SPARC_CORE9.sparc0.ffu
    `define TLU_HYPER9       `SPARC_CORE9.sparc0.tlu.tlu_hyperv
    `define IFQDP9           `SPARC_CORE9.sparc0.ifu.ifqdp
    `define ITLBPATH9        `SPARC_CORE9.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH9    `SPARC_CORE9.sparc0.cfg_asi

    `define PITON_CORE9_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc9_inst_done
`ifdef RTL_SPARC9
    `define PITON_CORE9_PC_W9     `PCPATH9.fdp.pc_w
`else
    `define PITON_CORE9_PC_W9     `TOP_MOD.monitor.pc_cmp.spc9_phy_pc_w
`endif

    

    `define TILE10            `CHIP.tile10
    `define ARIANE_CORE10     `TILE10.g_ariane_core.core.ariane
    `define SPARC_CORE10      `TILE10.g_sparc_core.core
    `define PICO_CORE10       `TILE10.g_picorv32_core.core
    `define CCX_TRANSDUCER10  `TILE10.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER10 `TILE10.g_picorv32_core.pico_l15_transducer
    `define L15_TOP10         `TILE10.l15.l15
    `define L15_PIPE10        `TILE10.l15.l15.pipeline
    `define DMBR10            `TILE10.dmbr_ins
    `define L2_TOP10          `TILE10.l2
    `define SPARC_REG10       `SPARC_CORE10.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH10       `SPARC_CORE10.sparc0.ffu.ffu
`else
    `define FLOATPATH10       `SPARC_CORE10.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH10         `SPARC_CORE10.sparc0.tlu.tlu
    `define DTLBPATH10        `SPARC_CORE10.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH10         `SPARC_CORE10.sparc0.tlu
    `define DTLBPATH10        `SPARC_CORE10.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH10         `SPARC_CORE10.sparc0
`ifndef RTL_SPU
    `define ICVPATH10         `SPARC_CORE10.sparc0.ifu.ifu.icv
    `define IFUPATH10         `SPARC_CORE10.sparc0.ifu.ifu
    `define TNUM10S           `SPARC_CORE10.sparc0.ifu.ifu.swl
    `define TPC10S            `SPARC_CORE10.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH10         `SPARC_CORE10.sparc0.ifu.icv
    `define IFUPATH10         `SPARC_CORE10.sparc0.ifu
    `define TNUM10S           `SPARC_CORE10.sparc0.ifu.swl
    `define TPC10S            `SPARC_CORE10.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH10         `SPARC_CORE10.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH10         `SPARC_CORE10.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH10         `SPARC_CORE10.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH10         `SPARC_CORE10.sparc0.ifu.fdp
`endif
    `define ALUPATH10         `SPARC_CORE10.sparc0.exu.exu.alu
    `define SPCPATH10         `SPARC_CORE10.sparc0
    `define REGPATH10         `SPARC_CORE10.sparc0.exu.exu.irf.irf
    `define CCRPATH10         `SPARC_CORE10.sparc0.exu.exu.ecl.ccr
    `define EXUPATH10         `SPARC_CORE10.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH10          `SPARC_CORE10.sparc0.tlu.tlu.tcl
    `define TS0PATH10         `SPARC_CORE10.sparc0.tlu.tlu.tsa0
    `define TS1PATH10         `SPARC_CORE10.sparc0.tlu.tlu.tsa1
    `define INTPATH10         `SPARC_CORE10.sparc0.tlu.tlu.intdp
    `define ASIPATH10         `SPARC_CORE10.sparc0.lsu.lsu.dctl
    `define ASIDPPATH10       `SPARC_CORE10.sparc0.lsu.lsu.dctldp
    `define ICTPATH10         `SPARC_CORE10.sparc0.ifu.ifu.ict
    `define DCACHE10          `SPARC_CORE10.sparc0.lsu.lsu.dcache
    `define INSTPATH10        `SPARC_CORE10.sparc0.ifu.ifu.fcl
    `define PCPATH10          `SPARC_CORE10.sparc0.ifu.ifu
    `define DVLD10            `SPARC_CORE10.sparc0.lsu.lsu.dva
    `define DTAG10            `SPARC_CORE10.sparc0.lsu.lsu.dtag
    `define SDTAG10           `SPARC_CORE10.sparc0.lsu.lsu.dtag
    `define SDVLD10           `SPARC_CORE10.sparc0.lsu.lsu.dva
    `define FFUPATH10         `SPARC_CORE10.sparc0.ffu.ffu
    `define TLU_HYPER10       `SPARC_CORE10.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP10           `SPARC_CORE10.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH10        `SPARC_CORE10.sparc0.ifu.ifu.itlb
`else
    `define TLPATH10          `SPARC_CORE10.sparc0.tlu.tcl
    `define TS0PATH10         `SPARC_CORE10.sparc0.tlu.tsa0
    `define TS1PATH10         `SPARC_CORE10.sparc0.tlu.tsa1
    `define INTPATH10         `SPARC_CORE10.sparc0.tlu.intdp
    `define ASIPATH10         `SPARC_CORE10.sparc0.lsu.dctl
    `define ASIDPPATH10       `SPARC_CORE10.sparc0.lsu.dctldp
    `define ICTPATH10         `SPARC_CORE10.sparc0.ifu.ict
    `define DCACHE10          `SPARC_CORE10.sparc0.lsu.dcache
    `define INSTPATH10        `SPARC_CORE10.sparc0.ifu.fcl
    `define PCPATH10          `SPARC_CORE10.sparc0.ifu
    `define DVLD10            `SPARC_CORE10.sparc0.lsu.dva
    `define DTAG10            `SPARC_CORE10.sparc0.lsu.dtag
    `define SDTAG10           `SPARC_CORE10.sparc0.lsu.dtag
    `define SDVLD10           `SPARC_CORE10.sparc0.lsu.dva
    `define FFUPATH10         `SPARC_CORE10.sparc0.ffu
    `define TLU_HYPER10       `SPARC_CORE10.sparc0.tlu.tlu_hyperv
    `define IFQDP10           `SPARC_CORE10.sparc0.ifu.ifqdp
    `define ITLBPATH10        `SPARC_CORE10.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH10    `SPARC_CORE10.sparc0.cfg_asi

    `define PITON_CORE10_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc10_inst_done
`ifdef RTL_SPARC10
    `define PITON_CORE10_PC_W10     `PCPATH10.fdp.pc_w
`else
    `define PITON_CORE10_PC_W10     `TOP_MOD.monitor.pc_cmp.spc10_phy_pc_w
`endif

    

    `define TILE11            `CHIP.tile11
    `define ARIANE_CORE11     `TILE11.g_ariane_core.core.ariane
    `define SPARC_CORE11      `TILE11.g_sparc_core.core
    `define PICO_CORE11       `TILE11.g_picorv32_core.core
    `define CCX_TRANSDUCER11  `TILE11.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER11 `TILE11.g_picorv32_core.pico_l15_transducer
    `define L15_TOP11         `TILE11.l15.l15
    `define L15_PIPE11        `TILE11.l15.l15.pipeline
    `define DMBR11            `TILE11.dmbr_ins
    `define L2_TOP11          `TILE11.l2
    `define SPARC_REG11       `SPARC_CORE11.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH11       `SPARC_CORE11.sparc0.ffu.ffu
`else
    `define FLOATPATH11       `SPARC_CORE11.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH11         `SPARC_CORE11.sparc0.tlu.tlu
    `define DTLBPATH11        `SPARC_CORE11.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH11         `SPARC_CORE11.sparc0.tlu
    `define DTLBPATH11        `SPARC_CORE11.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH11         `SPARC_CORE11.sparc0
`ifndef RTL_SPU
    `define ICVPATH11         `SPARC_CORE11.sparc0.ifu.ifu.icv
    `define IFUPATH11         `SPARC_CORE11.sparc0.ifu.ifu
    `define TNUM11S           `SPARC_CORE11.sparc0.ifu.ifu.swl
    `define TPC11S            `SPARC_CORE11.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH11         `SPARC_CORE11.sparc0.ifu.icv
    `define IFUPATH11         `SPARC_CORE11.sparc0.ifu
    `define TNUM11S           `SPARC_CORE11.sparc0.ifu.swl
    `define TPC11S            `SPARC_CORE11.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH11         `SPARC_CORE11.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH11         `SPARC_CORE11.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH11         `SPARC_CORE11.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH11         `SPARC_CORE11.sparc0.ifu.fdp
`endif
    `define ALUPATH11         `SPARC_CORE11.sparc0.exu.exu.alu
    `define SPCPATH11         `SPARC_CORE11.sparc0
    `define REGPATH11         `SPARC_CORE11.sparc0.exu.exu.irf.irf
    `define CCRPATH11         `SPARC_CORE11.sparc0.exu.exu.ecl.ccr
    `define EXUPATH11         `SPARC_CORE11.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH11          `SPARC_CORE11.sparc0.tlu.tlu.tcl
    `define TS0PATH11         `SPARC_CORE11.sparc0.tlu.tlu.tsa0
    `define TS1PATH11         `SPARC_CORE11.sparc0.tlu.tlu.tsa1
    `define INTPATH11         `SPARC_CORE11.sparc0.tlu.tlu.intdp
    `define ASIPATH11         `SPARC_CORE11.sparc0.lsu.lsu.dctl
    `define ASIDPPATH11       `SPARC_CORE11.sparc0.lsu.lsu.dctldp
    `define ICTPATH11         `SPARC_CORE11.sparc0.ifu.ifu.ict
    `define DCACHE11          `SPARC_CORE11.sparc0.lsu.lsu.dcache
    `define INSTPATH11        `SPARC_CORE11.sparc0.ifu.ifu.fcl
    `define PCPATH11          `SPARC_CORE11.sparc0.ifu.ifu
    `define DVLD11            `SPARC_CORE11.sparc0.lsu.lsu.dva
    `define DTAG11            `SPARC_CORE11.sparc0.lsu.lsu.dtag
    `define SDTAG11           `SPARC_CORE11.sparc0.lsu.lsu.dtag
    `define SDVLD11           `SPARC_CORE11.sparc0.lsu.lsu.dva
    `define FFUPATH11         `SPARC_CORE11.sparc0.ffu.ffu
    `define TLU_HYPER11       `SPARC_CORE11.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP11           `SPARC_CORE11.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH11        `SPARC_CORE11.sparc0.ifu.ifu.itlb
`else
    `define TLPATH11          `SPARC_CORE11.sparc0.tlu.tcl
    `define TS0PATH11         `SPARC_CORE11.sparc0.tlu.tsa0
    `define TS1PATH11         `SPARC_CORE11.sparc0.tlu.tsa1
    `define INTPATH11         `SPARC_CORE11.sparc0.tlu.intdp
    `define ASIPATH11         `SPARC_CORE11.sparc0.lsu.dctl
    `define ASIDPPATH11       `SPARC_CORE11.sparc0.lsu.dctldp
    `define ICTPATH11         `SPARC_CORE11.sparc0.ifu.ict
    `define DCACHE11          `SPARC_CORE11.sparc0.lsu.dcache
    `define INSTPATH11        `SPARC_CORE11.sparc0.ifu.fcl
    `define PCPATH11          `SPARC_CORE11.sparc0.ifu
    `define DVLD11            `SPARC_CORE11.sparc0.lsu.dva
    `define DTAG11            `SPARC_CORE11.sparc0.lsu.dtag
    `define SDTAG11           `SPARC_CORE11.sparc0.lsu.dtag
    `define SDVLD11           `SPARC_CORE11.sparc0.lsu.dva
    `define FFUPATH11         `SPARC_CORE11.sparc0.ffu
    `define TLU_HYPER11       `SPARC_CORE11.sparc0.tlu.tlu_hyperv
    `define IFQDP11           `SPARC_CORE11.sparc0.ifu.ifqdp
    `define ITLBPATH11        `SPARC_CORE11.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH11    `SPARC_CORE11.sparc0.cfg_asi

    `define PITON_CORE11_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc11_inst_done
`ifdef RTL_SPARC11
    `define PITON_CORE11_PC_W11     `PCPATH11.fdp.pc_w
`else
    `define PITON_CORE11_PC_W11     `TOP_MOD.monitor.pc_cmp.spc11_phy_pc_w
`endif

    

    `define TILE12            `CHIP.tile12
    `define ARIANE_CORE12     `TILE12.g_ariane_core.core.ariane
    `define SPARC_CORE12      `TILE12.g_sparc_core.core
    `define PICO_CORE12       `TILE12.g_picorv32_core.core
    `define CCX_TRANSDUCER12  `TILE12.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER12 `TILE12.g_picorv32_core.pico_l15_transducer
    `define L15_TOP12         `TILE12.l15.l15
    `define L15_PIPE12        `TILE12.l15.l15.pipeline
    `define DMBR12            `TILE12.dmbr_ins
    `define L2_TOP12          `TILE12.l2
    `define SPARC_REG12       `SPARC_CORE12.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH12       `SPARC_CORE12.sparc0.ffu.ffu
`else
    `define FLOATPATH12       `SPARC_CORE12.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH12         `SPARC_CORE12.sparc0.tlu.tlu
    `define DTLBPATH12        `SPARC_CORE12.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH12         `SPARC_CORE12.sparc0.tlu
    `define DTLBPATH12        `SPARC_CORE12.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH12         `SPARC_CORE12.sparc0
`ifndef RTL_SPU
    `define ICVPATH12         `SPARC_CORE12.sparc0.ifu.ifu.icv
    `define IFUPATH12         `SPARC_CORE12.sparc0.ifu.ifu
    `define TNUM12S           `SPARC_CORE12.sparc0.ifu.ifu.swl
    `define TPC12S            `SPARC_CORE12.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH12         `SPARC_CORE12.sparc0.ifu.icv
    `define IFUPATH12         `SPARC_CORE12.sparc0.ifu
    `define TNUM12S           `SPARC_CORE12.sparc0.ifu.swl
    `define TPC12S            `SPARC_CORE12.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH12         `SPARC_CORE12.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH12         `SPARC_CORE12.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH12         `SPARC_CORE12.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH12         `SPARC_CORE12.sparc0.ifu.fdp
`endif
    `define ALUPATH12         `SPARC_CORE12.sparc0.exu.exu.alu
    `define SPCPATH12         `SPARC_CORE12.sparc0
    `define REGPATH12         `SPARC_CORE12.sparc0.exu.exu.irf.irf
    `define CCRPATH12         `SPARC_CORE12.sparc0.exu.exu.ecl.ccr
    `define EXUPATH12         `SPARC_CORE12.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH12          `SPARC_CORE12.sparc0.tlu.tlu.tcl
    `define TS0PATH12         `SPARC_CORE12.sparc0.tlu.tlu.tsa0
    `define TS1PATH12         `SPARC_CORE12.sparc0.tlu.tlu.tsa1
    `define INTPATH12         `SPARC_CORE12.sparc0.tlu.tlu.intdp
    `define ASIPATH12         `SPARC_CORE12.sparc0.lsu.lsu.dctl
    `define ASIDPPATH12       `SPARC_CORE12.sparc0.lsu.lsu.dctldp
    `define ICTPATH12         `SPARC_CORE12.sparc0.ifu.ifu.ict
    `define DCACHE12          `SPARC_CORE12.sparc0.lsu.lsu.dcache
    `define INSTPATH12        `SPARC_CORE12.sparc0.ifu.ifu.fcl
    `define PCPATH12          `SPARC_CORE12.sparc0.ifu.ifu
    `define DVLD12            `SPARC_CORE12.sparc0.lsu.lsu.dva
    `define DTAG12            `SPARC_CORE12.sparc0.lsu.lsu.dtag
    `define SDTAG12           `SPARC_CORE12.sparc0.lsu.lsu.dtag
    `define SDVLD12           `SPARC_CORE12.sparc0.lsu.lsu.dva
    `define FFUPATH12         `SPARC_CORE12.sparc0.ffu.ffu
    `define TLU_HYPER12       `SPARC_CORE12.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP12           `SPARC_CORE12.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH12        `SPARC_CORE12.sparc0.ifu.ifu.itlb
`else
    `define TLPATH12          `SPARC_CORE12.sparc0.tlu.tcl
    `define TS0PATH12         `SPARC_CORE12.sparc0.tlu.tsa0
    `define TS1PATH12         `SPARC_CORE12.sparc0.tlu.tsa1
    `define INTPATH12         `SPARC_CORE12.sparc0.tlu.intdp
    `define ASIPATH12         `SPARC_CORE12.sparc0.lsu.dctl
    `define ASIDPPATH12       `SPARC_CORE12.sparc0.lsu.dctldp
    `define ICTPATH12         `SPARC_CORE12.sparc0.ifu.ict
    `define DCACHE12          `SPARC_CORE12.sparc0.lsu.dcache
    `define INSTPATH12        `SPARC_CORE12.sparc0.ifu.fcl
    `define PCPATH12          `SPARC_CORE12.sparc0.ifu
    `define DVLD12            `SPARC_CORE12.sparc0.lsu.dva
    `define DTAG12            `SPARC_CORE12.sparc0.lsu.dtag
    `define SDTAG12           `SPARC_CORE12.sparc0.lsu.dtag
    `define SDVLD12           `SPARC_CORE12.sparc0.lsu.dva
    `define FFUPATH12         `SPARC_CORE12.sparc0.ffu
    `define TLU_HYPER12       `SPARC_CORE12.sparc0.tlu.tlu_hyperv
    `define IFQDP12           `SPARC_CORE12.sparc0.ifu.ifqdp
    `define ITLBPATH12        `SPARC_CORE12.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH12    `SPARC_CORE12.sparc0.cfg_asi

    `define PITON_CORE12_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc12_inst_done
`ifdef RTL_SPARC12
    `define PITON_CORE12_PC_W12     `PCPATH12.fdp.pc_w
`else
    `define PITON_CORE12_PC_W12     `TOP_MOD.monitor.pc_cmp.spc12_phy_pc_w
`endif

    

    `define TILE13            `CHIP.tile13
    `define ARIANE_CORE13     `TILE13.g_ariane_core.core.ariane
    `define SPARC_CORE13      `TILE13.g_sparc_core.core
    `define PICO_CORE13       `TILE13.g_picorv32_core.core
    `define CCX_TRANSDUCER13  `TILE13.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER13 `TILE13.g_picorv32_core.pico_l15_transducer
    `define L15_TOP13         `TILE13.l15.l15
    `define L15_PIPE13        `TILE13.l15.l15.pipeline
    `define DMBR13            `TILE13.dmbr_ins
    `define L2_TOP13          `TILE13.l2
    `define SPARC_REG13       `SPARC_CORE13.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH13       `SPARC_CORE13.sparc0.ffu.ffu
`else
    `define FLOATPATH13       `SPARC_CORE13.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH13         `SPARC_CORE13.sparc0.tlu.tlu
    `define DTLBPATH13        `SPARC_CORE13.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH13         `SPARC_CORE13.sparc0.tlu
    `define DTLBPATH13        `SPARC_CORE13.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH13         `SPARC_CORE13.sparc0
`ifndef RTL_SPU
    `define ICVPATH13         `SPARC_CORE13.sparc0.ifu.ifu.icv
    `define IFUPATH13         `SPARC_CORE13.sparc0.ifu.ifu
    `define TNUM13S           `SPARC_CORE13.sparc0.ifu.ifu.swl
    `define TPC13S            `SPARC_CORE13.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH13         `SPARC_CORE13.sparc0.ifu.icv
    `define IFUPATH13         `SPARC_CORE13.sparc0.ifu
    `define TNUM13S           `SPARC_CORE13.sparc0.ifu.swl
    `define TPC13S            `SPARC_CORE13.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH13         `SPARC_CORE13.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH13         `SPARC_CORE13.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH13         `SPARC_CORE13.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH13         `SPARC_CORE13.sparc0.ifu.fdp
`endif
    `define ALUPATH13         `SPARC_CORE13.sparc0.exu.exu.alu
    `define SPCPATH13         `SPARC_CORE13.sparc0
    `define REGPATH13         `SPARC_CORE13.sparc0.exu.exu.irf.irf
    `define CCRPATH13         `SPARC_CORE13.sparc0.exu.exu.ecl.ccr
    `define EXUPATH13         `SPARC_CORE13.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH13          `SPARC_CORE13.sparc0.tlu.tlu.tcl
    `define TS0PATH13         `SPARC_CORE13.sparc0.tlu.tlu.tsa0
    `define TS1PATH13         `SPARC_CORE13.sparc0.tlu.tlu.tsa1
    `define INTPATH13         `SPARC_CORE13.sparc0.tlu.tlu.intdp
    `define ASIPATH13         `SPARC_CORE13.sparc0.lsu.lsu.dctl
    `define ASIDPPATH13       `SPARC_CORE13.sparc0.lsu.lsu.dctldp
    `define ICTPATH13         `SPARC_CORE13.sparc0.ifu.ifu.ict
    `define DCACHE13          `SPARC_CORE13.sparc0.lsu.lsu.dcache
    `define INSTPATH13        `SPARC_CORE13.sparc0.ifu.ifu.fcl
    `define PCPATH13          `SPARC_CORE13.sparc0.ifu.ifu
    `define DVLD13            `SPARC_CORE13.sparc0.lsu.lsu.dva
    `define DTAG13            `SPARC_CORE13.sparc0.lsu.lsu.dtag
    `define SDTAG13           `SPARC_CORE13.sparc0.lsu.lsu.dtag
    `define SDVLD13           `SPARC_CORE13.sparc0.lsu.lsu.dva
    `define FFUPATH13         `SPARC_CORE13.sparc0.ffu.ffu
    `define TLU_HYPER13       `SPARC_CORE13.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP13           `SPARC_CORE13.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH13        `SPARC_CORE13.sparc0.ifu.ifu.itlb
`else
    `define TLPATH13          `SPARC_CORE13.sparc0.tlu.tcl
    `define TS0PATH13         `SPARC_CORE13.sparc0.tlu.tsa0
    `define TS1PATH13         `SPARC_CORE13.sparc0.tlu.tsa1
    `define INTPATH13         `SPARC_CORE13.sparc0.tlu.intdp
    `define ASIPATH13         `SPARC_CORE13.sparc0.lsu.dctl
    `define ASIDPPATH13       `SPARC_CORE13.sparc0.lsu.dctldp
    `define ICTPATH13         `SPARC_CORE13.sparc0.ifu.ict
    `define DCACHE13          `SPARC_CORE13.sparc0.lsu.dcache
    `define INSTPATH13        `SPARC_CORE13.sparc0.ifu.fcl
    `define PCPATH13          `SPARC_CORE13.sparc0.ifu
    `define DVLD13            `SPARC_CORE13.sparc0.lsu.dva
    `define DTAG13            `SPARC_CORE13.sparc0.lsu.dtag
    `define SDTAG13           `SPARC_CORE13.sparc0.lsu.dtag
    `define SDVLD13           `SPARC_CORE13.sparc0.lsu.dva
    `define FFUPATH13         `SPARC_CORE13.sparc0.ffu
    `define TLU_HYPER13       `SPARC_CORE13.sparc0.tlu.tlu_hyperv
    `define IFQDP13           `SPARC_CORE13.sparc0.ifu.ifqdp
    `define ITLBPATH13        `SPARC_CORE13.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH13    `SPARC_CORE13.sparc0.cfg_asi

    `define PITON_CORE13_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc13_inst_done
`ifdef RTL_SPARC13
    `define PITON_CORE13_PC_W13     `PCPATH13.fdp.pc_w
`else
    `define PITON_CORE13_PC_W13     `TOP_MOD.monitor.pc_cmp.spc13_phy_pc_w
`endif

    

    `define TILE14            `CHIP.tile14
    `define ARIANE_CORE14     `TILE14.g_ariane_core.core.ariane
    `define SPARC_CORE14      `TILE14.g_sparc_core.core
    `define PICO_CORE14       `TILE14.g_picorv32_core.core
    `define CCX_TRANSDUCER14  `TILE14.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER14 `TILE14.g_picorv32_core.pico_l15_transducer
    `define L15_TOP14         `TILE14.l15.l15
    `define L15_PIPE14        `TILE14.l15.l15.pipeline
    `define DMBR14            `TILE14.dmbr_ins
    `define L2_TOP14          `TILE14.l2
    `define SPARC_REG14       `SPARC_CORE14.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH14       `SPARC_CORE14.sparc0.ffu.ffu
`else
    `define FLOATPATH14       `SPARC_CORE14.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH14         `SPARC_CORE14.sparc0.tlu.tlu
    `define DTLBPATH14        `SPARC_CORE14.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH14         `SPARC_CORE14.sparc0.tlu
    `define DTLBPATH14        `SPARC_CORE14.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH14         `SPARC_CORE14.sparc0
`ifndef RTL_SPU
    `define ICVPATH14         `SPARC_CORE14.sparc0.ifu.ifu.icv
    `define IFUPATH14         `SPARC_CORE14.sparc0.ifu.ifu
    `define TNUM14S           `SPARC_CORE14.sparc0.ifu.ifu.swl
    `define TPC14S            `SPARC_CORE14.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH14         `SPARC_CORE14.sparc0.ifu.icv
    `define IFUPATH14         `SPARC_CORE14.sparc0.ifu
    `define TNUM14S           `SPARC_CORE14.sparc0.ifu.swl
    `define TPC14S            `SPARC_CORE14.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH14         `SPARC_CORE14.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH14         `SPARC_CORE14.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH14         `SPARC_CORE14.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH14         `SPARC_CORE14.sparc0.ifu.fdp
`endif
    `define ALUPATH14         `SPARC_CORE14.sparc0.exu.exu.alu
    `define SPCPATH14         `SPARC_CORE14.sparc0
    `define REGPATH14         `SPARC_CORE14.sparc0.exu.exu.irf.irf
    `define CCRPATH14         `SPARC_CORE14.sparc0.exu.exu.ecl.ccr
    `define EXUPATH14         `SPARC_CORE14.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH14          `SPARC_CORE14.sparc0.tlu.tlu.tcl
    `define TS0PATH14         `SPARC_CORE14.sparc0.tlu.tlu.tsa0
    `define TS1PATH14         `SPARC_CORE14.sparc0.tlu.tlu.tsa1
    `define INTPATH14         `SPARC_CORE14.sparc0.tlu.tlu.intdp
    `define ASIPATH14         `SPARC_CORE14.sparc0.lsu.lsu.dctl
    `define ASIDPPATH14       `SPARC_CORE14.sparc0.lsu.lsu.dctldp
    `define ICTPATH14         `SPARC_CORE14.sparc0.ifu.ifu.ict
    `define DCACHE14          `SPARC_CORE14.sparc0.lsu.lsu.dcache
    `define INSTPATH14        `SPARC_CORE14.sparc0.ifu.ifu.fcl
    `define PCPATH14          `SPARC_CORE14.sparc0.ifu.ifu
    `define DVLD14            `SPARC_CORE14.sparc0.lsu.lsu.dva
    `define DTAG14            `SPARC_CORE14.sparc0.lsu.lsu.dtag
    `define SDTAG14           `SPARC_CORE14.sparc0.lsu.lsu.dtag
    `define SDVLD14           `SPARC_CORE14.sparc0.lsu.lsu.dva
    `define FFUPATH14         `SPARC_CORE14.sparc0.ffu.ffu
    `define TLU_HYPER14       `SPARC_CORE14.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP14           `SPARC_CORE14.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH14        `SPARC_CORE14.sparc0.ifu.ifu.itlb
`else
    `define TLPATH14          `SPARC_CORE14.sparc0.tlu.tcl
    `define TS0PATH14         `SPARC_CORE14.sparc0.tlu.tsa0
    `define TS1PATH14         `SPARC_CORE14.sparc0.tlu.tsa1
    `define INTPATH14         `SPARC_CORE14.sparc0.tlu.intdp
    `define ASIPATH14         `SPARC_CORE14.sparc0.lsu.dctl
    `define ASIDPPATH14       `SPARC_CORE14.sparc0.lsu.dctldp
    `define ICTPATH14         `SPARC_CORE14.sparc0.ifu.ict
    `define DCACHE14          `SPARC_CORE14.sparc0.lsu.dcache
    `define INSTPATH14        `SPARC_CORE14.sparc0.ifu.fcl
    `define PCPATH14          `SPARC_CORE14.sparc0.ifu
    `define DVLD14            `SPARC_CORE14.sparc0.lsu.dva
    `define DTAG14            `SPARC_CORE14.sparc0.lsu.dtag
    `define SDTAG14           `SPARC_CORE14.sparc0.lsu.dtag
    `define SDVLD14           `SPARC_CORE14.sparc0.lsu.dva
    `define FFUPATH14         `SPARC_CORE14.sparc0.ffu
    `define TLU_HYPER14       `SPARC_CORE14.sparc0.tlu.tlu_hyperv
    `define IFQDP14           `SPARC_CORE14.sparc0.ifu.ifqdp
    `define ITLBPATH14        `SPARC_CORE14.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH14    `SPARC_CORE14.sparc0.cfg_asi

    `define PITON_CORE14_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc14_inst_done
`ifdef RTL_SPARC14
    `define PITON_CORE14_PC_W14     `PCPATH14.fdp.pc_w
`else
    `define PITON_CORE14_PC_W14     `TOP_MOD.monitor.pc_cmp.spc14_phy_pc_w
`endif

    

    `define TILE15            `CHIP.tile15
    `define ARIANE_CORE15     `TILE15.g_ariane_core.core.ariane
    `define SPARC_CORE15      `TILE15.g_sparc_core.core
    `define PICO_CORE15       `TILE15.g_picorv32_core.core
    `define CCX_TRANSDUCER15  `TILE15.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER15 `TILE15.g_picorv32_core.pico_l15_transducer
    `define L15_TOP15         `TILE15.l15.l15
    `define L15_PIPE15        `TILE15.l15.l15.pipeline
    `define DMBR15            `TILE15.dmbr_ins
    `define L2_TOP15          `TILE15.l2
    `define SPARC_REG15       `SPARC_CORE15.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH15       `SPARC_CORE15.sparc0.ffu.ffu
`else
    `define FLOATPATH15       `SPARC_CORE15.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH15         `SPARC_CORE15.sparc0.tlu.tlu
    `define DTLBPATH15        `SPARC_CORE15.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH15         `SPARC_CORE15.sparc0.tlu
    `define DTLBPATH15        `SPARC_CORE15.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH15         `SPARC_CORE15.sparc0
`ifndef RTL_SPU
    `define ICVPATH15         `SPARC_CORE15.sparc0.ifu.ifu.icv
    `define IFUPATH15         `SPARC_CORE15.sparc0.ifu.ifu
    `define TNUM15S           `SPARC_CORE15.sparc0.ifu.ifu.swl
    `define TPC15S            `SPARC_CORE15.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH15         `SPARC_CORE15.sparc0.ifu.icv
    `define IFUPATH15         `SPARC_CORE15.sparc0.ifu
    `define TNUM15S           `SPARC_CORE15.sparc0.ifu.swl
    `define TPC15S            `SPARC_CORE15.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH15         `SPARC_CORE15.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH15         `SPARC_CORE15.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH15         `SPARC_CORE15.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH15         `SPARC_CORE15.sparc0.ifu.fdp
`endif
    `define ALUPATH15         `SPARC_CORE15.sparc0.exu.exu.alu
    `define SPCPATH15         `SPARC_CORE15.sparc0
    `define REGPATH15         `SPARC_CORE15.sparc0.exu.exu.irf.irf
    `define CCRPATH15         `SPARC_CORE15.sparc0.exu.exu.ecl.ccr
    `define EXUPATH15         `SPARC_CORE15.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH15          `SPARC_CORE15.sparc0.tlu.tlu.tcl
    `define TS0PATH15         `SPARC_CORE15.sparc0.tlu.tlu.tsa0
    `define TS1PATH15         `SPARC_CORE15.sparc0.tlu.tlu.tsa1
    `define INTPATH15         `SPARC_CORE15.sparc0.tlu.tlu.intdp
    `define ASIPATH15         `SPARC_CORE15.sparc0.lsu.lsu.dctl
    `define ASIDPPATH15       `SPARC_CORE15.sparc0.lsu.lsu.dctldp
    `define ICTPATH15         `SPARC_CORE15.sparc0.ifu.ifu.ict
    `define DCACHE15          `SPARC_CORE15.sparc0.lsu.lsu.dcache
    `define INSTPATH15        `SPARC_CORE15.sparc0.ifu.ifu.fcl
    `define PCPATH15          `SPARC_CORE15.sparc0.ifu.ifu
    `define DVLD15            `SPARC_CORE15.sparc0.lsu.lsu.dva
    `define DTAG15            `SPARC_CORE15.sparc0.lsu.lsu.dtag
    `define SDTAG15           `SPARC_CORE15.sparc0.lsu.lsu.dtag
    `define SDVLD15           `SPARC_CORE15.sparc0.lsu.lsu.dva
    `define FFUPATH15         `SPARC_CORE15.sparc0.ffu.ffu
    `define TLU_HYPER15       `SPARC_CORE15.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP15           `SPARC_CORE15.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH15        `SPARC_CORE15.sparc0.ifu.ifu.itlb
`else
    `define TLPATH15          `SPARC_CORE15.sparc0.tlu.tcl
    `define TS0PATH15         `SPARC_CORE15.sparc0.tlu.tsa0
    `define TS1PATH15         `SPARC_CORE15.sparc0.tlu.tsa1
    `define INTPATH15         `SPARC_CORE15.sparc0.tlu.intdp
    `define ASIPATH15         `SPARC_CORE15.sparc0.lsu.dctl
    `define ASIDPPATH15       `SPARC_CORE15.sparc0.lsu.dctldp
    `define ICTPATH15         `SPARC_CORE15.sparc0.ifu.ict
    `define DCACHE15          `SPARC_CORE15.sparc0.lsu.dcache
    `define INSTPATH15        `SPARC_CORE15.sparc0.ifu.fcl
    `define PCPATH15          `SPARC_CORE15.sparc0.ifu
    `define DVLD15            `SPARC_CORE15.sparc0.lsu.dva
    `define DTAG15            `SPARC_CORE15.sparc0.lsu.dtag
    `define SDTAG15           `SPARC_CORE15.sparc0.lsu.dtag
    `define SDVLD15           `SPARC_CORE15.sparc0.lsu.dva
    `define FFUPATH15         `SPARC_CORE15.sparc0.ffu
    `define TLU_HYPER15       `SPARC_CORE15.sparc0.tlu.tlu_hyperv
    `define IFQDP15           `SPARC_CORE15.sparc0.ifu.ifqdp
    `define ITLBPATH15        `SPARC_CORE15.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH15    `SPARC_CORE15.sparc0.cfg_asi

    `define PITON_CORE15_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc15_inst_done
`ifdef RTL_SPARC15
    `define PITON_CORE15_PC_W15     `PCPATH15.fdp.pc_w
`else
    `define PITON_CORE15_PC_W15     `TOP_MOD.monitor.pc_cmp.spc15_phy_pc_w
`endif

    

    `define TILE16            `CHIP.tile16
    `define ARIANE_CORE16     `TILE16.g_ariane_core.core.ariane
    `define SPARC_CORE16      `TILE16.g_sparc_core.core
    `define PICO_CORE16       `TILE16.g_picorv32_core.core
    `define CCX_TRANSDUCER16  `TILE16.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER16 `TILE16.g_picorv32_core.pico_l15_transducer
    `define L15_TOP16         `TILE16.l15.l15
    `define L15_PIPE16        `TILE16.l15.l15.pipeline
    `define DMBR16            `TILE16.dmbr_ins
    `define L2_TOP16          `TILE16.l2
    `define SPARC_REG16       `SPARC_CORE16.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH16       `SPARC_CORE16.sparc0.ffu.ffu
`else
    `define FLOATPATH16       `SPARC_CORE16.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH16         `SPARC_CORE16.sparc0.tlu.tlu
    `define DTLBPATH16        `SPARC_CORE16.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH16         `SPARC_CORE16.sparc0.tlu
    `define DTLBPATH16        `SPARC_CORE16.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH16         `SPARC_CORE16.sparc0
`ifndef RTL_SPU
    `define ICVPATH16         `SPARC_CORE16.sparc0.ifu.ifu.icv
    `define IFUPATH16         `SPARC_CORE16.sparc0.ifu.ifu
    `define TNUM16S           `SPARC_CORE16.sparc0.ifu.ifu.swl
    `define TPC16S            `SPARC_CORE16.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH16         `SPARC_CORE16.sparc0.ifu.icv
    `define IFUPATH16         `SPARC_CORE16.sparc0.ifu
    `define TNUM16S           `SPARC_CORE16.sparc0.ifu.swl
    `define TPC16S            `SPARC_CORE16.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH16         `SPARC_CORE16.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH16         `SPARC_CORE16.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH16         `SPARC_CORE16.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH16         `SPARC_CORE16.sparc0.ifu.fdp
`endif
    `define ALUPATH16         `SPARC_CORE16.sparc0.exu.exu.alu
    `define SPCPATH16         `SPARC_CORE16.sparc0
    `define REGPATH16         `SPARC_CORE16.sparc0.exu.exu.irf.irf
    `define CCRPATH16         `SPARC_CORE16.sparc0.exu.exu.ecl.ccr
    `define EXUPATH16         `SPARC_CORE16.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH16          `SPARC_CORE16.sparc0.tlu.tlu.tcl
    `define TS0PATH16         `SPARC_CORE16.sparc0.tlu.tlu.tsa0
    `define TS1PATH16         `SPARC_CORE16.sparc0.tlu.tlu.tsa1
    `define INTPATH16         `SPARC_CORE16.sparc0.tlu.tlu.intdp
    `define ASIPATH16         `SPARC_CORE16.sparc0.lsu.lsu.dctl
    `define ASIDPPATH16       `SPARC_CORE16.sparc0.lsu.lsu.dctldp
    `define ICTPATH16         `SPARC_CORE16.sparc0.ifu.ifu.ict
    `define DCACHE16          `SPARC_CORE16.sparc0.lsu.lsu.dcache
    `define INSTPATH16        `SPARC_CORE16.sparc0.ifu.ifu.fcl
    `define PCPATH16          `SPARC_CORE16.sparc0.ifu.ifu
    `define DVLD16            `SPARC_CORE16.sparc0.lsu.lsu.dva
    `define DTAG16            `SPARC_CORE16.sparc0.lsu.lsu.dtag
    `define SDTAG16           `SPARC_CORE16.sparc0.lsu.lsu.dtag
    `define SDVLD16           `SPARC_CORE16.sparc0.lsu.lsu.dva
    `define FFUPATH16         `SPARC_CORE16.sparc0.ffu.ffu
    `define TLU_HYPER16       `SPARC_CORE16.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP16           `SPARC_CORE16.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH16        `SPARC_CORE16.sparc0.ifu.ifu.itlb
`else
    `define TLPATH16          `SPARC_CORE16.sparc0.tlu.tcl
    `define TS0PATH16         `SPARC_CORE16.sparc0.tlu.tsa0
    `define TS1PATH16         `SPARC_CORE16.sparc0.tlu.tsa1
    `define INTPATH16         `SPARC_CORE16.sparc0.tlu.intdp
    `define ASIPATH16         `SPARC_CORE16.sparc0.lsu.dctl
    `define ASIDPPATH16       `SPARC_CORE16.sparc0.lsu.dctldp
    `define ICTPATH16         `SPARC_CORE16.sparc0.ifu.ict
    `define DCACHE16          `SPARC_CORE16.sparc0.lsu.dcache
    `define INSTPATH16        `SPARC_CORE16.sparc0.ifu.fcl
    `define PCPATH16          `SPARC_CORE16.sparc0.ifu
    `define DVLD16            `SPARC_CORE16.sparc0.lsu.dva
    `define DTAG16            `SPARC_CORE16.sparc0.lsu.dtag
    `define SDTAG16           `SPARC_CORE16.sparc0.lsu.dtag
    `define SDVLD16           `SPARC_CORE16.sparc0.lsu.dva
    `define FFUPATH16         `SPARC_CORE16.sparc0.ffu
    `define TLU_HYPER16       `SPARC_CORE16.sparc0.tlu.tlu_hyperv
    `define IFQDP16           `SPARC_CORE16.sparc0.ifu.ifqdp
    `define ITLBPATH16        `SPARC_CORE16.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH16    `SPARC_CORE16.sparc0.cfg_asi

    `define PITON_CORE16_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc16_inst_done
`ifdef RTL_SPARC16
    `define PITON_CORE16_PC_W16     `PCPATH16.fdp.pc_w
`else
    `define PITON_CORE16_PC_W16     `TOP_MOD.monitor.pc_cmp.spc16_phy_pc_w
`endif

    

    `define TILE17            `CHIP.tile17
    `define ARIANE_CORE17     `TILE17.g_ariane_core.core.ariane
    `define SPARC_CORE17      `TILE17.g_sparc_core.core
    `define PICO_CORE17       `TILE17.g_picorv32_core.core
    `define CCX_TRANSDUCER17  `TILE17.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER17 `TILE17.g_picorv32_core.pico_l15_transducer
    `define L15_TOP17         `TILE17.l15.l15
    `define L15_PIPE17        `TILE17.l15.l15.pipeline
    `define DMBR17            `TILE17.dmbr_ins
    `define L2_TOP17          `TILE17.l2
    `define SPARC_REG17       `SPARC_CORE17.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH17       `SPARC_CORE17.sparc0.ffu.ffu
`else
    `define FLOATPATH17       `SPARC_CORE17.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH17         `SPARC_CORE17.sparc0.tlu.tlu
    `define DTLBPATH17        `SPARC_CORE17.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH17         `SPARC_CORE17.sparc0.tlu
    `define DTLBPATH17        `SPARC_CORE17.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH17         `SPARC_CORE17.sparc0
`ifndef RTL_SPU
    `define ICVPATH17         `SPARC_CORE17.sparc0.ifu.ifu.icv
    `define IFUPATH17         `SPARC_CORE17.sparc0.ifu.ifu
    `define TNUM17S           `SPARC_CORE17.sparc0.ifu.ifu.swl
    `define TPC17S            `SPARC_CORE17.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH17         `SPARC_CORE17.sparc0.ifu.icv
    `define IFUPATH17         `SPARC_CORE17.sparc0.ifu
    `define TNUM17S           `SPARC_CORE17.sparc0.ifu.swl
    `define TPC17S            `SPARC_CORE17.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH17         `SPARC_CORE17.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH17         `SPARC_CORE17.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH17         `SPARC_CORE17.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH17         `SPARC_CORE17.sparc0.ifu.fdp
`endif
    `define ALUPATH17         `SPARC_CORE17.sparc0.exu.exu.alu
    `define SPCPATH17         `SPARC_CORE17.sparc0
    `define REGPATH17         `SPARC_CORE17.sparc0.exu.exu.irf.irf
    `define CCRPATH17         `SPARC_CORE17.sparc0.exu.exu.ecl.ccr
    `define EXUPATH17         `SPARC_CORE17.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH17          `SPARC_CORE17.sparc0.tlu.tlu.tcl
    `define TS0PATH17         `SPARC_CORE17.sparc0.tlu.tlu.tsa0
    `define TS1PATH17         `SPARC_CORE17.sparc0.tlu.tlu.tsa1
    `define INTPATH17         `SPARC_CORE17.sparc0.tlu.tlu.intdp
    `define ASIPATH17         `SPARC_CORE17.sparc0.lsu.lsu.dctl
    `define ASIDPPATH17       `SPARC_CORE17.sparc0.lsu.lsu.dctldp
    `define ICTPATH17         `SPARC_CORE17.sparc0.ifu.ifu.ict
    `define DCACHE17          `SPARC_CORE17.sparc0.lsu.lsu.dcache
    `define INSTPATH17        `SPARC_CORE17.sparc0.ifu.ifu.fcl
    `define PCPATH17          `SPARC_CORE17.sparc0.ifu.ifu
    `define DVLD17            `SPARC_CORE17.sparc0.lsu.lsu.dva
    `define DTAG17            `SPARC_CORE17.sparc0.lsu.lsu.dtag
    `define SDTAG17           `SPARC_CORE17.sparc0.lsu.lsu.dtag
    `define SDVLD17           `SPARC_CORE17.sparc0.lsu.lsu.dva
    `define FFUPATH17         `SPARC_CORE17.sparc0.ffu.ffu
    `define TLU_HYPER17       `SPARC_CORE17.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP17           `SPARC_CORE17.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH17        `SPARC_CORE17.sparc0.ifu.ifu.itlb
`else
    `define TLPATH17          `SPARC_CORE17.sparc0.tlu.tcl
    `define TS0PATH17         `SPARC_CORE17.sparc0.tlu.tsa0
    `define TS1PATH17         `SPARC_CORE17.sparc0.tlu.tsa1
    `define INTPATH17         `SPARC_CORE17.sparc0.tlu.intdp
    `define ASIPATH17         `SPARC_CORE17.sparc0.lsu.dctl
    `define ASIDPPATH17       `SPARC_CORE17.sparc0.lsu.dctldp
    `define ICTPATH17         `SPARC_CORE17.sparc0.ifu.ict
    `define DCACHE17          `SPARC_CORE17.sparc0.lsu.dcache
    `define INSTPATH17        `SPARC_CORE17.sparc0.ifu.fcl
    `define PCPATH17          `SPARC_CORE17.sparc0.ifu
    `define DVLD17            `SPARC_CORE17.sparc0.lsu.dva
    `define DTAG17            `SPARC_CORE17.sparc0.lsu.dtag
    `define SDTAG17           `SPARC_CORE17.sparc0.lsu.dtag
    `define SDVLD17           `SPARC_CORE17.sparc0.lsu.dva
    `define FFUPATH17         `SPARC_CORE17.sparc0.ffu
    `define TLU_HYPER17       `SPARC_CORE17.sparc0.tlu.tlu_hyperv
    `define IFQDP17           `SPARC_CORE17.sparc0.ifu.ifqdp
    `define ITLBPATH17        `SPARC_CORE17.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH17    `SPARC_CORE17.sparc0.cfg_asi

    `define PITON_CORE17_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc17_inst_done
`ifdef RTL_SPARC17
    `define PITON_CORE17_PC_W17     `PCPATH17.fdp.pc_w
`else
    `define PITON_CORE17_PC_W17     `TOP_MOD.monitor.pc_cmp.spc17_phy_pc_w
`endif

    

    `define TILE18            `CHIP.tile18
    `define ARIANE_CORE18     `TILE18.g_ariane_core.core.ariane
    `define SPARC_CORE18      `TILE18.g_sparc_core.core
    `define PICO_CORE18       `TILE18.g_picorv32_core.core
    `define CCX_TRANSDUCER18  `TILE18.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER18 `TILE18.g_picorv32_core.pico_l15_transducer
    `define L15_TOP18         `TILE18.l15.l15
    `define L15_PIPE18        `TILE18.l15.l15.pipeline
    `define DMBR18            `TILE18.dmbr_ins
    `define L2_TOP18          `TILE18.l2
    `define SPARC_REG18       `SPARC_CORE18.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH18       `SPARC_CORE18.sparc0.ffu.ffu
`else
    `define FLOATPATH18       `SPARC_CORE18.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH18         `SPARC_CORE18.sparc0.tlu.tlu
    `define DTLBPATH18        `SPARC_CORE18.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH18         `SPARC_CORE18.sparc0.tlu
    `define DTLBPATH18        `SPARC_CORE18.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH18         `SPARC_CORE18.sparc0
`ifndef RTL_SPU
    `define ICVPATH18         `SPARC_CORE18.sparc0.ifu.ifu.icv
    `define IFUPATH18         `SPARC_CORE18.sparc0.ifu.ifu
    `define TNUM18S           `SPARC_CORE18.sparc0.ifu.ifu.swl
    `define TPC18S            `SPARC_CORE18.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH18         `SPARC_CORE18.sparc0.ifu.icv
    `define IFUPATH18         `SPARC_CORE18.sparc0.ifu
    `define TNUM18S           `SPARC_CORE18.sparc0.ifu.swl
    `define TPC18S            `SPARC_CORE18.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH18         `SPARC_CORE18.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH18         `SPARC_CORE18.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH18         `SPARC_CORE18.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH18         `SPARC_CORE18.sparc0.ifu.fdp
`endif
    `define ALUPATH18         `SPARC_CORE18.sparc0.exu.exu.alu
    `define SPCPATH18         `SPARC_CORE18.sparc0
    `define REGPATH18         `SPARC_CORE18.sparc0.exu.exu.irf.irf
    `define CCRPATH18         `SPARC_CORE18.sparc0.exu.exu.ecl.ccr
    `define EXUPATH18         `SPARC_CORE18.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH18          `SPARC_CORE18.sparc0.tlu.tlu.tcl
    `define TS0PATH18         `SPARC_CORE18.sparc0.tlu.tlu.tsa0
    `define TS1PATH18         `SPARC_CORE18.sparc0.tlu.tlu.tsa1
    `define INTPATH18         `SPARC_CORE18.sparc0.tlu.tlu.intdp
    `define ASIPATH18         `SPARC_CORE18.sparc0.lsu.lsu.dctl
    `define ASIDPPATH18       `SPARC_CORE18.sparc0.lsu.lsu.dctldp
    `define ICTPATH18         `SPARC_CORE18.sparc0.ifu.ifu.ict
    `define DCACHE18          `SPARC_CORE18.sparc0.lsu.lsu.dcache
    `define INSTPATH18        `SPARC_CORE18.sparc0.ifu.ifu.fcl
    `define PCPATH18          `SPARC_CORE18.sparc0.ifu.ifu
    `define DVLD18            `SPARC_CORE18.sparc0.lsu.lsu.dva
    `define DTAG18            `SPARC_CORE18.sparc0.lsu.lsu.dtag
    `define SDTAG18           `SPARC_CORE18.sparc0.lsu.lsu.dtag
    `define SDVLD18           `SPARC_CORE18.sparc0.lsu.lsu.dva
    `define FFUPATH18         `SPARC_CORE18.sparc0.ffu.ffu
    `define TLU_HYPER18       `SPARC_CORE18.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP18           `SPARC_CORE18.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH18        `SPARC_CORE18.sparc0.ifu.ifu.itlb
`else
    `define TLPATH18          `SPARC_CORE18.sparc0.tlu.tcl
    `define TS0PATH18         `SPARC_CORE18.sparc0.tlu.tsa0
    `define TS1PATH18         `SPARC_CORE18.sparc0.tlu.tsa1
    `define INTPATH18         `SPARC_CORE18.sparc0.tlu.intdp
    `define ASIPATH18         `SPARC_CORE18.sparc0.lsu.dctl
    `define ASIDPPATH18       `SPARC_CORE18.sparc0.lsu.dctldp
    `define ICTPATH18         `SPARC_CORE18.sparc0.ifu.ict
    `define DCACHE18          `SPARC_CORE18.sparc0.lsu.dcache
    `define INSTPATH18        `SPARC_CORE18.sparc0.ifu.fcl
    `define PCPATH18          `SPARC_CORE18.sparc0.ifu
    `define DVLD18            `SPARC_CORE18.sparc0.lsu.dva
    `define DTAG18            `SPARC_CORE18.sparc0.lsu.dtag
    `define SDTAG18           `SPARC_CORE18.sparc0.lsu.dtag
    `define SDVLD18           `SPARC_CORE18.sparc0.lsu.dva
    `define FFUPATH18         `SPARC_CORE18.sparc0.ffu
    `define TLU_HYPER18       `SPARC_CORE18.sparc0.tlu.tlu_hyperv
    `define IFQDP18           `SPARC_CORE18.sparc0.ifu.ifqdp
    `define ITLBPATH18        `SPARC_CORE18.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH18    `SPARC_CORE18.sparc0.cfg_asi

    `define PITON_CORE18_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc18_inst_done
`ifdef RTL_SPARC18
    `define PITON_CORE18_PC_W18     `PCPATH18.fdp.pc_w
`else
    `define PITON_CORE18_PC_W18     `TOP_MOD.monitor.pc_cmp.spc18_phy_pc_w
`endif

    

    `define TILE19            `CHIP.tile19
    `define ARIANE_CORE19     `TILE19.g_ariane_core.core.ariane
    `define SPARC_CORE19      `TILE19.g_sparc_core.core
    `define PICO_CORE19       `TILE19.g_picorv32_core.core
    `define CCX_TRANSDUCER19  `TILE19.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER19 `TILE19.g_picorv32_core.pico_l15_transducer
    `define L15_TOP19         `TILE19.l15.l15
    `define L15_PIPE19        `TILE19.l15.l15.pipeline
    `define DMBR19            `TILE19.dmbr_ins
    `define L2_TOP19          `TILE19.l2
    `define SPARC_REG19       `SPARC_CORE19.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH19       `SPARC_CORE19.sparc0.ffu.ffu
`else
    `define FLOATPATH19       `SPARC_CORE19.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH19         `SPARC_CORE19.sparc0.tlu.tlu
    `define DTLBPATH19        `SPARC_CORE19.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH19         `SPARC_CORE19.sparc0.tlu
    `define DTLBPATH19        `SPARC_CORE19.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH19         `SPARC_CORE19.sparc0
`ifndef RTL_SPU
    `define ICVPATH19         `SPARC_CORE19.sparc0.ifu.ifu.icv
    `define IFUPATH19         `SPARC_CORE19.sparc0.ifu.ifu
    `define TNUM19S           `SPARC_CORE19.sparc0.ifu.ifu.swl
    `define TPC19S            `SPARC_CORE19.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH19         `SPARC_CORE19.sparc0.ifu.icv
    `define IFUPATH19         `SPARC_CORE19.sparc0.ifu
    `define TNUM19S           `SPARC_CORE19.sparc0.ifu.swl
    `define TPC19S            `SPARC_CORE19.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH19         `SPARC_CORE19.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH19         `SPARC_CORE19.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH19         `SPARC_CORE19.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH19         `SPARC_CORE19.sparc0.ifu.fdp
`endif
    `define ALUPATH19         `SPARC_CORE19.sparc0.exu.exu.alu
    `define SPCPATH19         `SPARC_CORE19.sparc0
    `define REGPATH19         `SPARC_CORE19.sparc0.exu.exu.irf.irf
    `define CCRPATH19         `SPARC_CORE19.sparc0.exu.exu.ecl.ccr
    `define EXUPATH19         `SPARC_CORE19.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH19          `SPARC_CORE19.sparc0.tlu.tlu.tcl
    `define TS0PATH19         `SPARC_CORE19.sparc0.tlu.tlu.tsa0
    `define TS1PATH19         `SPARC_CORE19.sparc0.tlu.tlu.tsa1
    `define INTPATH19         `SPARC_CORE19.sparc0.tlu.tlu.intdp
    `define ASIPATH19         `SPARC_CORE19.sparc0.lsu.lsu.dctl
    `define ASIDPPATH19       `SPARC_CORE19.sparc0.lsu.lsu.dctldp
    `define ICTPATH19         `SPARC_CORE19.sparc0.ifu.ifu.ict
    `define DCACHE19          `SPARC_CORE19.sparc0.lsu.lsu.dcache
    `define INSTPATH19        `SPARC_CORE19.sparc0.ifu.ifu.fcl
    `define PCPATH19          `SPARC_CORE19.sparc0.ifu.ifu
    `define DVLD19            `SPARC_CORE19.sparc0.lsu.lsu.dva
    `define DTAG19            `SPARC_CORE19.sparc0.lsu.lsu.dtag
    `define SDTAG19           `SPARC_CORE19.sparc0.lsu.lsu.dtag
    `define SDVLD19           `SPARC_CORE19.sparc0.lsu.lsu.dva
    `define FFUPATH19         `SPARC_CORE19.sparc0.ffu.ffu
    `define TLU_HYPER19       `SPARC_CORE19.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP19           `SPARC_CORE19.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH19        `SPARC_CORE19.sparc0.ifu.ifu.itlb
`else
    `define TLPATH19          `SPARC_CORE19.sparc0.tlu.tcl
    `define TS0PATH19         `SPARC_CORE19.sparc0.tlu.tsa0
    `define TS1PATH19         `SPARC_CORE19.sparc0.tlu.tsa1
    `define INTPATH19         `SPARC_CORE19.sparc0.tlu.intdp
    `define ASIPATH19         `SPARC_CORE19.sparc0.lsu.dctl
    `define ASIDPPATH19       `SPARC_CORE19.sparc0.lsu.dctldp
    `define ICTPATH19         `SPARC_CORE19.sparc0.ifu.ict
    `define DCACHE19          `SPARC_CORE19.sparc0.lsu.dcache
    `define INSTPATH19        `SPARC_CORE19.sparc0.ifu.fcl
    `define PCPATH19          `SPARC_CORE19.sparc0.ifu
    `define DVLD19            `SPARC_CORE19.sparc0.lsu.dva
    `define DTAG19            `SPARC_CORE19.sparc0.lsu.dtag
    `define SDTAG19           `SPARC_CORE19.sparc0.lsu.dtag
    `define SDVLD19           `SPARC_CORE19.sparc0.lsu.dva
    `define FFUPATH19         `SPARC_CORE19.sparc0.ffu
    `define TLU_HYPER19       `SPARC_CORE19.sparc0.tlu.tlu_hyperv
    `define IFQDP19           `SPARC_CORE19.sparc0.ifu.ifqdp
    `define ITLBPATH19        `SPARC_CORE19.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH19    `SPARC_CORE19.sparc0.cfg_asi

    `define PITON_CORE19_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc19_inst_done
`ifdef RTL_SPARC19
    `define PITON_CORE19_PC_W19     `PCPATH19.fdp.pc_w
`else
    `define PITON_CORE19_PC_W19     `TOP_MOD.monitor.pc_cmp.spc19_phy_pc_w
`endif

    

    `define TILE20            `CHIP.tile20
    `define ARIANE_CORE20     `TILE20.g_ariane_core.core.ariane
    `define SPARC_CORE20      `TILE20.g_sparc_core.core
    `define PICO_CORE20       `TILE20.g_picorv32_core.core
    `define CCX_TRANSDUCER20  `TILE20.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER20 `TILE20.g_picorv32_core.pico_l15_transducer
    `define L15_TOP20         `TILE20.l15.l15
    `define L15_PIPE20        `TILE20.l15.l15.pipeline
    `define DMBR20            `TILE20.dmbr_ins
    `define L2_TOP20          `TILE20.l2
    `define SPARC_REG20       `SPARC_CORE20.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH20       `SPARC_CORE20.sparc0.ffu.ffu
`else
    `define FLOATPATH20       `SPARC_CORE20.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH20         `SPARC_CORE20.sparc0.tlu.tlu
    `define DTLBPATH20        `SPARC_CORE20.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH20         `SPARC_CORE20.sparc0.tlu
    `define DTLBPATH20        `SPARC_CORE20.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH20         `SPARC_CORE20.sparc0
`ifndef RTL_SPU
    `define ICVPATH20         `SPARC_CORE20.sparc0.ifu.ifu.icv
    `define IFUPATH20         `SPARC_CORE20.sparc0.ifu.ifu
    `define TNUM20S           `SPARC_CORE20.sparc0.ifu.ifu.swl
    `define TPC20S            `SPARC_CORE20.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH20         `SPARC_CORE20.sparc0.ifu.icv
    `define IFUPATH20         `SPARC_CORE20.sparc0.ifu
    `define TNUM20S           `SPARC_CORE20.sparc0.ifu.swl
    `define TPC20S            `SPARC_CORE20.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH20         `SPARC_CORE20.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH20         `SPARC_CORE20.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH20         `SPARC_CORE20.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH20         `SPARC_CORE20.sparc0.ifu.fdp
`endif
    `define ALUPATH20         `SPARC_CORE20.sparc0.exu.exu.alu
    `define SPCPATH20         `SPARC_CORE20.sparc0
    `define REGPATH20         `SPARC_CORE20.sparc0.exu.exu.irf.irf
    `define CCRPATH20         `SPARC_CORE20.sparc0.exu.exu.ecl.ccr
    `define EXUPATH20         `SPARC_CORE20.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH20          `SPARC_CORE20.sparc0.tlu.tlu.tcl
    `define TS0PATH20         `SPARC_CORE20.sparc0.tlu.tlu.tsa0
    `define TS1PATH20         `SPARC_CORE20.sparc0.tlu.tlu.tsa1
    `define INTPATH20         `SPARC_CORE20.sparc0.tlu.tlu.intdp
    `define ASIPATH20         `SPARC_CORE20.sparc0.lsu.lsu.dctl
    `define ASIDPPATH20       `SPARC_CORE20.sparc0.lsu.lsu.dctldp
    `define ICTPATH20         `SPARC_CORE20.sparc0.ifu.ifu.ict
    `define DCACHE20          `SPARC_CORE20.sparc0.lsu.lsu.dcache
    `define INSTPATH20        `SPARC_CORE20.sparc0.ifu.ifu.fcl
    `define PCPATH20          `SPARC_CORE20.sparc0.ifu.ifu
    `define DVLD20            `SPARC_CORE20.sparc0.lsu.lsu.dva
    `define DTAG20            `SPARC_CORE20.sparc0.lsu.lsu.dtag
    `define SDTAG20           `SPARC_CORE20.sparc0.lsu.lsu.dtag
    `define SDVLD20           `SPARC_CORE20.sparc0.lsu.lsu.dva
    `define FFUPATH20         `SPARC_CORE20.sparc0.ffu.ffu
    `define TLU_HYPER20       `SPARC_CORE20.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP20           `SPARC_CORE20.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH20        `SPARC_CORE20.sparc0.ifu.ifu.itlb
`else
    `define TLPATH20          `SPARC_CORE20.sparc0.tlu.tcl
    `define TS0PATH20         `SPARC_CORE20.sparc0.tlu.tsa0
    `define TS1PATH20         `SPARC_CORE20.sparc0.tlu.tsa1
    `define INTPATH20         `SPARC_CORE20.sparc0.tlu.intdp
    `define ASIPATH20         `SPARC_CORE20.sparc0.lsu.dctl
    `define ASIDPPATH20       `SPARC_CORE20.sparc0.lsu.dctldp
    `define ICTPATH20         `SPARC_CORE20.sparc0.ifu.ict
    `define DCACHE20          `SPARC_CORE20.sparc0.lsu.dcache
    `define INSTPATH20        `SPARC_CORE20.sparc0.ifu.fcl
    `define PCPATH20          `SPARC_CORE20.sparc0.ifu
    `define DVLD20            `SPARC_CORE20.sparc0.lsu.dva
    `define DTAG20            `SPARC_CORE20.sparc0.lsu.dtag
    `define SDTAG20           `SPARC_CORE20.sparc0.lsu.dtag
    `define SDVLD20           `SPARC_CORE20.sparc0.lsu.dva
    `define FFUPATH20         `SPARC_CORE20.sparc0.ffu
    `define TLU_HYPER20       `SPARC_CORE20.sparc0.tlu.tlu_hyperv
    `define IFQDP20           `SPARC_CORE20.sparc0.ifu.ifqdp
    `define ITLBPATH20        `SPARC_CORE20.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH20    `SPARC_CORE20.sparc0.cfg_asi

    `define PITON_CORE20_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc20_inst_done
`ifdef RTL_SPARC20
    `define PITON_CORE20_PC_W20     `PCPATH20.fdp.pc_w
`else
    `define PITON_CORE20_PC_W20     `TOP_MOD.monitor.pc_cmp.spc20_phy_pc_w
`endif

    

    `define TILE21            `CHIP.tile21
    `define ARIANE_CORE21     `TILE21.g_ariane_core.core.ariane
    `define SPARC_CORE21      `TILE21.g_sparc_core.core
    `define PICO_CORE21       `TILE21.g_picorv32_core.core
    `define CCX_TRANSDUCER21  `TILE21.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER21 `TILE21.g_picorv32_core.pico_l15_transducer
    `define L15_TOP21         `TILE21.l15.l15
    `define L15_PIPE21        `TILE21.l15.l15.pipeline
    `define DMBR21            `TILE21.dmbr_ins
    `define L2_TOP21          `TILE21.l2
    `define SPARC_REG21       `SPARC_CORE21.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH21       `SPARC_CORE21.sparc0.ffu.ffu
`else
    `define FLOATPATH21       `SPARC_CORE21.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH21         `SPARC_CORE21.sparc0.tlu.tlu
    `define DTLBPATH21        `SPARC_CORE21.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH21         `SPARC_CORE21.sparc0.tlu
    `define DTLBPATH21        `SPARC_CORE21.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH21         `SPARC_CORE21.sparc0
`ifndef RTL_SPU
    `define ICVPATH21         `SPARC_CORE21.sparc0.ifu.ifu.icv
    `define IFUPATH21         `SPARC_CORE21.sparc0.ifu.ifu
    `define TNUM21S           `SPARC_CORE21.sparc0.ifu.ifu.swl
    `define TPC21S            `SPARC_CORE21.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH21         `SPARC_CORE21.sparc0.ifu.icv
    `define IFUPATH21         `SPARC_CORE21.sparc0.ifu
    `define TNUM21S           `SPARC_CORE21.sparc0.ifu.swl
    `define TPC21S            `SPARC_CORE21.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH21         `SPARC_CORE21.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH21         `SPARC_CORE21.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH21         `SPARC_CORE21.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH21         `SPARC_CORE21.sparc0.ifu.fdp
`endif
    `define ALUPATH21         `SPARC_CORE21.sparc0.exu.exu.alu
    `define SPCPATH21         `SPARC_CORE21.sparc0
    `define REGPATH21         `SPARC_CORE21.sparc0.exu.exu.irf.irf
    `define CCRPATH21         `SPARC_CORE21.sparc0.exu.exu.ecl.ccr
    `define EXUPATH21         `SPARC_CORE21.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH21          `SPARC_CORE21.sparc0.tlu.tlu.tcl
    `define TS0PATH21         `SPARC_CORE21.sparc0.tlu.tlu.tsa0
    `define TS1PATH21         `SPARC_CORE21.sparc0.tlu.tlu.tsa1
    `define INTPATH21         `SPARC_CORE21.sparc0.tlu.tlu.intdp
    `define ASIPATH21         `SPARC_CORE21.sparc0.lsu.lsu.dctl
    `define ASIDPPATH21       `SPARC_CORE21.sparc0.lsu.lsu.dctldp
    `define ICTPATH21         `SPARC_CORE21.sparc0.ifu.ifu.ict
    `define DCACHE21          `SPARC_CORE21.sparc0.lsu.lsu.dcache
    `define INSTPATH21        `SPARC_CORE21.sparc0.ifu.ifu.fcl
    `define PCPATH21          `SPARC_CORE21.sparc0.ifu.ifu
    `define DVLD21            `SPARC_CORE21.sparc0.lsu.lsu.dva
    `define DTAG21            `SPARC_CORE21.sparc0.lsu.lsu.dtag
    `define SDTAG21           `SPARC_CORE21.sparc0.lsu.lsu.dtag
    `define SDVLD21           `SPARC_CORE21.sparc0.lsu.lsu.dva
    `define FFUPATH21         `SPARC_CORE21.sparc0.ffu.ffu
    `define TLU_HYPER21       `SPARC_CORE21.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP21           `SPARC_CORE21.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH21        `SPARC_CORE21.sparc0.ifu.ifu.itlb
`else
    `define TLPATH21          `SPARC_CORE21.sparc0.tlu.tcl
    `define TS0PATH21         `SPARC_CORE21.sparc0.tlu.tsa0
    `define TS1PATH21         `SPARC_CORE21.sparc0.tlu.tsa1
    `define INTPATH21         `SPARC_CORE21.sparc0.tlu.intdp
    `define ASIPATH21         `SPARC_CORE21.sparc0.lsu.dctl
    `define ASIDPPATH21       `SPARC_CORE21.sparc0.lsu.dctldp
    `define ICTPATH21         `SPARC_CORE21.sparc0.ifu.ict
    `define DCACHE21          `SPARC_CORE21.sparc0.lsu.dcache
    `define INSTPATH21        `SPARC_CORE21.sparc0.ifu.fcl
    `define PCPATH21          `SPARC_CORE21.sparc0.ifu
    `define DVLD21            `SPARC_CORE21.sparc0.lsu.dva
    `define DTAG21            `SPARC_CORE21.sparc0.lsu.dtag
    `define SDTAG21           `SPARC_CORE21.sparc0.lsu.dtag
    `define SDVLD21           `SPARC_CORE21.sparc0.lsu.dva
    `define FFUPATH21         `SPARC_CORE21.sparc0.ffu
    `define TLU_HYPER21       `SPARC_CORE21.sparc0.tlu.tlu_hyperv
    `define IFQDP21           `SPARC_CORE21.sparc0.ifu.ifqdp
    `define ITLBPATH21        `SPARC_CORE21.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH21    `SPARC_CORE21.sparc0.cfg_asi

    `define PITON_CORE21_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc21_inst_done
`ifdef RTL_SPARC21
    `define PITON_CORE21_PC_W21     `PCPATH21.fdp.pc_w
`else
    `define PITON_CORE21_PC_W21     `TOP_MOD.monitor.pc_cmp.spc21_phy_pc_w
`endif

    

    `define TILE22            `CHIP.tile22
    `define ARIANE_CORE22     `TILE22.g_ariane_core.core.ariane
    `define SPARC_CORE22      `TILE22.g_sparc_core.core
    `define PICO_CORE22       `TILE22.g_picorv32_core.core
    `define CCX_TRANSDUCER22  `TILE22.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER22 `TILE22.g_picorv32_core.pico_l15_transducer
    `define L15_TOP22         `TILE22.l15.l15
    `define L15_PIPE22        `TILE22.l15.l15.pipeline
    `define DMBR22            `TILE22.dmbr_ins
    `define L2_TOP22          `TILE22.l2
    `define SPARC_REG22       `SPARC_CORE22.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH22       `SPARC_CORE22.sparc0.ffu.ffu
`else
    `define FLOATPATH22       `SPARC_CORE22.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH22         `SPARC_CORE22.sparc0.tlu.tlu
    `define DTLBPATH22        `SPARC_CORE22.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH22         `SPARC_CORE22.sparc0.tlu
    `define DTLBPATH22        `SPARC_CORE22.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH22         `SPARC_CORE22.sparc0
`ifndef RTL_SPU
    `define ICVPATH22         `SPARC_CORE22.sparc0.ifu.ifu.icv
    `define IFUPATH22         `SPARC_CORE22.sparc0.ifu.ifu
    `define TNUM22S           `SPARC_CORE22.sparc0.ifu.ifu.swl
    `define TPC22S            `SPARC_CORE22.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH22         `SPARC_CORE22.sparc0.ifu.icv
    `define IFUPATH22         `SPARC_CORE22.sparc0.ifu
    `define TNUM22S           `SPARC_CORE22.sparc0.ifu.swl
    `define TPC22S            `SPARC_CORE22.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH22         `SPARC_CORE22.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH22         `SPARC_CORE22.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH22         `SPARC_CORE22.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH22         `SPARC_CORE22.sparc0.ifu.fdp
`endif
    `define ALUPATH22         `SPARC_CORE22.sparc0.exu.exu.alu
    `define SPCPATH22         `SPARC_CORE22.sparc0
    `define REGPATH22         `SPARC_CORE22.sparc0.exu.exu.irf.irf
    `define CCRPATH22         `SPARC_CORE22.sparc0.exu.exu.ecl.ccr
    `define EXUPATH22         `SPARC_CORE22.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH22          `SPARC_CORE22.sparc0.tlu.tlu.tcl
    `define TS0PATH22         `SPARC_CORE22.sparc0.tlu.tlu.tsa0
    `define TS1PATH22         `SPARC_CORE22.sparc0.tlu.tlu.tsa1
    `define INTPATH22         `SPARC_CORE22.sparc0.tlu.tlu.intdp
    `define ASIPATH22         `SPARC_CORE22.sparc0.lsu.lsu.dctl
    `define ASIDPPATH22       `SPARC_CORE22.sparc0.lsu.lsu.dctldp
    `define ICTPATH22         `SPARC_CORE22.sparc0.ifu.ifu.ict
    `define DCACHE22          `SPARC_CORE22.sparc0.lsu.lsu.dcache
    `define INSTPATH22        `SPARC_CORE22.sparc0.ifu.ifu.fcl
    `define PCPATH22          `SPARC_CORE22.sparc0.ifu.ifu
    `define DVLD22            `SPARC_CORE22.sparc0.lsu.lsu.dva
    `define DTAG22            `SPARC_CORE22.sparc0.lsu.lsu.dtag
    `define SDTAG22           `SPARC_CORE22.sparc0.lsu.lsu.dtag
    `define SDVLD22           `SPARC_CORE22.sparc0.lsu.lsu.dva
    `define FFUPATH22         `SPARC_CORE22.sparc0.ffu.ffu
    `define TLU_HYPER22       `SPARC_CORE22.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP22           `SPARC_CORE22.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH22        `SPARC_CORE22.sparc0.ifu.ifu.itlb
`else
    `define TLPATH22          `SPARC_CORE22.sparc0.tlu.tcl
    `define TS0PATH22         `SPARC_CORE22.sparc0.tlu.tsa0
    `define TS1PATH22         `SPARC_CORE22.sparc0.tlu.tsa1
    `define INTPATH22         `SPARC_CORE22.sparc0.tlu.intdp
    `define ASIPATH22         `SPARC_CORE22.sparc0.lsu.dctl
    `define ASIDPPATH22       `SPARC_CORE22.sparc0.lsu.dctldp
    `define ICTPATH22         `SPARC_CORE22.sparc0.ifu.ict
    `define DCACHE22          `SPARC_CORE22.sparc0.lsu.dcache
    `define INSTPATH22        `SPARC_CORE22.sparc0.ifu.fcl
    `define PCPATH22          `SPARC_CORE22.sparc0.ifu
    `define DVLD22            `SPARC_CORE22.sparc0.lsu.dva
    `define DTAG22            `SPARC_CORE22.sparc0.lsu.dtag
    `define SDTAG22           `SPARC_CORE22.sparc0.lsu.dtag
    `define SDVLD22           `SPARC_CORE22.sparc0.lsu.dva
    `define FFUPATH22         `SPARC_CORE22.sparc0.ffu
    `define TLU_HYPER22       `SPARC_CORE22.sparc0.tlu.tlu_hyperv
    `define IFQDP22           `SPARC_CORE22.sparc0.ifu.ifqdp
    `define ITLBPATH22        `SPARC_CORE22.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH22    `SPARC_CORE22.sparc0.cfg_asi

    `define PITON_CORE22_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc22_inst_done
`ifdef RTL_SPARC22
    `define PITON_CORE22_PC_W22     `PCPATH22.fdp.pc_w
`else
    `define PITON_CORE22_PC_W22     `TOP_MOD.monitor.pc_cmp.spc22_phy_pc_w
`endif

    

    `define TILE23            `CHIP.tile23
    `define ARIANE_CORE23     `TILE23.g_ariane_core.core.ariane
    `define SPARC_CORE23      `TILE23.g_sparc_core.core
    `define PICO_CORE23       `TILE23.g_picorv32_core.core
    `define CCX_TRANSDUCER23  `TILE23.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER23 `TILE23.g_picorv32_core.pico_l15_transducer
    `define L15_TOP23         `TILE23.l15.l15
    `define L15_PIPE23        `TILE23.l15.l15.pipeline
    `define DMBR23            `TILE23.dmbr_ins
    `define L2_TOP23          `TILE23.l2
    `define SPARC_REG23       `SPARC_CORE23.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH23       `SPARC_CORE23.sparc0.ffu.ffu
`else
    `define FLOATPATH23       `SPARC_CORE23.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH23         `SPARC_CORE23.sparc0.tlu.tlu
    `define DTLBPATH23        `SPARC_CORE23.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH23         `SPARC_CORE23.sparc0.tlu
    `define DTLBPATH23        `SPARC_CORE23.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH23         `SPARC_CORE23.sparc0
`ifndef RTL_SPU
    `define ICVPATH23         `SPARC_CORE23.sparc0.ifu.ifu.icv
    `define IFUPATH23         `SPARC_CORE23.sparc0.ifu.ifu
    `define TNUM23S           `SPARC_CORE23.sparc0.ifu.ifu.swl
    `define TPC23S            `SPARC_CORE23.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH23         `SPARC_CORE23.sparc0.ifu.icv
    `define IFUPATH23         `SPARC_CORE23.sparc0.ifu
    `define TNUM23S           `SPARC_CORE23.sparc0.ifu.swl
    `define TPC23S            `SPARC_CORE23.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH23         `SPARC_CORE23.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH23         `SPARC_CORE23.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH23         `SPARC_CORE23.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH23         `SPARC_CORE23.sparc0.ifu.fdp
`endif
    `define ALUPATH23         `SPARC_CORE23.sparc0.exu.exu.alu
    `define SPCPATH23         `SPARC_CORE23.sparc0
    `define REGPATH23         `SPARC_CORE23.sparc0.exu.exu.irf.irf
    `define CCRPATH23         `SPARC_CORE23.sparc0.exu.exu.ecl.ccr
    `define EXUPATH23         `SPARC_CORE23.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH23          `SPARC_CORE23.sparc0.tlu.tlu.tcl
    `define TS0PATH23         `SPARC_CORE23.sparc0.tlu.tlu.tsa0
    `define TS1PATH23         `SPARC_CORE23.sparc0.tlu.tlu.tsa1
    `define INTPATH23         `SPARC_CORE23.sparc0.tlu.tlu.intdp
    `define ASIPATH23         `SPARC_CORE23.sparc0.lsu.lsu.dctl
    `define ASIDPPATH23       `SPARC_CORE23.sparc0.lsu.lsu.dctldp
    `define ICTPATH23         `SPARC_CORE23.sparc0.ifu.ifu.ict
    `define DCACHE23          `SPARC_CORE23.sparc0.lsu.lsu.dcache
    `define INSTPATH23        `SPARC_CORE23.sparc0.ifu.ifu.fcl
    `define PCPATH23          `SPARC_CORE23.sparc0.ifu.ifu
    `define DVLD23            `SPARC_CORE23.sparc0.lsu.lsu.dva
    `define DTAG23            `SPARC_CORE23.sparc0.lsu.lsu.dtag
    `define SDTAG23           `SPARC_CORE23.sparc0.lsu.lsu.dtag
    `define SDVLD23           `SPARC_CORE23.sparc0.lsu.lsu.dva
    `define FFUPATH23         `SPARC_CORE23.sparc0.ffu.ffu
    `define TLU_HYPER23       `SPARC_CORE23.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP23           `SPARC_CORE23.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH23        `SPARC_CORE23.sparc0.ifu.ifu.itlb
`else
    `define TLPATH23          `SPARC_CORE23.sparc0.tlu.tcl
    `define TS0PATH23         `SPARC_CORE23.sparc0.tlu.tsa0
    `define TS1PATH23         `SPARC_CORE23.sparc0.tlu.tsa1
    `define INTPATH23         `SPARC_CORE23.sparc0.tlu.intdp
    `define ASIPATH23         `SPARC_CORE23.sparc0.lsu.dctl
    `define ASIDPPATH23       `SPARC_CORE23.sparc0.lsu.dctldp
    `define ICTPATH23         `SPARC_CORE23.sparc0.ifu.ict
    `define DCACHE23          `SPARC_CORE23.sparc0.lsu.dcache
    `define INSTPATH23        `SPARC_CORE23.sparc0.ifu.fcl
    `define PCPATH23          `SPARC_CORE23.sparc0.ifu
    `define DVLD23            `SPARC_CORE23.sparc0.lsu.dva
    `define DTAG23            `SPARC_CORE23.sparc0.lsu.dtag
    `define SDTAG23           `SPARC_CORE23.sparc0.lsu.dtag
    `define SDVLD23           `SPARC_CORE23.sparc0.lsu.dva
    `define FFUPATH23         `SPARC_CORE23.sparc0.ffu
    `define TLU_HYPER23       `SPARC_CORE23.sparc0.tlu.tlu_hyperv
    `define IFQDP23           `SPARC_CORE23.sparc0.ifu.ifqdp
    `define ITLBPATH23        `SPARC_CORE23.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH23    `SPARC_CORE23.sparc0.cfg_asi

    `define PITON_CORE23_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc23_inst_done
`ifdef RTL_SPARC23
    `define PITON_CORE23_PC_W23     `PCPATH23.fdp.pc_w
`else
    `define PITON_CORE23_PC_W23     `TOP_MOD.monitor.pc_cmp.spc23_phy_pc_w
`endif

    

    `define TILE24            `CHIP.tile24
    `define ARIANE_CORE24     `TILE24.g_ariane_core.core.ariane
    `define SPARC_CORE24      `TILE24.g_sparc_core.core
    `define PICO_CORE24       `TILE24.g_picorv32_core.core
    `define CCX_TRANSDUCER24  `TILE24.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER24 `TILE24.g_picorv32_core.pico_l15_transducer
    `define L15_TOP24         `TILE24.l15.l15
    `define L15_PIPE24        `TILE24.l15.l15.pipeline
    `define DMBR24            `TILE24.dmbr_ins
    `define L2_TOP24          `TILE24.l2
    `define SPARC_REG24       `SPARC_CORE24.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH24       `SPARC_CORE24.sparc0.ffu.ffu
`else
    `define FLOATPATH24       `SPARC_CORE24.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH24         `SPARC_CORE24.sparc0.tlu.tlu
    `define DTLBPATH24        `SPARC_CORE24.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH24         `SPARC_CORE24.sparc0.tlu
    `define DTLBPATH24        `SPARC_CORE24.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH24         `SPARC_CORE24.sparc0
`ifndef RTL_SPU
    `define ICVPATH24         `SPARC_CORE24.sparc0.ifu.ifu.icv
    `define IFUPATH24         `SPARC_CORE24.sparc0.ifu.ifu
    `define TNUM24S           `SPARC_CORE24.sparc0.ifu.ifu.swl
    `define TPC24S            `SPARC_CORE24.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH24         `SPARC_CORE24.sparc0.ifu.icv
    `define IFUPATH24         `SPARC_CORE24.sparc0.ifu
    `define TNUM24S           `SPARC_CORE24.sparc0.ifu.swl
    `define TPC24S            `SPARC_CORE24.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH24         `SPARC_CORE24.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH24         `SPARC_CORE24.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH24         `SPARC_CORE24.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH24         `SPARC_CORE24.sparc0.ifu.fdp
`endif
    `define ALUPATH24         `SPARC_CORE24.sparc0.exu.exu.alu
    `define SPCPATH24         `SPARC_CORE24.sparc0
    `define REGPATH24         `SPARC_CORE24.sparc0.exu.exu.irf.irf
    `define CCRPATH24         `SPARC_CORE24.sparc0.exu.exu.ecl.ccr
    `define EXUPATH24         `SPARC_CORE24.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH24          `SPARC_CORE24.sparc0.tlu.tlu.tcl
    `define TS0PATH24         `SPARC_CORE24.sparc0.tlu.tlu.tsa0
    `define TS1PATH24         `SPARC_CORE24.sparc0.tlu.tlu.tsa1
    `define INTPATH24         `SPARC_CORE24.sparc0.tlu.tlu.intdp
    `define ASIPATH24         `SPARC_CORE24.sparc0.lsu.lsu.dctl
    `define ASIDPPATH24       `SPARC_CORE24.sparc0.lsu.lsu.dctldp
    `define ICTPATH24         `SPARC_CORE24.sparc0.ifu.ifu.ict
    `define DCACHE24          `SPARC_CORE24.sparc0.lsu.lsu.dcache
    `define INSTPATH24        `SPARC_CORE24.sparc0.ifu.ifu.fcl
    `define PCPATH24          `SPARC_CORE24.sparc0.ifu.ifu
    `define DVLD24            `SPARC_CORE24.sparc0.lsu.lsu.dva
    `define DTAG24            `SPARC_CORE24.sparc0.lsu.lsu.dtag
    `define SDTAG24           `SPARC_CORE24.sparc0.lsu.lsu.dtag
    `define SDVLD24           `SPARC_CORE24.sparc0.lsu.lsu.dva
    `define FFUPATH24         `SPARC_CORE24.sparc0.ffu.ffu
    `define TLU_HYPER24       `SPARC_CORE24.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP24           `SPARC_CORE24.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH24        `SPARC_CORE24.sparc0.ifu.ifu.itlb
`else
    `define TLPATH24          `SPARC_CORE24.sparc0.tlu.tcl
    `define TS0PATH24         `SPARC_CORE24.sparc0.tlu.tsa0
    `define TS1PATH24         `SPARC_CORE24.sparc0.tlu.tsa1
    `define INTPATH24         `SPARC_CORE24.sparc0.tlu.intdp
    `define ASIPATH24         `SPARC_CORE24.sparc0.lsu.dctl
    `define ASIDPPATH24       `SPARC_CORE24.sparc0.lsu.dctldp
    `define ICTPATH24         `SPARC_CORE24.sparc0.ifu.ict
    `define DCACHE24          `SPARC_CORE24.sparc0.lsu.dcache
    `define INSTPATH24        `SPARC_CORE24.sparc0.ifu.fcl
    `define PCPATH24          `SPARC_CORE24.sparc0.ifu
    `define DVLD24            `SPARC_CORE24.sparc0.lsu.dva
    `define DTAG24            `SPARC_CORE24.sparc0.lsu.dtag
    `define SDTAG24           `SPARC_CORE24.sparc0.lsu.dtag
    `define SDVLD24           `SPARC_CORE24.sparc0.lsu.dva
    `define FFUPATH24         `SPARC_CORE24.sparc0.ffu
    `define TLU_HYPER24       `SPARC_CORE24.sparc0.tlu.tlu_hyperv
    `define IFQDP24           `SPARC_CORE24.sparc0.ifu.ifqdp
    `define ITLBPATH24        `SPARC_CORE24.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH24    `SPARC_CORE24.sparc0.cfg_asi

    `define PITON_CORE24_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc24_inst_done
`ifdef RTL_SPARC24
    `define PITON_CORE24_PC_W24     `PCPATH24.fdp.pc_w
`else
    `define PITON_CORE24_PC_W24     `TOP_MOD.monitor.pc_cmp.spc24_phy_pc_w
`endif

    

    `define TILE25            `CHIP.tile25
    `define ARIANE_CORE25     `TILE25.g_ariane_core.core.ariane
    `define SPARC_CORE25      `TILE25.g_sparc_core.core
    `define PICO_CORE25       `TILE25.g_picorv32_core.core
    `define CCX_TRANSDUCER25  `TILE25.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER25 `TILE25.g_picorv32_core.pico_l15_transducer
    `define L15_TOP25         `TILE25.l15.l15
    `define L15_PIPE25        `TILE25.l15.l15.pipeline
    `define DMBR25            `TILE25.dmbr_ins
    `define L2_TOP25          `TILE25.l2
    `define SPARC_REG25       `SPARC_CORE25.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH25       `SPARC_CORE25.sparc0.ffu.ffu
`else
    `define FLOATPATH25       `SPARC_CORE25.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH25         `SPARC_CORE25.sparc0.tlu.tlu
    `define DTLBPATH25        `SPARC_CORE25.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH25         `SPARC_CORE25.sparc0.tlu
    `define DTLBPATH25        `SPARC_CORE25.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH25         `SPARC_CORE25.sparc0
`ifndef RTL_SPU
    `define ICVPATH25         `SPARC_CORE25.sparc0.ifu.ifu.icv
    `define IFUPATH25         `SPARC_CORE25.sparc0.ifu.ifu
    `define TNUM25S           `SPARC_CORE25.sparc0.ifu.ifu.swl
    `define TPC25S            `SPARC_CORE25.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH25         `SPARC_CORE25.sparc0.ifu.icv
    `define IFUPATH25         `SPARC_CORE25.sparc0.ifu
    `define TNUM25S           `SPARC_CORE25.sparc0.ifu.swl
    `define TPC25S            `SPARC_CORE25.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH25         `SPARC_CORE25.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH25         `SPARC_CORE25.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH25         `SPARC_CORE25.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH25         `SPARC_CORE25.sparc0.ifu.fdp
`endif
    `define ALUPATH25         `SPARC_CORE25.sparc0.exu.exu.alu
    `define SPCPATH25         `SPARC_CORE25.sparc0
    `define REGPATH25         `SPARC_CORE25.sparc0.exu.exu.irf.irf
    `define CCRPATH25         `SPARC_CORE25.sparc0.exu.exu.ecl.ccr
    `define EXUPATH25         `SPARC_CORE25.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH25          `SPARC_CORE25.sparc0.tlu.tlu.tcl
    `define TS0PATH25         `SPARC_CORE25.sparc0.tlu.tlu.tsa0
    `define TS1PATH25         `SPARC_CORE25.sparc0.tlu.tlu.tsa1
    `define INTPATH25         `SPARC_CORE25.sparc0.tlu.tlu.intdp
    `define ASIPATH25         `SPARC_CORE25.sparc0.lsu.lsu.dctl
    `define ASIDPPATH25       `SPARC_CORE25.sparc0.lsu.lsu.dctldp
    `define ICTPATH25         `SPARC_CORE25.sparc0.ifu.ifu.ict
    `define DCACHE25          `SPARC_CORE25.sparc0.lsu.lsu.dcache
    `define INSTPATH25        `SPARC_CORE25.sparc0.ifu.ifu.fcl
    `define PCPATH25          `SPARC_CORE25.sparc0.ifu.ifu
    `define DVLD25            `SPARC_CORE25.sparc0.lsu.lsu.dva
    `define DTAG25            `SPARC_CORE25.sparc0.lsu.lsu.dtag
    `define SDTAG25           `SPARC_CORE25.sparc0.lsu.lsu.dtag
    `define SDVLD25           `SPARC_CORE25.sparc0.lsu.lsu.dva
    `define FFUPATH25         `SPARC_CORE25.sparc0.ffu.ffu
    `define TLU_HYPER25       `SPARC_CORE25.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP25           `SPARC_CORE25.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH25        `SPARC_CORE25.sparc0.ifu.ifu.itlb
`else
    `define TLPATH25          `SPARC_CORE25.sparc0.tlu.tcl
    `define TS0PATH25         `SPARC_CORE25.sparc0.tlu.tsa0
    `define TS1PATH25         `SPARC_CORE25.sparc0.tlu.tsa1
    `define INTPATH25         `SPARC_CORE25.sparc0.tlu.intdp
    `define ASIPATH25         `SPARC_CORE25.sparc0.lsu.dctl
    `define ASIDPPATH25       `SPARC_CORE25.sparc0.lsu.dctldp
    `define ICTPATH25         `SPARC_CORE25.sparc0.ifu.ict
    `define DCACHE25          `SPARC_CORE25.sparc0.lsu.dcache
    `define INSTPATH25        `SPARC_CORE25.sparc0.ifu.fcl
    `define PCPATH25          `SPARC_CORE25.sparc0.ifu
    `define DVLD25            `SPARC_CORE25.sparc0.lsu.dva
    `define DTAG25            `SPARC_CORE25.sparc0.lsu.dtag
    `define SDTAG25           `SPARC_CORE25.sparc0.lsu.dtag
    `define SDVLD25           `SPARC_CORE25.sparc0.lsu.dva
    `define FFUPATH25         `SPARC_CORE25.sparc0.ffu
    `define TLU_HYPER25       `SPARC_CORE25.sparc0.tlu.tlu_hyperv
    `define IFQDP25           `SPARC_CORE25.sparc0.ifu.ifqdp
    `define ITLBPATH25        `SPARC_CORE25.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH25    `SPARC_CORE25.sparc0.cfg_asi

    `define PITON_CORE25_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc25_inst_done
`ifdef RTL_SPARC25
    `define PITON_CORE25_PC_W25     `PCPATH25.fdp.pc_w
`else
    `define PITON_CORE25_PC_W25     `TOP_MOD.monitor.pc_cmp.spc25_phy_pc_w
`endif

    

    `define TILE26            `CHIP.tile26
    `define ARIANE_CORE26     `TILE26.g_ariane_core.core.ariane
    `define SPARC_CORE26      `TILE26.g_sparc_core.core
    `define PICO_CORE26       `TILE26.g_picorv32_core.core
    `define CCX_TRANSDUCER26  `TILE26.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER26 `TILE26.g_picorv32_core.pico_l15_transducer
    `define L15_TOP26         `TILE26.l15.l15
    `define L15_PIPE26        `TILE26.l15.l15.pipeline
    `define DMBR26            `TILE26.dmbr_ins
    `define L2_TOP26          `TILE26.l2
    `define SPARC_REG26       `SPARC_CORE26.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH26       `SPARC_CORE26.sparc0.ffu.ffu
`else
    `define FLOATPATH26       `SPARC_CORE26.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH26         `SPARC_CORE26.sparc0.tlu.tlu
    `define DTLBPATH26        `SPARC_CORE26.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH26         `SPARC_CORE26.sparc0.tlu
    `define DTLBPATH26        `SPARC_CORE26.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH26         `SPARC_CORE26.sparc0
`ifndef RTL_SPU
    `define ICVPATH26         `SPARC_CORE26.sparc0.ifu.ifu.icv
    `define IFUPATH26         `SPARC_CORE26.sparc0.ifu.ifu
    `define TNUM26S           `SPARC_CORE26.sparc0.ifu.ifu.swl
    `define TPC26S            `SPARC_CORE26.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH26         `SPARC_CORE26.sparc0.ifu.icv
    `define IFUPATH26         `SPARC_CORE26.sparc0.ifu
    `define TNUM26S           `SPARC_CORE26.sparc0.ifu.swl
    `define TPC26S            `SPARC_CORE26.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH26         `SPARC_CORE26.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH26         `SPARC_CORE26.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH26         `SPARC_CORE26.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH26         `SPARC_CORE26.sparc0.ifu.fdp
`endif
    `define ALUPATH26         `SPARC_CORE26.sparc0.exu.exu.alu
    `define SPCPATH26         `SPARC_CORE26.sparc0
    `define REGPATH26         `SPARC_CORE26.sparc0.exu.exu.irf.irf
    `define CCRPATH26         `SPARC_CORE26.sparc0.exu.exu.ecl.ccr
    `define EXUPATH26         `SPARC_CORE26.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH26          `SPARC_CORE26.sparc0.tlu.tlu.tcl
    `define TS0PATH26         `SPARC_CORE26.sparc0.tlu.tlu.tsa0
    `define TS1PATH26         `SPARC_CORE26.sparc0.tlu.tlu.tsa1
    `define INTPATH26         `SPARC_CORE26.sparc0.tlu.tlu.intdp
    `define ASIPATH26         `SPARC_CORE26.sparc0.lsu.lsu.dctl
    `define ASIDPPATH26       `SPARC_CORE26.sparc0.lsu.lsu.dctldp
    `define ICTPATH26         `SPARC_CORE26.sparc0.ifu.ifu.ict
    `define DCACHE26          `SPARC_CORE26.sparc0.lsu.lsu.dcache
    `define INSTPATH26        `SPARC_CORE26.sparc0.ifu.ifu.fcl
    `define PCPATH26          `SPARC_CORE26.sparc0.ifu.ifu
    `define DVLD26            `SPARC_CORE26.sparc0.lsu.lsu.dva
    `define DTAG26            `SPARC_CORE26.sparc0.lsu.lsu.dtag
    `define SDTAG26           `SPARC_CORE26.sparc0.lsu.lsu.dtag
    `define SDVLD26           `SPARC_CORE26.sparc0.lsu.lsu.dva
    `define FFUPATH26         `SPARC_CORE26.sparc0.ffu.ffu
    `define TLU_HYPER26       `SPARC_CORE26.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP26           `SPARC_CORE26.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH26        `SPARC_CORE26.sparc0.ifu.ifu.itlb
`else
    `define TLPATH26          `SPARC_CORE26.sparc0.tlu.tcl
    `define TS0PATH26         `SPARC_CORE26.sparc0.tlu.tsa0
    `define TS1PATH26         `SPARC_CORE26.sparc0.tlu.tsa1
    `define INTPATH26         `SPARC_CORE26.sparc0.tlu.intdp
    `define ASIPATH26         `SPARC_CORE26.sparc0.lsu.dctl
    `define ASIDPPATH26       `SPARC_CORE26.sparc0.lsu.dctldp
    `define ICTPATH26         `SPARC_CORE26.sparc0.ifu.ict
    `define DCACHE26          `SPARC_CORE26.sparc0.lsu.dcache
    `define INSTPATH26        `SPARC_CORE26.sparc0.ifu.fcl
    `define PCPATH26          `SPARC_CORE26.sparc0.ifu
    `define DVLD26            `SPARC_CORE26.sparc0.lsu.dva
    `define DTAG26            `SPARC_CORE26.sparc0.lsu.dtag
    `define SDTAG26           `SPARC_CORE26.sparc0.lsu.dtag
    `define SDVLD26           `SPARC_CORE26.sparc0.lsu.dva
    `define FFUPATH26         `SPARC_CORE26.sparc0.ffu
    `define TLU_HYPER26       `SPARC_CORE26.sparc0.tlu.tlu_hyperv
    `define IFQDP26           `SPARC_CORE26.sparc0.ifu.ifqdp
    `define ITLBPATH26        `SPARC_CORE26.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH26    `SPARC_CORE26.sparc0.cfg_asi

    `define PITON_CORE26_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc26_inst_done
`ifdef RTL_SPARC26
    `define PITON_CORE26_PC_W26     `PCPATH26.fdp.pc_w
`else
    `define PITON_CORE26_PC_W26     `TOP_MOD.monitor.pc_cmp.spc26_phy_pc_w
`endif

    

    `define TILE27            `CHIP.tile27
    `define ARIANE_CORE27     `TILE27.g_ariane_core.core.ariane
    `define SPARC_CORE27      `TILE27.g_sparc_core.core
    `define PICO_CORE27       `TILE27.g_picorv32_core.core
    `define CCX_TRANSDUCER27  `TILE27.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER27 `TILE27.g_picorv32_core.pico_l15_transducer
    `define L15_TOP27         `TILE27.l15.l15
    `define L15_PIPE27        `TILE27.l15.l15.pipeline
    `define DMBR27            `TILE27.dmbr_ins
    `define L2_TOP27          `TILE27.l2
    `define SPARC_REG27       `SPARC_CORE27.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH27       `SPARC_CORE27.sparc0.ffu.ffu
`else
    `define FLOATPATH27       `SPARC_CORE27.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH27         `SPARC_CORE27.sparc0.tlu.tlu
    `define DTLBPATH27        `SPARC_CORE27.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH27         `SPARC_CORE27.sparc0.tlu
    `define DTLBPATH27        `SPARC_CORE27.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH27         `SPARC_CORE27.sparc0
`ifndef RTL_SPU
    `define ICVPATH27         `SPARC_CORE27.sparc0.ifu.ifu.icv
    `define IFUPATH27         `SPARC_CORE27.sparc0.ifu.ifu
    `define TNUM27S           `SPARC_CORE27.sparc0.ifu.ifu.swl
    `define TPC27S            `SPARC_CORE27.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH27         `SPARC_CORE27.sparc0.ifu.icv
    `define IFUPATH27         `SPARC_CORE27.sparc0.ifu
    `define TNUM27S           `SPARC_CORE27.sparc0.ifu.swl
    `define TPC27S            `SPARC_CORE27.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH27         `SPARC_CORE27.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH27         `SPARC_CORE27.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH27         `SPARC_CORE27.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH27         `SPARC_CORE27.sparc0.ifu.fdp
`endif
    `define ALUPATH27         `SPARC_CORE27.sparc0.exu.exu.alu
    `define SPCPATH27         `SPARC_CORE27.sparc0
    `define REGPATH27         `SPARC_CORE27.sparc0.exu.exu.irf.irf
    `define CCRPATH27         `SPARC_CORE27.sparc0.exu.exu.ecl.ccr
    `define EXUPATH27         `SPARC_CORE27.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH27          `SPARC_CORE27.sparc0.tlu.tlu.tcl
    `define TS0PATH27         `SPARC_CORE27.sparc0.tlu.tlu.tsa0
    `define TS1PATH27         `SPARC_CORE27.sparc0.tlu.tlu.tsa1
    `define INTPATH27         `SPARC_CORE27.sparc0.tlu.tlu.intdp
    `define ASIPATH27         `SPARC_CORE27.sparc0.lsu.lsu.dctl
    `define ASIDPPATH27       `SPARC_CORE27.sparc0.lsu.lsu.dctldp
    `define ICTPATH27         `SPARC_CORE27.sparc0.ifu.ifu.ict
    `define DCACHE27          `SPARC_CORE27.sparc0.lsu.lsu.dcache
    `define INSTPATH27        `SPARC_CORE27.sparc0.ifu.ifu.fcl
    `define PCPATH27          `SPARC_CORE27.sparc0.ifu.ifu
    `define DVLD27            `SPARC_CORE27.sparc0.lsu.lsu.dva
    `define DTAG27            `SPARC_CORE27.sparc0.lsu.lsu.dtag
    `define SDTAG27           `SPARC_CORE27.sparc0.lsu.lsu.dtag
    `define SDVLD27           `SPARC_CORE27.sparc0.lsu.lsu.dva
    `define FFUPATH27         `SPARC_CORE27.sparc0.ffu.ffu
    `define TLU_HYPER27       `SPARC_CORE27.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP27           `SPARC_CORE27.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH27        `SPARC_CORE27.sparc0.ifu.ifu.itlb
`else
    `define TLPATH27          `SPARC_CORE27.sparc0.tlu.tcl
    `define TS0PATH27         `SPARC_CORE27.sparc0.tlu.tsa0
    `define TS1PATH27         `SPARC_CORE27.sparc0.tlu.tsa1
    `define INTPATH27         `SPARC_CORE27.sparc0.tlu.intdp
    `define ASIPATH27         `SPARC_CORE27.sparc0.lsu.dctl
    `define ASIDPPATH27       `SPARC_CORE27.sparc0.lsu.dctldp
    `define ICTPATH27         `SPARC_CORE27.sparc0.ifu.ict
    `define DCACHE27          `SPARC_CORE27.sparc0.lsu.dcache
    `define INSTPATH27        `SPARC_CORE27.sparc0.ifu.fcl
    `define PCPATH27          `SPARC_CORE27.sparc0.ifu
    `define DVLD27            `SPARC_CORE27.sparc0.lsu.dva
    `define DTAG27            `SPARC_CORE27.sparc0.lsu.dtag
    `define SDTAG27           `SPARC_CORE27.sparc0.lsu.dtag
    `define SDVLD27           `SPARC_CORE27.sparc0.lsu.dva
    `define FFUPATH27         `SPARC_CORE27.sparc0.ffu
    `define TLU_HYPER27       `SPARC_CORE27.sparc0.tlu.tlu_hyperv
    `define IFQDP27           `SPARC_CORE27.sparc0.ifu.ifqdp
    `define ITLBPATH27        `SPARC_CORE27.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH27    `SPARC_CORE27.sparc0.cfg_asi

    `define PITON_CORE27_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc27_inst_done
`ifdef RTL_SPARC27
    `define PITON_CORE27_PC_W27     `PCPATH27.fdp.pc_w
`else
    `define PITON_CORE27_PC_W27     `TOP_MOD.monitor.pc_cmp.spc27_phy_pc_w
`endif

    

    `define TILE28            `CHIP.tile28
    `define ARIANE_CORE28     `TILE28.g_ariane_core.core.ariane
    `define SPARC_CORE28      `TILE28.g_sparc_core.core
    `define PICO_CORE28       `TILE28.g_picorv32_core.core
    `define CCX_TRANSDUCER28  `TILE28.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER28 `TILE28.g_picorv32_core.pico_l15_transducer
    `define L15_TOP28         `TILE28.l15.l15
    `define L15_PIPE28        `TILE28.l15.l15.pipeline
    `define DMBR28            `TILE28.dmbr_ins
    `define L2_TOP28          `TILE28.l2
    `define SPARC_REG28       `SPARC_CORE28.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH28       `SPARC_CORE28.sparc0.ffu.ffu
`else
    `define FLOATPATH28       `SPARC_CORE28.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH28         `SPARC_CORE28.sparc0.tlu.tlu
    `define DTLBPATH28        `SPARC_CORE28.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH28         `SPARC_CORE28.sparc0.tlu
    `define DTLBPATH28        `SPARC_CORE28.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH28         `SPARC_CORE28.sparc0
`ifndef RTL_SPU
    `define ICVPATH28         `SPARC_CORE28.sparc0.ifu.ifu.icv
    `define IFUPATH28         `SPARC_CORE28.sparc0.ifu.ifu
    `define TNUM28S           `SPARC_CORE28.sparc0.ifu.ifu.swl
    `define TPC28S            `SPARC_CORE28.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH28         `SPARC_CORE28.sparc0.ifu.icv
    `define IFUPATH28         `SPARC_CORE28.sparc0.ifu
    `define TNUM28S           `SPARC_CORE28.sparc0.ifu.swl
    `define TPC28S            `SPARC_CORE28.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH28         `SPARC_CORE28.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH28         `SPARC_CORE28.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH28         `SPARC_CORE28.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH28         `SPARC_CORE28.sparc0.ifu.fdp
`endif
    `define ALUPATH28         `SPARC_CORE28.sparc0.exu.exu.alu
    `define SPCPATH28         `SPARC_CORE28.sparc0
    `define REGPATH28         `SPARC_CORE28.sparc0.exu.exu.irf.irf
    `define CCRPATH28         `SPARC_CORE28.sparc0.exu.exu.ecl.ccr
    `define EXUPATH28         `SPARC_CORE28.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH28          `SPARC_CORE28.sparc0.tlu.tlu.tcl
    `define TS0PATH28         `SPARC_CORE28.sparc0.tlu.tlu.tsa0
    `define TS1PATH28         `SPARC_CORE28.sparc0.tlu.tlu.tsa1
    `define INTPATH28         `SPARC_CORE28.sparc0.tlu.tlu.intdp
    `define ASIPATH28         `SPARC_CORE28.sparc0.lsu.lsu.dctl
    `define ASIDPPATH28       `SPARC_CORE28.sparc0.lsu.lsu.dctldp
    `define ICTPATH28         `SPARC_CORE28.sparc0.ifu.ifu.ict
    `define DCACHE28          `SPARC_CORE28.sparc0.lsu.lsu.dcache
    `define INSTPATH28        `SPARC_CORE28.sparc0.ifu.ifu.fcl
    `define PCPATH28          `SPARC_CORE28.sparc0.ifu.ifu
    `define DVLD28            `SPARC_CORE28.sparc0.lsu.lsu.dva
    `define DTAG28            `SPARC_CORE28.sparc0.lsu.lsu.dtag
    `define SDTAG28           `SPARC_CORE28.sparc0.lsu.lsu.dtag
    `define SDVLD28           `SPARC_CORE28.sparc0.lsu.lsu.dva
    `define FFUPATH28         `SPARC_CORE28.sparc0.ffu.ffu
    `define TLU_HYPER28       `SPARC_CORE28.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP28           `SPARC_CORE28.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH28        `SPARC_CORE28.sparc0.ifu.ifu.itlb
`else
    `define TLPATH28          `SPARC_CORE28.sparc0.tlu.tcl
    `define TS0PATH28         `SPARC_CORE28.sparc0.tlu.tsa0
    `define TS1PATH28         `SPARC_CORE28.sparc0.tlu.tsa1
    `define INTPATH28         `SPARC_CORE28.sparc0.tlu.intdp
    `define ASIPATH28         `SPARC_CORE28.sparc0.lsu.dctl
    `define ASIDPPATH28       `SPARC_CORE28.sparc0.lsu.dctldp
    `define ICTPATH28         `SPARC_CORE28.sparc0.ifu.ict
    `define DCACHE28          `SPARC_CORE28.sparc0.lsu.dcache
    `define INSTPATH28        `SPARC_CORE28.sparc0.ifu.fcl
    `define PCPATH28          `SPARC_CORE28.sparc0.ifu
    `define DVLD28            `SPARC_CORE28.sparc0.lsu.dva
    `define DTAG28            `SPARC_CORE28.sparc0.lsu.dtag
    `define SDTAG28           `SPARC_CORE28.sparc0.lsu.dtag
    `define SDVLD28           `SPARC_CORE28.sparc0.lsu.dva
    `define FFUPATH28         `SPARC_CORE28.sparc0.ffu
    `define TLU_HYPER28       `SPARC_CORE28.sparc0.tlu.tlu_hyperv
    `define IFQDP28           `SPARC_CORE28.sparc0.ifu.ifqdp
    `define ITLBPATH28        `SPARC_CORE28.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH28    `SPARC_CORE28.sparc0.cfg_asi

    `define PITON_CORE28_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc28_inst_done
`ifdef RTL_SPARC28
    `define PITON_CORE28_PC_W28     `PCPATH28.fdp.pc_w
`else
    `define PITON_CORE28_PC_W28     `TOP_MOD.monitor.pc_cmp.spc28_phy_pc_w
`endif

    

    `define TILE29            `CHIP.tile29
    `define ARIANE_CORE29     `TILE29.g_ariane_core.core.ariane
    `define SPARC_CORE29      `TILE29.g_sparc_core.core
    `define PICO_CORE29       `TILE29.g_picorv32_core.core
    `define CCX_TRANSDUCER29  `TILE29.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER29 `TILE29.g_picorv32_core.pico_l15_transducer
    `define L15_TOP29         `TILE29.l15.l15
    `define L15_PIPE29        `TILE29.l15.l15.pipeline
    `define DMBR29            `TILE29.dmbr_ins
    `define L2_TOP29          `TILE29.l2
    `define SPARC_REG29       `SPARC_CORE29.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH29       `SPARC_CORE29.sparc0.ffu.ffu
`else
    `define FLOATPATH29       `SPARC_CORE29.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH29         `SPARC_CORE29.sparc0.tlu.tlu
    `define DTLBPATH29        `SPARC_CORE29.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH29         `SPARC_CORE29.sparc0.tlu
    `define DTLBPATH29        `SPARC_CORE29.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH29         `SPARC_CORE29.sparc0
`ifndef RTL_SPU
    `define ICVPATH29         `SPARC_CORE29.sparc0.ifu.ifu.icv
    `define IFUPATH29         `SPARC_CORE29.sparc0.ifu.ifu
    `define TNUM29S           `SPARC_CORE29.sparc0.ifu.ifu.swl
    `define TPC29S            `SPARC_CORE29.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH29         `SPARC_CORE29.sparc0.ifu.icv
    `define IFUPATH29         `SPARC_CORE29.sparc0.ifu
    `define TNUM29S           `SPARC_CORE29.sparc0.ifu.swl
    `define TPC29S            `SPARC_CORE29.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH29         `SPARC_CORE29.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH29         `SPARC_CORE29.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH29         `SPARC_CORE29.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH29         `SPARC_CORE29.sparc0.ifu.fdp
`endif
    `define ALUPATH29         `SPARC_CORE29.sparc0.exu.exu.alu
    `define SPCPATH29         `SPARC_CORE29.sparc0
    `define REGPATH29         `SPARC_CORE29.sparc0.exu.exu.irf.irf
    `define CCRPATH29         `SPARC_CORE29.sparc0.exu.exu.ecl.ccr
    `define EXUPATH29         `SPARC_CORE29.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH29          `SPARC_CORE29.sparc0.tlu.tlu.tcl
    `define TS0PATH29         `SPARC_CORE29.sparc0.tlu.tlu.tsa0
    `define TS1PATH29         `SPARC_CORE29.sparc0.tlu.tlu.tsa1
    `define INTPATH29         `SPARC_CORE29.sparc0.tlu.tlu.intdp
    `define ASIPATH29         `SPARC_CORE29.sparc0.lsu.lsu.dctl
    `define ASIDPPATH29       `SPARC_CORE29.sparc0.lsu.lsu.dctldp
    `define ICTPATH29         `SPARC_CORE29.sparc0.ifu.ifu.ict
    `define DCACHE29          `SPARC_CORE29.sparc0.lsu.lsu.dcache
    `define INSTPATH29        `SPARC_CORE29.sparc0.ifu.ifu.fcl
    `define PCPATH29          `SPARC_CORE29.sparc0.ifu.ifu
    `define DVLD29            `SPARC_CORE29.sparc0.lsu.lsu.dva
    `define DTAG29            `SPARC_CORE29.sparc0.lsu.lsu.dtag
    `define SDTAG29           `SPARC_CORE29.sparc0.lsu.lsu.dtag
    `define SDVLD29           `SPARC_CORE29.sparc0.lsu.lsu.dva
    `define FFUPATH29         `SPARC_CORE29.sparc0.ffu.ffu
    `define TLU_HYPER29       `SPARC_CORE29.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP29           `SPARC_CORE29.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH29        `SPARC_CORE29.sparc0.ifu.ifu.itlb
`else
    `define TLPATH29          `SPARC_CORE29.sparc0.tlu.tcl
    `define TS0PATH29         `SPARC_CORE29.sparc0.tlu.tsa0
    `define TS1PATH29         `SPARC_CORE29.sparc0.tlu.tsa1
    `define INTPATH29         `SPARC_CORE29.sparc0.tlu.intdp
    `define ASIPATH29         `SPARC_CORE29.sparc0.lsu.dctl
    `define ASIDPPATH29       `SPARC_CORE29.sparc0.lsu.dctldp
    `define ICTPATH29         `SPARC_CORE29.sparc0.ifu.ict
    `define DCACHE29          `SPARC_CORE29.sparc0.lsu.dcache
    `define INSTPATH29        `SPARC_CORE29.sparc0.ifu.fcl
    `define PCPATH29          `SPARC_CORE29.sparc0.ifu
    `define DVLD29            `SPARC_CORE29.sparc0.lsu.dva
    `define DTAG29            `SPARC_CORE29.sparc0.lsu.dtag
    `define SDTAG29           `SPARC_CORE29.sparc0.lsu.dtag
    `define SDVLD29           `SPARC_CORE29.sparc0.lsu.dva
    `define FFUPATH29         `SPARC_CORE29.sparc0.ffu
    `define TLU_HYPER29       `SPARC_CORE29.sparc0.tlu.tlu_hyperv
    `define IFQDP29           `SPARC_CORE29.sparc0.ifu.ifqdp
    `define ITLBPATH29        `SPARC_CORE29.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH29    `SPARC_CORE29.sparc0.cfg_asi

    `define PITON_CORE29_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc29_inst_done
`ifdef RTL_SPARC29
    `define PITON_CORE29_PC_W29     `PCPATH29.fdp.pc_w
`else
    `define PITON_CORE29_PC_W29     `TOP_MOD.monitor.pc_cmp.spc29_phy_pc_w
`endif

    

    `define TILE30            `CHIP.tile30
    `define ARIANE_CORE30     `TILE30.g_ariane_core.core.ariane
    `define SPARC_CORE30      `TILE30.g_sparc_core.core
    `define PICO_CORE30       `TILE30.g_picorv32_core.core
    `define CCX_TRANSDUCER30  `TILE30.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER30 `TILE30.g_picorv32_core.pico_l15_transducer
    `define L15_TOP30         `TILE30.l15.l15
    `define L15_PIPE30        `TILE30.l15.l15.pipeline
    `define DMBR30            `TILE30.dmbr_ins
    `define L2_TOP30          `TILE30.l2
    `define SPARC_REG30       `SPARC_CORE30.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH30       `SPARC_CORE30.sparc0.ffu.ffu
`else
    `define FLOATPATH30       `SPARC_CORE30.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH30         `SPARC_CORE30.sparc0.tlu.tlu
    `define DTLBPATH30        `SPARC_CORE30.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH30         `SPARC_CORE30.sparc0.tlu
    `define DTLBPATH30        `SPARC_CORE30.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH30         `SPARC_CORE30.sparc0
`ifndef RTL_SPU
    `define ICVPATH30         `SPARC_CORE30.sparc0.ifu.ifu.icv
    `define IFUPATH30         `SPARC_CORE30.sparc0.ifu.ifu
    `define TNUM30S           `SPARC_CORE30.sparc0.ifu.ifu.swl
    `define TPC30S            `SPARC_CORE30.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH30         `SPARC_CORE30.sparc0.ifu.icv
    `define IFUPATH30         `SPARC_CORE30.sparc0.ifu
    `define TNUM30S           `SPARC_CORE30.sparc0.ifu.swl
    `define TPC30S            `SPARC_CORE30.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH30         `SPARC_CORE30.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH30         `SPARC_CORE30.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH30         `SPARC_CORE30.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH30         `SPARC_CORE30.sparc0.ifu.fdp
`endif
    `define ALUPATH30         `SPARC_CORE30.sparc0.exu.exu.alu
    `define SPCPATH30         `SPARC_CORE30.sparc0
    `define REGPATH30         `SPARC_CORE30.sparc0.exu.exu.irf.irf
    `define CCRPATH30         `SPARC_CORE30.sparc0.exu.exu.ecl.ccr
    `define EXUPATH30         `SPARC_CORE30.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH30          `SPARC_CORE30.sparc0.tlu.tlu.tcl
    `define TS0PATH30         `SPARC_CORE30.sparc0.tlu.tlu.tsa0
    `define TS1PATH30         `SPARC_CORE30.sparc0.tlu.tlu.tsa1
    `define INTPATH30         `SPARC_CORE30.sparc0.tlu.tlu.intdp
    `define ASIPATH30         `SPARC_CORE30.sparc0.lsu.lsu.dctl
    `define ASIDPPATH30       `SPARC_CORE30.sparc0.lsu.lsu.dctldp
    `define ICTPATH30         `SPARC_CORE30.sparc0.ifu.ifu.ict
    `define DCACHE30          `SPARC_CORE30.sparc0.lsu.lsu.dcache
    `define INSTPATH30        `SPARC_CORE30.sparc0.ifu.ifu.fcl
    `define PCPATH30          `SPARC_CORE30.sparc0.ifu.ifu
    `define DVLD30            `SPARC_CORE30.sparc0.lsu.lsu.dva
    `define DTAG30            `SPARC_CORE30.sparc0.lsu.lsu.dtag
    `define SDTAG30           `SPARC_CORE30.sparc0.lsu.lsu.dtag
    `define SDVLD30           `SPARC_CORE30.sparc0.lsu.lsu.dva
    `define FFUPATH30         `SPARC_CORE30.sparc0.ffu.ffu
    `define TLU_HYPER30       `SPARC_CORE30.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP30           `SPARC_CORE30.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH30        `SPARC_CORE30.sparc0.ifu.ifu.itlb
`else
    `define TLPATH30          `SPARC_CORE30.sparc0.tlu.tcl
    `define TS0PATH30         `SPARC_CORE30.sparc0.tlu.tsa0
    `define TS1PATH30         `SPARC_CORE30.sparc0.tlu.tsa1
    `define INTPATH30         `SPARC_CORE30.sparc0.tlu.intdp
    `define ASIPATH30         `SPARC_CORE30.sparc0.lsu.dctl
    `define ASIDPPATH30       `SPARC_CORE30.sparc0.lsu.dctldp
    `define ICTPATH30         `SPARC_CORE30.sparc0.ifu.ict
    `define DCACHE30          `SPARC_CORE30.sparc0.lsu.dcache
    `define INSTPATH30        `SPARC_CORE30.sparc0.ifu.fcl
    `define PCPATH30          `SPARC_CORE30.sparc0.ifu
    `define DVLD30            `SPARC_CORE30.sparc0.lsu.dva
    `define DTAG30            `SPARC_CORE30.sparc0.lsu.dtag
    `define SDTAG30           `SPARC_CORE30.sparc0.lsu.dtag
    `define SDVLD30           `SPARC_CORE30.sparc0.lsu.dva
    `define FFUPATH30         `SPARC_CORE30.sparc0.ffu
    `define TLU_HYPER30       `SPARC_CORE30.sparc0.tlu.tlu_hyperv
    `define IFQDP30           `SPARC_CORE30.sparc0.ifu.ifqdp
    `define ITLBPATH30        `SPARC_CORE30.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH30    `SPARC_CORE30.sparc0.cfg_asi

    `define PITON_CORE30_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc30_inst_done
`ifdef RTL_SPARC30
    `define PITON_CORE30_PC_W30     `PCPATH30.fdp.pc_w
`else
    `define PITON_CORE30_PC_W30     `TOP_MOD.monitor.pc_cmp.spc30_phy_pc_w
`endif

    

    `define TILE31            `CHIP.tile31
    `define ARIANE_CORE31     `TILE31.g_ariane_core.core.ariane
    `define SPARC_CORE31      `TILE31.g_sparc_core.core
    `define PICO_CORE31       `TILE31.g_picorv32_core.core
    `define CCX_TRANSDUCER31  `TILE31.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER31 `TILE31.g_picorv32_core.pico_l15_transducer
    `define L15_TOP31         `TILE31.l15.l15
    `define L15_PIPE31        `TILE31.l15.l15.pipeline
    `define DMBR31            `TILE31.dmbr_ins
    `define L2_TOP31          `TILE31.l2
    `define SPARC_REG31       `SPARC_CORE31.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH31       `SPARC_CORE31.sparc0.ffu.ffu
`else
    `define FLOATPATH31       `SPARC_CORE31.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH31         `SPARC_CORE31.sparc0.tlu.tlu
    `define DTLBPATH31        `SPARC_CORE31.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH31         `SPARC_CORE31.sparc0.tlu
    `define DTLBPATH31        `SPARC_CORE31.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH31         `SPARC_CORE31.sparc0
`ifndef RTL_SPU
    `define ICVPATH31         `SPARC_CORE31.sparc0.ifu.ifu.icv
    `define IFUPATH31         `SPARC_CORE31.sparc0.ifu.ifu
    `define TNUM31S           `SPARC_CORE31.sparc0.ifu.ifu.swl
    `define TPC31S            `SPARC_CORE31.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH31         `SPARC_CORE31.sparc0.ifu.icv
    `define IFUPATH31         `SPARC_CORE31.sparc0.ifu
    `define TNUM31S           `SPARC_CORE31.sparc0.ifu.swl
    `define TPC31S            `SPARC_CORE31.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH31         `SPARC_CORE31.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH31         `SPARC_CORE31.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH31         `SPARC_CORE31.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH31         `SPARC_CORE31.sparc0.ifu.fdp
`endif
    `define ALUPATH31         `SPARC_CORE31.sparc0.exu.exu.alu
    `define SPCPATH31         `SPARC_CORE31.sparc0
    `define REGPATH31         `SPARC_CORE31.sparc0.exu.exu.irf.irf
    `define CCRPATH31         `SPARC_CORE31.sparc0.exu.exu.ecl.ccr
    `define EXUPATH31         `SPARC_CORE31.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH31          `SPARC_CORE31.sparc0.tlu.tlu.tcl
    `define TS0PATH31         `SPARC_CORE31.sparc0.tlu.tlu.tsa0
    `define TS1PATH31         `SPARC_CORE31.sparc0.tlu.tlu.tsa1
    `define INTPATH31         `SPARC_CORE31.sparc0.tlu.tlu.intdp
    `define ASIPATH31         `SPARC_CORE31.sparc0.lsu.lsu.dctl
    `define ASIDPPATH31       `SPARC_CORE31.sparc0.lsu.lsu.dctldp
    `define ICTPATH31         `SPARC_CORE31.sparc0.ifu.ifu.ict
    `define DCACHE31          `SPARC_CORE31.sparc0.lsu.lsu.dcache
    `define INSTPATH31        `SPARC_CORE31.sparc0.ifu.ifu.fcl
    `define PCPATH31          `SPARC_CORE31.sparc0.ifu.ifu
    `define DVLD31            `SPARC_CORE31.sparc0.lsu.lsu.dva
    `define DTAG31            `SPARC_CORE31.sparc0.lsu.lsu.dtag
    `define SDTAG31           `SPARC_CORE31.sparc0.lsu.lsu.dtag
    `define SDVLD31           `SPARC_CORE31.sparc0.lsu.lsu.dva
    `define FFUPATH31         `SPARC_CORE31.sparc0.ffu.ffu
    `define TLU_HYPER31       `SPARC_CORE31.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP31           `SPARC_CORE31.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH31        `SPARC_CORE31.sparc0.ifu.ifu.itlb
`else
    `define TLPATH31          `SPARC_CORE31.sparc0.tlu.tcl
    `define TS0PATH31         `SPARC_CORE31.sparc0.tlu.tsa0
    `define TS1PATH31         `SPARC_CORE31.sparc0.tlu.tsa1
    `define INTPATH31         `SPARC_CORE31.sparc0.tlu.intdp
    `define ASIPATH31         `SPARC_CORE31.sparc0.lsu.dctl
    `define ASIDPPATH31       `SPARC_CORE31.sparc0.lsu.dctldp
    `define ICTPATH31         `SPARC_CORE31.sparc0.ifu.ict
    `define DCACHE31          `SPARC_CORE31.sparc0.lsu.dcache
    `define INSTPATH31        `SPARC_CORE31.sparc0.ifu.fcl
    `define PCPATH31          `SPARC_CORE31.sparc0.ifu
    `define DVLD31            `SPARC_CORE31.sparc0.lsu.dva
    `define DTAG31            `SPARC_CORE31.sparc0.lsu.dtag
    `define SDTAG31           `SPARC_CORE31.sparc0.lsu.dtag
    `define SDVLD31           `SPARC_CORE31.sparc0.lsu.dva
    `define FFUPATH31         `SPARC_CORE31.sparc0.ffu
    `define TLU_HYPER31       `SPARC_CORE31.sparc0.tlu.tlu_hyperv
    `define IFQDP31           `SPARC_CORE31.sparc0.ifu.ifqdp
    `define ITLBPATH31        `SPARC_CORE31.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH31    `SPARC_CORE31.sparc0.cfg_asi

    `define PITON_CORE31_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc31_inst_done
`ifdef RTL_SPARC31
    `define PITON_CORE31_PC_W31     `PCPATH31.fdp.pc_w
`else
    `define PITON_CORE31_PC_W31     `TOP_MOD.monitor.pc_cmp.spc31_phy_pc_w
`endif

    

    `define TILE32            `CHIP.tile32
    `define ARIANE_CORE32     `TILE32.g_ariane_core.core.ariane
    `define SPARC_CORE32      `TILE32.g_sparc_core.core
    `define PICO_CORE32       `TILE32.g_picorv32_core.core
    `define CCX_TRANSDUCER32  `TILE32.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER32 `TILE32.g_picorv32_core.pico_l15_transducer
    `define L15_TOP32         `TILE32.l15.l15
    `define L15_PIPE32        `TILE32.l15.l15.pipeline
    `define DMBR32            `TILE32.dmbr_ins
    `define L2_TOP32          `TILE32.l2
    `define SPARC_REG32       `SPARC_CORE32.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH32       `SPARC_CORE32.sparc0.ffu.ffu
`else
    `define FLOATPATH32       `SPARC_CORE32.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH32         `SPARC_CORE32.sparc0.tlu.tlu
    `define DTLBPATH32        `SPARC_CORE32.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH32         `SPARC_CORE32.sparc0.tlu
    `define DTLBPATH32        `SPARC_CORE32.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH32         `SPARC_CORE32.sparc0
`ifndef RTL_SPU
    `define ICVPATH32         `SPARC_CORE32.sparc0.ifu.ifu.icv
    `define IFUPATH32         `SPARC_CORE32.sparc0.ifu.ifu
    `define TNUM32S           `SPARC_CORE32.sparc0.ifu.ifu.swl
    `define TPC32S            `SPARC_CORE32.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH32         `SPARC_CORE32.sparc0.ifu.icv
    `define IFUPATH32         `SPARC_CORE32.sparc0.ifu
    `define TNUM32S           `SPARC_CORE32.sparc0.ifu.swl
    `define TPC32S            `SPARC_CORE32.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH32         `SPARC_CORE32.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH32         `SPARC_CORE32.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH32         `SPARC_CORE32.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH32         `SPARC_CORE32.sparc0.ifu.fdp
`endif
    `define ALUPATH32         `SPARC_CORE32.sparc0.exu.exu.alu
    `define SPCPATH32         `SPARC_CORE32.sparc0
    `define REGPATH32         `SPARC_CORE32.sparc0.exu.exu.irf.irf
    `define CCRPATH32         `SPARC_CORE32.sparc0.exu.exu.ecl.ccr
    `define EXUPATH32         `SPARC_CORE32.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH32          `SPARC_CORE32.sparc0.tlu.tlu.tcl
    `define TS0PATH32         `SPARC_CORE32.sparc0.tlu.tlu.tsa0
    `define TS1PATH32         `SPARC_CORE32.sparc0.tlu.tlu.tsa1
    `define INTPATH32         `SPARC_CORE32.sparc0.tlu.tlu.intdp
    `define ASIPATH32         `SPARC_CORE32.sparc0.lsu.lsu.dctl
    `define ASIDPPATH32       `SPARC_CORE32.sparc0.lsu.lsu.dctldp
    `define ICTPATH32         `SPARC_CORE32.sparc0.ifu.ifu.ict
    `define DCACHE32          `SPARC_CORE32.sparc0.lsu.lsu.dcache
    `define INSTPATH32        `SPARC_CORE32.sparc0.ifu.ifu.fcl
    `define PCPATH32          `SPARC_CORE32.sparc0.ifu.ifu
    `define DVLD32            `SPARC_CORE32.sparc0.lsu.lsu.dva
    `define DTAG32            `SPARC_CORE32.sparc0.lsu.lsu.dtag
    `define SDTAG32           `SPARC_CORE32.sparc0.lsu.lsu.dtag
    `define SDVLD32           `SPARC_CORE32.sparc0.lsu.lsu.dva
    `define FFUPATH32         `SPARC_CORE32.sparc0.ffu.ffu
    `define TLU_HYPER32       `SPARC_CORE32.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP32           `SPARC_CORE32.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH32        `SPARC_CORE32.sparc0.ifu.ifu.itlb
`else
    `define TLPATH32          `SPARC_CORE32.sparc0.tlu.tcl
    `define TS0PATH32         `SPARC_CORE32.sparc0.tlu.tsa0
    `define TS1PATH32         `SPARC_CORE32.sparc0.tlu.tsa1
    `define INTPATH32         `SPARC_CORE32.sparc0.tlu.intdp
    `define ASIPATH32         `SPARC_CORE32.sparc0.lsu.dctl
    `define ASIDPPATH32       `SPARC_CORE32.sparc0.lsu.dctldp
    `define ICTPATH32         `SPARC_CORE32.sparc0.ifu.ict
    `define DCACHE32          `SPARC_CORE32.sparc0.lsu.dcache
    `define INSTPATH32        `SPARC_CORE32.sparc0.ifu.fcl
    `define PCPATH32          `SPARC_CORE32.sparc0.ifu
    `define DVLD32            `SPARC_CORE32.sparc0.lsu.dva
    `define DTAG32            `SPARC_CORE32.sparc0.lsu.dtag
    `define SDTAG32           `SPARC_CORE32.sparc0.lsu.dtag
    `define SDVLD32           `SPARC_CORE32.sparc0.lsu.dva
    `define FFUPATH32         `SPARC_CORE32.sparc0.ffu
    `define TLU_HYPER32       `SPARC_CORE32.sparc0.tlu.tlu_hyperv
    `define IFQDP32           `SPARC_CORE32.sparc0.ifu.ifqdp
    `define ITLBPATH32        `SPARC_CORE32.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH32    `SPARC_CORE32.sparc0.cfg_asi

    `define PITON_CORE32_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc32_inst_done
`ifdef RTL_SPARC32
    `define PITON_CORE32_PC_W32     `PCPATH32.fdp.pc_w
`else
    `define PITON_CORE32_PC_W32     `TOP_MOD.monitor.pc_cmp.spc32_phy_pc_w
`endif

    

    `define TILE33            `CHIP.tile33
    `define ARIANE_CORE33     `TILE33.g_ariane_core.core.ariane
    `define SPARC_CORE33      `TILE33.g_sparc_core.core
    `define PICO_CORE33       `TILE33.g_picorv32_core.core
    `define CCX_TRANSDUCER33  `TILE33.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER33 `TILE33.g_picorv32_core.pico_l15_transducer
    `define L15_TOP33         `TILE33.l15.l15
    `define L15_PIPE33        `TILE33.l15.l15.pipeline
    `define DMBR33            `TILE33.dmbr_ins
    `define L2_TOP33          `TILE33.l2
    `define SPARC_REG33       `SPARC_CORE33.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH33       `SPARC_CORE33.sparc0.ffu.ffu
`else
    `define FLOATPATH33       `SPARC_CORE33.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH33         `SPARC_CORE33.sparc0.tlu.tlu
    `define DTLBPATH33        `SPARC_CORE33.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH33         `SPARC_CORE33.sparc0.tlu
    `define DTLBPATH33        `SPARC_CORE33.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH33         `SPARC_CORE33.sparc0
`ifndef RTL_SPU
    `define ICVPATH33         `SPARC_CORE33.sparc0.ifu.ifu.icv
    `define IFUPATH33         `SPARC_CORE33.sparc0.ifu.ifu
    `define TNUM33S           `SPARC_CORE33.sparc0.ifu.ifu.swl
    `define TPC33S            `SPARC_CORE33.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH33         `SPARC_CORE33.sparc0.ifu.icv
    `define IFUPATH33         `SPARC_CORE33.sparc0.ifu
    `define TNUM33S           `SPARC_CORE33.sparc0.ifu.swl
    `define TPC33S            `SPARC_CORE33.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH33         `SPARC_CORE33.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH33         `SPARC_CORE33.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH33         `SPARC_CORE33.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH33         `SPARC_CORE33.sparc0.ifu.fdp
`endif
    `define ALUPATH33         `SPARC_CORE33.sparc0.exu.exu.alu
    `define SPCPATH33         `SPARC_CORE33.sparc0
    `define REGPATH33         `SPARC_CORE33.sparc0.exu.exu.irf.irf
    `define CCRPATH33         `SPARC_CORE33.sparc0.exu.exu.ecl.ccr
    `define EXUPATH33         `SPARC_CORE33.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH33          `SPARC_CORE33.sparc0.tlu.tlu.tcl
    `define TS0PATH33         `SPARC_CORE33.sparc0.tlu.tlu.tsa0
    `define TS1PATH33         `SPARC_CORE33.sparc0.tlu.tlu.tsa1
    `define INTPATH33         `SPARC_CORE33.sparc0.tlu.tlu.intdp
    `define ASIPATH33         `SPARC_CORE33.sparc0.lsu.lsu.dctl
    `define ASIDPPATH33       `SPARC_CORE33.sparc0.lsu.lsu.dctldp
    `define ICTPATH33         `SPARC_CORE33.sparc0.ifu.ifu.ict
    `define DCACHE33          `SPARC_CORE33.sparc0.lsu.lsu.dcache
    `define INSTPATH33        `SPARC_CORE33.sparc0.ifu.ifu.fcl
    `define PCPATH33          `SPARC_CORE33.sparc0.ifu.ifu
    `define DVLD33            `SPARC_CORE33.sparc0.lsu.lsu.dva
    `define DTAG33            `SPARC_CORE33.sparc0.lsu.lsu.dtag
    `define SDTAG33           `SPARC_CORE33.sparc0.lsu.lsu.dtag
    `define SDVLD33           `SPARC_CORE33.sparc0.lsu.lsu.dva
    `define FFUPATH33         `SPARC_CORE33.sparc0.ffu.ffu
    `define TLU_HYPER33       `SPARC_CORE33.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP33           `SPARC_CORE33.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH33        `SPARC_CORE33.sparc0.ifu.ifu.itlb
`else
    `define TLPATH33          `SPARC_CORE33.sparc0.tlu.tcl
    `define TS0PATH33         `SPARC_CORE33.sparc0.tlu.tsa0
    `define TS1PATH33         `SPARC_CORE33.sparc0.tlu.tsa1
    `define INTPATH33         `SPARC_CORE33.sparc0.tlu.intdp
    `define ASIPATH33         `SPARC_CORE33.sparc0.lsu.dctl
    `define ASIDPPATH33       `SPARC_CORE33.sparc0.lsu.dctldp
    `define ICTPATH33         `SPARC_CORE33.sparc0.ifu.ict
    `define DCACHE33          `SPARC_CORE33.sparc0.lsu.dcache
    `define INSTPATH33        `SPARC_CORE33.sparc0.ifu.fcl
    `define PCPATH33          `SPARC_CORE33.sparc0.ifu
    `define DVLD33            `SPARC_CORE33.sparc0.lsu.dva
    `define DTAG33            `SPARC_CORE33.sparc0.lsu.dtag
    `define SDTAG33           `SPARC_CORE33.sparc0.lsu.dtag
    `define SDVLD33           `SPARC_CORE33.sparc0.lsu.dva
    `define FFUPATH33         `SPARC_CORE33.sparc0.ffu
    `define TLU_HYPER33       `SPARC_CORE33.sparc0.tlu.tlu_hyperv
    `define IFQDP33           `SPARC_CORE33.sparc0.ifu.ifqdp
    `define ITLBPATH33        `SPARC_CORE33.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH33    `SPARC_CORE33.sparc0.cfg_asi

    `define PITON_CORE33_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc33_inst_done
`ifdef RTL_SPARC33
    `define PITON_CORE33_PC_W33     `PCPATH33.fdp.pc_w
`else
    `define PITON_CORE33_PC_W33     `TOP_MOD.monitor.pc_cmp.spc33_phy_pc_w
`endif

    

    `define TILE34            `CHIP.tile34
    `define ARIANE_CORE34     `TILE34.g_ariane_core.core.ariane
    `define SPARC_CORE34      `TILE34.g_sparc_core.core
    `define PICO_CORE34       `TILE34.g_picorv32_core.core
    `define CCX_TRANSDUCER34  `TILE34.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER34 `TILE34.g_picorv32_core.pico_l15_transducer
    `define L15_TOP34         `TILE34.l15.l15
    `define L15_PIPE34        `TILE34.l15.l15.pipeline
    `define DMBR34            `TILE34.dmbr_ins
    `define L2_TOP34          `TILE34.l2
    `define SPARC_REG34       `SPARC_CORE34.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH34       `SPARC_CORE34.sparc0.ffu.ffu
`else
    `define FLOATPATH34       `SPARC_CORE34.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH34         `SPARC_CORE34.sparc0.tlu.tlu
    `define DTLBPATH34        `SPARC_CORE34.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH34         `SPARC_CORE34.sparc0.tlu
    `define DTLBPATH34        `SPARC_CORE34.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH34         `SPARC_CORE34.sparc0
`ifndef RTL_SPU
    `define ICVPATH34         `SPARC_CORE34.sparc0.ifu.ifu.icv
    `define IFUPATH34         `SPARC_CORE34.sparc0.ifu.ifu
    `define TNUM34S           `SPARC_CORE34.sparc0.ifu.ifu.swl
    `define TPC34S            `SPARC_CORE34.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH34         `SPARC_CORE34.sparc0.ifu.icv
    `define IFUPATH34         `SPARC_CORE34.sparc0.ifu
    `define TNUM34S           `SPARC_CORE34.sparc0.ifu.swl
    `define TPC34S            `SPARC_CORE34.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH34         `SPARC_CORE34.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH34         `SPARC_CORE34.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH34         `SPARC_CORE34.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH34         `SPARC_CORE34.sparc0.ifu.fdp
`endif
    `define ALUPATH34         `SPARC_CORE34.sparc0.exu.exu.alu
    `define SPCPATH34         `SPARC_CORE34.sparc0
    `define REGPATH34         `SPARC_CORE34.sparc0.exu.exu.irf.irf
    `define CCRPATH34         `SPARC_CORE34.sparc0.exu.exu.ecl.ccr
    `define EXUPATH34         `SPARC_CORE34.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH34          `SPARC_CORE34.sparc0.tlu.tlu.tcl
    `define TS0PATH34         `SPARC_CORE34.sparc0.tlu.tlu.tsa0
    `define TS1PATH34         `SPARC_CORE34.sparc0.tlu.tlu.tsa1
    `define INTPATH34         `SPARC_CORE34.sparc0.tlu.tlu.intdp
    `define ASIPATH34         `SPARC_CORE34.sparc0.lsu.lsu.dctl
    `define ASIDPPATH34       `SPARC_CORE34.sparc0.lsu.lsu.dctldp
    `define ICTPATH34         `SPARC_CORE34.sparc0.ifu.ifu.ict
    `define DCACHE34          `SPARC_CORE34.sparc0.lsu.lsu.dcache
    `define INSTPATH34        `SPARC_CORE34.sparc0.ifu.ifu.fcl
    `define PCPATH34          `SPARC_CORE34.sparc0.ifu.ifu
    `define DVLD34            `SPARC_CORE34.sparc0.lsu.lsu.dva
    `define DTAG34            `SPARC_CORE34.sparc0.lsu.lsu.dtag
    `define SDTAG34           `SPARC_CORE34.sparc0.lsu.lsu.dtag
    `define SDVLD34           `SPARC_CORE34.sparc0.lsu.lsu.dva
    `define FFUPATH34         `SPARC_CORE34.sparc0.ffu.ffu
    `define TLU_HYPER34       `SPARC_CORE34.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP34           `SPARC_CORE34.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH34        `SPARC_CORE34.sparc0.ifu.ifu.itlb
`else
    `define TLPATH34          `SPARC_CORE34.sparc0.tlu.tcl
    `define TS0PATH34         `SPARC_CORE34.sparc0.tlu.tsa0
    `define TS1PATH34         `SPARC_CORE34.sparc0.tlu.tsa1
    `define INTPATH34         `SPARC_CORE34.sparc0.tlu.intdp
    `define ASIPATH34         `SPARC_CORE34.sparc0.lsu.dctl
    `define ASIDPPATH34       `SPARC_CORE34.sparc0.lsu.dctldp
    `define ICTPATH34         `SPARC_CORE34.sparc0.ifu.ict
    `define DCACHE34          `SPARC_CORE34.sparc0.lsu.dcache
    `define INSTPATH34        `SPARC_CORE34.sparc0.ifu.fcl
    `define PCPATH34          `SPARC_CORE34.sparc0.ifu
    `define DVLD34            `SPARC_CORE34.sparc0.lsu.dva
    `define DTAG34            `SPARC_CORE34.sparc0.lsu.dtag
    `define SDTAG34           `SPARC_CORE34.sparc0.lsu.dtag
    `define SDVLD34           `SPARC_CORE34.sparc0.lsu.dva
    `define FFUPATH34         `SPARC_CORE34.sparc0.ffu
    `define TLU_HYPER34       `SPARC_CORE34.sparc0.tlu.tlu_hyperv
    `define IFQDP34           `SPARC_CORE34.sparc0.ifu.ifqdp
    `define ITLBPATH34        `SPARC_CORE34.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH34    `SPARC_CORE34.sparc0.cfg_asi

    `define PITON_CORE34_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc34_inst_done
`ifdef RTL_SPARC34
    `define PITON_CORE34_PC_W34     `PCPATH34.fdp.pc_w
`else
    `define PITON_CORE34_PC_W34     `TOP_MOD.monitor.pc_cmp.spc34_phy_pc_w
`endif

    

    `define TILE35            `CHIP.tile35
    `define ARIANE_CORE35     `TILE35.g_ariane_core.core.ariane
    `define SPARC_CORE35      `TILE35.g_sparc_core.core
    `define PICO_CORE35       `TILE35.g_picorv32_core.core
    `define CCX_TRANSDUCER35  `TILE35.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER35 `TILE35.g_picorv32_core.pico_l15_transducer
    `define L15_TOP35         `TILE35.l15.l15
    `define L15_PIPE35        `TILE35.l15.l15.pipeline
    `define DMBR35            `TILE35.dmbr_ins
    `define L2_TOP35          `TILE35.l2
    `define SPARC_REG35       `SPARC_CORE35.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH35       `SPARC_CORE35.sparc0.ffu.ffu
`else
    `define FLOATPATH35       `SPARC_CORE35.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH35         `SPARC_CORE35.sparc0.tlu.tlu
    `define DTLBPATH35        `SPARC_CORE35.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH35         `SPARC_CORE35.sparc0.tlu
    `define DTLBPATH35        `SPARC_CORE35.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH35         `SPARC_CORE35.sparc0
`ifndef RTL_SPU
    `define ICVPATH35         `SPARC_CORE35.sparc0.ifu.ifu.icv
    `define IFUPATH35         `SPARC_CORE35.sparc0.ifu.ifu
    `define TNUM35S           `SPARC_CORE35.sparc0.ifu.ifu.swl
    `define TPC35S            `SPARC_CORE35.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH35         `SPARC_CORE35.sparc0.ifu.icv
    `define IFUPATH35         `SPARC_CORE35.sparc0.ifu
    `define TNUM35S           `SPARC_CORE35.sparc0.ifu.swl
    `define TPC35S            `SPARC_CORE35.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH35         `SPARC_CORE35.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH35         `SPARC_CORE35.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH35         `SPARC_CORE35.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH35         `SPARC_CORE35.sparc0.ifu.fdp
`endif
    `define ALUPATH35         `SPARC_CORE35.sparc0.exu.exu.alu
    `define SPCPATH35         `SPARC_CORE35.sparc0
    `define REGPATH35         `SPARC_CORE35.sparc0.exu.exu.irf.irf
    `define CCRPATH35         `SPARC_CORE35.sparc0.exu.exu.ecl.ccr
    `define EXUPATH35         `SPARC_CORE35.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH35          `SPARC_CORE35.sparc0.tlu.tlu.tcl
    `define TS0PATH35         `SPARC_CORE35.sparc0.tlu.tlu.tsa0
    `define TS1PATH35         `SPARC_CORE35.sparc0.tlu.tlu.tsa1
    `define INTPATH35         `SPARC_CORE35.sparc0.tlu.tlu.intdp
    `define ASIPATH35         `SPARC_CORE35.sparc0.lsu.lsu.dctl
    `define ASIDPPATH35       `SPARC_CORE35.sparc0.lsu.lsu.dctldp
    `define ICTPATH35         `SPARC_CORE35.sparc0.ifu.ifu.ict
    `define DCACHE35          `SPARC_CORE35.sparc0.lsu.lsu.dcache
    `define INSTPATH35        `SPARC_CORE35.sparc0.ifu.ifu.fcl
    `define PCPATH35          `SPARC_CORE35.sparc0.ifu.ifu
    `define DVLD35            `SPARC_CORE35.sparc0.lsu.lsu.dva
    `define DTAG35            `SPARC_CORE35.sparc0.lsu.lsu.dtag
    `define SDTAG35           `SPARC_CORE35.sparc0.lsu.lsu.dtag
    `define SDVLD35           `SPARC_CORE35.sparc0.lsu.lsu.dva
    `define FFUPATH35         `SPARC_CORE35.sparc0.ffu.ffu
    `define TLU_HYPER35       `SPARC_CORE35.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP35           `SPARC_CORE35.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH35        `SPARC_CORE35.sparc0.ifu.ifu.itlb
`else
    `define TLPATH35          `SPARC_CORE35.sparc0.tlu.tcl
    `define TS0PATH35         `SPARC_CORE35.sparc0.tlu.tsa0
    `define TS1PATH35         `SPARC_CORE35.sparc0.tlu.tsa1
    `define INTPATH35         `SPARC_CORE35.sparc0.tlu.intdp
    `define ASIPATH35         `SPARC_CORE35.sparc0.lsu.dctl
    `define ASIDPPATH35       `SPARC_CORE35.sparc0.lsu.dctldp
    `define ICTPATH35         `SPARC_CORE35.sparc0.ifu.ict
    `define DCACHE35          `SPARC_CORE35.sparc0.lsu.dcache
    `define INSTPATH35        `SPARC_CORE35.sparc0.ifu.fcl
    `define PCPATH35          `SPARC_CORE35.sparc0.ifu
    `define DVLD35            `SPARC_CORE35.sparc0.lsu.dva
    `define DTAG35            `SPARC_CORE35.sparc0.lsu.dtag
    `define SDTAG35           `SPARC_CORE35.sparc0.lsu.dtag
    `define SDVLD35           `SPARC_CORE35.sparc0.lsu.dva
    `define FFUPATH35         `SPARC_CORE35.sparc0.ffu
    `define TLU_HYPER35       `SPARC_CORE35.sparc0.tlu.tlu_hyperv
    `define IFQDP35           `SPARC_CORE35.sparc0.ifu.ifqdp
    `define ITLBPATH35        `SPARC_CORE35.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH35    `SPARC_CORE35.sparc0.cfg_asi

    `define PITON_CORE35_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc35_inst_done
`ifdef RTL_SPARC35
    `define PITON_CORE35_PC_W35     `PCPATH35.fdp.pc_w
`else
    `define PITON_CORE35_PC_W35     `TOP_MOD.monitor.pc_cmp.spc35_phy_pc_w
`endif

    

    `define TILE36            `CHIP.tile36
    `define ARIANE_CORE36     `TILE36.g_ariane_core.core.ariane
    `define SPARC_CORE36      `TILE36.g_sparc_core.core
    `define PICO_CORE36       `TILE36.g_picorv32_core.core
    `define CCX_TRANSDUCER36  `TILE36.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER36 `TILE36.g_picorv32_core.pico_l15_transducer
    `define L15_TOP36         `TILE36.l15.l15
    `define L15_PIPE36        `TILE36.l15.l15.pipeline
    `define DMBR36            `TILE36.dmbr_ins
    `define L2_TOP36          `TILE36.l2
    `define SPARC_REG36       `SPARC_CORE36.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH36       `SPARC_CORE36.sparc0.ffu.ffu
`else
    `define FLOATPATH36       `SPARC_CORE36.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH36         `SPARC_CORE36.sparc0.tlu.tlu
    `define DTLBPATH36        `SPARC_CORE36.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH36         `SPARC_CORE36.sparc0.tlu
    `define DTLBPATH36        `SPARC_CORE36.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH36         `SPARC_CORE36.sparc0
`ifndef RTL_SPU
    `define ICVPATH36         `SPARC_CORE36.sparc0.ifu.ifu.icv
    `define IFUPATH36         `SPARC_CORE36.sparc0.ifu.ifu
    `define TNUM36S           `SPARC_CORE36.sparc0.ifu.ifu.swl
    `define TPC36S            `SPARC_CORE36.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH36         `SPARC_CORE36.sparc0.ifu.icv
    `define IFUPATH36         `SPARC_CORE36.sparc0.ifu
    `define TNUM36S           `SPARC_CORE36.sparc0.ifu.swl
    `define TPC36S            `SPARC_CORE36.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH36         `SPARC_CORE36.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH36         `SPARC_CORE36.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH36         `SPARC_CORE36.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH36         `SPARC_CORE36.sparc0.ifu.fdp
`endif
    `define ALUPATH36         `SPARC_CORE36.sparc0.exu.exu.alu
    `define SPCPATH36         `SPARC_CORE36.sparc0
    `define REGPATH36         `SPARC_CORE36.sparc0.exu.exu.irf.irf
    `define CCRPATH36         `SPARC_CORE36.sparc0.exu.exu.ecl.ccr
    `define EXUPATH36         `SPARC_CORE36.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH36          `SPARC_CORE36.sparc0.tlu.tlu.tcl
    `define TS0PATH36         `SPARC_CORE36.sparc0.tlu.tlu.tsa0
    `define TS1PATH36         `SPARC_CORE36.sparc0.tlu.tlu.tsa1
    `define INTPATH36         `SPARC_CORE36.sparc0.tlu.tlu.intdp
    `define ASIPATH36         `SPARC_CORE36.sparc0.lsu.lsu.dctl
    `define ASIDPPATH36       `SPARC_CORE36.sparc0.lsu.lsu.dctldp
    `define ICTPATH36         `SPARC_CORE36.sparc0.ifu.ifu.ict
    `define DCACHE36          `SPARC_CORE36.sparc0.lsu.lsu.dcache
    `define INSTPATH36        `SPARC_CORE36.sparc0.ifu.ifu.fcl
    `define PCPATH36          `SPARC_CORE36.sparc0.ifu.ifu
    `define DVLD36            `SPARC_CORE36.sparc0.lsu.lsu.dva
    `define DTAG36            `SPARC_CORE36.sparc0.lsu.lsu.dtag
    `define SDTAG36           `SPARC_CORE36.sparc0.lsu.lsu.dtag
    `define SDVLD36           `SPARC_CORE36.sparc0.lsu.lsu.dva
    `define FFUPATH36         `SPARC_CORE36.sparc0.ffu.ffu
    `define TLU_HYPER36       `SPARC_CORE36.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP36           `SPARC_CORE36.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH36        `SPARC_CORE36.sparc0.ifu.ifu.itlb
`else
    `define TLPATH36          `SPARC_CORE36.sparc0.tlu.tcl
    `define TS0PATH36         `SPARC_CORE36.sparc0.tlu.tsa0
    `define TS1PATH36         `SPARC_CORE36.sparc0.tlu.tsa1
    `define INTPATH36         `SPARC_CORE36.sparc0.tlu.intdp
    `define ASIPATH36         `SPARC_CORE36.sparc0.lsu.dctl
    `define ASIDPPATH36       `SPARC_CORE36.sparc0.lsu.dctldp
    `define ICTPATH36         `SPARC_CORE36.sparc0.ifu.ict
    `define DCACHE36          `SPARC_CORE36.sparc0.lsu.dcache
    `define INSTPATH36        `SPARC_CORE36.sparc0.ifu.fcl
    `define PCPATH36          `SPARC_CORE36.sparc0.ifu
    `define DVLD36            `SPARC_CORE36.sparc0.lsu.dva
    `define DTAG36            `SPARC_CORE36.sparc0.lsu.dtag
    `define SDTAG36           `SPARC_CORE36.sparc0.lsu.dtag
    `define SDVLD36           `SPARC_CORE36.sparc0.lsu.dva
    `define FFUPATH36         `SPARC_CORE36.sparc0.ffu
    `define TLU_HYPER36       `SPARC_CORE36.sparc0.tlu.tlu_hyperv
    `define IFQDP36           `SPARC_CORE36.sparc0.ifu.ifqdp
    `define ITLBPATH36        `SPARC_CORE36.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH36    `SPARC_CORE36.sparc0.cfg_asi

    `define PITON_CORE36_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc36_inst_done
`ifdef RTL_SPARC36
    `define PITON_CORE36_PC_W36     `PCPATH36.fdp.pc_w
`else
    `define PITON_CORE36_PC_W36     `TOP_MOD.monitor.pc_cmp.spc36_phy_pc_w
`endif

    

    `define TILE37            `CHIP.tile37
    `define ARIANE_CORE37     `TILE37.g_ariane_core.core.ariane
    `define SPARC_CORE37      `TILE37.g_sparc_core.core
    `define PICO_CORE37       `TILE37.g_picorv32_core.core
    `define CCX_TRANSDUCER37  `TILE37.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER37 `TILE37.g_picorv32_core.pico_l15_transducer
    `define L15_TOP37         `TILE37.l15.l15
    `define L15_PIPE37        `TILE37.l15.l15.pipeline
    `define DMBR37            `TILE37.dmbr_ins
    `define L2_TOP37          `TILE37.l2
    `define SPARC_REG37       `SPARC_CORE37.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH37       `SPARC_CORE37.sparc0.ffu.ffu
`else
    `define FLOATPATH37       `SPARC_CORE37.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH37         `SPARC_CORE37.sparc0.tlu.tlu
    `define DTLBPATH37        `SPARC_CORE37.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH37         `SPARC_CORE37.sparc0.tlu
    `define DTLBPATH37        `SPARC_CORE37.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH37         `SPARC_CORE37.sparc0
`ifndef RTL_SPU
    `define ICVPATH37         `SPARC_CORE37.sparc0.ifu.ifu.icv
    `define IFUPATH37         `SPARC_CORE37.sparc0.ifu.ifu
    `define TNUM37S           `SPARC_CORE37.sparc0.ifu.ifu.swl
    `define TPC37S            `SPARC_CORE37.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH37         `SPARC_CORE37.sparc0.ifu.icv
    `define IFUPATH37         `SPARC_CORE37.sparc0.ifu
    `define TNUM37S           `SPARC_CORE37.sparc0.ifu.swl
    `define TPC37S            `SPARC_CORE37.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH37         `SPARC_CORE37.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH37         `SPARC_CORE37.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH37         `SPARC_CORE37.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH37         `SPARC_CORE37.sparc0.ifu.fdp
`endif
    `define ALUPATH37         `SPARC_CORE37.sparc0.exu.exu.alu
    `define SPCPATH37         `SPARC_CORE37.sparc0
    `define REGPATH37         `SPARC_CORE37.sparc0.exu.exu.irf.irf
    `define CCRPATH37         `SPARC_CORE37.sparc0.exu.exu.ecl.ccr
    `define EXUPATH37         `SPARC_CORE37.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH37          `SPARC_CORE37.sparc0.tlu.tlu.tcl
    `define TS0PATH37         `SPARC_CORE37.sparc0.tlu.tlu.tsa0
    `define TS1PATH37         `SPARC_CORE37.sparc0.tlu.tlu.tsa1
    `define INTPATH37         `SPARC_CORE37.sparc0.tlu.tlu.intdp
    `define ASIPATH37         `SPARC_CORE37.sparc0.lsu.lsu.dctl
    `define ASIDPPATH37       `SPARC_CORE37.sparc0.lsu.lsu.dctldp
    `define ICTPATH37         `SPARC_CORE37.sparc0.ifu.ifu.ict
    `define DCACHE37          `SPARC_CORE37.sparc0.lsu.lsu.dcache
    `define INSTPATH37        `SPARC_CORE37.sparc0.ifu.ifu.fcl
    `define PCPATH37          `SPARC_CORE37.sparc0.ifu.ifu
    `define DVLD37            `SPARC_CORE37.sparc0.lsu.lsu.dva
    `define DTAG37            `SPARC_CORE37.sparc0.lsu.lsu.dtag
    `define SDTAG37           `SPARC_CORE37.sparc0.lsu.lsu.dtag
    `define SDVLD37           `SPARC_CORE37.sparc0.lsu.lsu.dva
    `define FFUPATH37         `SPARC_CORE37.sparc0.ffu.ffu
    `define TLU_HYPER37       `SPARC_CORE37.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP37           `SPARC_CORE37.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH37        `SPARC_CORE37.sparc0.ifu.ifu.itlb
`else
    `define TLPATH37          `SPARC_CORE37.sparc0.tlu.tcl
    `define TS0PATH37         `SPARC_CORE37.sparc0.tlu.tsa0
    `define TS1PATH37         `SPARC_CORE37.sparc0.tlu.tsa1
    `define INTPATH37         `SPARC_CORE37.sparc0.tlu.intdp
    `define ASIPATH37         `SPARC_CORE37.sparc0.lsu.dctl
    `define ASIDPPATH37       `SPARC_CORE37.sparc0.lsu.dctldp
    `define ICTPATH37         `SPARC_CORE37.sparc0.ifu.ict
    `define DCACHE37          `SPARC_CORE37.sparc0.lsu.dcache
    `define INSTPATH37        `SPARC_CORE37.sparc0.ifu.fcl
    `define PCPATH37          `SPARC_CORE37.sparc0.ifu
    `define DVLD37            `SPARC_CORE37.sparc0.lsu.dva
    `define DTAG37            `SPARC_CORE37.sparc0.lsu.dtag
    `define SDTAG37           `SPARC_CORE37.sparc0.lsu.dtag
    `define SDVLD37           `SPARC_CORE37.sparc0.lsu.dva
    `define FFUPATH37         `SPARC_CORE37.sparc0.ffu
    `define TLU_HYPER37       `SPARC_CORE37.sparc0.tlu.tlu_hyperv
    `define IFQDP37           `SPARC_CORE37.sparc0.ifu.ifqdp
    `define ITLBPATH37        `SPARC_CORE37.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH37    `SPARC_CORE37.sparc0.cfg_asi

    `define PITON_CORE37_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc37_inst_done
`ifdef RTL_SPARC37
    `define PITON_CORE37_PC_W37     `PCPATH37.fdp.pc_w
`else
    `define PITON_CORE37_PC_W37     `TOP_MOD.monitor.pc_cmp.spc37_phy_pc_w
`endif

    

    `define TILE38            `CHIP.tile38
    `define ARIANE_CORE38     `TILE38.g_ariane_core.core.ariane
    `define SPARC_CORE38      `TILE38.g_sparc_core.core
    `define PICO_CORE38       `TILE38.g_picorv32_core.core
    `define CCX_TRANSDUCER38  `TILE38.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER38 `TILE38.g_picorv32_core.pico_l15_transducer
    `define L15_TOP38         `TILE38.l15.l15
    `define L15_PIPE38        `TILE38.l15.l15.pipeline
    `define DMBR38            `TILE38.dmbr_ins
    `define L2_TOP38          `TILE38.l2
    `define SPARC_REG38       `SPARC_CORE38.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH38       `SPARC_CORE38.sparc0.ffu.ffu
`else
    `define FLOATPATH38       `SPARC_CORE38.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH38         `SPARC_CORE38.sparc0.tlu.tlu
    `define DTLBPATH38        `SPARC_CORE38.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH38         `SPARC_CORE38.sparc0.tlu
    `define DTLBPATH38        `SPARC_CORE38.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH38         `SPARC_CORE38.sparc0
`ifndef RTL_SPU
    `define ICVPATH38         `SPARC_CORE38.sparc0.ifu.ifu.icv
    `define IFUPATH38         `SPARC_CORE38.sparc0.ifu.ifu
    `define TNUM38S           `SPARC_CORE38.sparc0.ifu.ifu.swl
    `define TPC38S            `SPARC_CORE38.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH38         `SPARC_CORE38.sparc0.ifu.icv
    `define IFUPATH38         `SPARC_CORE38.sparc0.ifu
    `define TNUM38S           `SPARC_CORE38.sparc0.ifu.swl
    `define TPC38S            `SPARC_CORE38.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH38         `SPARC_CORE38.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH38         `SPARC_CORE38.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH38         `SPARC_CORE38.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH38         `SPARC_CORE38.sparc0.ifu.fdp
`endif
    `define ALUPATH38         `SPARC_CORE38.sparc0.exu.exu.alu
    `define SPCPATH38         `SPARC_CORE38.sparc0
    `define REGPATH38         `SPARC_CORE38.sparc0.exu.exu.irf.irf
    `define CCRPATH38         `SPARC_CORE38.sparc0.exu.exu.ecl.ccr
    `define EXUPATH38         `SPARC_CORE38.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH38          `SPARC_CORE38.sparc0.tlu.tlu.tcl
    `define TS0PATH38         `SPARC_CORE38.sparc0.tlu.tlu.tsa0
    `define TS1PATH38         `SPARC_CORE38.sparc0.tlu.tlu.tsa1
    `define INTPATH38         `SPARC_CORE38.sparc0.tlu.tlu.intdp
    `define ASIPATH38         `SPARC_CORE38.sparc0.lsu.lsu.dctl
    `define ASIDPPATH38       `SPARC_CORE38.sparc0.lsu.lsu.dctldp
    `define ICTPATH38         `SPARC_CORE38.sparc0.ifu.ifu.ict
    `define DCACHE38          `SPARC_CORE38.sparc0.lsu.lsu.dcache
    `define INSTPATH38        `SPARC_CORE38.sparc0.ifu.ifu.fcl
    `define PCPATH38          `SPARC_CORE38.sparc0.ifu.ifu
    `define DVLD38            `SPARC_CORE38.sparc0.lsu.lsu.dva
    `define DTAG38            `SPARC_CORE38.sparc0.lsu.lsu.dtag
    `define SDTAG38           `SPARC_CORE38.sparc0.lsu.lsu.dtag
    `define SDVLD38           `SPARC_CORE38.sparc0.lsu.lsu.dva
    `define FFUPATH38         `SPARC_CORE38.sparc0.ffu.ffu
    `define TLU_HYPER38       `SPARC_CORE38.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP38           `SPARC_CORE38.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH38        `SPARC_CORE38.sparc0.ifu.ifu.itlb
`else
    `define TLPATH38          `SPARC_CORE38.sparc0.tlu.tcl
    `define TS0PATH38         `SPARC_CORE38.sparc0.tlu.tsa0
    `define TS1PATH38         `SPARC_CORE38.sparc0.tlu.tsa1
    `define INTPATH38         `SPARC_CORE38.sparc0.tlu.intdp
    `define ASIPATH38         `SPARC_CORE38.sparc0.lsu.dctl
    `define ASIDPPATH38       `SPARC_CORE38.sparc0.lsu.dctldp
    `define ICTPATH38         `SPARC_CORE38.sparc0.ifu.ict
    `define DCACHE38          `SPARC_CORE38.sparc0.lsu.dcache
    `define INSTPATH38        `SPARC_CORE38.sparc0.ifu.fcl
    `define PCPATH38          `SPARC_CORE38.sparc0.ifu
    `define DVLD38            `SPARC_CORE38.sparc0.lsu.dva
    `define DTAG38            `SPARC_CORE38.sparc0.lsu.dtag
    `define SDTAG38           `SPARC_CORE38.sparc0.lsu.dtag
    `define SDVLD38           `SPARC_CORE38.sparc0.lsu.dva
    `define FFUPATH38         `SPARC_CORE38.sparc0.ffu
    `define TLU_HYPER38       `SPARC_CORE38.sparc0.tlu.tlu_hyperv
    `define IFQDP38           `SPARC_CORE38.sparc0.ifu.ifqdp
    `define ITLBPATH38        `SPARC_CORE38.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH38    `SPARC_CORE38.sparc0.cfg_asi

    `define PITON_CORE38_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc38_inst_done
`ifdef RTL_SPARC38
    `define PITON_CORE38_PC_W38     `PCPATH38.fdp.pc_w
`else
    `define PITON_CORE38_PC_W38     `TOP_MOD.monitor.pc_cmp.spc38_phy_pc_w
`endif

    

    `define TILE39            `CHIP.tile39
    `define ARIANE_CORE39     `TILE39.g_ariane_core.core.ariane
    `define SPARC_CORE39      `TILE39.g_sparc_core.core
    `define PICO_CORE39       `TILE39.g_picorv32_core.core
    `define CCX_TRANSDUCER39  `TILE39.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER39 `TILE39.g_picorv32_core.pico_l15_transducer
    `define L15_TOP39         `TILE39.l15.l15
    `define L15_PIPE39        `TILE39.l15.l15.pipeline
    `define DMBR39            `TILE39.dmbr_ins
    `define L2_TOP39          `TILE39.l2
    `define SPARC_REG39       `SPARC_CORE39.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH39       `SPARC_CORE39.sparc0.ffu.ffu
`else
    `define FLOATPATH39       `SPARC_CORE39.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH39         `SPARC_CORE39.sparc0.tlu.tlu
    `define DTLBPATH39        `SPARC_CORE39.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH39         `SPARC_CORE39.sparc0.tlu
    `define DTLBPATH39        `SPARC_CORE39.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH39         `SPARC_CORE39.sparc0
`ifndef RTL_SPU
    `define ICVPATH39         `SPARC_CORE39.sparc0.ifu.ifu.icv
    `define IFUPATH39         `SPARC_CORE39.sparc0.ifu.ifu
    `define TNUM39S           `SPARC_CORE39.sparc0.ifu.ifu.swl
    `define TPC39S            `SPARC_CORE39.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH39         `SPARC_CORE39.sparc0.ifu.icv
    `define IFUPATH39         `SPARC_CORE39.sparc0.ifu
    `define TNUM39S           `SPARC_CORE39.sparc0.ifu.swl
    `define TPC39S            `SPARC_CORE39.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH39         `SPARC_CORE39.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH39         `SPARC_CORE39.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH39         `SPARC_CORE39.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH39         `SPARC_CORE39.sparc0.ifu.fdp
`endif
    `define ALUPATH39         `SPARC_CORE39.sparc0.exu.exu.alu
    `define SPCPATH39         `SPARC_CORE39.sparc0
    `define REGPATH39         `SPARC_CORE39.sparc0.exu.exu.irf.irf
    `define CCRPATH39         `SPARC_CORE39.sparc0.exu.exu.ecl.ccr
    `define EXUPATH39         `SPARC_CORE39.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH39          `SPARC_CORE39.sparc0.tlu.tlu.tcl
    `define TS0PATH39         `SPARC_CORE39.sparc0.tlu.tlu.tsa0
    `define TS1PATH39         `SPARC_CORE39.sparc0.tlu.tlu.tsa1
    `define INTPATH39         `SPARC_CORE39.sparc0.tlu.tlu.intdp
    `define ASIPATH39         `SPARC_CORE39.sparc0.lsu.lsu.dctl
    `define ASIDPPATH39       `SPARC_CORE39.sparc0.lsu.lsu.dctldp
    `define ICTPATH39         `SPARC_CORE39.sparc0.ifu.ifu.ict
    `define DCACHE39          `SPARC_CORE39.sparc0.lsu.lsu.dcache
    `define INSTPATH39        `SPARC_CORE39.sparc0.ifu.ifu.fcl
    `define PCPATH39          `SPARC_CORE39.sparc0.ifu.ifu
    `define DVLD39            `SPARC_CORE39.sparc0.lsu.lsu.dva
    `define DTAG39            `SPARC_CORE39.sparc0.lsu.lsu.dtag
    `define SDTAG39           `SPARC_CORE39.sparc0.lsu.lsu.dtag
    `define SDVLD39           `SPARC_CORE39.sparc0.lsu.lsu.dva
    `define FFUPATH39         `SPARC_CORE39.sparc0.ffu.ffu
    `define TLU_HYPER39       `SPARC_CORE39.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP39           `SPARC_CORE39.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH39        `SPARC_CORE39.sparc0.ifu.ifu.itlb
`else
    `define TLPATH39          `SPARC_CORE39.sparc0.tlu.tcl
    `define TS0PATH39         `SPARC_CORE39.sparc0.tlu.tsa0
    `define TS1PATH39         `SPARC_CORE39.sparc0.tlu.tsa1
    `define INTPATH39         `SPARC_CORE39.sparc0.tlu.intdp
    `define ASIPATH39         `SPARC_CORE39.sparc0.lsu.dctl
    `define ASIDPPATH39       `SPARC_CORE39.sparc0.lsu.dctldp
    `define ICTPATH39         `SPARC_CORE39.sparc0.ifu.ict
    `define DCACHE39          `SPARC_CORE39.sparc0.lsu.dcache
    `define INSTPATH39        `SPARC_CORE39.sparc0.ifu.fcl
    `define PCPATH39          `SPARC_CORE39.sparc0.ifu
    `define DVLD39            `SPARC_CORE39.sparc0.lsu.dva
    `define DTAG39            `SPARC_CORE39.sparc0.lsu.dtag
    `define SDTAG39           `SPARC_CORE39.sparc0.lsu.dtag
    `define SDVLD39           `SPARC_CORE39.sparc0.lsu.dva
    `define FFUPATH39         `SPARC_CORE39.sparc0.ffu
    `define TLU_HYPER39       `SPARC_CORE39.sparc0.tlu.tlu_hyperv
    `define IFQDP39           `SPARC_CORE39.sparc0.ifu.ifqdp
    `define ITLBPATH39        `SPARC_CORE39.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH39    `SPARC_CORE39.sparc0.cfg_asi

    `define PITON_CORE39_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc39_inst_done
`ifdef RTL_SPARC39
    `define PITON_CORE39_PC_W39     `PCPATH39.fdp.pc_w
`else
    `define PITON_CORE39_PC_W39     `TOP_MOD.monitor.pc_cmp.spc39_phy_pc_w
`endif

    

    `define TILE40            `CHIP.tile40
    `define ARIANE_CORE40     `TILE40.g_ariane_core.core.ariane
    `define SPARC_CORE40      `TILE40.g_sparc_core.core
    `define PICO_CORE40       `TILE40.g_picorv32_core.core
    `define CCX_TRANSDUCER40  `TILE40.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER40 `TILE40.g_picorv32_core.pico_l15_transducer
    `define L15_TOP40         `TILE40.l15.l15
    `define L15_PIPE40        `TILE40.l15.l15.pipeline
    `define DMBR40            `TILE40.dmbr_ins
    `define L2_TOP40          `TILE40.l2
    `define SPARC_REG40       `SPARC_CORE40.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH40       `SPARC_CORE40.sparc0.ffu.ffu
`else
    `define FLOATPATH40       `SPARC_CORE40.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH40         `SPARC_CORE40.sparc0.tlu.tlu
    `define DTLBPATH40        `SPARC_CORE40.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH40         `SPARC_CORE40.sparc0.tlu
    `define DTLBPATH40        `SPARC_CORE40.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH40         `SPARC_CORE40.sparc0
`ifndef RTL_SPU
    `define ICVPATH40         `SPARC_CORE40.sparc0.ifu.ifu.icv
    `define IFUPATH40         `SPARC_CORE40.sparc0.ifu.ifu
    `define TNUM40S           `SPARC_CORE40.sparc0.ifu.ifu.swl
    `define TPC40S            `SPARC_CORE40.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH40         `SPARC_CORE40.sparc0.ifu.icv
    `define IFUPATH40         `SPARC_CORE40.sparc0.ifu
    `define TNUM40S           `SPARC_CORE40.sparc0.ifu.swl
    `define TPC40S            `SPARC_CORE40.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH40         `SPARC_CORE40.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH40         `SPARC_CORE40.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH40         `SPARC_CORE40.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH40         `SPARC_CORE40.sparc0.ifu.fdp
`endif
    `define ALUPATH40         `SPARC_CORE40.sparc0.exu.exu.alu
    `define SPCPATH40         `SPARC_CORE40.sparc0
    `define REGPATH40         `SPARC_CORE40.sparc0.exu.exu.irf.irf
    `define CCRPATH40         `SPARC_CORE40.sparc0.exu.exu.ecl.ccr
    `define EXUPATH40         `SPARC_CORE40.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH40          `SPARC_CORE40.sparc0.tlu.tlu.tcl
    `define TS0PATH40         `SPARC_CORE40.sparc0.tlu.tlu.tsa0
    `define TS1PATH40         `SPARC_CORE40.sparc0.tlu.tlu.tsa1
    `define INTPATH40         `SPARC_CORE40.sparc0.tlu.tlu.intdp
    `define ASIPATH40         `SPARC_CORE40.sparc0.lsu.lsu.dctl
    `define ASIDPPATH40       `SPARC_CORE40.sparc0.lsu.lsu.dctldp
    `define ICTPATH40         `SPARC_CORE40.sparc0.ifu.ifu.ict
    `define DCACHE40          `SPARC_CORE40.sparc0.lsu.lsu.dcache
    `define INSTPATH40        `SPARC_CORE40.sparc0.ifu.ifu.fcl
    `define PCPATH40          `SPARC_CORE40.sparc0.ifu.ifu
    `define DVLD40            `SPARC_CORE40.sparc0.lsu.lsu.dva
    `define DTAG40            `SPARC_CORE40.sparc0.lsu.lsu.dtag
    `define SDTAG40           `SPARC_CORE40.sparc0.lsu.lsu.dtag
    `define SDVLD40           `SPARC_CORE40.sparc0.lsu.lsu.dva
    `define FFUPATH40         `SPARC_CORE40.sparc0.ffu.ffu
    `define TLU_HYPER40       `SPARC_CORE40.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP40           `SPARC_CORE40.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH40        `SPARC_CORE40.sparc0.ifu.ifu.itlb
`else
    `define TLPATH40          `SPARC_CORE40.sparc0.tlu.tcl
    `define TS0PATH40         `SPARC_CORE40.sparc0.tlu.tsa0
    `define TS1PATH40         `SPARC_CORE40.sparc0.tlu.tsa1
    `define INTPATH40         `SPARC_CORE40.sparc0.tlu.intdp
    `define ASIPATH40         `SPARC_CORE40.sparc0.lsu.dctl
    `define ASIDPPATH40       `SPARC_CORE40.sparc0.lsu.dctldp
    `define ICTPATH40         `SPARC_CORE40.sparc0.ifu.ict
    `define DCACHE40          `SPARC_CORE40.sparc0.lsu.dcache
    `define INSTPATH40        `SPARC_CORE40.sparc0.ifu.fcl
    `define PCPATH40          `SPARC_CORE40.sparc0.ifu
    `define DVLD40            `SPARC_CORE40.sparc0.lsu.dva
    `define DTAG40            `SPARC_CORE40.sparc0.lsu.dtag
    `define SDTAG40           `SPARC_CORE40.sparc0.lsu.dtag
    `define SDVLD40           `SPARC_CORE40.sparc0.lsu.dva
    `define FFUPATH40         `SPARC_CORE40.sparc0.ffu
    `define TLU_HYPER40       `SPARC_CORE40.sparc0.tlu.tlu_hyperv
    `define IFQDP40           `SPARC_CORE40.sparc0.ifu.ifqdp
    `define ITLBPATH40        `SPARC_CORE40.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH40    `SPARC_CORE40.sparc0.cfg_asi

    `define PITON_CORE40_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc40_inst_done
`ifdef RTL_SPARC40
    `define PITON_CORE40_PC_W40     `PCPATH40.fdp.pc_w
`else
    `define PITON_CORE40_PC_W40     `TOP_MOD.monitor.pc_cmp.spc40_phy_pc_w
`endif

    

    `define TILE41            `CHIP.tile41
    `define ARIANE_CORE41     `TILE41.g_ariane_core.core.ariane
    `define SPARC_CORE41      `TILE41.g_sparc_core.core
    `define PICO_CORE41       `TILE41.g_picorv32_core.core
    `define CCX_TRANSDUCER41  `TILE41.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER41 `TILE41.g_picorv32_core.pico_l15_transducer
    `define L15_TOP41         `TILE41.l15.l15
    `define L15_PIPE41        `TILE41.l15.l15.pipeline
    `define DMBR41            `TILE41.dmbr_ins
    `define L2_TOP41          `TILE41.l2
    `define SPARC_REG41       `SPARC_CORE41.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH41       `SPARC_CORE41.sparc0.ffu.ffu
`else
    `define FLOATPATH41       `SPARC_CORE41.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH41         `SPARC_CORE41.sparc0.tlu.tlu
    `define DTLBPATH41        `SPARC_CORE41.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH41         `SPARC_CORE41.sparc0.tlu
    `define DTLBPATH41        `SPARC_CORE41.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH41         `SPARC_CORE41.sparc0
`ifndef RTL_SPU
    `define ICVPATH41         `SPARC_CORE41.sparc0.ifu.ifu.icv
    `define IFUPATH41         `SPARC_CORE41.sparc0.ifu.ifu
    `define TNUM41S           `SPARC_CORE41.sparc0.ifu.ifu.swl
    `define TPC41S            `SPARC_CORE41.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH41         `SPARC_CORE41.sparc0.ifu.icv
    `define IFUPATH41         `SPARC_CORE41.sparc0.ifu
    `define TNUM41S           `SPARC_CORE41.sparc0.ifu.swl
    `define TPC41S            `SPARC_CORE41.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH41         `SPARC_CORE41.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH41         `SPARC_CORE41.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH41         `SPARC_CORE41.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH41         `SPARC_CORE41.sparc0.ifu.fdp
`endif
    `define ALUPATH41         `SPARC_CORE41.sparc0.exu.exu.alu
    `define SPCPATH41         `SPARC_CORE41.sparc0
    `define REGPATH41         `SPARC_CORE41.sparc0.exu.exu.irf.irf
    `define CCRPATH41         `SPARC_CORE41.sparc0.exu.exu.ecl.ccr
    `define EXUPATH41         `SPARC_CORE41.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH41          `SPARC_CORE41.sparc0.tlu.tlu.tcl
    `define TS0PATH41         `SPARC_CORE41.sparc0.tlu.tlu.tsa0
    `define TS1PATH41         `SPARC_CORE41.sparc0.tlu.tlu.tsa1
    `define INTPATH41         `SPARC_CORE41.sparc0.tlu.tlu.intdp
    `define ASIPATH41         `SPARC_CORE41.sparc0.lsu.lsu.dctl
    `define ASIDPPATH41       `SPARC_CORE41.sparc0.lsu.lsu.dctldp
    `define ICTPATH41         `SPARC_CORE41.sparc0.ifu.ifu.ict
    `define DCACHE41          `SPARC_CORE41.sparc0.lsu.lsu.dcache
    `define INSTPATH41        `SPARC_CORE41.sparc0.ifu.ifu.fcl
    `define PCPATH41          `SPARC_CORE41.sparc0.ifu.ifu
    `define DVLD41            `SPARC_CORE41.sparc0.lsu.lsu.dva
    `define DTAG41            `SPARC_CORE41.sparc0.lsu.lsu.dtag
    `define SDTAG41           `SPARC_CORE41.sparc0.lsu.lsu.dtag
    `define SDVLD41           `SPARC_CORE41.sparc0.lsu.lsu.dva
    `define FFUPATH41         `SPARC_CORE41.sparc0.ffu.ffu
    `define TLU_HYPER41       `SPARC_CORE41.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP41           `SPARC_CORE41.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH41        `SPARC_CORE41.sparc0.ifu.ifu.itlb
`else
    `define TLPATH41          `SPARC_CORE41.sparc0.tlu.tcl
    `define TS0PATH41         `SPARC_CORE41.sparc0.tlu.tsa0
    `define TS1PATH41         `SPARC_CORE41.sparc0.tlu.tsa1
    `define INTPATH41         `SPARC_CORE41.sparc0.tlu.intdp
    `define ASIPATH41         `SPARC_CORE41.sparc0.lsu.dctl
    `define ASIDPPATH41       `SPARC_CORE41.sparc0.lsu.dctldp
    `define ICTPATH41         `SPARC_CORE41.sparc0.ifu.ict
    `define DCACHE41          `SPARC_CORE41.sparc0.lsu.dcache
    `define INSTPATH41        `SPARC_CORE41.sparc0.ifu.fcl
    `define PCPATH41          `SPARC_CORE41.sparc0.ifu
    `define DVLD41            `SPARC_CORE41.sparc0.lsu.dva
    `define DTAG41            `SPARC_CORE41.sparc0.lsu.dtag
    `define SDTAG41           `SPARC_CORE41.sparc0.lsu.dtag
    `define SDVLD41           `SPARC_CORE41.sparc0.lsu.dva
    `define FFUPATH41         `SPARC_CORE41.sparc0.ffu
    `define TLU_HYPER41       `SPARC_CORE41.sparc0.tlu.tlu_hyperv
    `define IFQDP41           `SPARC_CORE41.sparc0.ifu.ifqdp
    `define ITLBPATH41        `SPARC_CORE41.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH41    `SPARC_CORE41.sparc0.cfg_asi

    `define PITON_CORE41_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc41_inst_done
`ifdef RTL_SPARC41
    `define PITON_CORE41_PC_W41     `PCPATH41.fdp.pc_w
`else
    `define PITON_CORE41_PC_W41     `TOP_MOD.monitor.pc_cmp.spc41_phy_pc_w
`endif

    

    `define TILE42            `CHIP.tile42
    `define ARIANE_CORE42     `TILE42.g_ariane_core.core.ariane
    `define SPARC_CORE42      `TILE42.g_sparc_core.core
    `define PICO_CORE42       `TILE42.g_picorv32_core.core
    `define CCX_TRANSDUCER42  `TILE42.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER42 `TILE42.g_picorv32_core.pico_l15_transducer
    `define L15_TOP42         `TILE42.l15.l15
    `define L15_PIPE42        `TILE42.l15.l15.pipeline
    `define DMBR42            `TILE42.dmbr_ins
    `define L2_TOP42          `TILE42.l2
    `define SPARC_REG42       `SPARC_CORE42.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH42       `SPARC_CORE42.sparc0.ffu.ffu
`else
    `define FLOATPATH42       `SPARC_CORE42.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH42         `SPARC_CORE42.sparc0.tlu.tlu
    `define DTLBPATH42        `SPARC_CORE42.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH42         `SPARC_CORE42.sparc0.tlu
    `define DTLBPATH42        `SPARC_CORE42.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH42         `SPARC_CORE42.sparc0
`ifndef RTL_SPU
    `define ICVPATH42         `SPARC_CORE42.sparc0.ifu.ifu.icv
    `define IFUPATH42         `SPARC_CORE42.sparc0.ifu.ifu
    `define TNUM42S           `SPARC_CORE42.sparc0.ifu.ifu.swl
    `define TPC42S            `SPARC_CORE42.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH42         `SPARC_CORE42.sparc0.ifu.icv
    `define IFUPATH42         `SPARC_CORE42.sparc0.ifu
    `define TNUM42S           `SPARC_CORE42.sparc0.ifu.swl
    `define TPC42S            `SPARC_CORE42.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH42         `SPARC_CORE42.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH42         `SPARC_CORE42.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH42         `SPARC_CORE42.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH42         `SPARC_CORE42.sparc0.ifu.fdp
`endif
    `define ALUPATH42         `SPARC_CORE42.sparc0.exu.exu.alu
    `define SPCPATH42         `SPARC_CORE42.sparc0
    `define REGPATH42         `SPARC_CORE42.sparc0.exu.exu.irf.irf
    `define CCRPATH42         `SPARC_CORE42.sparc0.exu.exu.ecl.ccr
    `define EXUPATH42         `SPARC_CORE42.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH42          `SPARC_CORE42.sparc0.tlu.tlu.tcl
    `define TS0PATH42         `SPARC_CORE42.sparc0.tlu.tlu.tsa0
    `define TS1PATH42         `SPARC_CORE42.sparc0.tlu.tlu.tsa1
    `define INTPATH42         `SPARC_CORE42.sparc0.tlu.tlu.intdp
    `define ASIPATH42         `SPARC_CORE42.sparc0.lsu.lsu.dctl
    `define ASIDPPATH42       `SPARC_CORE42.sparc0.lsu.lsu.dctldp
    `define ICTPATH42         `SPARC_CORE42.sparc0.ifu.ifu.ict
    `define DCACHE42          `SPARC_CORE42.sparc0.lsu.lsu.dcache
    `define INSTPATH42        `SPARC_CORE42.sparc0.ifu.ifu.fcl
    `define PCPATH42          `SPARC_CORE42.sparc0.ifu.ifu
    `define DVLD42            `SPARC_CORE42.sparc0.lsu.lsu.dva
    `define DTAG42            `SPARC_CORE42.sparc0.lsu.lsu.dtag
    `define SDTAG42           `SPARC_CORE42.sparc0.lsu.lsu.dtag
    `define SDVLD42           `SPARC_CORE42.sparc0.lsu.lsu.dva
    `define FFUPATH42         `SPARC_CORE42.sparc0.ffu.ffu
    `define TLU_HYPER42       `SPARC_CORE42.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP42           `SPARC_CORE42.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH42        `SPARC_CORE42.sparc0.ifu.ifu.itlb
`else
    `define TLPATH42          `SPARC_CORE42.sparc0.tlu.tcl
    `define TS0PATH42         `SPARC_CORE42.sparc0.tlu.tsa0
    `define TS1PATH42         `SPARC_CORE42.sparc0.tlu.tsa1
    `define INTPATH42         `SPARC_CORE42.sparc0.tlu.intdp
    `define ASIPATH42         `SPARC_CORE42.sparc0.lsu.dctl
    `define ASIDPPATH42       `SPARC_CORE42.sparc0.lsu.dctldp
    `define ICTPATH42         `SPARC_CORE42.sparc0.ifu.ict
    `define DCACHE42          `SPARC_CORE42.sparc0.lsu.dcache
    `define INSTPATH42        `SPARC_CORE42.sparc0.ifu.fcl
    `define PCPATH42          `SPARC_CORE42.sparc0.ifu
    `define DVLD42            `SPARC_CORE42.sparc0.lsu.dva
    `define DTAG42            `SPARC_CORE42.sparc0.lsu.dtag
    `define SDTAG42           `SPARC_CORE42.sparc0.lsu.dtag
    `define SDVLD42           `SPARC_CORE42.sparc0.lsu.dva
    `define FFUPATH42         `SPARC_CORE42.sparc0.ffu
    `define TLU_HYPER42       `SPARC_CORE42.sparc0.tlu.tlu_hyperv
    `define IFQDP42           `SPARC_CORE42.sparc0.ifu.ifqdp
    `define ITLBPATH42        `SPARC_CORE42.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH42    `SPARC_CORE42.sparc0.cfg_asi

    `define PITON_CORE42_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc42_inst_done
`ifdef RTL_SPARC42
    `define PITON_CORE42_PC_W42     `PCPATH42.fdp.pc_w
`else
    `define PITON_CORE42_PC_W42     `TOP_MOD.monitor.pc_cmp.spc42_phy_pc_w
`endif

    

    `define TILE43            `CHIP.tile43
    `define ARIANE_CORE43     `TILE43.g_ariane_core.core.ariane
    `define SPARC_CORE43      `TILE43.g_sparc_core.core
    `define PICO_CORE43       `TILE43.g_picorv32_core.core
    `define CCX_TRANSDUCER43  `TILE43.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER43 `TILE43.g_picorv32_core.pico_l15_transducer
    `define L15_TOP43         `TILE43.l15.l15
    `define L15_PIPE43        `TILE43.l15.l15.pipeline
    `define DMBR43            `TILE43.dmbr_ins
    `define L2_TOP43          `TILE43.l2
    `define SPARC_REG43       `SPARC_CORE43.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH43       `SPARC_CORE43.sparc0.ffu.ffu
`else
    `define FLOATPATH43       `SPARC_CORE43.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH43         `SPARC_CORE43.sparc0.tlu.tlu
    `define DTLBPATH43        `SPARC_CORE43.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH43         `SPARC_CORE43.sparc0.tlu
    `define DTLBPATH43        `SPARC_CORE43.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH43         `SPARC_CORE43.sparc0
`ifndef RTL_SPU
    `define ICVPATH43         `SPARC_CORE43.sparc0.ifu.ifu.icv
    `define IFUPATH43         `SPARC_CORE43.sparc0.ifu.ifu
    `define TNUM43S           `SPARC_CORE43.sparc0.ifu.ifu.swl
    `define TPC43S            `SPARC_CORE43.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH43         `SPARC_CORE43.sparc0.ifu.icv
    `define IFUPATH43         `SPARC_CORE43.sparc0.ifu
    `define TNUM43S           `SPARC_CORE43.sparc0.ifu.swl
    `define TPC43S            `SPARC_CORE43.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH43         `SPARC_CORE43.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH43         `SPARC_CORE43.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH43         `SPARC_CORE43.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH43         `SPARC_CORE43.sparc0.ifu.fdp
`endif
    `define ALUPATH43         `SPARC_CORE43.sparc0.exu.exu.alu
    `define SPCPATH43         `SPARC_CORE43.sparc0
    `define REGPATH43         `SPARC_CORE43.sparc0.exu.exu.irf.irf
    `define CCRPATH43         `SPARC_CORE43.sparc0.exu.exu.ecl.ccr
    `define EXUPATH43         `SPARC_CORE43.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH43          `SPARC_CORE43.sparc0.tlu.tlu.tcl
    `define TS0PATH43         `SPARC_CORE43.sparc0.tlu.tlu.tsa0
    `define TS1PATH43         `SPARC_CORE43.sparc0.tlu.tlu.tsa1
    `define INTPATH43         `SPARC_CORE43.sparc0.tlu.tlu.intdp
    `define ASIPATH43         `SPARC_CORE43.sparc0.lsu.lsu.dctl
    `define ASIDPPATH43       `SPARC_CORE43.sparc0.lsu.lsu.dctldp
    `define ICTPATH43         `SPARC_CORE43.sparc0.ifu.ifu.ict
    `define DCACHE43          `SPARC_CORE43.sparc0.lsu.lsu.dcache
    `define INSTPATH43        `SPARC_CORE43.sparc0.ifu.ifu.fcl
    `define PCPATH43          `SPARC_CORE43.sparc0.ifu.ifu
    `define DVLD43            `SPARC_CORE43.sparc0.lsu.lsu.dva
    `define DTAG43            `SPARC_CORE43.sparc0.lsu.lsu.dtag
    `define SDTAG43           `SPARC_CORE43.sparc0.lsu.lsu.dtag
    `define SDVLD43           `SPARC_CORE43.sparc0.lsu.lsu.dva
    `define FFUPATH43         `SPARC_CORE43.sparc0.ffu.ffu
    `define TLU_HYPER43       `SPARC_CORE43.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP43           `SPARC_CORE43.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH43        `SPARC_CORE43.sparc0.ifu.ifu.itlb
`else
    `define TLPATH43          `SPARC_CORE43.sparc0.tlu.tcl
    `define TS0PATH43         `SPARC_CORE43.sparc0.tlu.tsa0
    `define TS1PATH43         `SPARC_CORE43.sparc0.tlu.tsa1
    `define INTPATH43         `SPARC_CORE43.sparc0.tlu.intdp
    `define ASIPATH43         `SPARC_CORE43.sparc0.lsu.dctl
    `define ASIDPPATH43       `SPARC_CORE43.sparc0.lsu.dctldp
    `define ICTPATH43         `SPARC_CORE43.sparc0.ifu.ict
    `define DCACHE43          `SPARC_CORE43.sparc0.lsu.dcache
    `define INSTPATH43        `SPARC_CORE43.sparc0.ifu.fcl
    `define PCPATH43          `SPARC_CORE43.sparc0.ifu
    `define DVLD43            `SPARC_CORE43.sparc0.lsu.dva
    `define DTAG43            `SPARC_CORE43.sparc0.lsu.dtag
    `define SDTAG43           `SPARC_CORE43.sparc0.lsu.dtag
    `define SDVLD43           `SPARC_CORE43.sparc0.lsu.dva
    `define FFUPATH43         `SPARC_CORE43.sparc0.ffu
    `define TLU_HYPER43       `SPARC_CORE43.sparc0.tlu.tlu_hyperv
    `define IFQDP43           `SPARC_CORE43.sparc0.ifu.ifqdp
    `define ITLBPATH43        `SPARC_CORE43.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH43    `SPARC_CORE43.sparc0.cfg_asi

    `define PITON_CORE43_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc43_inst_done
`ifdef RTL_SPARC43
    `define PITON_CORE43_PC_W43     `PCPATH43.fdp.pc_w
`else
    `define PITON_CORE43_PC_W43     `TOP_MOD.monitor.pc_cmp.spc43_phy_pc_w
`endif

    

    `define TILE44            `CHIP.tile44
    `define ARIANE_CORE44     `TILE44.g_ariane_core.core.ariane
    `define SPARC_CORE44      `TILE44.g_sparc_core.core
    `define PICO_CORE44       `TILE44.g_picorv32_core.core
    `define CCX_TRANSDUCER44  `TILE44.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER44 `TILE44.g_picorv32_core.pico_l15_transducer
    `define L15_TOP44         `TILE44.l15.l15
    `define L15_PIPE44        `TILE44.l15.l15.pipeline
    `define DMBR44            `TILE44.dmbr_ins
    `define L2_TOP44          `TILE44.l2
    `define SPARC_REG44       `SPARC_CORE44.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH44       `SPARC_CORE44.sparc0.ffu.ffu
`else
    `define FLOATPATH44       `SPARC_CORE44.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH44         `SPARC_CORE44.sparc0.tlu.tlu
    `define DTLBPATH44        `SPARC_CORE44.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH44         `SPARC_CORE44.sparc0.tlu
    `define DTLBPATH44        `SPARC_CORE44.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH44         `SPARC_CORE44.sparc0
`ifndef RTL_SPU
    `define ICVPATH44         `SPARC_CORE44.sparc0.ifu.ifu.icv
    `define IFUPATH44         `SPARC_CORE44.sparc0.ifu.ifu
    `define TNUM44S           `SPARC_CORE44.sparc0.ifu.ifu.swl
    `define TPC44S            `SPARC_CORE44.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH44         `SPARC_CORE44.sparc0.ifu.icv
    `define IFUPATH44         `SPARC_CORE44.sparc0.ifu
    `define TNUM44S           `SPARC_CORE44.sparc0.ifu.swl
    `define TPC44S            `SPARC_CORE44.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH44         `SPARC_CORE44.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH44         `SPARC_CORE44.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH44         `SPARC_CORE44.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH44         `SPARC_CORE44.sparc0.ifu.fdp
`endif
    `define ALUPATH44         `SPARC_CORE44.sparc0.exu.exu.alu
    `define SPCPATH44         `SPARC_CORE44.sparc0
    `define REGPATH44         `SPARC_CORE44.sparc0.exu.exu.irf.irf
    `define CCRPATH44         `SPARC_CORE44.sparc0.exu.exu.ecl.ccr
    `define EXUPATH44         `SPARC_CORE44.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH44          `SPARC_CORE44.sparc0.tlu.tlu.tcl
    `define TS0PATH44         `SPARC_CORE44.sparc0.tlu.tlu.tsa0
    `define TS1PATH44         `SPARC_CORE44.sparc0.tlu.tlu.tsa1
    `define INTPATH44         `SPARC_CORE44.sparc0.tlu.tlu.intdp
    `define ASIPATH44         `SPARC_CORE44.sparc0.lsu.lsu.dctl
    `define ASIDPPATH44       `SPARC_CORE44.sparc0.lsu.lsu.dctldp
    `define ICTPATH44         `SPARC_CORE44.sparc0.ifu.ifu.ict
    `define DCACHE44          `SPARC_CORE44.sparc0.lsu.lsu.dcache
    `define INSTPATH44        `SPARC_CORE44.sparc0.ifu.ifu.fcl
    `define PCPATH44          `SPARC_CORE44.sparc0.ifu.ifu
    `define DVLD44            `SPARC_CORE44.sparc0.lsu.lsu.dva
    `define DTAG44            `SPARC_CORE44.sparc0.lsu.lsu.dtag
    `define SDTAG44           `SPARC_CORE44.sparc0.lsu.lsu.dtag
    `define SDVLD44           `SPARC_CORE44.sparc0.lsu.lsu.dva
    `define FFUPATH44         `SPARC_CORE44.sparc0.ffu.ffu
    `define TLU_HYPER44       `SPARC_CORE44.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP44           `SPARC_CORE44.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH44        `SPARC_CORE44.sparc0.ifu.ifu.itlb
`else
    `define TLPATH44          `SPARC_CORE44.sparc0.tlu.tcl
    `define TS0PATH44         `SPARC_CORE44.sparc0.tlu.tsa0
    `define TS1PATH44         `SPARC_CORE44.sparc0.tlu.tsa1
    `define INTPATH44         `SPARC_CORE44.sparc0.tlu.intdp
    `define ASIPATH44         `SPARC_CORE44.sparc0.lsu.dctl
    `define ASIDPPATH44       `SPARC_CORE44.sparc0.lsu.dctldp
    `define ICTPATH44         `SPARC_CORE44.sparc0.ifu.ict
    `define DCACHE44          `SPARC_CORE44.sparc0.lsu.dcache
    `define INSTPATH44        `SPARC_CORE44.sparc0.ifu.fcl
    `define PCPATH44          `SPARC_CORE44.sparc0.ifu
    `define DVLD44            `SPARC_CORE44.sparc0.lsu.dva
    `define DTAG44            `SPARC_CORE44.sparc0.lsu.dtag
    `define SDTAG44           `SPARC_CORE44.sparc0.lsu.dtag
    `define SDVLD44           `SPARC_CORE44.sparc0.lsu.dva
    `define FFUPATH44         `SPARC_CORE44.sparc0.ffu
    `define TLU_HYPER44       `SPARC_CORE44.sparc0.tlu.tlu_hyperv
    `define IFQDP44           `SPARC_CORE44.sparc0.ifu.ifqdp
    `define ITLBPATH44        `SPARC_CORE44.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH44    `SPARC_CORE44.sparc0.cfg_asi

    `define PITON_CORE44_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc44_inst_done
`ifdef RTL_SPARC44
    `define PITON_CORE44_PC_W44     `PCPATH44.fdp.pc_w
`else
    `define PITON_CORE44_PC_W44     `TOP_MOD.monitor.pc_cmp.spc44_phy_pc_w
`endif

    

    `define TILE45            `CHIP.tile45
    `define ARIANE_CORE45     `TILE45.g_ariane_core.core.ariane
    `define SPARC_CORE45      `TILE45.g_sparc_core.core
    `define PICO_CORE45       `TILE45.g_picorv32_core.core
    `define CCX_TRANSDUCER45  `TILE45.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER45 `TILE45.g_picorv32_core.pico_l15_transducer
    `define L15_TOP45         `TILE45.l15.l15
    `define L15_PIPE45        `TILE45.l15.l15.pipeline
    `define DMBR45            `TILE45.dmbr_ins
    `define L2_TOP45          `TILE45.l2
    `define SPARC_REG45       `SPARC_CORE45.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH45       `SPARC_CORE45.sparc0.ffu.ffu
`else
    `define FLOATPATH45       `SPARC_CORE45.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH45         `SPARC_CORE45.sparc0.tlu.tlu
    `define DTLBPATH45        `SPARC_CORE45.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH45         `SPARC_CORE45.sparc0.tlu
    `define DTLBPATH45        `SPARC_CORE45.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH45         `SPARC_CORE45.sparc0
`ifndef RTL_SPU
    `define ICVPATH45         `SPARC_CORE45.sparc0.ifu.ifu.icv
    `define IFUPATH45         `SPARC_CORE45.sparc0.ifu.ifu
    `define TNUM45S           `SPARC_CORE45.sparc0.ifu.ifu.swl
    `define TPC45S            `SPARC_CORE45.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH45         `SPARC_CORE45.sparc0.ifu.icv
    `define IFUPATH45         `SPARC_CORE45.sparc0.ifu
    `define TNUM45S           `SPARC_CORE45.sparc0.ifu.swl
    `define TPC45S            `SPARC_CORE45.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH45         `SPARC_CORE45.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH45         `SPARC_CORE45.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH45         `SPARC_CORE45.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH45         `SPARC_CORE45.sparc0.ifu.fdp
`endif
    `define ALUPATH45         `SPARC_CORE45.sparc0.exu.exu.alu
    `define SPCPATH45         `SPARC_CORE45.sparc0
    `define REGPATH45         `SPARC_CORE45.sparc0.exu.exu.irf.irf
    `define CCRPATH45         `SPARC_CORE45.sparc0.exu.exu.ecl.ccr
    `define EXUPATH45         `SPARC_CORE45.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH45          `SPARC_CORE45.sparc0.tlu.tlu.tcl
    `define TS0PATH45         `SPARC_CORE45.sparc0.tlu.tlu.tsa0
    `define TS1PATH45         `SPARC_CORE45.sparc0.tlu.tlu.tsa1
    `define INTPATH45         `SPARC_CORE45.sparc0.tlu.tlu.intdp
    `define ASIPATH45         `SPARC_CORE45.sparc0.lsu.lsu.dctl
    `define ASIDPPATH45       `SPARC_CORE45.sparc0.lsu.lsu.dctldp
    `define ICTPATH45         `SPARC_CORE45.sparc0.ifu.ifu.ict
    `define DCACHE45          `SPARC_CORE45.sparc0.lsu.lsu.dcache
    `define INSTPATH45        `SPARC_CORE45.sparc0.ifu.ifu.fcl
    `define PCPATH45          `SPARC_CORE45.sparc0.ifu.ifu
    `define DVLD45            `SPARC_CORE45.sparc0.lsu.lsu.dva
    `define DTAG45            `SPARC_CORE45.sparc0.lsu.lsu.dtag
    `define SDTAG45           `SPARC_CORE45.sparc0.lsu.lsu.dtag
    `define SDVLD45           `SPARC_CORE45.sparc0.lsu.lsu.dva
    `define FFUPATH45         `SPARC_CORE45.sparc0.ffu.ffu
    `define TLU_HYPER45       `SPARC_CORE45.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP45           `SPARC_CORE45.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH45        `SPARC_CORE45.sparc0.ifu.ifu.itlb
`else
    `define TLPATH45          `SPARC_CORE45.sparc0.tlu.tcl
    `define TS0PATH45         `SPARC_CORE45.sparc0.tlu.tsa0
    `define TS1PATH45         `SPARC_CORE45.sparc0.tlu.tsa1
    `define INTPATH45         `SPARC_CORE45.sparc0.tlu.intdp
    `define ASIPATH45         `SPARC_CORE45.sparc0.lsu.dctl
    `define ASIDPPATH45       `SPARC_CORE45.sparc0.lsu.dctldp
    `define ICTPATH45         `SPARC_CORE45.sparc0.ifu.ict
    `define DCACHE45          `SPARC_CORE45.sparc0.lsu.dcache
    `define INSTPATH45        `SPARC_CORE45.sparc0.ifu.fcl
    `define PCPATH45          `SPARC_CORE45.sparc0.ifu
    `define DVLD45            `SPARC_CORE45.sparc0.lsu.dva
    `define DTAG45            `SPARC_CORE45.sparc0.lsu.dtag
    `define SDTAG45           `SPARC_CORE45.sparc0.lsu.dtag
    `define SDVLD45           `SPARC_CORE45.sparc0.lsu.dva
    `define FFUPATH45         `SPARC_CORE45.sparc0.ffu
    `define TLU_HYPER45       `SPARC_CORE45.sparc0.tlu.tlu_hyperv
    `define IFQDP45           `SPARC_CORE45.sparc0.ifu.ifqdp
    `define ITLBPATH45        `SPARC_CORE45.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH45    `SPARC_CORE45.sparc0.cfg_asi

    `define PITON_CORE45_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc45_inst_done
`ifdef RTL_SPARC45
    `define PITON_CORE45_PC_W45     `PCPATH45.fdp.pc_w
`else
    `define PITON_CORE45_PC_W45     `TOP_MOD.monitor.pc_cmp.spc45_phy_pc_w
`endif

    

    `define TILE46            `CHIP.tile46
    `define ARIANE_CORE46     `TILE46.g_ariane_core.core.ariane
    `define SPARC_CORE46      `TILE46.g_sparc_core.core
    `define PICO_CORE46       `TILE46.g_picorv32_core.core
    `define CCX_TRANSDUCER46  `TILE46.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER46 `TILE46.g_picorv32_core.pico_l15_transducer
    `define L15_TOP46         `TILE46.l15.l15
    `define L15_PIPE46        `TILE46.l15.l15.pipeline
    `define DMBR46            `TILE46.dmbr_ins
    `define L2_TOP46          `TILE46.l2
    `define SPARC_REG46       `SPARC_CORE46.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH46       `SPARC_CORE46.sparc0.ffu.ffu
`else
    `define FLOATPATH46       `SPARC_CORE46.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH46         `SPARC_CORE46.sparc0.tlu.tlu
    `define DTLBPATH46        `SPARC_CORE46.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH46         `SPARC_CORE46.sparc0.tlu
    `define DTLBPATH46        `SPARC_CORE46.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH46         `SPARC_CORE46.sparc0
`ifndef RTL_SPU
    `define ICVPATH46         `SPARC_CORE46.sparc0.ifu.ifu.icv
    `define IFUPATH46         `SPARC_CORE46.sparc0.ifu.ifu
    `define TNUM46S           `SPARC_CORE46.sparc0.ifu.ifu.swl
    `define TPC46S            `SPARC_CORE46.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH46         `SPARC_CORE46.sparc0.ifu.icv
    `define IFUPATH46         `SPARC_CORE46.sparc0.ifu
    `define TNUM46S           `SPARC_CORE46.sparc0.ifu.swl
    `define TPC46S            `SPARC_CORE46.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH46         `SPARC_CORE46.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH46         `SPARC_CORE46.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH46         `SPARC_CORE46.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH46         `SPARC_CORE46.sparc0.ifu.fdp
`endif
    `define ALUPATH46         `SPARC_CORE46.sparc0.exu.exu.alu
    `define SPCPATH46         `SPARC_CORE46.sparc0
    `define REGPATH46         `SPARC_CORE46.sparc0.exu.exu.irf.irf
    `define CCRPATH46         `SPARC_CORE46.sparc0.exu.exu.ecl.ccr
    `define EXUPATH46         `SPARC_CORE46.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH46          `SPARC_CORE46.sparc0.tlu.tlu.tcl
    `define TS0PATH46         `SPARC_CORE46.sparc0.tlu.tlu.tsa0
    `define TS1PATH46         `SPARC_CORE46.sparc0.tlu.tlu.tsa1
    `define INTPATH46         `SPARC_CORE46.sparc0.tlu.tlu.intdp
    `define ASIPATH46         `SPARC_CORE46.sparc0.lsu.lsu.dctl
    `define ASIDPPATH46       `SPARC_CORE46.sparc0.lsu.lsu.dctldp
    `define ICTPATH46         `SPARC_CORE46.sparc0.ifu.ifu.ict
    `define DCACHE46          `SPARC_CORE46.sparc0.lsu.lsu.dcache
    `define INSTPATH46        `SPARC_CORE46.sparc0.ifu.ifu.fcl
    `define PCPATH46          `SPARC_CORE46.sparc0.ifu.ifu
    `define DVLD46            `SPARC_CORE46.sparc0.lsu.lsu.dva
    `define DTAG46            `SPARC_CORE46.sparc0.lsu.lsu.dtag
    `define SDTAG46           `SPARC_CORE46.sparc0.lsu.lsu.dtag
    `define SDVLD46           `SPARC_CORE46.sparc0.lsu.lsu.dva
    `define FFUPATH46         `SPARC_CORE46.sparc0.ffu.ffu
    `define TLU_HYPER46       `SPARC_CORE46.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP46           `SPARC_CORE46.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH46        `SPARC_CORE46.sparc0.ifu.ifu.itlb
`else
    `define TLPATH46          `SPARC_CORE46.sparc0.tlu.tcl
    `define TS0PATH46         `SPARC_CORE46.sparc0.tlu.tsa0
    `define TS1PATH46         `SPARC_CORE46.sparc0.tlu.tsa1
    `define INTPATH46         `SPARC_CORE46.sparc0.tlu.intdp
    `define ASIPATH46         `SPARC_CORE46.sparc0.lsu.dctl
    `define ASIDPPATH46       `SPARC_CORE46.sparc0.lsu.dctldp
    `define ICTPATH46         `SPARC_CORE46.sparc0.ifu.ict
    `define DCACHE46          `SPARC_CORE46.sparc0.lsu.dcache
    `define INSTPATH46        `SPARC_CORE46.sparc0.ifu.fcl
    `define PCPATH46          `SPARC_CORE46.sparc0.ifu
    `define DVLD46            `SPARC_CORE46.sparc0.lsu.dva
    `define DTAG46            `SPARC_CORE46.sparc0.lsu.dtag
    `define SDTAG46           `SPARC_CORE46.sparc0.lsu.dtag
    `define SDVLD46           `SPARC_CORE46.sparc0.lsu.dva
    `define FFUPATH46         `SPARC_CORE46.sparc0.ffu
    `define TLU_HYPER46       `SPARC_CORE46.sparc0.tlu.tlu_hyperv
    `define IFQDP46           `SPARC_CORE46.sparc0.ifu.ifqdp
    `define ITLBPATH46        `SPARC_CORE46.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH46    `SPARC_CORE46.sparc0.cfg_asi

    `define PITON_CORE46_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc46_inst_done
`ifdef RTL_SPARC46
    `define PITON_CORE46_PC_W46     `PCPATH46.fdp.pc_w
`else
    `define PITON_CORE46_PC_W46     `TOP_MOD.monitor.pc_cmp.spc46_phy_pc_w
`endif

    

    `define TILE47            `CHIP.tile47
    `define ARIANE_CORE47     `TILE47.g_ariane_core.core.ariane
    `define SPARC_CORE47      `TILE47.g_sparc_core.core
    `define PICO_CORE47       `TILE47.g_picorv32_core.core
    `define CCX_TRANSDUCER47  `TILE47.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER47 `TILE47.g_picorv32_core.pico_l15_transducer
    `define L15_TOP47         `TILE47.l15.l15
    `define L15_PIPE47        `TILE47.l15.l15.pipeline
    `define DMBR47            `TILE47.dmbr_ins
    `define L2_TOP47          `TILE47.l2
    `define SPARC_REG47       `SPARC_CORE47.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH47       `SPARC_CORE47.sparc0.ffu.ffu
`else
    `define FLOATPATH47       `SPARC_CORE47.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH47         `SPARC_CORE47.sparc0.tlu.tlu
    `define DTLBPATH47        `SPARC_CORE47.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH47         `SPARC_CORE47.sparc0.tlu
    `define DTLBPATH47        `SPARC_CORE47.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH47         `SPARC_CORE47.sparc0
`ifndef RTL_SPU
    `define ICVPATH47         `SPARC_CORE47.sparc0.ifu.ifu.icv
    `define IFUPATH47         `SPARC_CORE47.sparc0.ifu.ifu
    `define TNUM47S           `SPARC_CORE47.sparc0.ifu.ifu.swl
    `define TPC47S            `SPARC_CORE47.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH47         `SPARC_CORE47.sparc0.ifu.icv
    `define IFUPATH47         `SPARC_CORE47.sparc0.ifu
    `define TNUM47S           `SPARC_CORE47.sparc0.ifu.swl
    `define TPC47S            `SPARC_CORE47.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH47         `SPARC_CORE47.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH47         `SPARC_CORE47.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH47         `SPARC_CORE47.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH47         `SPARC_CORE47.sparc0.ifu.fdp
`endif
    `define ALUPATH47         `SPARC_CORE47.sparc0.exu.exu.alu
    `define SPCPATH47         `SPARC_CORE47.sparc0
    `define REGPATH47         `SPARC_CORE47.sparc0.exu.exu.irf.irf
    `define CCRPATH47         `SPARC_CORE47.sparc0.exu.exu.ecl.ccr
    `define EXUPATH47         `SPARC_CORE47.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH47          `SPARC_CORE47.sparc0.tlu.tlu.tcl
    `define TS0PATH47         `SPARC_CORE47.sparc0.tlu.tlu.tsa0
    `define TS1PATH47         `SPARC_CORE47.sparc0.tlu.tlu.tsa1
    `define INTPATH47         `SPARC_CORE47.sparc0.tlu.tlu.intdp
    `define ASIPATH47         `SPARC_CORE47.sparc0.lsu.lsu.dctl
    `define ASIDPPATH47       `SPARC_CORE47.sparc0.lsu.lsu.dctldp
    `define ICTPATH47         `SPARC_CORE47.sparc0.ifu.ifu.ict
    `define DCACHE47          `SPARC_CORE47.sparc0.lsu.lsu.dcache
    `define INSTPATH47        `SPARC_CORE47.sparc0.ifu.ifu.fcl
    `define PCPATH47          `SPARC_CORE47.sparc0.ifu.ifu
    `define DVLD47            `SPARC_CORE47.sparc0.lsu.lsu.dva
    `define DTAG47            `SPARC_CORE47.sparc0.lsu.lsu.dtag
    `define SDTAG47           `SPARC_CORE47.sparc0.lsu.lsu.dtag
    `define SDVLD47           `SPARC_CORE47.sparc0.lsu.lsu.dva
    `define FFUPATH47         `SPARC_CORE47.sparc0.ffu.ffu
    `define TLU_HYPER47       `SPARC_CORE47.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP47           `SPARC_CORE47.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH47        `SPARC_CORE47.sparc0.ifu.ifu.itlb
`else
    `define TLPATH47          `SPARC_CORE47.sparc0.tlu.tcl
    `define TS0PATH47         `SPARC_CORE47.sparc0.tlu.tsa0
    `define TS1PATH47         `SPARC_CORE47.sparc0.tlu.tsa1
    `define INTPATH47         `SPARC_CORE47.sparc0.tlu.intdp
    `define ASIPATH47         `SPARC_CORE47.sparc0.lsu.dctl
    `define ASIDPPATH47       `SPARC_CORE47.sparc0.lsu.dctldp
    `define ICTPATH47         `SPARC_CORE47.sparc0.ifu.ict
    `define DCACHE47          `SPARC_CORE47.sparc0.lsu.dcache
    `define INSTPATH47        `SPARC_CORE47.sparc0.ifu.fcl
    `define PCPATH47          `SPARC_CORE47.sparc0.ifu
    `define DVLD47            `SPARC_CORE47.sparc0.lsu.dva
    `define DTAG47            `SPARC_CORE47.sparc0.lsu.dtag
    `define SDTAG47           `SPARC_CORE47.sparc0.lsu.dtag
    `define SDVLD47           `SPARC_CORE47.sparc0.lsu.dva
    `define FFUPATH47         `SPARC_CORE47.sparc0.ffu
    `define TLU_HYPER47       `SPARC_CORE47.sparc0.tlu.tlu_hyperv
    `define IFQDP47           `SPARC_CORE47.sparc0.ifu.ifqdp
    `define ITLBPATH47        `SPARC_CORE47.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH47    `SPARC_CORE47.sparc0.cfg_asi

    `define PITON_CORE47_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc47_inst_done
`ifdef RTL_SPARC47
    `define PITON_CORE47_PC_W47     `PCPATH47.fdp.pc_w
`else
    `define PITON_CORE47_PC_W47     `TOP_MOD.monitor.pc_cmp.spc47_phy_pc_w
`endif

    

    `define TILE48            `CHIP.tile48
    `define ARIANE_CORE48     `TILE48.g_ariane_core.core.ariane
    `define SPARC_CORE48      `TILE48.g_sparc_core.core
    `define PICO_CORE48       `TILE48.g_picorv32_core.core
    `define CCX_TRANSDUCER48  `TILE48.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER48 `TILE48.g_picorv32_core.pico_l15_transducer
    `define L15_TOP48         `TILE48.l15.l15
    `define L15_PIPE48        `TILE48.l15.l15.pipeline
    `define DMBR48            `TILE48.dmbr_ins
    `define L2_TOP48          `TILE48.l2
    `define SPARC_REG48       `SPARC_CORE48.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH48       `SPARC_CORE48.sparc0.ffu.ffu
`else
    `define FLOATPATH48       `SPARC_CORE48.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH48         `SPARC_CORE48.sparc0.tlu.tlu
    `define DTLBPATH48        `SPARC_CORE48.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH48         `SPARC_CORE48.sparc0.tlu
    `define DTLBPATH48        `SPARC_CORE48.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH48         `SPARC_CORE48.sparc0
`ifndef RTL_SPU
    `define ICVPATH48         `SPARC_CORE48.sparc0.ifu.ifu.icv
    `define IFUPATH48         `SPARC_CORE48.sparc0.ifu.ifu
    `define TNUM48S           `SPARC_CORE48.sparc0.ifu.ifu.swl
    `define TPC48S            `SPARC_CORE48.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH48         `SPARC_CORE48.sparc0.ifu.icv
    `define IFUPATH48         `SPARC_CORE48.sparc0.ifu
    `define TNUM48S           `SPARC_CORE48.sparc0.ifu.swl
    `define TPC48S            `SPARC_CORE48.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH48         `SPARC_CORE48.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH48         `SPARC_CORE48.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH48         `SPARC_CORE48.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH48         `SPARC_CORE48.sparc0.ifu.fdp
`endif
    `define ALUPATH48         `SPARC_CORE48.sparc0.exu.exu.alu
    `define SPCPATH48         `SPARC_CORE48.sparc0
    `define REGPATH48         `SPARC_CORE48.sparc0.exu.exu.irf.irf
    `define CCRPATH48         `SPARC_CORE48.sparc0.exu.exu.ecl.ccr
    `define EXUPATH48         `SPARC_CORE48.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH48          `SPARC_CORE48.sparc0.tlu.tlu.tcl
    `define TS0PATH48         `SPARC_CORE48.sparc0.tlu.tlu.tsa0
    `define TS1PATH48         `SPARC_CORE48.sparc0.tlu.tlu.tsa1
    `define INTPATH48         `SPARC_CORE48.sparc0.tlu.tlu.intdp
    `define ASIPATH48         `SPARC_CORE48.sparc0.lsu.lsu.dctl
    `define ASIDPPATH48       `SPARC_CORE48.sparc0.lsu.lsu.dctldp
    `define ICTPATH48         `SPARC_CORE48.sparc0.ifu.ifu.ict
    `define DCACHE48          `SPARC_CORE48.sparc0.lsu.lsu.dcache
    `define INSTPATH48        `SPARC_CORE48.sparc0.ifu.ifu.fcl
    `define PCPATH48          `SPARC_CORE48.sparc0.ifu.ifu
    `define DVLD48            `SPARC_CORE48.sparc0.lsu.lsu.dva
    `define DTAG48            `SPARC_CORE48.sparc0.lsu.lsu.dtag
    `define SDTAG48           `SPARC_CORE48.sparc0.lsu.lsu.dtag
    `define SDVLD48           `SPARC_CORE48.sparc0.lsu.lsu.dva
    `define FFUPATH48         `SPARC_CORE48.sparc0.ffu.ffu
    `define TLU_HYPER48       `SPARC_CORE48.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP48           `SPARC_CORE48.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH48        `SPARC_CORE48.sparc0.ifu.ifu.itlb
`else
    `define TLPATH48          `SPARC_CORE48.sparc0.tlu.tcl
    `define TS0PATH48         `SPARC_CORE48.sparc0.tlu.tsa0
    `define TS1PATH48         `SPARC_CORE48.sparc0.tlu.tsa1
    `define INTPATH48         `SPARC_CORE48.sparc0.tlu.intdp
    `define ASIPATH48         `SPARC_CORE48.sparc0.lsu.dctl
    `define ASIDPPATH48       `SPARC_CORE48.sparc0.lsu.dctldp
    `define ICTPATH48         `SPARC_CORE48.sparc0.ifu.ict
    `define DCACHE48          `SPARC_CORE48.sparc0.lsu.dcache
    `define INSTPATH48        `SPARC_CORE48.sparc0.ifu.fcl
    `define PCPATH48          `SPARC_CORE48.sparc0.ifu
    `define DVLD48            `SPARC_CORE48.sparc0.lsu.dva
    `define DTAG48            `SPARC_CORE48.sparc0.lsu.dtag
    `define SDTAG48           `SPARC_CORE48.sparc0.lsu.dtag
    `define SDVLD48           `SPARC_CORE48.sparc0.lsu.dva
    `define FFUPATH48         `SPARC_CORE48.sparc0.ffu
    `define TLU_HYPER48       `SPARC_CORE48.sparc0.tlu.tlu_hyperv
    `define IFQDP48           `SPARC_CORE48.sparc0.ifu.ifqdp
    `define ITLBPATH48        `SPARC_CORE48.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH48    `SPARC_CORE48.sparc0.cfg_asi

    `define PITON_CORE48_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc48_inst_done
`ifdef RTL_SPARC48
    `define PITON_CORE48_PC_W48     `PCPATH48.fdp.pc_w
`else
    `define PITON_CORE48_PC_W48     `TOP_MOD.monitor.pc_cmp.spc48_phy_pc_w
`endif

    

    `define TILE49            `CHIP.tile49
    `define ARIANE_CORE49     `TILE49.g_ariane_core.core.ariane
    `define SPARC_CORE49      `TILE49.g_sparc_core.core
    `define PICO_CORE49       `TILE49.g_picorv32_core.core
    `define CCX_TRANSDUCER49  `TILE49.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER49 `TILE49.g_picorv32_core.pico_l15_transducer
    `define L15_TOP49         `TILE49.l15.l15
    `define L15_PIPE49        `TILE49.l15.l15.pipeline
    `define DMBR49            `TILE49.dmbr_ins
    `define L2_TOP49          `TILE49.l2
    `define SPARC_REG49       `SPARC_CORE49.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH49       `SPARC_CORE49.sparc0.ffu.ffu
`else
    `define FLOATPATH49       `SPARC_CORE49.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH49         `SPARC_CORE49.sparc0.tlu.tlu
    `define DTLBPATH49        `SPARC_CORE49.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH49         `SPARC_CORE49.sparc0.tlu
    `define DTLBPATH49        `SPARC_CORE49.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH49         `SPARC_CORE49.sparc0
`ifndef RTL_SPU
    `define ICVPATH49         `SPARC_CORE49.sparc0.ifu.ifu.icv
    `define IFUPATH49         `SPARC_CORE49.sparc0.ifu.ifu
    `define TNUM49S           `SPARC_CORE49.sparc0.ifu.ifu.swl
    `define TPC49S            `SPARC_CORE49.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH49         `SPARC_CORE49.sparc0.ifu.icv
    `define IFUPATH49         `SPARC_CORE49.sparc0.ifu
    `define TNUM49S           `SPARC_CORE49.sparc0.ifu.swl
    `define TPC49S            `SPARC_CORE49.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH49         `SPARC_CORE49.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH49         `SPARC_CORE49.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH49         `SPARC_CORE49.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH49         `SPARC_CORE49.sparc0.ifu.fdp
`endif
    `define ALUPATH49         `SPARC_CORE49.sparc0.exu.exu.alu
    `define SPCPATH49         `SPARC_CORE49.sparc0
    `define REGPATH49         `SPARC_CORE49.sparc0.exu.exu.irf.irf
    `define CCRPATH49         `SPARC_CORE49.sparc0.exu.exu.ecl.ccr
    `define EXUPATH49         `SPARC_CORE49.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH49          `SPARC_CORE49.sparc0.tlu.tlu.tcl
    `define TS0PATH49         `SPARC_CORE49.sparc0.tlu.tlu.tsa0
    `define TS1PATH49         `SPARC_CORE49.sparc0.tlu.tlu.tsa1
    `define INTPATH49         `SPARC_CORE49.sparc0.tlu.tlu.intdp
    `define ASIPATH49         `SPARC_CORE49.sparc0.lsu.lsu.dctl
    `define ASIDPPATH49       `SPARC_CORE49.sparc0.lsu.lsu.dctldp
    `define ICTPATH49         `SPARC_CORE49.sparc0.ifu.ifu.ict
    `define DCACHE49          `SPARC_CORE49.sparc0.lsu.lsu.dcache
    `define INSTPATH49        `SPARC_CORE49.sparc0.ifu.ifu.fcl
    `define PCPATH49          `SPARC_CORE49.sparc0.ifu.ifu
    `define DVLD49            `SPARC_CORE49.sparc0.lsu.lsu.dva
    `define DTAG49            `SPARC_CORE49.sparc0.lsu.lsu.dtag
    `define SDTAG49           `SPARC_CORE49.sparc0.lsu.lsu.dtag
    `define SDVLD49           `SPARC_CORE49.sparc0.lsu.lsu.dva
    `define FFUPATH49         `SPARC_CORE49.sparc0.ffu.ffu
    `define TLU_HYPER49       `SPARC_CORE49.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP49           `SPARC_CORE49.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH49        `SPARC_CORE49.sparc0.ifu.ifu.itlb
`else
    `define TLPATH49          `SPARC_CORE49.sparc0.tlu.tcl
    `define TS0PATH49         `SPARC_CORE49.sparc0.tlu.tsa0
    `define TS1PATH49         `SPARC_CORE49.sparc0.tlu.tsa1
    `define INTPATH49         `SPARC_CORE49.sparc0.tlu.intdp
    `define ASIPATH49         `SPARC_CORE49.sparc0.lsu.dctl
    `define ASIDPPATH49       `SPARC_CORE49.sparc0.lsu.dctldp
    `define ICTPATH49         `SPARC_CORE49.sparc0.ifu.ict
    `define DCACHE49          `SPARC_CORE49.sparc0.lsu.dcache
    `define INSTPATH49        `SPARC_CORE49.sparc0.ifu.fcl
    `define PCPATH49          `SPARC_CORE49.sparc0.ifu
    `define DVLD49            `SPARC_CORE49.sparc0.lsu.dva
    `define DTAG49            `SPARC_CORE49.sparc0.lsu.dtag
    `define SDTAG49           `SPARC_CORE49.sparc0.lsu.dtag
    `define SDVLD49           `SPARC_CORE49.sparc0.lsu.dva
    `define FFUPATH49         `SPARC_CORE49.sparc0.ffu
    `define TLU_HYPER49       `SPARC_CORE49.sparc0.tlu.tlu_hyperv
    `define IFQDP49           `SPARC_CORE49.sparc0.ifu.ifqdp
    `define ITLBPATH49        `SPARC_CORE49.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH49    `SPARC_CORE49.sparc0.cfg_asi

    `define PITON_CORE49_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc49_inst_done
`ifdef RTL_SPARC49
    `define PITON_CORE49_PC_W49     `PCPATH49.fdp.pc_w
`else
    `define PITON_CORE49_PC_W49     `TOP_MOD.monitor.pc_cmp.spc49_phy_pc_w
`endif

    

    `define TILE50            `CHIP.tile50
    `define ARIANE_CORE50     `TILE50.g_ariane_core.core.ariane
    `define SPARC_CORE50      `TILE50.g_sparc_core.core
    `define PICO_CORE50       `TILE50.g_picorv32_core.core
    `define CCX_TRANSDUCER50  `TILE50.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER50 `TILE50.g_picorv32_core.pico_l15_transducer
    `define L15_TOP50         `TILE50.l15.l15
    `define L15_PIPE50        `TILE50.l15.l15.pipeline
    `define DMBR50            `TILE50.dmbr_ins
    `define L2_TOP50          `TILE50.l2
    `define SPARC_REG50       `SPARC_CORE50.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH50       `SPARC_CORE50.sparc0.ffu.ffu
`else
    `define FLOATPATH50       `SPARC_CORE50.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH50         `SPARC_CORE50.sparc0.tlu.tlu
    `define DTLBPATH50        `SPARC_CORE50.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH50         `SPARC_CORE50.sparc0.tlu
    `define DTLBPATH50        `SPARC_CORE50.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH50         `SPARC_CORE50.sparc0
`ifndef RTL_SPU
    `define ICVPATH50         `SPARC_CORE50.sparc0.ifu.ifu.icv
    `define IFUPATH50         `SPARC_CORE50.sparc0.ifu.ifu
    `define TNUM50S           `SPARC_CORE50.sparc0.ifu.ifu.swl
    `define TPC50S            `SPARC_CORE50.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH50         `SPARC_CORE50.sparc0.ifu.icv
    `define IFUPATH50         `SPARC_CORE50.sparc0.ifu
    `define TNUM50S           `SPARC_CORE50.sparc0.ifu.swl
    `define TPC50S            `SPARC_CORE50.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH50         `SPARC_CORE50.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH50         `SPARC_CORE50.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH50         `SPARC_CORE50.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH50         `SPARC_CORE50.sparc0.ifu.fdp
`endif
    `define ALUPATH50         `SPARC_CORE50.sparc0.exu.exu.alu
    `define SPCPATH50         `SPARC_CORE50.sparc0
    `define REGPATH50         `SPARC_CORE50.sparc0.exu.exu.irf.irf
    `define CCRPATH50         `SPARC_CORE50.sparc0.exu.exu.ecl.ccr
    `define EXUPATH50         `SPARC_CORE50.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH50          `SPARC_CORE50.sparc0.tlu.tlu.tcl
    `define TS0PATH50         `SPARC_CORE50.sparc0.tlu.tlu.tsa0
    `define TS1PATH50         `SPARC_CORE50.sparc0.tlu.tlu.tsa1
    `define INTPATH50         `SPARC_CORE50.sparc0.tlu.tlu.intdp
    `define ASIPATH50         `SPARC_CORE50.sparc0.lsu.lsu.dctl
    `define ASIDPPATH50       `SPARC_CORE50.sparc0.lsu.lsu.dctldp
    `define ICTPATH50         `SPARC_CORE50.sparc0.ifu.ifu.ict
    `define DCACHE50          `SPARC_CORE50.sparc0.lsu.lsu.dcache
    `define INSTPATH50        `SPARC_CORE50.sparc0.ifu.ifu.fcl
    `define PCPATH50          `SPARC_CORE50.sparc0.ifu.ifu
    `define DVLD50            `SPARC_CORE50.sparc0.lsu.lsu.dva
    `define DTAG50            `SPARC_CORE50.sparc0.lsu.lsu.dtag
    `define SDTAG50           `SPARC_CORE50.sparc0.lsu.lsu.dtag
    `define SDVLD50           `SPARC_CORE50.sparc0.lsu.lsu.dva
    `define FFUPATH50         `SPARC_CORE50.sparc0.ffu.ffu
    `define TLU_HYPER50       `SPARC_CORE50.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP50           `SPARC_CORE50.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH50        `SPARC_CORE50.sparc0.ifu.ifu.itlb
`else
    `define TLPATH50          `SPARC_CORE50.sparc0.tlu.tcl
    `define TS0PATH50         `SPARC_CORE50.sparc0.tlu.tsa0
    `define TS1PATH50         `SPARC_CORE50.sparc0.tlu.tsa1
    `define INTPATH50         `SPARC_CORE50.sparc0.tlu.intdp
    `define ASIPATH50         `SPARC_CORE50.sparc0.lsu.dctl
    `define ASIDPPATH50       `SPARC_CORE50.sparc0.lsu.dctldp
    `define ICTPATH50         `SPARC_CORE50.sparc0.ifu.ict
    `define DCACHE50          `SPARC_CORE50.sparc0.lsu.dcache
    `define INSTPATH50        `SPARC_CORE50.sparc0.ifu.fcl
    `define PCPATH50          `SPARC_CORE50.sparc0.ifu
    `define DVLD50            `SPARC_CORE50.sparc0.lsu.dva
    `define DTAG50            `SPARC_CORE50.sparc0.lsu.dtag
    `define SDTAG50           `SPARC_CORE50.sparc0.lsu.dtag
    `define SDVLD50           `SPARC_CORE50.sparc0.lsu.dva
    `define FFUPATH50         `SPARC_CORE50.sparc0.ffu
    `define TLU_HYPER50       `SPARC_CORE50.sparc0.tlu.tlu_hyperv
    `define IFQDP50           `SPARC_CORE50.sparc0.ifu.ifqdp
    `define ITLBPATH50        `SPARC_CORE50.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH50    `SPARC_CORE50.sparc0.cfg_asi

    `define PITON_CORE50_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc50_inst_done
`ifdef RTL_SPARC50
    `define PITON_CORE50_PC_W50     `PCPATH50.fdp.pc_w
`else
    `define PITON_CORE50_PC_W50     `TOP_MOD.monitor.pc_cmp.spc50_phy_pc_w
`endif

    

    `define TILE51            `CHIP.tile51
    `define ARIANE_CORE51     `TILE51.g_ariane_core.core.ariane
    `define SPARC_CORE51      `TILE51.g_sparc_core.core
    `define PICO_CORE51       `TILE51.g_picorv32_core.core
    `define CCX_TRANSDUCER51  `TILE51.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER51 `TILE51.g_picorv32_core.pico_l15_transducer
    `define L15_TOP51         `TILE51.l15.l15
    `define L15_PIPE51        `TILE51.l15.l15.pipeline
    `define DMBR51            `TILE51.dmbr_ins
    `define L2_TOP51          `TILE51.l2
    `define SPARC_REG51       `SPARC_CORE51.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH51       `SPARC_CORE51.sparc0.ffu.ffu
`else
    `define FLOATPATH51       `SPARC_CORE51.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH51         `SPARC_CORE51.sparc0.tlu.tlu
    `define DTLBPATH51        `SPARC_CORE51.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH51         `SPARC_CORE51.sparc0.tlu
    `define DTLBPATH51        `SPARC_CORE51.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH51         `SPARC_CORE51.sparc0
`ifndef RTL_SPU
    `define ICVPATH51         `SPARC_CORE51.sparc0.ifu.ifu.icv
    `define IFUPATH51         `SPARC_CORE51.sparc0.ifu.ifu
    `define TNUM51S           `SPARC_CORE51.sparc0.ifu.ifu.swl
    `define TPC51S            `SPARC_CORE51.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH51         `SPARC_CORE51.sparc0.ifu.icv
    `define IFUPATH51         `SPARC_CORE51.sparc0.ifu
    `define TNUM51S           `SPARC_CORE51.sparc0.ifu.swl
    `define TPC51S            `SPARC_CORE51.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH51         `SPARC_CORE51.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH51         `SPARC_CORE51.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH51         `SPARC_CORE51.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH51         `SPARC_CORE51.sparc0.ifu.fdp
`endif
    `define ALUPATH51         `SPARC_CORE51.sparc0.exu.exu.alu
    `define SPCPATH51         `SPARC_CORE51.sparc0
    `define REGPATH51         `SPARC_CORE51.sparc0.exu.exu.irf.irf
    `define CCRPATH51         `SPARC_CORE51.sparc0.exu.exu.ecl.ccr
    `define EXUPATH51         `SPARC_CORE51.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH51          `SPARC_CORE51.sparc0.tlu.tlu.tcl
    `define TS0PATH51         `SPARC_CORE51.sparc0.tlu.tlu.tsa0
    `define TS1PATH51         `SPARC_CORE51.sparc0.tlu.tlu.tsa1
    `define INTPATH51         `SPARC_CORE51.sparc0.tlu.tlu.intdp
    `define ASIPATH51         `SPARC_CORE51.sparc0.lsu.lsu.dctl
    `define ASIDPPATH51       `SPARC_CORE51.sparc0.lsu.lsu.dctldp
    `define ICTPATH51         `SPARC_CORE51.sparc0.ifu.ifu.ict
    `define DCACHE51          `SPARC_CORE51.sparc0.lsu.lsu.dcache
    `define INSTPATH51        `SPARC_CORE51.sparc0.ifu.ifu.fcl
    `define PCPATH51          `SPARC_CORE51.sparc0.ifu.ifu
    `define DVLD51            `SPARC_CORE51.sparc0.lsu.lsu.dva
    `define DTAG51            `SPARC_CORE51.sparc0.lsu.lsu.dtag
    `define SDTAG51           `SPARC_CORE51.sparc0.lsu.lsu.dtag
    `define SDVLD51           `SPARC_CORE51.sparc0.lsu.lsu.dva
    `define FFUPATH51         `SPARC_CORE51.sparc0.ffu.ffu
    `define TLU_HYPER51       `SPARC_CORE51.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP51           `SPARC_CORE51.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH51        `SPARC_CORE51.sparc0.ifu.ifu.itlb
`else
    `define TLPATH51          `SPARC_CORE51.sparc0.tlu.tcl
    `define TS0PATH51         `SPARC_CORE51.sparc0.tlu.tsa0
    `define TS1PATH51         `SPARC_CORE51.sparc0.tlu.tsa1
    `define INTPATH51         `SPARC_CORE51.sparc0.tlu.intdp
    `define ASIPATH51         `SPARC_CORE51.sparc0.lsu.dctl
    `define ASIDPPATH51       `SPARC_CORE51.sparc0.lsu.dctldp
    `define ICTPATH51         `SPARC_CORE51.sparc0.ifu.ict
    `define DCACHE51          `SPARC_CORE51.sparc0.lsu.dcache
    `define INSTPATH51        `SPARC_CORE51.sparc0.ifu.fcl
    `define PCPATH51          `SPARC_CORE51.sparc0.ifu
    `define DVLD51            `SPARC_CORE51.sparc0.lsu.dva
    `define DTAG51            `SPARC_CORE51.sparc0.lsu.dtag
    `define SDTAG51           `SPARC_CORE51.sparc0.lsu.dtag
    `define SDVLD51           `SPARC_CORE51.sparc0.lsu.dva
    `define FFUPATH51         `SPARC_CORE51.sparc0.ffu
    `define TLU_HYPER51       `SPARC_CORE51.sparc0.tlu.tlu_hyperv
    `define IFQDP51           `SPARC_CORE51.sparc0.ifu.ifqdp
    `define ITLBPATH51        `SPARC_CORE51.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH51    `SPARC_CORE51.sparc0.cfg_asi

    `define PITON_CORE51_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc51_inst_done
`ifdef RTL_SPARC51
    `define PITON_CORE51_PC_W51     `PCPATH51.fdp.pc_w
`else
    `define PITON_CORE51_PC_W51     `TOP_MOD.monitor.pc_cmp.spc51_phy_pc_w
`endif

    

    `define TILE52            `CHIP.tile52
    `define ARIANE_CORE52     `TILE52.g_ariane_core.core.ariane
    `define SPARC_CORE52      `TILE52.g_sparc_core.core
    `define PICO_CORE52       `TILE52.g_picorv32_core.core
    `define CCX_TRANSDUCER52  `TILE52.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER52 `TILE52.g_picorv32_core.pico_l15_transducer
    `define L15_TOP52         `TILE52.l15.l15
    `define L15_PIPE52        `TILE52.l15.l15.pipeline
    `define DMBR52            `TILE52.dmbr_ins
    `define L2_TOP52          `TILE52.l2
    `define SPARC_REG52       `SPARC_CORE52.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH52       `SPARC_CORE52.sparc0.ffu.ffu
`else
    `define FLOATPATH52       `SPARC_CORE52.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH52         `SPARC_CORE52.sparc0.tlu.tlu
    `define DTLBPATH52        `SPARC_CORE52.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH52         `SPARC_CORE52.sparc0.tlu
    `define DTLBPATH52        `SPARC_CORE52.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH52         `SPARC_CORE52.sparc0
`ifndef RTL_SPU
    `define ICVPATH52         `SPARC_CORE52.sparc0.ifu.ifu.icv
    `define IFUPATH52         `SPARC_CORE52.sparc0.ifu.ifu
    `define TNUM52S           `SPARC_CORE52.sparc0.ifu.ifu.swl
    `define TPC52S            `SPARC_CORE52.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH52         `SPARC_CORE52.sparc0.ifu.icv
    `define IFUPATH52         `SPARC_CORE52.sparc0.ifu
    `define TNUM52S           `SPARC_CORE52.sparc0.ifu.swl
    `define TPC52S            `SPARC_CORE52.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH52         `SPARC_CORE52.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH52         `SPARC_CORE52.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH52         `SPARC_CORE52.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH52         `SPARC_CORE52.sparc0.ifu.fdp
`endif
    `define ALUPATH52         `SPARC_CORE52.sparc0.exu.exu.alu
    `define SPCPATH52         `SPARC_CORE52.sparc0
    `define REGPATH52         `SPARC_CORE52.sparc0.exu.exu.irf.irf
    `define CCRPATH52         `SPARC_CORE52.sparc0.exu.exu.ecl.ccr
    `define EXUPATH52         `SPARC_CORE52.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH52          `SPARC_CORE52.sparc0.tlu.tlu.tcl
    `define TS0PATH52         `SPARC_CORE52.sparc0.tlu.tlu.tsa0
    `define TS1PATH52         `SPARC_CORE52.sparc0.tlu.tlu.tsa1
    `define INTPATH52         `SPARC_CORE52.sparc0.tlu.tlu.intdp
    `define ASIPATH52         `SPARC_CORE52.sparc0.lsu.lsu.dctl
    `define ASIDPPATH52       `SPARC_CORE52.sparc0.lsu.lsu.dctldp
    `define ICTPATH52         `SPARC_CORE52.sparc0.ifu.ifu.ict
    `define DCACHE52          `SPARC_CORE52.sparc0.lsu.lsu.dcache
    `define INSTPATH52        `SPARC_CORE52.sparc0.ifu.ifu.fcl
    `define PCPATH52          `SPARC_CORE52.sparc0.ifu.ifu
    `define DVLD52            `SPARC_CORE52.sparc0.lsu.lsu.dva
    `define DTAG52            `SPARC_CORE52.sparc0.lsu.lsu.dtag
    `define SDTAG52           `SPARC_CORE52.sparc0.lsu.lsu.dtag
    `define SDVLD52           `SPARC_CORE52.sparc0.lsu.lsu.dva
    `define FFUPATH52         `SPARC_CORE52.sparc0.ffu.ffu
    `define TLU_HYPER52       `SPARC_CORE52.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP52           `SPARC_CORE52.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH52        `SPARC_CORE52.sparc0.ifu.ifu.itlb
`else
    `define TLPATH52          `SPARC_CORE52.sparc0.tlu.tcl
    `define TS0PATH52         `SPARC_CORE52.sparc0.tlu.tsa0
    `define TS1PATH52         `SPARC_CORE52.sparc0.tlu.tsa1
    `define INTPATH52         `SPARC_CORE52.sparc0.tlu.intdp
    `define ASIPATH52         `SPARC_CORE52.sparc0.lsu.dctl
    `define ASIDPPATH52       `SPARC_CORE52.sparc0.lsu.dctldp
    `define ICTPATH52         `SPARC_CORE52.sparc0.ifu.ict
    `define DCACHE52          `SPARC_CORE52.sparc0.lsu.dcache
    `define INSTPATH52        `SPARC_CORE52.sparc0.ifu.fcl
    `define PCPATH52          `SPARC_CORE52.sparc0.ifu
    `define DVLD52            `SPARC_CORE52.sparc0.lsu.dva
    `define DTAG52            `SPARC_CORE52.sparc0.lsu.dtag
    `define SDTAG52           `SPARC_CORE52.sparc0.lsu.dtag
    `define SDVLD52           `SPARC_CORE52.sparc0.lsu.dva
    `define FFUPATH52         `SPARC_CORE52.sparc0.ffu
    `define TLU_HYPER52       `SPARC_CORE52.sparc0.tlu.tlu_hyperv
    `define IFQDP52           `SPARC_CORE52.sparc0.ifu.ifqdp
    `define ITLBPATH52        `SPARC_CORE52.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH52    `SPARC_CORE52.sparc0.cfg_asi

    `define PITON_CORE52_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc52_inst_done
`ifdef RTL_SPARC52
    `define PITON_CORE52_PC_W52     `PCPATH52.fdp.pc_w
`else
    `define PITON_CORE52_PC_W52     `TOP_MOD.monitor.pc_cmp.spc52_phy_pc_w
`endif

    

    `define TILE53            `CHIP.tile53
    `define ARIANE_CORE53     `TILE53.g_ariane_core.core.ariane
    `define SPARC_CORE53      `TILE53.g_sparc_core.core
    `define PICO_CORE53       `TILE53.g_picorv32_core.core
    `define CCX_TRANSDUCER53  `TILE53.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER53 `TILE53.g_picorv32_core.pico_l15_transducer
    `define L15_TOP53         `TILE53.l15.l15
    `define L15_PIPE53        `TILE53.l15.l15.pipeline
    `define DMBR53            `TILE53.dmbr_ins
    `define L2_TOP53          `TILE53.l2
    `define SPARC_REG53       `SPARC_CORE53.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH53       `SPARC_CORE53.sparc0.ffu.ffu
`else
    `define FLOATPATH53       `SPARC_CORE53.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH53         `SPARC_CORE53.sparc0.tlu.tlu
    `define DTLBPATH53        `SPARC_CORE53.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH53         `SPARC_CORE53.sparc0.tlu
    `define DTLBPATH53        `SPARC_CORE53.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH53         `SPARC_CORE53.sparc0
`ifndef RTL_SPU
    `define ICVPATH53         `SPARC_CORE53.sparc0.ifu.ifu.icv
    `define IFUPATH53         `SPARC_CORE53.sparc0.ifu.ifu
    `define TNUM53S           `SPARC_CORE53.sparc0.ifu.ifu.swl
    `define TPC53S            `SPARC_CORE53.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH53         `SPARC_CORE53.sparc0.ifu.icv
    `define IFUPATH53         `SPARC_CORE53.sparc0.ifu
    `define TNUM53S           `SPARC_CORE53.sparc0.ifu.swl
    `define TPC53S            `SPARC_CORE53.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH53         `SPARC_CORE53.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH53         `SPARC_CORE53.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH53         `SPARC_CORE53.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH53         `SPARC_CORE53.sparc0.ifu.fdp
`endif
    `define ALUPATH53         `SPARC_CORE53.sparc0.exu.exu.alu
    `define SPCPATH53         `SPARC_CORE53.sparc0
    `define REGPATH53         `SPARC_CORE53.sparc0.exu.exu.irf.irf
    `define CCRPATH53         `SPARC_CORE53.sparc0.exu.exu.ecl.ccr
    `define EXUPATH53         `SPARC_CORE53.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH53          `SPARC_CORE53.sparc0.tlu.tlu.tcl
    `define TS0PATH53         `SPARC_CORE53.sparc0.tlu.tlu.tsa0
    `define TS1PATH53         `SPARC_CORE53.sparc0.tlu.tlu.tsa1
    `define INTPATH53         `SPARC_CORE53.sparc0.tlu.tlu.intdp
    `define ASIPATH53         `SPARC_CORE53.sparc0.lsu.lsu.dctl
    `define ASIDPPATH53       `SPARC_CORE53.sparc0.lsu.lsu.dctldp
    `define ICTPATH53         `SPARC_CORE53.sparc0.ifu.ifu.ict
    `define DCACHE53          `SPARC_CORE53.sparc0.lsu.lsu.dcache
    `define INSTPATH53        `SPARC_CORE53.sparc0.ifu.ifu.fcl
    `define PCPATH53          `SPARC_CORE53.sparc0.ifu.ifu
    `define DVLD53            `SPARC_CORE53.sparc0.lsu.lsu.dva
    `define DTAG53            `SPARC_CORE53.sparc0.lsu.lsu.dtag
    `define SDTAG53           `SPARC_CORE53.sparc0.lsu.lsu.dtag
    `define SDVLD53           `SPARC_CORE53.sparc0.lsu.lsu.dva
    `define FFUPATH53         `SPARC_CORE53.sparc0.ffu.ffu
    `define TLU_HYPER53       `SPARC_CORE53.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP53           `SPARC_CORE53.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH53        `SPARC_CORE53.sparc0.ifu.ifu.itlb
`else
    `define TLPATH53          `SPARC_CORE53.sparc0.tlu.tcl
    `define TS0PATH53         `SPARC_CORE53.sparc0.tlu.tsa0
    `define TS1PATH53         `SPARC_CORE53.sparc0.tlu.tsa1
    `define INTPATH53         `SPARC_CORE53.sparc0.tlu.intdp
    `define ASIPATH53         `SPARC_CORE53.sparc0.lsu.dctl
    `define ASIDPPATH53       `SPARC_CORE53.sparc0.lsu.dctldp
    `define ICTPATH53         `SPARC_CORE53.sparc0.ifu.ict
    `define DCACHE53          `SPARC_CORE53.sparc0.lsu.dcache
    `define INSTPATH53        `SPARC_CORE53.sparc0.ifu.fcl
    `define PCPATH53          `SPARC_CORE53.sparc0.ifu
    `define DVLD53            `SPARC_CORE53.sparc0.lsu.dva
    `define DTAG53            `SPARC_CORE53.sparc0.lsu.dtag
    `define SDTAG53           `SPARC_CORE53.sparc0.lsu.dtag
    `define SDVLD53           `SPARC_CORE53.sparc0.lsu.dva
    `define FFUPATH53         `SPARC_CORE53.sparc0.ffu
    `define TLU_HYPER53       `SPARC_CORE53.sparc0.tlu.tlu_hyperv
    `define IFQDP53           `SPARC_CORE53.sparc0.ifu.ifqdp
    `define ITLBPATH53        `SPARC_CORE53.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH53    `SPARC_CORE53.sparc0.cfg_asi

    `define PITON_CORE53_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc53_inst_done
`ifdef RTL_SPARC53
    `define PITON_CORE53_PC_W53     `PCPATH53.fdp.pc_w
`else
    `define PITON_CORE53_PC_W53     `TOP_MOD.monitor.pc_cmp.spc53_phy_pc_w
`endif

    

    `define TILE54            `CHIP.tile54
    `define ARIANE_CORE54     `TILE54.g_ariane_core.core.ariane
    `define SPARC_CORE54      `TILE54.g_sparc_core.core
    `define PICO_CORE54       `TILE54.g_picorv32_core.core
    `define CCX_TRANSDUCER54  `TILE54.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER54 `TILE54.g_picorv32_core.pico_l15_transducer
    `define L15_TOP54         `TILE54.l15.l15
    `define L15_PIPE54        `TILE54.l15.l15.pipeline
    `define DMBR54            `TILE54.dmbr_ins
    `define L2_TOP54          `TILE54.l2
    `define SPARC_REG54       `SPARC_CORE54.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH54       `SPARC_CORE54.sparc0.ffu.ffu
`else
    `define FLOATPATH54       `SPARC_CORE54.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH54         `SPARC_CORE54.sparc0.tlu.tlu
    `define DTLBPATH54        `SPARC_CORE54.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH54         `SPARC_CORE54.sparc0.tlu
    `define DTLBPATH54        `SPARC_CORE54.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH54         `SPARC_CORE54.sparc0
`ifndef RTL_SPU
    `define ICVPATH54         `SPARC_CORE54.sparc0.ifu.ifu.icv
    `define IFUPATH54         `SPARC_CORE54.sparc0.ifu.ifu
    `define TNUM54S           `SPARC_CORE54.sparc0.ifu.ifu.swl
    `define TPC54S            `SPARC_CORE54.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH54         `SPARC_CORE54.sparc0.ifu.icv
    `define IFUPATH54         `SPARC_CORE54.sparc0.ifu
    `define TNUM54S           `SPARC_CORE54.sparc0.ifu.swl
    `define TPC54S            `SPARC_CORE54.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH54         `SPARC_CORE54.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH54         `SPARC_CORE54.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH54         `SPARC_CORE54.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH54         `SPARC_CORE54.sparc0.ifu.fdp
`endif
    `define ALUPATH54         `SPARC_CORE54.sparc0.exu.exu.alu
    `define SPCPATH54         `SPARC_CORE54.sparc0
    `define REGPATH54         `SPARC_CORE54.sparc0.exu.exu.irf.irf
    `define CCRPATH54         `SPARC_CORE54.sparc0.exu.exu.ecl.ccr
    `define EXUPATH54         `SPARC_CORE54.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH54          `SPARC_CORE54.sparc0.tlu.tlu.tcl
    `define TS0PATH54         `SPARC_CORE54.sparc0.tlu.tlu.tsa0
    `define TS1PATH54         `SPARC_CORE54.sparc0.tlu.tlu.tsa1
    `define INTPATH54         `SPARC_CORE54.sparc0.tlu.tlu.intdp
    `define ASIPATH54         `SPARC_CORE54.sparc0.lsu.lsu.dctl
    `define ASIDPPATH54       `SPARC_CORE54.sparc0.lsu.lsu.dctldp
    `define ICTPATH54         `SPARC_CORE54.sparc0.ifu.ifu.ict
    `define DCACHE54          `SPARC_CORE54.sparc0.lsu.lsu.dcache
    `define INSTPATH54        `SPARC_CORE54.sparc0.ifu.ifu.fcl
    `define PCPATH54          `SPARC_CORE54.sparc0.ifu.ifu
    `define DVLD54            `SPARC_CORE54.sparc0.lsu.lsu.dva
    `define DTAG54            `SPARC_CORE54.sparc0.lsu.lsu.dtag
    `define SDTAG54           `SPARC_CORE54.sparc0.lsu.lsu.dtag
    `define SDVLD54           `SPARC_CORE54.sparc0.lsu.lsu.dva
    `define FFUPATH54         `SPARC_CORE54.sparc0.ffu.ffu
    `define TLU_HYPER54       `SPARC_CORE54.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP54           `SPARC_CORE54.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH54        `SPARC_CORE54.sparc0.ifu.ifu.itlb
`else
    `define TLPATH54          `SPARC_CORE54.sparc0.tlu.tcl
    `define TS0PATH54         `SPARC_CORE54.sparc0.tlu.tsa0
    `define TS1PATH54         `SPARC_CORE54.sparc0.tlu.tsa1
    `define INTPATH54         `SPARC_CORE54.sparc0.tlu.intdp
    `define ASIPATH54         `SPARC_CORE54.sparc0.lsu.dctl
    `define ASIDPPATH54       `SPARC_CORE54.sparc0.lsu.dctldp
    `define ICTPATH54         `SPARC_CORE54.sparc0.ifu.ict
    `define DCACHE54          `SPARC_CORE54.sparc0.lsu.dcache
    `define INSTPATH54        `SPARC_CORE54.sparc0.ifu.fcl
    `define PCPATH54          `SPARC_CORE54.sparc0.ifu
    `define DVLD54            `SPARC_CORE54.sparc0.lsu.dva
    `define DTAG54            `SPARC_CORE54.sparc0.lsu.dtag
    `define SDTAG54           `SPARC_CORE54.sparc0.lsu.dtag
    `define SDVLD54           `SPARC_CORE54.sparc0.lsu.dva
    `define FFUPATH54         `SPARC_CORE54.sparc0.ffu
    `define TLU_HYPER54       `SPARC_CORE54.sparc0.tlu.tlu_hyperv
    `define IFQDP54           `SPARC_CORE54.sparc0.ifu.ifqdp
    `define ITLBPATH54        `SPARC_CORE54.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH54    `SPARC_CORE54.sparc0.cfg_asi

    `define PITON_CORE54_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc54_inst_done
`ifdef RTL_SPARC54
    `define PITON_CORE54_PC_W54     `PCPATH54.fdp.pc_w
`else
    `define PITON_CORE54_PC_W54     `TOP_MOD.monitor.pc_cmp.spc54_phy_pc_w
`endif

    

    `define TILE55            `CHIP.tile55
    `define ARIANE_CORE55     `TILE55.g_ariane_core.core.ariane
    `define SPARC_CORE55      `TILE55.g_sparc_core.core
    `define PICO_CORE55       `TILE55.g_picorv32_core.core
    `define CCX_TRANSDUCER55  `TILE55.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER55 `TILE55.g_picorv32_core.pico_l15_transducer
    `define L15_TOP55         `TILE55.l15.l15
    `define L15_PIPE55        `TILE55.l15.l15.pipeline
    `define DMBR55            `TILE55.dmbr_ins
    `define L2_TOP55          `TILE55.l2
    `define SPARC_REG55       `SPARC_CORE55.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH55       `SPARC_CORE55.sparc0.ffu.ffu
`else
    `define FLOATPATH55       `SPARC_CORE55.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH55         `SPARC_CORE55.sparc0.tlu.tlu
    `define DTLBPATH55        `SPARC_CORE55.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH55         `SPARC_CORE55.sparc0.tlu
    `define DTLBPATH55        `SPARC_CORE55.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH55         `SPARC_CORE55.sparc0
`ifndef RTL_SPU
    `define ICVPATH55         `SPARC_CORE55.sparc0.ifu.ifu.icv
    `define IFUPATH55         `SPARC_CORE55.sparc0.ifu.ifu
    `define TNUM55S           `SPARC_CORE55.sparc0.ifu.ifu.swl
    `define TPC55S            `SPARC_CORE55.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH55         `SPARC_CORE55.sparc0.ifu.icv
    `define IFUPATH55         `SPARC_CORE55.sparc0.ifu
    `define TNUM55S           `SPARC_CORE55.sparc0.ifu.swl
    `define TPC55S            `SPARC_CORE55.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH55         `SPARC_CORE55.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH55         `SPARC_CORE55.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH55         `SPARC_CORE55.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH55         `SPARC_CORE55.sparc0.ifu.fdp
`endif
    `define ALUPATH55         `SPARC_CORE55.sparc0.exu.exu.alu
    `define SPCPATH55         `SPARC_CORE55.sparc0
    `define REGPATH55         `SPARC_CORE55.sparc0.exu.exu.irf.irf
    `define CCRPATH55         `SPARC_CORE55.sparc0.exu.exu.ecl.ccr
    `define EXUPATH55         `SPARC_CORE55.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH55          `SPARC_CORE55.sparc0.tlu.tlu.tcl
    `define TS0PATH55         `SPARC_CORE55.sparc0.tlu.tlu.tsa0
    `define TS1PATH55         `SPARC_CORE55.sparc0.tlu.tlu.tsa1
    `define INTPATH55         `SPARC_CORE55.sparc0.tlu.tlu.intdp
    `define ASIPATH55         `SPARC_CORE55.sparc0.lsu.lsu.dctl
    `define ASIDPPATH55       `SPARC_CORE55.sparc0.lsu.lsu.dctldp
    `define ICTPATH55         `SPARC_CORE55.sparc0.ifu.ifu.ict
    `define DCACHE55          `SPARC_CORE55.sparc0.lsu.lsu.dcache
    `define INSTPATH55        `SPARC_CORE55.sparc0.ifu.ifu.fcl
    `define PCPATH55          `SPARC_CORE55.sparc0.ifu.ifu
    `define DVLD55            `SPARC_CORE55.sparc0.lsu.lsu.dva
    `define DTAG55            `SPARC_CORE55.sparc0.lsu.lsu.dtag
    `define SDTAG55           `SPARC_CORE55.sparc0.lsu.lsu.dtag
    `define SDVLD55           `SPARC_CORE55.sparc0.lsu.lsu.dva
    `define FFUPATH55         `SPARC_CORE55.sparc0.ffu.ffu
    `define TLU_HYPER55       `SPARC_CORE55.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP55           `SPARC_CORE55.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH55        `SPARC_CORE55.sparc0.ifu.ifu.itlb
`else
    `define TLPATH55          `SPARC_CORE55.sparc0.tlu.tcl
    `define TS0PATH55         `SPARC_CORE55.sparc0.tlu.tsa0
    `define TS1PATH55         `SPARC_CORE55.sparc0.tlu.tsa1
    `define INTPATH55         `SPARC_CORE55.sparc0.tlu.intdp
    `define ASIPATH55         `SPARC_CORE55.sparc0.lsu.dctl
    `define ASIDPPATH55       `SPARC_CORE55.sparc0.lsu.dctldp
    `define ICTPATH55         `SPARC_CORE55.sparc0.ifu.ict
    `define DCACHE55          `SPARC_CORE55.sparc0.lsu.dcache
    `define INSTPATH55        `SPARC_CORE55.sparc0.ifu.fcl
    `define PCPATH55          `SPARC_CORE55.sparc0.ifu
    `define DVLD55            `SPARC_CORE55.sparc0.lsu.dva
    `define DTAG55            `SPARC_CORE55.sparc0.lsu.dtag
    `define SDTAG55           `SPARC_CORE55.sparc0.lsu.dtag
    `define SDVLD55           `SPARC_CORE55.sparc0.lsu.dva
    `define FFUPATH55         `SPARC_CORE55.sparc0.ffu
    `define TLU_HYPER55       `SPARC_CORE55.sparc0.tlu.tlu_hyperv
    `define IFQDP55           `SPARC_CORE55.sparc0.ifu.ifqdp
    `define ITLBPATH55        `SPARC_CORE55.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH55    `SPARC_CORE55.sparc0.cfg_asi

    `define PITON_CORE55_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc55_inst_done
`ifdef RTL_SPARC55
    `define PITON_CORE55_PC_W55     `PCPATH55.fdp.pc_w
`else
    `define PITON_CORE55_PC_W55     `TOP_MOD.monitor.pc_cmp.spc55_phy_pc_w
`endif

    

    `define TILE56            `CHIP.tile56
    `define ARIANE_CORE56     `TILE56.g_ariane_core.core.ariane
    `define SPARC_CORE56      `TILE56.g_sparc_core.core
    `define PICO_CORE56       `TILE56.g_picorv32_core.core
    `define CCX_TRANSDUCER56  `TILE56.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER56 `TILE56.g_picorv32_core.pico_l15_transducer
    `define L15_TOP56         `TILE56.l15.l15
    `define L15_PIPE56        `TILE56.l15.l15.pipeline
    `define DMBR56            `TILE56.dmbr_ins
    `define L2_TOP56          `TILE56.l2
    `define SPARC_REG56       `SPARC_CORE56.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH56       `SPARC_CORE56.sparc0.ffu.ffu
`else
    `define FLOATPATH56       `SPARC_CORE56.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH56         `SPARC_CORE56.sparc0.tlu.tlu
    `define DTLBPATH56        `SPARC_CORE56.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH56         `SPARC_CORE56.sparc0.tlu
    `define DTLBPATH56        `SPARC_CORE56.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH56         `SPARC_CORE56.sparc0
`ifndef RTL_SPU
    `define ICVPATH56         `SPARC_CORE56.sparc0.ifu.ifu.icv
    `define IFUPATH56         `SPARC_CORE56.sparc0.ifu.ifu
    `define TNUM56S           `SPARC_CORE56.sparc0.ifu.ifu.swl
    `define TPC56S            `SPARC_CORE56.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH56         `SPARC_CORE56.sparc0.ifu.icv
    `define IFUPATH56         `SPARC_CORE56.sparc0.ifu
    `define TNUM56S           `SPARC_CORE56.sparc0.ifu.swl
    `define TPC56S            `SPARC_CORE56.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH56         `SPARC_CORE56.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH56         `SPARC_CORE56.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH56         `SPARC_CORE56.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH56         `SPARC_CORE56.sparc0.ifu.fdp
`endif
    `define ALUPATH56         `SPARC_CORE56.sparc0.exu.exu.alu
    `define SPCPATH56         `SPARC_CORE56.sparc0
    `define REGPATH56         `SPARC_CORE56.sparc0.exu.exu.irf.irf
    `define CCRPATH56         `SPARC_CORE56.sparc0.exu.exu.ecl.ccr
    `define EXUPATH56         `SPARC_CORE56.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH56          `SPARC_CORE56.sparc0.tlu.tlu.tcl
    `define TS0PATH56         `SPARC_CORE56.sparc0.tlu.tlu.tsa0
    `define TS1PATH56         `SPARC_CORE56.sparc0.tlu.tlu.tsa1
    `define INTPATH56         `SPARC_CORE56.sparc0.tlu.tlu.intdp
    `define ASIPATH56         `SPARC_CORE56.sparc0.lsu.lsu.dctl
    `define ASIDPPATH56       `SPARC_CORE56.sparc0.lsu.lsu.dctldp
    `define ICTPATH56         `SPARC_CORE56.sparc0.ifu.ifu.ict
    `define DCACHE56          `SPARC_CORE56.sparc0.lsu.lsu.dcache
    `define INSTPATH56        `SPARC_CORE56.sparc0.ifu.ifu.fcl
    `define PCPATH56          `SPARC_CORE56.sparc0.ifu.ifu
    `define DVLD56            `SPARC_CORE56.sparc0.lsu.lsu.dva
    `define DTAG56            `SPARC_CORE56.sparc0.lsu.lsu.dtag
    `define SDTAG56           `SPARC_CORE56.sparc0.lsu.lsu.dtag
    `define SDVLD56           `SPARC_CORE56.sparc0.lsu.lsu.dva
    `define FFUPATH56         `SPARC_CORE56.sparc0.ffu.ffu
    `define TLU_HYPER56       `SPARC_CORE56.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP56           `SPARC_CORE56.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH56        `SPARC_CORE56.sparc0.ifu.ifu.itlb
`else
    `define TLPATH56          `SPARC_CORE56.sparc0.tlu.tcl
    `define TS0PATH56         `SPARC_CORE56.sparc0.tlu.tsa0
    `define TS1PATH56         `SPARC_CORE56.sparc0.tlu.tsa1
    `define INTPATH56         `SPARC_CORE56.sparc0.tlu.intdp
    `define ASIPATH56         `SPARC_CORE56.sparc0.lsu.dctl
    `define ASIDPPATH56       `SPARC_CORE56.sparc0.lsu.dctldp
    `define ICTPATH56         `SPARC_CORE56.sparc0.ifu.ict
    `define DCACHE56          `SPARC_CORE56.sparc0.lsu.dcache
    `define INSTPATH56        `SPARC_CORE56.sparc0.ifu.fcl
    `define PCPATH56          `SPARC_CORE56.sparc0.ifu
    `define DVLD56            `SPARC_CORE56.sparc0.lsu.dva
    `define DTAG56            `SPARC_CORE56.sparc0.lsu.dtag
    `define SDTAG56           `SPARC_CORE56.sparc0.lsu.dtag
    `define SDVLD56           `SPARC_CORE56.sparc0.lsu.dva
    `define FFUPATH56         `SPARC_CORE56.sparc0.ffu
    `define TLU_HYPER56       `SPARC_CORE56.sparc0.tlu.tlu_hyperv
    `define IFQDP56           `SPARC_CORE56.sparc0.ifu.ifqdp
    `define ITLBPATH56        `SPARC_CORE56.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH56    `SPARC_CORE56.sparc0.cfg_asi

    `define PITON_CORE56_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc56_inst_done
`ifdef RTL_SPARC56
    `define PITON_CORE56_PC_W56     `PCPATH56.fdp.pc_w
`else
    `define PITON_CORE56_PC_W56     `TOP_MOD.monitor.pc_cmp.spc56_phy_pc_w
`endif

    

    `define TILE57            `CHIP.tile57
    `define ARIANE_CORE57     `TILE57.g_ariane_core.core.ariane
    `define SPARC_CORE57      `TILE57.g_sparc_core.core
    `define PICO_CORE57       `TILE57.g_picorv32_core.core
    `define CCX_TRANSDUCER57  `TILE57.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER57 `TILE57.g_picorv32_core.pico_l15_transducer
    `define L15_TOP57         `TILE57.l15.l15
    `define L15_PIPE57        `TILE57.l15.l15.pipeline
    `define DMBR57            `TILE57.dmbr_ins
    `define L2_TOP57          `TILE57.l2
    `define SPARC_REG57       `SPARC_CORE57.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH57       `SPARC_CORE57.sparc0.ffu.ffu
`else
    `define FLOATPATH57       `SPARC_CORE57.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH57         `SPARC_CORE57.sparc0.tlu.tlu
    `define DTLBPATH57        `SPARC_CORE57.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH57         `SPARC_CORE57.sparc0.tlu
    `define DTLBPATH57        `SPARC_CORE57.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH57         `SPARC_CORE57.sparc0
`ifndef RTL_SPU
    `define ICVPATH57         `SPARC_CORE57.sparc0.ifu.ifu.icv
    `define IFUPATH57         `SPARC_CORE57.sparc0.ifu.ifu
    `define TNUM57S           `SPARC_CORE57.sparc0.ifu.ifu.swl
    `define TPC57S            `SPARC_CORE57.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH57         `SPARC_CORE57.sparc0.ifu.icv
    `define IFUPATH57         `SPARC_CORE57.sparc0.ifu
    `define TNUM57S           `SPARC_CORE57.sparc0.ifu.swl
    `define TPC57S            `SPARC_CORE57.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH57         `SPARC_CORE57.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH57         `SPARC_CORE57.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH57         `SPARC_CORE57.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH57         `SPARC_CORE57.sparc0.ifu.fdp
`endif
    `define ALUPATH57         `SPARC_CORE57.sparc0.exu.exu.alu
    `define SPCPATH57         `SPARC_CORE57.sparc0
    `define REGPATH57         `SPARC_CORE57.sparc0.exu.exu.irf.irf
    `define CCRPATH57         `SPARC_CORE57.sparc0.exu.exu.ecl.ccr
    `define EXUPATH57         `SPARC_CORE57.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH57          `SPARC_CORE57.sparc0.tlu.tlu.tcl
    `define TS0PATH57         `SPARC_CORE57.sparc0.tlu.tlu.tsa0
    `define TS1PATH57         `SPARC_CORE57.sparc0.tlu.tlu.tsa1
    `define INTPATH57         `SPARC_CORE57.sparc0.tlu.tlu.intdp
    `define ASIPATH57         `SPARC_CORE57.sparc0.lsu.lsu.dctl
    `define ASIDPPATH57       `SPARC_CORE57.sparc0.lsu.lsu.dctldp
    `define ICTPATH57         `SPARC_CORE57.sparc0.ifu.ifu.ict
    `define DCACHE57          `SPARC_CORE57.sparc0.lsu.lsu.dcache
    `define INSTPATH57        `SPARC_CORE57.sparc0.ifu.ifu.fcl
    `define PCPATH57          `SPARC_CORE57.sparc0.ifu.ifu
    `define DVLD57            `SPARC_CORE57.sparc0.lsu.lsu.dva
    `define DTAG57            `SPARC_CORE57.sparc0.lsu.lsu.dtag
    `define SDTAG57           `SPARC_CORE57.sparc0.lsu.lsu.dtag
    `define SDVLD57           `SPARC_CORE57.sparc0.lsu.lsu.dva
    `define FFUPATH57         `SPARC_CORE57.sparc0.ffu.ffu
    `define TLU_HYPER57       `SPARC_CORE57.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP57           `SPARC_CORE57.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH57        `SPARC_CORE57.sparc0.ifu.ifu.itlb
`else
    `define TLPATH57          `SPARC_CORE57.sparc0.tlu.tcl
    `define TS0PATH57         `SPARC_CORE57.sparc0.tlu.tsa0
    `define TS1PATH57         `SPARC_CORE57.sparc0.tlu.tsa1
    `define INTPATH57         `SPARC_CORE57.sparc0.tlu.intdp
    `define ASIPATH57         `SPARC_CORE57.sparc0.lsu.dctl
    `define ASIDPPATH57       `SPARC_CORE57.sparc0.lsu.dctldp
    `define ICTPATH57         `SPARC_CORE57.sparc0.ifu.ict
    `define DCACHE57          `SPARC_CORE57.sparc0.lsu.dcache
    `define INSTPATH57        `SPARC_CORE57.sparc0.ifu.fcl
    `define PCPATH57          `SPARC_CORE57.sparc0.ifu
    `define DVLD57            `SPARC_CORE57.sparc0.lsu.dva
    `define DTAG57            `SPARC_CORE57.sparc0.lsu.dtag
    `define SDTAG57           `SPARC_CORE57.sparc0.lsu.dtag
    `define SDVLD57           `SPARC_CORE57.sparc0.lsu.dva
    `define FFUPATH57         `SPARC_CORE57.sparc0.ffu
    `define TLU_HYPER57       `SPARC_CORE57.sparc0.tlu.tlu_hyperv
    `define IFQDP57           `SPARC_CORE57.sparc0.ifu.ifqdp
    `define ITLBPATH57        `SPARC_CORE57.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH57    `SPARC_CORE57.sparc0.cfg_asi

    `define PITON_CORE57_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc57_inst_done
`ifdef RTL_SPARC57
    `define PITON_CORE57_PC_W57     `PCPATH57.fdp.pc_w
`else
    `define PITON_CORE57_PC_W57     `TOP_MOD.monitor.pc_cmp.spc57_phy_pc_w
`endif

    

    `define TILE58            `CHIP.tile58
    `define ARIANE_CORE58     `TILE58.g_ariane_core.core.ariane
    `define SPARC_CORE58      `TILE58.g_sparc_core.core
    `define PICO_CORE58       `TILE58.g_picorv32_core.core
    `define CCX_TRANSDUCER58  `TILE58.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER58 `TILE58.g_picorv32_core.pico_l15_transducer
    `define L15_TOP58         `TILE58.l15.l15
    `define L15_PIPE58        `TILE58.l15.l15.pipeline
    `define DMBR58            `TILE58.dmbr_ins
    `define L2_TOP58          `TILE58.l2
    `define SPARC_REG58       `SPARC_CORE58.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH58       `SPARC_CORE58.sparc0.ffu.ffu
`else
    `define FLOATPATH58       `SPARC_CORE58.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH58         `SPARC_CORE58.sparc0.tlu.tlu
    `define DTLBPATH58        `SPARC_CORE58.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH58         `SPARC_CORE58.sparc0.tlu
    `define DTLBPATH58        `SPARC_CORE58.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH58         `SPARC_CORE58.sparc0
`ifndef RTL_SPU
    `define ICVPATH58         `SPARC_CORE58.sparc0.ifu.ifu.icv
    `define IFUPATH58         `SPARC_CORE58.sparc0.ifu.ifu
    `define TNUM58S           `SPARC_CORE58.sparc0.ifu.ifu.swl
    `define TPC58S            `SPARC_CORE58.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH58         `SPARC_CORE58.sparc0.ifu.icv
    `define IFUPATH58         `SPARC_CORE58.sparc0.ifu
    `define TNUM58S           `SPARC_CORE58.sparc0.ifu.swl
    `define TPC58S            `SPARC_CORE58.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH58         `SPARC_CORE58.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH58         `SPARC_CORE58.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH58         `SPARC_CORE58.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH58         `SPARC_CORE58.sparc0.ifu.fdp
`endif
    `define ALUPATH58         `SPARC_CORE58.sparc0.exu.exu.alu
    `define SPCPATH58         `SPARC_CORE58.sparc0
    `define REGPATH58         `SPARC_CORE58.sparc0.exu.exu.irf.irf
    `define CCRPATH58         `SPARC_CORE58.sparc0.exu.exu.ecl.ccr
    `define EXUPATH58         `SPARC_CORE58.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH58          `SPARC_CORE58.sparc0.tlu.tlu.tcl
    `define TS0PATH58         `SPARC_CORE58.sparc0.tlu.tlu.tsa0
    `define TS1PATH58         `SPARC_CORE58.sparc0.tlu.tlu.tsa1
    `define INTPATH58         `SPARC_CORE58.sparc0.tlu.tlu.intdp
    `define ASIPATH58         `SPARC_CORE58.sparc0.lsu.lsu.dctl
    `define ASIDPPATH58       `SPARC_CORE58.sparc0.lsu.lsu.dctldp
    `define ICTPATH58         `SPARC_CORE58.sparc0.ifu.ifu.ict
    `define DCACHE58          `SPARC_CORE58.sparc0.lsu.lsu.dcache
    `define INSTPATH58        `SPARC_CORE58.sparc0.ifu.ifu.fcl
    `define PCPATH58          `SPARC_CORE58.sparc0.ifu.ifu
    `define DVLD58            `SPARC_CORE58.sparc0.lsu.lsu.dva
    `define DTAG58            `SPARC_CORE58.sparc0.lsu.lsu.dtag
    `define SDTAG58           `SPARC_CORE58.sparc0.lsu.lsu.dtag
    `define SDVLD58           `SPARC_CORE58.sparc0.lsu.lsu.dva
    `define FFUPATH58         `SPARC_CORE58.sparc0.ffu.ffu
    `define TLU_HYPER58       `SPARC_CORE58.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP58           `SPARC_CORE58.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH58        `SPARC_CORE58.sparc0.ifu.ifu.itlb
`else
    `define TLPATH58          `SPARC_CORE58.sparc0.tlu.tcl
    `define TS0PATH58         `SPARC_CORE58.sparc0.tlu.tsa0
    `define TS1PATH58         `SPARC_CORE58.sparc0.tlu.tsa1
    `define INTPATH58         `SPARC_CORE58.sparc0.tlu.intdp
    `define ASIPATH58         `SPARC_CORE58.sparc0.lsu.dctl
    `define ASIDPPATH58       `SPARC_CORE58.sparc0.lsu.dctldp
    `define ICTPATH58         `SPARC_CORE58.sparc0.ifu.ict
    `define DCACHE58          `SPARC_CORE58.sparc0.lsu.dcache
    `define INSTPATH58        `SPARC_CORE58.sparc0.ifu.fcl
    `define PCPATH58          `SPARC_CORE58.sparc0.ifu
    `define DVLD58            `SPARC_CORE58.sparc0.lsu.dva
    `define DTAG58            `SPARC_CORE58.sparc0.lsu.dtag
    `define SDTAG58           `SPARC_CORE58.sparc0.lsu.dtag
    `define SDVLD58           `SPARC_CORE58.sparc0.lsu.dva
    `define FFUPATH58         `SPARC_CORE58.sparc0.ffu
    `define TLU_HYPER58       `SPARC_CORE58.sparc0.tlu.tlu_hyperv
    `define IFQDP58           `SPARC_CORE58.sparc0.ifu.ifqdp
    `define ITLBPATH58        `SPARC_CORE58.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH58    `SPARC_CORE58.sparc0.cfg_asi

    `define PITON_CORE58_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc58_inst_done
`ifdef RTL_SPARC58
    `define PITON_CORE58_PC_W58     `PCPATH58.fdp.pc_w
`else
    `define PITON_CORE58_PC_W58     `TOP_MOD.monitor.pc_cmp.spc58_phy_pc_w
`endif

    

    `define TILE59            `CHIP.tile59
    `define ARIANE_CORE59     `TILE59.g_ariane_core.core.ariane
    `define SPARC_CORE59      `TILE59.g_sparc_core.core
    `define PICO_CORE59       `TILE59.g_picorv32_core.core
    `define CCX_TRANSDUCER59  `TILE59.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER59 `TILE59.g_picorv32_core.pico_l15_transducer
    `define L15_TOP59         `TILE59.l15.l15
    `define L15_PIPE59        `TILE59.l15.l15.pipeline
    `define DMBR59            `TILE59.dmbr_ins
    `define L2_TOP59          `TILE59.l2
    `define SPARC_REG59       `SPARC_CORE59.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH59       `SPARC_CORE59.sparc0.ffu.ffu
`else
    `define FLOATPATH59       `SPARC_CORE59.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH59         `SPARC_CORE59.sparc0.tlu.tlu
    `define DTLBPATH59        `SPARC_CORE59.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH59         `SPARC_CORE59.sparc0.tlu
    `define DTLBPATH59        `SPARC_CORE59.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH59         `SPARC_CORE59.sparc0
`ifndef RTL_SPU
    `define ICVPATH59         `SPARC_CORE59.sparc0.ifu.ifu.icv
    `define IFUPATH59         `SPARC_CORE59.sparc0.ifu.ifu
    `define TNUM59S           `SPARC_CORE59.sparc0.ifu.ifu.swl
    `define TPC59S            `SPARC_CORE59.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH59         `SPARC_CORE59.sparc0.ifu.icv
    `define IFUPATH59         `SPARC_CORE59.sparc0.ifu
    `define TNUM59S           `SPARC_CORE59.sparc0.ifu.swl
    `define TPC59S            `SPARC_CORE59.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH59         `SPARC_CORE59.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH59         `SPARC_CORE59.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH59         `SPARC_CORE59.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH59         `SPARC_CORE59.sparc0.ifu.fdp
`endif
    `define ALUPATH59         `SPARC_CORE59.sparc0.exu.exu.alu
    `define SPCPATH59         `SPARC_CORE59.sparc0
    `define REGPATH59         `SPARC_CORE59.sparc0.exu.exu.irf.irf
    `define CCRPATH59         `SPARC_CORE59.sparc0.exu.exu.ecl.ccr
    `define EXUPATH59         `SPARC_CORE59.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH59          `SPARC_CORE59.sparc0.tlu.tlu.tcl
    `define TS0PATH59         `SPARC_CORE59.sparc0.tlu.tlu.tsa0
    `define TS1PATH59         `SPARC_CORE59.sparc0.tlu.tlu.tsa1
    `define INTPATH59         `SPARC_CORE59.sparc0.tlu.tlu.intdp
    `define ASIPATH59         `SPARC_CORE59.sparc0.lsu.lsu.dctl
    `define ASIDPPATH59       `SPARC_CORE59.sparc0.lsu.lsu.dctldp
    `define ICTPATH59         `SPARC_CORE59.sparc0.ifu.ifu.ict
    `define DCACHE59          `SPARC_CORE59.sparc0.lsu.lsu.dcache
    `define INSTPATH59        `SPARC_CORE59.sparc0.ifu.ifu.fcl
    `define PCPATH59          `SPARC_CORE59.sparc0.ifu.ifu
    `define DVLD59            `SPARC_CORE59.sparc0.lsu.lsu.dva
    `define DTAG59            `SPARC_CORE59.sparc0.lsu.lsu.dtag
    `define SDTAG59           `SPARC_CORE59.sparc0.lsu.lsu.dtag
    `define SDVLD59           `SPARC_CORE59.sparc0.lsu.lsu.dva
    `define FFUPATH59         `SPARC_CORE59.sparc0.ffu.ffu
    `define TLU_HYPER59       `SPARC_CORE59.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP59           `SPARC_CORE59.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH59        `SPARC_CORE59.sparc0.ifu.ifu.itlb
`else
    `define TLPATH59          `SPARC_CORE59.sparc0.tlu.tcl
    `define TS0PATH59         `SPARC_CORE59.sparc0.tlu.tsa0
    `define TS1PATH59         `SPARC_CORE59.sparc0.tlu.tsa1
    `define INTPATH59         `SPARC_CORE59.sparc0.tlu.intdp
    `define ASIPATH59         `SPARC_CORE59.sparc0.lsu.dctl
    `define ASIDPPATH59       `SPARC_CORE59.sparc0.lsu.dctldp
    `define ICTPATH59         `SPARC_CORE59.sparc0.ifu.ict
    `define DCACHE59          `SPARC_CORE59.sparc0.lsu.dcache
    `define INSTPATH59        `SPARC_CORE59.sparc0.ifu.fcl
    `define PCPATH59          `SPARC_CORE59.sparc0.ifu
    `define DVLD59            `SPARC_CORE59.sparc0.lsu.dva
    `define DTAG59            `SPARC_CORE59.sparc0.lsu.dtag
    `define SDTAG59           `SPARC_CORE59.sparc0.lsu.dtag
    `define SDVLD59           `SPARC_CORE59.sparc0.lsu.dva
    `define FFUPATH59         `SPARC_CORE59.sparc0.ffu
    `define TLU_HYPER59       `SPARC_CORE59.sparc0.tlu.tlu_hyperv
    `define IFQDP59           `SPARC_CORE59.sparc0.ifu.ifqdp
    `define ITLBPATH59        `SPARC_CORE59.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH59    `SPARC_CORE59.sparc0.cfg_asi

    `define PITON_CORE59_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc59_inst_done
`ifdef RTL_SPARC59
    `define PITON_CORE59_PC_W59     `PCPATH59.fdp.pc_w
`else
    `define PITON_CORE59_PC_W59     `TOP_MOD.monitor.pc_cmp.spc59_phy_pc_w
`endif

    

    `define TILE60            `CHIP.tile60
    `define ARIANE_CORE60     `TILE60.g_ariane_core.core.ariane
    `define SPARC_CORE60      `TILE60.g_sparc_core.core
    `define PICO_CORE60       `TILE60.g_picorv32_core.core
    `define CCX_TRANSDUCER60  `TILE60.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER60 `TILE60.g_picorv32_core.pico_l15_transducer
    `define L15_TOP60         `TILE60.l15.l15
    `define L15_PIPE60        `TILE60.l15.l15.pipeline
    `define DMBR60            `TILE60.dmbr_ins
    `define L2_TOP60          `TILE60.l2
    `define SPARC_REG60       `SPARC_CORE60.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH60       `SPARC_CORE60.sparc0.ffu.ffu
`else
    `define FLOATPATH60       `SPARC_CORE60.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH60         `SPARC_CORE60.sparc0.tlu.tlu
    `define DTLBPATH60        `SPARC_CORE60.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH60         `SPARC_CORE60.sparc0.tlu
    `define DTLBPATH60        `SPARC_CORE60.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH60         `SPARC_CORE60.sparc0
`ifndef RTL_SPU
    `define ICVPATH60         `SPARC_CORE60.sparc0.ifu.ifu.icv
    `define IFUPATH60         `SPARC_CORE60.sparc0.ifu.ifu
    `define TNUM60S           `SPARC_CORE60.sparc0.ifu.ifu.swl
    `define TPC60S            `SPARC_CORE60.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH60         `SPARC_CORE60.sparc0.ifu.icv
    `define IFUPATH60         `SPARC_CORE60.sparc0.ifu
    `define TNUM60S           `SPARC_CORE60.sparc0.ifu.swl
    `define TPC60S            `SPARC_CORE60.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH60         `SPARC_CORE60.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH60         `SPARC_CORE60.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH60         `SPARC_CORE60.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH60         `SPARC_CORE60.sparc0.ifu.fdp
`endif
    `define ALUPATH60         `SPARC_CORE60.sparc0.exu.exu.alu
    `define SPCPATH60         `SPARC_CORE60.sparc0
    `define REGPATH60         `SPARC_CORE60.sparc0.exu.exu.irf.irf
    `define CCRPATH60         `SPARC_CORE60.sparc0.exu.exu.ecl.ccr
    `define EXUPATH60         `SPARC_CORE60.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH60          `SPARC_CORE60.sparc0.tlu.tlu.tcl
    `define TS0PATH60         `SPARC_CORE60.sparc0.tlu.tlu.tsa0
    `define TS1PATH60         `SPARC_CORE60.sparc0.tlu.tlu.tsa1
    `define INTPATH60         `SPARC_CORE60.sparc0.tlu.tlu.intdp
    `define ASIPATH60         `SPARC_CORE60.sparc0.lsu.lsu.dctl
    `define ASIDPPATH60       `SPARC_CORE60.sparc0.lsu.lsu.dctldp
    `define ICTPATH60         `SPARC_CORE60.sparc0.ifu.ifu.ict
    `define DCACHE60          `SPARC_CORE60.sparc0.lsu.lsu.dcache
    `define INSTPATH60        `SPARC_CORE60.sparc0.ifu.ifu.fcl
    `define PCPATH60          `SPARC_CORE60.sparc0.ifu.ifu
    `define DVLD60            `SPARC_CORE60.sparc0.lsu.lsu.dva
    `define DTAG60            `SPARC_CORE60.sparc0.lsu.lsu.dtag
    `define SDTAG60           `SPARC_CORE60.sparc0.lsu.lsu.dtag
    `define SDVLD60           `SPARC_CORE60.sparc0.lsu.lsu.dva
    `define FFUPATH60         `SPARC_CORE60.sparc0.ffu.ffu
    `define TLU_HYPER60       `SPARC_CORE60.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP60           `SPARC_CORE60.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH60        `SPARC_CORE60.sparc0.ifu.ifu.itlb
`else
    `define TLPATH60          `SPARC_CORE60.sparc0.tlu.tcl
    `define TS0PATH60         `SPARC_CORE60.sparc0.tlu.tsa0
    `define TS1PATH60         `SPARC_CORE60.sparc0.tlu.tsa1
    `define INTPATH60         `SPARC_CORE60.sparc0.tlu.intdp
    `define ASIPATH60         `SPARC_CORE60.sparc0.lsu.dctl
    `define ASIDPPATH60       `SPARC_CORE60.sparc0.lsu.dctldp
    `define ICTPATH60         `SPARC_CORE60.sparc0.ifu.ict
    `define DCACHE60          `SPARC_CORE60.sparc0.lsu.dcache
    `define INSTPATH60        `SPARC_CORE60.sparc0.ifu.fcl
    `define PCPATH60          `SPARC_CORE60.sparc0.ifu
    `define DVLD60            `SPARC_CORE60.sparc0.lsu.dva
    `define DTAG60            `SPARC_CORE60.sparc0.lsu.dtag
    `define SDTAG60           `SPARC_CORE60.sparc0.lsu.dtag
    `define SDVLD60           `SPARC_CORE60.sparc0.lsu.dva
    `define FFUPATH60         `SPARC_CORE60.sparc0.ffu
    `define TLU_HYPER60       `SPARC_CORE60.sparc0.tlu.tlu_hyperv
    `define IFQDP60           `SPARC_CORE60.sparc0.ifu.ifqdp
    `define ITLBPATH60        `SPARC_CORE60.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH60    `SPARC_CORE60.sparc0.cfg_asi

    `define PITON_CORE60_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc60_inst_done
`ifdef RTL_SPARC60
    `define PITON_CORE60_PC_W60     `PCPATH60.fdp.pc_w
`else
    `define PITON_CORE60_PC_W60     `TOP_MOD.monitor.pc_cmp.spc60_phy_pc_w
`endif

    

    `define TILE61            `CHIP.tile61
    `define ARIANE_CORE61     `TILE61.g_ariane_core.core.ariane
    `define SPARC_CORE61      `TILE61.g_sparc_core.core
    `define PICO_CORE61       `TILE61.g_picorv32_core.core
    `define CCX_TRANSDUCER61  `TILE61.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER61 `TILE61.g_picorv32_core.pico_l15_transducer
    `define L15_TOP61         `TILE61.l15.l15
    `define L15_PIPE61        `TILE61.l15.l15.pipeline
    `define DMBR61            `TILE61.dmbr_ins
    `define L2_TOP61          `TILE61.l2
    `define SPARC_REG61       `SPARC_CORE61.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH61       `SPARC_CORE61.sparc0.ffu.ffu
`else
    `define FLOATPATH61       `SPARC_CORE61.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH61         `SPARC_CORE61.sparc0.tlu.tlu
    `define DTLBPATH61        `SPARC_CORE61.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH61         `SPARC_CORE61.sparc0.tlu
    `define DTLBPATH61        `SPARC_CORE61.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH61         `SPARC_CORE61.sparc0
`ifndef RTL_SPU
    `define ICVPATH61         `SPARC_CORE61.sparc0.ifu.ifu.icv
    `define IFUPATH61         `SPARC_CORE61.sparc0.ifu.ifu
    `define TNUM61S           `SPARC_CORE61.sparc0.ifu.ifu.swl
    `define TPC61S            `SPARC_CORE61.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH61         `SPARC_CORE61.sparc0.ifu.icv
    `define IFUPATH61         `SPARC_CORE61.sparc0.ifu
    `define TNUM61S           `SPARC_CORE61.sparc0.ifu.swl
    `define TPC61S            `SPARC_CORE61.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH61         `SPARC_CORE61.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH61         `SPARC_CORE61.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH61         `SPARC_CORE61.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH61         `SPARC_CORE61.sparc0.ifu.fdp
`endif
    `define ALUPATH61         `SPARC_CORE61.sparc0.exu.exu.alu
    `define SPCPATH61         `SPARC_CORE61.sparc0
    `define REGPATH61         `SPARC_CORE61.sparc0.exu.exu.irf.irf
    `define CCRPATH61         `SPARC_CORE61.sparc0.exu.exu.ecl.ccr
    `define EXUPATH61         `SPARC_CORE61.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH61          `SPARC_CORE61.sparc0.tlu.tlu.tcl
    `define TS0PATH61         `SPARC_CORE61.sparc0.tlu.tlu.tsa0
    `define TS1PATH61         `SPARC_CORE61.sparc0.tlu.tlu.tsa1
    `define INTPATH61         `SPARC_CORE61.sparc0.tlu.tlu.intdp
    `define ASIPATH61         `SPARC_CORE61.sparc0.lsu.lsu.dctl
    `define ASIDPPATH61       `SPARC_CORE61.sparc0.lsu.lsu.dctldp
    `define ICTPATH61         `SPARC_CORE61.sparc0.ifu.ifu.ict
    `define DCACHE61          `SPARC_CORE61.sparc0.lsu.lsu.dcache
    `define INSTPATH61        `SPARC_CORE61.sparc0.ifu.ifu.fcl
    `define PCPATH61          `SPARC_CORE61.sparc0.ifu.ifu
    `define DVLD61            `SPARC_CORE61.sparc0.lsu.lsu.dva
    `define DTAG61            `SPARC_CORE61.sparc0.lsu.lsu.dtag
    `define SDTAG61           `SPARC_CORE61.sparc0.lsu.lsu.dtag
    `define SDVLD61           `SPARC_CORE61.sparc0.lsu.lsu.dva
    `define FFUPATH61         `SPARC_CORE61.sparc0.ffu.ffu
    `define TLU_HYPER61       `SPARC_CORE61.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP61           `SPARC_CORE61.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH61        `SPARC_CORE61.sparc0.ifu.ifu.itlb
`else
    `define TLPATH61          `SPARC_CORE61.sparc0.tlu.tcl
    `define TS0PATH61         `SPARC_CORE61.sparc0.tlu.tsa0
    `define TS1PATH61         `SPARC_CORE61.sparc0.tlu.tsa1
    `define INTPATH61         `SPARC_CORE61.sparc0.tlu.intdp
    `define ASIPATH61         `SPARC_CORE61.sparc0.lsu.dctl
    `define ASIDPPATH61       `SPARC_CORE61.sparc0.lsu.dctldp
    `define ICTPATH61         `SPARC_CORE61.sparc0.ifu.ict
    `define DCACHE61          `SPARC_CORE61.sparc0.lsu.dcache
    `define INSTPATH61        `SPARC_CORE61.sparc0.ifu.fcl
    `define PCPATH61          `SPARC_CORE61.sparc0.ifu
    `define DVLD61            `SPARC_CORE61.sparc0.lsu.dva
    `define DTAG61            `SPARC_CORE61.sparc0.lsu.dtag
    `define SDTAG61           `SPARC_CORE61.sparc0.lsu.dtag
    `define SDVLD61           `SPARC_CORE61.sparc0.lsu.dva
    `define FFUPATH61         `SPARC_CORE61.sparc0.ffu
    `define TLU_HYPER61       `SPARC_CORE61.sparc0.tlu.tlu_hyperv
    `define IFQDP61           `SPARC_CORE61.sparc0.ifu.ifqdp
    `define ITLBPATH61        `SPARC_CORE61.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH61    `SPARC_CORE61.sparc0.cfg_asi

    `define PITON_CORE61_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc61_inst_done
`ifdef RTL_SPARC61
    `define PITON_CORE61_PC_W61     `PCPATH61.fdp.pc_w
`else
    `define PITON_CORE61_PC_W61     `TOP_MOD.monitor.pc_cmp.spc61_phy_pc_w
`endif

    

    `define TILE62            `CHIP.tile62
    `define ARIANE_CORE62     `TILE62.g_ariane_core.core.ariane
    `define SPARC_CORE62      `TILE62.g_sparc_core.core
    `define PICO_CORE62       `TILE62.g_picorv32_core.core
    `define CCX_TRANSDUCER62  `TILE62.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER62 `TILE62.g_picorv32_core.pico_l15_transducer
    `define L15_TOP62         `TILE62.l15.l15
    `define L15_PIPE62        `TILE62.l15.l15.pipeline
    `define DMBR62            `TILE62.dmbr_ins
    `define L2_TOP62          `TILE62.l2
    `define SPARC_REG62       `SPARC_CORE62.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH62       `SPARC_CORE62.sparc0.ffu.ffu
`else
    `define FLOATPATH62       `SPARC_CORE62.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH62         `SPARC_CORE62.sparc0.tlu.tlu
    `define DTLBPATH62        `SPARC_CORE62.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH62         `SPARC_CORE62.sparc0.tlu
    `define DTLBPATH62        `SPARC_CORE62.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH62         `SPARC_CORE62.sparc0
`ifndef RTL_SPU
    `define ICVPATH62         `SPARC_CORE62.sparc0.ifu.ifu.icv
    `define IFUPATH62         `SPARC_CORE62.sparc0.ifu.ifu
    `define TNUM62S           `SPARC_CORE62.sparc0.ifu.ifu.swl
    `define TPC62S            `SPARC_CORE62.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH62         `SPARC_CORE62.sparc0.ifu.icv
    `define IFUPATH62         `SPARC_CORE62.sparc0.ifu
    `define TNUM62S           `SPARC_CORE62.sparc0.ifu.swl
    `define TPC62S            `SPARC_CORE62.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH62         `SPARC_CORE62.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH62         `SPARC_CORE62.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH62         `SPARC_CORE62.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH62         `SPARC_CORE62.sparc0.ifu.fdp
`endif
    `define ALUPATH62         `SPARC_CORE62.sparc0.exu.exu.alu
    `define SPCPATH62         `SPARC_CORE62.sparc0
    `define REGPATH62         `SPARC_CORE62.sparc0.exu.exu.irf.irf
    `define CCRPATH62         `SPARC_CORE62.sparc0.exu.exu.ecl.ccr
    `define EXUPATH62         `SPARC_CORE62.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH62          `SPARC_CORE62.sparc0.tlu.tlu.tcl
    `define TS0PATH62         `SPARC_CORE62.sparc0.tlu.tlu.tsa0
    `define TS1PATH62         `SPARC_CORE62.sparc0.tlu.tlu.tsa1
    `define INTPATH62         `SPARC_CORE62.sparc0.tlu.tlu.intdp
    `define ASIPATH62         `SPARC_CORE62.sparc0.lsu.lsu.dctl
    `define ASIDPPATH62       `SPARC_CORE62.sparc0.lsu.lsu.dctldp
    `define ICTPATH62         `SPARC_CORE62.sparc0.ifu.ifu.ict
    `define DCACHE62          `SPARC_CORE62.sparc0.lsu.lsu.dcache
    `define INSTPATH62        `SPARC_CORE62.sparc0.ifu.ifu.fcl
    `define PCPATH62          `SPARC_CORE62.sparc0.ifu.ifu
    `define DVLD62            `SPARC_CORE62.sparc0.lsu.lsu.dva
    `define DTAG62            `SPARC_CORE62.sparc0.lsu.lsu.dtag
    `define SDTAG62           `SPARC_CORE62.sparc0.lsu.lsu.dtag
    `define SDVLD62           `SPARC_CORE62.sparc0.lsu.lsu.dva
    `define FFUPATH62         `SPARC_CORE62.sparc0.ffu.ffu
    `define TLU_HYPER62       `SPARC_CORE62.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP62           `SPARC_CORE62.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH62        `SPARC_CORE62.sparc0.ifu.ifu.itlb
`else
    `define TLPATH62          `SPARC_CORE62.sparc0.tlu.tcl
    `define TS0PATH62         `SPARC_CORE62.sparc0.tlu.tsa0
    `define TS1PATH62         `SPARC_CORE62.sparc0.tlu.tsa1
    `define INTPATH62         `SPARC_CORE62.sparc0.tlu.intdp
    `define ASIPATH62         `SPARC_CORE62.sparc0.lsu.dctl
    `define ASIDPPATH62       `SPARC_CORE62.sparc0.lsu.dctldp
    `define ICTPATH62         `SPARC_CORE62.sparc0.ifu.ict
    `define DCACHE62          `SPARC_CORE62.sparc0.lsu.dcache
    `define INSTPATH62        `SPARC_CORE62.sparc0.ifu.fcl
    `define PCPATH62          `SPARC_CORE62.sparc0.ifu
    `define DVLD62            `SPARC_CORE62.sparc0.lsu.dva
    `define DTAG62            `SPARC_CORE62.sparc0.lsu.dtag
    `define SDTAG62           `SPARC_CORE62.sparc0.lsu.dtag
    `define SDVLD62           `SPARC_CORE62.sparc0.lsu.dva
    `define FFUPATH62         `SPARC_CORE62.sparc0.ffu
    `define TLU_HYPER62       `SPARC_CORE62.sparc0.tlu.tlu_hyperv
    `define IFQDP62           `SPARC_CORE62.sparc0.ifu.ifqdp
    `define ITLBPATH62        `SPARC_CORE62.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH62    `SPARC_CORE62.sparc0.cfg_asi

    `define PITON_CORE62_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc62_inst_done
`ifdef RTL_SPARC62
    `define PITON_CORE62_PC_W62     `PCPATH62.fdp.pc_w
`else
    `define PITON_CORE62_PC_W62     `TOP_MOD.monitor.pc_cmp.spc62_phy_pc_w
`endif

    

    `define TILE63            `CHIP.tile63
    `define ARIANE_CORE63     `TILE63.g_ariane_core.core.ariane
    `define SPARC_CORE63      `TILE63.g_sparc_core.core
    `define PICO_CORE63       `TILE63.g_picorv32_core.core
    `define CCX_TRANSDUCER63  `TILE63.g_sparc_core.ccx_l15_transducer
    `define PICO_TRANSDUCER63 `TILE63.g_picorv32_core.pico_l15_transducer
    `define L15_TOP63         `TILE63.l15.l15
    `define L15_PIPE63        `TILE63.l15.l15.pipeline
    `define DMBR63            `TILE63.dmbr_ins
    `define L2_TOP63          `TILE63.l2
    `define SPARC_REG63       `SPARC_CORE63.sparc0.exu.exu.irf.irf
`ifndef RTL_SPU
    `define FLOATPATH63       `SPARC_CORE63.sparc0.ffu.ffu
`else
    `define FLOATPATH63       `SPARC_CORE63.sparc0.ffu
`endif
`ifndef RTL_SPU
    `define TLUPATH63         `SPARC_CORE63.sparc0.tlu.tlu
    `define DTLBPATH63        `SPARC_CORE63.sparc0.lsu.lsu.dtlb
`else
    `define TLUPATH63         `SPARC_CORE63.sparc0.tlu
    `define DTLBPATH63        `SPARC_CORE63.sparc0.lsu.dtlb
`endif
`ifndef RTL_SPU
    `define LSU_PATH sparc0.lsu.lsu
`else
    `define LSU_PATH sparc0.lsu
`endif
    `define PCXPATH63         `SPARC_CORE63.sparc0
`ifndef RTL_SPU
    `define ICVPATH63         `SPARC_CORE63.sparc0.ifu.ifu.icv
    `define IFUPATH63         `SPARC_CORE63.sparc0.ifu.ifu
    `define TNUM63S           `SPARC_CORE63.sparc0.ifu.ifu.swl
    `define TPC63S            `SPARC_CORE63.sparc0.ifu.ifu.fdp
`else
    `define ICVPATH63         `SPARC_CORE63.sparc0.ifu.icv
    `define IFUPATH63         `SPARC_CORE63.sparc0.ifu
    `define TNUM63S           `SPARC_CORE63.sparc0.ifu.swl
    `define TPC63S            `SPARC_CORE63.sparc0.ifu.fdp
`endif
`ifndef RTL_SPU
    `define TDPPATH63         `SPARC_CORE63.sparc0.tlu.tlu.tdp
`else
    `define TDPPATH63         `SPARC_CORE63.sparc0.tlu.tdp
`endif
`ifndef RTL_SPU
    `define DTUPATH63         `SPARC_CORE63.sparc0.ifu.ifu.fdp
`else
    `define DTUPATH63         `SPARC_CORE63.sparc0.ifu.fdp
`endif
    `define ALUPATH63         `SPARC_CORE63.sparc0.exu.exu.alu
    `define SPCPATH63         `SPARC_CORE63.sparc0
    `define REGPATH63         `SPARC_CORE63.sparc0.exu.exu.irf.irf
    `define CCRPATH63         `SPARC_CORE63.sparc0.exu.exu.ecl.ccr
    `define EXUPATH63         `SPARC_CORE63.sparc0.exu.exu
`ifndef RTL_SPU
    `define TLPATH63          `SPARC_CORE63.sparc0.tlu.tlu.tcl
    `define TS0PATH63         `SPARC_CORE63.sparc0.tlu.tlu.tsa0
    `define TS1PATH63         `SPARC_CORE63.sparc0.tlu.tlu.tsa1
    `define INTPATH63         `SPARC_CORE63.sparc0.tlu.tlu.intdp
    `define ASIPATH63         `SPARC_CORE63.sparc0.lsu.lsu.dctl
    `define ASIDPPATH63       `SPARC_CORE63.sparc0.lsu.lsu.dctldp
    `define ICTPATH63         `SPARC_CORE63.sparc0.ifu.ifu.ict
    `define DCACHE63          `SPARC_CORE63.sparc0.lsu.lsu.dcache
    `define INSTPATH63        `SPARC_CORE63.sparc0.ifu.ifu.fcl
    `define PCPATH63          `SPARC_CORE63.sparc0.ifu.ifu
    `define DVLD63            `SPARC_CORE63.sparc0.lsu.lsu.dva
    `define DTAG63            `SPARC_CORE63.sparc0.lsu.lsu.dtag
    `define SDTAG63           `SPARC_CORE63.sparc0.lsu.lsu.dtag
    `define SDVLD63           `SPARC_CORE63.sparc0.lsu.lsu.dva
    `define FFUPATH63         `SPARC_CORE63.sparc0.ffu.ffu
    `define TLU_HYPER63       `SPARC_CORE63.sparc0.tlu.tlu.tlu_hyperv
    `define IFQDP63           `SPARC_CORE63.sparc0.ifu.ifu.ifqdp
    `define ITLBPATH63        `SPARC_CORE63.sparc0.ifu.ifu.itlb
`else
    `define TLPATH63          `SPARC_CORE63.sparc0.tlu.tcl
    `define TS0PATH63         `SPARC_CORE63.sparc0.tlu.tsa0
    `define TS1PATH63         `SPARC_CORE63.sparc0.tlu.tsa1
    `define INTPATH63         `SPARC_CORE63.sparc0.tlu.intdp
    `define ASIPATH63         `SPARC_CORE63.sparc0.lsu.dctl
    `define ASIDPPATH63       `SPARC_CORE63.sparc0.lsu.dctldp
    `define ICTPATH63         `SPARC_CORE63.sparc0.ifu.ict
    `define DCACHE63          `SPARC_CORE63.sparc0.lsu.dcache
    `define INSTPATH63        `SPARC_CORE63.sparc0.ifu.fcl
    `define PCPATH63          `SPARC_CORE63.sparc0.ifu
    `define DVLD63            `SPARC_CORE63.sparc0.lsu.dva
    `define DTAG63            `SPARC_CORE63.sparc0.lsu.dtag
    `define SDTAG63           `SPARC_CORE63.sparc0.lsu.dtag
    `define SDVLD63           `SPARC_CORE63.sparc0.lsu.dva
    `define FFUPATH63         `SPARC_CORE63.sparc0.ffu
    `define TLU_HYPER63       `SPARC_CORE63.sparc0.tlu.tlu_hyperv
    `define IFQDP63           `SPARC_CORE63.sparc0.ifu.ifqdp
    `define ITLBPATH63        `SPARC_CORE63.sparc0.ifu.itlb
`endif
    `define CFG_ASI_PATH63    `SPARC_CORE63.sparc0.cfg_asi

    `define PITON_CORE63_INST_DONE  `TOP_MOD.monitor.pc_cmp.spc63_inst_done
`ifdef RTL_SPARC63
    `define PITON_CORE63_PC_W63     `PCPATH63.fdp.pc_w
`else
    `define PITON_CORE63_PC_W63     `TOP_MOD.monitor.pc_cmp.spc63_phy_pc_w
`endif

    


`define ITAG0           `TOP_MOD.monitor.l_cache_mon0
`define IVLD0           `TOP_MOD.monitor.l_cache_mon0
`define SAS_INTER `TOP_MOD.sas_intf
`ifndef RTL_SPU
`define STNUM `SPARC_CORE0.sparc0.ifu.ifu.dtu.swl
`define STPC  `SPARC_CORE0.sparc0.ifu.ifu.fdp
`else
`define STNUM `SPARC_CORE0.sparc0.ifu.dtu.swl
`define STPC  `SPARC_CORE0.sparc0.ifu.fdp
`endif
`define MONITOR `TOP_MOD.monitor

`endif
