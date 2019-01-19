/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_vd_matF_info.c
 *
 * Code generation for function '_coder_fj_vd_matF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_vd_matF.h"
#include "_coder_fj_vd_matF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_vd_matF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_vd_matF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737429.71693287033));
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
    "bea6cc032ecf0bdcb634d249f05a47888fa8861d5da5ff1ea9724c3dd71208b9aa9c0c178c7688817f74798ab8fe8b36fdb38bf00f09e91fc63ea5aa92c05155",
    "9ae5a9546c33a47445864ae8bd504b95f2a97cb42b521189e546fb614ea5a9f6e2428062744db9566cb3458156e30b82f53a1e21c6f9aacdeb805b53ae109747"
    "7a37374cbc63843dbb7ebb89c02321bd7ed9f202af05932cd260410b912adde072fc91f18f56265dffa4f1c0821a8f296ec54d6e029ea97f98dcded742a7a5c8",
    "1490181a50a9507e3b14a6768381c5f512a54a1228491d8a1340ffe776df5fd46dd361d4730e1b048e777173fcfb774ffe0a791ba75ecf8bf3c3eb20ecd98dc3"
    "6b083c12d2af6e06c05a662d9b29240a4a616fb5726fb7a9464fc691998033691c04a2ef957d3c9fc7b7a6a0d601a7f177038147427a681d1069b9c28b4cb5ee",
    "57fe2f4cc033f536e3450b0a996329235a06310387ced0677ac878c8ff6f7eb4fb07e6ff33c2f38affbb9dc3e45d3a5eaeac0498744ccad5e2adb5c318e6ffff"
    "db7c46c583ddf87b05711d5706ed0dcb5fef6c18edfb83f6d686533e36712f21c6410e34652049fadda45b78af42fd133c43c34aad12e04ef09e38c48b20f1ac",
    "fa97d82f00be4469b786802e511c28b744aaef23eff707bfdebff527e6fb33c2f38aefd79b6be97c134457eae16a3ebb99539bd128139f1ebec7f3d72a6795e7"
    "790f8147427a687fcf2be1160fd4a4b8d312389967ce8de73dcb0f3abc2f841de67d7ef0f8a77fffc6bcef77de4fb79b915039d15ecf6797bb4c4c1083f10390",
    "c0bc3f1bbcff816bbcff36028f84f410ef2b9aab6879c1dcdd3bdfdfc36237bff3c329f14cfbe90978a6de29efdf363c368c190ff9fedbbdb730dffb9def4bd5"
    "d5ccbe0854362709b19698582ac5c25b9b98ef678defbf46d8b3eba70f117824a487f89e6e344037d7a7b0784b64545e12936206d08c5922608eafe1707c6f4c",
    "189fa92f0f4651acd222abdd0898f83d87f89f4cc037f54ed703b4438d00f32ebe7aa5d76af8b9afdfd70789deae95687a33c22eadd794fd20973a6874a7e8b9"
    "6f0f713e9ed756b1c6e11dd7f2fc97a13e313cced0f08ad2a06585f36b9e3f81c4b3ea4fb77fd07da3ef204c2f2d08dec5c1c6e58f3fc3fcee777e3fdc4b2a71",
    "502fc483653907dab5f49678948d607e9f6d7e5f98ba3cd069f91fe781c68f1fe781bcc1c3792077ece3facef1ad29d6f80b0cf9ff0b843dbb7e9b47e091901e"
    "ce0b290a27ab051af0acee8a905c191ce7d7e7c079249e55ef781ff19ce33ccffb5c881ce2fb02bfaf07c160fde86e341e4e56b63bb983a34429717757c5f59e",
    "33389f3539dec0f91e9b7838dfe3169e21b38287f33deed8c7bc3ebe35c5caeb215ce739f83baef31cdf9a82eb3cbdc1c3759eeed8ef21ceb7ebc722c23e09e9"
    "cf621d98e7155d5f9169e06d1cf61e78f6f92dfd12cb04fefc16aa2e4cfb85eafbc8fbf7353cc5fcee7f7e5fe9a440bcde666bc9d5fdce162b0797c5dc2afefc",
    "d60ccc5f5ddcabe3c7fb7a149e558ff7f52f8b67c8ace0e17dbd3bf67b88f37db3af2f492d91553cded7675d5b0fde41e09190feb9f520a9dfd1707204689e21"
    "dcdbf75f84fa27e331344c95ee1710b955cf9381fa04749ca977be1e8c3accd33cff57d7aee03cbfdfd781b8b89d0987f6768e78a193ae355821adee74a728cf",
    "df439c8fd701ab58d781fbaee57726edc335070874e7fc78dee9fd61148967d53bba3fecfbc8f3fa9ca7d731bffb9edfe566a051e395e590b09a591333a5fda5"
    "7b05258cf97da6f99d2878caefbc88f97d12bff3a2e7fcfe33e677fff37b857eb0965edadb69ae95426a64854e2f73cb595c8f3fb43753753a4402f3ba4d3ccc",
    "eb6ee119322b7898d7ddb18f797d7c6b8ab5fe7207e7636ce2e17c8c5b7886cc0a1ecec7b863ff37c4f976fd4823ec9390fe0c3e3f3bdfa6e5feabf28b0d5962"
    "a1eb7a8418b7bb3ccfb8f6fcf55d041e09e935e71435a714cb920c24a95194da9c5c06d26191d1bd727eefd5ec9d12cfb47f3001cfd49f721d30c2ea059ef3be",
    "2ea7f7cb3f97f0fae0f7f541b917ebc4a2474799ad4e7039150c44b2a1c5c0147d9ef619e27cbb7e3c46d82721fdd9cdebf9171f50ac72a0c1c9dec6e9a66bf7"
    "0793f6ebbc52d6bf5bd3b57981fade5012d2c3754222cb7592a23a1cc76387e3d898300e53ff927155e63b1cdb90b47153bae7bcaccf21707dfe19e279b51ee4",
    "ba0d5e5869eeee2df22576397990cda416db53f45ecdc788f36778de12a3efd56920ecd9f5cf55a84f40c7997a5e118d827255ff8665ffd65d26917856bd9378"
    "18f194b9cdf79287bec7ef51f33faf6f2ed5bbb9668507917ca4bedb0c57f2f5fbb129e2f56788f3f13e7ffcf5da8bd3247e0e60130f3f07700bcf9059c1c3cf",
    "01dcb1ff0c713ee6fff1d76beff980b7fc8feb7b707d8f29b38287eb7b9cd9ff0f5f703c4f",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 35416U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_vd_matF_info.c) */
