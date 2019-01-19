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
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/rjtipF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737429.71692129632));
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
  const char * data[28] = {
    "789ced5d4d6ce3c615e6a6bb6916455a026993f42fcda6c522c506962cc9b2b7e8b6d6af2ddbfad7da5e27a94c4994449b3f1249c9922ef5b1871c72eca1871c"
    "d3a20db645812c9aa0506fbd16687ae8698122e8a5d7f65c51146d0f5713d1e68816a5f700634c3d71bed1c3e337336fde0ca91b89e40d8aa2be3af8fbe3cf29",
    "eaf025ed8aa25ea474a147e573142a66fd8d51b964ba36e4167513b9efc608ef57a3ebb224aa6c47d52f784e64532da1c4ca830b9111d8b36a2a92c0898ca816"
    "ba0d96925945e2db6c65a8a9723c5be0047647ba70b1c90d2e84f805d5d985a6d2fe8fd4d9f271be2550725d396f2e7ff1821ad94793c798df7fd3a27d5218fb",
    "d026fddbb1773d7549603d75a6c27992b18d90d215cb9e4ded2ad452a542b210ed8a9e8854612f5e875995f1b49797bc9eb2a6918f54ae115f12cedbff4b4cfb"
    "9eb7d8fe2f63da7f7b54ae219f6eadebe583519918953f1e953fd1cb53e3f39fae1bed3cc4b4c3aa9d6f61da498f340de964e85da4f09e375d9fe3e99a8ad42a",
    "f1ec39de8736f142583c54ff7662677fe04a2d45f6f05299e13dc950612714f6e47cdee5b592479524be24753cacc07b78aee4111895674a1ea9a1788616d25c"
    "672893ec64d57fcca521b7a91746ff9dbef759f01f21e7f0745914bc0ea63eab7ef732068f36e9f7eabb6c309fcdafe40ad9d67e74fb6057ca3f8c9cb7233301",
    "67523b28ccb553f5bbf5f96d60da65d5df9e335d1b62f03f8d7c7a775d2fdf38e3f5534cfd56edf63d0c3e6dd26bdd9fbcc40d0615b2c8f04b9c126e71bc9a10"
    "07c30a56e6cad7c6fb4f6ce2e5b078a8fe127ea3fddd1bdacb73cf3098c76c30c3911cec073efeef3f3f837e604a784ef503e9763312aa6eb6d70ad940b71c13",
    "445ffc80df9c9f7ec0ee7c600b533f6dd2dbee07ee5479d518f4520efbdd69729d94dfbd82c1a34d7a13ff2b03933172ac766dbc3f837e3296f70d435d03df7f"
    "74f76730ee773bdf7b73b5e5b6ba755f926b75251f676ae178a21d05be5f9ce79842f81e37dfb06aaf174dd794e97b869e53447da0aa6a91c1eb8bebd8f58f04",
    "160fd55f723c50e53a6ca5210ddcc38358ea1ae23bd4eff6be09e37ab7f3fc86ffb89b6fd6383e52881ce79ae15ae1f8610c787e61791e8767d55e2f98aea9b3"
    "efe91a4ea97283494dddadf1fa28160fd5dbe175dd42ba27009fcf079e5d3eff06068f36e9db4d36d6689795fbfb277e49ca28f965ffa3036a7ef8dc2d71d773",
    "3ebf53e56445ad72e8ef38c4b493a8fff50f89c5eb5fc3e0d126fdc018c581118a5549e625a95194daac5ce5a59362595b9fb73f9e370bae3d861878fd2be219"
    "f51f4cc033f4578bef8ddce80b2ce7fcb8a0ffe9e7b7208e33abfd81d5f1bdb21debc4a2bd5e66abe30b247dde4836b4ec8dcd4f7ff01473bf553b9e62eaa74d",
    "fae93dd777bef80bc53acb3758d9593fdd20361fb869baa6cebea76bb4d1ae565ef3ba022756d84e4254cfdaf181cd76ac4f6887a1b7374f58121cf48b27b08e"
    "ebfefe20df6d70c24a33b7b7cc952a81c44136935c9ea7b8fe0798fb17f8b91d88776ee2f893fa93729d19ae8c431c7f7c6908c47d9cc183383e99fa9f62ee87",
    "71fef8df6bcd4f13c4c6f993e2f0831f2e309debeb076634ee6ff80f3ff8c7a3dbc8e9b87fffc92bb721cee376fe979bdec611a704424230b32a664afbfeed5d"
    "250cfc0ffc8f0abaeeeb2cff7322f0ff24fee744c7f9ff13e07ff7f37f8d79b49af6efa59aaba5901a5961d2013690dd981ffe8775dff1a52188ff3d3d24c6eb",
    "978ddfdbc5bb6c3ecf0736f1d6b178a8de45f13e88d34f110fe2f464ea77219ff75859525a02fa3b70f1f4a9ecc3edbfb33e2cd7df758cdfab2d9ed74ac8d71c"
    "376e571a8c5c6d891ecd4a4e8fdb4f7f0f717bf7f3bc1af409b9e8de46fdc02ff5da6a52882797d539e2f9c798fb615fed45bf3bcfbfff05a63eabf67a138347",
    "9bf4a6fc17a6d1e0bb614e64e46e7ed8e3c55b6259e52491d4baf1d726b4cbd05747b8c53a2356061d01a9fccdb727e01b7abbe305ac21472bbb0ef60f7ff8b5"
    "0c711db7f70fd96c443dce1c79574b07a9ed54a9c0aca5934a7c7efa873ee67e78ae5141fd7095587ff17d0c1e6dd29bfb8bb6c45542b2cc74e33ca3aaacc889",
    "b5e1f7ae2bbfdfee7c7277029ea1b7ed47630c77f15cbf434c3b09facfe9ff4ad02fb8bd5fe86d6dfa230f1bfb42b694ae84f6ab9bc98e909ea3f378ec3ecf05"
    "4cfdb4496f7fdea047888a555e62d4e2d90cc2d97d5e07702e8f4dbcf9dfe70de7f24c130fcee52153bf5ddecf62eaa74d7afbbc2f4a6a8a49a5e5c4e0d1ae19",
    "612387cf6dd823b60e30e99c654e11199172ef3a40048b87ea6de5ef6836723ece03ebbd53c473eadc8666a8951602ddfd803727fb5a9165f67e5b4851f3c3eb"
    "f0fca282fadb0f889dd300e72ae3f0503d9cab7c593c5d16050fce5526533f8ce7c79786e0c6f3a798faacdaeddb183cdaa41f1bc759aaf292a45bc0adf19c34",
    "160fd5dbed07eee916f30c2d36e8041ce4ffdf40fe8ffbf9bf540f66f6455eade42521d61237fda558786b8ef2f667302e3b7bf93fa72962f1fbaf63f06893de"
    "c4fbac2c4b96d62da6b53f6bc6c6fdcaa0796cc5a3b3fd88f3cdd43fb4d9358cfbffbcfd08e2f86ee7fd8e983de9251b4278a3198d2b6b91ad665bf2ce511cdf",
    "2eefa730f5d326fdb4deaf7888691f59bfdb762c8f5f69cac39772ba357e1fc6e2a1faabc6ffb42c7ecd46cef3f9fa5f1ede8571bcdbf93cb011abd6bdc1c451"
    "3ae64fa899ac28b623d1398ae3c0f38b0aea6f7789c56dbe83c1a34dfa67e2f75149603831661ec7376cb6c76edebe5be23888019d8de3fce93f908fe97afee7",
    "9342453896d96423b2a7ae49ad4af5518b9ba3f377e0391edf7ed4ef82c4c6f393dfa3a2ed3d5558b78ee737b178a8dedebe5cc34a4e9ebfb0fec203c8b3743d"
    "9f9fec2594387fbc1bf755e53cdf3e4a6f89bd6c04f87cb1f8fc01ecb31a09ecb342db6dc17f609fd514f1609f1599fa21ae830aea6f6fc2baac4d3c58979d16",
    "9e2e8b8207ebb264ea07be4705f5b7256271fc6f61f068937e7cfea5b15a7b7de37cbbf343cbebf784f22f0d9f71ce5ffa1fffebdfb06e3bab7c6f75dfd55a6b"
    "27efddf5a74372c21f13f7b772413117a480ef178defdfc7d467d54e3fc4e0d126fdb873d7d0038512628667caece8fbb3b28edbb789ffce047c434fe49ca6b1",
    "0675fc5cfdd2578e603e30abfd83d5f980c4ec1c9518662352f1af1d29fb3e3679d0e8ced17ca08fb91f9e6b54503f7c0bd6792de2c13a2f293c5d16050fd679"
    "c9d4dfc7dc0ffc8ecabcc781aecaff10071adf7e8803398307712032f53bf61cbb7a3f569218efbf8ec1a34d7a13efcbac52671a6c9eebb111edad908a5bf37c",
    "f213f00cbd5dde7fc660ce9fbff6b7df7e08f38059e57fabf380e086975fcdac6633bb9bbbcaee5eb0b69d6bced37b58e0791e5f1a82fadfebc4f27e5ec5e0d1"
    "26bda91f1019b9c689e5fab15bf99f709ea795bc9f339b393b6e387de947b9bf03ff4f09cf29feef764e12f79978b5b6e22da76352fe28de5a3d8901ffcfdaf3",
    "8cf307abfef725ccef30deb7f82af2e95beb7af9c6a83cdfe77b88c12175deb271029b5be3fed33eaf75f8d6c5d1996b9a38c84f705ec314f19ce2fbb5e66aba"
    "d0e4a32bc7e17a21bb91579bd168798edeab05cf2f2ab8f1fd29a63e386fd91a1e9cb73c2d3c5d16050fce5b26533ff03e2ad33a677f56ce57368bd5f8cee32b",
    "e219f5c3f9caa4f17459143c385f994cfdc0f7a8e0f8fe7d4c7d90dfaf4bdf26fee2e589417eff34f120bf9f4cfd7dccfdf05ca332adfccf5999275c353e04f3"
    "84f1ed8779823378304f20533fe4ff8c2f0d41fdcf7bc6ff76cf7dbb83c1a34d7af3bc41515859dd6578aea2992224d746df73eb3a41018b87ea6d8f239e319c",
    "e3f382e72227302f707b7fe0f31df7ee47e3e1446da7933fe86d9636efe754c8075ac0e77920a7ebb0dfd7221eecf72585a7cba2e0c17e5f32f503af8f2f0d41"
    "793d047940a3cf210f687c6908e401398307794064eaef63eeb76ac722a67edaa49f463f708753347d4d667867fdb0ffc8b1fc7eed275629c8efc7e50d0cfef1",
    "0c6de4fc7ede27c0efeee7f7954e928f1fb72b4789e07e67ab22fb02623e08f9fd0bf0fc6a422ecf13c6f5383c540fe3facbe2e9b2287830ae27537f1f73bf6b"
    "c6f525a925561487c7f55962fdc1773178b449ff4c7f90d06634ac1ce10796a1c88dfb2ffb3e97c736f132a66bcaf43d436fbf3fb8683047e3fcefbd7c1be2fc",
    "6eef07e2e24e261cda4bf538a1933e6a5484b49aeace519cbf8fb91ffa0154d07ee021b1f8cea471f8c00002d3b93e9eb73b3f8c62f150bdadf9e1d0468ee7e7"
    "3c7905f8ddf5fc2e37bd8d234e098484606655cc94f6fddbbbca1cbd6fbd8fb91ff81d15d40f771de5774e047e9fc4ef9ce838bf7f02fcee7e7eaf318f56d3fe",
    "bd5473b51452232b4c3ac006b2908f7f56df42e5e9509bc0eb16f180d749e1e9b22878c0eb64ea075e1f5f1a82e65fa6201e63110fe231a4f07459143c88c790"
    "a9ffaf98fbadda91c1d44f9bf453d83f7ba7cdc8c3a3948b0d59aa987ed721a6dd6479be4c6cfdf5350c1e6dd20f8c531c18a55895645e921a45a9cdca555e3a",
    "299635ab5cdfb96bfd2be219f51f4cc033f457ec0774b7fa02cb399f97d3fff4f35bd03fb8bd7f50b6639d58b4d7cb6c757c81a4cf1bc98696bd73b09ff6ff7e"
    "8f0df7", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70520U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
