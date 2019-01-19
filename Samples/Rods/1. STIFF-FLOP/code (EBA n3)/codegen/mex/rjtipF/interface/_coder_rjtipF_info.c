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
                (737431.7863657407));
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
    "789ced5dcd6fe3c615e726d9208b222d81b449fa9566d362912281254bb264070820591fb66ceb5b2b7b9da4322551126d7e4824254bbed4c71e72c81fd0438e"
    "69d116db5eb2488242bdf55aa0e9a1a70045d04bafedb9a228da1eae26a2cd112d4aef01c6887ee2fc460f8fbf9979f36648dd49a6ee5014f5ede15fe9971415",
    "7e49bba2a817295de871f90c858a597f675cae98ae0db94b3d87dc77678cf7ebf175551255b6a7ea173c27b2e98e5061e5e185c808ec45353549e04446548bfd"
    "164bc9ac22f15db636d2d4399e2d7202bb275db9d8e6861742e28aeae24253699fa34db67a52e80894dc542e9bcb5fbda0c6f6d1e431e6f73f67d13e698c7d68",
    "93febdf8079ea624b09e2653e33ca9f85644e98b55cfb67615e9a85231558cf5454f54aab157af375995f1745757bc9eaaa6918f55ae9558112edbdfc3b4ef79"
    "8bed7f16d3fe7be3f255e4bfa1b05eae8dcb60d868c71106c7aa1def62da418f352de974e43da4f09e375d5fe2e99a9ad4a9f0ec25de2736f122583c54ff5e72",
    "ef60e82a1d45f6f05295e13da948712fb2e9c9fbbcabeb158f2a497c45ea795881f7f05cc523302acf543c524bf18c2ca4b9c648a6d9c9aa7f984b43ee512f8c"
    "3f9d7ff865f01f11e7f07459163cdcf36dd5ef5ec6e0d126fd7eb3c4060bb9c25abe98eb1cc4760f4b52e161f4b21dd92938d3da4161ae9daadfadcf6f0bd32e",
    "abfef68ce9da1083df69e4bf0fc27af9c605af9f63eab76ab79f60f069935eebdee4156e38689045865fe194cd0ec7ab4971386c6065ae7a6bbcffc4265e1e8b"
    "87eaafe137dadf5b237b79de320ce6311bcc702407fb814ffffbcf2fa11f98119e53fd40a6db8e46eadbddf5622ed0afc605d19738e4b717a71fb03bdedfc1d4",
    "4f9bf4b6fb81fb755e3506bd94c37e779e0a93f2bb573078b4496fe27f656832468e376e8df7e7d04f26f2be61a85be0fb3f3cf8058cfbddcef7de7c63b5abee"
    "6c4872a3a914124c633391ecc680ef97e739a610bec7cd37acdaeb45d33565fa9ea1e714511fa8aa5ae4eff6e23a76fd2389c543f5d71c0fd4b91e5b6b4943f7",
    "f02096ba85f80ef5fbfdefc3b8deed3cbfe53fe917da0d8e8f16a327f9f666a378f2300e3cbfb43c8fc3b36aaf174cd7d4c5f7740da7d4b9e1a4a6e9d6787d0c"
    "8b87eaedf0ba6e21dd1380cf1703cf2e9f7f0f83479bf4dd361b6f75abcac6c1a95f92b24a61d5ffe8905a1c3e774bdcf592cfefd7395951eb1cfa3b8e30ed24",
    "ea7f832362f1fad73078b4493f3446796884725d9279496a95a52e2bd779e9b45cd5d6dfed8fe7cd826b8f2106dee0867846fd8753f00cfdcde27b6337fa06cb"
    "393f2e187cf1f55d88e3cc6b7f60757cafecc67bf1d8d95976a7e70ba47cde682eb2ea8d2f4e7ff015e67eab763cc7d44f9bf4b37baeef7ff317ca4d966fb1b2",
    "b37eba456c3ef09ce99abaf89eaed146bb5a79cbeb0a9c58637b4951bd68c7c736db119ed20e436f6f9eb02238e8174f601dd7fdfd41a1dfe284b5767e7f95ab"
    "d402c9c35c36b5ba4871fd8f31f72ff1733b14efc2c4f1a7f527d526335a198738fee4d21088fb388307717c32f57f85b91fc6f9937faf353f4d121be74f8bc3",
    "0f7fb8c0f46eaf1f98d3b8bfe13ffcf08347b791d371ffc19357ee419cc7edfc2fb7bdad634e094484603624662b07fedd92b209fc0ffc8f0abaeeeb2cff7322"
    "f0ff34fee744c7f9ff73e07ff7f37f837914caf8f7d3ed5025a246d7984c800de4b61687ff61dd77726908e27f5f1d11e3f5ebc6efede25d379fe7639b78612c",
    "1eaa7751bc0fe2f433c483383d99fa5dc8e767ac2c291d01fd1db878fa4cf6e10ede0f8fcaf0078ef17bbdc3f35a09f99a93c6ed4a8b91eb1dd1a359c9e971fb"
    "f91f216eef7e9e57833e211fdbdf6a1efaa5b3ae9a1212a955758178fe31e67ed8577bd5ef2ef3ef7f85a9cfaabddec4e0d126bd29ff8569b5f8fe26273272bf",
    "30eaf1121db1aa7292486addf83b53da65e8eb63dc7293116bc38e8054fee67b53f00dbdddf102d690e3955d07fb873ffd4686b88edbfb875c2eaa9e648fbda1"
    "ca617a375d2932eb999492589cfe6180b91f9e6b54503f0c11eb2f7e8ac1a34d7a737fd195b85a4496997e826754951539b131fade6de5f7db9d4f96a6e0197a",
    "db7e34c17057cfed3bc2b493a0ff9cffaf02fd82dbfb85b39d6d7ff461eb40c85532b5c8417d3bd513320b741e8fdde7b988a99f36e9edcf1bf40851b9ce4b8c"
    "5abe984138bbcfeb10cee5b189b7f8fbbce15c9e59e2c1b93c64eab7cbfb394cfdb4496f9ff745494d33e98c9c1c3eda0d236ce4f0b90dfbc4d601a69db3cc29",
    "222352ee5d078862f150bdadfc1dcd46cec77960bd7786784e9ddbd08e743242a07f10f0e6655f27baca6e748534b538bc0ecf2f2aa8bffd8cd8390d70ae320e"
    "0fd5c3b9cad7c5d36559f0e05c6532f5c3787e7269086e3c7f8ea9cfaadd7e88c1a34dfa89719c953a2f49ba05dc1acfc960f150bddd7ee02ddd629e91c5869d",
    "8083fcff5bc8ff713fff579ac1ec81c8abb58224c43be2b6bf12dfdc59a0bcfd398ccbce5ffecf799a58fcfebb183cdaa437f13e2bcb92a5758b59edcf9ab371"
    "bf326c1e5bf3e86c3fe67c33f58f6c760be3fe3fef3e8238bedb79bf27e64ecf522d6173ab1d4b28ebd19d7657f22e501cdf2eefa731f5d326fdacde9f788469",
    "1f59bfdb702c8f5f69cba3976eba357ebf89c543f5378dff6959fc9a8d9ce7f3f05f1e3e8071bcdbf93cb015af37bdc1e47126ee4faad99c2876a3b1058ae3c0"
    "f38b0aea6f0f88c56d7e84c1a34dfaa7e2f731496038316e1ec7b76cb6c76edebe5be23888019d8de37cf61fc8c7743dfff329a1269cc86caa15dd57d7a54ead",
    "fea8c32dd0f93bf01c4f6e3fea77e4de7b3efd3d2adade538575eb787e1b8b87eaededcb35ace4e4f90be117de853c4bd7f3f9e97e5249f027a584af2e17f8ee"
    "7166473ccb4581cf978bcfdf857d5663817d5668bb2df80fecb39a211eecb322533fc4755041fded4d5897b58907ebb2b3c2d36559f0605d964cfdc0f7a8a0fe",
    "b6422c8eff030c1e6dd24fcebf34566b6f6f9c6f777e6879fd9e50fea5e133cef9cbe0d37ffd1bd66de795efadeebb5aefec15bc257f262227fd71f160271f14"
    "f3410af87ed9f8fe234c7d56edf4730c1e6dd24f3a770d3d5028296679a6ca8ebf3f2febb8039bf8ef4fc137f444ce699a6850c7cfd5af7ceb18e603f3da3f58",
    "9d0f48ccde718561b6a235fffab172e0635387adfe02cd070698fbe1b94605f5c3b7619dd7221eacf392c2d36559f0609d974cfd03ccfdc0efa82c7a1ce8a6fc"
    "0f71a0c9ed873890337810072253bf63cfb1abf763bd438cf75fc7e0d126bd89f7655669322db6c09db151edad908a5bf37c0a53f00cbd5dde7fca60ce9fbff6",
    "b7df7d02f38079e57fabf380e096970f6543b96c69bba494f6838ddd7c7b91dec302cff3e4d210d4ff5e2796f7f32a068f36e94dfd80c8c80d4eac364fdccaff"
    "84f33cade4fd5cd8ccd971c3f94befe4ff0efc3f233ca7f8bfdf3b4d6e30897a63cd5bcdc4a5c271a2133a8d03ffcfdbf38cf307abfef72ce67718ef5b7c15f9",
    "efdb61bd7c635c5eeef33dc2e0903a6fd93881cdad71ff599fd73a7aebe2f8cc354d1ce42738af6186784ef1fd7a3b9429b6f9d8dac966b398db2aa8ed58acba"
    "40efd582e71715dcf8fe1c531f9cb76c0d0fce5b9e159e2ecb8207e72d93a91f781f95599db33f2fe72b9bc56a7ce7f10df18cfae17c65d278ba2c0b1e9caf4c",
    "a67ee07b54707cff11a63ec8efd76560137ff9f2c420bf7f967890df4fa6fe01e67e78ae519955fee7bccc136e1a1f8279c2e4f6c33cc1193c982790a91ff27f"
    "269786a0fee7bde07fbbe7beddc7e0d126bd79dea028acac96189eab69a688c88df1f7dcba4e50c4e2a17adbe388a70ce7f8bce099e829cc0bdcde1ff87c2767",
    "1bb1c466b2b1d72b1c9e6d57b637f22ae4032de1f33c94f330ecf7b58807fb7d49e1e9b22c78b0df974cfdc0eb934b43505e8f401ed0f8ff900734b93404f280"
    "9cc1833c2032f50f30f75bb56319533f6dd2cfa21fb8cf299abe2133bcb37e3878e4587ebff613eb14e4f7e3f206861f3c231b39bf9ff709f0bbfbf97dad97e2",
    "1327ddda713278d0dba9c9be805808427eff123cbf9a90cbf384713d0e0fd5c3b8feba78ba2c0b1e8cebc9d43fc0dcef9a717d45ea8835c5e1717d8e587ff063"
    "0c1e6dd23fd51f24b5190d2b47f9a1652872e3feebbecfe5b14dbcace99a327dcfd0dbef0fae1accd138ff872fdf8338bfdbfb8184b897dd8ceca7cf38a19739",
    "6ed5848c9aee2f509c7f80b91ffa0154d07ee021b1f8ceb471f8d00002d3bb3d9eb73b3f8c61f150bdadf9e1c8468ee7e73c7905f8ddf5fc2eb7bdad634e0944"
    "84603624662b07fedd92b240ef5b1f60ee077e4705f5c392a3fcce89c0efd3f89d131de7f7cf81dfddcfef0de65128e3df4fb74395881a5d6332013690837cfc",
    "8bfa962a4f87da065eb78807bc4e0a4f9765c1035e27533ff0fae4d21034ff320df1188b78108f2185a7cbb2e0413c864cfd7fc5dc6fd58e0ca67edaa49fc1fe"
    "d9fb5d461e1da55c6ec952cdf4bb8e30ed26cbf35562ebafaf61f068937e689cf2d028e5ba24f392d42a4b5d56aef3d269b9aa59e5f6ce5d1bdc10cfa8ff700a",
    "9ea1bf613fa0bbd53758cef9bc9cc1175fdf85fec1edfd83b21befc5636767d99d9e2f90f279a3b9c8aa7701f6d3fe1f0fac0a02",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70488U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
