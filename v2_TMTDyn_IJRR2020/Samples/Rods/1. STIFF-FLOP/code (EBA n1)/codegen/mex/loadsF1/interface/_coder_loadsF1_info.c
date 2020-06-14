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
    "/home/hadi/Safe/MEGAsync/Hadi/TMTDyn/Code/TMTDyn/Beta/v1.0/Rods/1. STIFF-FLOP/code/loadsF1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737560.59439814813));
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
    "789ced5dcd6fe3c615e726d9208b22ad80b449fa9566d3629122a9a92fcbde0201f46dcbb6beb5b6d7492a531225d1e6874452b2a44b7dec2187fc013de49816"
    "6db1ed258b2428d45baf059a1e7a0a5004bdf4da9e2b8aa2bdc3d544b439a245e93d6031a29f38bfd1dbc7dfccbc7933a46ea5d2b7288afae6e8df07bfa4a8f3",
    "97b42b8a7a91d2c533299fa15031eb6f4dca35d3b521b7a9e790fb6e4df07e3db9ae4aa2caf654fd82e74436d3112aac3cba101981bda8a626099cc8886aa9df"
    "6229995524becbd6c69a3ac7b3254e60f7a4272eb6b9d185907c427571a1a9b4cfb1265b3d2d76044a6e2a97cde59fbca026f6d16488f9fdcf59b44f19631f8f",
    "49ff6ee27dba29092cdd646a1c5d64ea2c9d4e6c4594be58a5b7b53f95d2a5785fa463528d353e475995a1bbbe352f5d906a0aed5b7bbd584a25933f4bee6573"
    "7455fb222f313525e95b132e7e4f0fd3dee72dfe9e6731bfe7cea47c15f96b20ac97be49e90f1bed38c6e058b5eb6d4c3b3c134d4b3a1b7b1329bce74dd79778",
    "baa626752a3c7b89f7b14dbc08160fd5bf9bda3b1cb94e479147ffd95586a7d391d25e244a17fc5edf6685562589af483d9a15789ae72ab4c0a83c53a1a59642"
    "8f2d34f20c5d66d9c9aa7f984b43ee502f4c3e9d7ff045e81f11e7f07459153cdcf36dd5ef5ec6e0794cfa83e63e1b2ae68beb8552be7318df3dda978a0f6297",
    "edc8cdc099d50e0a73ed54fd6e7d7e5b987659f5b7674cd78618fcee41fe7a2fac976f5cf0fa39a67eab76fb1106df63d26bdd9bbcc68d0611b2c8f06b9c12ed"
    "70bc9a1247c30856e6aa37c6fb8f6de215b078a8fe0a7ea3fd7b6b6c2ffa2dc360b4d960862339d80f7cf2df7f7e01fdc09cf09cea07b2dd762c52dfee6e96f2",
    "c17e352188fee411bfbd3cfdc023ccfd56edb883a9df63d2dbee07eed679d518f4520efbdd793a4ccaef5ec1e0794c7a13ff2b23933172a27163bcbf807e3295"
    "f70d43dd00dfffe1de2f60dcef76bef7161abeaeba735f921b4da598641ad164aa1b07be5f9de79842f81e37dfb06aaf174dd794e97b869e53447da0aa6a91c0",
    "9b8bebd8f58f14160fd55f713c50e77a6cad258ddc83462c7503f11deaf707df8571bddb797e2b70da2fb61b1c1f2bc54e0bed68a374fa20013cbfb23c8fc3b3"
    "6aaf174cd7d4c5f7740da7d4b9d1a4a6e9d6787d1c8b87eaedf0ba6e21dd1380cf9703cf2e9f7f0783e731e9bb6d36d1ea5695fb87670149ca29455fe0e111b5",
    "3c7cee96b8eb259fdfad73b2a2d639f4771c63da49d4ff86c7c4e2f5af61f03c26fdc818e59111ca7549e625a95596baac5ce7a5b372555b8fb73f9e370bae3d"
    "86905adf3f9a8167e8af17df9bb8d1d758cef971c1f0f3af6e431c6751fb03abe37b6537d14bc40783dc4ecf1f4cfbbdb17cc4e74d2c4f7ff025e67eab763cc7",
    "d4ef31e9e7f75cdffdfa2f949b2cdf626567fd748bd87ce039d33575f13d5da38d76b5f286d71538b1c6f652a27ad18e8f6cb6233ca31d86dede3c614d70d02f"
    "1ec33aaefbfb8362bfc509ebedc2818fabd482a9a37c2eed5ba6b8fe4798fb57f8b91d897769e2f8b3fa936a9319af8c431c7f7a6908c47d9cc183383e99fabf",
    "c4dc0fe3fce9bfd79a9fa6888df367c5e1473f5c607a37d70f2c68dcdff01f7ef481d66de474dc7ff8f8953b10e7713bffcb6d6feb845382112194db107395c3"
    "c0eebe1205fe07fe47055df77596ff3911f87f16ff73a2e3fcff19f0bffbf9bfc13cdcc8060e32ed8d4a448dad33d9201bcc6f2d0fffc3baeff4d210c4ffbe3c",
    "26c6eb578ddfdbc5bb6a3ecf4736f1c2583c54efa2781fc4e9e78807717a32f5bb90cf07ac2c291d01fd1db878fa5cf6e10edf0b8fcbf0fb8ef17bbdc3f35a09"
    "f99ad3c6ed4a8b91eb1d91d6ace4f4b8fdfc8f10b7773fcfab21bf50881f6c358f02d2a0aba68564daa72e11cf3fc2dc0ffb6a9ff4bbcbfcfb5f61eab36aaf37",
    "31781e93de94ffc2b45a7c3fca898cdc2f8e7bbc6447acaa9c24925a37fed68c7619fafa04b7dc64c4daa8232095bff9ee0c7c436f77bc8035e46465d7c1fee1"
    "4fbf9121aee3f6fe219f8fa9a7b913ef46e528b39ba99498cd6c5a492e4fff30c4dc0fcf352aa81f6e10eb2f7e8cc1f398f4e6fea22b71b5882c33fd24cfa82a",
    "2b726263fcbd9bcaefb73b9fdc9f8167e86dfbd114c3692ee4a0ff9cffaf02fd82dbfb85c1ce7620f6a07528e42bd95ae4b0be9dee09d9253a8fc7eef35cc2d4"
    "ef31e9edcf1bf40851b9ce4b8c5abe984138bbcfeb08cee5b189b7fcfbbce15c9e79e2c1b93c64eab7cbfb794cfd1e93de3eef8b929a61325939357ab41b46d8",
    "c8e1731b0e88ad03cc3a6799534446a4dcbb0e10c3e2a17a5bf93b9a8d9c8ff3c07aef1cf19c3ab7a11de9648560ff30e82dc8fe4eccc7deef0a196a79781d9e"
    "5f54507ffb09b1731ae05c651c1eaa877395af8aa7cbaae0c1b9ca64ea87f1fcf4d210dc78fe1c539f55bb7d1f83e731e9a7c671d6eabc24e916706b3c278bc5",
    "43f576fb81b7748bd1638b3df1fe9d634cfb08f2ff6f21ffc7fdfc5f6986728722afd68a9290e888db814a22bab34479fb0b18975dbcfc9ff30cb1f8fdb73178"
    "1e93dec4fbac2c4b96d62de6b53f6bc1c6fdcaa8796c8dd6d97ec2f966ea1fdbec06c6fd7fde7d08717cb7f37e4fcc9f0dd22d21bad58e2795cdd84ebb2b7997",
    "288e3fc4dc6fd58e8bf63ec516a6bdf379df5628ac97eb8ee5f92b6d79fc924eb7c6f7a3583c547fddf8a096e5afd9c879be0fffe5c13d18e7bb9def835b897a"
    "d31b4a9d641381949acb8b6237165fa2380f3cbfa8a0fe768f585ce707183c8f49ff547c3f2e090c2726cce37c5cbfe6545ebf5be23c88019d8df37cfa1fc8d7",
    "743dfff369a1269cca6cba153b5037a54eadfeb0c32dd1f93cf01c4f6f3fea772162e3f9d9ef59d1f6a62aac5bc7f3db583c546f6fdfae612527cf6708bff00e"
    "e461ba9ecfcf0e524a923fdd4ffaeb7291ef9e6477c4413e067cbe5a7cfe0eecc39a08ecc342db6dc17f601fd61cf1601f1699fa21ae830aea6f6fc2baad4d3c",
    "58b79d179e2eab8207ebb664ea07be4705f5b7356271fcef61f03c26fdf4fc4c63b5f6e6c6f976e787991978869e547ea6e133cef9cbf0937ffd1bd66d1795ef"
    "adeecbdaecec15bdfb816c444e0512e2e14e2124164214f0fdaaf1fd8798faacdae9a7183c8f493fed5c36f4c0a19498e3992a3bf9fea2ace30e6de2bf3703df",
    "d01339c769aa411d3f77bff28d13980f2c6aff60753e20317b271586d98ad5029b27caa19f4d1fb5fa4b341f1862ee87e71a15d40fdf86755e8b78b0ce4b0a4f"
    "9755c183755e32f50f31f703bfa3b2ec71a0ebf23fc481a6b71fe240cee0411c884cfd43ccfd6eddaf758c69efbcf27fce31f559b5dfeb183c8f496fea076456",
    "69322db6c80dd898f61649c5ad793fc5197886de6e3ff094c19c3fafed6fbffb18e6058bda1f589d1784b6bcfc466e239fdbdfde57f60f428ddd427b99dedb02"
    "cff3f4d210d4ff5e279607f42a06cf63d29bfa0191911b9c586d9eba95ff09e77d5ac903bab099b3f381f3977e5ef83bf0ff9cf09ce2ff7eef2c759f49d61beb",
    "de6a3621154f929d8db304f0ffa23dcf387fb0ea7fcf627e87716ec3abc85fdf0eebe51b93f272dfef310687d4f9ccc6896d6e5d0798f7f9aee3b7344ece68d3"
    "c4417e82f31be688e714df6fb637b2a5361f5f3f8d364bf9ada2da8ec7ab4bf41e2e787e51c18defcf31f5c1f9ccd6f0e07ce679e1e9b22a78703e3399fa81f7",
    "5199d7b9fc8b721eb359acc6771e5d13cfa81fce63268da7cbaae0c179cc64ea07be4705c7f71f62ea837c7f5d8636f1572f6f0cf2fde78907f9fe64ea1f62ee"
    "87e71a9579e5832eca3ce1baf12198274c6f3fcc139cc183790299fa21ff677a6908ea7fde0bfeb77b0edc5d0c9ec7a437cf1b148595d57d86e76a9a29227263",
    "f23db7ae1394b078a8def638e229c3393e2f78267606f302b7f7077effe9e07e3c194d35f67ac5a3c17665fb7e41857ca0157c9e47721e86fdbf16f160ff2f29"
    "3c5d56050ff6ff92a91f787d7a6908caeb11c8039afc1df280a69786401e903378900744a6fe21e67ee2fb7fe7d00fdce5144ddf9019de593f1c3e742cbf5ffb",
    "89750af2fb717903a30ff4d846ceefe77d0cfcee7e7e5fefa5f9e469b776920a1df6766ab23f28164390dfbf02cfaf26e4f23c615c8fc343f530aebf2a9e2eab"
    "8207e37a32f50f31f7bb665c5f913a624d71785c9f27d61ffc1083e731e99fea0f52da8c869563fcc83214b971ff55dfeff2c8265ece744d99be67e8edf7074f",
    "1accd138ff072fdf8138bfdbfb81a4b8978b460e32034ee8654f5a3521ab66fa4b14e71f62ee877e0015b41f78402cbe336b1c3e3280c0f46e8ee7edce0fe358"
    "3c546f6b7e38b691e3f9398f5f017e773dbfcb6d6feb845382112194db107395c3c0eebeb244ef5f1f62ee077e4705f5c37d47f99d1381df67f13b273aceef9f",
    "01bfbb9fdf1bccc38d6ce020d3dea844d4d83a930db2c13ce4e35fd4b752793ad436f0ba453ce0755278baac0a1ef03a99fa81d7a79786a0f9971988c758c483"
    "780c293c5d56050fe23164eaff2be67eab766430f57b4cfa39ec9fbddb65e4f151cae5962cd54cbfeb18d36eb23c5f25b6fefa1a06cf63d28f8c531e19a55c97",
    "645e925a65a9cbca755e3a2b5735abdcdcb96bc36be219f51fcdc033f4d7ec0774b7fa1acb399f9733fcfcabdbd03fb8bd7f507613bd447c30c8edf4fcc1b4df"
    "1bcb477cde25d84ffb7fc4de1778", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70552U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_loadsF1_info.c) */
