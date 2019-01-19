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
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/2. Passive/code/rksF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737443.03385416663));
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
    "789ced5d4b6f1bd7151ea7766023484aa0401e28dad84511a070a0a1288a940314109f226d51a4449a929536cabc480e392fce0c5fda54cb2ebac8aae8a28b2c"
    "d3a205baabd176c1eeba0dd076d19537fd09dd97c3e1a534635e732c0eaf3ce4398070757578cf77e7f8dcefbe0ec7d4ad7ce1164551ef8d7e7ef30b8adaf90b",
    "359677ed820a4dcab728a7b8f5b726e5c7ae3a923bd46d47bb5b13bcdf4eea9caa9842dfb42b92a808071d9915f451456164616a865765516114b332d0044a17"
    "0c55ea0afc58531325a122cac2be7aa592134715397b4535ad582aebf75443e05ae58e4ce90de3b2bbd2d50a35f18f2543ccf3dff6e89f2f30fe09b9f49f677e",
    "4e375459a01b0c2fd285cc5ec218281c9db36a898ea9560a95f440a1532a2f5cad270593a1bb9b1b613acbb0bac8d1918dfb25c630c4ae4073d667f59691dd90"
    "2f9fe74b4c7fdff6f83cee12c93deaee95da93dd79785efdf71d0c5e68a2e154fb1fce2fbcb75df54b3c5bc3ab1d56122ef1be59102f81c573ea3fcfef9f8c42",
    "a463e8b4a4728c44171295fd44923e8a84377758da54558955fbb4204bb424b2b4cc9812c3d28254eb28a34030ac10180bc138f8fbd34ffe95201b77a4e3fce6"
    "f0fa187b5ee3ee7d0c5ec8a5d72afd66bc689662f1225329372bfade80539297fd28cdc199d70f0a5327651fc6af539cf1f6e3298f5f60ec79f5d34718bc904b",
    "6f4d5afa86385a1ce80a236d18235731fa0662f9c579de2db8fe2041787fba261eb25f988387f4af1127d6cfc3b1bfe887c861f443db63d39821172fbbb15fff"
    "0ef83ee87cbfa3ef1bcc21577876cc3e3b6193c958b4561780efd78eefbfc2d8f3eaa79f60f0422ebd8bef194d9306e53185653b0a678aaa92574a12c3a12d21",
    "ea9fb660ffbe3ba77f485f9bf4e2acc128fc68e1efd7bef06773f0917ed1f900ef503bc4c8c5d7907da7f96f981f9684476a7e5099fd26cb307b297e6ba7699c"
    "4484c2a93648afcefc30c4b48771ed14671c7eeadb79cf5d579d9a7eced68886a131ba2104f5bc2787c573eaafb77eb07c63ad209097366482ebffbb3ffd02f8",
    "3de8fcde3bce1b59a955cd466a7a59ea368b8f95f3c314f0fb7af3fbc6ca9d035d97ffe11c6876ffe11c880c1e9c03f9637f88690ff7ba4eb9a97b5d4354c665"
    "50d7f924ce09473eba8173c25db8d75d221e297e67985cf2b4d7ca89d542aa2325934a3a5e3a58a1731c18bf4e7933ef7511cbc3bdaed7f53c8a1982e7f6bbb0",
    "9e0f3edf87b773b19d54ef38124ef67a525893a2e9faf90aade781ef9d02f7bab3fb07f7bab6c0bd6e30f0e05ed71ffb434c7b18d74e7933cffdfddb275cf73c"
    "08f609b3fb0ffb043278b04ff0c7fe10d31ecefd9d823bf7bfc0d8f3eabffb18bc904bef9a0774c168309a5016cfed2ff01937755ef4fc9a78c87e790e1ed22f",
    "3a0fbce4b0c9ce935cdc5c7cfb876f605f10f4f920b61796e2a5f861a99aab1ad5e358fdc951db5ca17d018ce7d9251267fcdddff52bfe3ec4e0855c7ad73ca0"
    "307a5d54b8462ba8fc5f9d8387f41ee3651414bac0d376b44c62c61d3a539f915d375c7cefb3a37f02ff2f098f14ff0ffabdfc23265bab6f87b962462d37b39d",
    "782f03fcffa68d675c3c788d3f5c3ecebd49f9a1e3af9feedae58f26e527bee505ddc1f42334d1d42455b5de1212d4bca01416cfa95fe49e69ec23f2eb03c80b"
    "5a221eb1bccf76bc58694be9ed56b25139dc2b9bed749acbae0edfc3f8750a6e7d7f81b1e7d54fb8f742855c7ad7fa5e34921d5132f3ca4147167491bb319e5f",
    "745d7084c573ea17dd17ba1d86120c08aef3fffcbfff00ef079df78bdd762a51cb75772a87d10197919548f654ca01efaf07effb970ffa7d0c5ec8a59f7dcf8b"
    "56f7c1cd072dcec1437abfee7951cc10e4fbdf1f7f047c1f74be671bb1d28922997c5995331d25b7c566928ff780efd78defbfc2d8837c505b860be2af5fde18",
    "e4832e130ff241fdb13fc4b48771ed9465e583be29fb84eb9e0fc13e6176ff619f40060ff609fed887fc9fd9251267fc85a7fcff4b8c3daf7e7b80c10bb9f4ee"
    "7d836108ba59652491b75c91d0eb93cf05f59ea082c573ea175e47bce438e2fb82b7523dd817047d3e88445ae78fd2d964bebedf2f9f9ee7d8dca32313f281d6",
    "703c8fe462d7b7bc1f78efa72df0decf7978b6ac0b1ebcf7d31ffbc0ebb34b244e5e4f401ed0e4ef900734bb4402794064f0200fc81ffb434c7baf7e3cc3d80f"
    "b9f4cb98071e8886a5afeb8c44360e87cf88e5f75b8f58a320bf1f973730fa851efb88fcf7799f03bf079fdfb7fb0529dbeaf2cd7ceca4ff98d72351a51c83fc",
    "fe3518bf96f897e709eb7a1c9e530febfad7c5b3655df0605def8ffd21a67d60d6f5acda517883f0bafed0b7f9e00718bc904bffd27c90b77634829e92469ea1"
    "fc5bf7df76d52ffb636bb806334e20f22b9fa7e4aa53aecf21fde2f3c15587113de7ffd5fbf7e09c3fe8f34056d92f2513c707e7a2dc2f36355e2e9a0783153a",
    "e71f62dac33ce014e73cf0d4b7f39d79ebf0910364a67f733cbfe8fe308dc573ea17da1f8e7d443c3fe7f907c0ef81e777bd1dd69aa2114dc8b1525c29b1275b"
    "4faa06bcbf73bdf99daa12e577eb65cdc0efafe677f45f4110e4f7bf02bf079fdfebccb37871ebf8a01d6713666a9b294685e821e4e34fedad559e0e95035ef7",
    "8807bcee179e2deb8207bcee8f7de0f5d9251267fee5019cc778c483f318bff06c59173c388ff1c7fe3f30edbdfa91c1d80fb9f44bf8feec832ea38f5fa57ca6"
    "e92aef7aae2f31fdf697e739dfee5f7f88c10bb9f423e79c8d9c725653754955b533b52be83549ed9d7196576eeebd6bc36be221fba773f090fe9af3801d56af",
    "f01cf9bc9ce1dffe7b07e687a0cf0fc6934c3f933e3f2f3dee47a28548387598d80cafd0f7695f60da7bf5e305c67ec8a55fdeb87ef0ea0f9c3504491374b271"
    "bae7dbfe60de7a5d346aa255fa352e3ec0e239f5ee3c218517fa79c59cf6e3eb05fbb13ba71f48ff9a715513fb02afa9a37ed396e748e6e750909fbf443c52f3",
    "4179a089f276fbe8785364f968fef4b054d8ecaed07bd7bec6b45fe3714b5d7daf8e86b1e7d53fefbaea94eb73482f1a8a9d506e0e34eb9d9b41cdbbcc63f19c"
    "fa45e2e18aa7d0329f240ffd11dea3167c5edfdb6a0dcaedba28a52aa9d6513b59afb49e665688d75f60dac33a7ff6f37a8bd33cdc0378c4837b00bff06c5917",
    "3cb807f0c7fe0b4c7be0ffd9cfebed7e802cff437e0fe4f72059173cc8ef59ccfeff017953fef8",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 47696U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rksF_info.c) */
