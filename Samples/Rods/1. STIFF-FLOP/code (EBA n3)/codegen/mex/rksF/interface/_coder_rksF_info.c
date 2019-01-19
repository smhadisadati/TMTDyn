/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_rksF_info.c
 *
 * Code generation for function '_coder_rksF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "rksF.h"
#include "_coder_rksF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rksF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/rksF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737431.7863657407));
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
    "789ced5ddd6fdb541477c78636a18125a46d08012b4293d0a63a4d3f8784d47c36e99a266db2b4eb80cc899dc4c9b59dd84e9af4853e22c4037f000f7b9c1048"
    "7b63123c84375e9180079ef6c29fc03b769c9bc677b98b57bb2e6eee91aadbdb639fdff5e9b9bf7b7c7de25033c9d40c45516fea3ff92f296af56baa2f57cd86",
    "a207ed05ca2aa87e66d05e47fa502e51172de7cd0cf0be1bf44bb2a4f11dcdec0041e2b75a629157f48ec48afcd00c278b82c44a5aaedbe029855765d0e6b9be"
    "a62c003e2788fca63cd249087a478c8fa8861d4365fc1ea9f2a57ab625524a553d1e2e18ed5003ff18f21473fd176dfa6713e31f1ad13f8c7dce54659167aa2c",
    "2730a9d87a48ed4a252661f4422d4dcea572d1aec444648e1fed87798d65daf37301a6646894ba1a9f1347c7ff0833bed76d8e1f6da15ca12e8ff4e6d720de11"
    "c69e5d7fddc4e0d188deb85c654ed08348915830a78746956df059e1d0fc07ab93ae7fd27850c18d070ac47b76423c683f3b010fea1f2637f7f49069a90a03e4",
    "120b985428b7190a333bc1c0fc6a91d1641914e50ec38ba0ff73bbef2fe6367418f382c3ccb0f1306e8e7effe1c95f216fe3d4eb797176781d8c3dbb71780d83"
    "4723fae5f50058c9ac6c67f289bc9adf5daedcdb696ad1e3716426e04c1a0785e97b659fcce7f12d146bfcdd5c732bfe6e60f068448fac0312ab5404a954adfb",
    "95fff313f0a0de66bce841a1f01c6346cb2066d0d019facc08190ff9ffed4f76fe20fc7f4a785ef17fb77390bccbc6cb95a540291d93b3b5786be52046f8ffff"
    "369f71f16037fe5ec35cc795417bc3f2d73b6b66fbe1a0bdb5e6948f21ee25cc38e881a60c64d9b88b740bef75a47f8c676a38b95504fc31de138778112c9e55",
    "ff0af902108a8cc86a802d323c28b724a6ef23eff3835fefdffa93f0fd29e179c5f7abcd9574ae09a24bf57035b7bd9ed59ad168297e7ef89ecc5fabe0f2fb23"
    "8c3dbb7efa008347237a24bf17d4704b005a52da6a89bc2294ce8ce79de6053b583cabdee97d21eab041d87899e7fff4efdf84f7fdcefbe97633122a27daabb9",
    "edc56e29264ac1f83e4810de9f0edeffc835de7f178347237a84f755dd55ac3207b37be7f93d2a76f7779e9e100fda4f4fc0837aa7bc7fdbf4d830663ce4fbef"
    "77df217cef77be2f5697337b12d0b8ac2cc65a5262a1180b6fac13be9f36beff1663cfae9f3ec6e0d1881ee17bb6d100dd6c9fc2e22da9a409b2949432802dc1",
    "d20038be86c3f1bd35617c505f1e8ca25065254ebf1180f83d87f89f4dc0877aa7eb01dea15ed70bf48a6fd4c8735fbfaf0f32bb592bb2ec7a845b58ada97b41"
    "3eb5dfe89ea3e7be3dccf9645e5bc51a87775cdbe7bf8cf4a9e171a64650d506aba8bc5ff7f913583cabfe64f983e11b2383805e9a13bd8b83b5cb9f7e41f8dd",
    "effc7eb09b54e3a09e8f07cb4a16b46be90de9703b42f87dbaf97deedced039d94ffc93ed0f8f1937d206ff0c83e903bf6497de7f8168a35fe0243feff0a63cf"
    "aedf66317834a247f785549557b43c0b04ce704548a90c8ef3eb73e01c16cfaa779c47bce038cff77d2e440ec87d81dfd78360b07e78371a0f272b9b9decfe61",
    "a298b8bba3917acf299ccfba1cad91fd1e9b7864bfc72d3c53a6058fecf7b8639ff0faf8168a95d743a4ce73f07752e739be8542ea3cbdc123759eeed8ef61ce"
    "b7ebc702c63e8de84f631d981554435f5158e06d1cf61e78f6f92de312cb14f9fc16ae2e4cff85e9fbc8fbf7353c23fcee7f7e5feaa440bcdee66ac9e5bdce06",
    "a70417a5ec32f9fcd614cc5f43dcabe327793d0ecfaa2779fdabe299322d7824af77c77e0f73be6ff2faa2dc9238d5e3bc7edbb5f5e03d0c1e8de85f580f92c6"
    "1d0daf4480ee19cabdbcff22d23f1e8fa92955d97e01915bf53c19a44f21c741bdf3f560d4619eeef37f73ed0ad9e7f7fb3a10973633e1d0eed6a12076d2b506",
    "27a6b5adee39dae7ef61ce27eb8055acebc07dd7f67726e5e1ba0344b673763ceff4fe308ac5b3ea1ddd1ff67de4797dceb3eb84df7dcfef4a33d0a809ea6248"
    "5cceac4899e2dec2bdbc1a26fc3ed5fc4ee53de5774122fc3e89df05c9737eff99f0bbfff9bdc23e58492fec6e35578a212db2c4a617f9c56d528f3fb4375575",
    "3a5482f0ba4d3cc2eb6ee199322d7884d7ddb14f787d7c0bc55a7fb945f6636ce291fd18b7f04c99163cb21fe38efddf30e7dbf5238bb14f23fa53f8fcec6c9b"
    "55faafca2f34149943aeeb1166dceef27cc9b5e7afef63f06844af3ba7a03ba550961520cb8d82dce69532900f0a25c32b67f75ecdde09f1a0fdfd0978507fc2",
    "75c00cab9778cefbba9cde2fff5c22eb83dfd707f55eac138b1e1e66363ac1c5543010d90ecd07ced1e7699f63ceb7ebc7238c7d1ad19fdebc9e7df901852a0f"
    "1abce26d9caebb767f30295f17d4b2f19d9aaecd0bdcf785d2881ead139238be9394b4e1381e3b1cc7da847140fd2bc65559e8f05c43d6c7cd189ef3b23e8722",
    "f5f9a788e7d57a90ed360471a9b9b33b2f14b9c5e4fe762635df3e47efd57c8c397f8ae72d35fa5e9d06c69e5dff5c45fa14721cd40baa6416946bc6372bfbb7"
    "ee3289c5b3ea9dc4c388a7609aef250ffd48dea3e67f5e5f5fa877b3cd8a0022b9487da719aee4eaf763e788d79f63ce2779fef8ebb517a749f21cc0261e790e",
    "e0169e29d382479e03b863ff39e67cc2ffe3afd7def3016ff99fd4f790fa1e28d38247ea7b9cd9ff0fc5ac392e",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 35408U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rksF_info.c) */
