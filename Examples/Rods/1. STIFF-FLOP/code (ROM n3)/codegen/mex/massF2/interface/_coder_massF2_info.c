/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_massF2_info.c
 *
 * Code generation for function '_coder_massF2_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "massF2.h"
#include "_coder_massF2_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("massF2"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF2.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737429.668912037));
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
    "789ced5dcd6fe3c615e76e77832c8ab404f2d9af349b148b14092c5992656f8100fab6645b5f963f6427a94c4994449b1f1249c9922ed5b1871cf60fe821c7b4"
    "688b6d51208b2408d45baf059a1e7a0a5004bdf4da9c4b89a26dce6a56dc254599d47b8031a69e38bfd1c3f0f766de0cdf103752e91b04417c4ff9fbcbaf08e2",
    "c18ba32b82788150859c943709bda0fa1b937205b9d6e436714b77df8d09de6f26d7158197e9aeac5eb00c4f67da5c9916950b9ee2e88b6aaa02c7f0142feff5"
    "9a3421d292c076e8ea585363587a8fe1e81de1ca4592512eb8c415d5c5c54835fa3fdaa02b67853647880de9b2b9ecd50b62629f913cc4fcfe5b06ed93c1d887",
    "44f4efc73ff434048ef634a82ae349c737c3528faf7892a3ab705b16f6d27bb11eef890a55faea758496294f6775c5eba98c341c254909df0a77d9fe8f31ed7b"
    "ce60fb9fc7b4ffcea40c5dfd7090995c86d53274a09683ed49199ae8e3937267f2f94e486bef09a63d46ed7d1bd35e72a2690ae7e35e6615de73c8f5259eaaa9",
    "0aed324b5fe27d62122f8cc5d3ebdf4fed14952ed596440f2b5428d6930eefed84239e5d9f7775a3ec9105812d0b5d0fcdb11e96292b1d4766a9b247684a9eb1"
    "85465d682cb3ec64b41fa1a526772e7ad8e0a3af82ff0cdb87a7cab2e07531f519ed77af60f048447fd838a083857c616d772fdf2ec6b68f0f84c27ef4b21db9",
    "1938b3da4160aeedaadfa9cf6f13d32ea3fded2672ad89e60748dda7f7426af9e605af0f30f51bb5db4f31f824a21fb9417185510617224fb12b8c146933ac9c"
    "e295e1052d329585f1fe239378bb583cbdfe29facde8ef9db1bd3cef6806f3a006d33a928d7ee0d3fffdeb2bf00373c2b3cb0f643bad68b896ec6cece503bd4a",
    "9ce37d896336e91e3f60765eb085a99f44f4a6fdc0dd1a2b6b835ec2e67e374887acea77af62f048448ff0bfa4988c12e3f585f1fe35ec2753795f33d402f8fe"
    "8ff77e09e37ea7f3bd77b7beda91b7ee0b62bd211512543d92487562c0f7cbf31c133abec7cd378cdaeb05e49a40bea7e919895707aaf22842b8b8b88ed9fe91",
    "c2e2e9f54f391ea8315dbada1494eee1d1596a01f11de20f873f8071bdd3797ed37fd62bb4ea0c1bdd8b9eedb622f5bdb3fd38f0fcd2f23c0ecfa8bd70eb0be4"
    "44c348354699d4349c1aaf8f61f1f47a33bcae5a48ed09c0e7eec033cbe72f63f04844df69d1f166a722dd2f9efb0521271556fd47c7847bf8dc2971d74b3ebf",
    "5b634449ae31fadf718269a7a5fd6f786259bcfe750c1e89e81563941423946a82c80a42b3247468b1c60ae7a5ca689ddefc781e155c7b34d1f086cf88a7d57f"
    "3c034fd33f5b7c6fd28d9e6039fbc705c32fbeb90d719cebea0f8c8eefa5ed78371eebf7735b5d5f20edf346f3e1556fdc3dfee06bccfd46ed38c0d44f22faf9",
    "3dd7779ffc855283669bb4686f3fddb46c3e700bb9262ebea76a46a3dd51b9e0750586afd2dd142fcfdc6765b41da119edd0f4e6e6092b9c8dfde211ace33adf"
    "1f147a4d865b6bed1eae32e56a20759ccfa557dd14d7ff1873ff123fb78a785d13c79fe54f2a0d6abc320e71fce9a52610f7b1070fe2f8d6d4ff35e67e18e74f",
    "ffbdc6fa69cab271feac38bcf2c339aabb383f704de3fe5aff61957f3caa8dec8efb0f1fbd7a07e23c4ee77fb1e56d9e325220cc0573eb7cae5cf46f1f4811e0"
    "7fe07fbde8d77dede57f8607fe9fc5ff0c6f3bff7f0efcef7cfeaf5347eb59ff61a6b55e0ecbd1352a1ba003f94df7f03facfb4e2f35d1f5bfaf4f2ce3f5a78d",
    "df9bc57bdafd3c1f9bc40b61f1f47a07c5fb204e3f473c88d35b53bf03f9bc4f8b82d4e6f4bf03174f9fcb7bb8c30f42e332f4a16dfc5e6bb3eca884fd9ad3c6"
    "ed5293126b6dde33b292dde3f6c19f206eef7c9e97833e6e3776b8d938f60bfd8e9ce612e955d9453cff10733fbc577bb5df5deebfff35a63ea3f67a1b834722",
    "7a64ff0bd56cb2bd08c35362af30f67889365f911981b76addf8fb33daa5e96b13dc5283e2ab8a23b06affe6fb33f035bdd9f102d69093955d1bfdc39f7f2b42"
    "5cc7e9fe219f8fca67b953ef7af938b39d29ef511bd9b494708f7f1862ee87e75a2ffa7eb86e99bf780b8347227ad45f7404a61a1645aa97602959a67986af8f",
    "bfb7a8fdfd66e7930733f034bde97e34c57057f3fb9d60da6961ff197c5b06bfe074bfd0df4afaa3fbcd22972f67abe1622d99ee725917e5e331fb3cef61ea27"
    "11bdf979831a212ad55881924b1733087bdff33a86bc3c26f1dcff9e37e4e599271ee4e5b1a67eb3bc9fc7d44f227af3bccf0b7286ca64c594f268d7b5b091cd",
    "791b0e2d5b079895679991788a279cbb0e10c5e2e9f5a6f6ef8c6c647f9c07d67be7886757de8656b89de502bd62c0bb2bfadad155fa7e87cb10eee175787ef5"
    "a2ef6f3fb32c4f03e455c6e1e9f59057f969f15459163cc8ab6c4dfd309e9f5e6a821bcf0f30f519b5db8f307824a29f1ac759a9b182a05ac0a9f19c2c164faf",
    "37eb07de512de6195b4c710236f2ffef60ff8ff3f9bfdc08e68a3c2b570b02176ff3497f391ed972d1befd6b1897bd7efb7f0619cbe2f72f61f048448ff03e2d"
    "8a82a1758b79bd9f75cdc6fd92d23cbaea51d97ec2f928f58f6db68071ff97db4710c7773aef77f9fc793fdde4229bad5842da886eb53a82d745717cb3bc9fc1",
    "d44f22fa799db388eb0746fbdd7730edd7f6f5bf76f5c31339a4fe1353cbc1be65f3803730ed20113de20f445a61c0265d60faea019b9253f7f51466e0697ab3"
    "f380c70c66ff3ac0df7fff09f805a7fb85e0a6975dcfade77307c903e9e03058dfde6db9e97d00789ea7979ae8fbdf1b96cd0b5e43ae09e47b9a1ef1033c25d6",
    "19bed238732aff5bbcafd3c8bce0c266f6eeeb1cbcf88bdd7f00ffcf09cf2efeef75cf53f7a944adbee6ad64e342e134d15e3f7751be66b73ccfb6ce0f887743"
    "6af9e6a4bc67dbbe1f6d2500f6fd4cdf37307efb7712fb1f898dfcf4d7fd7b10ff773adf6fb4d6b37b2d36b6761669ece5370b722b16abb8e8fd2e787ef5821b",
    "df0f30f5c1be1f6378b0ef675e78aa2c0b1eecfbb1a67ee07dbdcc6bbfe775d9e7838ad1f8cec367c4d3ea877d3e56e3a9b22c78b0cfc79afa81eff582e3fb07"
    "98fa8cdae9e7183c12d14fcbefa34f5c91e2732c55a127dfd7dad734d9be45e7f9f96006bea6b7241fc85483da9ebfb9fcdd5358f775ba7f10a89dd332456d46",
    "abfe8d53a9e8a3d3c7cd9e8bd67d8798fbe1b9d68bbe1fbe6b599c7ff6b9eca35c9612edd4387f128ba7d79bcbf3a959c9ce7ccea1e7df83bc0d8ee7f7f3c394"
    "9460cf0e12be9a58603ba7d92dbe9f8f02bf2f37bfafb82e0ef4acfc0f71a0e9ed8738903d781007b2a67ed8df39bdd404772eafd93c9e77317824a247e34292",
    "448bf201c532d59129c2627df23da7ae03cf21efdff471c46386b33dee73337a0ef302a7fb039fefac7f3f9688a4ea3bddc2713f594ededf9561bfe7123ecf8a"
    "0c4210ef318807f11eabf05459163c88f758533ff0faf452133daf87619fe7e473d8e739bdd404f679da8307fb3cada97f88b9dfa81d4b98fa49443f0f3f7097",
    "9146faba48b1f6f6c3e1916def6f8d7e628d80f7b79e9cf755b111e46d76159e5dfcbed64db389b34ef534152c76b7aaa22fc01782f0fed6123cbf2381bccd30"
    "aed7b71bc6f58bc58371bd35f50f31f73b665c5f16da7c55b2795c9fb7cc1ffc04834722fac7fcc1247d7594552c432c2e9fe743937839e49a40bea7e9cdfb83",
    "ab06b335ceffd12b7720ceef743f90e0777291f061a6cf70ddec69b3ca65e54ccf4571fe21e67ef0037ad1fb817dcbe23bb3c6e18a0138aabb389e373b3f8c61"
    "f1f47a53f3c3b18d6cdf9ff3e855e077c7f3bbd8f2364f192910e682b9753e572efab70fa408f0fb52f33b71602bbf333cf0fb2c7e6778dbf9fd73e077e7f37b",
    "9d3a5acffa0f33adf572588eae51d9001dc8c37efc8bfa966a9f0e91045e378807bc6e159e2acb8207bc6e4dfdc0ebd34b4d70e76be1f0201ea30ac463acc253"
    "6559f0201e634dfd7fc3dc6fd48e14a67e12d1cfe1fdd9bb1d4a1ca7ca2f3545a18afcae134cbbade5f98a65ebafaf63f04844af18a7a418a554134456109a25",
    "a1438b3556382f554656595c5ecde133e269f51fcfc0d3f4cfe807d46ef504cbd9bf2f67f8c537b7c13f38dd3f48dbf16e3cd6efe7b6babe40dae78de6c3ab5e"
    "17bd4ffb1073bf53ce556c62da67b4dfddc4b45f3b3745cf8799d0b818a42d1bffcf1a8f4b2d511e954edd6f1fc1e2e9f566f2b08e6c643fbf87e0bc9439e2d9",
    "c5ef81cd78ade10da64eb3717f4acee579be138db968df253cbf7ad1f7b77b968def7f8cc12311fd63fb2b630247317c1c3d2f1de7d7ecca9b6c765c6057fe34"
    "9d01edcd9ff6d97fcb30be773affb369aeca9d8974ba193d94378476b576d4665c14ff81e7787afbf5fd2e68d9781ef2e4a802797266e1a9b22c789027c79afa",
    "81cfa7b75fdfefdebbe073b37930dfc2e091881ecd83d911986a5814a95e82a56499e6195ecd84b9a8f8fd353b2719bfbe3fc570f69e7b4e0cbe8571bde3fd40"
    "7f2be98fee378b5cbe9cad868bb564bacb6521aeb324719db74356f5b797307824a247f89f46e3392726dbf1b4fb76ae59fe0449691e5df5a86c3fe17c94fae9",
    "c95081b8fa3b4e30edb4308ef3e5f611f0bdd3f9becbe7cffbe92617d96cc512d24674abd511bc2e3aef0af85e2ff33af7e487183c12d14f3ff7445bad5ddc38"
    "dfecfcd0f07abe45e79e687dc6c67d399ffefb3fb06e7b5df9fe650c1e89e837da3b05ef813f1b1653fe385fdcda0df2bb4102f87ed9f8fe01a63ea37682f36f",
    "9f8cbf7ce7a8c1f9b7f3c483f36fada97f88b91f9e6bbdb87d9ea0e1db7d3e22cc13acc6536559f0609e60aefeff037542135d",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70568U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF2_info.c) */
