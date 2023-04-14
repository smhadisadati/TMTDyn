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
  const char * data[17] = {
    "789ced5ddd6fdb541477c7366d42034b48db1002568426a14d759aa61f43426a3e9b6c4d933459da7540e6d84ee2e4da4e6c274dfa421f11e2813f80873d4e08"
    "a43dc12478086fbc22010f3ced853f8177ec384ee3bbdcc5ab5d1737f748d5ededf13dbfe3d3e3dfbdbe3e7188b9547a8e208837b49f1fbf2088b5af88815c31",
    "1a821cb6e708abc0fab9617b0dea9b7281386f193737c4fb76d8672451e5baaad101bcc86db58532276b1d9116b891195612789116d542afc91132a748a0c3b1"
    "034d85075c8117b84d69ac93e4b58e9018538d3aba4aff3d5ae39846be2d10724d3972178c7788617c74798a38fff336e39341c48784f40fe39f513549e0a81a",
    "cdf2543abe11567a224325f55eb8ad4a857421d613a9a8c472e3fd08a7d2546771214031ba064834ab2416178491ff8f10fe5db4e93fdc9a7299b834d60bad9b"
    "7887087b76e375038147427afd74e5055e4b2259a4c182961a35bac9e5f903e31fac4c3bff69fec082f2c71413efd931f14cfbf92978a6fe616a73574b99b622",
    "6bff748606543a5cd80c47a8ed606071ad4ca99204ca5297e20430f8b935881775cb0c18f542c0b49c193f8f47083fddcb9bc3dfbf7ff257d8db3cf5f2fc4e17"
    "af8bb067370faf22f04848bfb21100abd9d55cb6982c2ac59d95eabded961a3bf2233b05679a1f04a2ef957d7c3d4f6e4db1e6df8d75b7f2ef3a028f84f4d03c",
    "20d2729517995ac3affc5f9c8267ea6de68b961432c75246b60c73064e9d51ccf494f190ffdffa78fb0fccff2784e715fff7bafba93b74a2525d0e3099b894af"
    "27daabfb71ccffffb7eb19950f76f3ef35c4795c1eb6d72d7fbdbd6eb41f0cdb9beb4ef9d8c4bd80f0831c6a2a4092f4bb48b7f02e42fd233c43c34aed32e08e",
    "f09e38c48b22f1acfa57582f00be4c09b40ae832c5814a5ba40631f27e7df0ebfd9b7f62be3f213caff87eadb59a29b4406cb911a915721b79b5158b3189b3c3"
    "f7f8fab50a6a7d7f88b067374eef23f048480fadef7925d2e6819a12b7da0227f3cca9f1bcd375c13612cfaa777a5f08076c98365eaef37ffaf76fccfb7ee7fd",
    "4ca7150d57929db5422ed463e282184cec8124e6fdd9e0fd0f5de3fd77107824a487785fd14245cb0be6eadef9fa1e16bbfb3b4f8f8967dab7fd3cc821efdf32"
    "2236ca190ff9febb9db731dffb9defcbb595ecae0854362f09f1b6985c2ac723773730dfcf1adf7f83b067374e1f21f048480ff13ddd6c825e7e406189b6c8a8",
    "bc24a6c42ca019b334c0f4afe9d0bf37a7f867ea2b432f4a355a64b51b0113bfef10ffd329f8a6dee97c800ea89160dee557bffc7a1d3ff7f5fbfc20d19bf532"
    "4d6f44d9a5b5bab21be4d27bcdde197aeedb478cc7d7b555ac7978dbb57dfe4b509f181d6768784569d2b2c2f9759f3f89c4b3ea8fb77ed063a3af20cc282d08",
    "dee5c1faa54f3ec7fcee777edfdf492909d028268215390f3af5cc5df12017c5fc3edbfcbe70e6f6818ecbff781f68b2ff781fc81b3cbc0fe48e7d5cdf39b935"
    "c59a7f8111ff7f89b067376ef3083c12d2c3fb428ac2c96a91063cab87222c5787c7f9f53970018967d53b5e47bc1038cff77dce45f7f17d81dfe78360b07170",
    "279688a4aa9bddfcde41b29cbcb3ade27acf19bc9e35395cc7fb3d36f1f07e8f5b7886cc0a1edeef71c73ee6f5c9ad29565e0fe33acfe1df719de7e4d6145ce7"
    "e90d1eaef374c77e1f31de6e1c4b08fb24a43f8979609e57747d55a681b779d87fe0d9e7b7f453ac10f8f35ba8ba30ed176a1023efdfd7f00cf3bbfff97db99b",
    "06894687ada75676bb7759391812f32bf8f35b3370fdeae25e1d3f5ed7a3f0ac7abcae7f553c4366050fafebddb1df478cf7cdbabe2cb54556f1785d9f736d3e"
    "7817814742fa17e683947e47c3c951a04586706fdd7f1eea1ff96368981a3d282072ab9e270bf509e83853ef7c3e180f98a7fbfc5f5fbd8cf7f9fd3e0f24c4cd",
    "6c24bcb375c00bdd4cbdc90a1975ab7786f6f9fb88f1781eb08a751eb8efdafeceb475b8160081ee9e1ecf3bbd3f8c21f1ac7a47f7878318795e9ff3ec1ae677"
    "dff3bbdc0a34ebbc120a0b2bd955315bde5dba57542298df679adf89a2a7fcce8b98dfa7f13b2f7aceef3f637ef73fbf57e907ab99a59dadd66a39ac4697e94c",
    "880be5703dfec8de4cd5e91049cceb36f130afbb8567c8ace0615e77c73ee6f5c9ad29d6facb2dbc1f63130fefc7b88567c8ace0e1fd1877ecff86186f378e34"
    "c23e09e94fe0f3b3f31d5a1ebc2abfd49425163aaf4708bfdde579c6b5e7afef21f04848af05a7a405a55491642049cd92d4e1e40a90f64b8c1e95d37baf66ff",
    "9878a6fdbd2978a6fe98f38091562f899cf77539fd5ffeb980e707bfcf0fcabd78371e3b38c8deed0643e960209a0b2f06ced0e7699f23c6db8de321c23e09e9"
    "4feeba9e7ff901a51a079a9cec6d9e6eb8767f306dbdce2b15fd3b355dbb2e50df174a427ab84e4864b96e4a54477e3c76e8c7fa143f4cfd2be65585ef726c53",
    "d2fca6f4c879599f43e0fafc13c4f36a3ec8f79abcb0dcdade59e4cb6c28b597cba6173b67e8bd9a8f11e367f8ba25c6dfabd344d8b31b9f2b509f808e33f5bc"
    "221a05e5aafecdcafeadbb4c21f1ac7a27f93016297399ef250ffd80dfa3e67f5edf586af4f2ad2a0fa2856863bb15a9161af7e36788d79f23c6e375fee4f3b5",
    "97a729fc1cc0261e7e0ee0169e21b382879f03b863ff39623ce6ffc9e76beff980b7fc8feb7b707d8f29b38287eb7b9cd9ff0f2fc83aeb",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 35408U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_loadsF1_info.c) */
