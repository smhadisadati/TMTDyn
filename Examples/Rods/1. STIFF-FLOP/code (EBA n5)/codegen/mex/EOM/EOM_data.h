/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * EOM_data.h
 *
 * Code generation for function 'EOM_data'
 *
 */

#ifndef EOM_DATA_H
#define EOM_DATA_H

/* Include files */
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "EOM_types.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern const volatile char_T *emlrtBreakCheckR2012bFlagVar;
extern real_T t_report;
extern uint32_T t_report_dirty;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo ob_emlrtRSI;
extern emlrtRSInfo pb_emlrtRSI;
extern emlrtRSInfo qb_emlrtRSI;
extern emlrtRSInfo rb_emlrtRSI;
extern emlrtRSInfo sb_emlrtRSI;
extern emlrtRSInfo ue_emlrtRSI;
extern emlrtRSInfo ve_emlrtRSI;
extern emlrtRSInfo we_emlrtRSI;
extern emlrtRSInfo af_emlrtRSI;
extern emlrtRSInfo bf_emlrtRSI;
extern emlrtRSInfo cf_emlrtRSI;
extern emlrtRSInfo ff_emlrtRSI;
extern emlrtRSInfo gf_emlrtRSI;
extern emlrtRSInfo hf_emlrtRSI;
extern emlrtRSInfo if_emlrtRSI;
extern emlrtRSInfo jf_emlrtRSI;
extern emlrtRSInfo kf_emlrtRSI;
extern emlrtRSInfo lf_emlrtRSI;
extern emlrtRSInfo mf_emlrtRSI;
extern emlrtRSInfo nf_emlrtRSI;
extern emlrtRSInfo of_emlrtRSI;
extern emlrtRSInfo pf_emlrtRSI;
extern emlrtRSInfo qf_emlrtRSI;
extern emlrtRSInfo rf_emlrtRSI;
extern emlrtRSInfo sf_emlrtRSI;
extern emlrtRSInfo tf_emlrtRSI;
extern emlrtRSInfo uf_emlrtRSI;
extern emlrtRSInfo vf_emlrtRSI;
extern emlrtRSInfo wf_emlrtRSI;
extern emlrtRSInfo xf_emlrtRSI;
extern emlrtRSInfo bg_emlrtRSI;
extern emlrtRSInfo dg_emlrtRSI;
extern emlrtRSInfo eg_emlrtRSI;
extern emlrtRSInfo fg_emlrtRSI;
extern emlrtRSInfo ig_emlrtRSI;
extern emlrtRSInfo jg_emlrtRSI;
extern emlrtRSInfo kg_emlrtRSI;
extern emlrtRSInfo ng_emlrtRSI;
extern emlrtRSInfo og_emlrtRSI;
extern emlrtRSInfo pg_emlrtRSI;
extern emlrtRSInfo qg_emlrtRSI;
extern emlrtRSInfo rg_emlrtRSI;
extern emlrtRSInfo sg_emlrtRSI;
extern emlrtRSInfo tg_emlrtRSI;
extern emlrtRSInfo ug_emlrtRSI;
extern emlrtRSInfo vg_emlrtRSI;
extern emlrtRSInfo wg_emlrtRSI;
extern emlrtRSInfo xg_emlrtRSI;
extern emlrtRSInfo yg_emlrtRSI;
extern emlrtRSInfo ah_emlrtRSI;
extern emlrtRSInfo bh_emlrtRSI;
extern emlrtRSInfo ch_emlrtRSI;
extern emlrtRSInfo dh_emlrtRSI;
extern emlrtRSInfo eh_emlrtRSI;
extern emlrtRSInfo fh_emlrtRSI;
extern emlrtRSInfo gh_emlrtRSI;
extern emlrtRSInfo jh_emlrtRSI;
extern emlrtRSInfo lh_emlrtRSI;
extern emlrtRSInfo mh_emlrtRSI;
extern emlrtRSInfo nh_emlrtRSI;
extern emlrtRSInfo qh_emlrtRSI;
extern emlrtRSInfo rh_emlrtRSI;
extern emlrtRSInfo sh_emlrtRSI;
extern emlrtRSInfo vh_emlrtRSI;
extern emlrtRSInfo wh_emlrtRSI;
extern emlrtRSInfo xh_emlrtRSI;
extern emlrtRSInfo yh_emlrtRSI;
extern emlrtRSInfo ai_emlrtRSI;
extern emlrtRSInfo bi_emlrtRSI;
extern emlrtRSInfo ci_emlrtRSI;
extern emlrtRSInfo di_emlrtRSI;
extern emlrtRSInfo ei_emlrtRSI;
extern emlrtRSInfo fi_emlrtRSI;
extern emlrtRSInfo gi_emlrtRSI;
extern emlrtRSInfo hi_emlrtRSI;
extern emlrtRSInfo ii_emlrtRSI;
extern emlrtRSInfo ji_emlrtRSI;
extern emlrtRSInfo ki_emlrtRSI;
extern emlrtRSInfo li_emlrtRSI;
extern emlrtRSInfo mi_emlrtRSI;
extern emlrtRSInfo ni_emlrtRSI;
extern emlrtRSInfo oi_emlrtRSI;
extern emlrtRSInfo ri_emlrtRSI;
extern emlrtRSInfo ti_emlrtRSI;
extern emlrtRSInfo ui_emlrtRSI;
extern emlrtRSInfo vi_emlrtRSI;
extern emlrtRSInfo yi_emlrtRSI;
extern emlrtRSInfo aj_emlrtRSI;
extern emlrtRSInfo bj_emlrtRSI;
extern emlrtRSInfo ej_emlrtRSI;
extern emlrtRSInfo fj_emlrtRSI;
extern emlrtRSInfo gj_emlrtRSI;
extern emlrtRSInfo hj_emlrtRSI;
extern emlrtRSInfo ij_emlrtRSI;
extern emlrtRSInfo jj_emlrtRSI;
extern emlrtRSInfo kj_emlrtRSI;
extern emlrtRSInfo lj_emlrtRSI;
extern emlrtRSInfo mj_emlrtRSI;
extern emlrtRSInfo nj_emlrtRSI;
extern emlrtRSInfo oj_emlrtRSI;
extern emlrtRSInfo pj_emlrtRSI;
extern emlrtRSInfo qj_emlrtRSI;
extern emlrtRSInfo rj_emlrtRSI;
extern emlrtRSInfo sj_emlrtRSI;
extern emlrtRSInfo tj_emlrtRSI;
extern emlrtRSInfo uj_emlrtRSI;
extern emlrtRSInfo vj_emlrtRSI;
extern emlrtRSInfo wj_emlrtRSI;
extern emlrtRSInfo ak_emlrtRSI;
extern emlrtRSInfo lk_emlrtRSI;
extern emlrtRSInfo mk_emlrtRSI;
extern emlrtRSInfo nk_emlrtRSI;
extern emlrtRSInfo vk_emlrtRSI;
extern emlrtRSInfo wk_emlrtRSI;
extern emlrtRSInfo bl_emlrtRSI;
extern emlrtRSInfo cl_emlrtRSI;

#endif

/* End of code generation (EOM_data.h) */
