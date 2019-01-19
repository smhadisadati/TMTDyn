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
                (737430.95061342593));
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
  const char * data[25] = {
    "789ced5ddd6fe35815f72c33ab19a1054bc0ce22c4b25dd00834ab3a49d3a645426a3e9bb4cd5793693b9d5d324ee2246efd91d84e9ae4853cf2b00ffc013ccc"
    "e382000d3cc048bb42e18d572496079e4642fb27c0334e1cb7f59ddc89a7769cda39471addde39f6fd5d1f5dffcef1f1f10d712b95be4510c437d47f7ffe0541",
    "74ff438ce51dad21c849fb166114547f6bd23e40fabadc216e1bcebb35c1fbf5a45f110585e92a5a87630526d3e6cb8ca476049a672e86a98a3c2bd08252ec35"
    "1942626491eb30d5b1a6c6724c91e5997df14a27c9aa1d3e714575d119a9467f471b4ce5acd0e609a9215f4e97bbda2126f619c973ccf5df36699f0cc63e24a2",
    "7f12ff846a883c4335e82a4ba5e33b61b92754a8e4a8176e2b62315d8cf5042a2a5699abfd08a3d054c7bfeaa32a238d74aab0cdc42a7f39ffa798f9bd6d72fe"
    "68abcb3de2ee959e7f7b169e597bddc1e091134d533c1faf12bbf0de46fa97789aa62ab6cb1c7389f79945bc3016cfa87f92da3f5697445b96284eacd01c950e",
    "17f7c311ea20e0f36f96294514b9b2d8a5189ea338b64cf1b4c2d1654a6ccad4d842a3253016e7d6c1e0d32f37fe157676dd39bdce1787d7c58c6776ddbd8bc1"
    "2311fd51e390d928e40beb07c57cfb38b6777228161e452fe7919b81336b1e04a6efd4f86ebd7f9b9879995d6f6f217d5dee21c76bf2605b6b3fbce0f501667c",
    "b376fb01069f44f4233726adb26a70200934b7caca9136cb2929410d0f1889ad2c8cf75f58c43bc0e219f56fb06e46ff1e8eed453dd40d46a106d31792837ee0"
    "2ffffdf797e007e684e7941fc8765ad1702dd9d92ce683bd4a9c170289132ee91d3f6035aedfc58c4f227acb7e60a5c6297ad04b38bcee06e96dbbd6dd7d0c1e",
    "89e811fe975593d152bcbe30debf81eb642aefeb865a00dfffe1c1cf21ee773bdffb0eeafe8eb2bb254af5865c48d0f54822d58901df2fcf7d4c18f81ef7bc61"
    "d65eef207d02394ed7b3b2a005aaca28c3b7b8bc8ed5f591c2e219f56f180fd4d82e536d8aeaf2a00c965a407e87f8fdd17721ae773bcfefac9df50aad3acb45",
    "8bd1b38356a45e3c7b14079e5f5a9ec7e199b5d75da44f5c1ca76958b9c6aa0f350db7e6eb63583ca3de0aaf6b16d25602f0b937f0acf2f977307824a2efb498"
    "78b35391b78ecfd744312717fc6b8f4f08eff0b95bf2ae977cbe52632559a9b1c6eb788a99a7adeb6ff8d4b67cfdfb183c12d1abc628a94628d5448913c56649",
    "ec30528d13cf4b95d17b76ebf13c2ab8f9e8a2e30daf89a78f7f32034fd75f2fbf375946afb19cf371c1f08bafee401ee7a6fa03b3f1bdbc17efc663fd7e6eb7"
    "1b08a603be683eecf7c5bde30f5e62ce376bc701667c12d1cfefbe5e79fd01a506c33519c9d975ba63dbf3c06da44f5c1ca76946d1eea85df07b0556a832dd94",
    "a05ccce399c5796ccf9887aeb7f69cb0ca3bb82e5ec07b5cf7fb8342afc9f2ebad83233f5bae065327f95cdaefa5bcfe33ccf94b7cdfaae2f34c1e7f963fa934"
    "e8f19b71c8e34f6f7581bc8f337890c7b767fc9798f321ce9f7ebde6d669cab6387f561e5ebd709eee2ece0fdcd0bcbfbe7e38f50f4ab391d379ffe18bfbf720",
    "cfe376fe975abee6292b07c3fc462e24e4cac76b7b877204f81ff8df28c6f7becef23f2b00ffcfe27f56709cff3f07fe773fffd7e9c7a1ecda51a6152a8795e8"
    "3a9d0d32c1fc8e77f81fdefb4e6f7531acbf974f6de3f537cddf5bc57bd37a9e6716f1b6b17846bd8bf27d90a79f231ee4e9ed19df857cde6724516ef3c6ebc0",
    "e5d3e7f21deef0e3ed71bbfd8963fc5e6b73dca8857acd6971bbdca4a55a5ba04656723a6e1ffc11f2f6eee7796523c01fc48e761a276b62bfa3a4f944daaf78"
    "88e79f63ce87ef6aafaebbcbfafb5f62c6336baf1f63f048448fd4bfd0cd26d78bb0022df50a638f97680b15851505bbde1b7f73c6bc747d6d825b6ad0425575",
    "0476d56f3e9981afebadc60b58434edeec3ae81ffef41b09f23a6ef70ff97c5439cb9dfa42e593cc5ea65ca437b36939e11dff30c49c0ff7b5518ceb30649bbf"
    "f821068f44f4a8bfe8886c352c49742fc1d18ac208ac501f1fb7a8fa7eabcf938733f074bde57534c5700eefcf37f85f19fc82dbfd427f37b9167dd43ce6f3e5",
    "6c357c5c4ba6bb7cd643fbf158bd9f8b98f149446ffdb941cb10956a9c482ba58b270867bff33a817d792ce279ff3b6fd897679e78b02f8f3de35be5fd3c667c"
    "12d15be77d41543274262ba5d45bbbaea78d1cdeb7e1c8b6f700b3f6596665811608f7be078862f18c7a4bf53b231b399fe781f7bd73c4736adf8656b89de583",
    "bde3a0ef400ab4a37e66abc36708eff03adcbf4631aeb71fd9b64f03ecab8cc333ea615fe537c5d36459f0605f657bc687787e7aab0b2e9e1f60c6336bb7ef61"
    "f048443f358fb35ae34451b3805bf339592c9e516fd50f3cd42c468d2da63a0107f9ffb750ffe37efe2f373672c702a7540b221f6f0bc9b5723cb2eba1bafd1b",
    "9897bd79f53f838c6df9fb6f63f048448ff03e2349a2a9f716f3fa3eeb86c5fdb23a3da64a696c3fe17c94fac7365b40dcffd7bdc790c7773bef7785fc793fdd"
    "e4233bad5842de8ceeb63aa2cf43797cabbc9fc18c4f227aaffc4ee200339e597b7d80c123113dc2fb12a3325d9329b07ded873065b7d6ef1466e0e97aabf1fe",
    "2b06733edfff8fdf7d06fcef76fedfd8f171a15c289f3b4c1eca87471bf5bd839697eafee17e9edeea625c7f1fd816ffbf87c123113de207045aaab342a571e6"
    "56feb7b97ed34cfc7f613367e386c1b77e7af04fe0ff39e139c5ffbdee796a8b4ed4eaebbe4a362e164e13edd0b987f665f6cafd8c5b0f66d7dfd730d7a17fdf",
    "fb9ee17f3fdad6da0f27ed03c7ea7bf48c3fd4f74caf0f187fe53bc9f18fc4417efadba30790e7773bdf6fb642d9628b8bad9f451ac5fc4e4169c562150f7dc7"
    "05f7af5170f1fd00331ed4f798c383fa9e79e169b22c7850df63cff8c0fb4699575de74da9e741c56c7ee7f935f1f4f1a19ec76e3c4d96050fea79ec191ff8de",
    "2838beff15663cb376fa09068f44f4d3f6f1316e509112721c5d6126c7ebf36b5a9cdfa2f7f3f97806beaeb765df8fa906757c9fe6f2d74fe1bdafdbfd8348ef"
    "9f96697a275a5ddb3c958f034cfaa4d9f3d07bdf21e67cb8af8d625c871fd996e79ffdfbeba33d2b65c6ad79fe2416cfa8b7b69fa76e2527f76ddebefb33d89f",
    "c1f5fc7e7e949213dcd9612250930a5ce734bb2bf4f351e0f7e5e6f755cfe581aecbff90079a3e7fc80339830779207bc687facee9ad2eb8dfdfb5ba5fe70a06"
    "8f44f4685e4896194939a439b63a324558aa4f8e73eb7be039ecef373d8e78c5708ee77dde8a9ec37381dbfd412070d6df8a2522a9fa7eb770d24f96935b070a",
    "d47b2ee1fdacca601bf23d26f120df63179e26cb8207f91e7bc6075e9fdeea62e4f530d4794efe1fea3ca7b7ba409da7337850e769cff843ccf966ed58c28c4f"
    "22fa79f88115561ee9eb12cd39bb0e878f1dfb7e6b74893502bedf7afdfeaeaa8d607f664fe139c5efebdd349738eb544f531bc7ddddaa14080a850df87e6b09",
    "eedf91c0fecc10d71be70d71fd62f120aeb767fc21e67cd7c4f565b12d546587e3fabc6dfee0fb183c12d1bfe20f26db544739d532c4e2f6ed7c6e112f87f409"
    "e4385d6fdd1f5c3598a379fe4fdfbd07797eb7fb8184b09f8b848f327d96ef664f9b553eab647a1ecaf30f31e7831f308ad10f3cb22dbf332b0e570dc0d3ddc5",
    "f1bcd5e7c31816cfa8b7f47c38b691e3f5392fee03bfbb9edfa596af79cacac130bf910b09b9f2f1dadea11c017e5f6a7e270e1de57756007e9fc5eface038bf"
    "7f0efcee7e7eafd38f43d9b5a34c2b540e2bd1753a1b648279a8c7bf186fa9ea748824f0ba493ce075bbf03459163ce0757bc6075e9fdeea82fb1d2d1c1ee463",
    "34817c8c5d789a2c0b1ee463ec19ffef98f3cdda91c68c4f22fa397c3fbbd2a1a5f156f9a5a6245691eb7a8a99b7bd3c5fb1edfdebfb183c12d1abc629a94629"
    "d5448913c56649ec30528d13cf4b95915516b7afe6f09a78faf82733f074fd35fd80b6ac5e6339e7eb72865f7c7507fc83dbfd83bc17efc663fd7e6eb71b08a6",
    "03be683eecf779e07bdaff0374ac4fa1", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 58256U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
