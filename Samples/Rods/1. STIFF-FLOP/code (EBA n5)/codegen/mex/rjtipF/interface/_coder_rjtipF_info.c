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
                (737431.8314583333));
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
    "789ced5dcd6fe3c615e726d96017455a026993f42bcda6c52245024b9664d9db36a8be6dd9d6b756f63a49654aa224dafc90484a9675a98f3de4903fa0871cd3"
    "a22d36bd64d104857aebb540d3434f018aa0975edb734551b43d5c4d449b235a94de038c11fdc4f98d1e1e7f33f3e6cd90ba954cdda228eaebc3bfd22f292af4",
    "a27645512f50bad0e3f2190a15b3fed6b85c315d1b729b7a0eb9efd618efd7e3ebaa24aa6c4fd52f784e64d31da1c2cac30b9111d8f36a6a92c0898ca8164f5b"
    "2c25b38ac477d9da4853e778b6c809ecae74e9628b1b5e08894baaf30b4da57d8e36d9ea71a123507253b9682e7ff9821adb4793c798dfff9c45fba431f6a14d",
    "fa77e2ef799a92c07a9a4c8df3a4e29b61e554ac7ab6b4ab7047958aa962ec54f444a51a7bf93ac2aa8ca7bbbae2f554358d7ca472adc48a70d1fe1ea67dcf5b"
    "6cffb398f6df1d97af20ff7d3ba4973f1d973f0b19ed38c4e058b5e36d4c3be8b1a6259d8cbc8714def3a6eb0b3c5d53933a159ebdc0fbc8265e188b87eadf49",
    "eeee0f5da5a3c81e5eaa32bc27152eee86239ebccfbbba51f1a892c457a49e8715780fcf553c02a3f24cc523b514cfc8429a6b8c649a9dacfa87b934e42e7567"
    "fce9ecfdcf83ff083b87a7cbb2e0e19e6fab7ef712068f36e9f79a253658c815d6f2c55c673fb67350920a0fa317edc84ec199d60e0a73ed54fd6e7d7e5b9876",
    "59f5b7674cd78618fc4e23ffbd1fd2cbd7cf79fd0c53bf55bbfd00834f9bf45af726af70c341832c32fc0aa7443a1caf26c5e1b08195b9ea8df1fe139b78792c"
    "1eaabf82df687f6f8eece579d33098c76c30c3911cec073ef9ef3f3f877e6046784ef503996e3b1aae6f75378ab9c069352e88bec401bfb538fd80ddf1fe36a6",
    "7edaa4b7dd0fdcabf3aa31e8a51cf6bbb3548894dfbd8cc1a34d7a13ff2b43933172bc7163bc3f877e3291f70d43dd00dfffe1fe2f60dcef76bef7e61bab5d75"
    "fb8124379a4a21c13422896437067cbf3ccf3185f03d6ebe61d55e2f98ae29d3f70c3da788fa4055d5227f3717d7b1eb1f492c1eaabfe278a0cef5d85a4b1aba",
    "8707b1d40dc477a8dfef7d1bc6f56ee7f94dfff169a1dde0f868317a9c6f471ac5e38771e0f9a5e5791c9e557bdd315d53e7dfd3359c52e786939aa65be3f531"
    "2c1eaab7c3ebba85744f003e5f0c3cbb7cfe2d0c1e6dd277db6cbcd5ad2a0ff64ffc9294550aabfe4707d4e2f0b95be2ae177c7eafcec98a5ae7d0df71886927",
    "51ff1b1c128bd7bf8ac1a34dfaa131ca432394eb92cc4b52ab2c7559b9ce4b27e5aab6fe6e7f3c6f165c7b0c31f006d7c433ea3f988267e8af17df1bbbd15758"
    "cef971c1e0b32f6f431c675efb03abe37b6527de8bc7fafdec76cf1748f9bcd15c78d51b5f9cfee00bccfd56ed7886a99f36e967f75cdffbea2f949b2cdf6265",
    "67fd7493d87ce039d33575fe3d5da38d76b5f286d71538b1c6f692a27ade8e0f6db62334a51d86dede3c614570d02f9ec03aaefbfb83c2698b13d6daf9bd55ae"
    "520b240f72d9d4ea22c5f53fc4dcbfc4cfed50bc0b13c79fd69f549bcc68651ce2f8934b4320eee30c1ec4f1c9d4ff05e67e18e74ffebdd6fc34496c9c3f2d0e",
    "3ffce102d3bbb97e604ee3fe86fff0c30f1edd464ec7fd074f5ebe0b711eb7f3bfdcf6b68e3825101682d975315bd9f7ef949408f03ff03f2ae8baafb3fccf89"
    "c0ffd3f89f131de7ff4f81ffddcfff0de6d17ac6bf976eaf57c26a748dc904d8406e7371f81fd67d27978620fef7c521315ebf6afcde2ede55f3793eb48917c2",
    "e2a17a17c5fb204e3f433c88d393a9df857cde676549e908e8efc0c5d367b20f77f06e685486de738cdfeb1d9ed74ac8d79c346e575a8c5cef881ecd4a4e8fdb"
    "cf3e86b8bdfb795e0dfa847c6c6fb379e097fa5d35252452abea02f1fc63ccfdb0aff6b2df5de4dfff0a539f557bbd81c1a34d7a53fe0bd36af1a7114e64e4d3",
    "c2a8c74b74c4aaca4922a975e36f4c6997a1af8f71cb4d46ac0d3b0252f99bef4cc137f476c70b58438e57761dec1ffef81b19e23a6eef1f72b9a87a9c3df2ae"
    "570ed23be94a91d9c8a494c4e2f40f03ccfdf05ca382fae13ab1fee287183cdaa437f7175d89ab856599394df08caab222273646dfbba9fc7ebbf3c9d2143c43",
    "6fdb8f2618eef2b97d87987612f49fb3ff55a05f707bbfd0dfdef2471fb6f6855c25530befd7b7523d21b340e7f1d87d9e8b98fa6993defebc418f1095ebbcc4"
    "a8e5f31984b3fbbc0ee05c1e9b788bbfcf1bcee599251e9ccb43a67ebbbc9fc3d44f9bf4f6795f94d43493cec8c9e1a3dd30c2460e9fdbb0476c1d60da39cb9c",
    "223222e5de758028160fd5dbcadfd16ce47c9c07d67b6788e7d4b90ded702723044ef703debceceb4457d9075d214d2d0eafc3f38b0aea6f3f22764e039cab8c"
    "c343f570aef255f17459163c3857994cfd309e9f5c1a821bcf9f61eab36ab7ef62f068937e621c67a5ce4b926e01b7c67332583c546fb71f7853b7986764b161",
    "27e020ffff16f27fdccfff956630bb2ff26aad2009f18eb8e5afc423db0b94b73f8771d9f9cbff394b138bdf7f1383479bf426de676559b2b46e31abfd597336"
    "ee5786cd636b1e9dedc79c6fa6fe91cd6e60dcffe79d4710c7773beff7c4dc493fd512229bed5842d9886eb7bb927781e2f876793f8da99f36e967f5fec4434c",
    "fbc8faddcf1dcbe357daf2e8a59b6e8ddf47b078a8febaf13f2d8b5fb391f37c1efacbc3fb308e773b9f0736e3f5a637983ccac4fd49359b13c56e34b640711c"
    "787e5141fded3eb1b8cdf73078b449ff54fc3e26090c27c6cde3f896cdf6d8cddb774b1c0731a0b3719c3ffd07f2315dcfff7c4aa809c7329b6a45f7d40da953",
    "ab3fea700b74fe0e3cc793db8ffa5d90d8787efa7b54b4bda70aebd6f1fc16160fd5dbdb976b58c9c9f3174277de863c4bd7f3f9c95e5249f0c7a584af2e17f8"
    "ee51665bece7a2c0e7cbc5e76fc33eabb1c03e2bb4dd16fc07f659cd100ff65991a91fe23aa8a0fef606accbdac48375d959e1e9b22c78b02e4ba67ee07b5450",
    "7f5b2116c7ff0e068f36e927e75f1aabb53737ceb73b3fb4bc7e4f28ffd2f019e7fc65f0c9bffe0debb6f3caf756f75d6d74760bde923f139693feb8b8bf9d0f"
    "8af920057cbf6c7cff01a63eab76fa31068f36e9279dbb861e289414b33c5365c7df9f9775dc814dfc77a7e01b7a22e7344d34a8e3e7ea57be7604f38179ed1f",
    "acce072466f7a8c2309bd19a7fe348d9f7b1a983d6e902cd070698fbe1b94605f5c3b7609dd7221eacf392c2d36559f0609d974cfd03ccfdc0efa82c7a1ce8ba"
    "fc0f71a0c9ed873890337810072253bf63cfb1abf7638588f1fe6b183cdaa437f1becc2a4da6c516b83e1bd5de0aa9b835cfa73005cfd0dbe5fda70ce6fcf96b",
    "7ffbdd47300f9857feb73a0f086e7af9f5ec7a2e5bda2a29a5bd606327df5ea4f7b0c0f33cb93404f5bfd788e5fdbc82c1a34d7a533f2032728313abcd63b7f2"
    "3fe13c4f2b793fe7367376dc70f6e24ff27f07fe9f119e53fc7fda3b493e6012f5c69ab79a894b85a34467fd240efc3f6fcf33ce1facfadfb398df61bc6ff115",
    "e4bf6f85f4f2f57179b1cff7108343eabc65e30436b7c6fd677d5eebe8ad8be333d73471909fe0bc8619e239c5f71bedf54cb1cdc7d68e23cd626eb3a0b663b1"
    "ea02bd570b9e5f5470e3fb334c7d70deb2353c386f795678ba2c0b1e9cb74ca67ee07d546675cefebc9caf6c16abf19dc7d7c433ea87f39549e3e9b22c7870be",
    "3299fa81ef51c1f1fd0798fa20bf5f97814dfce5cb1383fcfe59e2417e3f99fa0798fbe1b9466556f99ff3324fb86e7c08e60993db0ff30467f0609e40a67ec8"
    "ff995c1a82fa9ff79cffed9efb760f83479bf4e67983a2b0b25a6278aea699222c37c6df73eb3a41118b87ea6d8f239e329ce3f38267a227302f707b7fe0f31d",
    "f71fc412916463b75738e86f55b61ee455c8075ac2e779286717fb027078b0df5717d8ef4b0a4f9765c183fdbe64ea075e9f5c1a82f27a18f280c6ff873ca0c9"
    "a5219007e40c1ee40191a97f80b9dfaa1dcb98fa69937e16fdc03d4ed1f40d99e19df5c3c123c7f2fbb59f58a720bf1f973730fce019d9c8f9fdbc4f80dfddcf",
    "ef6bbd149f38eed68e92c1fdde764df605c44210f2fb97e0f9d5845c9e278ceb7178a81ec6f557c5d36559f0605c4fa6fe01e67ed78ceb2b5247ac290e8feb73"
    "c4fa83ef63f06893fea9fe20a9cd685839ca0f2d43911bf75ff57d2e8f6de2654dd794e97b86de7e7f70d9608ec6f9df7fe92ec4f9ddde0f24c4dd6c24bc97ee",
    "73422f73d4aa0919357dba4071fe01e67ee8075041fb8187c4e23bd3c6e14303084cefe678deeefc3086c543f5b6e687231b399e9ff3e465e077d7f3bbdcf6b6"
    "8e3825101682d975315bd9f7ef9494057adffa00733ff03b2aa81f961ce5774e047e9fc6ef9ce838bf7f0afcee7e7e6f308fd633febd747bbd1256a36b4c26c0",
    "0672908f7f5edf52e5e9505bc0eb16f180d749e1e9b22c78c0eb64ea075e9f5c1a82e65fa6211e63110fe231a4f07459163c88c790a9ffaf98fbadda91c1d44f"
    "9bf433d83f7bafcbc8a3a394cb2d59aa997ed721a6dd6479be4a6cfdf5550c1e6dd20f8d531e1aa55c97645e925a65a9cbca755e3a295735abdcdcb96b836be2",
    "19f51f4cc133f4d7ec0774b7fa0acb399f9733f8eccbdbd03fb8bd7f5076e2bd78acdfcf6ef77c8194cf1bcd8557bd0bb09ff6ff7ddf0a20",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70488U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
