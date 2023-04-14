/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_kF_info.c
 *
 * Code generation for function '_coder_fj_kF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_kF.h"
#include "_coder_fj_kF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_kF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_kF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.9506018518));
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
    "789ced5dcb6fe3c619e726bbc12e82b43cb40d821629b62d160d363065496b7b0b24d5fb615b2f4bb665eda63629511265924391d4cb97ead8430f39f5d4c31e"
    "93022dd21eda055a14ca2dff407ae8692ffd13da734991944d42b3d29a1465d23380311e7fe2fc469fbff97d33df3c88ddc9e6ee6018f61de5e7afbfc6b0e217",
    "d834bda76518aee76f61e66495dfd1f31f59ca46ba87dd353d7747c7fbbd5eae035ea687b25660199ecef7388a1695024f72f4ac9a06e0189ee4e5ca48a03191"
    "9600dba71b53499361e90ac3d1fbe04a21c328052e7545342ba822f5f7789bae9f977b1c26b6a5cbe6b2570b98ae1f357d05f9fe7797d44f0ea21fdc227f96fc",
    "8c68038e26da64832172c974541af17522a396a23d19547295c48827e2a0415f2dc7689924fa9b1b01a2ae4a9a9dd3f3d40677a5fd6790f6bdb364fbadb9911e"
    "60f7af94b6238bf096d5d7db103c5c97d481f68f720aef1d4bf9124f9334408f62e94bbc2f6ce245a17866f9b3ec7e5531899e24122ca8932c918b56f6a331e2",
    "2018d8dca108190096024382e65882652882236596a4089a6df678c514a4a90da8c9453bf8faf0d1b75177edce6d3b5f1fde1052dfb276f703081e6e910b9561"
    "67bb2017b7b60b64a5dca988e9519d8f5db6a3b80067513b3048d9adfa51ff3527b3bdfd6cc6e363487dcbeae903081e6e91ab6e4bdc6094c180c893ec86a4a8",
    "8a14370c96b7cff3d6046b8f915cf7fbcbdb89faf378aa2fe2b1a130e2b1a6b199cdb8672f91addf7d89f8deeb7cbf23ee4b64a99e3b39a64eaa542cb6156eb6"
    "68c4f7b78eef3f87d4b7ac9e3e82e0e116b985ef49416047e52985a57a7c5d66009fe58b2c5937a68046fb049bedfbee82f619f2a6de8ad336c9379481bf813f",
    "b189ff7c01be21b7eb0fe00ad54ccc3dfb9a50ef76fe85fcc38af0dcf20f80dcef5024998e37423b1da91aa473356194f08f7f98409e47fdda9ccc76f8b163f1"
    "9efb963236fb9c26612449204589f66abc2703c533cbaf377e5075a38e200c2d6d702e8effef7ff22bc4ef5ee7f7c171564ab1e747a960532cb3fd4e6197bf28",
    "c511bfdf6e7edff05d1ce8bafc8fe240f3db8fe240eee0a1389033f5bbd68f57b48efb0da47dcbdadd7b96b2911ee879fbea1fc7a988f68b9127b47c1cd7cb7a"
    "3e4eeae55fe8e5885e7eaa97337ad9f8fb277afe4bc7e60ff72c656cf6394d2280c174578157e70fab8d3f024122a61a5a43fc71fcdb6fb7d0fcc1eb7ee3b87d",
    "446f954be527079552af9ad8ab1d81f2a18fe60f5eedbfb078f9b2f6f696a56c24c35fe0a6bf3e8a68f94f1c9b37fc18828f5be496790323c57a0c2b67f97c8f"
    "a345a6be36de7f6913ef008a6796db9d3758156618928b7ee06ffffd379a3f78dd0f14fadd78b499e9ef544ae1513dc9f1c1548dcdf8c70fd89d3fec42eac72d",
    "72db7ee06193958d412fe6b2dd8d7311a7ecee7d081e6e91cf8d1b255b9e8d17adc04ee6f2bea1a835f0fd9f1ea17503cff37de0a0b5d997779f02b1d596ca29"
    "b2154b65fb3e5a1746fd787efb617c0f9b6f2cab2f587c0ab7c81989d706aab27a22c4bbeb0259289e59fe86e3812633a41b0250cc8330696a1dfbcbfe78fc01",
    "1ad77b9de7d3a1f351b9db62d878257e7ed08db52ae78749c4f3b796e76178ceedf76932caa4a6edd5787d028a6796dbe1754d43aeef0b407cbe423cbb7cfe7d"
    "081e6e91f7bb7452e8d7a5a7d5410880a254de0c9dd430fff0b957e2ae977cfeb0c98892dc64ccdfe30cd24e47ed6f72e658bcfe43081e6e912bca38559470da",
    "04220b80700afab4d864c1e0b4ae9ecb5edf79afc935f18cfa6b0bf00cf935cf896866f41acdb93f2e98fce33ff7501ce7a6fa8365c7f7d25e72984c5c5c1477"
    "87c1702e188897a29b81a47ffcc12bc8f3cbea710ca91fb7c857d7af1fbefe03a76d9a1568d15d3b4d3b361fb86b2963b3cf691275b4abe66b5e5760f8063dcc",
    "f2f2ac1d2f6cb623b2a01d86dcde3cc1cdf300d84bb48eeb7d7f501e090cf7a47b70bcc9508d70b6562ae636fd14d77f0179fe16f75b25057c13c75fe44fea6d"
    "72ba328ee2f8f37323a1b88f3b78288eef4cfdaf20cfa371fefcefbb9c9d661d1be72f8ac32b5f9c2387ebf3033734ee3fbb2744f985d074e4fa3d0e2fdf7f80",
    "e23c5ee77fb11b103a8c148e725bc56dbe4855437b47928fce77bd823c8ff87ffef75dca4ec7eef23fc323fe5fc4ff0cef3affff1df1bff7f9bf459e6c1742c7"
    "f9ee361595e34fc842980e97d2fee17fb4ee3b3f3792c9fe5e9d39c6eb6f1abfb78bf7a6fb795ed8c48b40f1cc720fc5fb509c7e8578284eef4cfd1ee4f30b5a",
    "04528f337f0f583c7d25e77027cf23d33cf2996bfcdeecb1ac9aa3fd9aafbb9f4dd592dbe3f6f19f51dcdefb3c2f6f05b983c471ba5d0b818bbe9ce352b94dd9"
    "473cff15e47974aef6aadd5deebfff0da4be65f5f573081e6e91cfbba739c6f0a468b9a4cea975e375dfcffc6c01be2177e49ebf798ad457765df40f7ff95244",
    "711daffb8752292e9f173b816daa96dfcb531572a7909352fef10f13c8f3a85f9b13ec7d5c76fdc54f2178b8456ef5177dc034a2a2488e522c29cb34cff0ade9"
    "e7d6b5bfdfee7cf268019e21b76d477314a79a908bf633fe1f85fc82d7fdc2c56e26143f14aa5c892a34a2d5662637e40a3eba8fc76e7fae40eac72d72fbf306",
    "2d4274da6401299fce6610ee9ef3aaa17b796ce2f9ff9c37ba97679578e85e1e67eab7cbfb2548fdb8456e9ff77920e7c97c41cc2a5dbb65848d5cbeb7e1d8b1"
    "758045f72c33124ff29877d701e2503cb3dcd6fe1d5547eec779d07aef0af1dcbab7a11bed15b8f0a81a0e1c88c15e7c937edae7f2987f781df55f735ad57b79",
    "d1bdca303cb31cddabfca6785aba2d78e85e6567ea47e3f9f9b99160e3f931a4be65f5f643081e6e91cf7f2f57930540d38057e33905289e59eed47bb9a61a53"
    "9c808bfcff07b4ffc7fbfc4fb5b78a559e951b65c0257b7c26442563bb3edab77f03e3b2376fffcf38ef58fcfe7b103cdc22b7f03e2d8a60a9758b559dcfba61",
    "e37e49691edd2034b6d739df4afd539dad61dcffcfbd1314c7f73aef0ff9d2e0222770b17437919276e2bbdd3e08f8288e6f97f77390fa718b7c55ef633c83b4"
    "cf59bbfbd4b1f8fddb103c5c9748eae15bccbbf1fb2814cf2cbf6efc4fddc52f19876f3137ed20f2f5e123348ef73a9f936426561b9c6798a35cbcc7c6627c62",
    "bb98f7119fa3fe6b4eab8adfdb7b9fbac1f2ebdb87e99adf77286e63d88c7bf63289a0f7a97b9fef034f325b3bf1c17130101b0cd880c08613ad0b1fddb783f8"
    "de9c607cff39a4be65f5f411040fb7c8e79dd7321f44c8f24596acd3fae7fd726eebf9027c43eec8f98eb90a75fd3e1eeadd0e8aef78dd3f0072bf4391643ade",
    "08ed74a46a90ced584918fe60313c8f3a85f9b93d90e377c374fb86e3c08cd13e6b71fcd13dcc143f3047bf5ff1fd60bca73",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 43112U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_kF_info.c) */
