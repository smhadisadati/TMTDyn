/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_cnstF6_info.c
 *
 * Code generation for function '_coder_cnstF6_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "cnstF6.h"
#include "_coder_cnstF6_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("cnstF6"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (3.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/cnstF6.m"));
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
    "44af456442701af0f91f245229108792aec800692a908961c6833eb5ef39de33ecbc39e27338574a4bc2621fb71c1e8637aadfae33f0bc1d89acb5ffb069e1dd"
    "74f03dbcb624af55248c7a785f27c48b30f1ecf2a3646adf0a8d8aa103acc910837424978a88e055c0ff34240153d3b0a4d5005231c08a045468622801840b15",
    "022c1fb562a0492ec6c1af9de53f1177e3ceed38bf38bc1a43dfa871778f81e775c8cbb95a696dcbcc04d7b6602e5bcae91b7599883d3b32437086d9213078b7"
    "f4f3f7d74ef6787bd8cde31f19fa46f5d37d069ed72197ad7d4df7295651a013887d86e52aa8fb68969f3ccf3b89650f258af7634c3caa3f3d048fcaff234e9a",
    "9f9596bfc00a751858697bac1b33eec54b38f8f91bcff7b39eef437aca80db72fa604f3ad8974431b85a38463cdf5fb97cff89a16f543f3d66e0791d7247be87"
    "e532ae675b292c5e21b2a96824493218caf42848ed2b4f68dfdd21f65179a163c5bb222479abf0a7f88d09f15f0fc1a7f249f703b643db21e65e7c35a45ba5bf",
    "7c7f38273cb7f6070da64a12841bd1fcb350c9d80fa0f461b91e9b9ffda1c1b89fbfd776b2c7e193a9f57b161dbcd0fd5d5ba2184619ea069ad57e4f82896797"
    "8f573f347dd3ac20a8977caa8bf5ffe28bb73cbfcf7a7eafee258d383ed98d070a7a169f96b65e92b3ed28cfef573bbffbe6ae0f346efee77da0c1f6f33e903b",
    "78bc0f341dfd7c9e3b78a5648fbf47aecd730d85b4d659adefdde80f5a3eba80fe6098cf73cf11cfadbc0e61423cac9e2494dd74b4824591c4d6329b73d4bfe1"
    "efaf9d2ee73c9766793ecf1db58ea731e362bf3eccebf8d9cff7fee78960285add0bf8c56a15fbcb7835767c3647753ccff776e2f3dcc1f6f1796e9bf83c7736",
    "f0f83c773afa1b8cfbf97b6da7cbd9ef9fde3961dc7e103f270cb69f9f13dcc1e3e784c9f4ff0332503955",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 14056U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_cnstF6_info.c) */
