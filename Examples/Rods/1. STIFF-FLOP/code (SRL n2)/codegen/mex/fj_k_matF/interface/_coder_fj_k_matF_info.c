/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_k_matF_info.c
 *
 * Code generation for function '_coder_fj_k_matF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_k_matF.h"
#include "_coder_fj_k_matF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_k_matF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_k_matF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737431.32946759264));
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
  const char * data[29] = {
    "789ced5dcd6fe3c615e726d96017415a026df381a269362d160d1258b2244b768a00fab6645b5f96d65f49aaa5244aa2c40f89a43e2fd5b1871c72eaa9871c93"
    "a22db63db40b2428945b8e2dd0f4d0d35ef227b4e78a22a93519cd4a3629caa4de038cf1f889f31b3d3ffe66e6f1cd10bb954cddc230ec7b939fbffe1ac3fef1",
    "03a986612f63b2e04af91ca615bdfe96526ee9eaaadcc65ed05c774bc1fb9d522f73ac48f645b942532c99ee3025929f5458822167cd5438866209562c0c5a24"
    "c693024777c9ca5453a568b24031e41177a992a02615267e4935ab482ae9f7489d2c37f31d06e3ebc2d3eed2972b98621f491e23beff0b4bda2787b00faed37f",
    "10fbc855e718d255272a942b15db0f0903b6ec4a48b55047e40aa94274c0ba225c85bc5c0f9322e1ea6e6fb95d6549536d149b458610e35b8cee7b3c44f4f3c5"
    "25bf87be54e52e76e7526d3bb8086f59bb3d8fc0c3154d9993ff6166e1bda8ab3fc5933515ae53a2c9a7789f19c40b21f1b4fa0f92476713d7e808bc8be6ca04",
    "ed4a850a47a1b0ebd8e3dede2db9448ea34b5cdf4532b48ba64aaec9ff9e264a2e92ae76d8894b08ebf083af1edcff2664addf59ede7ebc3eb23da5bd6ef5e41"
    "e0e13a7dabd06f043262d61fc810857ca3c0ef0fca6cf8693fb20b7016f50343d4ad6a1fee5fad68fdede7331e1f21da5bd64eaf23f0709d5e1abef82d6a3229",
    "e05982de1226a622f82d95e58df3bc5e50fd5145c57b744d3cb5fdd4023c557f053f917ede99dacbf58e6a30d73bb2c5663e639dbf04fdbffd1cf8deee7cbfcb"
    "1f0944ae9c3a3f2d9d9f95c261bfaf5a2381ef378eef3f41b4b7ac9dde46e0e13abd8eef89568b1ee4a71416efb06591e2d8249ba589b2ba1454fbd732d8bfef",
    "2fe89faaaf2abd28d609b63299f8abf86383f81f2ec057f546c703b4416517b3cebfc6a5971aff86f1614578568d0f1c71d42811c47ea4e2dd6d08671e3275d1"
    "1a449d333e8c11d7c37dad15ad1fbe6b5abce78eae8ecd3e276b28416811bc40da35de9340e269f5d79b3f48b6916610aa95b6180be7ff77deff15f0bbddf9bd",
    "779a14e274f324eea9f279badbc81cb0c35c04f87db3f97dcb7171a0ebf23fc481e6f71fe240d6e0411cc89cf69df23cf76b443f97f5bf97757555ee2a65fdf2"
    "1f4791a0fc8b5a86e4721454ea4a390a2b759f52fe5229bd8a3ea6d4df53ca8052ee99b68eb8adab63b3cfc99a16d79b6619d8751db1da3824d7125c530bad21",
    "0e39faf81b3fac23ec3e7e9cd64f487f3e97df392ee43a67d1c38b132effc041eb08bbdebfa8b8f9b2fef69caeae8a3a5ee09abfde0fcae55ba6ad1f7e8ac0c7"
    "757addfa8112c21d8a16936cbac3903c555e1bef1b9d771c23f1b47aa3eb07bdc15447b2701cf8db7fff03eb08bb8f03996e3b12aa26babb859c6f508e31ac27",
    "7e41279c330e188d071c20dac7757ac3e3c0bd2a2daa935ecc62bf1ba58266f9ddab083c5ca79f1b3f8ad56c1b375a819fcce57dd5506be0fb3fdd87e707b6e7"
    "7bf7716dbb2b1eec717cad2ee4e3442d1c4f761df47c18eee3f9fd47f13d6abdb1acbd50f1295ca7a704569ea88ad20e11fb3e1f4822f1b4fa2bce07aa549fac",
    "b4b8897bb834965a479ed91f4f5f8779bddd797edfdb1ce4db358a8e1422cde376b856683e8801cf6f2ccfa3f0cccbfba95293454dddaef1fa28124fab37c2eb"
    "b2852ccf0f003e5f219e513eff11020fd7e9bb6d32d6ea9685bdb39e97e3b2427edb7b7e813987cfed12777dcae7f7aa142f88554afb3d1e22fa69aaff8d1f9a",
    "16af7f038187ebf413631427462856399ee6b85691eb927c95e67ac5b2b44f7b7dfbbec6d7c453dbbf5880a7eaafb95f4476a36758cefa79c1f8cb6f6f431ce7"
    "a68e07cbceef85c3583f161d0eb3077d8f2fe5714772a16d77cc39e3c113c4f5cbda7184681fd7e957775fdf7bf6078a75926e91bcb57eba6fda7ae0055d1d9b",
    "7d4ed648b35da95cf373058aad90fd242bcefaf1a9c17e0417f443d51b5b2758b92f007b0ccf71ed3f1ee4072d8ad9691f9f6e53a58a2f7991cba6b69d14d7ff"
    "1471fd06dfb713713b268ebf683c29d789e9937188e3cf2f5581b88f357810c737a7fd2788eb619e3ffffb2ee7a749d3e6f98be2f0932fce10fdf58d033734ee",
    "3f3b2f64f28b4bb691e5e7393c7ef52ec479ecceff7cdbdd6a50822fc4f8b301365b3af31e9e080edae7f504713df0fffcefbb949f8eace57f8a05fe5fc4ff14"
    "6b39ff7f01fc6f7ffeaf11e7818cf734dd0e9442626487c8f8485f6edf39fc0fcf7de797aa68fcefc943d378fdaaf17ba37857cde7f9d4205e1089a7d5db28de",
    "0771fa15e2419cde9cf66dc8e74392e7840ea3fd1ea878fa4af6e18e3f0c4ecbe04796f17bb543d35209f99acf3aa74db292d5f3f6d19f216e6f7f9e17fd1ee6"
    "387aba5fbff072c3ae9862e2a96dd1413cff08713decabbdec774ff3ef7f83686f597bfd028187ebf4f3ce6b0e532cc1eb0eab33ebb9f1bacf69fe6001beaa37",
    "e5bcbf7986549eec5a383efce5731ee23a761f1f72b988d8cc36dc81d245fa305d2a10bb99941077cef830465c0ff7b556b47e18306dbcf819020fd7e9f5e345"
    "97a32a219e2706719a104592a5d8daf473ebcaef37ba9e3c5980a7ea0dfbd11cc3492e64a1ff8cfe578271c1eee3c2f020e18d3c689d31b952a6123aab26527d",
    "26e3a0f3788cdecf0544fbb84e6f7cdd2047888a559a23c4e26c0561ed3eaf0b3897c7209ef3f779c3b93cabc4837379cc69dfb2f39c0df33ecb8969229de193"
    "935bbba6868d2c3eb7e1d4b4e7008bce59a604966031fb3e078820f1b47a43f93b928dac8ff3c0f3de15e259756e433bd4c930bec199cf7dcc7b3a916d72afcb",
    "a431e7f03adcbf5a59d5fb79e15c65149e560fe72a5f154f964dc1837395cd691fe6f3f34b5550f3f911a2bd65edf663041eaed3cf7f3f5795e638d902768de7"
    "6490785abd59efe79a5a6c320858c8ffbf87fc1ffbf37fa9eecf9eb1b458c9734cacc326bca558f8c04179fb37302e7bf3f27f4669d3e2f73f44e0e13abd8ef7",
    "499ee7967a6eb1aafd59376cde2f4cba47565c32db2b9cafa7fea9cdd630effffbe139c4f1edcefb7d36d71ba65a4c78bf1d8d0bbb9183769773431cffeaf3fe"
    "15bf97f121a29fe6fadfae6971fce71178b8a211a44db8987de3f821249e567fdd38a094cd2fa89b70312bfd20f8d583fb309fb73baf1344227cd16b26a89354",
    "a44387c36c34904d3b88d7e1fed5caaae2f8c6deafaeb2fcfaf2318daefb520bf054bd59f11bd567acf3977110deaf6e7fbe77ef24fcbb91dea9c71deef56877"
    "8bf6456b43079dbb037caf1514df7f82686f593bbd8dc0c375fa79fbb6b41b12926c9626caa4f279a7ecdffa7001beaa37659fc75c835a7e2e4fe9a506c479ec",
    "3e3e70c451a34410fb918a77b7219c79c8d4456be0a0f5c018713ddcd75ad1fae196e3d609d78d07c13a617eff619d600d1eac13cc691fe2fdf34b5550ef5719"
    "21da5bd66e6f22f0709d5ec7ff3c29d4891699a78664443a7d54b0ebbeddfc023c556f94ffbf6330ebf3fcfff987cf603d60f771c0bfefa603d9402e7b923811",
    "4e4efdb5c3e3b693cefb81fb797ea98ad6ffde342defe735041eaed3ebc60196e06b145bae37edcaff269fdbb04cdecfcc66d69edb30fac17bc7ff02fe5f119e"
    "55fc3fe8f7927b44bc5adb719733312edf8877023d07bd8fd129f733ca1f96f53f541e8e7aaee76b9abfbe1b94cbb794f2be65fb7ad54c7fbbe603ad7a5fe0f4",
    "744f25b75f120bf909f28156886715dfefb60399429b8eee34c3f5426e3f2fb6a3d1b283ce6f83fb572ba8f9fd08d11eeceb5d0e0ff6f5ae0a4f964dc1837dbd"
    "e6b40fbcaf9555e581de947dbc7a5936bef3e89a786afbb08fd76c3c5936050ff6f19ad33ef0bd56200f747eff200f5416c803b5071ee4819ad3fe18713ddcd7",
    "5a59551ee84d59275c373e04eb84f9fd8775823578b04e30a77dc8ff995faaa2f53ff78cff8dbec7e51e020fd7e9f5eb06412079f184a0a98a648a105f533e67"
    "d7e7042b78efc3fc79c4770c67f9bae0b9480fd605761f0f3c9ee6702f1a0f276b47fdfcc530514aec1d8b900fb481f7f3444641d3f27eeee8ead8ec73b28612",
    "a477d70aa45df37e12483cadded87b7d552b59f9fef6e09df7e13d2db6e7f5de695288d3cd93b8a7cae7e96e2373c00e7311e0f5cde4f510e401297f873ca0f9"
    "a52a9007640d1ee40199d3fe1871fdb2762c22dac775fa558c03f72841d2d77882b6d60fc7e796e5f74b5fb18a417effb3dffb33b111bcb7cb517856f1fb4e3f",
    "45c79bdd4a23e93feb1f54788f8fcdfb21bf7f03ee5f49e0bd5d30afd7f61be6f5ebc58379bd39ed8f11d7db665e5fe23a6c45b0785e9f336d3cf809020fd7e9"
    "bf331e28af2f8bd013cb60e6cdfbaffa3e974706f1b2ba3aa6fb9caa373e1e5c3698a571fe8f5fb90b717ebb8f0371f6281b0e9da68714d3cf345a152623a607",
    "0e8af38f11d7c338a015ed38f0c0b4f8cea279f8c4000cd15f1fcf1b5d1f4691785abda1f5e1d44696e7e73c7e15f8ddf6fcceb7ddad0625f8428c3f1b60b3a5"
    "33efe189e0a0733bc788eb81dfb5a2f5c3134bf95d3aa419f8fdd9fcaebe02c2427eff02f8ddfefc5e23ce0319ef69ba1d2885c4c80e91f191be1ce4e3cfdadb",
    "a83c1d2c01bcbe241ef0ba5978b26c0a1ef0ba39ed03afcf2f5541bd5f1d8507f11859201e63169e2c9b8207f11873daff1a71fdb2762410ede33afd0af6cfde"
    "eb12fcf428e5628be72abaeff510d16f7379be6cdaf3d7371078b84e3f314e7162946295e3698e6b15b92ec95769ae572c4b5659dfb96be36be2a9ed5f2cc053",
    "f5d71c0764b77a86e5accfcb197ff9ed6d181fec3e3e0887b17e2c3a1c660ffa1e5fcae38ee442db6e07eca7fd3f560b1079",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70632U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_k_matF_info.c) */
