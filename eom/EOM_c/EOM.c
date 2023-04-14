/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 * File: EOM.c
 *
 * MATLAB Coder version            : 4.2
 * C/C++ source code generated on  : 14-Oct-2020 16:42:47
 */

/* Include Files */
#include "EOM.h"
#include "EOM_input.h"
#include "pinv.h"
#include "loadsF1.h"
#include "sprdmpF34.h"
#include "sprdmpF33.h"
#include "massF2.h"
#include "massF1.h"
#include "romF.h"
#include "dyn_mid_step.h"

/* Function Definitions */

/*
 * Arguments    : double t
 *                const double z[64]
 *                const struct0_T *par_mex
 *                double dz[64]
 *                double *flag
 * Return Type  : void
 */
void EOM(double t, const double z[64], const struct0_T *par_mex, double dz[64],
         double *flag)
{
  struct0_T b_par_mex;
  double rom_mass[4];
  double rom_sprdmp[68];
  double M[36];
  double T[192];
  double Dd[192];
  double fg[6];
  int i0;
  double b_tmp;
  int i1;
  double d0;
  int i2;
  double TMT_tmp[192];
  double TMT[1024];
  double b_b_tmp;
  double w_in[32];
  double b_Dd[6];
  int w_in_tmp;
  double Tt[192];
  double kx[6];
  double vd[6];
  double in[6];
  double a;
  double c_b_tmp;
  double y[32];
  double b_y[32];
  double d_b_tmp;
  double d1;
  double b_T[192];
  double b_fg[6];
  double d2;
  double c_T[192];
  double c_Dd[192];
  double c_fg[6];
  double w_sd[32];
  double b_Tt[192];
  double b_kx[6];
  double b_vd[6];
  double b_in[6];
  double c_Tt[192];
  double c_kx[6];
  double c_vd[6];
  double c_in[6];
  double sn;
  double b_TMT_tmp[192];
  double c_TMT_tmp[192];
  double d_TMT_tmp[1024];
  double e_TMT_tmp[1024];
  double f_TMT_tmp[1024];
  int TMT_tmp_tmp;
  double TMfd[32];
  int i3;
  double g_TMT_tmp[32];
  double w_vd_j[32];
  b_par_mex = *par_mex;
  dyn_mid_step(t, &b_par_mex);
  romF(b_par_mex.var, rom_mass, rom_sprdmp);
  massF1(b_par_mex.var, z, rom_mass[0], M, T, Dd, fg);
  for (i0 = 0; i0 < 32; i0++) {
    for (i1 = 0; i1 < 6; i1++) {
      d0 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d0 += T[i2 + 6 * i0] * M[i2 + 6 * i1];
      }

      TMT_tmp[i0 + (i1 << 5)] = d0;
    }

    for (i1 = 0; i1 < 32; i1++) {
      d0 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d0 += TMT_tmp[i0 + (i2 << 5)] * T[i2 + 6 * i1];
      }

      TMT[i0 + (i1 << 5)] = d0;
    }
  }

  b_tmp = rom_mass[2] - rom_mass[0];
  for (i0 = 0; i0 < 192; i0++) {
    Dd[i0] = -Dd[i0];
  }

  for (i0 = 0; i0 < 6; i0++) {
    d0 = 0.0;
    for (i1 = 0; i1 < 32; i1++) {
      d0 += Dd[i0 + 6 * i1] * z[32 + i1];
    }

    b_Dd[i0] = d0 + fg[i0];
  }

  massF2(b_par_mex.var, z, rom_mass[1], M, T, Dd, fg);
  for (i0 = 0; i0 < 32; i0++) {
    w_in[i0] = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      w_in_tmp = i0 + (i1 << 5);
      w_in[i0] += TMT_tmp[w_in_tmp] * b_Dd[i1];
      d0 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d0 += T[i2 + 6 * i0] * M[i2 + 6 * i1];
      }

      TMT_tmp[w_in_tmp] = d0;
    }
  }

  b_b_tmp = rom_mass[3] - rom_mass[1];
  for (i0 = 0; i0 < 192; i0++) {
    Dd[i0] = -Dd[i0];
  }

  for (i0 = 0; i0 < 6; i0++) {
    d0 = 0.0;
    for (i1 = 0; i1 < 32; i1++) {
      d0 += Dd[i0 + 6 * i1] * z[32 + i1];
    }

    b_Dd[i0] = d0;
  }

  sprdmpF33(b_par_mex.var, z, rom_sprdmp[32], Tt, kx, vd, in, &a);
  for (i0 = 0; i0 < 192; i0++) {
    Tt[i0] *= a;
  }

  c_b_tmp = rom_sprdmp[66] - rom_sprdmp[32];
  for (i0 = 0; i0 < 32; i0++) {
    y[i0] = 0.0;
    b_y[i0] = 0.0;
    d0 = 0.0;
    d1 = 0.0;
    d2 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      a = Tt[i0 + (i1 << 5)];
      d0 += a * vd[i1];
      d1 += a * kx[i1];
      d2 += a * in[i1];
    }

    b_y[i0] = d2;
    y[i0] = d1;
    w_sd[i0] = d0;
  }

  sprdmpF34(b_par_mex.var, z, rom_sprdmp[33], Tt, kx, vd, in, &a);
  for (i0 = 0; i0 < 192; i0++) {
    Tt[i0] *= a;
  }

  d_b_tmp = rom_sprdmp[67] - rom_sprdmp[33];
  massF1(b_par_mex.var, z, (rom_mass[2] - rom_mass[0]) + rom_mass[0], M, b_T, Dd,
         b_fg);
  for (i0 = 0; i0 < 32; i0++) {
    for (i1 = 0; i1 < 6; i1++) {
      d0 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d0 += b_T[i2 + 6 * i0] * M[i2 + 6 * i1];
      }

      b_TMT_tmp[i0 + (i1 << 5)] = d0;
    }
  }

  massF2(b_par_mex.var, z, (rom_mass[3] - rom_mass[1]) + rom_mass[1], M, c_T,
         c_Dd, c_fg);
  for (i0 = 0; i0 < 32; i0++) {
    for (i1 = 0; i1 < 6; i1++) {
      d0 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        d0 += c_T[i2 + 6 * i0] * M[i2 + 6 * i1];
      }

      c_TMT_tmp[i0 + (i1 << 5)] = d0;
    }
  }

  sprdmpF33(b_par_mex.var, z, (rom_sprdmp[66] - rom_sprdmp[32]) + rom_sprdmp[32],
            b_Tt, b_kx, b_vd, b_in, &a);
  sprdmpF34(b_par_mex.var, z, (rom_sprdmp[67] - rom_sprdmp[33]) + rom_sprdmp[33],
            c_Tt, c_kx, c_vd, c_in, &sn);
  for (i0 = 0; i0 < 192; i0++) {
    b_Tt[i0] *= a;
    c_Tt[i0] *= sn;
  }

  for (i0 = 0; i0 < 32; i0++) {
    for (i1 = 0; i1 < 32; i1++) {
      TMT_tmp_tmp = i0 + (i1 << 5);
      e_TMT_tmp[TMT_tmp_tmp] = 0.0;
      f_TMT_tmp[TMT_tmp_tmp] = 0.0;
      d0 = 0.0;
      d1 = 0.0;
      d2 = 0.0;
      for (i2 = 0; i2 < 6; i2++) {
        w_in_tmp = i0 + (i2 << 5);
        i3 = i2 + 6 * i1;
        d0 += TMT_tmp[w_in_tmp] * T[i3];
        d1 += b_TMT_tmp[w_in_tmp] * b_T[i3];
        d2 += c_TMT_tmp[w_in_tmp] * c_T[i3];
      }

      f_TMT_tmp[TMT_tmp_tmp] = d2;
      e_TMT_tmp[TMT_tmp_tmp] = d1;
      d_TMT_tmp[TMT_tmp_tmp] = d0;
    }
  }

  for (i0 = 0; i0 < 1024; i0++) {
    TMT[i0] = (((TMT[i0] * b_tmp + d_TMT_tmp[i0] * b_b_tmp) + e_TMT_tmp[i0] *
                b_tmp) + f_TMT_tmp[i0] * b_b_tmp) / 2.0;
  }

  for (i0 = 0; i0 < 6; i0++) {
    b_Dd[i0] += fg[i0];
  }

  for (i0 = 0; i0 < 32; i0++) {
    d0 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d0 += TMT_tmp[i0 + (i1 << 5)] * b_Dd[i1];
    }

    TMfd[i0] = d0;
  }

  for (i0 = 0; i0 < 192; i0++) {
    Dd[i0] = -Dd[i0];
  }

  for (i0 = 0; i0 < 6; i0++) {
    d0 = 0.0;
    for (i1 = 0; i1 < 32; i1++) {
      d0 += Dd[i0 + 6 * i1] * z[32 + i1];
    }

    b_Dd[i0] = d0 + b_fg[i0];
  }

  for (i0 = 0; i0 < 32; i0++) {
    d0 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d0 += b_TMT_tmp[i0 + (i1 << 5)] * b_Dd[i1];
    }

    g_TMT_tmp[i0] = d0;
  }

  for (i0 = 0; i0 < 192; i0++) {
    c_Dd[i0] = -c_Dd[i0];
  }

  for (i0 = 0; i0 < 6; i0++) {
    d0 = 0.0;
    for (i1 = 0; i1 < 32; i1++) {
      d0 += c_Dd[i0 + 6 * i1] * z[32 + i1];
    }

    b_Dd[i0] = d0 + c_fg[i0];
  }

  for (i0 = 0; i0 < 32; i0++) {
    d0 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      d0 += c_TMT_tmp[i0 + (i1 << 5)] * b_Dd[i1];
    }

    TMfd[i0] = (((w_in[i0] * b_tmp + TMfd[i0] * b_b_tmp) + g_TMT_tmp[i0] * b_tmp)
                + d0 * b_b_tmp) / 2.0;
  }

  for (i0 = 0; i0 < 32; i0++) {
    d0 = 0.0;
    d1 = 0.0;
    d2 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i0 + (i1 << 5);
      d0 += Tt[i2] * vd[i1];
      d1 += b_Tt[i2] * b_vd[i1];
      d2 += c_Tt[i2] * c_vd[i1];
    }

    w_vd_j[i0] = (((w_sd[i0] * c_b_tmp + d0 * d_b_tmp) + d1 * c_b_tmp) + d2 *
                  d_b_tmp) / 2.0;
    d0 = 0.0;
    d1 = 0.0;
    d2 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i0 + (i1 << 5);
      d0 += Tt[i2] * kx[i1];
      d1 += b_Tt[i2] * b_kx[i1];
      d2 += c_Tt[i2] * c_kx[i1];
    }

    w_sd[i0] = (((y[i0] * c_b_tmp + d0 * d_b_tmp) + d1 * c_b_tmp) + d2 * d_b_tmp)
      / 2.0;
    d0 = 0.0;
    d1 = 0.0;
    d2 = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      i2 = i0 + (i1 << 5);
      d0 += Tt[i2] * in[i1];
      d1 += b_Tt[i2] * b_in[i1];
      d2 += c_Tt[i2] * c_in[i1];
    }

    w_in[i0] = (((b_y[i0] * c_b_tmp + d0 * d_b_tmp) + d1 * c_b_tmp) + d2 *
                d_b_tmp) / 2.0;
  }

  for (w_in_tmp = 0; w_in_tmp < 19; w_in_tmp++) {
    sn = 0.050001000000000004 + (double)w_in_tmp * 0.05;
    massF1(b_par_mex.var, z, sn * (rom_mass[2] - rom_mass[0]) + rom_mass[0], M,
           T, Dd, fg);
    for (i0 = 0; i0 < 32; i0++) {
      for (i1 = 0; i1 < 6; i1++) {
        d0 = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d0 += T[i2 + 6 * i0] * M[i2 + 6 * i1];
        }

        TMT_tmp[i0 + (i1 << 5)] = d0;
      }

      for (i1 = 0; i1 < 32; i1++) {
        d0 = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d0 += TMT_tmp[i0 + (i2 << 5)] * T[i2 + 6 * i1];
        }

        d_TMT_tmp[i0 + (i1 << 5)] = d0;
      }
    }

    for (i0 = 0; i0 < 1024; i0++) {
      TMT[i0] += d_TMT_tmp[i0] * b_tmp;
    }

    for (i0 = 0; i0 < 192; i0++) {
      Dd[i0] = -Dd[i0];
    }

    for (i0 = 0; i0 < 6; i0++) {
      d0 = 0.0;
      for (i1 = 0; i1 < 32; i1++) {
        d0 += Dd[i0 + 6 * i1] * z[32 + i1];
      }

      b_Dd[i0] = d0 + fg[i0];
    }

    massF2(b_par_mex.var, z, sn * (rom_mass[3] - rom_mass[1]) + rom_mass[1], M,
           T, Dd, fg);
    for (i0 = 0; i0 < 32; i0++) {
      g_TMT_tmp[i0] = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        TMT_tmp_tmp = i0 + (i1 << 5);
        g_TMT_tmp[i0] += TMT_tmp[TMT_tmp_tmp] * b_Dd[i1];
        d0 = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d0 += T[i2 + 6 * i0] * M[i2 + 6 * i1];
        }

        TMT_tmp[TMT_tmp_tmp] = d0;
      }

      TMfd[i0] += g_TMT_tmp[i0] * b_tmp;
      for (i1 = 0; i1 < 32; i1++) {
        d0 = 0.0;
        for (i2 = 0; i2 < 6; i2++) {
          d0 += TMT_tmp[i0 + (i2 << 5)] * T[i2 + 6 * i1];
        }

        d_TMT_tmp[i0 + (i1 << 5)] = d0;
      }
    }

    for (i0 = 0; i0 < 1024; i0++) {
      TMT[i0] += d_TMT_tmp[i0] * b_b_tmp;
    }

    for (i0 = 0; i0 < 192; i0++) {
      Dd[i0] = -Dd[i0];
    }

    for (i0 = 0; i0 < 6; i0++) {
      d0 = 0.0;
      for (i1 = 0; i1 < 32; i1++) {
        d0 += Dd[i0 + 6 * i1] * z[32 + i1];
      }

      b_Dd[i0] = d0 + fg[i0];
    }

    for (i0 = 0; i0 < 32; i0++) {
      d0 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d0 += TMT_tmp[i0 + (i1 << 5)] * b_Dd[i1];
      }

      TMfd[i0] += d0 * b_b_tmp;
    }

    sprdmpF33(b_par_mex.var, z, sn * (rom_sprdmp[66] - rom_sprdmp[32]) +
              rom_sprdmp[32], Tt, kx, vd, in, &a);
    for (i0 = 0; i0 < 192; i0++) {
      Tt[i0] *= a;
    }

    for (i0 = 0; i0 < 32; i0++) {
      d0 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d0 += Tt[i0 + (i1 << 5)] * vd[i1];
      }

      w_vd_j[i0] += d0 * c_b_tmp;
      d0 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d0 += Tt[i0 + (i1 << 5)] * kx[i1];
      }

      w_sd[i0] += d0 * c_b_tmp;
      d0 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d0 += Tt[i0 + (i1 << 5)] * in[i1];
      }

      w_in[i0] += d0 * c_b_tmp;
    }

    sprdmpF34(b_par_mex.var, z, sn * (rom_sprdmp[67] - rom_sprdmp[33]) +
              rom_sprdmp[33], Tt, kx, vd, in, &a);
    for (i0 = 0; i0 < 192; i0++) {
      Tt[i0] *= a;
    }

    for (i0 = 0; i0 < 32; i0++) {
      d0 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d0 += Tt[i0 + (i1 << 5)] * vd[i1];
      }

      w_vd_j[i0] += d0 * d_b_tmp;
      d0 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d0 += Tt[i0 + (i1 << 5)] * kx[i1];
      }

      w_sd[i0] += d0 * d_b_tmp;
      d0 = 0.0;
      for (i1 = 0; i1 < 6; i1++) {
        d0 += Tt[i0 + (i1 << 5)] * in[i1];
      }

      w_in[i0] += d0 * d_b_tmp;
    }
  }

  for (i0 = 0; i0 < 1024; i0++) {
    d_TMT_tmp[i0] = TMT[i0] / 20.0;
  }

  loadsF1(b_par_mex.var, z, T, fg);

  /*  EOM */
  for (i0 = 0; i0 < 32; i0++) {
    d0 = TMfd[i0] / 20.0;
    TMfd[i0] = d0;
    d1 = w_vd_j[i0] / 20.0;
    w_vd_j[i0] = d1;
    d2 = w_sd[i0] / 20.0;
    w_sd[i0] = d2;
    a = w_in[i0] / 20.0;
    w_in[i0] = a;
    sn = 0.0;
    for (i1 = 0; i1 < 6; i1++) {
      sn += T[i0 + (i1 << 5)] * fg[i1];
    }

    g_TMT_tmp[i0] = (((d0 + d2) + a) + d1) + sn;
  }

  pinv(d_TMT_tmp, TMT);
  for (i0 = 0; i0 < 32; i0++) {
    d0 = 0.0;
    for (i1 = 0; i1 < 32; i1++) {
      d0 += TMT[i0 + (i1 << 5)] * g_TMT_tmp[i1];
    }

    dz[i0] = z[32 + i0];
    dz[i0 + 32] = d0;
  }

  *flag = 0.0;
}

/*
 * File trailer for EOM.c
 *
 * [EOF]
 */
