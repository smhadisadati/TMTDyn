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
                (737431.00445601856));
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
    "789ced5dcd8fdb4414f79616b542054b486d1102ba085542add6d9ec679190f2bdc976b349366976bb0552c7761227633bb19d6cb217f6881007fe000e3d5608"
    "244e50090ee1c615093870ea853f813b761c67e369a671d75e2fdecc9356b3b3cff37e336fdffc663c7e7188b9547a8e2088d7b59f1f3f2788d097c440ae1a05",
    "410ecb0b845560fddcb0bc0ed54db9445cb4b49b1be27d33ac3392a8725dd5a8005ee4b6db429993b58a480bdcc80c2b09bc488b6aa1d7e408995324d0e1d881"
    "a6c203aec00bdc96345649f25a45488ca946155da5ff1ead714c23df1608b9a61c77178c5788a17f74798a18ff459bfed941f88784f40fe39f523549e0a81acd",
    "f2543abe11567a224325f55ab8ad4a857421d613a9a8c472e3f508a7d2546771214031baa6522f75d89240ab8905c13a8e47887ebe6a731c7069ca15e2f258ed"
    "4ec8c43b42d8b3ebb79b083c12d2ebc39617782d986491060b5a88d4e82697e70f8d7fb4326dfcd3fa030baa3fa6b81537f92978a6fe616a6b4f0b9db6225340",
    "626840a5c385ad7084da090616d7cb942a49a02c75294e00839fdb037f51b74d8751cf396c1838dec5cdd1efdf3df92bec6d9c7a3d2fce0eaf8bb067370eaf21"
    "f04848bfba11006bd9b55cb6982c2ac5ddd5eabd9d961a3bee47760aceb47e1088ba57f6f17c9e5c9a628dbf9b21b7e2ef06028f84f4d03a20d2729517995ac3",
    "affc5f9c8267ea6dc68b161432c75246b40c63060e9d91cff490f190ffdffc68e70fccffa784e715fff7ba07a9bb74a2525d093099b894af27da6b0771ccffff"
    "b7f98c8a07bbf1f70a621c5786e50dcb5fef848cf2fd61792be4948f4ddc4b887e90434d0548927e37e916deab50fd18cfd0b052bb0cb863bc270ef1a2483cab",
    "fe25f60b802f53daad21a0cb14072a6d911af8c8fbfdc1aff76ffd89f9fe94f0bce2fbf5d65aa6d002b19546a456c86de4d5562cc624ce0fdfe3f96b15d4fefe"
    "0861cfae9fde43e091901edadff34aa4cd0335256eb7054ee69933e379cfce071dde17c20ef3fe7cf0e8a77fffc6bcef77decf745ad17025d9592fe4967b4c5c",
    "1083897d90c4bc3f1bbcff816bbcff36028f84f410ef2b9aab6879c1dcdd3bdfdfc362f77ce78713e299f63353f04cbd53debf6d786c14331ef2fdb7bb6f61be"
    "f73bdf976babd93d11a86c5e12e26d31b9548e47363730dfcf1adf7f8db067d74f1f22f048480ff13ddd6c825e7e406189b6c8a8bc24a6c42ca0193345c0ec5f",
    "d361ffde98d23f535f19f6a254a34556bb1130f1fb0ef13f99826fea9dae0768871a01e65d7cf5cbafd5f1735fbfaf0f12bd552fd3f446945d5aaf2b7b412ebd"
    "dfec9da3e7be7d447b3cafad82ca0342e1d9f5df65a84e8cae3334bca2346959e1fc7ace9f44e259f527db3fe8bed17710a6971604efe22074f9e3cf30bffb9d",
    "df0f76534a02348a896045ce834e3db3291ee6a298df679bdf17cedd39d049f91f9f034dee3f3e07f2060f9f03b9631fe7774e2e4db1c65f60c4ff5f20ecd9f5"
    "db3c028f84f4f0b990a270b25aa401cfeaae08cbd5e1757e7d0e5c40e259f58ef711cf39cef3739f0bd1037c5fe0f7f520186c1cde8d2522a9ea5637bf7f982c",
    "27efeea838df7306e7b32647217cde63130f9ff7b88567c8ace0e1f31e77ec635e9f5c9a62e5f530cef31cfe1de7794e2e4dc1799edee0e13c4f77ecf711eded"
    "fab184b04f42fad35807e67945d757651a781b87fd079e7d7e4b1f6285c09fdf42e58569bf50031f79ffbe86a798dffdcfef2bdd3448343a6c3db5bad7dd64e5",
    "e0b2985fc59fdf9a81f9ab8b7b79fc785f8fc2b3eaf1befe65f10c99153cbcaf77c77e1fd1de37fbfab2d41659c5e37d7dceb5f5e01d041e09e99f5b0f52fa1d"
    "0d274781e619c2bd7dff45a87edc1f43c3d4e84102915bf93c59a84e40d7997ae7ebc1b8c33c3de7ffeada157cceeff77520216e6523e1dded435ee866ea4d56",
    "c8a8dbbd7374cedf47b4c7eb8055acebc07dd7ce77a6edc335070874f7ec78dee9fd610c8967d53bba3f1cf8c8f3fc9ca7d731bffb9edfe556a059e795e5b0b0"
    "9a5d13b3e5bda57b452582f97da6f99d287acaefbc88f97d1abff3a2e7fcfe33e677fff37b957eb09659dadd6ead95c36a7485ce2c73cb399c8f3fb23753793a",
    "4412f3ba4d3ccceb6ee119322b7898d7ddb18f797d72698a35ff721b9fc7d8c4c3e7316ee119322b78f83cc61dfbbf21dadbf5238db04f42fa53f8fcec7c8796"
    "07afca2f35658985c6f508d16f77799e71edf9ebbb083c12d26bce29694e295524194852b3247538b902a48312a37be5ecdeabd93f219e697f7f0a9ea93fe13a",
    "6084d50b3ce77d5e4eff977f2ee1f5c1efeb83722fde8dc70e0fb39bdde0723a1888e6c28b8173f479da6788f676fd7884b04f42fad39bd7f32fbea054e34093"
    "93bd8dd30dd7ee0fa6edd779a5a27fb7a66bf302f5bda124a487f3844496eba64475d48fc70efb119ad20f53ff927155e1bb1cdb94b47e53bae7bccccf21707e",
    "fe29e279b51ee47b4d5e5869edec2ef2657639b59fcba6173be7e8bd9a8f11ed6778de12e3efd56922ecd9f5cf55a84e40d7997a5e118d847255ff8665ffe65d"
    "a6907856bd937818f394b9cdf79287bec7ef51f33faf6f2c357af9569507d142b4b1d38a540b8dfbf173c4ebcf10edf13e7ff278edc5690a3f07b089879f03b8",
    "8567c8ace0e1e700eed87f86688ff97ff278ed3d1ff096ff717e0fceef316556f0707e8f33fbff01e7f03c5f",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 35416U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_vd_matF_info.c) */
