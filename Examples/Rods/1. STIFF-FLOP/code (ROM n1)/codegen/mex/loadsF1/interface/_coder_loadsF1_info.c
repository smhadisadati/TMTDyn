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
                (737429.55662037036));
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
    "789ced5dcd6fe3c615e7a6d9208b222d81b4d9f42bcda6c522c506962cc9b2b76d00c9fab0655bdf5a5beb249529899268f343222959f2a53ef69043fe801e72"
    "4c8bb6d81605b2688242bdf55aa0e9a1a70045d04bafedb9a228da1eae26a2cd11254aef018b11fdc4f98dde3efe66e6cd9b21752b91bc4551d4d706fffef873",
    "8a2abeac5d51d44b942ef4a87c8e42c5acbf352a574cd786dca69e47eebb35c2fbe5e8ba22892adb55f50b9e13d9545b28b3f2e0426404f6a29aaa24702223aa"
    "855e93a5645691f80e5b1d6a6a1ccf163881dd93ae5c6c73830b217e457571a1a9b4cf91065b39c9b7054a6e2897cde5af5e5023fb68f204f3fb9fb7689f34c6",
    "3eb449ff4eec3d4f4312584f83a9729e646c2bacf4c48a675bbb0ab755a9902c447ba2272255d9abd79bacca783aab2b5e4f45d3f0125355e2ab2bc245fbcf31"
    "ed7bc162fb9f375d1b726754be8efc3518d2cbb551e91f958190d19e230c9e557bdec6b4871e699ad2e9d08b48e1bd60babec4d33555a95de6d94bbc8f6ce285",
    "b178a8fe9dc45e71e0326d451efca75718de930c17f6c29b9e9ccfbbba51f6a892c497a5ae8715780fcf953d02a3f24cd9233515cfd042030fd165929dacfa89"
    "b934e40ef5e2e8d3f9fb9f05ff11760e4f9765c1eb62eab3ea77af60f06893fea0b1cf06f3d9fc5aae906d17a3bb87fb52fe51e4b21d99093893da4161ae9daa",
    "dfadcf6f13d32eabfef69ce9da1083e769e4aff7437af94668523f63d56edfc7e0d326bdd6cdc92bdc60f0208b0cbfc2299b6d8e5713e260f8c0ca5c6566bcff"
    "d4265e0e8b87eaafe137dabf07437b791e1806f3980d66389283fdc0c7fffde767d00f4c09cfa97e20dd6945c2b5edce46211be8556282e88b1ff2db8bd30fd8",
    "1df7ef60eaa74d7adbfdc0bd1aaf1a835eca61bf3b4f8648f9dd5d0c1e6dd29bf85f19988c9163f599f1fe1cfac958de370c3503beffddfd9fc1b8dfed7cefcd"
    "d5573beace4349ae37947c9ca96fc6139d28f0fdf23cc714c2f7b8f986557bbd64baa64cdf33f49c22ea0355558b00ce2eae63d73f12583c547fcdf1408debb2",
    "d5a634700f0f62a919c477a8df1e7c0bc6f56ee7f92dff492fdfaa737ca41039c9b536eb85934731e0f9a5e5791c9e557bbd68baa62ebea76b38a5c60d26350d"
    "b7c6eba3583c546f87d7750be99e007cbe187876f9fc9b183cdaa4efb4d858b353511e164ffd929451f2abfec787d4e2f0b95be2ae977c7eafc6c98a5ae3d0df",
    "7184692751ffeb1f118bd7bf86c1a34dfa81314a0323946a92cc4b52b3247558b9c64ba7a58ab60e6f7f3c6f165c7b0c31f0fa37c433ea3f9c8067e86f16df1b"
    "b9d19758cef97141ffd32f6e431c675efb03abe37b6537d68d45cfce323b5d5f20e9f346b2e1556f6c71fa83cf31f75bb5e339a67edaa49fde737defcbbf506a",
    "b07c93959df5d32d62f3015c3e113dd268a35dad9cf1ba022756d96e42542fdaf1a1cd768426b4c3d0db9b27ac080efac55358c7757f7f90ef353961ad953b58"
    "e5cad540e2309b49ae2e525cff43ccfd4bfcdc0ec4bb3071fc49fd49a5c10c57c6218e3fbe3404e23ecee0411c9f4cfd9f63ee8771fef8df6bcd4f13c4c6f993",
    "e2f0831f2e30ddd9f503731af737fc871f7cf0e836723aeedf7f7af70ec479dcceff72cbdb3ce69440580866d6c54cb9e8dfdd573681ff81ff5141d77d9de57f"
    "4e04fe9fc4ff9ce838ff7f02fcef7efeaf338fd7d3fe83546bbd1c56236b4c3ac006b25b8bc3ffb0ee3bbe3404f1bfcf8f88f1fa75e3f776f1ae9bcff3a14dbc",
    "10160fd5bb28de0771fa29e2419c9e4cfd2ee4f333569694b680fe0e5c3c7d2afb70fbef868665e83dc7f8bdd6e679ad847ccd71e376a5c9c8b5b6e8d1ace4f4"
    "b8fdfcf710b7773fcfab419f908b1e6c350efdd259474d0af1e4aaba403cff04733fecabbdea7797f9f7bfc0d467d55e6f62f06893de94ffc2349b7c6f931319",
    "b9971ff678f1b65851394924b56efcf509ed32f4b5116ea9c188d54147402a7ff39d09f886deee78016bc8d1caae83fdc31f7e25435cc7edfd43361b514f32c7"
    "def5f2616a37552e301be9a4125f9cfea18fb91f9e6b54503f5c27d65ffc0083479bf4e6fea22371d5b02c33bd38cfa82a2b72627df8bd59e5f7db9d4fee4fc0",
    "33f4b6fd688ce1341772d07fceff57867ec1edfdc2d9ceb63ff2a85914b2e574355cac6d27bb427a81cee3b1fb3c1730f5d326bdfd79831e212ad57889514b17"
    "330867f7791dc2b93c36f1167f9f379ccb334d3c3897874cfd76793f8ba99f36e9edf3be28a929269596138347bb6e848d1c3eb7e180d83ac0a4739639456444",
    "cabdeb00112c1eaab795bfa3d9c8f9380facf74e11cfa9731b5ae1765a08f48a016f4ef6b523abecc38e90a21687d7e1f94505f5b71f123ba701ce55c6e1a17a"
    "3857f9ba78ba2c0b1e9cab4ca67e18cf8f2f0dc18de7cf31f559b5db773078b4493f368eb352e32549b7805be33996dfc363b31f78a05bcc33b4d895f7f01c61",
    "da4790ff7f0df93feee7ff722398298abc5acd4b42ac2d6efbcbb1cd9d05cadb9fc3b8ecfce5ff9ca788c5efbf81c1a34d7a13efb3b22c595ab798d6feac391b"
    "f72b83e6b1558fcef623ce3753ffd0663318f7ff79f731c4f1ddcefb5d317b7a966c0a9b5bad685cd988ecb43a927781e2f88e8ddfa6f41ec526a67dd379bfd6",
    "4f437af913c7f2fa95963c7c19a75be3f99b583c547fd378a096d5afd9c8797e0ffde5d17d18d7bb9ddf035bb15ac31b4c1ca763fe849ac98a6227125da0b80e"
    "3cbfa8a0fe769f581ce7bb183cdaa47f269e1f9504861363e6713dae5f732a8fdf2d711dc480cec675fef41fc8cf743dfff349a12a9cc86cb219395037a476b5",
    "f6b8cd2dd0793cf01c8f6f3fea774162e3f9c9ef55d1f6a22aac5bc7f3db583c546f6f9fae612527cf6308bdf836e45dba9ecf4f0f124a9c3fd98ffb6a729eef"
    "1ca777c4b36c04f87cb9f8fc6dd8773512d87785b6db82ffc0beab29e2c1be2b32f5435c0715d4dfde84755a9b78b04e3b2d3c5d96050fd669c9d40f7c8f0aea",
    "6f2bc4e2f8dfc6e0d126fdf87c4c63b57676e37cbbf3c3d4043c434f2a1fd3f019e7fca5fff1bffe0debb6f3caf756f7616db4f7f2de7d7f3a2c27fc31b1b893"
    "0b8ab920057cbf6c7cff01a63eab76fa11068f36e9c79dc3861e309410333c536147df9f9775dcbe4dfc7727e01b7a22e7368d35a8e3e7ec97bf7a0cf38179ed",
    "1facce072466efb8cc305b91aa7fe35829fad8e461b3b740f3813ee67e78ae5141fdf02d58e7b58807ebbca4f07459163c58e725537f1f733ff03b2a8b1e07ba"
    "29ff431c687cfb210ee40c1ec481c8d46ff7399ef5feac234cfbc8eecb0d13e3fdd73178b4496fe27d99551a4c93cd73676c447b4ba4e2d63c9ffc043c436f97",
    "f79f3198f3e7b1fded371fc13c605ef9dfea3c20b8e5e5d733ebd9ccfef6beb27f10acefe65a8bf45e16789ec79786a0fef73ab1bc9f573178b4496fea074446"
    "ae7362a571e256fe279ce76925efe7c266ce8effcf5ffe71eeefc0ff53c2738aff7bddd3c443265eabaf792be998943f8eb7d74f63c0fff3f63ce3fcc1aaff7d",
    "05f33b8c731a5e45fefa56482fdf189597fb7c8f3038a4ce5f364e64736bdc7fdae7b70edfc2383a834d1307f909ce6b98229e537cbfd15a4f175a7c74ed64b3"
    "51c86ee5d556345a59a0f76cc1f38b0a6e7c7f8ea90fce5fb68607e72f4f0b4f9765c183f397c9d40fbc8fcab4cedd9f97f396cd6235bef3e4867846fd70de32",
    "693c5d96050fce5b26533ff03d2a38beff00531fe4f7ebd2b789bf7c796290df3f4d3cc8ef27537f1f733f3cd7a84c2bff735ee609378d0fc13c617cfb619ee0"
    "0c1ecc13c8d40ff93fe34b4350fff35ef0bfdd73dfee61f06893de3c6f50145656f7199eab6aa608cbf5d1f7dcba4e50c0e2a17adbe388670ce7f8bce0b9c829",
    "cc0bdcde1ff87c27670fa3f1cd447daf9b3f3cdb2e6f3fcca9900fb484cff340ce43b0dfd7221eecf72585a7cbb2e0c17e5f32f503af8f2f0d99d67e2fc803c2"
    "e1a17ac803ba2e9e2ecb8207794064eaef63eeb76ac712a67edaa49f463f708f53347d5d667867fdb0ffd8b1fc7eed27d628c8efc7e50d0c3e788636727e3fef",
    "53e077f7f3fb5a37c9c74f3ad5e344b0d8dda9cabe80980f427eff123cbf9a90cbf384713d0e0fd5c3b8feba78ba2c0b1e8cebc9d4dfc7dcef9a717d596a8b55"
    "c5e1717d96587ff03d0c1e6dd23fd31f24b4190d2b47f881652872e3feebbecfe5894dbc8ce99a327dcfd0dbef0fae1accd138fffbafdc8138bfdbfb81b8b897",
    "d90c1fa4ce38a19b3e6e5685b49aea2d509cbf8fb91ffa0154d07ee011b1f8cea471f8c00002d39d1dcfdb9d1f46b178a8ded6fc706823c7f3739ede057e773d"
    "bfcb2d6ff3985302612198591733e5a27f775f59a0f7adf731f703bfa382fae1bea3fcce89c0ef93f89d131de7f74f80dfddcfef75e6f17ada7f906aad97c36a",
    "648d4907d84016f2f12fea5baa3c1d6a1b78dd221ef03a293c5d96050f789d4cfdc0ebe34b43d0fccb14c4632ce2413c86149e2ecb8207f11832f5ff1573bf55"
    "3b3298fa69937e0afb67ef751879789472a9294b55d3ef3ac2b49b2ccf5788adbfbe86c1a34dfa81714a03a3946a92cc4b52b3247558b9c64ba7a58a6695d99d",
    "bbd6bf219e51ffe1043c437fc37e4077ab2fb19cf37939fd4fbfb80dfd83dbfb076537d68d45cfce323b5d5f20e9f346b2e155ef02eca7fd3fe7910ccc",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70512U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_loadsF1_info.c) */
