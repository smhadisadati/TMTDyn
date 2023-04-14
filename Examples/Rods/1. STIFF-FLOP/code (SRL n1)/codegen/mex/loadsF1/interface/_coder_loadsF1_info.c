/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_loadsF1_info.c
 *
 * Code generation for function '_coder_loadsF1_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "loadsF1.h"
#include "_coder_loadsF1_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("loadsF1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.88295138883));
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
  const char * data[20] = {
    "789ced5dcd6fdbc81567b6c922c162770514d80f146d3745b140918529cbb2e42cb080be2d259625598aec78db3a14494994f82592faf2657deca1873df5d4c3"
    "1eb7450bf4d6a0ed41bdf55a60db434fb9f44fe8bda4a8914d461331264587d27b80311a3f717ea3e737bf7933f334266e158ab70882784fff79ff2b82d8fb0b",
    "319577cd8208cdcab708abd8f5b766e58f6d75247788db96e76ecdf07e3babd392a8b123cdacf09cc81ef68506abe8159112d879338c247022256ab5b1cc120a"
    "ab4afc8065a69a26c7b3354e600fa42b953ca75784dc15d5bc62a88cd7e9364b77ab7d8150daea6577f9ab1562661f43fe84f9fcb71ddaa784b14fc8a6ff32fb",
    "0bb22d092cd9a6188e2c66f793ea58a4c9bc514bf635a956ac65c622999618f66a3dc56a1439d8de0a93b4a1e1258a5173db5bc2bcff234cffde76d8ffef61fa"
    "7f6f567e64f9ed5ec22c7767652c81faf10c83e3d48eb87e84661a5a32ff805ee1bd6dab5fe2991a46ea3778f612ef5b9778492c9e55ff65e1e0447795beaae8",
    "7f6c9ae2c962b276904c914791f0f65e83d424896f482392157892e71aa440693cd52059bed91775175175cf3065999d9cfa87bd44728fb88b5efefdc9a7ff4a"
    "fa8837954dc1c38d6fa77ef701062f64d3cbb551275ed2cab17889aa553b35657f4c8ba9cb7e9497e02ceb0781a9fbd53e8c5fab58fdeda7731ebfc0b4e7d44e",
    "1f63f04236bd319d295b9c1e242822c56fa9baa928650bb1bc7b9eb70bae3f48bc8a078a4bf090fe35fcc4f87930b517f900198c7c605a6cee33fef94b22f69b"
    "df01df079deff7940395aad0c5a7c78da7278d542a166db658e0fb8de3fbaf31ed39b5d3cf3078219bdec6f7942cf3e3ea94c2727d91d638492c88659ea2d1d2",
    "10f54f76d9bff797f40fe99bb35e9cb52991d1037f843f7189fff325f848ef763ec01bd47431fffc6bd278a7f36f981f5684e7d7fc2051079d0645eda7999dbd"
    "8e7a12618ba7f238b33ef3c304f33c8c6bab58fdf033cff67beedaeac4fc7da686535599525436a8fb3d792c9e557fbdf8c1b08d1141202b6d093ec6ff77bff8",
    "25f07bd0f97d785c50737cb79e8b34952a3fe8941e89e79534f0fb66f3fbd6daed035d97ff611f6871ff611fc81f3cd807f2a67db7e378b3ce773f4f98657c56"
    "3ef4ed7c57e5c46919d478df8ffd42dd4637b05f9880f3dd15e2f9c5f314954f9d0ebb79ae5e4cf7f9544accc4cb876bb49f03e3d72a6fe6f92e627938df751a",
    "d7239ff171ff3e01717df0f93ebc9b8feda587c791706a38e4c3321fcdb4ced728ae07beb70a9cef2eee1f9cef9a02e7bbc1c083f35d6fda9f609e87716d9537"
    "73ffdfbb75c2a6ecffc33a61bdf0609de04dfb41dfff7f86e99fa77e7771e819ef7f82c10bd9f436de5758b54dc96c953b37bfc0a7ded4fed0f36be2a1f6ab4b",
    "f090de2defbf64b0d94ad33fbfb9f8e71fbe857540d0f93fb61fe6e3e578a55ccfd7d5fa71acf5f8a8a7add13a00c6f3e21289d5ff3e4978e57f1fd9ea84ed7d"
    "486f9b07444a697122ddee0695ffeb4bf090dea1bfe84ea1b00c697acbcc67ecae33b799e1323ef2fff73f3ffa0ef87f45787ef1ff78342c3ca472cdd66e982e",
    "65a56a27d78f0fb3c0ff6fda78f6370fe8b38459fe64567eea591ed01d4c3f42334d939724e39690a0e601a5b17856bd9b73a5a98dfc8f0f200f688578bee57b"
    "f6e2a55a8fcfec7653ed5a65bfaaf532193ab73e7c0fe3d72ab8f8fe02d39e533be1ee850ad9f4b6f89e53537d8ed70ae2615f60158ebe319e771b171c61f1ac",
    "7ab7eb42bbc15042818f71fe9ffff71fe0fda0f37e69d04b279bf9c15ead121dd359418ce44ef93cf0fe66f0be77f99f3fc0e0856cfac5e7ba28ba0f6efea7e3"
    "f3208fce7591cff8c8f7bf3ffe18f83ee87cdf68c7ca2722af315549c8f6c5fc4e239b7ab40f7cbf697cff35a63dc8ff3465e2127ff3f2c420ff73957890ffe9",
    "4dfb13ccf330aeadb2aafccf37659d70ddfd2158272cee3fac13fcc183758237ed43fecfe21289d5ffc273feff15a63da776bb8fc10bd9f4f67583aab28a56a7"
    "788e314c91545ab3f705f59ca086c5b3ea5dc7112f19cef775c15be921ac0b823e1f4422ddf387995caad03a18554fcff38dfcc3230df28136703ceb7291f02c",
    "ef07eefb3405eefb5c8667caa6e0c17d9fdeb40fbcbeb84462e5f524e401cd7e0f79408b4b249007e40f1ee40179d3fe04f3bc533b9e61da0fd9f4ab9807ee73"
    "aaa16f2914efaf1f4e9efa96df6f7cc42601f9fdb8bc01fd0539b591ffdfe77d0efc1e7c7edf1d15f95c77c0740ab193d123468944c56a0cf2fb3760fc1ae25d",
    "9e27c4f5383cab1ee2fad7c5336553f020aef7a6fd09e6f9c0c4f50da92f32aacf717dc5b3f9e08718bc904dffd27c50305634ac92e675cb10dec5fdb76df5cb"
    "fe981aba4d4d1388bccae729dbea84ed7d48ef7e3eb86a305ff7f97ffdc13dd8e70ffa3c90130fcaa9e4f1e139278c4a1d99114adae1788df6f92798e7611eb0",
    "8a751e78e2d9feceb2385c3780408d6e8ee7ddae0f33583cabded5fa706a23dff3739e7f08fc1e787e577a61b9c3a9d1a4102bc7c572e364e7715d5da3fb3a27"
    "98e781dfad62f5c3baaffc6e5cce0cfcfe6a7e47fffac1477eff2bf07bf0f9bd453d8d97768e0f7bf146524bef52a5281bad403efebcbd8dcad321f2c0eb0ef1",
    "80d7bdc2336553f080d7bd691f787d71890477df3e0e0ff6634c81fd18aff04cd9143cd88ff1a6fd7f609e776a470ad37ec8a65fc1f767ef0f28657a95f299ac"
    "488ced733dc3f4db5b9ea73d3b7ffd11062f64d3ebc639d38d72d694145e92e43369c02a4d5e1a9ed186556eeedeb5c935f150fba74bf090fe9af380e956afb0",
    "9cff793993bffdf70ecc0f419f1fd4c7d95136737e5e7e348a448b9170ba92dc0eafd1f7695f609e776ac70b4cfb219b7e75e3fafeabdf70d666799955fcf5d3"
    "7dcfd607cbe2754e6d7246e9d5b8f8108b67d5dbf38444861d15446dde8f6f5cf623b1a41f48ff9a7ed5e4462c234b7abf49c3727ee6e710909fbf423cbfe683",
    "ea58e684ddded1f136d760a285d34ab9b83d58a37bd7bec13cbfc1e396b87aaf8e8c69cfa97ddeb5d509dbfb909e534533a15c1bcbc69d9b41cdbb2c60f1ac7a"
    "37fe70c55228ccf79387fe08f7a8059fd7f777bae36aafc5f1e95aba7bd44bb56add27d935e2f51798e721ce5ffc799df96901ce011ce2c139805778a66c0a1e",
    "9c0378d3fe0bccf3c0ff8b3fafb3f3017ff91ff27b20bf07c9a6e0417e8fbbf6ff0f52b6f0c6",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 47696U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_loadsF1_info.c) */
