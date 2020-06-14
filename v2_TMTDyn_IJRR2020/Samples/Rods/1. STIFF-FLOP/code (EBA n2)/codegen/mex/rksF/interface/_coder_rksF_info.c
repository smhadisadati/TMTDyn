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
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rksF"));
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
  const char * data[18] = {
    "789ced5dcd73da4614571cc76d0e693dd39934997ec56d269d4e128b2f1bbb27630c36180c36d8b19d76889004c8e80b4960f0c9339de9f4d8de7ae81fd0430f"
    "9d9e7ae4d8e9b95fd34b7be8a1d3bfa0c74a883548f106255a4481dd195b5e3fe9fd568fa7df7bbb6f01e24a227d85208857f49f19fde7fc0ba2d36e980762be",
    "7b9c21accd2ebfd23ddeb2f541bb46cc5aae03f2afba475a1235b6a9991d9e13d99dba506415bd2352027ba18691044ea4442ddf9259426155896fb04c4752e2"
    "7836cf096c4aeaeb6c717a4788f7892e3a86c8f83b5a61e96aae2e104a45ed0d97efef107df6f91272ffb30eedb304b1cf7c573f903f8e7d1cfd90dc57594525",
    "55d51f0eac04c80d56ad6a924cfa17efe4f28978fc613c95c992b4c4b0a45255e38b42df389f40c631e7709cf62368d78997fb7a0fd606e139b5cb4b10bc795d"
    "62e8d75feb0aa5bfe6a8f0e66cfd1ede5c473f23d58b3cdbb3e7b72ef1b6a178a67e207f9c481d765efaac2295154ab863f8a84aa623f954649ddc0bf8fce122",
    "a949125f949a242bf024cf154981d278aa48b2bcfe07d9b554c71bbcf487f37f16fff839e2adff79edefa3c36b42f439f5bf9b103ce07f409ef09dacd65b91a0"
    "e80bfa764e357f8c669b7cac378eec009c41e320207daff4e3e7f8f2f1c378ddaddfc1f201602f2037a298b2c8e949802252fca24829654ea42b55b77c6f6fb0",
    "718006f0da2f8807f47f34000fc89fcb4f74875058a613f195eeeffbdd03b01c796139d3713ce4ffab0ff67ec2fc3f243caff8bfd53c4dac52f15279c9476762"
    "52ee245e0f9f4e10ffb721d78feb730df30ba77e7815723fd7bbc75b96ffbebb661eef758fe8f2ff6b9071cceb12437f899724633638aef97f028a67ea077277",
    "7943a92e921d4b75b3064ff9eae1c63d9cff8f3bffafd4c2997c8ddf58aaae57f2bb9b39adb6b141c72787fff1737cf9f8ad7e77e782d7cf21fa9cdaeb1d081e"
    "b01790dbf27f4e5daf73bc961077ea02ab70f4c878ff7b977887503c533f903fb7bf183f4f250976b32d0a1ee6ffeffdf53be6ff71e7ff4ca3168d94b61a2bf9",
    "dd508b8e0962207ecc6f61fe9f2efebf8b8cffdf80e0017b01b98dff559ae229651164fdeef37e7b73ba0ee496fff707e001391afebf6fdaadcf773ce4ff9bf1"
    "db98ffc79dff8b95e5eca1c86b4c4e126275712b588cad273731ff4f2bff7f0ed1e7d45e1f40f080bd80dcc6ff942cf3ad5c87cce27591d638494c88599ea2c1",
    "5600303ed9e5f85e1d303e202f754751a85022c3f7ead03fb8c42f0ec0077234f1016e56e0681efa59f074e9171c2f8684e755bc4825b7e9a35a763572940e29"
    "6a40e6028d70726372e2057ebe2fbf2f67feb83871f38851ad23e179c4b0f0cc362d78781e8146bfdb79c474ec235abee0ffcf20fa9cda6b018207ec05e4f679",
    "84aab28a7640f11c93e3ced88852ee9e37aa38d07689770cc533f50339a27ce229f38d208ff8f1bbd7f03c61dce3419a2b2672c9d8b1bc256cc65657d7771ba7"
    "67abd1c989076dc8f5f8b9b6368b1f9eafe13a3381ebccfde376303fc075e621e2e13a331afd6ed78d585b9fe83b6fa64f3ebc78b0c0a9865c57ca131efbe3da",
    "9167fb4a8d9b2c11785fe9e07964c75223a8479ddfc57c3ffe7cbfd44cf3f16a8339492c1f36938c120889b965bcaf748a9e63a3a1db5784f37d181ecef7dde1"
    "996d5af070be8f46ff84e4fb45a92e322ae175bebf8b2c2ebc05c1037604f2a7e242c298ebb04a94d76d43a09b0fccdafabdf1cc76f4d315aa53984615170ea0",
    "78a67e20471517facd6624151efacdbfb3d7715d60dce3425c4c65d7238f76ce38a19939911921a3edb426a82e80e3c2e5f7e52c2eec235b071a949feb2610a8"
    "e6e878dfedfc3109c533f5033982f963c752ded78bceefce61be1f7bbe576a3ef98453431161391b16b3c5c3e0f681ba8ef91ef3bddecebde57b4ec47cef8cef",
    "3971047cff3ee6fbf1e7fb327514ce041fedd4c2c588165da2322136b43b41fb4031df5f7e5fcef2fb0364eb3e6f42f0801d81dcbeee23326c33216a7b2c2fc9"
    "867c54ef336ebf201ed0ffc4d6b7e30139f2cfa5b258d0d3bac07e48c47581718f0fa9543c1a8ea495642925a842b652891cfacf26683ef037e47aa776fc04a2",
    "1fd811c887fd5c2f947889d20ab4b1ce5b303eac9be244b5004e02abe61efbeb9f2cb2f8711b8207ec0ce4b6f8d1b14a5aff1fdf958f6bdd600f8a67ea077234"
    "7948cf6c239857e0f7970d11cfabb8d1580986c26c723b53da58d58ec3d45e2aca0913544ffe0d72bd533b366d7da2efbcfed769e87183530b2a571659c61a2c",
    "3cf5cf368dd7951ce2e17525d478669b163cbcae84467f1b723d7e3f99b559fd7013f3bc433cccf3a8f1cc362d7898e7d1e86f43aec73c6f6dd63a711aef0b72"
    "8887f705a1c633dbb4e0e17d4168f4b721d73bb5e311443fb0239023fcbca08506a574be74a6202b1263bb9f2790f1a2f5c3debacd39449f53fbbd0dc103f603",
    "72dd24059dc90a2549e125492e480d5629f1d2698136be2714d7879fe93f66daf00cfb795a1ffee6d76b382e8c7b5c50b763cdd8c6d95936d90c84d2015f7437"
    "e2f74dd0f791b9ad0f7f0ad10fec08e4c37eae179e7d42a1c2f2b2f175cee3ba1e34286fe7d492f15dd3c89e8fd7a178a67e2087ec67ba18c7d72ec7111f300e",
    "207f21ff2a714d9691257df4a4613f8fdf3f863f576288785ec5875c4be684a5dade233f57644289e3dd6cdadf98a0cf9fc6cfafb559fdcd77c1ef32449f533b"
    "ddb0f589bef366fae49c2a9a1f81a0b564636feeb8ae0b65a078a67e2077ef177df6d21dc443ffb88df7f98c3fbf6f06abad5cadccf1d17cb4ba575b2fe7abfb",
    "b109e2779cff5bef0badbf26709dc0211eae13a0c633dbb4e0e13a011afd381e58ef0b6dddd8db7880f707e1fd41ff177ef61a0fef0f72a7ff3f79d3de52",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 37272U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rksF_info.c) */
