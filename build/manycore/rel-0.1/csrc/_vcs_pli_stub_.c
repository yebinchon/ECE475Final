#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <dlfcn.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void* VCS_dlsymLookup(const char *);
extern void vcsMsgReportNoSource1(const char *, const char*);

/* PLI routine: $slam_random:call */
#ifndef __VCS_PLI_STUB_slam_random_call
#define __VCS_PLI_STUB_slam_random_call
extern void slam_random_call(int data, int reason);
#pragma weak slam_random_call
void slam_random_call(int data, int reason)
{
    static int _vcs_pli_stub_initialized_ = 0;
    static void (*_vcs_pli_fp_)(int data, int reason) = NULL;
    if (!_vcs_pli_stub_initialized_) {
        _vcs_pli_stub_initialized_ = 1;
        _vcs_pli_fp_ = (void (*)(int data, int reason)) dlsym(RTLD_NEXT, "slam_random_call");
        if (_vcs_pli_fp_ == NULL) {
            _vcs_pli_fp_ = (void (*)(int data, int reason)) VCS_dlsymLookup("slam_random_call");
        }
    }
    if (_vcs_pli_fp_) {
        _vcs_pli_fp_(data, reason);
    } else {
        vcsMsgReportNoSource1("PLI-DIFNF", "slam_random_call");
    }
}
void (*__vcs_pli_dummy_reference_slam_random_call)(int data, int reason) = slam_random_call;
#endif /* __VCS_PLI_STUB_slam_random_call */

/* PLI routine: $bw_force_by_name:call */
#ifndef __VCS_PLI_STUB_bw_tlb_reset_vld_call
#define __VCS_PLI_STUB_bw_tlb_reset_vld_call
extern void bw_tlb_reset_vld_call(int data, int reason);
#pragma weak bw_tlb_reset_vld_call
void bw_tlb_reset_vld_call(int data, int reason)
{
    static int _vcs_pli_stub_initialized_ = 0;
    static void (*_vcs_pli_fp_)(int data, int reason) = NULL;
    if (!_vcs_pli_stub_initialized_) {
        _vcs_pli_stub_initialized_ = 1;
        _vcs_pli_fp_ = (void (*)(int data, int reason)) dlsym(RTLD_NEXT, "bw_tlb_reset_vld_call");
        if (_vcs_pli_fp_ == NULL) {
            _vcs_pli_fp_ = (void (*)(int data, int reason)) VCS_dlsymLookup("bw_tlb_reset_vld_call");
        }
    }
    if (_vcs_pli_fp_) {
        _vcs_pli_fp_(data, reason);
    } else {
        vcsMsgReportNoSource1("PLI-DIFNF", "bw_tlb_reset_vld_call");
    }
}
void (*__vcs_pli_dummy_reference_bw_tlb_reset_vld_call)(int data, int reason) = bw_tlb_reset_vld_call;
#endif /* __VCS_PLI_STUB_bw_tlb_reset_vld_call */

/* PLI routine: $init_jbus_model:call */
#ifndef __VCS_PLI_STUB_init_jbus_model_call
#define __VCS_PLI_STUB_init_jbus_model_call
extern void init_jbus_model_call(int data, int reason);
#pragma weak init_jbus_model_call
void init_jbus_model_call(int data, int reason)
{
    static int _vcs_pli_stub_initialized_ = 0;
    static void (*_vcs_pli_fp_)(int data, int reason) = NULL;
    if (!_vcs_pli_stub_initialized_) {
        _vcs_pli_stub_initialized_ = 1;
        _vcs_pli_fp_ = (void (*)(int data, int reason)) dlsym(RTLD_NEXT, "init_jbus_model_call");
        if (_vcs_pli_fp_ == NULL) {
            _vcs_pli_fp_ = (void (*)(int data, int reason)) VCS_dlsymLookup("init_jbus_model_call");
        }
    }
    if (_vcs_pli_fp_) {
        _vcs_pli_fp_(data, reason);
    } else {
        vcsMsgReportNoSource1("PLI-DIFNF", "init_jbus_model_call");
    }
}
void (*__vcs_pli_dummy_reference_init_jbus_model_call)(int data, int reason) = init_jbus_model_call;
#endif /* __VCS_PLI_STUB_init_jbus_model_call */

/* PLI routine: $iob_cdriver:call */
#ifndef __VCS_PLI_STUB_iob_cdrive_call
#define __VCS_PLI_STUB_iob_cdrive_call
extern void iob_cdrive_call(int data, int reason);
#pragma weak iob_cdrive_call
void iob_cdrive_call(int data, int reason)
{
    static int _vcs_pli_stub_initialized_ = 0;
    static void (*_vcs_pli_fp_)(int data, int reason) = NULL;
    if (!_vcs_pli_stub_initialized_) {
        _vcs_pli_stub_initialized_ = 1;
        _vcs_pli_fp_ = (void (*)(int data, int reason)) dlsym(RTLD_NEXT, "iob_cdrive_call");
        if (_vcs_pli_fp_ == NULL) {
            _vcs_pli_fp_ = (void (*)(int data, int reason)) VCS_dlsymLookup("iob_cdrive_call");
        }
    }
    if (_vcs_pli_fp_) {
        _vcs_pli_fp_(data, reason);
    } else {
        vcsMsgReportNoSource1("PLI-DIFNF", "iob_cdrive_call");
    }
}
void (*__vcs_pli_dummy_reference_iob_cdrive_call)(int data, int reason) = iob_cdrive_call;
#endif /* __VCS_PLI_STUB_iob_cdrive_call */

/* PLI routine: $bw_sys:call */
#ifndef __VCS_PLI_STUB_bw_sys_call
#define __VCS_PLI_STUB_bw_sys_call
extern void bw_sys_call(int data, int reason);
#pragma weak bw_sys_call
void bw_sys_call(int data, int reason)
{
    static int _vcs_pli_stub_initialized_ = 0;
    static void (*_vcs_pli_fp_)(int data, int reason) = NULL;
    if (!_vcs_pli_stub_initialized_) {
        _vcs_pli_stub_initialized_ = 1;
        _vcs_pli_fp_ = (void (*)(int data, int reason)) dlsym(RTLD_NEXT, "bw_sys_call");
        if (_vcs_pli_fp_ == NULL) {
            _vcs_pli_fp_ = (void (*)(int data, int reason)) VCS_dlsymLookup("bw_sys_call");
        }
    }
    if (_vcs_pli_fp_) {
        _vcs_pli_fp_(data, reason);
    } else {
        vcsMsgReportNoSource1("PLI-DIFNF", "bw_sys_call");
    }
}
void (*__vcs_pli_dummy_reference_bw_sys_call)(int data, int reason) = bw_sys_call;
#endif /* __VCS_PLI_STUB_bw_sys_call */

/* PLI routine: $read_64b:call */
#ifndef __VCS_PLI_STUB_read_64b_call
#define __VCS_PLI_STUB_read_64b_call
extern void read_64b_call(int data, int reason);
#pragma weak read_64b_call
void read_64b_call(int data, int reason)
{
    static int _vcs_pli_stub_initialized_ = 0;
    static void (*_vcs_pli_fp_)(int data, int reason) = NULL;
    if (!_vcs_pli_stub_initialized_) {
        _vcs_pli_stub_initialized_ = 1;
        _vcs_pli_fp_ = (void (*)(int data, int reason)) dlsym(RTLD_NEXT, "read_64b_call");
        if (_vcs_pli_fp_ == NULL) {
            _vcs_pli_fp_ = (void (*)(int data, int reason)) VCS_dlsymLookup("read_64b_call");
        }
    }
    if (_vcs_pli_fp_) {
        _vcs_pli_fp_(data, reason);
    } else {
        vcsMsgReportNoSource1("PLI-DIFNF", "read_64b_call");
    }
}
void (*__vcs_pli_dummy_reference_read_64b_call)(int data, int reason) = read_64b_call;
#endif /* __VCS_PLI_STUB_read_64b_call */

/* PLI routine: $write_64b:call */
#ifndef __VCS_PLI_STUB_write_64b_call
#define __VCS_PLI_STUB_write_64b_call
extern void write_64b_call(int data, int reason);
#pragma weak write_64b_call
void write_64b_call(int data, int reason)
{
    static int _vcs_pli_stub_initialized_ = 0;
    static void (*_vcs_pli_fp_)(int data, int reason) = NULL;
    if (!_vcs_pli_stub_initialized_) {
        _vcs_pli_stub_initialized_ = 1;
        _vcs_pli_fp_ = (void (*)(int data, int reason)) dlsym(RTLD_NEXT, "write_64b_call");
        if (_vcs_pli_fp_ == NULL) {
            _vcs_pli_fp_ = (void (*)(int data, int reason)) VCS_dlsymLookup("write_64b_call");
        }
    }
    if (_vcs_pli_fp_) {
        _vcs_pli_fp_(data, reason);
    } else {
        vcsMsgReportNoSource1("PLI-DIFNF", "write_64b_call");
    }
}
void (*__vcs_pli_dummy_reference_write_64b_call)(int data, int reason) = write_64b_call;
#endif /* __VCS_PLI_STUB_write_64b_call */

/* PLI routine: $init_oram:call */
#ifndef __VCS_PLI_STUB_init_oram_call
#define __VCS_PLI_STUB_init_oram_call
extern void init_oram_call(int data, int reason);
#pragma weak init_oram_call
void init_oram_call(int data, int reason)
{
    static int _vcs_pli_stub_initialized_ = 0;
    static void (*_vcs_pli_fp_)(int data, int reason) = NULL;
    if (!_vcs_pli_stub_initialized_) {
        _vcs_pli_stub_initialized_ = 1;
        _vcs_pli_fp_ = (void (*)(int data, int reason)) dlsym(RTLD_NEXT, "init_oram_call");
        if (_vcs_pli_fp_ == NULL) {
            _vcs_pli_fp_ = (void (*)(int data, int reason)) VCS_dlsymLookup("init_oram_call");
        }
    }
    if (_vcs_pli_fp_) {
        _vcs_pli_fp_(data, reason);
    } else {
        vcsMsgReportNoSource1("PLI-DIFNF", "init_oram_call");
    }
}
void (*__vcs_pli_dummy_reference_init_oram_call)(int data, int reason) = init_oram_call;
#endif /* __VCS_PLI_STUB_init_oram_call */

#ifdef __cplusplus
}
#endif
