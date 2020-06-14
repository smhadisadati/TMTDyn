/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_massF1_info.c
 *
 * Code generation for function '_coder_massF1_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "massF1.h"
#include "_coder_massF1_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("massF1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v2.0 HLL/Fabric/eom/massF1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737612.15587962966));
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
  const char * data[20] = {
    "789ced5dcd6fdbc815677693458262b7020aec078a769da258b4cdc294655b721658c0fab49448966cc91f71da7af92589123f249292255fea630f3df4d4530f"
    "7bdc165da0b7066d0feaadd7026d0f3de5d23fa1f792a2c63619cd8a31a97128bd0718a3d123df6ff8fce637338f2392ba5328dda128ea3df3efeb5f50d4ca9f",
    "a9b1bc6b17546452be4539c5adbf33293f76d591dca3ee3acebb33c1fbeda4cea98a210c0cbb22898ab0db935941332b0a230b97667855161546316ac38e4069"
    "82ae4a7d811f6beaa224d4445928aad72a79d1acc8b96baacb8aa5b23ea79b02d7aef6644a6bea57cd95ae57a8897f2c7981b9febb1efd7380f14fc4a57f9efd",
    "19dd5465816e32bc485799ba4097b23b497da87074defaaa56aa65860a9d5679017d4e090643f763abd1957cb148e7185613395a50655a66743db7b62a5fbb8e"
    "2f30ed7cc7e375b84b240fa8fbd76a3fdc467817187b5efdb682c18bb8f49ce90f6d55348349531869d50c9126d311aae2b9fd8fd6675dffacf6b805d71e2441",
    "c54d75061ed23f2f148fcdd0e9e91a2da91c23d1a564ad984cd1fbb1e8da164b1baa2ab1ea80166469fcf768ec2ffa117218fd8ac3c65143326e2efef187affe"
    "9d241ba7a4fbc5ede10d30f6bcc6e1fb18bc884b1fdf894a894a62af72983fd40f8fe28da7fb5d2373d58eca0c9c59eda0307552f6a13f4f2f9138e36f653ba8",
    "f8fb10831771e95de380c2680d51e19aedb0f2ffe10c3ca4f7182f665068024fdbd132891977e85cfacc0a1982fcff9dcff6ff09fc3f273c52fc3f1c9c151e33"
    "b97a6333ca95b36ab595eb25ceb2c0ff6f5a7fc6c583d7f87b1b731d0f26e5878e6f3fddb6cb1f4cca4fb6fdf231c2bd87694764a2a94baa6aad2683c27bc755",
    "bfc2b335bcda6325e10aef2b9f78692c9e53ff1af3054964cd95a121312c2d48f59e428f7d447e7ef0b7834ffe057c3f273c527cbfd54d946b5d29b3d94e356b"
    "7b3b55a39bc970b9c5e17be8bf4ec1cdef2f30f6bcfa09973f8cb8f4aef9bda8a77aa2641494dd9e2c6822776b3cef775eb08fc573eafdae0bdd0e9b840dc979",
    "fe9ffef71fe0fdb0f37eb9df4d27ebf9fe566d6f63c8656525963b91f2c0fbcbc1fbc1e5f7bf8bc18bb8f42eded74d5731da2a9addfb9fdfbbc56b7ee78f37c4"
    "43f6cb33f090de2fef3fb23d76193304f9fef7471f01df879defd966bc72ac48065f55e56c4fc9afb3d9d4931de0fb65e3fb5f63ec79f5d38f31781197dec5f7",
    "4ca7230dab630acbf514ce1055a5a0542486435b0450fb3a3edbf7ed19ed43fafaa415a74d46e1cd8500c21ff9c4ffe90c7ca4f73b1ee01d6a0718b9f81ab1df"
    "6ac17ddfb08f0f2a536cb10cb393e6d7b75afa714c289d74860b74df7784391ffab5539c71f8696079fefbae3a75799cad1175bdc368ba10d63c7f1e8be7d4df",
    "6cfe60f9c69a41202fadcae4e260fbfee73f077e0f3bbf9f1d15f49cd43eccc5ea5a55eab7ca4f94f3bd34f0fb72f3fbeac2e5816ecaff90079ade7ec80391c1"
    "833c5030f6617fe7f4128933fea297fcff4b8c3daf7e7b88c18bb8f4eebc90ae0b9a71c848226fb922a93526c785f53e700d8be7d4fb9e47bce238e2799fb7d2",
    "67b02e08fb78108bb5cf1f6772a942a338a89e9ce7d9fce37d03f67b2e617f36e5621bf23d1ef120df13149e2dcb8207f99e60ec03af4f2f9138793d09fb3c27"
    "dfc33ecfe92512d8e749060ff67906637f8439dfab1f4f31f6232efd3cc68187a26ee91b1a23918dc3d13362bfdfb22eb14ec1efb770fbc2cc0ff4d847e49fd7",
    "f002f83dfcfcbe392849b9769f6f15e2c78327bc16db50aa71f8fdd612f45f4b82dbc70ff37a1c9e530ff3fad7c5b36559f0605e1f8cfd11e6fcd0cceb59b5a7"
    "f03ae179fd5e60e3c1f730781197fe95f1a060ad68042d2d999ea1829bf7df75d5afda636bb82633de4014d47e9e8aab4eb98e437affe3c1758711cdf3ffeafd",
    "0790e70ffb3890538a9554f268f75c9407e5568797cbc6ee7081f2fc23ccf9300e38c5390e1c0496df99350f371d203383dbe379bfebc30c16cfa9f7b53e1cfb"
    "88f8fe9c171f00bf879edfb56eb4d312f58da41caf24940a7bbcfef4504f01bf2f35bf538744f95d5480df67f1bba810e7f7bf00bf879fdf1bccb34479fd68b7",
    "9b6093467a93296f081b7bb01fffd2de52edd3a1f2c0eb1ef180d783c2b36559f080d783b10fbc3ebd44e2dc7fb90bf9188f78908f090acf9665c1837c4c30f6"
    "ff8e39dfab1f198cfd884b3f87dfcf3eec33daf851f9a71d4de55dd7f505a6ddc1f23c17d8fdd7ef63f0222ebde99c53d329a775559354b573aaf605ad2ea967",
    "a79ce595db7baee6e88678c8fec90c3ca4bfe1386087d537788efcbe9cd15fff7b0fc687b08f0ffad3ec209b393faf3c19c4364ab1687a2fb9165da0dfd3bec4"
    "9cefd58f1718fb11977e7efdfae1371f70da14a48ea0918dd39dc0d607b3e6eba25eb7dead1958bff8008be7d4bbf70929bc302828c6653bbef4d98eed19ed40",
    "fad78cabba3810f88e6ab69bb63c47727f0e05fbf3e788476a3ca80e3ba2bcd9dd3f5a13597ea370b25729adf517e8b99a5f62ce5fe27e4b5d7fae4e0763cfab"
    "7fde75d529d771482fea8abda1dcb0deb01cde7d97052c9e53ef271eae790a4df349f2d0d7f01cb5f0f3face7a7b58ed3644295d4bb7f7bba946ad7d905d205e",
    "7f89391fe6f9d3afd75b9c16e03e80473cb80f10149e2dcb8207f70182b1ff12733ef0fff4ebf5767f802cffc3fe1ed8df836459f0607f4f30f6fdeeef39c0d8"
    "8fb8f4cfcdcedb5465816e32bc485799ba4097b23b497da87074defaaa56aa65860a9d5679017d4e090643f763abd1957cb148e718d65cccd3822a9bbd5bd773",
    "6be30e4d36fe7e1418afbf8dc18b4c34ba45ea54789fa793c4e239f57edeb3a62352a748c6c136bc0f7d8e78a4789d61f2a993b3765e3c2ca57b522aa5641295"
    "dd05caeb40ff75cabc9ea7f311062fe2d24f7f1f0a62f9dbdbbfe3378f5f9a8187f441bd0f05c50cc179fcf66f7e077c1f76be8f6ee6e35be9b3a35834757626",
    "453bd246a671be40791ce07ba7c07b71a7b70fde8b6b4b80e303bc17778e78f05edc60ec8f30e743bf76cabcde9bf8a6ac136e9a0f8275c2f4f6c33a810c1eac"
    "1382b10ff9fee9251267fcfd8458be9f53f57109f97efcfad1f4d16dac1f21df3f473c52bcdea90d5a89b2518927ca4caddaaa693b434e59205e87feeb943733",
    "df8f581ef2fd5ee7f1286608dedf8dc33c3efc7cbfa51575668f2b3d3b629f1db3a9547ca3de1080ef978eef21df6f0be4fbbd5d8f873c0fe4fbe78807f9fe60"
    "ec8f30e743bf76ca9b99ef0f6e9d70d37c10ac13a6b71fd60964f0609de0cffeff0165baf2db",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 47672U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF1_info.c) */
