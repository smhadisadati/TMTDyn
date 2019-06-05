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
  const char * data[27] = {
    "789ced5d4b6fe3c811e6ec3c321320c9208fdd1924d98c3783d96c66d67adab2f764590f5bb2de926d599b40a6284a6a9b2f91942cf964204090430e39e6901f"
    "90c31e829c721490cb22e76c360802640f392cf203823de4104a54db22473de28c5a9449770306d55d647fc572b1aa58fd20752b91be4551d437b5bfe171f05f",
    "6a54bea11fa887e3e35b94b198e9b7c6c70f4c7558ee52770cd741faefc647461454b6a7ea150e086ca6c3d75859ab0834cf5e7653177920d0825aea4b2c25b3"
    "8ac875d9fa88d2001c5b023c9b12272abb40abf0f109d26565481afe8eb458e6b4d8e129b9a55cb1cb4d56a809f9fc1671ff772cca278490cfc3711ba47f1cfb",
    "79e423cfbec2ca8a47517c21ff86df1365955355943cbed527c552221eff309ecae63c8c58673df2890aa4f82a7fc9670fc1c73d8b7cde46f0f9607c7c6468f5"
    "6de947fff818d8827c1c2370accaeb2e828f871a65d8268967232dc18577cf54bfc2bb376aab8b9d1ac75ee1fd7e4ebc1d249ede06e91f2752e5914ae464b129",
    "d3fc93a1ee2a9e74b8940a6f7b0a7eaf2f54f3a8a2c8d5c49e87e5390f076a1e9e5639bae61125c53392d3847e1c23f8b2aa1fe6232c0fa8fbe35f175ffd79fd"
    "6f61fbf0f47253f050cfb755bd7b1b8107f50ed20f5b07ec7a315f5c2b94f29d7274af722016f723577ce466e0cce28342d4edeadfa9cfaf84e0cbaabebd65aa",
    "c302edfb4343eb7b5bfaf1d9a55dbf40f46f556e3f42e043b941fad0bbc9ab400b0e6481e65681b2dd019c9a10b4f0809501b334bbffa739f1ca483cbd0dd25f"
    "5b6f867fcf4752f33c8762f398c5b6cadbe8077efcef7f7c46fcc082f0ecf203d96e3b126eec76374af9609f89f1823f5ee176dde307fe80b8deaa1c73a63a35",
    "71de24ff98fcc04a8353473f6dd5bb8bf4162ebd7b078107e505e926fbaf303447cbb1e6d2ecfeb5d593a9761f8acb567bffe0d7ff24f6dee9f6de9b390bf125"
    "c057f640a11edb8b32c546a3bf4decfdcd798e2983bd47bd6f58959739ef474d9c776b820e14410f51d561866f79799d79f5238bc4d3db20fd8de28106e8b175",
    "49d4d4c3639097adf91dea71fc31b1f34eb7f33b81d37eb1dd045ca414392db4b79ba5d3fd5894d8f99b6ae7517856e575df54a72ecfbb3f6a034a0368af332d"
    "a7daf524124f6f83f4f9edba2e27cda48f0ab1ebeec09bd7ae7f0f8107f50fd2bb6d3626751965b37c1610c59c52f4058e2a947becbab3f2af57767da5016445",
    "6d005bf56f708c2d6fff2e020fca0dd2353154b5dbaf3644991345a92a7659b9c18967556638de3e7f5c6f2e287e60b99cdff08678b0af6353dd8c07e9f3e4f9"
    "c66af40af9d99acff9e4f3bb641cf7bafa03ab71beb217ebc5a2e7e7b964cf1f4cfbbd917cd8e78db9c71f7c89b8deaa1c7f89e81fca11d217fd5cafbcfa846a",
    "8be5a4e184177bf57507dbfbc11d539dba3cefcee5fbc1b0bee4710620d4d95e4250b1cd1388cfe003d271bc370cdf196cd48fa7647cd7f9fea1d89700bfd62e"
    "1cfa40ad1e4c54f2b9b4afeba23c10797e8dc5a86f5ed7e4f967f917a6450fa78b923c3fe2080bc907d98347f2fc78fa27f1bff1bef0ea6b025bfc3f2b5fafdd",
    "3a4ff79ceb0f163a3e00f588d37e787449d93f3e70f1f4de03920f72ba3f90db5ee90428c130bf9e0b09b95a39b077a0b8687e0ff107c6fbc23b5e6caf3f0002"
    "f107d6fc011096e00fde27fec0f9fea0491f85b281c34c3b540bab91353a1b6483f91df7f803325e3cfd088b41ffbe38c666df5f37df3f2f9eddeb775d9c1724",
    "79fd05e291bc3e9efee78dcf72a63a3571de24ff8e5eb7455dcdeffc15a23fabf2fa09020fca0bd24de3a9b42471fd6d20d072bf38f26df18ec0a84014708d3b"
    "7c6b065f90de18e3565bb450d71c01c4ff744e7c7a063ea4e3890f90e284e1bf9df1ff67ff23fb3c38de4f9cb3b4181632818ada6cfa77bce96c7dffd0e7223f",
    "31405c6f558e1544ff508e908ecb4fe86f00d50627d26a156e7243d9ac87830a59ef3b27dec2e28b6bb37e84acf75d241e59ef8ba7ff79f33f8788fea11c211d"
    "97fd1744354367b272427bb49b9af1b737bf7f882dff336bff36a008b44039779d6f0289a7b7413a86fcfe5052cb88ef491e68817876ad076b873b593ed82f07",
    "bd05d9df89f8d8cd2e9fa1dc63dfc9733c9d7fa3de3dc5b60e8cecdf86c2d3dbc8fe6d6f8aa7979b8247f66fc3d33f89efa71f6141c5f71788feaccaedfb083c"
    "2837489f9ad7596d70a2a827b69cea07f691787a1ba4e3f103cf75b97946721bc51036fa81b7c93a00e7fb815a6b3d571638b55e14f95847d80dd462db4917cd",
    "f3b9b6f9daeb341e7c91c196d7ff2e020fca0bd24df69f9565d130cff2784e3e5e775ee7b58cff158d49b6eed1adfed8f69b5dc04872b6c6ffe2e01919df75ba"
    "dd174a4779da7fb45b0974bb9d58b9eb0bf049e0a27dfc9df25d9663041f78f52b882d7fff3504de438d326c93eba00beaecd2e27727e4fd86fe7e2ca765e4ef",
    "dff97a9ec4edd7d57e5bcddf6f9ce51bfbe5e07a68b7cb1536a31b1b29719fa1dc63bf9dfe1c4b08fec8f758de8c1f92cf37f249f2f9cec023f97c3cfd3bdd1f"
    "1c23f8c3ab773fc566ff9f20f0a0bc207d4a1e9fed49119197681568167959f67f3027de11124f6f83747cf3340d625b86fefce58fdf21791da7fb81565d922b",
    "e5f318d30c4553a17ea04387f31b2e9ab749fcc074fe8d7af711b67cfeb71178505e906ef203daddebed4ecd03ed21f1f43648c763ff35718d3585d87b77e0d9"
    "b64fc3f676bf1e0ac462959ebfbbbb5702d123b9e0a2b89fe4f19794c76795162d39378fbf30fbfdd2fcddb1a46cb7df17ff59fd17c9db38dd7e27bc279b9d7e",
    "38207803decc99ea8b316c8f73d13efce4399ecebf51ef5e608bd71f21f0a0bc20dd14af0bb4dc0402d33a9dd7de9b0b8a0f5870e56b7e36030fd2b1cfbfb994"
    "9cae3836daffdb2f0a7f25f67f417876d9ff7eef2cb149c71bcd352f938d89c593782774e622fb3f405cefd4e71aa51756f5f036e27ee0b8ee2343eb7b5bfaf1",
    "d9f8f8025bfc3f6b1d2e9c89efd4f8df9ef57b8d8e3031f77e586cb4571f469f91f8dfe9f67fa31dca96da5c74ed74bb55caef14d57634cac4dd63ffc9733c9d"
    "7fa3de3d21f376c6e790793bd38fb090793bf6e091793b78fa27f67f3aff8bda87e1baacbf3517143fb090f5b746be2dd87fb2fe76817864fd2d9efe89fd9fce",
    "3fcafeff06d19f55797d80c083f282f469fb311bb70e4e08398e66d8f1f9b3d63538655fe6da0c7c48c7b82ff354b1daff5d162a70b646e6fb38dd5fa4927bcc"
    "513bb7193e4a0765c52f017f379474d1becce4f99e7e5fd6f471d575ef11109fece363e493bc4738038fbc47e0e97fdef7889b318f68fdd2fecffb5d9715041e",
    "9417a49bdf23148595d5039a03f5223867c372737c9e53d7812dec3b0fd3e38997c4b7843882ac0b58209e5dfe200d6a896232569176f99dd8e6e676be7b76be"
    "e9a2fd7d0688ebc9736d2cc67ddeb6c8383385e7fd808c332f0a4f2f37058f8c33e3e97fdebc116baa5313e7dd9aa02fce1fac006548d73ae5289bf571ebc8b6",
    "79a5c39b6c50645ea995ef42689222df7771199e5df67ead97e6e2a7ddfa4962bddc4bd6657f5028ae9379a537e8391e16f27d1712ef1bf926f1fe72f148bc8f"
    "a77f97c4fb35b123d415caee783f8fcd2ffc108107e508e92ff985f1876e229c261b0adffb80ddfbfe1f20f1f43648c7e51726c5360c2a6cd49bafee3c20e302",
    "4ef70b712195db0e1f66ce01dfcb9e48753eab66fa2e1a17207e61fa7d59f30bfbd8f240b3e2734d043cdd5b9edd9ff7fd3189c4d3db201dc3fbe34852f68f17"
    "5d3cbd47ecbde3edbddcf64a27400986f9f55c48c8d5ca81bd03c545fb81127b3ffdbe2ce9e385bdf61e08c4de5bb3f7405882bd7f9fd87be7dbfb267d14ca06",
    "0e33ed502dac46d6e86c900de65d340f94d8fbe9f7652dbe3fc096f7f901020fca11d2cd791fa1cef612825a6039511ad297b5ce78f08678b0af6353dd8c07e9"
    "d8f7a53248d0d67181fda040c6059cee1f52a97824144ecbc9468a57f85cab152efbce5df43ef025e27aab72fc05a27f2847485ff473bdd2e0445aad32c33c6f",
    "951105950682528527c1acb9cdfafa058bcd7f3c46e0413943bac97f8ca492d6dab831dda9e30605249ede06e978e2902bb12de1bd82ac2f5b209e5d7ea3bb11"
    "0886d8e45eb611dd542b21ba908a00de45e3c97f475c6f558e3d539d9a386ff2ffb470bf0194aa029a025b373a0b5bf573c090bc92453c9257c28da7979b8247",
    "f24a78fa1f20ae27ebc98cc5a8873bc4ce5bc423761e379e5e6e0a1eb1f378fa1f20ae2776de588ce3c469322fc8221e9917841b4f2f37058fcc0bc2d3ff0071"
    "fdd2bfff8dde2f68a54bcba38fce542559ac9beee718c12f5e3dbccadb5c20fab32abf771178507e90ae89a4aa59b26a4394395194aa6297951b9c7856655a2c",
    "734ac6875fa93f7ad8f00af9d93a3efcc9e777895f70ba5f50f662bd58f4fc3c97ecf98369bf37920ffbbc2ef81ed9ff011bd7b1dc",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 63192U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
