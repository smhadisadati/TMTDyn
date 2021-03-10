/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: EOM.c
 *
 * MATLAB Coder version            : 5.1
 * C/C++ source code generated on  : 10-Mar-2021 22:46:32
 */

/* Include Files */
#include "EOM.h"
#include "EOM_types.h"
#include "dyn_mid_step.h"
#include "massF1.h"
#include "massF2.h"
#include "massF3.h"
#include "massF4.h"
#include "massF5.h"
#include "pinv.h"
#include "romF.h"
#include "sprdmpF25.h"
#include "sprdmpF26.h"
#include "sprdmpF27.h"
#include "sprdmpF28.h"
#include "sprdmpF29.h"

/* Function Definitions */
/*
 * Arguments    : double t
 *                const double z[48]
 *                const struct0_T *par_mex
 *                double dz[48]
 *                double *flag
 * Return Type  : void
 */
void EOM(double t, const double z[48], const struct0_T *par_mex, double dz[48],
         double *flag)
{
  static struct0_T b_par_mex;
  double TMT[576];
  double h_TMT_tmp[576];
  double i_TMT_tmp[576];
  double j_TMT_tmp[576];
  double k_TMT_tmp[576];
  double l_TMT_tmp[576];
  double m_TMT_tmp[576];
  double n_TMT_tmp[576];
  double o_TMT_tmp[576];
  double p_TMT_tmp[576];
  double Dd[144];
  double T[144];
  double TMT_tmp[144];
  double Tt[144];
  double b_T[144];
  double b_TMT_tmp[144];
  double b_Tt[144];
  double c_Dd[144];
  double c_T[144];
  double c_TMT_tmp[144];
  double c_Tt[144];
  double d_Dd[144];
  double d_T[144];
  double d_TMT_tmp[144];
  double d_Tt[144];
  double e_Dd[144];
  double e_T[144];
  double e_TMT_tmp[144];
  double f_Dd[144];
  double f_T[144];
  double f_TMT_tmp[144];
  double g_Dd[144];
  double g_T[144];
  double g_TMT_tmp[144];
  double h_Dd[144];
  double h_T[144];
  double i_Dd[144];
  double i_T[144];
  double q_TMT_tmp[144];
  double r_TMT_tmp[144];
  double rom_sprdmp[87];
  double M[36];
  double TMfd[24];
  double b_y[24];
  double s_TMT_tmp[24];
  double t_TMT_tmp[24];
  double u_TMT_tmp[24];
  double v_TMT_tmp[24];
  double w_TMT_tmp[24];
  double w_in[24];
  double w_sd[24];
  double w_vd_j[24];
  double x_TMT_tmp[24];
  double y[24];
  double rom_mass[10];
  double b_Dd[6];
  double b_fg[6];
  double b_in[6];
  double b_kx[6];
  double b_vd[6];
  double c_fg[6];
  double c_in[6];
  double c_kx[6];
  double c_vd[6];
  double d_fg[6];
  double d_in[6];
  double d_kx[6];
  double d_vd[6];
  double e_fg[6];
  double e_in[6];
  double e_kx[6];
  double e_vd[6];
  double f_fg[6];
  double f_in[6];
  double f_vd[6];
  double fg[6];
  double g_fg[6];
  double h_fg[6];
  double i_fg[6];
  double in[6];
  double kx[6];
  double vd[6];
  double a;
  double b_a;
  double b_b_tmp;
  double b_tmp;
  double c_a;
  double c_b_tmp;
  double d;
  double d1;
  double d10;
  double d11;
  double d12;
  double d13;
  double d14;
  double d15;
  double d16;
  double d17;
  double d18;
  double d19;
  double d2;
  double d20;
  double d21;
  double d22;
  double d23;
  double d24;
  double d25;
  double d26;
  double d27;
  double d28;
  double d29;
  double d3;
  double d30;
  double d4;
  double d5;
  double d6;
  double d7;
  double d8;
  double d9;
  double d_a;
  double d_b_tmp;
  double e_b_tmp;
  double f_b_tmp;
  double g_b_tmp;
  double h_b_tmp;
  double i_b_tmp;
  double j_b_tmp;
  double sn;
  int b_sn;
  int i;
  int i1;
  int i2;
  int w_in_tmp;
  b_par_mex = *par_mex;
  dyn_mid_step(t, &b_par_mex);
  romF(b_par_mex.var, rom_mass, rom_sprdmp);
  massF1(b_par_mex.var, z, 1.0E-6 * (rom_mass[5] - rom_mass[0]) + rom_mass[0], M,
         T, Dd, fg);
  for (i = 0; i < 24; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      TMT_tmp[i + 24 * i1] = d;
    }

    for (i1 = 0; i1 < 24; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += TMT_tmp[i + 24 * i2] * T[i2 + 6 * i1];
      }

      TMT[i + 24 * i1] = d;
    }
  }

  b_tmp = rom_mass[5] - rom_mass[0];
  for (i = 0; i < 144; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + fg[i];
  }

  massF2(b_par_mex.var, z, 1.0E-6 * (rom_mass[6] - rom_mass[1]) + rom_mass[1], M,
         T, Dd, fg);
  for (i = 0; i < 24; i++) {
    w_in[i] = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      w_in_tmp = i + 24 * i1;
      w_in[i] += TMT_tmp[w_in_tmp] * b_Dd[i1];
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      TMT_tmp[w_in_tmp] = d;
    }
  }

  b_b_tmp = rom_mass[6] - rom_mass[1];
  for (i = 0; i < 144; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d;
  }

  massF3(b_par_mex.var, z, 1.0E-6 * (rom_mass[7] - rom_mass[2]) + rom_mass[2], M,
         b_T, Dd, b_fg);
  for (i = 0; i < 24; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += b_T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      b_TMT_tmp[i + 24 * i1] = d;
    }
  }

  c_b_tmp = rom_mass[7] - rom_mass[2];
  massF4(b_par_mex.var, z, 1.0E-6 * (rom_mass[8] - rom_mass[3]) + rom_mass[3], M,
         c_T, c_Dd, c_fg);
  for (i = 0; i < 24; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += c_T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      c_TMT_tmp[i + 24 * i1] = d;
    }
  }

  d_b_tmp = rom_mass[8] - rom_mass[3];
  massF5(b_par_mex.var, z, 1.0E-6 * (rom_mass[9] - rom_mass[4]) + rom_mass[4], M,
         d_T, d_Dd, d_fg);
  for (i = 0; i < 24; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += d_T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      d_TMT_tmp[i + 24 * i1] = d;
    }
  }

  e_b_tmp = rom_mass[9] - rom_mass[4];
  sprdmpF25(b_par_mex.var, z, 1.0E-6 * (rom_sprdmp[53] - rom_sprdmp[24]) +
            rom_sprdmp[24], Tt, kx, vd, in, &a);
  for (i = 0; i < 144; i++) {
    Tt[i] *= a;
  }

  f_b_tmp = rom_sprdmp[53] - rom_sprdmp[24];
  for (i = 0; i < 24; i++) {
    d = 0.0;
    d1 = 0.0;
    d2 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d3 = Tt[i + 24 * i1];
      d += d3 * vd[i1];
      d1 += d3 * kx[i1];
      d2 += d3 * in[i1];
    }

    y[i] = d2;
    b_y[i] = d1;
    w_sd[i] = d;
  }

  sprdmpF26(b_par_mex.var, z, 1.0E-6 * (rom_sprdmp[54] - rom_sprdmp[25]) +
            rom_sprdmp[25], Tt, kx, vd, in, &a);
  g_b_tmp = rom_sprdmp[54] - rom_sprdmp[25];
  sprdmpF27(b_par_mex.var, z, 1.0E-6 * (rom_sprdmp[55] - rom_sprdmp[26]) +
            rom_sprdmp[26], b_Tt, b_kx, b_vd, b_in, &sn);
  h_b_tmp = rom_sprdmp[55] - rom_sprdmp[26];
  sprdmpF28(b_par_mex.var, z, 1.0E-6 * (rom_sprdmp[56] - rom_sprdmp[27]) +
            rom_sprdmp[27], c_Tt, c_kx, c_vd, c_in, &b_a);
  i_b_tmp = rom_sprdmp[56] - rom_sprdmp[27];
  sprdmpF29(b_par_mex.var, z, 1.0E-6 * (rom_sprdmp[57] - rom_sprdmp[28]) +
            rom_sprdmp[28], d_Tt, d_kx, d_vd, d_in, &c_a);
  for (i = 0; i < 144; i++) {
    Tt[i] *= a;
    b_Tt[i] *= sn;
    c_Tt[i] *= b_a;
    d_Tt[i] *= c_a;
  }

  j_b_tmp = rom_sprdmp[57] - rom_sprdmp[28];
  massF1(b_par_mex.var, z, 0.999999 * (rom_mass[5] - rom_mass[0]) + rom_mass[0],
         M, e_T, e_Dd, e_fg);
  for (i = 0; i < 24; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += e_T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      e_TMT_tmp[i + 24 * i1] = d;
    }
  }

  massF2(b_par_mex.var, z, 0.999999 * (rom_mass[6] - rom_mass[1]) + rom_mass[1],
         M, f_T, f_Dd, f_fg);
  for (i = 0; i < 24; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += f_T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      f_TMT_tmp[i + 24 * i1] = d;
    }
  }

  massF3(b_par_mex.var, z, 0.999999 * (rom_mass[7] - rom_mass[2]) + rom_mass[2],
         M, g_T, g_Dd, g_fg);
  for (i = 0; i < 24; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += g_T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      g_TMT_tmp[i + 24 * i1] = d;
    }
  }

  massF4(b_par_mex.var, z, 0.999999 * (rom_mass[8] - rom_mass[3]) + rom_mass[3],
         M, h_T, h_Dd, h_fg);
  for (i = 0; i < 24; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += h_T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      q_TMT_tmp[i + 24 * i1] = d;
    }
  }

  massF5(b_par_mex.var, z, 0.999999 * (rom_mass[9] - rom_mass[4]) + rom_mass[4],
         M, i_T, i_Dd, i_fg);
  for (i = 0; i < 24; i++) {
    for (i1 = 0; i1 < 6; i1++) {
      d = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d += i_T[i2 + 6 * i] * M[i2 + 6 * i1];
      }

      r_TMT_tmp[i + 24 * i1] = d;
    }

    for (i1 = 0; i1 < 24; i1++) {
      d = 0.0;
      d1 = 0.0;
      d2 = 0.0;
      d3 = 0.0;
      b_a = 0.0;
      c_a = 0.0;
      d_a = 0.0;
      a = 0.0;
      sn = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        w_in_tmp = i + 24 * i2;
        b_sn = i2 + 6 * i1;
        d += TMT_tmp[w_in_tmp] * T[b_sn];
        d1 += b_TMT_tmp[w_in_tmp] * b_T[b_sn];
        d2 += c_TMT_tmp[w_in_tmp] * c_T[b_sn];
        d3 += d_TMT_tmp[w_in_tmp] * d_T[b_sn];
        b_a += e_TMT_tmp[w_in_tmp] * e_T[b_sn];
        c_a += f_TMT_tmp[w_in_tmp] * f_T[b_sn];
        d_a += g_TMT_tmp[w_in_tmp] * g_T[b_sn];
        a += q_TMT_tmp[w_in_tmp] * h_T[b_sn];
        sn += r_TMT_tmp[w_in_tmp] * i_T[b_sn];
      }

      w_in_tmp = i + 24 * i1;
      p_TMT_tmp[w_in_tmp] = sn;
      o_TMT_tmp[w_in_tmp] = a;
      n_TMT_tmp[w_in_tmp] = d_a;
      m_TMT_tmp[w_in_tmp] = c_a;
      l_TMT_tmp[w_in_tmp] = b_a;
      k_TMT_tmp[w_in_tmp] = d3;
      j_TMT_tmp[w_in_tmp] = d2;
      i_TMT_tmp[w_in_tmp] = d1;
      h_TMT_tmp[w_in_tmp] = d;
    }
  }

  for (i = 0; i < 576; i++) {
    TMT[i] = ((((((((TMT[i] * b_tmp + h_TMT_tmp[i] * b_b_tmp) + i_TMT_tmp[i] *
                    c_b_tmp) + j_TMT_tmp[i] * d_b_tmp) + k_TMT_tmp[i] * e_b_tmp)
                 + l_TMT_tmp[i] * b_tmp) + m_TMT_tmp[i] * b_b_tmp) + n_TMT_tmp[i]
               * c_b_tmp) + o_TMT_tmp[i] * d_b_tmp) + p_TMT_tmp[i] * e_b_tmp;
  }

  for (i = 0; i < 6; i++) {
    b_Dd[i] += fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += TMT_tmp[i + 24 * i1] * b_Dd[i1];
    }

    TMfd[i] = d;
  }

  for (i = 0; i < 144; i++) {
    Dd[i] = -Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + b_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += b_TMT_tmp[i + 24 * i1] * b_Dd[i1];
    }

    s_TMT_tmp[i] = d;
  }

  for (i = 0; i < 144; i++) {
    c_Dd[i] = -c_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += c_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + c_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += c_TMT_tmp[i + 24 * i1] * b_Dd[i1];
    }

    w_vd_j[i] = d;
  }

  for (i = 0; i < 144; i++) {
    d_Dd[i] = -d_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += d_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + d_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += d_TMT_tmp[i + 24 * i1] * b_Dd[i1];
    }

    t_TMT_tmp[i] = d;
  }

  for (i = 0; i < 144; i++) {
    e_Dd[i] = -e_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += e_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + e_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += e_TMT_tmp[i + 24 * i1] * b_Dd[i1];
    }

    u_TMT_tmp[i] = d;
  }

  for (i = 0; i < 144; i++) {
    f_Dd[i] = -f_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += f_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + f_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += f_TMT_tmp[i + 24 * i1] * b_Dd[i1];
    }

    v_TMT_tmp[i] = d;
  }

  for (i = 0; i < 144; i++) {
    g_Dd[i] = -g_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += g_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + g_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += g_TMT_tmp[i + 24 * i1] * b_Dd[i1];
    }

    w_TMT_tmp[i] = d;
  }

  for (i = 0; i < 144; i++) {
    h_Dd[i] = -h_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += h_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + h_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += q_TMT_tmp[i + 24 * i1] * b_Dd[i1];
    }

    x_TMT_tmp[i] = d;
  }

  for (i = 0; i < 144; i++) {
    i_Dd[i] = -i_Dd[i];
  }

  for (i = 0; i < 6; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += i_Dd[i + 6 * i1] * z[i1 + 24];
    }

    b_Dd[i] = d + i_fg[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d += r_TMT_tmp[i + 24 * i1] * b_Dd[i1];
    }

    TMfd[i] = ((((((((w_in[i] * b_tmp + TMfd[i] * b_b_tmp) + s_TMT_tmp[i] *
                     c_b_tmp) + w_vd_j[i] * d_b_tmp) + t_TMT_tmp[i] * e_b_tmp) +
                  u_TMT_tmp[i] * b_tmp) + v_TMT_tmp[i] * b_b_tmp) + w_TMT_tmp[i]
                * c_b_tmp) + x_TMT_tmp[i] * d_b_tmp) + d * e_b_tmp;
  }

  sprdmpF25(b_par_mex.var, z, 0.999999 * (rom_sprdmp[53] - rom_sprdmp[24]) +
            rom_sprdmp[24], T, fg, b_Dd, b_fg, &a);
  sprdmpF26(b_par_mex.var, z, 0.999999 * (rom_sprdmp[54] - rom_sprdmp[25]) +
            rom_sprdmp[25], Dd, c_fg, d_fg, e_fg, &sn);
  sprdmpF27(b_par_mex.var, z, 0.999999 * (rom_sprdmp[55] - rom_sprdmp[26]) +
            rom_sprdmp[26], TMT_tmp, f_fg, g_fg, h_fg, &b_a);
  sprdmpF28(b_par_mex.var, z, 0.999999 * (rom_sprdmp[56] - rom_sprdmp[27]) +
            rom_sprdmp[27], b_T, i_fg, e_vd, e_in, &c_a);
  sprdmpF29(b_par_mex.var, z, 0.999999 * (rom_sprdmp[57] - rom_sprdmp[28]) +
            rom_sprdmp[28], b_TMT_tmp, e_kx, f_vd, f_in, &d_a);
  for (i = 0; i < 144; i++) {
    T[i] *= a;
    Dd[i] *= sn;
    TMT_tmp[i] *= b_a;
    b_T[i] *= c_a;
    b_TMT_tmp[i] *= d_a;
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    d1 = 0.0;
    d2 = 0.0;
    d3 = 0.0;
    b_a = 0.0;
    c_a = 0.0;
    d_a = 0.0;
    a = 0.0;
    sn = 0.0;
    d4 = 0.0;
    d5 = 0.0;
    d6 = 0.0;
    d7 = 0.0;
    d8 = 0.0;
    d9 = 0.0;
    d10 = 0.0;
    d11 = 0.0;
    d12 = 0.0;
    d13 = 0.0;
    d14 = 0.0;
    d15 = 0.0;
    d16 = 0.0;
    d17 = 0.0;
    d18 = 0.0;
    d19 = 0.0;
    d20 = 0.0;
    d21 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i + 24 * i1;
      d22 = Tt[i2];
      d += d22 * vd[i1];
      d23 = b_Tt[i2];
      d1 += d23 * b_vd[i1];
      d24 = c_Tt[i2];
      d2 += d24 * c_vd[i1];
      d25 = d_Tt[i2];
      d3 += d25 * d_vd[i1];
      d26 = T[i2];
      b_a += d26 * b_Dd[i1];
      d27 = Dd[i2];
      c_a += d27 * d_fg[i1];
      d28 = TMT_tmp[i2];
      d_a += d28 * g_fg[i1];
      d29 = b_T[i2];
      a += d29 * e_vd[i1];
      d30 = b_TMT_tmp[i2];
      sn += d30 * f_vd[i1];
      d4 += d22 * kx[i1];
      d5 += d23 * b_kx[i1];
      d6 += d24 * c_kx[i1];
      d7 += d25 * d_kx[i1];
      d8 += d26 * fg[i1];
      d9 += d27 * c_fg[i1];
      d10 += d28 * f_fg[i1];
      d11 += d29 * i_fg[i1];
      d12 += d30 * e_kx[i1];
      d13 += d22 * in[i1];
      d14 += d23 * b_in[i1];
      d15 += d24 * c_in[i1];
      d16 += d25 * d_in[i1];
      d17 += d26 * b_fg[i1];
      d18 += d27 * e_fg[i1];
      d19 += d28 * h_fg[i1];
      d20 += d29 * e_in[i1];
      d21 += d30 * f_in[i1];
    }

    w_vd_j[i] = ((((((((w_sd[i] * f_b_tmp + d * g_b_tmp) + d1 * h_b_tmp) + d2 *
                      i_b_tmp) + d3 * j_b_tmp) + b_a * f_b_tmp) + c_a * g_b_tmp)
                  + d_a * h_b_tmp) + a * i_b_tmp) + sn * j_b_tmp;
    w_sd[i] = ((((((((b_y[i] * f_b_tmp + d4 * g_b_tmp) + d5 * h_b_tmp) + d6 *
                    i_b_tmp) + d7 * j_b_tmp) + d8 * f_b_tmp) + d9 * g_b_tmp) +
                d10 * h_b_tmp) + d11 * i_b_tmp) + d12 * j_b_tmp;
    w_in[i] = ((((((((y[i] * f_b_tmp + d13 * g_b_tmp) + d14 * h_b_tmp) + d15 *
                    i_b_tmp) + d16 * j_b_tmp) + d17 * f_b_tmp) + d18 * g_b_tmp)
                + d19 * h_b_tmp) + d20 * i_b_tmp) + d21 * j_b_tmp;
  }

  for (i = 0; i < 576; i++) {
    TMT[i] /= 2.0;
  }

  for (i = 0; i < 24; i++) {
    TMfd[i] /= 2.0;
    w_vd_j[i] /= 2.0;
    w_sd[i] /= 2.0;
    w_in[i] /= 2.0;
  }

  for (b_sn = 0; b_sn < 9; b_sn++) {
    sn = (double)b_sn * 0.1 + 0.100001;
    massF1(b_par_mex.var, z, sn * (rom_mass[5] - rom_mass[0]) + rom_mass[0], M,
           T, Dd, fg);
    for (i = 0; i < 24; i++) {
      for (i1 = 0; i1 < 6; i1++) {
        d = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d += T[i2 + 6 * i] * M[i2 + 6 * i1];
        }

        TMT_tmp[i + 24 * i1] = d;
      }

      for (i1 = 0; i1 < 24; i1++) {
        d = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d += TMT_tmp[i + 24 * i2] * T[i2 + 6 * i1];
        }

        h_TMT_tmp[i + 24 * i1] = d;
      }
    }

    for (i = 0; i < 576; i++) {
      TMT[i] += h_TMT_tmp[i] * b_tmp;
    }

    for (i = 0; i < 144; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 24; i1++) {
        d += Dd[i + 6 * i1] * z[i1 + 24];
      }

      b_Dd[i] = d + fg[i];
    }

    massF2(b_par_mex.var, z, sn * (rom_mass[6] - rom_mass[1]) + rom_mass[1], M,
           T, Dd, fg);
    for (i = 0; i < 24; i++) {
      s_TMT_tmp[i] = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        w_in_tmp = i + 24 * i1;
        s_TMT_tmp[i] += TMT_tmp[w_in_tmp] * b_Dd[i1];
        d = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d += T[i2 + 6 * i] * M[i2 + 6 * i1];
        }

        TMT_tmp[w_in_tmp] = d;
      }

      TMfd[i] += s_TMT_tmp[i] * b_tmp;
      for (i1 = 0; i1 < 24; i1++) {
        d = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d += TMT_tmp[i + 24 * i2] * T[i2 + 6 * i1];
        }

        h_TMT_tmp[i + 24 * i1] = d;
      }
    }

    for (i = 0; i < 576; i++) {
      TMT[i] += h_TMT_tmp[i] * b_b_tmp;
    }

    for (i = 0; i < 144; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 24; i1++) {
        d += Dd[i + 6 * i1] * z[i1 + 24];
      }

      b_Dd[i] = d + fg[i];
    }

    massF3(b_par_mex.var, z, sn * (rom_mass[7] - rom_mass[2]) + rom_mass[2], M,
           T, Dd, fg);
    for (i = 0; i < 24; i++) {
      s_TMT_tmp[i] = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        w_in_tmp = i + 24 * i1;
        s_TMT_tmp[i] += TMT_tmp[w_in_tmp] * b_Dd[i1];
        d = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d += T[i2 + 6 * i] * M[i2 + 6 * i1];
        }

        TMT_tmp[w_in_tmp] = d;
      }

      TMfd[i] += s_TMT_tmp[i] * b_b_tmp;
      for (i1 = 0; i1 < 24; i1++) {
        d = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d += TMT_tmp[i + 24 * i2] * T[i2 + 6 * i1];
        }

        h_TMT_tmp[i + 24 * i1] = d;
      }
    }

    for (i = 0; i < 576; i++) {
      TMT[i] += h_TMT_tmp[i] * c_b_tmp;
    }

    for (i = 0; i < 144; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 24; i1++) {
        d += Dd[i + 6 * i1] * z[i1 + 24];
      }

      b_Dd[i] = d + fg[i];
    }

    massF4(b_par_mex.var, z, sn * (rom_mass[8] - rom_mass[3]) + rom_mass[3], M,
           T, Dd, fg);
    for (i = 0; i < 24; i++) {
      s_TMT_tmp[i] = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        w_in_tmp = i + 24 * i1;
        s_TMT_tmp[i] += TMT_tmp[w_in_tmp] * b_Dd[i1];
        d = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d += T[i2 + 6 * i] * M[i2 + 6 * i1];
        }

        TMT_tmp[w_in_tmp] = d;
      }

      TMfd[i] += s_TMT_tmp[i] * c_b_tmp;
      for (i1 = 0; i1 < 24; i1++) {
        d = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d += TMT_tmp[i + 24 * i2] * T[i2 + 6 * i1];
        }

        h_TMT_tmp[i + 24 * i1] = d;
      }
    }

    for (i = 0; i < 576; i++) {
      TMT[i] += h_TMT_tmp[i] * d_b_tmp;
    }

    for (i = 0; i < 144; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 24; i1++) {
        d += Dd[i + 6 * i1] * z[i1 + 24];
      }

      b_Dd[i] = d + fg[i];
    }

    massF5(b_par_mex.var, z, sn * (rom_mass[9] - rom_mass[4]) + rom_mass[4], M,
           T, Dd, fg);
    for (i = 0; i < 24; i++) {
      s_TMT_tmp[i] = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        w_in_tmp = i + 24 * i1;
        s_TMT_tmp[i] += TMT_tmp[w_in_tmp] * b_Dd[i1];
        d = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d += T[i2 + 6 * i] * M[i2 + 6 * i1];
        }

        TMT_tmp[w_in_tmp] = d;
      }

      TMfd[i] += s_TMT_tmp[i] * d_b_tmp;
      for (i1 = 0; i1 < 24; i1++) {
        d = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d += TMT_tmp[i + 24 * i2] * T[i2 + 6 * i1];
        }

        h_TMT_tmp[i + 24 * i1] = d;
      }
    }

    for (i = 0; i < 576; i++) {
      TMT[i] += h_TMT_tmp[i] * e_b_tmp;
    }

    for (i = 0; i < 144; i++) {
      Dd[i] = -Dd[i];
    }

    for (i = 0; i < 6; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 24; i1++) {
        d += Dd[i + 6 * i1] * z[i1 + 24];
      }

      b_Dd[i] = d + fg[i];
    }

    for (i = 0; i < 24; i++) {
      d = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d += TMT_tmp[i + 24 * i1] * b_Dd[i1];
      }

      TMfd[i] += d * e_b_tmp;
    }

    sprdmpF25(b_par_mex.var, z, sn * (rom_sprdmp[53] - rom_sprdmp[24]) +
              rom_sprdmp[24], Tt, kx, vd, in, &a);
    for (i = 0; i < 144; i++) {
      Tt[i] *= a;
    }

    for (i = 0; i < 24; i++) {
      d = 0.0;
      d1 = 0.0;
      d2 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d3 = Tt[i + 24 * i1];
        d += d3 * vd[i1];
        d1 += d3 * kx[i1];
        d2 += d3 * in[i1];
      }

      w_vd_j[i] += d * f_b_tmp;
      w_sd[i] += d1 * f_b_tmp;
      w_in[i] += d2 * f_b_tmp;
    }

    sprdmpF26(b_par_mex.var, z, sn * (rom_sprdmp[54] - rom_sprdmp[25]) +
              rom_sprdmp[25], Tt, kx, vd, in, &a);
    for (i = 0; i < 144; i++) {
      Tt[i] *= a;
    }

    for (i = 0; i < 24; i++) {
      d = 0.0;
      d1 = 0.0;
      d2 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d3 = Tt[i + 24 * i1];
        d += d3 * vd[i1];
        d1 += d3 * kx[i1];
        d2 += d3 * in[i1];
      }

      w_vd_j[i] += d * g_b_tmp;
      w_sd[i] += d1 * g_b_tmp;
      w_in[i] += d2 * g_b_tmp;
    }

    sprdmpF27(b_par_mex.var, z, sn * (rom_sprdmp[55] - rom_sprdmp[26]) +
              rom_sprdmp[26], Tt, kx, vd, in, &a);
    for (i = 0; i < 144; i++) {
      Tt[i] *= a;
    }

    for (i = 0; i < 24; i++) {
      d = 0.0;
      d1 = 0.0;
      d2 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d3 = Tt[i + 24 * i1];
        d += d3 * vd[i1];
        d1 += d3 * kx[i1];
        d2 += d3 * in[i1];
      }

      w_vd_j[i] += d * h_b_tmp;
      w_sd[i] += d1 * h_b_tmp;
      w_in[i] += d2 * h_b_tmp;
    }

    sprdmpF28(b_par_mex.var, z, sn * (rom_sprdmp[56] - rom_sprdmp[27]) +
              rom_sprdmp[27], Tt, kx, vd, in, &a);
    for (i = 0; i < 144; i++) {
      Tt[i] *= a;
    }

    for (i = 0; i < 24; i++) {
      d = 0.0;
      d1 = 0.0;
      d2 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d3 = Tt[i + 24 * i1];
        d += d3 * vd[i1];
        d1 += d3 * kx[i1];
        d2 += d3 * in[i1];
      }

      w_vd_j[i] += d * i_b_tmp;
      w_sd[i] += d1 * i_b_tmp;
      w_in[i] += d2 * i_b_tmp;
    }

    sprdmpF29(b_par_mex.var, z, sn * (rom_sprdmp[57] - rom_sprdmp[28]) +
              rom_sprdmp[28], Tt, kx, vd, in, &a);
    for (i = 0; i < 144; i++) {
      Tt[i] *= a;
    }

    for (i = 0; i < 24; i++) {
      d = 0.0;
      d1 = 0.0;
      d2 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d3 = Tt[i + 24 * i1];
        d += d3 * vd[i1];
        d1 += d3 * kx[i1];
        d2 += d3 * in[i1];
      }

      w_vd_j[i] += d * j_b_tmp;
      w_sd[i] += d1 * j_b_tmp;
      w_in[i] += d2 * j_b_tmp;
    }
  }

  for (i = 0; i < 24; i++) {
    TMfd[i] /= 10.0;
    w_vd_j[i] /= 10.0;
    w_sd[i] /= 10.0;
    w_in[i] /= 10.0;
  }

  /*  EOM */
  for (i = 0; i < 576; i++) {
    h_TMT_tmp[i] = TMT[i] / 10.0;
  }

  pinv(h_TMT_tmp, TMT);
  for (i = 0; i < 24; i++) {
    TMfd[i] = ((TMfd[i] + w_sd[i]) + w_in[i]) + w_vd_j[i];
  }

  for (i = 0; i < 24; i++) {
    d = 0.0;
    for (i1 = 0; i1 < 24; i1++) {
      d += TMT[i + 24 * i1] * TMfd[i1];
    }

    dz[i] = z[i + 24];
    dz[i + 24] = d;
  }

  *flag = 0.0;
}

/*
 * File trailer for EOM.c
 *
 * [EOF]
 */
