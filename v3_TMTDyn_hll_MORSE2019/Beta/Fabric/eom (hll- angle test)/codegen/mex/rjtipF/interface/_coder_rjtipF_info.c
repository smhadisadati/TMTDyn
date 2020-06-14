/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_rjtipF_info.c
 *
 * Code generation for function '_coder_rjtipF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "rjtipF.h"
#include "_coder_rjtipF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rjtipF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/rjtipF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737612.15589120367));
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
    "789ced594f6f1241145fb49a3646e564e2cd1863626a18c44ab99894855230d052a1fffd37bb0c65e9ecec667729d08b7e849e3cf901f460e2d1237e032ffa79"
    "5cfe0cb09b4e40a0db52e6259bd9c763dfefedcbdbdfccbc117ca98c4f10843bf6f5fda320fc0e0b2db9dd1e047f67bc2638c56df775c605974ee58630e778ce",
    "d7c1fbd2d1658d58a866b515ac10b45e512564d80a812aeaba2968aa4220b1f2751d090632357c8c0a2d4b51c128afa828adf52949c556d4449fa9ab344dcdfb"
    "5809c947b98a2a1825b3172eee57844e7e9af293f1fe7343e6678b911fbfcb7eb0fa1694341581122c2820078b086456d7a2669dc820d9fc299fc9c7eb04c4b4",
    "02a2f722b220380e05820f92e9344840c9506480341518654bd11301b5ef3d3e30e2bc39e47bb8472a0bc27c9ff6706510deb079bbcec0f3772ca6425ae3a4f0"
    "6ebaf41e5edb52d02a12463dbcaf63e24599784efb412abd6b9746c53400d6648841269a4f4745f03a147c169180a56958d26a00a9186045022ab4309400c2c5",
    "0a01768e5a35d014efea60e5d7d6e33f516febceeb3abf38bc1ac3dfb075778f81e777d9214c8afbd5a3a4b29d8955b02892f872763dde8b233b0067501c0243"
    "f7ca3fff7e9de2acb7475d1effc4f0376c9eee33f0fc2ebb6ccf6b4640b1170506813860daa9824680b2fcf83cef16563c5428de8f11f1a8ffcc003c6aff8f3a",
    "695e8bad7c81459a30b0d8ce58b766bcab97c6cae76f9cefa79def832f92e148acba130a8ad52a0eea78297e782272be9f35be3f65f81b364f4f18787e97ddc5"
    "f750d7713dd7a2b04485c896a29114c96228d3ad208d4f1f33bebb03e2a3f662278af725480af6c29fe237c6c47f33009fdac79d0fd8096d979887f38374abfc",
    "97cf0fe784e7d5fca0c1745982702d56781e299bbb2194d9d7eb57683fd0603ccfbf6ba738ebf0e9c4fa3df32e5de8feaf6d514c53878689a6b5df9364e239ed"
    "a3ad1f9ab969ae20689602aa87fd9ef997ef38bf4f3bbf57775266021f6d27424523878fcb1bafc8c9668cf3fb6cf37be0caf58146e57fde073a3b7ede07f206",
    "8ff78126e39f9fe79e3d52b9a8f35c596b1fc04febfade8bfea09da38be80ff2f3dc73c4f38ad7f57cadbcbc6165c3cb1b309f2be78db5ba4cae10aff3efd729"
    "97f33c97b23c3fcf1d761d4f6bc6c37e4e98afe3a79fef2346da849b72666f47dadb954431bc543c449cef678eef4f19fef8796e5b1a63e2cf5e5f909fe79e27",
    "1e3fcf9d8cff06e379fe5d3be572f6fb27b74f18b51fc4f70967c7cff709dee0f17dc278feff0110a239c1",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 14056U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
