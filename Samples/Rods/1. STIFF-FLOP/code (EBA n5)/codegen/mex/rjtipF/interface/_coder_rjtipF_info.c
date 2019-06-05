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
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rjtipF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.3.0.713579 (R2017b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[28] = {
    "789ced5d4b6fe3d61566e6d5318ab603b44d67fa48e37430493113eb696bdc076a590f5bb2f5969f6921531225d1e643222959f6ca4081a28b2eb2eca23fa08b"
    "2c82aeb214d04dd14d81a2698aa240b328d0a03fa0c8a28b52a2ae2d32ba2366784589d4b980415f1ff27c97c7e79e73eeb90f52af2452af5014f565f5e796fa",
    "d3bbdfaf51d49728ad3c185e6f51fa62a4bf32bc3e33d451b94bddd13d87e8bf195e2ba2a0305d45ab70acc0a4db7c9991d48a40f3cc359baac8b3022d28c58b"
    "2643498c2c721da63aa0d4588e29b23cb32b8e54b659b5c2c74748d7953ea9ff7ba4c154ce0a6d9e921af24d73b9d10a35229f5f63deff8e49f98430f27930e4",
    "8fe8efc47e16f981674f6624d923cbbe90ffb9df1365e433456c7a7c2baf178a8978fcedf86e26eba98855c6239d2a6c33bec25fb7b38b69c73d93edbc8d69e7"
    "d2f0fa50f7d71f6e68d71f0daf3fde40ed38c1e09895d75d4c3b1ea8943effa6783ed0125278f70cf51bbc7b03fe55b15de6981bbcdf5ac4dbc2e269fc11fd9d",
    "c4eee14025b292589768fef5beeeca9e54b8b81bdef4e4fd5e5fa8ec5144912b8b5d0fc3731e8e2d7b785ae1e8b2476cca9e819c46f4e304d32eb3fa61bca2b2"
    "44dd1ffe76f5e9efd7fe1ab60f4f2b8b8287ebdf66f5ee550c1ed23b443f68ec336b855c61355fccb50fa33bc7fb62612f72d38eec049c49eda03075bbf83bb5",
    "ff3631ed32ab6fb70c7554907d7fa0fbeb1b1bdaf5c9b55dbfc2f0372bb7ef62f091dc10bdefdda415560d0e2481e6565879b3cd724a4250c30346622b33b3fb"
    "1f58c43bc4e269fc11fd73eb4dffe7e9406a9ea7486c1ea3d856781bfdc0f7fef5f70fc10f4c09cf2e3f90e9b422e1da76e7793117bca8c478c11f3fe6b6dde3",
    "07dec73c6f568e59439d1ab96fb4fd84fcc0728d5306bfdaaa7757a90d527af70d0c1e9217a21becbf5ca1395a8ad56766f7e7564fc6da7d242e5bedfdd2affe"
    "01f6dee9f6de9b3e0ff145963fde61f3d5d84eb452a8d52e36c1de2f4e3fa674f61e37de302b2f63de8f1ab9efd6089d95052d4455fa19bed9e575acea47068b",
    "a7f147f4978a076a6c97a93645553d3c3a79d99adfa11ec51f819d77ba9ddf0a9c5d145a75968b142367f9d666bd78b6178b829d5f543b8fc3332baffb863a75"
    "7ddffd017f56aeb1ea70a6e154bb9ec4e269fc11ddba5dd7e4a49af44101bbee0e3cab76fdeb183ca47f88de6931b166a722af1f9e0744312b177c81a363ca3d",
    "76dd59f9d71bbbbe5c632559a9b1b6ea5fef8458defe350c1e921ba2ab6228a9af5faa8912278acd92d861a41a279e972afdf976eb71bdb1e0da83caf5fa8697"
    "c443fc4f0c75231ea25bc9f30dd5e805f2b3359ff3de4777611e775efd81d9385fde897563d1cbcb6cb2eb0fa6fcde482eecf3c6dce30f3ec13c6f568ebfc0f0",
    "477244f469f7ebe517df506a305cb3bfe0c55e7ddd22363eb863a853d7f7ddb91e1ff4eb339e6760852ad34d080ab17502f109ed407412e386fe98c146fd780c"
    "f3bbcef70f858b26cbafb6f2073eb65c0d268e73d994afe3a23c10f45f7dd1eb9bd73579fe49fea5d2a0fbcb4521cf8fb9a202f9207bf020cf4f863fc4fffaf7",
    "22abaf0962f1ffa47cbdfaea3cdd75ae3f98eafc00d2234efdc5a349cafef981abc7f796201fe4747f20b5bccd53560e86f9b56c48c8960f033bfbb28bd6f780"
    "3fd0bf17d9f9627bfd012b803f30e70f586106fee04df007cef70775fa2894091ca45ba1725889acd2992013cc6db9c71fc07cf1f82b2a3afdfbf884987dffbc",
    "f97eab7876efdf75715e10f2fa53c483bc3e19fe56e3b3aca14e8ddc67697de73ceddba26ed677fe12c3cfacbcdec2e0217921ba613e956e36b98b4d56a0a58b"
    "c2c0b7c5db4245614581d4bcc35726b40bd16b43dc528316aaaa2340f87fb0884f4fc0477432f101569c28fcb733fefff07f70ce83e3fdc425438b61211d3856",
    "ea75ff963795a9ee1df85ce4277a98e7cdcaf118c31fc911d149f9096d0450aa7122ad94d0213794cd7ad83b86fdbe16f1a6165fcccdfe11d8ef3b4d3cd8ef4b"
    "86bfd5fccf01863f9223a293b2ff82a8a4e974464aa85dbbae1a7f7bf3fb07c4f23f93ce6f6365811628e7eef34d60f134fe884e20bfdf97d42ce27bc8034d11",
    "cfaefd60ad703bc3072f0e83debce46f477ccc7a874f53eeb1efd08fc7b75faf778f89ed0383f3db7078d3980f82f3dbdc8a07e7b791e10ff1fdf82b2ab8f8fe"
    "0ac3cfacdcbe85c1437243f4b1799d951a278a5a62cba97e600f8ba7f14774327ee0a92637cf406e8318c2463ff02aec0370be1f2837d6b28702a7540b221f6b",
    "0bdb81726c33e9a2753e739baf9da7f9e0ab34b1bcfed73078485e886eb0ff8c2489ba75962716dbf179d775ce65fc2fab8d64aa1ecdea0f6dbfd1050c24676b"
    "fc2ff69ec0fcaed3edbe503ccad1fea3ede340a7d38e1d767c013ec9bae81c7fa77c97e504d30eb2faf513dbd66fca2d69f0d11ea7aedfdcc6e269fc11dd5ade",
    "afd6163c7d49d97aaedfdbd12710af3bdd6e07b762b586772d719a8905124a3627089d48d445791be8bffaa2d73772df5bf936060fc909d13f93af8f8a3ccd0a"
    "3163bcdeb4d81eabeb359d95b7d189d1e6bc0db5f4a74d88dfe7d50f989dbfe552a972cc1788ac9eb3954a4c6e761a47f51dca3d7e00faf3f82b2a7afd5b2316",
    "df4f3eaf596ed292cc38757d4e1a8ba7f147742bf1415f42fd0801c9cade7d5a575fccff17e2fc79b5ef66e3fc552ebf7d2ea69e6f05f6b6eba14ae432994f14"
    "5cb4fe12e27c7dd1ebdb5b908fb78807f9f869e1696551f0201f4f863fd87b7dd1ebdb0ab1bcce373178484e883e7efd0dcade5bb7fbc6826b0f2aa4ec7e7102",
    "1ea2935d7fa3e9cce87b9c60da49721de69fff0d71febcda7db3799ce7eddd82773f90094b89404c384ce6d784fc1a05767fd1ecfebb187e66e5f47d0c1e9213"
    "a28f3b87417f644042c872748519de3f2ff97dabe7319427e0233ac1f318c68a7506dfef0a9cafc2f8605efd84d9f1c16e72a772d4caae878f524149f637597f",
    "279474d1790cd0bfc7bfd7a28e1f5e767e00c60fe3afa8c0f8c11e3c183f90e10feb3847f56b83d83cef1730780f544a9fbfc4c80dbac9cccc8ebf6f116f078b"
    "a7f14774ebfbb787921a3a7e1bedf77f56fe09f67b5eedb7d9b83ee13d5d6f5f84038237e04d9f2bbe5885e9722efa0e23f4e3f1edd7ebdd3362f3bd0f317848",
    "5e886e88df055aaab342a57136abbc7fef25f110ff9f4ec04374e2f3bdd792b33d7ebffd2cff17b0ff53c2b3cbfe5f74cf13eb74bc565ff5563231b1701a6f87"
    "ce5d64ff7b98e79ddaaf717a61560f6f63de6769787da8fbeb1b1bdaf5c9f0fa8c58fc3fe91c3674128353e37f7bce6feacf1bdd9cbdd02fb09fcb1d7876d9ff",
    "e7ad50a6d8e2a2ab679b8d626eaba0b4a2d14adc3df61ffaf1f8f6ebf5ee7562f97b38870d876761dd279cc3765d16050fce6123c31fecfff8f64feb1cce7939"
    "7fcd58cce6819cb5ef0fce5f732b1e9cbf46863fd8fff1edc7d9ff7731fc601d28ac137bd17b99d03358073a453c58074a863ff4eff1ef654e1fc9ad039d9771",
    "c4acf248308e98169e5616050fc61164f85b1d472cc63aa29b7380ac7ed777198387e485e8c671842c3392b24f736cb5c05e3261a93ebc6f567ea067116f6adf"
    "f91c1f4f7c467c338823fef8bbafc238c1e9fe20c596138564ecb8b9cd6fc5d6d737739df3cb75179d27d1c33c0ffd5a5ff4e7fc6f101b1fc03c330e0fe699ad",
    "e1696551f0609e990c7fab7923c650a746eebb35429f9e3f5866e53e5d65ca5136ebe3c6916deb4afb2f59a3605da999ef82aa9282effbba0ccfb6f343bb292e"
    "7ed6a99e26d60ebbc9aae40f0a85355857ba40fdb85fe0fbbe10efebdb0df1fe6cf120de27c3df25f17e596c0b5599b23bdecf11f30bdfc1e0213922fa67fcc2",
    "f043c7114e950d456e3c60f739d3fb583c8d3fa293f20ba362b3f7bb02d4a77796605ec0e97e212eec6637c307e94b96ef664e9b553ea3a42f5c342f007e61fc"
    "7b99f30b7bc4f24093e27355043cdd9d9dddb73a7e4c62f134fe884e60fc389094fdf345578fef81bd77bcbd975adee6292b07c3fc5a362464cb87819d7d7913",
    "ec3dd87bb55cd96bef5901ecbd397bcf0a33b0f76f82bd77bebdafd347a14ce020dd0a95c34a6495ce049960ce45eb40c1de8f7f2f73f1fd3eb1bccfcb7e3f58"
    "a832dd84a0e4194e6cf6e9b3da67dc7b493cc4ffc45037e2213af173a97412b4755e602f28c0bc80d3fdc3ee6e3c120aa7a4646d9797f96ca3113ef45dba683c",
    "f009e679b372fc39863f9223a24fbb5f2fd73891564a957e9eb7541105856605b9846e4259739bf5f5638698ff7884c14372467483ff184825a5fe8d1bd29d3a"
    "6f90c7e269fc119d4c1c7223b6198c2b607fd914f1ecf21b9de781608849ee646ad175e53844e777232cefa2f9e4bf619e372bc7aea14e8ddc37fa7f9abadf60",
    "e592ccd605a6aa7716b6ea67af02792593789057228da79545c183bc1219fe3dccf3b09f4c5ff47ab80576de241ed879d2785a59143cb0f364f8f730cf839dd7"
    "17fd3c710ad60599c4837541a4f1b4b22878b02e880cff1ee679b3723cc2f04772447482e7052d776869f0d199525312ab86f739c1b497ac1edee46dae30fccc",
    "caef350c1e921fa2ab2229a996ac5413254e149b25b1c348354e3c2f551a4ce50ce6875fa83f5ad8f002f9d93a3ffcde4777c12f38dd2fc83bb16e2c7a79994d"
    "76fdc194df1bc9857d5e177c8fecff1bbfcaad", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 67800U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
