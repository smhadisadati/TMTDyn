/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sprdmpF4_info.c
 *
 * Code generation for function '_coder_sprdmpF4_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF4.h"
#include "_coder_sprdmpF4_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("sprdmpF4"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (8.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF4.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.94943287037));
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
  const char * data[23] = {
    "789ced5dcd6f234915ef59665633420b7d00560b0834b01a2d1a9476628f93110cf83b76268eedd89338995d92b6ddb63be92f77b71d3b1772e4c0614f9c38ec"
    "9145022d1cd81120146efc038b10a79110e2c215ceb4dddd49aa708d9de9763bdd7e4fca542aafbb7ed56f5efdaaea557535752b97bf4551d4178c9fdffdd8f8",
    "e76fd448de32138ab6d237285470fd2d2b7d17cbdb7287ba8ddc77cbc2fbb995afcb92cef5753323f012b7d5156b9c6a642456e42e8a69c8222fb1925e19281c"
    "a5729a2cf4b8c648d3e405aec28bdca67c2593e58d8c98b9a2bac80c55c3df936dae7e5cee8a94dad62eab2b5ccd50967d86f209e1f96f4f699f22c13e34a67f",
    "9efe8069cb22c7b4d906cfe4d3eb716d20d599ec3017efea72255f490d24262937b8abf904a7b34c6f7929c4d4871a4d511ba292892c8976fdff42a8df9b53d6"
    "ff2d2c6fcb3d2b6d5ffde3592e66a6eb664aa5ad7ccaca5be959c6ca7fdf4abf67a5f67d4facf487561ab3ee4bc4ece73a24d47bdaff973b589ebab8ced428f2",
    "c9c81bddc27b13cb5fe2999a86dcad09dc25de2f1ce2c58978a8fe796eb36ab85e57531941aeb302938f5736e309667b25b4bc56637459166a729fe1448111f8"
    "1a23b2bac0d61859d19891859644ab9c49769ad6dff0d4967bd45debb7b39f7e16fd6bdc3b3c531605af4f286f5abffb0a018fc6f4bbed1d2e5a2e951f6d574a",
    "dd6aeae9fe8e5c7e96bcac87cd8b249c49f5a00879afcaf76bfb5508f59ad6dfdec0f2b6d8fd058dfcf541cc4cbf75c1eb6784f2a7b5db3709f834a61f7697ea"
    "126f0c4254891596782dd1e5053d2719c3104ee5eb73e3fd170ef1b68978a8fe1a7e33fc7938b217f3d03618831bcc76240ffb814ffff3f7cfa01f98119e57fd",
    "40a1d749c69bd9de5aa51419d4d3a2b492d917b2c1e9079cce1f3608e5d398de713f70bf29e8f6a097f2d8efcef231b7fcee6d021e8de931fed70c93b16aba35"
    "37debf817e3296f76d43cd81ef7ffde04730eef73bdf87b65bcb3d7de3b1acb6da5a39c3b612995c2f057cbf38ed9842f89e34df98d65ea4f8148de9794d3207",
    "aafa309238bfb88e53ffc811f150fd35c7034dbecf3514d9700f06b1d41ce23bd4af76df8171bddf797e3d7c3c28775abc90ac248fb73b8956e5f8591a787e61"
    "799e8437adbdee6279eae23a53c36b4dde98d4b4fd1aaf4f11f150bd135e372d647a02f07930f09cf2f997097834a6ef75b8b4d2ab6b8fab2761592e6ae5e5f0",
    "de3e151c3ef74bdcf592cfef377955d39b3cfa1c87847abaea7fe787aec5ebbf41c0a331bd618c03c308074d5915645939907b9cda14e49383fa703ddff9781e"
    "17527d6cb1f1ce5f13cf2e7f7f029ead7fbdf89ee546afb09cf7e382f33ffef30ec4716e6a7f30edf85e7b9aeea753a7a7c58dfe4a24bf124a96e2cba17470fa",
    "839784fba7b5e319a17c1ad3cfae5ddf7ff505076d4e5038d55b3f5d776d3e701bcb5317d7999ae1687798ce795d81971a5c3f27e917f5f8c8613d6213ea61eb"
    "9dcd132ef78f1d12eae3a25fbc80755cfff707e581c28b8f3adbbbcb7cad11c9ed978af9e520c5f53f22dcbfc0edd6905060e2f893fa937a9b1dad8c431c7f7c",
    "6a0bc47dbcc18338be3be5bf24dc0fe3fcf1cf3b9d9fe65c1be74f8ac31b0f2eb2fdf9f5033734ee6ffb8f60fcc29836f23aee7ffee2ed7b10e7f13bffab9d90"
    "72c46b91b8182dae4ac55a35fc74474b00ff03ffa382aefb7acbffbc04fc3f89ff79c973feff03f0bffff9bfc5eead16c2bb5b9dd55a5c4f3e620b112e525a0f",
    "0effc3baeff8d416c4ff5e1ebac6ebd78ddf3bc5bbee7e9e8f1ce2c58878a8de47f13e88d3cf100fe2f4ee94ef433e3fe55459eb8ae87390e2e933790ff7fcfd"
    "d8288d7de019bf37bb82304c61bfe6b871bba6b06ab32b31432b793d6e3ffb0dc4edfdcff37a7445dc4eedaeb7f7c3f2694fcf8b99fcb21e209eff84703fbc57",
    "7bd5ef2ef7dfff8450deb4f67a8f8047637a6cff0bab28c220c14bac3a288f7abc4c57aaebbc2cb9b56efcc509f5b2f54d0bf7a0cd4a0da323706bffe6f309f8"
    "b6dee9788168486b65d7c3fee1b71fab10d7f17bff502a25f5e3e25168b5b6bff574ab5661d70a792d139cfee19c703fb46b54503f5c75adbff836018fc6f478",
    "7fd193f9465c55d9414660759d9378a935ba6e5efbfb9dce277726e0d97ac77e34c6704317f2d07fcefe5b837ec1effdc2e946369c7ca654c552add088579bd9"
    "7c5f2c04e83c1ea7edb942289fc6f4cee70d6684e8a029c8ac7e703183f0f63daf7d3897c7215ef0dff3867379668907e7f2b853be53de2f11caa731bd73de97",
    "647d8bdd2aa839a369b7ecb091c7e736ecbab60e30e99c655e935889f2ef3a40928887ea1deddf19dac8fb380facf7ce10cfab731b3af16e418c0caa91d0b6ba"
    "d24d2e738f7be216151c5e87f68b0aea6fefba764e039cab4cc243f570aef275f14c59143c3857d99df2613c3f3eb585349e3f239437adddbe46c0a331fdd838",
    "ce52539065d3027e8de7148878a8de693ff0d0b41833b298d10978c8ffbf84fd3ffee7ff5a3b5aac4a82de28cb62ba2b65c3b574622340fbf66f605cf6e6edff"
    "39db722d7eff25021e8de931dee754559e6add6256ef67ddb071bf66548f6b3026db5b9c8f53ffc8667318f7ffe9e91ec4f1fdcefb7da974729a57c4c47a2795",
    "d1d6921b9d9e1c0a501cdf29ef17b13c855d67eb67f53dc64342fddcf5bb1fb816bfff1c018fb63475d9fc70a65fe3f771221eaa7fddf8df7017bf61a3799cbf"
    "f3e7670f601cef773e572afda3d5825e8cae16d84af9a8a2ae0fea5280ce5f80f68bcaace2f7ef10f0684c3f3e6e63b3fcfcf6613aedf7f313f06cbd5b711bdb",
    "67bcf39758f4671f03dffb9defd7d44d8d2dd5f37bbbb5bd6a2d9188469a2d0ef87ee1f8fe434279d3dae93b043c1ad38f7b5f0b7d1121271505b6ce59d707e5"
    "bdadf727e0db7a57deef186b50cfcfe3a97dfe08e23b7eef1f6476f3a8c6b2ebc94678ed48abae70f97d6510a0f8ce39e17e68d7a8a07ef85dd7e23d93bfb335",
    "3c9b40e3fc1aefc912f150bdb3731b6c2b7919f78bdd7d02fbf07dcfef27bb392d231cef64569a6a59e81d1536a4d35212f87db1f97d297071a0d7e57f88038d"
    "af3fc481bcc18338903be53b6dc7452c4f61d7d97a7fafe3263c5bc7d586872853b08efbaab8a0661fa24c79cae7b08e3b433caff89c65b389fd93e32cbf934f",
    "768544424aad16b70214b781f68bcacd5cc7b5591ed671a71dbfdb3ee3619c3e06e377fff37de85136ba963cd95d09254e4e8490224452add3008ddf81ef5181"
    "75dcf1f583755c53601dd71f78b08eeb4ef9e784fba15da37233e3fceecd135e371e04f384f1f58779823778304f70a77c88f38faf3fea7749d7e2fc93de8fd5",
    "3aaa3e4cfd1ae74f10f150bda379a36123efdfbf8538ff2cf1bce2f3c87abad90e457347857438a7174b92d44ba60274ee0eb45f54507f7be0daf8fdeb043c1a"
    "d3ffdf796b29596479298d9fbb30ef388fd3718057e7ee2006f4f6dc9ddfff1bcecff73dff0b79b1211eab5c5e49eeea6b72b7d1dcebf2309e5fa0763c9428ec",
    "c79f120ff6e3bb8567caa2e0c17e7c77ca073e1f5f7fd4ef9e5cf0397c17cb14f82ed6f8d416f82e963778f05d2c77ca87b80e2aa8bfbd1773cbdfe01c4d1c0f"
    "d5c3399ad7c5336551f0e01c4d77ca07be476556fb70be4ac0a3313d611f8eb55aebdffdfa5b13f06cbd6bfb702c9ff1701fcea7fff817acdbde54be9ff63b59",
    "6bddcd7268275c88abb9705aaa6e6c47a5ed28057cbf687cff21a13cd8af6fcab943fcc5dbd70bfbf5678907fbf5dd29ff9c703fb46b54823e4fb0f1bddeaf0f"
    "f304b7f14c59143c9827382bff7fd7f989c0", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 55320U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_sprdmpF4_info.c) */
