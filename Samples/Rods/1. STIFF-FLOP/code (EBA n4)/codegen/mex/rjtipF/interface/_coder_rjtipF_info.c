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
                (737431.800462963));
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
    "789ced5dcd6fe3c615e726d9208b222d81b449fa9566d362912281254bb26c070d20591fb66ceb5b2b7b9da4322551126d7e4824254bbad4c71e72c81fd0438e"
    "69d116db5eb2688242bdf55aa0e9a1a70045d04bafedb9a228da1eae26a2cd112d4aef01c6887ee2fc460f8fbf9979f36648dd4924ef5014f5cde15ff1171415",
    "7a49bba2a817295de871f90c858a597f675cae98ae0db94b3d87dc77678cf7abf175451255b6abea173c27b2a9b65066e5e185c808ec45355549e04446540bbd"
    "264bc9ac22f11db63ad2d4389e2d7002bb2f5db9d8e1861742fc8aeae24253699f230db6729a6f0b94dc502e9bcb5fbda0c6f6d1e431e6f73f67d13e298c7d68",
    "93febdd8079e8624b09e0653e53cc9d87658e98915cf8e76156eab52215988f6444f44aab257afb75895f1745657bc9e8aa6914f54ae195f112edbdfc5b4ef79"
    "8bed7f16d3fe7be3f255e4bfef84f472635c6e868c761c6370acdaf12ea61df458d394ce46de430aef79d3f5259eaea94aed32cf5ee27d62132f8cc543f5ef25",
    "f60f87aed256640f2f5518de930c17f6c35b9e9ccfbbba51f6a892c497a5ae8715780fcf953d02a3f24cd9233515cfc8429a6b8c649a9dacfa87b934e41ef5c2"
    "f8d3f9875f04ff11760e4f9765c1c33ddf56fdee650c1e6dd21f348a6c309fcdafe50ad9f66174efa828e51f462edb91998233ad1d14e6daa9faddfafc3631ed",
    "b2ea6fcf98ae0d31f89d46fefb20a4976f5cf0fa39a67eab76fb11069f36e9b5ee4d5ee18683065964f8154ed96a73bc9a1087c30656e62ab7c6fb4f6ce2e5b0"
    "78a8fe1a7ea3fdbd35b297e72dc3601eb3c10c4772b01ff8f4bffffc02fa8119e139d50fa43bad48b8b6d3d9286403bd4a4c107df1237e6771fa01bbe3fd5d4c",
    "fdb4496fbb1fb85fe35563d04b39ec77e7c91029bf7b0583479bf426fe57862663e458fdd6787f0efd6422ef1b86ba05befffd839fc3b8dfed7cefcdd5573bea"
    "eea624d71b4a3eced4b7e2894e14f87e799e630ae17bdc7cc3aabd5e345d53a6ef197a4e11f581aaaa45fe6e2fae63d73f12583c547fcdf1408debb2d5a63474",
    "0f0f62a95b88ef50bf3bf82e8cebddcef3dbfed35ebe55e7f84821729a6b6dd50ba70f63c0f34bcbf3383cabf67ac1744d5d7c4fd7704a8d1b4e6a1a6e8dd747"
    "b178a8de0eafeb16d23d01f87c31f0ecf2f9773078b449df69b1b166a7a26c1e9ef92529a3e457fd8f8ea8c5e173b7c45d2ff9fc7e8d9315b5c6a1bfe318d34e",
    "a2fe37382616af7f0d83479bf4436394864628d5249997a46649eab0728d97ce4a156dfdddfe78de2cb8f61862e00d6e8867d47f3405cfd0df2cbe3776a3afb1"
    "9cf3e382c1e75fdd8538cebcf60756c7f7ca5eac1b8bf6fb99ddae2f90f47923d9f0aa37b638fdc19798fbaddaf11c533f6dd2cfeeb9befff55f283558bec9ca",
    "cefae936b1f9c073a66beae27bba461bed6ae52daf2b706295ed2644f5a21d1fdb6c47684a3b0cbdbd79c28ae0a05f3c81755cf7f707f95e9313d65ab98355ae"
    "5c0d248eb299e4ea22c5f53fc6dcbfc4cfed50bc0b13c79fd69f541acc68651ce2f8934b4320eee30c1ec4f1c9d4ff25e67e18e74ffebdd6fc34416c9c3f2d0e",
    "3ffce102d3bdbd7e604ee3fe86fff0c30f1edd464ec7fd074f5eb907711eb7f3bfdcf2364f3825101682997531533ef4ef15952de07fe07f54d0755f67f99f13"
    "81ffa7f13f273aceff9f01ffbb9fffebcca3f5b4ff20d55a2f87d5c81a930eb081ecf6e2f03facfb4e2e0d41fcefcb6362bc7eddf8bd5dbcebe6f37c6c132f84",
    "c543f52e8af7419c7e867810a72753bf0bf9bccfca92d216d0df818ba7cf641feee0fdd0a80c7de018bfd7da3caf9590af3969dcae3419b9d6163d9a959c1eb7"
    "9fff01e2f6eee77935e81372d183edc6915fea77d4a4104faeaa0bc4f38f31f7c3bedaab7e77997fff4b4c7d56edf526068f36e94df92f4cb3c9f7b63891917b",
    "f9518f176f8b1595934452ebc6df9ad22e435f1be3961a8c581d7604a4f237df9b826fe8ed8e17b0861cafec3ad83ffcf1d732c475dcde3f64b311f53473e25d"
    "2f1fa5f652e502b3914e2af1c5e91f0698fbe1b94605f5c37562fdc58f3178b4496fee2f3a12570dcb32d38bf38caab22227d647dfbbadfc7ebbf3c9e2143c43",
    "6fdb8f2618eeeab97dc7987612f49ff3ff95a15f707bbfd0dfddf1471e360f856c395d0d1fd676925d21bd40e7f1d87d9e0b98fa6993defebc418f10956abcc4"
    "a8a58b1984b3fbbc8ee05c1e9b788bbfcf1bcee599251e9ccb43a67ebbbc9fc5d44f9bf4f6795f94d414934acb89e1a35d37c2460e9fdb70406c1d60da39cb9c",
    "223222e5de758008160fd5dbcadfd16ce47c9c07d67b6788e7d4b90dad703b2d047a87016f4ef6b523abec664748518bc3ebf0fca282fadb4f889dd300e72ae3"
    "f0503d9cab7c5d3c5d96050fce5526533f8ce7279786e0c6f3e798faacdaedfb183cdaa49f18c759a9f192a45bc0adf19c34160fd5dbed07ded22de619596cd8",
    "0938c8ffbf81fc1ff7f37fb911cc1c8abc5acd4b42ac2deef8cbb1addd05cadb9fc3b8ecfce5ff9ca788c5efbf8dc1a34d7a13efb3b22c595ab798d5feac391b"
    "f72bc3e6b1558fcef663ce3753ffc866b730eefff3de2388e3bb9df7bb62f6ac9f6c0a5bdbad685cd988ecb63a927781e2f876793f85a99f36e967f5fec4634c",
    "fbc8faddcf1ccbe3575af2e8a59b6e8ddf6f61f150fd4de37f5a16bf6623e7f93cf497870f601cef763e0f6cc76a0d6f3071928ef9136a262b8a9d487481e238"
    "f0fca282fadb0362719b1f60f06893fea9f87d5412184e8c99c7f14d9bedb19bb7ef96380e624067e3387ffa0fe463ba9efff9a450154e6536d98c1ca81b52bb",
    "5a7bd4e616e8fc1d788e27b71ff5bb20b1f1fcf4f7a8687b4f15d6ade3f91d2c1eaab7b72fd7b09293e72f845e7817f22c5dcfe767070925ce9f16e3be9a9ce7"
    "3b27e95db19f8d009f2f179fbf0bfbacc602fbacd0765bf01fd86735433cd86745a67e88eba082fadb9bb02e6b130fd6656785a7cbb2e0c1ba2c99fa81ef5141",
    "fd6d85581cff7b183cdaa49f9c7f69acd6dede38dfeefcd0f2fa3da1fc4bc3679cf397c1a7fffa37acdbce2bdf5bdd77b5d1decf7b8bfe74584ef863e2e16e2e"
    "28e68214f0fdb2f1fd4798faacdae9a7183cdaa49f74ee1a7aa05042ccf04c851d7f7f5ed6710736f1df9f826fe8899cd334d1a08e9fab5ffec609cc07e6b57f",
    "b03a1f9098fd9332c36c47aafe8d13e5d0c7268f9abd059a0f0c30f7c3738d0aea876fc33aaf453c58e72585a7cbb2e0c13a2f99fa0798fb81df5159f438d04d"
    "f91fe24093db0f712067f0200e44a67ec79e6357efc77a9718efbf8ec1a34d7a13efcbacd2609a6c9eebb311edad908a5bf37cf253f00cbd5dde7fca60ce9fbf",
    "f6b7df7e02f38079e57fabf380e0b6975fcfac6733c59da2523c08d6f772ad457a0f0b3ccf934b4350ff7b9d58decfab183cdaa437f5032223d739b1d238752b"
    "ff13cef3b492f773613367c70de72fbd93fb3bf0ff8cf09ce2ff5ef72cb1c9c46bf5356f251d93f227f1f6fa590cf87fde9e679c3f58f5bf6731bfc378dfe2ab",
    "c87fdf0ee9e51be3f2729fef310687d479cbc6096c6e8dfbcffabcd6d15b17c767ae69e2203fc1790d33c4738aef375aebe9428b8fae9d6e350ad9edbcda8a46"
    "2b0bf45e2d787e51c18defcf31f5c179cbd6f0e0bce559e1e9b22c7870de3299fa81f75199d539fbf372beb259acc6771edf10cfa81fce57268da7cbb2e0c1f9",
    "ca64ea07be4705c7f71f61ea83fc7e5d0636f1972f4f0cf2fb678907f9fd64ea1f60ee87e71a9559e57fcecb3ce1a6f12198274c6e3fcc139cc183790299fa21"
    "ff67726908ea7fde0bfeb77beedb7d0c1e6dd29be70d8ac2ca6a91e1b9aa668ab05c1f7fcfadeb04052c1eaab73d8e78ca708ecf0b9e899cc1bcc0edfd81cf77",
    "dadf8cc6b712f5fd6efea8bf53ded9cca9900fb484cff350ce43b0dfd7221eecf72585a7cbb2e0c17e5f32f503af4f2e0d41793d0c7940e3ff431ed0e4d210c8"
    "0372060ff280c8d43fc0dc6fd58e254cfdb4493f8b7ee03ea768fabaccf0cefae1e09163f9fdda4fac5190df8fcb1b187ef08c6ce4fc7ede27c0efeee7f7b56e",
    "928f9f76aa2789e06177b72afb02623e08f9fd4bf0fc6a422ecf13c6f5383c540fe3faebe2e9b22c7830ae2753ff0073bf6bc6f565a92d561587c7f55962fdc1"
    "0f3178b449ff547f90d06634ac1ce18796a1c88dfbaffb3e97c736f132a66bcaf43d436fbf3fb86a3047e3fc1fbe7c0fe2fc6eef07e2e27e662b7c90ea734237",
    "7dd2ac0a6935d55ba038ff00733ff403a8a0fdc04362f19d69e3f0a10104a67b7b3c6f777e18c5e2a17a5bf3c3918d1ccfcf79f20af0bbebf95d6e799b279c12"
    "080bc1ccba98291ffaf78aca02bd6f7d80b91ff81d15d40f8b8ef23b2702bf4fe3774e749cdf3f037e773fbfd79947eb69ff41aab55e0eab9135261d600359c8",
    "c7bfa86fa9f274a81de0758b78c0eba4f07459163ce07532f503af4f2e0d41f32f53108fb18807f1185278ba2c0b1ec463c8d4ff57ccfd56edc860eaa74dfa19"
    "ec9fbddf61e4d151caa5a62c554dbfeb18d36eb23c5f21b6fefa1a068f36e987c6290d8d52aa49322f49cd92d461e51a2f9d952a9a556eefdcb5c10df18cfa8f",
    "a6e019fa1bf603ba5b7d8de59ccfcb197cfed55de81fdcde3f287bb16e2cdaef6776bbbe40d2e78d64c3abde05d84ffb7fc6be0a11",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70488U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
