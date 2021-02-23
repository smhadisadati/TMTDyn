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
    "C:\\Users\\customer\\MEGAsync\\Hadi\\Postdoc\\2_KCL\\2_Research\\1. Model\\MOMOBOT TMTDyn\\eom\\rjtipF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (738078.20763888885));
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.6.0.1135713 (R2019a) Update 3"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[35] = {
    "789ced5d4d6ce3c615e6a6d960f7905640d16cd2b489372d8216292c5996253b4000fd58b2e4b57e6cd996edfcd8944449b4f96792fab1d0830214450e2db0a7"
    "9e7ac8b10d50203d356872507b2ad24b0e6910043d2c50042d8a1e8202e92d412571e835b99c15d71a51a6f406c88e478f9c6ff8f2e6bd79efcd90d4b554fa1a",
    "4551dfecfdd7afbfc8f7ffa5a82729ad7850fd18652c66fa35542f9bda7ab94e3d6eb84fa7ff1ad52551509996aa353856603275bec8c8bd8640f3cc79376591"
    "67055a50b7cf2486921945e41a4c7940a9b01cb3cdf2cc8678a191647b0d3e718174dee893fa7fc76a4ce9245fe729b9a6dc1f2e77b1415de04f17f3fc8fdbe4",
    "cf11863f1e13fdd5f8ebb197bd3b0a232bde525d51459e91bde9f85a4439134ade245d66bd395151cb62c9eb3fbc13dbe8fdbbc5280c2d976ade85f9b9b45866"
    "386f3a9bce46b3db73dbe9edd533c1cb88bc573e56592931cfebcf73f79af5789fb0f93c2f629ee726aa7d17099e7a785077b6b43a5cd16a2aa5d55d15d5887e",
    "84e81d44a7eea036aa25d41f85ae9f9350bfa8fdae4e2fa0fe503b8cda1d5453e8f72e6abfcda036aaefa19a42e399d3c7856a9f8e8bea1caa8f502da1fa23f4"
    "7cf750fd05aa3b08ff2eaadfae87f5ff3f471af0a5e5edbaa94d9d5fa75124b1399865a4f09e30b5efe36994b2582f72cc7dbcdf8c88b786c533d25f4d6dec0d",
    "a6544e16ab32cdcff5e7bee24d47b6372251ef96dfb7b0427b5551e48a62cbcbf09c97638b5e9e5639bae81525c53be0d33c3f944f76e78db9d6cb4dea06faab"
    "f3f12f3ff924e21c9e566605af85e9cfaedc7d0783e731d1cf7c2b422d156b66938ca008c19d60f1602d79611cb92138c3c64161da4ef5efd6f92b61c66557de",
    "1e33b5f5a2db3d8fe1d7f9b0562f9cebf50ea67fbb7c7b1e83ef31d14bbd85803ccff61657b24073f3ac12adb39c9a127acb2b46664b13d3fb7f1911af84c533"
    "d21f496e941a2d3365ef8067e8df9750a573d06be6604fa6fac5413df621f535d885ab6a179ec2e0794cf4e64174a7dd6ed54259a91e8ffb63a5a52d7a393a3d",
    "76e15dccfd76f99833b529d3753a9d905db85de1d4c19f8eca5d3817262577b730781e13dd640f9412cdd172bc3a313b7065e5a4ffdf03ca5f67d77dfff90833"
    "3e7272d2fdeffe5f41df5f557d6fd70f8804848ab8ee63f3befd602eb7b0518d2c05380af4fdeccce35ee9a4c3c3fc0fbbfc32c75129d3753a9d55046d9daaf6",
    "23a6938bf38c2a1f592c9e917ea9f540856d316549ec8987d7c02f47e33dd4ef0acffc0df4fc98f09c5ad7af2d9e9ce54fab2c17db8e9d6c9d46abdb273bf155"
    "d0f3b3aae7717876f975c3d4a6ceafd328ac52617bee4ccdad7a7d1d8b67a48faed7353ea1700de8f529c1736afdde3865e252a3a4acec35174531a7e41716f7",
    "0fa8e9d1ebef61eeb7cbc73d4cff1e139db45ebf5d616545adb0cec66d686271fce730781e13bdc786c3dee31f5644991345e9506c307285139b87a5fefe85d1"
    "d7f5e6821b8f5e1cdf0f31429c0f89d143f8e7683ce783cfaf433ce7aada03bbeb7ce54ebc155f6db773eb2d7f20edf7c536230bbef8f4d8837f61eeb7cbc79f",
    "63faf798e8e39ed7b71f7ec1618de1a4fe061867e5758d987ff0b8a94d9d5fa751faebde7e3de13c032b9499564a5089ed1b480c19874e27e137f47d0607e5e3"
    "bd2f3f037fc1edf6217f26b1fcd2e95661812d9603a983cd5c7aa13145712098bfc6629437dfd4c4f987d997528dee6f1f85383fa6d60bc4839cc183383f99fe",
    "61fd6f1c2f59794d115bff0f8bd7f71e9da75beeb50763cd0fe872c4f5fef06a9c723e3fd0b9fee6a7100f72bb3dd897e964be516c14435bcc6afc8c5f5a29ec"
    "33600fc01e609edb982f76d61eb002d8037bf680159cb707ddf76fdd047be0767b50a5f743d9c542e634548ca8b1253a1b60029b6bd3630f205f6c5debc5207f",
    "473431fdfea8f1fe51f19c3ecf3bc5714188eb8f110fe2fa64fa77ad5e6f33b2a8d4cff771e0e2ee6339df1b7e233ca8bbaf3ba6e72b75ae7f7cc4b5fbf99d58"
    "c72b122d57ea82b7cfab09c4757e0f717ef7eb7b35e8e7b7560b6bb58345b1dd50d37c22bda04e91be1f751ee74c6dca749d4e77f5395deafe39ddb730fdd9e5",
    "d78f30781e13ddb47f869624ee2cca0ab47c961fd8bc445d28a9ac2890ca337f6bc8b8747a05e11ed668a1dc33083afea8ef73a087e0eb7432eb062c3b7533e1"
    "a45edb2cfc1be23d6eb713893d25bab7b9762793df594d6ea46479259913a628de03f3dbfab9ecc9638898fdf80106cf63a29bed474364cb1159a6cf121cadaa",
    "8cc00ad5c1756e3d37f0da103c9d4e489e2cd8a789928372d4f95f11ec84dbed447b3db918db91f6f8cd62b61cd9ab24d32d3e9b9c1e3bd1c5dc6f978f0798fe"
    "3d263a297f428b201d563891560ff59761520ecb61f835780fd0887863f343afccb972780fd038f1e03d4064fa1f357f50c0f4ef31d149e97f41543374262ba7",
    "7a53bbda53fececadf3eb17cc1b0f73cb38a400b947bf305292c9e914e60df4f9f5313f0133b901f1e239e53fafd3452cff281b3bd806f4bf6d7630bcc4a83cf"
    "50d3a3df611e5b8fdf28773f24f67e0878cf330ecf4887f73c8f8c3728b38207ef7926d33facf7ad6bbde0d6fb1d4c7f76f9f62c06cf63a25bc679e62b9c286a",
    "81ae49d98551e566078b67a49389f7bca4f1cd3be0dbc01238e817bc03fb88dc6f078ab5606e4fe0d4725ee4e37521b9588c47d7a7283fdcc5dcefd6efa2e1d6"
    "ad76e5f049535b2ffafed1dac51fe75ae141ddd9d0ea23f45d3009d56144ef36b53a87da1fa1b60fb5e7daa88dea0eaaefb61ddb97aa9cca838ff8b9f5fc4112",
    "8b67a48fe69ff677a5f639e564fe20fca79d17c18eb8dd8e04d6e2959a2f983acec617536a6e53101ab1d529ca1fc3fc3516a3bcbd48cc7ff81e06cf63a23f10"
    "575a15799a15e2b22c1acef54a238e67d4fda7eef2270c6c74da9ff8e37f601f91ebed0097e6cbfc89cca4a558415d16ebe5ca7e9d85b8d20ccee77e09125bdf",
    "0fffde40ff5495c2b8358f9cc1e219e924ce9de9bc72f69c71f8c62b6f807e77bb7e6f16524a823bd94df82b729e6b1c67d785f6660cf4fb6ceaf757e0fc002a"
    "707ec0fa796cc8119c1f18231e9c1f20d33fc47f8cc5286ff3c4e23fdfc5e0794c74ebfcb11ee59f9cfe1f75fdb03d044fa793cd1f6b3273f1398e30e324786e",
    "e00ffff827c4fdafaadeb7bbaf74b9be91f7ed2e6623726a312eecad6f0585ad20057a7fd6f4fe5d4c7f76f9f4630c9ec744b77aff84f128754ac871748941d7"
    "5f953cc0a8fb4d8b43f0753ac173ea966c9dc0772ae13d1463c473ca3fa8e762b15628569032db4b4c28535b4c6f844ea6286e04f3dbfab9ecc9e34f204f6013",
    "0ff204a4f1b4322b78902720d33fe87bebe79ad578d165ed01c48bac6bbd40bcc8193c881791e9bf8bb9dfade70d70711dbb7288d387fa7903dfc51fefd5c383"
    "fa6d56aba963ad0e37b4ba8be8730d62fec23730e3f3204a495406b55bcf0dac61f18cf4d1e38f3d4e39fbbd4a383730463ca7fc0469bb751ccaaab960284b6f",
    "e78fb7e5b5b3923045fb4561fe1acbb8de47f10c06cf63a25bfb01ba96776fde383f044fa793f5033499b9f81c479871128c0f057ff55bd0fb6ed7fbcbf28642"
    "6f96d2fb85e2fe5e311a0d062a5506f4fecce97d9c7f017963ed1e88335a3f970d3983bcf118f1206f4ca67f98dfd6cf654f1ec9e511ae8aff70d93811f80fd6",
    "b55ec07f70060ffc0732fd7731f7431ec1582cf30839942ff808e50bba289f3087f2095fa0df7dcee51194fec7ed29c823d8d8c73cf8b8bd83f600f20863c473"
    "ca1ed074327ad03c49b2bbe9589d8b4685d5502e3345dfc384f96b2c57338fa06b79c8233ce27e225670dc0fe886c10f70bfdef72d2583cbb166c1ef8b369b9c",
    "4fe202abd5f614f901a0f78d05f208d6e3833c82713c904770071ee411c8f40ff3dbfab9ecc9e355c92390f31f2e1b2702ffc1bad60bf80fcee081ff40a6ff2e"
    "e67eb7e6113a98f1da9543dc7702f43cc29ce15721acfd886a4ad26a8fe458de8069699e03e40d86f99f3d4ec1f983a9c1734aff9ff90a7b69b6995d0f6e886c",
    "33e55f0eec9c2d4cd1f76f60fe1a8b51de5eb822eb7e5dcb43dee0d1d6fd9acc5c7c8e23cc3809aefb7ff6d59f41efbb5defa72aeb9585e486ba5ca0174e774b"
    "191fbd97ac41be78e6f43ee40db4027903ad40dec01d78903720d33fcc6febe7b2278f57256f40ce7fd0f167236f00fec3b4e181ff40a6ff2ee67eb7e60d74bc",
    "b1ca61f7a7c4ecc11c06cf63a29bec81cc28355a62f26c9b89d598d28932a97852f792787afffb43f0743a197bf000dbf4e584937aecd6577f077fc1ed76a1ba"
    "2ffb025beb296e331b6c083bfc62cc2f65a6289fd0c5dc0ff3da5870f1a651e5f0690c9ec74437d9058196abac50aa9db8d51e8ce5bb683de19099b257931a24",
    "3b66113ae79cd3ef3bed7cfbe5ad8fc11e8c09cfb1fc72ab995aa11395ea92af948d8bf9e3443dd48c833db8aaf31a271776e510b79f47df5ff4b4e1d717c25a"
    "fd22aac97d07e13a661c1e44a970a22853938b17bd3b225e0a8b67a48f9e9f1a706a12eb06d85f34463cc7de53711aca6e9f72ab4b27d1daf6e65a5e3d5d5d2d",
    "25a647ffc33cb61ebf51eee688c5859ec7e0794c74d3fa9f55a27596535342a6ce33325b9a98de1f35df54c2e219e9c4d70b660e3a9e37a03ea4be86f890dbed"
    "41f320bad36eb76aa1ac548fc7fdb1d2d216bd3c45e70dc01e588f7f5cefab781683e731d1adf3c6ba17e0de7da73b43f0743ad9bcf17dd971301ef44ee119f0",
    "07dcaeff8bb5606e4fe0d4725ee4e37521b9588c47d7a7283f00fadf7afcf0de0aebf1c1fe53e37860ffa93bf060ff2999fe617e5b3f973d7924b7fff4aaf811"
    "978d2b811f615deb05fc0867f0c08f20d37f17733fec333216a31c2e9cdb83b730fdd9e5df6d0c9ec74437fb158ac2c8ea2ecdb1e53e332272155d3729bbd01d",
    "11ef008b67a4135a5f3cc03ee7d715ddc7624df01bdc6e1ffcfe93f6ca6a229aaa6eb4f207ed6431b9b2a5c2bea3199ed7bdd20913db5f74c3d4a6ceafd328ac"
    "a248b4ac306edd5f94c1e219e9a3c421fb1cea4722755ef565c2397908df78e50dd0f36ed7f3cd424a497027bb097f45ce738de3ecbad0de9ca2f85017733fe8",
    "796331eaf908ec3742d7c07e23ebe7b22147b0df688c78b0df884cffa3ce6fc6d4a64cd7e9f4f1d987dbacd2a7f73ae52887e5b1bbefd87983fe435628386ff0"
    "f07d09bd3fbc034e4d207ed879efcbcf202fe0767dbfd44a73899346f93815dc6bad97657f40c807e1bcc10ccde37e21b7bf14d6ff383c231dd6ff23e30dcaac",
    "e0c1fa9f4cff53b2fe2f8a75a1ac504eafff3789d989ef63f03c26fa037622d5f77d1839c6f5784391f30f70df79f0204aa9a782a90b78a3ee1fdac5e219e964"
    "e4c8c83687f306bf78ea26d805b7db8584b0918b460a9936cbb7b2c75299cfaa99b329ca1b805db07e2e7b766187585c68d87abdc7029e6e4d4eef8fea4fae63",
    "f18c7402fee48053cee7933ad7dffc14f4bddbf5fdbe4c27f38d62a318da6256e367fcd24a619f99a2f79582beb77e2e7bf2b8eba8beef7fe412f4bd1d7d7ffe"
    "594b27f77fbe7f0bd6f7aed7f7557a3f945d2c644e43c5881a5ba2b30126b009e703cefb9bc97d415412f4bc4d3cd0f3a4f1b4322b78a0e7c9f4dfc5dc0f7ade",
    "588cfb3f3310bfb18907f11bd2785a99153c88df90e97fd4f84dd5d4a64cd7e9f4b19df7bddda0e5c12ba50f25592c3b2b8ff74ac4f2b8cf61f03c267a8f2d87"
    "3d761c5644991345e9506c307285139b87a53e3f26f73eb9ee25f1f4fe8f4c6d339e4e1fc91e6862f510fe39f9dda2ee079f5f07fbe076fba0dc89b7e2abed76",
    "6ebde50fa4fdbed86664c13705e77dff0f19b8af67", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 87048U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
