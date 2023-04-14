/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sprdmpF2_info.c
 *
 * Code generation for function '_coder_sprdmpF2_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF2.h"
#include "_coder_sprdmpF2_info.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[6] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs", "FullPath", "TimeStamp" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 6, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("sprdmpF2"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (8.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF2.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.94942129625));
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.5.0.944444 (R2018b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[21] = {
    "789ced5dcd6fe3c615e726bbc12e82b43cb44d83162db62d160db6306549b6b468d3eafbc3b6be2cd996b59bdaa4444994490e45525fbe54c71e7ac8a9a71ef6"
    "98146891f6d02e90a250fe88f4d0d35ef227a4e78a92689b03cd4a3629caa46700633c7ee4fc86cf6f7e6fe60d6748dc4b67ee1104f1adf1cf3f7e4710dfff94",
    "98a4f7a61941cef2b7086382e5f766f90fa1b29e1e10f70df7dd9be1fd6956ae025165fbeab4c073229bed080c2b8f0b222db017d5d480c089b4a89606124bc8"
    "ac02f82e5b9b48ea1ccf963881dd03570a296e5c1012574417054da4fd1e6db2d5b3624720e4a672d95cfe6a8198e9474b9f239efffe92fac923f44342f2e7f1",
    "8fa9261058aa49d7382a134f86958158a5525a29dc514129538a0d442a0a6aecd572845569aabbb9e1a1aa9a4491e49a2025bc1b82defe5344fbde59b2fd70ae"
    "a747c4c32ba5add022bc65f5f536028f9c49aa60fa8fb20aef1da87c893795d44087e1d94bbc4f4de285917846f9f3f45e796c121d45a67850a5792a132eed85",
    "23d4bed7b319642815009e017d8a15788ae7184aa0559e662896af77c4b129281bc2ac1e1bede0cb83275f85edb53b5b9f6fad787d447dcbdaddf71078242497"
    "4afd5620a7e6b70339ba546c95e4e4a02a462edba1f3150a67513b0844d9aefa71ff3526a3bdfdec82c78788fa96d5d307083c12926b6e4bdee0c6830159a4f9",
    "0d65ac2a5aded059de3ccfc309d51e3d59e5f7330bf074f935ec44fb793ad117f5545718f574aab10b9bb1cf5e42db7ffc0cf3bdd3f93e28ef2974a19a393e62"
    "8ecb4c24b2edaf3758ccf7778eef3f41d4b7ac9e3e44e091901ce27b5a92f841714261898e58553920a6c53c4f57f529a0de3ec964fbbebda07dbabc3e6bc549",
    "93166be381bf8e3f3289ff6201be2e37eb0fd00a9d9a987df63562de6dfd07fb8715e1d9e51f00bdd762683a19adf9822da5ec6533156910738f7f1821eec7fd"
    "da988c76f80bcbe23d0fa1327171dd54c2298a44cb0aebd4784f0a896794df6cfca0e9461b41e85ab233ee177af8d16f31bf3b9ddf7b476925c19f1d26bc75b9",
    "c8775bb91df1bc10c5fc7eb7f97dc37571a09bf23f8e03cd6f3f8e03d98387e340d6d46fb61fe7a132015da7cb57b58e8b8acf2c6b7728de7b34cb3d86bf7e14"
    "9ae6bf9ce5bf9ee58159fe9b591eb46c1ef000d13e722691406ff2768053e701ab8d230249a1261a5a431c71f887afb6f13cc0e9fc7fd43c64b78b85e2d67ea9",
    "d029c7762b87a078e0a2798053fb2f2aeebdacbdbd0595f5a4f33e69f8eb93d034ff8965e3ff1f23f049480e8dff3925d2e178352d663b022b73d5b5f1fe2b93"
    "78fb483ca3dcecf81f56986e4836fa817f7ef35f3c0f70ba1fc875dbd1703dd50d960afe41352e88de44854fb9c70f989d07ec20ea2721b9693ff0b8ceabfaa0",
    "97b0d9ee8699905576f73e028f84e473e33ff18663e33e2bb093b9bcaf2b6a0d7cffd72738feef78bef7ec3736bbeace3320379a4a314137228974d745ebbbb8"
    "1fcf6f3f8aef51f38d65f5f51e5426a0eb7439a788d381aaaaedec706e7c3f8dc433caaf391ea8737db62681b17950064dade33db1bf1c7d80c7f54ee7f9a4ef",
    "6c506c37383e5a8a9eedb7238dd2d9411cf3fc9de579149e75efedd4b9f1a4a6e9d4787d0c8967949be1f5a9866c5fdfc77cbe423cb37cfe5d041e09c9bb6d36"
    "2e75abcab372cf07405e296efa8e2b847bf8dc2971d74b3e7f5ce76445ad73c6e73845b4d352fb1b9d5a16afff11028f84e463659c8c95705207320f807402ba",
    "ac5ce741efa4aaedaf5edfbeadd10df1f4fa2b0bf074f90df77b4ccde80d9ab37f5c30fad7d70f701ce7b6fa8365c7f7ca6ebc1f8f9d9fe777fa5e7fc6eb8916"
    "c29b9eb87bfcc16bc4fdcbea7188a89f84e4abebd78fdf7cc14993e52556b6d74e9396cd07ee4365e2e2baa9441bed6af99ad71538b1c6f6d3a27ad18e9726db",
    "115ad00e5d6e6e9e60eb791eaff03aaef3fd41712071c2567bff6893636afe74a590cf6cba29aeff1271ff1deeb7e3e4714d1c7f913fa936e9c9ca388ee3cfcf"
    "f584e33ef6e0e138be35f5bf46dc8fc7f9f39f77393b4d5b36ce5f14871f3fb840f7d7e7076e69dcffe2bc8ff12fd45447b69fc7f0eafd4738cee374fe97db1e",
    "a9c529feb0b09d0f8879a6ecdb3d545cb44feb35e27eccfff39f77293b1ddacbff9c88f97f11ff73a2edfcff05e67fe7f37f833e0ee47c47d9768009abd12d3a"
    "e767fd85a47bf81faffbcecff564b0bfd7a796f1fa75e3f766f1aefb3ecf4b937821249e51eea0781f8ed3af100fc7e9ada9df817c7ececa40e908c6e740c5d3",
    "57b20f77f42234c9431fdbc6eff50ecf6b397e5ff34de7ac695ab27bdc3efc1b8edb3b9fe7d56dafb01f3b4a362b3e70de55334222b3a9ba88e73f47dc8ff7d5"
    "5eb5bbcbf7ef7f8fa86f597dfd1c814742f279e72d47389196a1c3e6ac5a375ef739cbcf17e0eb724bceeb9ba7c8d9caae8dfee1ef9fc938aee374ff502844d5",
    "b37ccb13602ad9dd2c53a283b98c92708f7f1821eec7fdda988c7618b0cc5ffc1481474272d85f7401570bcb323d48f0b4aab222273626d7adebfd7eb3f3c9c3"
    "0578badcb41dcd519c664236dacff07f0cf60b4ef70be73b295ff4402a0b0526570b97eba94c5fc8b9e83c1eb3fdb984a89f84e4e6e70dd308d1499d07b47a72",
    "3183b0779f57059fcb6312cffdfbbcf1b93cabc4c3e7f25853bf59de2f20ea2721b979de17819aa5b339393deeda0d3d6c64f3b90d4796ad032c3a679953445a"
    "249cbb0e1045e219e5a6dedfd174647f9c07aff7ae10cfae731bdae14e4ef00fca7ecfbeeced4437d9675d214bb887d771ff35a6557d5f179fab8cc233caf1b9",
    "cad7c59ba6bb8287cf55b6a67e3c9e9f9feb09359e1f22ea5b566f3f40e091907cfef7b5ea3c00530d38359e9343e219e5567d5f6ba2b1b113b091ffff8cdfff"
    "713eff33cded7c59e4d55a1108f18e98f231f1c88e8bdedbbf8571d9dbf7fecf306b59fcfe3b083c129243bccfca32586add6255fbb36ed9b85f19378fad5153",
    "b69f713e4cfd139dad61dcffefdd631cc7773aeff7c542ef3c230991643b965082d19d7617785c14c737cbfb79a84c40d7e9f2557d57f114d13e6bedee5796c5"
    "efdf46e0913389a26dbe259c1bbf0f23f18cf29bc6ffb4b7f8157df32d6127ff84be3c7882c7f14ee7739a4e452abdb31477988976f848448c05f25917f139ee",
    "bfc6b4aaf8bdb9efa2eb2cbfbef730cdfafdcc023c5d6e55dc46b719fbec6514c2df45773edf7bb652dbc168efc8eb89f47abc47e2fdb1c6b98bcedbc17c6f4c"
    "28beff0451dfb27afa10814742f279fbb58c1b11d2629ea7abecec7ab7ecdb7ab1005f975bb2bf63ae426d3f8f8779b785e33b4ef70f80de6b31349d8cd67cc1",
    "9652f6b2998a3470d17c6084b81ff76b6332dae186ebe609378d07e179c2fcf6e379823d78789e60aefeff037ac6c72e",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 43056U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_sprdmpF2_info.c) */
