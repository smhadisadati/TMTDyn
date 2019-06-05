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
    "789ced5d4b6fe3d615669299498ca22d81b669d2471aa783498a4caca72dbb2bcb12654bb61e96e4675ac8944449b4f990484a96bd3250a0e8a28b2cbbe80fe8"
    "228ba0ab2e0574537453a0689aa228d0591468d01f5064d14525511c9b37ba23cef08a12a9738099abeb43deeff2e0f09c73cf7d907a29997e89a2a8aff5ff0d",
    "ca27af0dfea7a8af523ad1a3f265ca4c28ffa551f918a91b749fba67bacfe0ff7a54566449e3ba9a5e117889cbb4c532a7f42b122b724f9ba9ca222fb19256bc"
    "6a7294c2a9b2d0e1aa434e8d17b8222f727bf29dca0edfaf88893baca795016bf03bd6e02a1785b648290df5b6bbc2dd0a75473ebfc23cff3d8bf28960e44323",
    "fc0f999fc67eec3b503945f5a96a20125c0ffae29c7aa1c94d5f60e5ed423199487c90d8cbe67c15b9caf994738d6f2656c489fd7c60b19faf62fab9342ad74d"
    "7fcd6fea655c2f3747f59b51fdc6e033a33ab369f4f30cd30fabf2bc8fe9273de234e5cba11691c27b80d46ff1744e556e9705ee16ef3736f1b6b17866fe87c9",
    "bde3a1cae414b9aeb0e2db03dd567de968712fbae5cb07fd8148d9a7c9b25096bb3e4e147c025ff689ac26b0659fdc547d4339ddd19f334cbfacea0f5a1ab444"
    "bd36fa75f3c5efd7fe1a750e4fa745c1eb62dab3aa77af63f068847fd438e4d60afb85d57c71bf7d1cdf3d3d940b07b1db7ee426e04cea0785a93bd5be5bdfdf",
    "26a65f56f5ed65a46e9061ff69d35fdfd9d4cb474fedfa0da67dab72fb01069f46f803efa7acf0fde0419158618557b7dabca025a57ef8c0297c656676ff7736"
    "f18eb17866fe73ebcde0dffb43a9f9de37c4e643c5b6223ae8077ef8afbf7f0a7e604a784ef9816ca7158bd6763aebc5fdf0558511a560e254d8f18e1ff80473",
    "bf5539e6903a855c67f009f981e59aa00d7f3aaa7737e94d527af76d0c1e8df011fbaf5658815598faccecfedceac958bb6f88cb517bbff4cb7f80bd77bbbdf7"
    "672e236291174f77f97c95d98d570ab5dad516d8fbc5798f2993bdc78d37acca0bcd0b52c875069f57253d44d50619c0d9e575ecea47168b67e6bf503c50e3bb",
    "5cb529f7d5c3679297a3f91deacdc49b60e7dd6ee7b743175785569d1762c5d845beb5552f5e1c3071b0f38b6ae7717856e5f51a52a79e5ea77378b5c6f78733"
    "0db7daf51416cfccb76fd77539f54dfa90c0ae7b03cfae5dff16068f46f89d16c7343b1575e3f83224cb39b510089d9c52deb1ebeecabfdedaf5e51aafa85a8d",
    "7754ff7a67c4f2f66f61f06884df1743a9fff8a59aac08b2dc2cc91d4ea909f265a932988fb71fd7a384eb8f41065eef05f18cf6cf903a8a67f0ede4f9466af4"
    "0cf9399acff9f8b3fb308f3baffec06a9cafee325d267e7d9d4b7583e174d01fdb8f06fc8c77fcc1e798fbadcaf1e798f669843fedf77af9d917941a9cd01c2c",
    "7871565fb7898d0fee2175eae9753a6710f70eca19cf33f05295eb26258dd83a81c4847e187c12e386c198c141fd7808f3bbeef70f85ab262faeb6f24701be5c"
    "0d274ff773e940c7437920787fcd64d637bf67f2fc93fc4ba5c10e968b429e1f531a04f92067f020cf4fa67d88ffcdfd25abaf4962f1ffa47c7dffd145b6eb5e",
    "7f30d5f901438f84fe0f9f2e29e7e7076e1e3e58827c90dbfd81d2f237cf79351c15d7721129573e0eed1eaa1e5adf03fec0dc5fb2f3c5cefa035e027f60cd1f"
    "f0d20cfcc1bbe00fdcef0feaec49241b3acab422e5a8165b65b3612ebcbfed1d7f00f3c5e34b834cfaf7e48c987d7fde7cbf5d3ca7f7ef7a382f0879fd29e241",
    "5e9f4cfb76e3b31c52a790eb0cbeabf76d51b7eb3b7f8169cfaabcdec3e0d1081f994f659b4de16a8b9758e5aa30f46d89b654d178592235eff0f509fd32f8b5"
    "116ea9c14ad5be2330f0ff60139f9d806ff0c9c40758711ae1bf93f1ffa7ff83731e5cef27ae39568e4a99d0a956af07b7fde96cf5e028e0213fd1c3dc6f558e",
    "a798f669844fca4fe82380524d9059ad641c724339ac87bd53d8ef6b136f6af1c5dcec1f81fdbed3c483fdbe64dab79bff39c2b44f237c52f65f92b50c9bc92a"
    "c9feab5def1b7f67f3fb47c4f23f93ce6fe355899528f7eef34d62f1cc7c02f9fd81a46611df431e688a784eed076b45db59317c751cf6e795603b16e0363a62",
    "86f28e7d87f7787cffcd7af790d83e3038bf0d8767e6c3f96dcf8ba7d3a2e0c1f96d64da87f87e7c69102ebebfc1b467556edfc5e0d1087f6c5e67a526c8b29e"
    "d872ab1f38c0e299f964fcc0fbbadc7c43b90d630807fdc0ebb00fc0fd7ea0dc58cb1d4b82562dc822d396764265662be5a1753e739baf9da7f9e09b0cb1bcfe",
    "37317834c247ec3fa728b2699de599cd7e3cefbaceb98cffd57e27b9aa4fb7fa23db8fba80a1e41c8dffe5de2398df75bbdd978a27fb6cf064e734d4e9b499e3"
    "4e2024a6780f9de3ef96efb69c61fa4156bf0a8eaddf545bcaf0a33e6e5dbfb983c533f3ede5fd6a6dc9379094a3e7fa7d107f04f1badbed76789ba935fc6bc9",
    "f32c134a6ab97d49eac4e21ecadbc0fb6b26b3be91fbdecaf7307834c2ff52be3e2e8b2c2f3168bcdeb4d91fbbeb35dd95b73189d1e1bc0db5f4a72d88dfe7d5"
    "0f589dbf15d2e9321308c5562ff94a85519b9dc6497d97f28e1f80f7797c699059ffd688c5f793cf6b569baca2726e5d9f93c1e299f976e2838184061182212b",
    "67f769dd7c25ff5f88f3e7d5be5b8df35785fccea59c5edf0e1decd42395d8752a9f2c7868fd25c4f96632ebdb7b908fb78907f9f869e1e9b42878908f27d33e"
    "d87b3399f56d85585ee73b183c1ae18f5f7f6364efeddb7d9470fd318894dd2f4ec033f864d7dfe83a73f739ce30fd24b90ef3cfff86387f5eedbed53cce7a7b",
    "afe03f0c65a34a32c448c7a9fc9a945fa3c0ee2f9addff08d39e5539fd08834723fc71e730988f0c484a3981ad70a3ebe725bf6ff73c86f2047c834ff03c86b1"
    "629dc1f7bb4297ab303e98573f61757cb097daad9cb4721bd193745851834d3ed889a43c741e03bcdfe39f6b51c70f06bed3ebf761fc302d3c9d16050fc60f64",
    "da87759c77d7e91789cdf3be8ac1a3471c85531b6c939b991dffc426de2e16cfccb7bf7f7b24a991e377d07eff67e59f60bfe7d57e5b8deb93fef38df6553424"
    "f943fecca516602a5c57f0d07718e13d1edf7fb3de3d2636dffb06068f46f848fc2eb14a9d972a8d8b59e5fd7b2f8867b4ff930978069ff87cef53c9391ebfbf",
    "f238ff17b0ff53c273cafe5f752f931b6ca2565ff557b28c5c384fb423971eb2ff3dccfd6e7daf717a61550f5fc13ccfd2a87cc3f4d77736f5f2d1a87c4c2cfe"
    "9f740e9b7112835be37f67ce6f1acc1bdd9ebd3020d8cfe50d3ca7ecff7a2b922db684f8eac556a3b8bf5dd05af17825e11dfb0feff1f8fe9bf5ee6d62f97b38",
    "870d8767e6c3396ccf8ba7d3a2e0c1396c64da07fb3fbeffd33a87735ece5f43c96a1ec85dfbfee0fc35afe2c1f96b64da07fb3fbeff38fbff11a63d5807aadf"
    "03ebc4c63f97053d8375a053c48375a064da87f77bfc7359d34772eb40e7651c31ab3c128c23a685a7d3a2e0c138824cfb76c7118bb18ee8f61c20bbdff55dc6",
    "e0d1081f1d47a82aa76887acc0570bfc351755eaa3eb66e5077a36f1a6f69dcff1f1c497c4378338e28fbffd068c13dcee0fd27c39594831a7cd1d719bd9d8d8"
    "daef5c5e6f78e83c891ee67e78afcd64de3fb009f3cc1499f101cc334f0b4fa745c183796632eddbcd1b71489d42ae33f8d3f307cbbc3ae0f71b152887f571f3",
    "c4b175a58387ac51b0aed4ca7741fb9282effb7a0ccfb1f343bb692171d1a99e27d78ebba9aa120c4b85355857ba40eff180e0fbbe10ef9bfb0df1fe6cf120de"
    "27d3be47e2fdb2dc96aa2ae574bcbf4fcc2f7c1f834723fc2ff985d1878e63425f3614b9f180d3e74c1f62f1cc7c527ee1aed89cfdae00f5c5bd25981770bb5f",
    "48487bb9ade851e69a17bbd9f36655cc6a992b0fcd0b805f18ff5cd6fcc201b13cd0a4f8bc2f0291edceceeedb1d3fa6b078663e81f1e35052cecf17dd3c7c00"
    "f6def5f65e69f99be7bc1a8e8a6bb988942b1f87760f550f7d4706ecfdf8e7b2a48f37ceda7b5e027b6fcddef3d20cecfdbb60efdd6fefebec49241b3acab422",
    "e5a8165b65b3612ebcefa175a060efc73f97b5f8fe9058dee745bf1f2c55b96e52d2f29c203707fc59ed33eebd209ed1fe195247f10c3ef173a94c1274745ee0"
    "202cc1bc80dbfdc3de5e221689a695546d4f54c55ca3113d0e5c7b683cf039e67eab72fc19a67d1ae14ffbbd5eae0932ab952a833c6fa9224b1acb4b6ac9b8c8",
    "c89a3bacaf4f3862fee34d0c1e8df011ff31944abaff3761c477ebbc411e8b67e69389436ec536837105ec2f9b229e537ea3b31e0a47b8d46eb616dfd04e236c"
    "7e2fc68b1e9a4ffe1be67eab72ec22750ab9cee04fdd6ff06a49e5eb1257353b0b47f5b35781bc92453cc82b91c6d36951f020af44a6fd1ee67ed84f6626b31e",
    "6e839db78807769e349e4e8b8207769e4cfb3dccfd60e7cd649e274ec3ba208b78b02e88349e4e8b8207eb82c8b4dfc3dc6f558e2798f669844ff0bca0e50eab"
    "0c3f3a536a2a7215799e334c7fc9eae16ddee606d39e55f9bd85c1a3117e5f24a5be252bd5644590e56649ee704a4d902f4b950657b980f9e167ea8f1e363c43",
    "7e8ece0f7ffcd97df00b6ef70bea2ed365e2d7d7b95437184e07fdb1fd68c0ef81ef91fd1fa7b2cc04",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 67832U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
