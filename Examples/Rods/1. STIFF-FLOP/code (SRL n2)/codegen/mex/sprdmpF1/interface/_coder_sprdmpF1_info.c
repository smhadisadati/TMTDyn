/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sprdmpF1_info.c
 *
 * Code generation for function '_coder_sprdmpF1_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF1.h"
#include "_coder_sprdmpF1_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("sprdmpF1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (8.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.88287037041));
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
  const char * data[23] = {
    "789ced5d4b6cdbc8196676934582c5767968bb5814689bb408ba4861ea65d92ebaadde0fdb7a59b2252bd9daa4444994f91249bd7ca98e3df4b0bdf4d4438edd"
    "022db6bd34c01685f6deebf6d05e8202bdf5da9e4b491cdb2434916c529449cf00ce78fc93f30dfffcfcfe997f1ec4eea533f7300cfb9afaf3fecfd57ffe864d",
    "d37bb30cc3b5fc2d4c9f8cf27b5afec45006e901765f77df3d0def375ab926f00a3d50660596e1e96c97a368492df024475f54531738862779a53414694ca265"
    "81edd1f5a9a4c1b07489e1e87de14a21c5a8052e71457451988826bf475b74edacd8e530a9255f3697bd5ac034fd4cd2e790e7bfbfa47ef210fde006f9f3f827",
    "444be068a245d61922134f86e5215f23529352b8ab08a54c2936e489a850a7af9623b442123def8687a84d24b228d53931e1dde040fb4f21ed7b67c9f61b7390"
    "1e610faf9482a14578cbeaeb6d081eae496ac2ec3fca2abc770ce54bbc99a42e742996bec4fbad49bc30144f2f7f9edeafa826d1952582156a244b64c2a5fd70",
    "8438f079bcdb14a108024b090382e65882652882231596a4089a6d7479d514e40d4eabc7463bf8f2f0e957617bedced6e75b2bde0052dfb276f74d081e6e908b"
    "a5417b2ba7e4835b39b2546c97a4e4b0c6472edb01f80a86b3a81d18a46c57fde8fdd527bdbd7dff82c74790fa96d5d387103cdc209fb82d6983513b03124fb2",
    "1bb2aa2a52da002c6f9ee78d09d61e90acf2fb990578407e0d3b99fc3c9bea8b780614463c9b69ecc266ecb39750f0d79f21be773adf6f4bfb3259a8658ecbd4"
    "71858a4482814693467c7fe7f8fe53487dcbeae923081e6e901bf89e144576589c5258a2cbd71446e0d37c9e256b600808da279a6cdffb0bda07e40dad15272d",
    "92afab1d7f803f3689ff62013e909bf5077085ce4ccc3efb1a53efb6ff8efcc38af0ecf20f02b9dfa6483219adfbb7db72c54767aae230e61eff3086dc8fde6b"
    "7dd2dbe10f2d8bf73c3494b18beb6612469645529269a7c67b52503cbdfc66fd87896e263d08a0253be37ea1871fff0cf1bbd3f9bd5f4ecb09f6ec28e16b4845",
    "b6d7ceedf2e78528e2f7bbcdef1bae8b03dd94ff511c687efb511cc81e3c1407b2a67eb3ef71de50c60cd701f9aae6715f42dab7acddc1fad98fb43ca4fbebae"
    "568c69f98e9687b47c5bcb7faae53fd6f29f58362e7800692fae4944a13f5d2de0d471c16ae38a822813530dad21ae38fae55741342e70ba3f28b78ee860b150",
    "dc3c2815ba95d85ef548281eba685ce0d4f71716075fd6dede329441027e00d7fdf56968963fb16c3cf01d083e6e901bc6038c1ce932ac92e6b35d8e9698dada"
    "78ff9549bc03289e5e6e763c60541830241bfdc09ffffb0f342e70ba1fc8f53ad17023d5db2e1502c35a9ce37d892a9b728f1f303b2ed885d48f1be4a6fdc0e3",
    "06ab804e2f66b3dd8d3221abecee03081e6e90cf8d07c59b8e8d03adc04ee6f23e50d41af8fe0f4fd17c80e3f9de73d0f4f694dd1d416ab6e462826c4612e99e"
    "8be67bd17b3cbffd30be878d3796d5d77b863266b80ec819999f755495c94e0fe7c6fbd3503cbdfc9afd810633a0eba2a09a07a1d3d43ad68dfdbefc21ead73b",
    "9de793feb361b1d364d868297a76d089344b678771c4f37796e76178d6ade36930eaa0a6e5d4787d0c8aa7979be1f599866c9fef477cbe423cb37cfe0d081e6e"
    "90f73a745cecd5e49d4adf2f0879b9e8f51f5731f7f0b953e2ae977cfeb8c148b2d260f4cf710a69a7a5f6373eb52c5eff6d081e6e90abca38519570d2102456",
    "10c413a1474b0d56e89fd426fbadd7b78f6b7c433c507f75011e90df70ffc7cc8cdea039fbfb05e3bffcfb018ae3dc567fb06cff5ede8b0fe2b1f3f3fceec017"
    "c8f83cd142d8eb89bbc71fbc86dcbfac1e4790fa71837c75eff5e3375f70d2a2599196ecb5d3a465e381fb86327671dd4c32e9ed4ef235cf2b307c9d1ea479e5",
    "a21d2f4db623b4a01d406e6e9c60ebf91eafd03caef3fd41712832dc66e7a0ec65a87a205d2de4335e37c5f55f42eebfc3efad9a3cae89e32ff227b516399d19"
    "4771fcf9394828ee630f1e8ae35b53ff6bc8fda89f3fff7997b3d3b465fdfc457178f5c13972b03e3f704be3fe17e77fa8bf10331dd97e3ec3ab0f1ea1388fd3",
    "f95fea78c4362307c25c30bfc5e7a98a7fef4876d1beadd790fb11ffcf7fdea5ec74642fff333ce2ff45fccff0b6f3ff1788ff9dcfff4df2782be72f673b5b54"
    "58896e92b9001d2824ddc3ff68de777e0e92cefe5e9f5ac6ebd78ddf9bc5bbee7a9e9726f142503cbddc41f13e14a75f211e8ad35b53bf03f9fc9c9604b9cbe9",
    "9f03164f5fc93edcf18bd0340f7d621bbf37ba2c3bc9d17acd379dbb36d192ddfdf6d11f51dcdef93caf047ddc41ac9c6c55fdc2794fc970898c577111cf7f0e"
    "b91fedabbd6a7797ebef7f01a96f597dfd0082871be4f3ce5f8e303c29190e9fb36ade78dde72e3f5f800fe4969cdf374f91daccae8dfee14f9f4928aee374ff",
    "50284495b37cdbb34555b37b59aa446ee73272c23dfe610cb91fbdd7faa4b7c32dcbfcc5f72078b8416ef4173d81a98725891c26585251689ee19bd3ebd6b5be"
    "dfec78f268011e909bb6a3398a9b98908df633fa1f85fc82d3fdc2f96eca1f3d142b5c81cad5c395462a33e0722e3a8fc7ecfb5c82d48f1be4e6c70db308d149",
    "831548e5e4620461ef3eaf2a3a97c7249efbf779a37379568987cee5b1a67eb3bc5f80d48f1be4e6799f17942c99cd4969f5d56e82b091cde736942d9b075874"
    "ce3223f3248f39771e200ac5d3cb4daddf99e8c8fe380f9aef5d219e5de73674c2dd1c171856029e03c9d78d7ae99d1e97c5dcc3ebe8fdd5a7557d6f179dab0c",
    "c3d3cbd1b9cad7c59ba5bb8287ce55b6a67ed49f9f9f8304ebcf8f20f52dabb76f41f070837cfef7b61aac20cc34e0d4784e0e8aa7975bf5bdada9c654276023"
    "ffff0eadff713eff53ad60bec2b34abd2870f12e9ff253f1c8ae8bd6eddfc2b8eced5bff33ca5a16bfff3a040f37c80dbc4f4b92b0d4bcc5aaf667ddb27ebfac",
    "368fae1333b6d738df48fd539dada1dfffd7bd6314c7773aef0ff842ff3c23729164279690b7a3bb9d9ee071511cdf2cefe70d65cc701d90afea3b8ba790f659"
    "6b771f5b16bf7f1b82876b1279b2f916736efc3e0cc5d3cb6f1aff9bace297c1e65bcc4efe097d79f814f5e39dcee724998a54fb6729e62813edb291081fdbca",
    "675dc4e7e8fdd5a755c5efcd7d271db0fcfad6619af5fb990578406e55dc06d88c7df6320ea1efa43b9fef3d9ba9e076b45ff67922fd3eeb11d940ac79eea2f3"
    "7610dfeb138cef3f85d4b7ac9e3e82e0e106f9bcfd5afa8d08693ecf92355abbde2dfbb65e2cc007724bf677cc55a8ede7f150efb6517cc7e9fe4120f7db1449",
    "26a375ff765baef8e84c551cba683c3086dc8fde6b7dd2dbe186ebc609378d07a171c2fcf6a371823d78689c604dfd28ce3fbffd7abb8bd916e72729799aa338"
    "3f7cdca8ea680de3c6f118c5f99dcfe71d8aaa370222952be58b5241f02693ec7ec0457c8ede5f7dd2dbdb77d13a7dedefb76cbd0e5aa77f4b78d86e3cb44edf",
    "9afa11efeb13ecfb5923487df6c46d40ef1ecdef2e1bb7013663633fff57fffc11e27ba7f37d7b335968d60b47e99d44d6bb734415369b8d7c14f1fd5de37bb3"
    "e7ab3d81e0e106f9e2f9ddd975b7655ed76cffff70013e90af60fec76e7ff0afffa0f3d61cef0ff68ebc6742e0bc41d6fbfdf2812f90d9491c1ebbe83beae87d",
    "9e9f83a4b7bf4dcbfc033a7f7396d0f99b2bc39ba6bb8287cedfb4a67ee40fe6e720e9ed2fe5baf8d04de705507c687efb517cc81e3c141f3257ffff01d231d4"
    "2b", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 52248U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_sprdmpF1_info.c) */
