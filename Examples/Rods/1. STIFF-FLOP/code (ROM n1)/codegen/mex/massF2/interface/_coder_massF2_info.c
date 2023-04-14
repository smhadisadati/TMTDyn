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
                (737429.55559027777));
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
    "789ced5dcd6fe3c615e76eb34116455a02f9ec579a4d8a458a04962cc9b2b7685a7d5b922d4bb2fc213b49654aa224dafc90484a9674a98e3de4903fa0871cd3"
    "a22db645812c9a20506fbd16687ae8698122e8a5d7e65c49246d7356b3e22e29caa4de038c31f5c4f98d1e86bf37f366f886b891cadc2008e25ba3bf3fff9220",
    "3e7a617c4510cf138a906a7993d00baabfa1962bc8b526b7886774f7dd50f17ead5e57045ea6bbb272c1323cbdd3e6cab438bae0298ebea8a62a700c4ff1f25e"
    "af4913222d096c87ae4e343586a5f7188ede16ae5c2499d10597b8a2bab818abc6ff471b74e5acd0e608b1215d3697bd7a41a8f619cb7dccef7fc6a07d7630f6",
    "2111fd7bf10f3c0d81a33d0daaca7832f1cdb0d4e32b9ee4f82adc9685bdcc5eacc77ba24295be7a1da165cad3595df17a2a630d474952c2b7c25db6ff634cfb"
    "9e35d8fee730edbfad9621dda769e57290523f0eaae59a5afe4c2d7fae9621f5fba190d6de134c7b8cdafb16a6bda4aa690ae7935e6615deb3c8f5259ea2a90a",
    "ed324b5fe27d62122f8cc5d3ebdf4b6d17475daa2d891e56a850ac2713dedb0e473cbb3eefea46d9230b025b16ba1e9a633d2c531e751c99a5ca1ea129792616"
    "1a77a189ccb293d17e84969adcbee861830fbf0cfe336c1f9e22cb82d7c5d467b4dfbd8cc12311fd61e3800e16f285b5ddbd7cbb18db3a3e100afbd1cb76e466",
    "e0cc6a0781b9b6ab7ea73ebf4d4cbb8cf6b79bc8b5269a1f20759fde0d29e51b17bc3ec0d46fd46e3fc4e093887eec06c5156634b810798a5d61a4489b61e514"
    "3f1a5ed022535918ef3f3089b78bc5d3eb9fa0df8cffde9ed8cbf3b666300f6a30ad23d9e8073efddfbfbe043f30273cbbfc40b6d38a866bc9cec65e3ed0abc4",
    "39de97386693eef10366e705694cfd24a237ed07eed458591bf41236f7bb41266455bf7b058347227a84ffa591c928315e5f18ef5fc37e3295f735432d80efff"
    "70f71730ee773adf7b77ebab1d397d4f10eb0da990a0ea9144aa1303be5f9ee798d0f13d6ebe61d45ecf23d704f23d4dcf48bc325095c711c2c5c575ccf68f14",
    "164faf7fc2f1408de9d2d5a630ea1e1e9da51610df217e7ff81d18d73b9de737fd67bd42abceb0d1bde8d96e2b52df3bdb8f03cf2f2dcfe3f08cda0bb7be40aa"
    "1a46aa31a3494dc3a9f1fa18164faf37c3eb8a85949e007cee0e3cb37cfe12068f44f49d161d6f762ad2bde2b95f10725261d57f744cb887cf9d1277bde4f33b",
    "354694e41aa3ff1d2798765adaff862796c5eb5fc3e091887e648cd2c808a59a20b282d02c091d5aacb1c279a9325ea7373f9e4705d71e4d34bce153e269f51f"
    "cfc0d3f44f17df53bbd1632c67ffb860f8f957b7208e735dfd81d1f1bdb415efc663fd7e2eddf505323e6f341f5ef5c6dde30f1e62ee376ac701a67e12d1cfef",
    "b9bef3f82f941a34dba4457bfbe9a665f38167906be2e27b8a663cda1d970b5e5760f82add4df1f2cc7d5646db119ad10e4d6f6e9eb0c2d9d82f1ec03aaef3fd"
    "41a1d764b8b5d6eee12a53ae0652c7f95c66d54d71fd8f31f72ff1733b12af6be2f8b3fc49a5414d56c6218e3fbdd404e23ef6e0411cdf9afa1f62ee8771fef4",
    "df6bac9fa62c1be7cf8ac38f7e38477517e707ae69dc5feb3fece81f8f6223bbe3fec307afdc86388fd3f95f6c799ba78c140873c1dc3a9f2b17fd5b075204f8"
    "1ff85f2ffa755f7bf99fe181ff67f13fc3dbceff9f01ff3b9fffebd4d17ad67fb8d35a2f87e5e81a950dd081fca67bf81fd67da7979ae8fadfc313cb78fd49e3",
    "f766f19e743fcfc726f142583cbdde41f13e88d3cf110fe2f4d6d4ef403eefd3a220b539fdefc0c5d3e7f21eeef0fdd0a40c7d601bbfd7da2c3b2e61bfe6b471"
    "bbd4a4c45a9bf78cad64f7b87df04788db3b9fe7e5a08fdb8d1d6e368efd42bf2367b84466557611cfdfc7dc0fefd55eed7797fbef7f85a9cfa8bddec2e09188",
    "1ed9ff42359b6c2fc2f094d82b4c3c5ea2cd576446e0ad5a37fef68c7669fa9a8a5b6a507c75e408acdabff9de0c7c4d6f76bc8035a4bab26ba37ff8d36f4488"
    "eb38dd3fe4f351f92c77ea5d2f1fef6ced94f7a88d6c464ab8c73f0c31f7c373ad177d3f5cb7cc5fbc89c123113dea2f3a02530d8b22d54bb0942cd33cc3d727",
    "df5bd4fe7eb3f3c98319789ade743f9a62b8abf9fd4e30edb4b0ff0cbe2e835f70ba5fe8a793fee87eb3c8e5cbd96ab8584b66ba5cd645f978cc3ecf7b98fa49"
    "446f7edea044884a3556a0e4d2c50cc2def7bc8e212f8f493cf7bfe70d7979e689077979aca9df2cefe731f59388de3ceff382bc43ed64c5d4e8d1ae6b61239b",
    "f3361c5ab60e302bcf3223f1144f38771d208ac5d3eb4deddf19dbc8fe380facf7ce11cfaebc0dad703bcb057ac5807757f4b5a3abf4bd0eb743b887d7e1f9d5"
    "8bbebffdc8b23c0d90571987a7d7435ee527c5536459f020afb235f5c3787e7aa9096e3c3fc0d467d46edfc3e091887e6a1c67a5c60a826201a7c673b2583cbd",
    "deac1f785bb1986762b19113b091ff7f0bfb7f9ccfffe5463057e459b95a10b8789b4ffacbf148da45fbf6af615cf6faedff19ec5816bf7f118347227a84f769"
    "51140cad5bccebfdac6b36ee9746cda3ab1e85ed55ce47a97f62b3058cfbbfd83a8238bed379bfcbe7cffb992617d96cc512d24634ddea085e17c5f1cdf2fe0e",
    "a67e12d1cfeb9c455c3f30daefbe8169bfb6afffd5ab1f0ef743ca3f3f55cba465f380d731ed20113de20f447ac4804dbac0f495033625a7eeeb29ccc0d3f466"
    "e7018f18ccfe7580bfffee13f00b4ef70bc14d2fbb9e5bcfe70e9207d2c161b0beb5db72d3fb00f03c4f2f35d1f7bfd72d9b17bc8a5c13c8f7343de207784aac",
    "337ca571e654feb7785fa79179c185cdecddd73978e127bbff00fe9f139e5dfcdfeb9ea7ee51895a7dcd5bc9c685c269a2bd7eeea27ccd6e799e6d9d1f10ef84"
    "94f20db5bc6bdbbe1f6d2500f6fd4cdf373079fb578dfd8fc5467efaebfe5d88ff3b9def375aebd9bd161b5b3b8b34f6f29b05b9158b555cf47e173cbf7ac18d",
    "ef0798fa60df8f313cd8f7332f3c4596050ff6fd58533ff0be5ee6b5dff3baecf341c5687ce7fe53e269f5c33e1fabf11459163cd8e7634dfdc0f77ac1f1fd47"
    "98fa8cdae9c7183c12d14fcbefa34f5c91e2732c55a1d5ef6bed6b9a6cdfa2f3fcbc3f035fd35b920f64aa416dcfdf5cfee629acfb3add3f08d4f66999a236a3",
    "55ffc6a954f4d199e366cf45ebbe43ccfdf05ceb45df0fdfb12cce3ffb5cf6712e4b89766a9c3f89c5d3ebcde5f9d4ac64673ee7d073ef42de06c7f3fbf9614a"
    "4ab06707095f4d2cb09dd36c9aefe7a3c0efcbcdef2bae8b033d2dff431c687afb210e640f1ec481aca91ff6774e2f35c19dcb6b368fe71d0c1e89e8d1b89024",
    "d1a27c40b14c756c8ab05857bfe7d475e039e4fd9b3e8e78c470b6c77d6e46cf615ee0747fe0f39df5efc51291547dbb5b38ee27cbc97bbb32ecf75cc2e77924"
    "8310c47b0ce241bcc72a3c4596050fe23dd6d40fbc3ebdd444cfeb61d8e7a97e0efb3ca7979ac03e4f7bf0609fa735f50f31f71bb56309533f89e8e7e107ee30",
    "d2585f1729d6de7e383cb2edfdadf14fac11f0fed6e3f3be8e6c04799b5d856717bfaf75336ce2ac533d4d058bdd7455f405f84210dedf5a82e7772c90b719c6"
    "f5fa76c3b87eb17830aeb7a6fe21e67ec78cebcb429baf4a368febf396f9831f60f04844ff883f50d35747d9916588c5e5f3bc6f122f875c13c8f734bd797f70",
    "d560b6c6f93f7cf936c4f99dee0712fc762e123edce9335c377bdaac725979a7e7a238ff10733ff801bde8fdc0be65f19d59e3f0910138aabb389e373b3f8c61"
    "f1f47a53f3c3898d6cdf9ff3e015e077c7f3bbd8f2364f192910e682b9753e572efab70ea408f0fb52f33b71602bbf333cf0fb2c7e6778dbf9fd33e077e7f37b",
    "9d3a5acffa0f775aebe5b01c5da3b2013a9087fdf817f52dd53e9d2b79f77178c0eb8a00af5b85a7c8b2e001af5b533ff0faf45213dcf95a383c88c72802f118"
    "abf01459163c88c75853ffdf30f71bb52385a99f44f473787ff64e871227a9f24b4d51a822bfeb04d36e6b79be62d9faeb6b183c12d18f8c531a19a554134456",
    "109a25a1438b3556382f55c656595c5ecde153e269f51fcfc0d3f44fe907946ef518cbd9bf2f67f8f957b7c03f38dd3f485bf16e3cd6efe7d25d5f20e3f346f3"
    "e155af8bdea7bd8fb9df29e72a3631ed33daef6e62daaf9d9ba2e3c34134a4fc13b56cfc3f6b3c2eb544795c3a75bf7d048ba7d79bc9c33ab691fdfc1e82f352",
    "e6886717bf0736e3b58637983acdc6fd293997e7f94e34e6a27d97f0fcea45dfdfee5a36beff3e068f44f48fecaf8c091cc5f071f4bc749c5fb32b6fb2d97181"
    "5df9d37406b4377fda5ffe5b86f1bdd3f99fcd7055ee4ca433cde8a1bc21b4abb5a336e3a2f80f3cc7d3dbafef7741cbc6f390274711c893330b4f9165c1833c",
    "39d6d40f7c3ebdfdfa7ef7ee059f9bcd83f926068f44f4681ecc8ec054c3a248f5122c25cb34cff04a26cc45c5efafd939c9f8f5fd2986b3f7dc7362f0358ceb"
    "1def07fae9a43fbadf2c72f972b61a2ed692992e9785b8ce92c475de0a59d5df5ec4e091881ee17f1a8de79c986cc793eedbb966f913a451f3e8aa47617b95f3",
    "51eaa7d5a10271f5779c60da69611ce78bad23e07ba7f37d97cf9ff7334d2eb2d98a25a48d68bad511bc2e3aef0af85e2ff33af7e4bb183c12d14f3ff7445bad"
    "5ddc38dfecfcd0f07abe45e79e687dc6c67d399ffefb3fb06e7b5df9fe250c1e89e837dadb05ef813f1b1653fe385f4cef06f9dd20017cbf6c7cff11a63ea376",
    "82f36f1f8fbf7ce7a8c1f9b7f3c483f36fada97f88b91f9e6bbdb87d9ea0e1db7d3e22cc13acc6536459f0609e60aefeff031d091162",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70568U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF2_info.c) */
