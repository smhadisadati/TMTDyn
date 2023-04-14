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
                (737430.19488425925));
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
    "789ced5d4d6ce3c615e6a6d9348b222d81b4d9f42fcda6c52245024b9664d95b2080fe6dd9d6bfd6f63a49654aa224dafc91484a9674a98f3de490630f3de498"
    "166db1ed258b2628d45baf059a1e7a0a5004bd14bdb5e78aa2687bb89a156d8e68517a0f30c6d413e71b3d3c7e33f3e6cd90ba954cdda228eaebc3bffffc8ca2",
    "8e5ed6ae28ea254a177a5c3e47a162d6df1a972ba66b436e53cf23f7dd1ae3fd727c5d914495edaafa05cf896cba2d945979782132027b5e4d5512389111d562"
    "afc95232ab487c87ad8e34358e678b9cc0ee4a972eb6b8e18590b8a43abfd054daffd1065b3929b4054a6e2817cde52f5f5063fb68f218f3fb9fb7689f34c63e",
    "b449ff6efc7d4f4312584f83a9729e547c33acf4c48a674bbb0ab755a9982ac67aa2272a55d9cbd71156653c9dd515afa7a269e463956b2656848bf6ff02d3be"
    "172cb6ffab98f6df19971b973f3ccb84f432ac9794518e3fa72263bd51a643463b8f30edb06ae7db9876d2634d533a1d791729bc174cd71778baa62ab5cb3c7b",
    "81f7b14dbc30160fd5bf9bdc3d18ba525b913dbc5461784f2a5cdc0d473c799f7775a3ec5125892f4b5d0f2bf01e9e2b7b0446e599b2476a2a9e918534d719c9"
    "343b59f51f7369c81deac5f17f671f7c1efc7bd8393c5d9605af8ba9cfaadfbd82c1a34dfafdc61e1b2ce40a6bf962ae7d10db39dc930a0fa317edc84ec199d6",
    "0e0a73ed54fd6e7d7e9b987659f5b7e74cd78618fc4f239fde0fe9e51be7bc7e86a9dfaadd7e80c1a74d7aadfb9357b8e1a04216197e8553226d8e5793e27058"
    "c1ca5ce5c678ff894dbc3c160fd55fc16fb4bfb746f6f2bc6518cc633698e1480ef6039ffcf71f9f433f30233ca7fa814ca7150dd7b63a1bc55ca057890ba22f",
    "71c86f2d4e3f60773eb08da99f36e96df703f76abc6a0c7a2987fdee2c1522e577773178b4496fe27f656832468ed76f8cf7e7d04f26f2be61a81be0fbdfddff"
    "298cfbddcef7de7c7db5a36e3f90e47a432924987a2491ecc480ef97e739a610bec7cd37acdaeb25d33565fa9ea1e714511fa8aa5a64f0e6e23a76fd2389c543",
    "f5571c0fd4b82e5b6d4a43f7f02096ba81f80ef5dbfd6fc3b8deed3cbfe93fe9155a758e8f16a327f956a45e3c7918079e5f5a9ec7e159b5d78ba66beafc7bba"
    "86536adc7052d3706bbc3e86c543f576785db790ee09c0e78b816797cfbf85c1a34dfa4e8b8d373b15e5c1c1a95f92b24a61d5ffe8905a1c3e774bdcf582cfef",
    "d53859516b1cfa3b8e30ed24ea7f832362f1fad73078b4493f3446696884524d9279496a96a40e2bd778e9b454d1d6e7ed8fe7cd826b8f2106dee09a7846fd87"
    "53f00cfdf5e27b63377a86e59c1f170c3efbf236c471e6b53fb03abe5776e2dd78acdfcf6e777d8194cf1bcd8557bdf1c5e90fbec0dc6fd58e6798fa69937e76",
    "cff5bd677fa1d460f9262b3beba79bc4e603cf9baea9f3efe91a6db4ab9537bcaec08955b69b14d5f3767c64b31da129ed30f4f6e6092b82837ef104d671dddf"
    "1f147a4d4e586be5f757b97235903ccc6553ab8b14d7ff0873ff123fb743f12e4c1c7f5a7f526930a3957188e34f2e0d81b88f337810c72753ff1798fb619c3f",
    "f9f75af3d324b171feb438fcf0870b4cf7e6fa81398dfb1bfec30ffff1e836723aee3f7872f70ec479dcceff72cbdb3ce69440580866d7c56cf9c0bfb3a74480"
    "ff81ff5141d77d9de57f4e04fe9fc6ff9ce838ff7f0afcef7efeaf338fd633fefd746bbd1c56a36b4c26c006729b8bc3ffb0ee3bb93404f1bf2f8e88f1fa55e3",
    "f776f1ae9acff3914dbc10160fd5bb28de0771fa19e2419c9e4cfd2ee4f33e2b4b4a5b407f072e9e3e937db883f742a332f4be63fc5e6bf3bc5642bee6a471bb"
    "d264e45a5bf46856727adc7ef67b88dbbb9fe7d5a04fc8c7f6371b877ea9df51534222b5aa2e10cf3fc6dc0ffb6a2ffbdd45fefdcf31f559b5d79b183cdaa437",
    "e5bf30cd26df8b702223f70aa31e2fd1162b2a2789a4d68dbf31a55d86be36c62d3518b13aec0848e56fbe3b05dfd0db1d2f600d395ed975b07ff8c3af6488eb"
    "b8bd7fc8e5a2ea49f6d8bb5e3e4cefa4cb4566239352128bd33f0c30f7c3738d0aea87ebc4fa8b1f62f06893dedc5f7424ae1a9665a697e0195565454eac8fbe",
    "7753f9fd76e7937b53f00cbd6d3f9a60b8cbe7fa1d61da49d07fcefe57867ec1edfd427f7bcb1f7dd83c1072e54c357c50db4a7585cc029dc763f7792e62eaa7"
    "4d7afbf3063d4254aaf112a396ce6710ceeef33a8473796ce22dfe3e6f3897679678702e0f99faedf27e0e533f6dd2dbe77d5152d34c3a2327878f76dd081b39",
    "7c6ec33eb1758069e72c738ac888947bd701a2583c546f2b7f47b391f3711e58ef9d219e53e736b4c2ed8c10e81d04bc79d9d78eaeb20f3a429a5a1c5e87e717"
    "15d4df7e44ec9c063857198787eae15ce5abe2e9b22c7870ae3299fa613c3fb93404379e3fc3d467d56edfc5e0d126fdc438ce4a8d9724dd026e8de764b078a8",
    "de6e3ff0966e31cfc862c34ec041feff35e4ffb89fffcb8d60f640e4d56a4112e26d71cb5f8e47b617286f7f0ee3b2f397ff73e97d5976fdee9b183cdaa437f1"
    "3e2bcb92a5758b59edcf9ab371bf326c1e5bf5e86c3fe67c33f58f6c7603e3fe3fed3c8238bedb79bf2be64efba9a610d96cc512ca4674bbd591bc0b14c7b7cb",
    "fb694cfdb4493fabf72b1e61da47d4ef4259c7f2f895963c7a29a75be3f7112c1eaabf6efc4fcbe2d76ce43c9f87fefcf03e8ce3ddcee781cd78ade10d268f33"
    "717f52cde644b1138d2d501c079e5f54507fbb4f2c6ef33d0c1e6dd23f15bf8f4902c38971f338be69b33d76f3f6dd12c7410ce86c1ce78fff867c4cd7f33f9f",
    "12aac289cca69ad17d75436a576b8fdadc029dbf03cff1e4f6a37e1724369e9ffe1e156defa9c2ba753cbf85c543f5f6f6e51a5672f2fc85d08bef409ea5ebf9"
    "fc743fa924f893bd84af2617f8ce71665bece7a2c0e7cbc5e7efc03eabb1c03e2bb4dd16fc07f659cd100ff65991a91fe23aa8a0fef626accbdac48375d959e1",
    "e9b22c78b02e4ba67ee07b54507f5b2116c7ff0e068f36e927e75f1aabb53737ceb73b3fb4bc7e4f28ffd2f019e7fc65f0c93fff05ebb6f3caf756f75d6db477"
    "0bde3d7f262c27fd71f1603b1f14f3410af87ed9f8fe434c7d56edf4630c1e6dd24f3a770d3d5028296679a6c28ebf3f2febb8039bf8ef4dc137f444ce699a68",
    "50c7cfd52f7fed18e603f3da3f589d0f48ccee71996136a355ffc6b172e0635387cdde02cd070698fbe1b94605f5c3b7619dd7221eacf392c2d36559f0609d97"
    "4cfd03ccfdc0efa82c7a1ce8bafc0f71a0c9ed873890337810072253bf63cfb19bf7639de588f1feeb183cdaa437f1becc2a0da6c916b83e1bd5de0aa9b835cf",
    "a73005cfd0dbe5fda70ce6fcf96b7ffdcdc7300f9857feb73a0f086e7af9f5ec7a2ebbb7b5a7eced07eb3bf9d622bd87059ee7c9a521a8ffbd4e2cefe7550c1e"
    "6dd29bfa019191eb9c58699cb895ff09e7795ac9fb39b799b3e386b3977f92ff1bf0ff8cf09ce2ff5ef734f98049d4ea6bde4a262e158e13edf5d338f0ffbc3d",
    "cf387fb0ea7f5fc1fc0ee37d8baf229fbe1dd2cb37c6e5c53edf230c0ea9f3968d13d8dc1af79ff579ada3b72e8ecf5cd3c4417e82f31a6688e714df6fb4d633"
    "c5161f5b3b89348ab9cd82da8ac52a0bf45e2d787e51c18defcf30f5c179cbd6f0e0bce559e1e9b22c7870de3299fa81f75199d539fbf372beb259acc6771e5f",
    "13cfa81fce57268da7cbb2e0c1f9ca64ea07be4705c7f71f62ea83fc7e5d0636f1972f4f0cf2fb678907f9fd64ea1f60ee87e71a9559e57fcecb3ce1baf12198"
    "274c6e3fcc139cc183790299fa21ff67726908ea7fde73feb77beedb3d0c1e6dd29be70d8ac2caea1ec37355cd1461b93efe9e5bd7098a583c546f7b1cf194e1",
    "1c9f173c173d857981dbfb039fefa4ff20968824ebbbddc2617fabbcf520af423ed0123ecf43390bc17e5f8b78b0df97149e2ecb8207fb7dc9d40fbc3eb93404"
    "e5f530e4018d3f873ca0c9a5219007e40c1ee40191a97f80b9dfaa1d4b98fa69937e16fdc03d4ed1f47599e19df5c3c123c7f2fbb59f58a320bf1f973730fcc7",
    "33b291f3fb799f00bfbb9fdfd7ba293e71d2a91e278307ddedaaec0b888520e4f72fc1f3ab09b93c4f18d7e3f0503d8cebaf8aa7cbb2e0c1b89e4cfd03ccfdae"
    "19d797a5b658551c1ed7933bd7e7fb183cdaa47faa3f486a331a568ef243cb50e4c6fd577d9fcb639b7859d33565fa9ea1b7df1f5c3698a371fe0f5eb903717e",
    "b7f7030971371b09efa7fb9cd0cd1c37ab42464df71628ce3fc0dc0ffd002a683ff090587c67da387c680081e9de1ccfdb9d1fc6b078a8ded6fc706423c7f373"
    "9edc057e773dbfcb2d6ff39853026121985d17b3e503ffce9eb240ef5b1f60ee077e4705f5c33d47f99d1381dfa7f13b273aceef9f02bfbb9fdfebcca3f58c7f",
    "3fdd5a2f87d5e81a9309b0811ce4e39fd7b754793ad416f0ba453ce0755278ba2c0b1ef03a99fa81d7279786a0f9976988c758c483780c293c5d96050fe23164"
    "eaff0be67eab766430f5d326fd0cf6cfdeeb30f2e828e5525396aaa6df75846937599eaf105b7f7d0d83479bf443e394864629d5249997a46649eab0728d974e",
    "4b15cd2a3777eedae09a7846fd8753f00cfd35fb01ddad9e6139e7f372069f7d791bfa07b7f70fca4ebc1b8ff5fbd9edae2f90f279a3b9f0aa7701f6d3fe1fd7"
    "1710d4", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70520U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
