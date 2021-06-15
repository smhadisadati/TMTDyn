/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_k_matF_info.c
 *
 * Code generation for function '_coder_fj_k_matF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_k_matF.h"
#include "_coder_fj_k_matF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_k_matF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_k_matF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737429.55663194449));
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
  const char * data[17] = {
    "789ced5ddd6fdb541477c78636a18125a46d08012b4293d0a63a4d3f8784d47c36e99a2669b2b4eb80ccb19dc4c9b59dd84e9af4853e22c4037f000f7b9c1048"
    "3c2031091ec21baf48c0034f7be14fe01d3b8ed3f82e77f16ad7c5c93d52757b7becf3bb3e3df777af8f4f1c622e999a2308e275ede7c7cf0962e34ba22f578d",
    "862007ed05c22ab07e6ed05e87faa65c222e5ace9b1be07d33e83392a8721dd5e8005ee4765a428993b58e480bdcd00c2b09bc488b6abedbe008995324d0e6d8"
    "bea6cc032ecf0bdcb634d249f05a47888fa8861d5da5ff1ea9724c3dd71208b9aa9c0c178c7688817f74798ab8fe8b36fd9345f88784f40f639f525549e0a82a",
    "cdf2542ab61952ba224325f45ea8a54af9543eda15a988c472a3fd30a7d2547b71214031baa65c2bd68b02adc61704e83a1e21c6f9aacdeb805b53ae1097477a"
    "37374cbc63843dbb7ebb89c02321bd7ed9f202af05932cd260410b912adde072fc91f18f56265dffa4f1c0821a8f296ec54d6e029ea97f98dcded742a7a5c814",
    "90181a50a9507e3b14a6768381c5f512a54a1228491d8a1340ffe776df5fd46dd361d4730e1b448e777173fcfb774ffe0a791ba75ecf8bf3c3eb20ecd98dc36b"
    "083c12d2af6e06c05a662d9b29240a4a616fb5726fb7a9464fc691998033691c04a2ef957d3c9fc7b7a6a0d601a7f177038147427a681d1069b9c28b4cb5ee57",
    "fe2f4cc033f536e3450b0a996329235a06310387ced0677ac878c8ff6f7eb4fb07e6ff33c2f38affbb9dc3e45d3a5eaeac0498744ccad5e2adb5c318e6ffffdb"
    "7c46c583ddf87b05711d5706ed0dcb5fef6c18edfb83f6d686533e36712f21c6410e34652049fadda45b78af42fd133c43c34aad12e04ef09e38c48b20f1acfa",
    "97d82f00be4469f786802e511c28b744aaef23eff707bfdebff527e6fb33c2f38aefd79b6be97c134457eae16a3ebb99539bd128139f1ebec7f3d72a6795e779"
    "0f8147427a687fcf2be1160fd4a4b8d312389967ce8de79dee0b76917856bdd3fb42d8616682d0c37dfe4ffffe8d79dfefbc9f6e3723a172a2bd9ecf2e779998",
    "2006e3072081797f3678ff03d778ff6d041e09e921de573457d1f282b9bb77bebf87c56e7ee78753e299f6d313f04cbd53debf6d786c18331ef2fdb77b6f61be"
    "f73bdf97aaab997d11a86c4e12622d31b1548a85b73631dfcf1adf7f8db067d74f1f22f048480ff13ddd68806eae4f61f196c8a8bc2426c50ca019b344c01c5f",
    "c3e1f8de98303e535f1e8ca258a54556bb1130f17b0ef13f99806fea9dae0768871a01e65d7cf54aafd5f0735fbfaf0f12bd5d2bd1f466845d5aaf29fb412e75"
    "d0e84ed173df1ee27c3cafad628dc33baee5f92f437d62789ca1e115a541cb0ae7d73c7f028967d59f6effa0fb46df41985e5a10bc8b838dcb1f7f86f9ddeffc",
    "7eb89754e2a05e8807cb720eb46be92df1281bc1fc3edbfcbe307579a0d3f23fce038d1f3fce03798387f340eed8c7f59de35b53acf11718f2ff17087b76fd36"
    "8fc023213d9c1752144e560b34e059dd1521b93238ceafcf81f3483cabdef13ee239c7799ef7b91039c4f7057e5f0f82c1fad1dd683c9cac6c777207478952e2",
    "eeae8aeb3d67703e6b72bc81f33d36f170bec72d3c4366050fe77bdcb18f797d7c6b8a95d743b8ce73f0775ce739be3505d7797a8387eb3cddb1df439c6fd78f"
    "45847d12d29fc53a30cf2bbabe22d3c0db38ec3df0ecf35bfa259609fcf92d545d98f60bd5f791f7ef6b788af9ddfffcbed2498178bdcdd692abfb9d2d560e2e",
    "8bb955fcf9ad1998bfbab857c78ff7f5283cab1eefeb5f16cf9059c1c3fb7a77ecf710e7fb665f5f925a22ab78bcafcfbab61ebc83c02321fd73eb4152bfa3e1"
    "e408d03c43b8b7efbf08f54fc66368982add2f2072ab9e2703f509e83853ef7c3d187598a779feafae5dc1797ebfaf0371713b130eeded1cf142275d6bb0425a",
    "dde94e519ebf87381faf0356b1ae03f75dcbef4cda876b0e10e8cef9f1bcd3fbc32812cfaa77747fd8f791e7f5394faf637ef73dbfcbcd40a3c62bcb216135b3"
    "26664afb4bf70a4a18f3fb4cf33b51f094df7911f3fb247ee745cff9fd67cceffee7f70afd602dbdb4b7d35c2b85d4c80a9d5ee696b3b81e7f686fa6ea748804",
    "e6759b7898d7ddc2336456f030afbb631ff3faf8d6146bfde50ecec7d8c4c3f918b7f00c99153c9c8f71c7fe6f88f3edfa9146d82721fd197c7e76be4dcbfd57"
    "e5171bb2c442d7f508316e77799e71edf9ebbb083c12d26bce296a4e299625194852a328b539b90ca4c322a37be5fcdeabd93b259e69ff60029ea93fe53a6084",
    "d50b3ce77d5d4eef977f2ee1f5c1efeb83722fd689458f8e325b9de0722a188864438b8129fa3ced33c4f976fd788cb04f42fab39bd7f32f3ea058e5408393bd"
    "8dd34dd7ee0f26edd779a5ac7fb7a66bf302f5bda124a487eb844496eb244575388ec70ec7b131611ca6fe25e3aacc7738b62169e3a674cf79599f43e0fafc33",
    "c4f36a3dc8751bbcb0d2dcdd5be44bec72f2209b492db6a7e8bd9a8f11e7cff0bc2546dfabd340d8b3eb9fab509f808e33f5bc221a05e5aafe0dcbfeadbb4c22"
    "f1ac7a27f130e2a9f3f87ee5eff17bd4fccfeb9b4bf56eae59e141241fa9ef36c3957cfd7e6c8a78fd19e27cbccf1f7fbdf6e234899f03d8c4c3cf01dcc23364",
    "56f0f0730077ec3f439c8ff97ffcf5da7b3ee02dffe3fa1e5cdf63caace0e1fa1e67f6ff0321893bde",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 35416U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_k_matF_info.c) */
