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
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/rjtipF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737560.59440972225));
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
    "789ced5dcd6fe3c615e726d9208b222d81b449fa9566d3629122a9294bb2ec2d10c0fab4655bdf5adbeb7cc8944449b4f92191942ce9521f7bc8217f400f39a6"
    "455b6c7bc9a2090af5d66b81a6879e0214412fbdb6e78aa268ef7035116d8e68517a0f3046f413e7377c78fccdcc9b3723ea5632758ba2a86f0eff3efc054535",
    "5fd2af28ea45ca107a5c3e43a162d5df1a972b966b536e53cf21f7dd1ae3fd6a7c5d91258deb6ac685c04b5cba2d9639657821b12277514d5516798995b462af"
    "c9510aa7ca4287ab8e34355ee08abcc8edc94f5c6cf3c30b31f184eae24257e99fa30dae725a688b94d2502f9b2b3c79418deda3cb00f3fccfd9b4cf0718fbd0",
    "16fdbbf1f799862c724c83adf24c81ad714c2abe15567b5285d9d6ff554c15633d8989ca55cefc1ce13496e9acaef898bc5c5599d595d70bc56422f1b3c45e26"
    "cb54f42f2a271adf4cac8897cfd3c5b4f7799bcff32ce679ee8ccb5791fffa368df2ed71b9b269b6e3188363d7aeb731eda0c79aa67c36f2265278cf5bae2ff1",
    "0c4d556e9705ee12ef138778612c1eaa7f37b97738749db6aa30825c610526152eee85234cdeef5bdd28339a2c0b65b9cb70a2c0087c9911594d60cb8cdc5499"
    "918574d718c9343bd9f50f6b69ca1dea85f1a7f30fbf08fd23ec1e9e21cb82877bbfedfaddcb183cdaa23f68ec73a142aeb0962fe6da87b1dda37db9f0207ad9",
    "8eec149c69eda030d76ed5efd5f7b78969975d7f7bc6726d8ac9ef34f2df7b9b46f9c605af9f63eab76bb71f61f0698b5eefde94157e388850245658e1d5489b"
    "17b4a4341c46700a5fb931de7fec102f8fc543f557f01bfdefad91bd98b74c83315683998ee4623ff0e97ffff905f40333c273ab1fc8745ad1706dbbb351cc05",
    "7b95b828f91347c2f6e2f4038f30f7dbb5e30ea67edaa277dc0fdcad099a39e8a55cf6bbf3d42629bf7b0583475bf416fe578726639578fdc6787f0efd6422ef"
    "9b86ba01befffdbd0f60dcef75bef7e5ebab1d6de7beacd41b6a21c1d623896427067cbf3cef3185f03d6ebe61d75e2f5aae29cbf74c3daf4ac64055d3238137",
    "17d771ea1f492c1eaabfe278a0c677b96a531eba078358ea06e23bd4ef0ebe0be37aaff3fc56e0b45768d579215a8c9ee65b917af1f4411c787e69791e8767d7"
    "5e2f58aea98bef191a5eadf1c3494dc3abf1fa18160fd53be175c3428627009f2f069e533eff0e068fb6e83b2d2edeec54d4fb87670159ceaa85d5c0c3236a71",
    "f8dc2b71d74b3ebf5be31555abf1e8731c63da49d4ff06c7c4e2f5af61f0688b7e688cd2d008a59aac08b2dc2cc91d4ea909f259a9a2afc73b1fcf5b05d71e53"
    "48adef1f4dc133f5d78bef8ddde86b2ce7feb860f0f957b7218e33affd81ddf1bdba1befc663fd7e76a7eb0fa6fcbe682ebcea8b2f4e7ff025e67ebb763cc7d4",
    "4f5bf4b37bafef7efd174a0d4e68728abb7eba456c3ef09ce59abaf89ea1d147bb7a79c3eb0abc54e5ba4949bb68c7c70edbb139a51da6ded93c614574d12f1e"
    "c33aaef7fb8342afc98b6badfcc12a5fae069347b96c6a7591e2fa1f63ee5fe2f796d2f33317258e3fad3fa934d8d1ca38c4f12797a640dcc71d3c88e393a9ff",
    "4bccfd30ce9ffcbcf6fc34496c9c3f2d0e3f7c7091edde5c3f30a7717fd37f84e107c6b091db71ffc1e357ee409cc7ebfcafb47ccd135e0d86c550765dca960f"
    "03bbfb6a04f81ff81f1574ddd75dfee725e0ff69fccf4baef3ff67c0ffdee7ff3afb703d133848b7d6cb612dbac666825c30b7b538fc0febbe934b5310fffbf2",
    "9818af5f357eef14efaaf93c1f3bc4dbc4e2a17a0fc5fb204e3f433c88d393a9df837cdee714596d8be873e0e2e933d9873b786f73546ebeef1abfd7da82a097"
    "90af3969dcae3659a5d69618dd4a6e8fdbcfff00717beff3bc16f28bf9d8c156e32820f73b5a4a4ca456b505e2f94798fb615fed937e77997fff4b4c7d76edf5",
    "26068fb6e82df92f6cb329f422bcc42abdc2a8c74bb4a58ac6cb12a975e36f4d6997a9af8d714b0d56aa0e3b0252f99bef4ec137f54ec70b58438e57765dec1f"
    "fef86b05e23a5eef1f72b9a8769a3df1ad978fd2bbe97291ddc8a4d4c4e2f40f03ccfdf05ea382fae13ab1fee2c7183cdaa2b7f6171d99af861585ed250456d3",
    "388997eaa3efdd547ebfd3f9e4fe143c53efd88f2618eec973fb8e31ed24e83fe7ff2b43bfe0f57ea1bfb31d883e681e8ab972a61a3eac6da7ba626681cee371"
    "fa3e1731f5d316bdf3798311212ad50499d54a17330877f7791dc1b93c0ef1167f9f379ccb334b3c3897874cfd4e793f87a99fb6e89df3be246b69369d5192c3",
    "57bb6e868d5c3eb7e180d83ac0b4739679556225cabbeb00512c1eaa7794bfa3dbc8fd380facf7ce10cfad731b5ae176460cf60e83bebce26f4757b9fb1d314d"
    "2d0eafc3fb8b0aea6f3f21764e039cab8cc343f570aef255f10c59163c3857994cfd309e9f5c9a821bcf9f63eab36bb7ef63f0688b7e621c67a526c8b26101af",
    "c67332583c54efb41f78cbb01833b2d8b0137091ff7f03f93fdee7ff7223943d9404ad5a90c5785bda0e94e3919d05cadb9fc3b8ecfce5ff9ca789c5efbf8dc1"
    "a32d7a0bef738a22db5ab798d5feac391bf7abc3e67155c660fb31e75ba97f64b31b18f7ff79f721c4f1bdcefb5d2977d64f35c5c8562b965037a23bad8eec5b",
    "a038fe0073bf5d3bcedbef291e63da4bd60ffdaee5f5ab2d65f4a39c5e8de747b078a8febaf1403dab5fb791fbfcbef99707f7605cef757e0f6ec56b0d5f2879"
    "928907925a3627499d686c81e23af0fea282fadb3d62719c1f60f0688bfea9787e4c16595e8a5bc7f54d87ed719ac7ef95b80e624077e33a7ffa0fe4677a9eff",
    "859458154f152ed58c1e681b72bb5a7bd8e617e83c1e788f27b71ff5bb10b1f1fcf4df55d1f7a2aa9c57c7f3db583c54ef6c9fae692537cf63d87ce11dc8bbf4"
    "3c9f9f1d24d58470ba9ff0d79482d039c9ec48fd5c14f87cb9f8fc1dd8773516d87785b6db86ffc0beab19e2c1be2b32f5435c0715d4dfde84755a8778b04e3b",
    "2b3c4396050fd669c9d40f7c8f0aea6f2bc4e2f8dfc3e0d116fde47c4c73b5f6e6c6f94ee787e92978a69e543ea6e933eef9cbe0d37ffd1bd66de795efedeec3"
    "da68ef157cfb814c584906e2d2e14e3e24e54314f0fdb2f1fd4798faecdae9a7183cdaa29f740e1b7ac05052ca0a6c851b7f7f5ed671070ef1df9b826fea899c",
    "db34d1a0ae9fb35ffec609cc07e6b57fb03b1f90d9bd9332cb6e45ab818d13f5d0cfa58e9abd059a0f0c30f7c37b8d0aea876fc33aaf4d3c58e7258567c8b2e0"
    "c13a2f99fa0798fb81df5159f438d075f91fe24093db0f712077f0200e44a6fe01e67ed89f850aea870162fdc0eb183cdaa2b7f4030aa736d82657e0fb5c54ff",
    "d548d5ab793f852978a6de693ff094c1dc3f9fed6fbffd04e605f3da1fd89d1784b67cc27a763d97dddfde57f70f42f5dd7c6b917ea705dee7c9a529a8ffbd4e"
    "2c0fe8550c1e6dd15bfa018955eabc54699c7a95ff09e77ddac903bab099bbe386f3977e9eff3bf0ff8cf0dce2ff5ef72c799f4dd4ea6bbe4a262e174e12edf5",
    "b338f0ffbcbdcf387fb0eb7fcf629ec3fc3dc65791ffbebd69946f8ccbcb7dbfc7181c52e7319b27b479751d60d6e7b98e7e95717c269b2e2ef2139cdf30433c"
    "b7f87ea3b59e29b684d8da69a451cc6d15b4562c5659a0dfdd82f71715dcf8fe1c531f9cc76c0f0fce639e159e21cb8207e73193a91f781f95599dc33f2fe72f",
    "5bc56e7ce7d135f1ccfae1fc65d278862c0b1e9cbf4ca67ee07b54707cff11a63ec8f73764e0107ff9f2c620df7f967890ef4fa6fe01e67e78af5199553ee8bc"
    "cc13ae1b1f8279c2e4f6c33cc11d3c982790a91ff27f2697a6a0fee7bbe07fa7e7c0ddc5e0d116bd75dea0aa9ca2edb3025fd54d1156eae3ef79759da088c543",
    "f58ec7114f19cef579c133d133981778bd3ff0fb4ffbf7638948b2bed72d1cf5b7cbdbf7f31ae4032de1fb3c94f34dd8ff6b130ff6ff92c2336459f060ff2f99"
    "fa81d72797a6a0bc1e863ca0f1ff210f6872690ae401b98307794064ea1f60eeb76bc712a67edaa29f453f709757757d5d610577fd70f0d0b5fc7efd116b14e4",
    "f7e3f206861f98918ddcdfcffb18f8ddfbfcbed64d0989d34ef524193aecee54157f502a8420bf7f09de5f5dc8e579c2b81e8787ea615c7f553c4396050fc6f5"
    "64ea1f60eef7ccb8be2cb7a5aaeaf2b83e47ac3ff821068fb6e89fea0f92fa8c8653a2c2d03214b971ff557fdfe59143bcace59ab27ccfd43bef0f9e3498ab71",
    "fe0f5fbe03717eaff70309692f1b091fa4fbbcd8cd9c34ab62464bf71628ce3fc0dc0ffd002a683ff080587c67da387c680091edde1ccf3b9d1fc6b078a8ded1"
    "fc706423d7f3731ebf02fcee797e575abee609af06c36228bb2e65cb8781dd7d75817e7f7d80b91ff81d15d40ff75de5775e027e9fc6efbce43abf7f06fcee7d",
    "7eafb30fd7338183746bbd1cd6a26b6c26c80573908f7f51df52e5e950dbc0eb36f180d749e119b22c78c0eb64ea075e9f5c9a82e65fa6211e63130fe231a4f0"
    "0c59163c88c790a9ffaf98fbedda91c5d44f5bf433d83f7bb7c32aa3a3944b4d45ae5a9eeb18d36eb23c5f21b6fefa1a068fb6e887c6290d8d52aac98a20cbcd",
    "92dce1949a209f952aba556eeedcb5c135f1ccfa8fa6e099fa6bf603865b7d8de5dccfcb197cfed56de81fbcde3fa8bbf16e3cd6ef6777bafe60caef8be6c2ab"
    "be05d84ffb7f30e51669", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70536U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
