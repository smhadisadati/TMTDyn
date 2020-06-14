/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_cnstF1_info.c
 *
 * Code generation for function '_coder_cnstF1_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "cnstF1.h"
#include "_coder_cnstF1_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("cnstF1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/cnstF1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737612.386574074));
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
    "789ced59cd6eda4010366d1a25aada72aad45b0f55d42a154b684ab85402430854909042fefbb7364b3059af916d02e4d23e424f3df501da43a51e7ba46fd04b"
    "fb3c353f0bd862050dc409644742eb61f07ce3613c3b3b237892698f200877adcff70f82f03b28b4e84e7b11bc9df5866027a7dcd359171d3ca55bc29ced3e4f",
    "07ef4b87973562a29ad966b042d0664595906e3104aaa8ab26afa90a81c4ccd5cb48d091a1e153946f490a0a4639454529ad8f492816a3c6fb445da6296a5e47"
    "8b483ec95654412f1a3d73713f2374fcd3a49f8ce79f1bd13f3b0cff781df2a3f537a0a8a90814615e0159584020bdbe1131ea440689e657b9742e562720aae5",
    "11bd169109c169c0e77f9848a5401c4aba2203a4a9402686195ff1a97dcff19e61e7fc88cfe15c292d0a0b7ddc527818dea87ebbc9c0f37624b2d6fec3268537"
    "efe07b786d495eab4818f5f0be8e891761e2d9e547c9d4be151a15430758932106e9482e1511c1ab807f25240153d3b0a4d5005231c08a045468622801840b15",
    "022c1fb562a0492ec6c1af9da53f1177e3ceed38bf3cbc1a43dfa871779f81e775c8cbb95a696dcbcc04d7b6602e5bcae91b7599883d3b32437086d9213078b7"
    "f4f3f7d74ef6787bd4cde31f19fa46f5d303069ed72197ad7d4df7295651a013887d86e52aa8fb68961f3fcf3b89650f258af7e39c78547f7a081e95ff479c34",
    "3fcb2d7f8165ea30b0dcf6583766dc8b9770f0f3379eefa73ddf87f49401b7e5f4c19e74b02f896270b5708c78bebf76f9fe1343dfa87e7ac2c0f33ae48e7c0f"
    "cb655ccfb65258bc426453d14892643094e95190da571ed3be7b43eca3f242c78a774548f256e14ff11b63e2bf1e824fe5e3ee076c87b643ccbdf86a48b74b7f",
    "f9fe7041786eed0f1a4c95240837a2f967a192b11f40e9c3723d363bfb4383713f7fafed648fc3a713ebf72c3878a1fbbbb644318c32d40d34adfd9e0413cf2e"
    "3f5ffdd0f44db382a05ef2a92ed6ff0b2fdef2fc3eedf9bdba9734e2f864371e28e8597c5ada7a49ceb6a33cbf5feffcee9bb93ed079f33fef030db69ff781dc",
    "c1e37da0c9e8e7f3dcc12b257bfc3d766d9e6b28a4b54e6b7def467fd0f2d125f407c37c9e7b81786ee5750813e261f524a1eca6a3152c8a24b696d99ca1fe0d"
    "7f7fed7435e7b934cbf379eea8753c8d1917fbf5615ec74f7fbef73f4f0443d1ea5ec02f56abd85fc6abb1e3b319aae379beb7139fe70eb68fcf73dbc4e7b9d3",
    "81c7e7b993d1df60dccfdf6b3b5dcd7effe4ce09e7ed07f173c260fbf939c11d3c7e4e184fff3fb556394b",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 14056U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_cnstF1_info.c) */
