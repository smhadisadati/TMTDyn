/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_cnstF4_info.c
 *
 * Code generation for function '_coder_cnstF4_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "cnstF4.h"
#include "_coder_cnstF4_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("cnstF4"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/cnstF4.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737612.38659722218));
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
  const char * data[9] = {
    "789ced594f6f1241145fb49a3646e564e2cd836934350c62a55c4c60a1140cb454e87fffcd2e43593a3b4b769702bde847f0e4c90fa007138f1ef11b78d1cfe3"
    "f26780dd3001816e0b9d9790d9c763dfefede3ed9b37ef099e64da2308c21debf3fd8320fc0e0a2dbadd5e046f67bd26d8c929f774d625074fe986b060bbcfd3",
    "c1fbd2e1658d98a866b619ac10b4595125a45b0c812aeaaac96baa42203173f53212746468f814e55b928282514e51514aeb63128ac5a8f13e5197698a9ad7d1"
    "22924fb21555d08b46cf5cdccf081dff34e927e3f91746f4cf0ec33f5e87fc68fd0d286a2a024598574016161048af6f448c3a9141a2f9552e9d8bd509886a79",
    "44af456442701af0f91f245229108792aec800692a908961c6577d6adf73bc67d87973c4e770ae949684c53e6e393c0c6f54bf5d67e0793b12596bff61d3c2bb"
    "e9e07b786d495eab4818f5f0be4e881761e2d9e547c9d4be151a15430758932106e9482e1511c1ab80ff694802a6a66149ab01a462801509a8d0c4500208172a",
    "04583e6ac540935c8c835f3bcb7f22eec69ddb717e71783586be51e3ee1e03cfeb909773b5d2da969909ae6dc15cb694d337ea32117b766486e00cb34360f06e"
    "e9e7efaf9decf1f6b09bc73f32f48deaa7fb0c3caf432e5bfb9aee53aca2402710fb0ccb5550f7d12c3f799e7712cb1e4a14efc79878547f7a081e95ff479c34",
    "3f2b2d7f8115ea30b0d2f6583766dc8b9770f0f3379eef673ddf87f49401b7e5f4c19e74b02f896270b5708c78bebf72f9fe1343dfa87e7accc0f33ae48e7c0f"
    "cb655ccfb65258bc426453d14892643094e95190da579ed0bebb43eca3f242c78a774548f256e14ff11b13e2bf1e824fe593ee076c87b643ccbdf86a48b74a7f",
    "f9fe704e786eed0f1a4c95240837a2f967a192b11f40e9c3723d363ffb4383713f7fafed648fc32753ebf72c3a78a1fbbbb644318c32d40d34abfd9e0413cf2e"
    "1faf7e68faa65941502ff95417ebffc5176f797e9ff5fc5edd4b1a717cb21b0f14f42c3e2d6dbd2467db519edfaf767ef7cd5d1f68dcfccffb4083ede77d2077",
    "f0781f683afaf93c77f04ac91e7f8f5c9be71a0a69adb35adfbbd11fb47c7401fdc1309fe79e239e5b791dc28478583d4928bbe968058b2289ad6536e7a87fc3"
    "df5f3b5dce792ecdf27c9e3b6a1d4f63c6c57e7d98d7f1b39feffdcf13c150b4ba17f08bd52af697f16aecf86c8eea789eefedc4e7b983ede3f3dc36f179ee6c",
    "e0f179ee74f43718f7f3f7da4e97b3df3fbd73c2b8fd207e4e186c3f3f27b883c7cf0993e9ff0799e93951",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 14056U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_cnstF4_info.c) */
