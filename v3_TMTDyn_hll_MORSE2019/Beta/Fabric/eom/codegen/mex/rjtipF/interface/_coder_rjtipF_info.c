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
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/rjtipF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737612.38663194445));
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
    "789ced5d4b8fdbd615a693b8b011a42590360f144de3b4301a241869341a695c2080de23cd8c5e238da45192ca944449d4f02191d473532dbbc822abaebac832"
    "299ac2eda6061214caaedb024d175d79939fd0ae4b89e28cc9f05af290a286d4398041d387bcdfe5f1e577ce3df7f00abb9548dec230ec87d29f2f7f8b61ad57",
    "676718f60a260bbe38be80a945abbfb538ee68ce15b98dbda4baefd602ef0f8bf31ac78ae450944f688a25533da64af2d2094b30e46533758ea1588215f3a30e"
    "89f1a4c0d17db23ed734289acc530c79c23d7512a7a41326f694eaf264a69afd3ddc226b17b91e83f12de1aabbf4d327d8c23e33798c78fe9756b4cf19c23eb8",
    "46ff61f463578b6348578ba853ae1cd1205dc9e8615018b135577cf64ff9643e32625d61ae4e2a7f0f9122e1ea7b76dc6fc74f4e5c31a2ca533517c9312ebe2d"
    "529dd80ef3d4733c44f4f3072b3e87f6a8c85decced5c9e438b00c6f55bbbd88c0c3179a1a27ff879985f703cdf9159eaca973bd2a4d5ee17d6e102f88c453eb",
    "3f4c9c94a4a1d1137817cdd508da950ce64f8221d7a9c7bd7b5075891c4757b9a18b6468174d555d0c21d244d545d28d1eeb926c341f0333b1701c7c7376ffdb"
    "a0a5e30eb3789c6f106f88686fd571f71a020fd7e83bf961db9f16333e7f9ac8e7da79fe7054634357fdc82cc159d60f0c716e55fbf0feaa453dde7e79c9e313",
    "447babdae94d041eaed1d724bfc6ef505250c0b304bd2348a622f81d85e58df3bc5650fd5144c17b744d3ca5fde4123c45ff1ce364f6e7bdb9bd5cef290673bd"
    "275bec72cc58375e02bedf7f017c6f77be3fe04f04225b4b9e17abe7a56a28e4f3369a24f0fdd6f1fda788f656b5d3bb083c5ca3d7f03dd1e9d0a3dc9cc2623d",
    "b626521c9b6033345153a6824aff3a06fbf7a325fd53f48d452f2a2d82ad4b81bf823f3588ffd1127c456fd41fa00d2a0f31ebc6d7b4fa72fbdfe01fd6846795"
    "7fe088937695200ec3f5bd83b650f290c9726714718e7f9822ee87f75a2dea71f8be69f99e3b9a73ecf23a5943094287e005d2aef99e38124fadbf5efc30b3cd",
    "2c8250acb4c35818ffdff9e037c0ef76e7f7413121c4e88b42ccd3e07374bf9d3e62c7d930f0fb76f3fb8ee3f240d7e57fc803e9f71ff240d6e0411ec89cf661"
    "3d57ffa8887afc9d58b69e2b50ecfc68d7f8de8afca064a30de40703b09ebb463cab789d20e2a1f2e0224e1592e11e1d0ab1117f26e5a0fc0dbcbf6ab999ebb9",
    "0acbc37aeeaa71bc32662cccd707208eb73fdfbbf7e3be83f0a0e871870603dadda1bd91e6d841713cf0bd5a603d57bf7fb09e2b0bace7da030fd673cd697f8a"
    "b81fde6bb5dccc7cbf79f384ebe683609ea0df7f9827588307f30473da877cbffe5111f5f75be6e5fb6f23f0f085a6c30de65ffb41be5f6ffec87504d7dc421b",
    "983f4e3ef9d607f1bddd79bdd82a90be5c36b77f9acff64a91e37281cb9d39a89ec7aeef2f2adfb1ea787b4173aec85dcdf5b2dc0fc8c7774c8beb7f8ec0c735"
    "7a4d5c4f09a11e458b0936d56348c9cd6d8cf78dc603a7483cb5de685caf359832902cf4037ffbef7f20beb7bb1f48f7bbe16023de3fc867bda35a94613db132",
    "1d778e1f303a4f3f42b48f6bf486fdc0bd062d2a412f66755c9f0c9835ee5e47e0e11abd6e5e27dab46d3e670de34497f715436d80efff7c1feaf86dcff7eed3"
    "e66e5f3c7ac0f1cd96908b11cd502cd177505e1fde63fdfea3f81e35df58d55eaf68ce31cd758a9e1258395015673b35d9376f9f40e2a9f5cf190f34a82159ef",
    "70d2f070a92cb589fa802f8b6f425c6f779e3fdcbb18e5ba4d8a0ee7c317a7dd50337f7116059edf5a9e47e199f7fd6d839226352dbbe6eb23483cb5de08afcb"
    "16b27cdd1ef87c8d7846f9fc27083c5ca3ef77c968a75f131e94067b1c971172bb7be765cc397c6e97bceb159fdf6b50bc203628f5733c44f4d3d4f1377d685a",
    "befe2d041eaed14bc6a84846a834389ee6b84e85eb937c83e60695da6cbfd4cdd5eb4faf89a7b45f5e82a7e8af59e72b0fa36758cefab860faf577b7218f7353"
    "fdc1aaf1bd701c1d4623e371e668e8f1263dee7036b8eb8e3ac71f3c41dcbfaa1d2788f6718d7e7deff5bd675f5069917487e4ad1da787a6cd075ed29c6397d7",
    "c99a59b43b3b6e785d8162ebe430c18a97fdf8cc603f024bfaa1e88dcd13acdc9f077b0cebb8f6f707b9518762f6bba7c55daa5af726cad94c72d74979fdcf10"
    "f76ff17b2b89db3179fc65fea4d622e62be390c7d73f2a02791f6bf0208f6f4efb4f10f7439cafffbcab8dd3846971feb23cbcf4e00c31dc9c1fb8a179ffcbef",
    "bca5bfb8641b59fe1deee3d7ef429ec7eefccf77dd9d362578838c2fe36733d5d2de714170d0f7574f10f703ffeb3fef4ae374622dffcf3ec605fe7f36ff2b5b"
    "7d58c8ff5f01ffdb9fff9bc4b93fbd574c75fdd5a018de27d25ed29b3d740effc3baaffe5111d5f87bf2d0345e7fdefcbd51bce7ade7f9cc205e0089a7d6db28",
    "df0779fa35e2419ede9cf66dc8e76392e7841ea37e0e543e7d2ddfe14e3f0acc8f818f2de3f7468fa66747a8d77cd6efa5ccac6475dc3ef90be4ededcff3a2cf"
    "c39c468a87adf21e37ee8b492696dc151dc4f38f10f7c377b54f8fbbabfafbdf21da5bd55ebf42e0e11abdde3e9b218a2578cd267266ad1b6f7a7fcd0f97e02b",
    "7a53f6e1d333e46265d742fff0d72f78c8ebd8dd3f64b361f122d376fbabe5d471aa9a270ed24921e61cff3045dc0fefb55ad4e3d06f9abff805020fd7e8b5fe"
    "a2cf51f520cf13a3184d8822c9526c737edda6eafb8dce270b4bf014bde171a463b8d910b270fc4cfe5705bf6077bf303e8aef85cf3a25265b4dd783a5463c39",
    "64d20eda8fc7e8fb9c47b48f6bf4c6e70d7286a8d2a03942ac5cce20acfdceab0cfbf218c473fe77deb02fcf3af1605f1e73da37cafb5944fbb8466f9cf7594e"
    "4c11a9349f905eeda69236b278df86a269eb00cbf659a604966031fbae038491786abda1fa9d998daccff3c07aef1af1acdab7a11beca519efa8e4759ff29e5e",
    "78977cd067529873781dde5fb5aceb7715615f65149e5a0ffb2a3f2f9e2cdb8207fb2a9bd33ec4f3fa474550f1fc04d1deaa76fb29020fd7e8f57f37ab41739c"
    "6c01bbe673d2483cb5deacdfcd9a5b4c720216f2ff1fa1fec7fefc5f6df932259616eb398e89f6d8f85e351a3a7250ddfe0dcccbdebcfa9f49cab4fcfd8f1178",
    "b846afe17d92e7b995d62dd6f57dd60d8bfb05a97b64dd25b3fd82f3b5d43fb7d906e2febf1f9f431edfeebc3f64b38371b2c3840ebb919870103eeaf63937e4"
    "f12fdbdbd6df4b9c20da5bd56e6f23f0708d5ec3ff3c29315e87cc5163323cfb1a59b06b1d4f6e099ea2371af77fcf60d6e7fdfff9a7cfc10fd8dd0ff80eddb4",
    "3fe3cf660af1825028fa9ac7a75d27d5ffc3fbac7f54443dfede366d1ef006020fd7e8357e8025f826c5d65a1776e57f93eb385799075cdaccda3acec9abbf3e"
    "fd17f0ff9af0ace2ffd170907840c41acd7d772d1de572ed58cf3f70d0fecc4e799f51e361d5f1f722e23994ef7cdf50fdebfb01f9f8cee278dfb23a1f25f30f",
    "753efa7502f3af7d17b9fe9958c84fdf9cdd877cbfddf9fea0eb4fe7bb7464ff22d4ca670f73623712a939e87b2e787fd5828aef2788f6a0ce67353ca8f35917"
    "9e2cdb8207753ee6b40fbcaf9675d577de94ba1eadac9adf79744d3ca57da8eb311b4f966dc183ba1e73da07be570b8aef3f45b4b7aa9dde45e0e11abdde7e3e",
    "ea8d2a126c86266ae4e27aa57f1d83fddbf4be3e1f2dc157f4a6ecffa16b50cbf76baebedc86755fbbfb078e38695709e2305cdf3b680b250f992c77460e5af7"
    "9d22ee87f75a2dea71b8e3b879c275f343304fd0ef3fcc13acc183798239ed43fd8ffe5111d4ef341addd7ed1e020fd7e8b5f306412079b140d0547d668a20df",
    "5c5c67d7758235ec03a51f477ccf7096cf0b5e080f605e60777fe0f15c8c1f4462a144f364982b8fe3d5f8835311ea81b6f07d96641230adeee78ee61cbbbc4e"
    "d650c26c2f7b81b46bdd4f1c89a7d61bdbe75fb19295bfe712b8f301ecdb667b5e1f1413428cbe28c43c0d3e47f7dbe923769c0d03af6f27af07a10e68f1ef50",
    "07a47f5404ea80acc1833a2073da9f22ee5fd58e1544fbb846bf0e3f708f1266fa264fd0d68ec3e9b965f5fdb3476c6050dfffec7d00251bc13e9e8ec2b38adf"
    "f787493a76d1afb713bed2f0a8ce7bbc6cce07f5fd5bf0fece04f6f184b85edd6f88eb378b0771bd39ed4f11f7db26aeaf723db62e581cd7674df3073f43e0e1",
    "1afdf7fcc1623bd3302d5906dbdcfe6e8f0ce26534e798e63a456fdc1f3c6d304bf3fc9fbc7617f2fc76f70331f624130a1653638a19a6db9d3a9316532307e5"
    "f9a788fbc10fa845ed07ce4ccbef2c8bc3250330c470733c7fb37faf7d313f9cdbc8f2fa9cc7af03bfdb9edff9aebbd3a6046f90f165fc6ca65ada3b2e0821e0",
    "f7ade677ac6029bf532cf0fb327ea758cbf9fd2be077fbf37b9338f7a7f78aa9aebf1a14c3fb44da4b7ab3508f7fd9de56d5e96071e0f515f180d7cdc293655b"
    "f080d7cd691f785dffa808eaf7565078908f9105f23166e1c9b22d78908f31a7fd7f20ee5fd58e04a27d5ca35fc3f7b3f7fa043fdf4ab9d2e1b9bae6b91e22fa",
    "6d2ecfd74c5b7f7d0b81876bf492712a92512a0d8ea739ae53e1fa24dfa0b941a536b3cae6f65d9b5e134f69bfbc044fd15fd30fc8c3ea1996b3be2e67faf577"
    "b7c13fd8dd3f08c7d16134321e678e861e6fd2e30e6783bb6e077c4ffb7fdf1d0b4c", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70528U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
