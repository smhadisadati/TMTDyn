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
                (737431.7759375));
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
    "789ced5ddd6fdb541477c7366d42034b48db1002568426a14d759a7e0e09a9f96cd2354dd26469d70199633b89936b3bb19d34e90b7d448807fe001ef6382190"
    "7863123c84375e9180079ef6c29fc03b761ca7f15deee2d58e8b9b7ba4eaf6f6d8e7777d7aeeef5e1f9f38c45c32354710c41bda4fe10b82d8f88ae8cb35a321",
    "c8417b81b00aac9f1bb437a0be2997888b96f3e60678df0efa8c24aa5c47353a8017b99d9650e264ad23d2023734c34a022fd2a29aef363842e61409b439b6af"
    "29f380cbf302b72d8d7412bcd611e223aa614757e9bf47aa1c53cfb50442ae2a27c305a31d62e01f5d9e21aeffa24dffec22fc4342fa47b1cfa8aa2470549566",
    "792a15db0c295d91a1127a2fd452a57c2a1fed8a544462b9d17e985369aabdb810a0185d53ae15db6c51a0d5f88260bd8ec788715eb6791d706bca55e2ca48ef"
    "d68689778cb067d76fb7107824a4d72f5b5ee0b56092451a2c682152a51b5c8e3f32fed1caa4eb9f341e5850e331c5adb8c94dc033f58f92dbfb5ae8b4149902",
    "1243032a15ca6f87c2d46e30b0b85ea254490225a9437102e8ffdce9fb8bba633a8c7ac16183c0f12e6e8e7ffffee95f216fe3d4eb797176781d843dbb71781d"
    "814742fad5cd0058cbac653385444129ecad56eeef36d5e8c938321370268d8340f4bdb28fe7f3f8d614d43ae034fe6e22f048480fad03222d577891a9d6fdca",
    "ff850978a6de66bc684121732c6544cb2066e0d019fa4c0f190ff9ffad8f77ffc0fc3f253caff8bfdb394cdea3e3e5ca4a8049c7a45c2dde5a3b8c61feffbfcd"
    "67543cd88dbfd710d77175d0deb4fcf5ee86d17e30686f6f38e56313f712621ce440530692a4df4dba857719ea9fe0191a566a95007782f7d4215e048967d5bf",
    "c27e01f0254abb35047489e240b925527d1f79bf3ff8f5c1ed3f31df4f09cf2bbe5f6faea5f34d105da987abf9ec664e6d46a34cfcfcf03d9ebf5699569ee77d"
    "041e09e9a1fd3daf845b3c5093e24e4be0649e39339ef72c3fe8f0be107698f7f9c1e39ffefd1bf3bedf793fdd6e4642e5447b3d9f5dee3231410cc60f4002f3",
    "fe6cf0fe87aef1fe3b083c12d243bcaf68aea2e5057377ef7c7f0f8bddfcce8fa7c433eda727e0997aa7bc7fc7f0d830663ce4fbeff6dec67cef77be2f555733"
    "fb2250d99c24c45a6262a9140b6f6d62be9f35beff0661cfae9f3e42e091901ee27bbad100dd5c9fc2e22d915179494c8a19403366898039be86c3f1bd39617c",
    "a6be3c1845b14a8bac762360e2f71ce27f3a01dfd43b5d0fd00e3502ccbbf8ea955eafe1e7be7e5f1f247abb56a2e9cd08bbb45e53f6835ceaa0d13d47cf7d7b"
    "88f3f1bcb68a350eefba96e7bf02f589e17186865794062d2b9c5ff3fc09249e557fbafd83ee1b7d07617a6941f02e0e36ae7cf239e677bff3fbe15e5289837a",
    "211e2ccb39d0aea5b7c4a36c04f3fb6cf3fbc2b9cb039d96ff711e68fcf8711ec81b3c9c0772c73eaeef1cdf9a628dbfc090ffbf44d8b3ebb779041e09e9e1bc"
    "90a270b25aa001cfeaae08c995c1717e7d0e9c47e259f58ef7112f38cef3bccf85c821be2ff0fb7a100cd68fee45e3e16465bb933b384a9412f776555cef3983",
    "f35993e30d9cefb18987f33d6ee119322b7838dfe38e7dccebe35b53acbc1ec2759e83bfe33acff1ad29b8ced31b3c5ce7e98efd1ee27cbb7e2c22ec93907e1a"
    "ebc03cafe8fa8a4c036fe3b0f7d0b3cf6fe9975826f0e7b7507561da2f54df47debfafe119e677fff3fb4a2705e2f5365b4baeee77b65839b82ce656f1e7b766",
    "60feeae25e1d3fded7a3f0ac7abcaf7f553c4366050fefebddb1df439cef9b7d7d496a89ace2f1be3eebda7af02e028f84f42fac0749fd8e86932340f30ce1de"
    "beff22d43f198fa161aa74bf80c8ad7a9e0cd427a0e34cbdf3f560d4619ee6f9bfbe7e15e7f9fdbe0ec4c5ed4c38b4b773c40b9d74adc10a6975a77b8ef2fc3d",
    "c4f9781db08a751d78e05a7e67d23e5c73804077ce8ee79dde1f46917856bda3fbc3be8f3cafcf797603f3bbeff95d6e061a355e590e09ab99353153da5fba5f"
    "50c298df679adf8982a7fcce8b98df27f13b2f7aceef3f637ef73fbf57e8876be9a5bd9de65a29a44656e8f432b79cc5f5f8437b3355a7432430afdbc4c3bcee",
    "169e21b3828779dd1dfb98d7c7b7a658eb2f77703ec6261ecec7b88567c8ace0e17c8c3bf67f439c6fd78f34c23e09e9a7f0f9d9f9362df75f955f6cc8120b5d"
    "d763c4b8dde579c6b5e7afef21f04848af39a7a839a558966420498da2d4e6e432900e8b8cee95b37baf66ef9478a6fd830978a6fe94eb8011562ff19cf77539",
    "bd5ffeb984d707bfaf0fcafd5827163d3aca6c7582cba96020920d2d06ced1e7699f23ceb7ebc763847d12d24f6f5ecfbffc806295030d4ef6364e375dbb3f98"
    "b45fe795b2fedd9aaecd0bd4f78692901eae131259ae9314d5e1389e381cc7c6847198fa578cab32dfe1d886a48d9bd23de7657d0e81ebf3a788e7d57a90eb36",
    "7861a5b9bbb7c897d8e5e44136935a6c9fa3f76a3e419c3fc3f396187daf4e0361cfae7fae417d023aced4f38a681494abfa372cfbb7ee3289c4b3ea9dc4c388"
    "a7cc6dbe973cf4037e8f9aff797d73a9decd352b3c88e423f5dd66b892af3f889d235e7f8e381feff3c75fafbd384de2e70036f1f07300b7f00c99153cfc1cc0",
    "1dfbcf11e763fe1f7fbdf69e0f78cbffb8be07d7f798322b78b8bec799fdff00f2c63b93",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 35416U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_vd_matF_info.c) */
