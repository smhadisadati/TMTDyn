/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_fj_inF_info.c
 *
 * Code generation for function '_coder_fj_inF_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "fj_inF.h"
#include "_coder_fj_inF_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("fj_inF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/fj_inF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.9506018518));
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
  const char * data[24] = {
    "789ced5dcd6fdbc8156776934582c5b63cb45d6c5bb44dbb307691c2942559765a04d0b725dbfab2644b56b2b549899428934389a4be7ca98e3df490534f3de4"
    "d82dd062db4337d81685f6d67f60bbc09e0214452fbdb6e78aa2689bac26924d8a32a9794030993c717ea397c7dfbc79f321ec4e327507c3b0af8dfefce9e718",
    "f6b72fb1b1bca316183e29dfc0f462d4df9994ef1bea9adcc3eeea9ebb33c1fbf5a45e11804cf764b5c2b1804eb7798a16471540f2f445335581670109e442bf"
    "4963222d095c87ae8e350ccbd10596a7f7852b95043baaf0f12baa8b8aa252fe1ea9d395b37c9bc7c4ba74d95dee6a059bd847914f20dfffee9cf64943ec831b",
    "f44f631f117581a7893a596589546c2724f541854828b5505b160aa942b40f888850a5afd6c3b44c129d8d750f5151344ce38405f175feb2ffa790febd3567ff"
    "8da5260fb0fb576adee02cbc79edf526040f9f682a82fa1f6515de5b86fa259eaaa90a6d8aa32ff17e63122f04c5d3eb9f26f74b2397684b22c10915922352a1",
    "c27e284c1c783d1bdb14210b0247093d82e6398263298227658ea4089a63da60e40a92e20263b1d10f3e3f5cfb2264afdfd9ede7cbc3eb41da9bd7efbe05c1c3"
    "0dfa66a1d7d8cac8d9c056862ce41b0571a75f01e1cb7e6467e0ccea0706a9dbd53e7a7ff5a2f7b7f72f787c00696f5e3bbd07c1c30d7a65d812d7d951302002",
    "925b9746a622c5758de5cdf3bc5160fdd1c4aa713f35034fd35fc34f943f8fc6f6221e6906231ea916bbf019fbfc2518f8d5c788ef9dcef7dbe2be44e62aa9e3"
    "22755ca2c2e1809fa9d188ef578eef9f43da9bd74e1f42f07083dec0f764b3c9f5f3630a8bb7414566059004598eac685340ad7f4d93fdfbfa8cfe697a66d28b",
    "933a09aaa3c05fc31f9ac47f36035fd39b1d0fe006555dcc3eff1a526f37fe8ec68705e1d9353e08e47e8322c99d48d5b7dd904a5e3a556ef6a3ee191f8690e7"
    "d17bad17bd1ffed8b27ccf7d431dbbf89caa6125a9498a12edd47c4f028aa7d7df2c7e506ca344109a95d6791be3fffb4f7e86f8dde9fcde2d26a538777614f7",
    "32629eeb3432bbe03c1741fcbedafcbeeeba3cd04df91fe581a6f71fe581ecc14379206bda37fb1e2f7b1d7700e9dfbc7e77d750d7e4c1a4fc81ee5fb7826a19"
    "9894be49b96959dc7f0fd21f7ca2690addf16e00a7c6fd8bcd1b0a4d89185b680979c3c12fbf08a0b8dfe97c5fac1fd1817c2ebf7950c8b54bd1bdf291903f74",
    "51dcefd4f71796e79ed7dfde30d435d1781ed7fdeb5a502d7f6859bcff7d083e6ed01be27d560ab7594e4e82749ba745b6b234de7f6912ef008aa7d79b8df78d"
    "06d31cc9c671e0d3ff7c85e27ea78f03994e2b1262129ded42cedfafc478e08d97b9847bc601b371ff2ea47ddca0373d0e3c6438590b7a319bfd6e900a5ae577",
    "ef42f070837e6abe2756736c9e67017e3295f735432d81ef7fbf86f2fd8ee77bcf416da323ef3e16c45a5dcac7c95a389eecb8683d17bdc7d3fb0fe37bd87c63"
    "5e7bbd63a86386cf697a56026aa02a2b27399c9bcf4f42f1f4fa6bc6030cdba3ab4d61e41e84ce52cbd817f6bbe27b28ae773acfeff8cefaf9568de52285c8d9",
    "412b5c2b9c1dc610cfaf2ccfc3f0acdba7c3b0a3494ddda9f9fa28144faf37c3ebaa856c5fcf477cbe403cb37cfe4d081e6ed0775a74acd9a9488f4b5d9f2064"
    "a5fc86efb88cb987cf9d9277bde4f3870c2b4a32c3eabfc729a49f96fadff0d4b27cfdf72078b8413f32c6c9c808278c207282d03c113ab4c87042f7a4a29ca7",
    "5ede39ade10df1b4f6cb33f034fd0dcf77a86ef41acbd91f170cfff2cf7b288f735bc78379e37b692fd68b45cfcfb3bb3daf3fe5f54472a10d4fcc3de3c12bc8"
    "f3f3da7100691f37e817f75e3f7cfd074eea34d7a4457bfd74c7b2f9006c3f113ed128d1ae522e795d810555ba9704f2453f5e98ec4770463f34bdb979829dfb",
    "f8b197681dd7f9e341bedf64f9cdd6417183a5aafe6439974d6db829afff02f2fc0abfb723f1b8268f3f6b3ca9d4c9f1ca38cae34f2f3541791f7bf0501edf9a"
    "f65f419e4771fef4ef3b9f9f262d8bf367e5e1475f9c277bcb1b076e69deffe27e8fd15f08d546b6dfbff0f2dd0728cfe374fe175b9e668395fc213e90dd0259",
    "aae4db3b925c742eeb15e479c4ffd3bfef5c7e3ab097ff5980f87f16ffb3c076feff33e27fe7f37f8d3cdecaf88ae9d6161592239b64c64ffb733beee17fb4ee"
    "3bbdd444e77faf4e2de3f5ebe6efcde25d773fcf0b937841289e5eefa07c1fcad32f100fe5e9ad69df817c7e4e8b82d4e6f5df03964f5fc839dce1b3e0b80c7e",
    "641bbf336d8e534ab45ff375f7aa2956b23b6e1ffc01e5ed9dcff372c0cb1f448b3bf5b24f38efc8293e9eda905dc4f39f409e47e76aaffadde5fefb5f40da9b"
    "d75e1f40f070837edafdca611690a2e17239abd68d977daff2d319f89ade92fbf9a61972b2b26be3f8f0c78f4594d771faf890cb45e4b36cc3b34595d37b69aa",
    "406e675252dc3de3c310f23c7aaff5a2f7c32dcbc68b1f41f07083de385e7404b61a1245b21fe74859a6010b6ae3cf2d6b7fbfd9f9e4d10c3c4d6fda8fa618ce"
    "e6df611bfc9742e382d3c785f3dd842f72d82cf1392a530d959844aac7675c741f8fd9f7b900691f37e8cdcf1bd40cd109c309a47c723183b0f79c5719ddcb63",
    "12cffde7bcd1bd3c8bc443f7f258d3be59decf41dac70d7af3bc0f04394da6336272f46ad7b4b491cdf736142d5b079875cf322b011260ce5d078840f1f47a53"
    "fb77141bd99fe741ebbd0bc4b3ebde8656a89de1fdfd92df73207adb910dfa71874f63eee175f4feea6551bfa78bee5586e1e9f5e85ee5ebe2a9b22a78e85e65",
    "6bda47f1fcf45213583c3f80b437afddbe03c1c30dfae9bfa7c57082a05ac0a9f99c0c144fafb7eaf7b4c6161b0d0236f2ff6fd1fe1fe7f33f550f644b8093ab"
    "79818fb541c247c5c2bb2edab77f0bf3b2b76fffcf206d59fefe1b103cdca037f03e2d8ac25ceb168b3a9f75cbe27e69d43dba4aa86c3fe17c23f58f6db684b8",
    "ffaf7bc7288fef74deef815cf73cd5e4c33bad685cda8eecb63a82c745797cb3bc9f86b48f1bf48bfa1dc55348ffacf53bbf65f9fb372178f8442329876f31e7"
    "e6ef43503cbdfea6f93f6517bfa41dbec5ecf483e0e7876b288e773a9f9364225cee9e25d8a354a4cd85c320ba954dbb88cfd1fbab9745e5efcdfd0ebac6f2cb",
    "db876976dc4fcdc0d3f456e56d349fb1cf5f8641f43be8cee77bcf6622b01de916bd9e70b7cb799a9c3f5a3b77d17d3b88eff502e3fbe790f6e6b5d387103cdc"
    "a09f765e4b7f102109b21c59a1279f77cbb9ad6733f035bd25e73ba61ad4f6fb78a8b71b28bfe3f4f14120f71b1449ee44aabeed8654f2d2a972b3efa2f9c010",
    "f23c7aaff5a2f7c375d7cd136e9a0f42f384e9fd47f3047bf0d03cc19af69d9ee787c5c70bb9bf07fb69502d7f6259de7fd63aabd41265a5746ade3f0cc5d3eb"
    "4dcd234736b27f1d17e5fd17896717bffb77624cdd13483632315f52cee600e844a22edabf89de5fbde8fd6dcdb278febb103cdca0ffbf7dfb518127591033ee",
    "df5976dec76c5c60d7fe4d9d01edddbff9d9bfd13d0c8ee77f2ec557f933914e352345795b685799e3368be2fb157a8f15095816cfcffefd74e5ce4989766a3c"
    "9f80e2e9f5e6eee3d4ac64e7bdcbc1fb4fd0fd0a8ee7f36e3129c5b9b3a3b89711f35ca791d905e7b908e2f3d5e2f327177c8eee575305ddaf36bdd404ddaf66",
    "0f1eba5fcd9af6515e472f7a7ffb009dc7328987ce632d0a4f9555c143e7b1ac691ff1bd5e16b52fe7db103cdca087eccb99acd63a77fffedcebf956edcb99f8"
    "8c8dfb723efdc7bfd0baed6de5fb79ef5bdb6eefe73d47be4c484cfa62a0b47b100007010cf1fdaaf1fd73487b68ffbe2a4393f8abb7cf17eddf5f241edabf6f",
    "4dfb43c8f3e8bdd68bdbe7091abeddfbf7d13cc16a3c5556050fcd13ccb5ff3f49da7ff5",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 55264U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_fj_inF_info.c) */
