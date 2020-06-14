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
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 3);
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("rjtipF"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", emlrtMxCreateString(
    "9.3.0.713579 (R2017b)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[28] = {
    "789ced5dcd6feb5815f7fbe45508781230cce363980e4f6f06cd9be6b3cd2b0b689a8f3669f39d7e0e2875122771eb8fc476d2b4ab4a4888058b59b2e00f6031"
    "8b112b96916683d8202186410889592031e20f40b3608113e7b6b127f7c553df38b173ae54b9b7c73ebfebd373cf39f7dc0f537712a93b14457d55fdb9abfef4",
    "1ef56b14f5154a2b8f87d7bb94be18e97786d7e7863a2a0fa8fbbae710fd37c36b451414a6ab68158e1598749b2f33925a11689eb96653157956a005a578d164"
    "28899145aec35407941acb3145966776c591ca36ab56f8f808e9bad227f57f8f3498ca59a1cd535243be692e375aa146e4f36bccfbdf37299f10463e8f87fc11",
    "fdddd8cf223ff2ecc98c247b64d917f2bff07ba28c7ca6884d8f6fe5f54231118fbf13dfcd643d15b1ca78a453856dc657f8eb767631ed7868b29df730ed5c1a"
    "5e5fd5fdf5c71bdaf527c3ebc6066ac70906c7acbc1e60daf158a5f4f937c5f3819690c27b68a8dfe03d1cf0af8aed32c7dce0fdd622de16164fe38fe8ef2676",
    "0f072a9195c4ba44f3aff77557f6a4c2c5ddf0a627eff7fa42658f228a5c59ec7a189ef3706cd9c3d30a47973d6253f60ce434a21f27987699d50fe3159525ea"
    "d1f0b7abcf3e5cfb6bd83e3cad2c0a1eae7f9bd5bb57307848ef10fda0b1cfac157285d57c31d73e8cee1cef8b85bdc84d3bb2137026b583c2d4ede2efd4fedb",
    "c4b4cbacbedd35d45141f6fdb1eeaf6f6c68d767d776fd0ac3dfacdcbe8fc1477243f4be77935658353890049a5b61e5cd36cb2909410d0f1889adcccceeffde"
    "22de21164fe38fe85f586ffa3f6f0fa4e6791b89cd6314db0a6fa31ff8c1bffefe11f88129e1d9e507329d56245cdbeebc28e6821795182ff8e3c7dcb67bfcc0",
    "0798e7cdca316ba85323f78db69f901f58ae71cae0575bf5ee2ab5414aefbe85c143f2427483fd972b34474bb1faccecfedceac958bb8fc465abbd5ffad53fc0"
    "de3bddde7bd3e721bec8f2c73b6cbe1adb89560ab5dac526d8fbc5e9c794cedee3c61b66e565ccfb5123f7dd1da1b3b2a085a84a3fc337bbbc8e55fdc860f134",
    "fe887eab78a0c676996a5354d5c3a39397adf91dea49fc09d879a7dbf9adc0d945a15567b9483172966f6dd68b677bb128d8f945b5f3383cb3f27a64a853d7f7"
    "3d1af067e51aab0e671a4eb5eb492c9ec61fd1addb754d4eaa491f14b0ebeec0b36ad7bf89c143fa87e89d16136b762af2fae1794014b372c117383aa6dc63d7",
    "9d957fbdb1ebcb355692951a6babfef54e88e5ed5fc3e021b921ba2a8692fafaa59a2871a2d82c891d46aa71e279a9d29f6fb71ed71b0bae3da85caf6fb8251e"
    "e27f62a81bf110dd4a9e6fa8462f919fadf99cf73f7e00f3b8f3ea0fccc6f9f24eac1b8b5e5e66935d7f30e5f74672619f37e61e7ff029e679b372fc05863f92",
    "23a24fbb5f2fbffc865283e19afd052ff6eaeb16b1f1c17d439dbabeeffef5f8a05f9ff13c032b54996e425088ad13884f6807a2931837f4c70c36eac75398df"
    "75be7f285c34597eb5953ff0b1e56a30719ccba67c1d17e581a0ffea8b5edfbcaec9f34ff22f9506dd5f2e0a797ecc1515c807d98307797e32fc21fed7bf1759",
    "7d4d108bff27e5ebd557e7e9ae73fdc154e707901e71ea2f1e4d52f6cf0f5c3d7db804f920a7fb03a9e56d9eb27230ccaf654342b67c18d8d9975db4be07fc81"
    "febdc8ce17dbeb0f5801fc81397fc00a33f0076f823f70be3fa8d347a14ce020dd0a95c34a6495ce0499606ecb3dfe00e68bc75f51d1e9df2727c4ecfb17cdf7",
    "5bc5b37bffae8bf38290d79f221ee4f5c9f0b71a9f650d756ae43e4beb3be769df1675b3bef397187e66e5f516060fc90bd10df3a974b3c95d6cb2022d5d1406"
    "be2dde162a0a2b0aa4e61dbe36a15d885e1be2961ab450551d01c2ff83457c7a023ea293890fb0e244e1bf9df1ff47ff83731e1cef272e195a0c0be9c0b152af",
    "fbb7bca94c75efc0e7223fd1c33c6f568ec718fe488e884eca4f682380528d1369a5840eb9a16cd6c3de31ecf7b58837b5f8626ef68fc07edf69e2c17e5f32fc"
    "ade67f0e30fc911c119d94fd1744254da7335242edda75d5f8db9bdf3f2096ff99747e1b2b0bb44039779f6f028ba7f1477402f9fdbea46611df431e688a7876",
    "ed076b85db193e787118f4e6257f3be263d63b7c9a728f7d877e3cbefd7abd7b4a6c1f189cdf86c39bc67c109cdfe6563c38bf8d0c7f88efc75f51c1c5f75718"
    "7e66e5f61d0c1e921ba28fcdebacd43851d4125b4ef5037b583c8d3fa293f1036f6b72f30ce43688216cf403afc03e00e7fb8172632d7b28704ab520f2b1b6b0",
    "1d28c736932e5ae733b7f9da799a0fbe4a13cbeb7f038387e485e806fbcf4892a85b677962b11d5f745de75cc6ffb2da48a6ead1acfed0f61b5dc04072b6c6ff"
    "62ef19ccef3addee0bc5a31ced3fda3e0e743aedd861c717e093ac8bcef177ca77594e30ed20ab5f61dbd66fca2d69f0d11ea7aedfdcc6e269fc11dd5adeafd6",
    "163c7d49d97aaedf3bd16710af3bdd6e07b762b586772d719a8905124a3627089d48d445791be8bffaa2d73772df5bf92e060fc909d13f97af8f8a3ccd0a3163"
    "bcdeb4d81eabeb359d95b7d189d1e6bc0db5f4a74d88dfe7d50f989dbfe552a972cc1788ac9eb3954a4c6e761a47f51dca3d7e00faf3f82b2a7afd5b2316df4f",
    "3eaf596ed292cc38757d4e1a8ba7f147742bf1415f42fd0801c9cade7d5a575fceff17e2fc79b5ef66e3fc552ebf7d2ea65e6c05f6b6eba14ae432994f145cb4"
    "fe12e27c7dd1ebdb5b908fb78807f9f869e1696551f0201f4f863fd87b7dd1ebdb0ab1bcceb73178484e883e7efd0dcade5bb7fbc6826b0f2aa4ec7e71021ea2",
    "935d7fa3e9cce87b9c60da49721de69fff0d71febcda7db3799c17eddd82773f90094b89404c384ce6d784fc1a05767fd1ecfe7b187e66e5f4430c1e9213a28f"
    "3b87417f644042c872748519de3f2ff97dabe7319427e0233ac1f318c68a7506dfef0a9cafc2f8605efd84d9f1c16e72a772d4caae878f524149f637597f2794",
    "74d1790cd0bfc7bfd7a28e1f6e3b3f00e387f1575460fc600f1e8c1fc8f087759ca3ebf4c9ade3fc1206efb14ae9f39718b941379999d9f10f2ce2ed60f134fe"
    "886e7dfff6505243c76fa3fdfecfca3fc17ecfabfd361bd727bca7ebed8b7040f006bce973c517ab305dce45df61847e3cbefd7abd7b4e6cbef7550c1e9217a2",
    "1be2778196eaac50699ccd2aefdfbb251ee2ffd30978884e7cbef75a72b6c7eff79ee7ff02f67f4a7876d9ff8bee79629d8ed7eaabde4a2626164ee3edd0b98b"
    "ec7f0ff3bc53fb354e2fcceae13dccfb2c0dafafeafefac686767d36bc3e2716ff4f3a870d9dc4e0d4f8df9ef39bfaf34637672ff40bece772079e5df6ff452b",
    "9429b6b8e8ead966a398db2a28ad68b412778ffd877e3cbefd7abd7b9d58fe1ece61c3e15958f709e7b05d9745c18373d8c8f007fb3fbefdd33a87735ece5f33"
    "16b3792067edfb83f3d7dc8a07e7af91e10ff67f7cfb71f6ff3d0c3f58070aebc45ef65e26f40cd6814e110fd68192e10ffd7bfc7b99d34772eb40e7651c31ab",
    "3c128c23a685a79545c183710419fe56c7118bb18ee8e61c20abdff55dc6e0217921ba711c21cb8ca4ecd31c5b2db0974c58aa0fef9b951fe859c49bda773ec7"
    "c7139f13df0ce2883ffeeeeb304e70ba3f48b1e54421193b6e6ef35bb1f5f5cd5ce7fc72dd45e749f430cf43bfd617fdfe810d9867a6609e79b4dd26c60730cf",
    "3c453c986726c3df6ade8831d4a991fbee8ed0a7e70f9659b94f57997294cdfab87164dbbad2fe4bd62858576ae6bba0aaa4e0fbbe2ec3b3edfcd06e8a8b9f75"
    "aaa789b5c36eb22af98342610dd6952e503fee17f8be2fc4fbfa7643bc3f5b3c88f7c9f07749bc5f16db4255a6ec8ef773c4fcc2f73078488e88fe39bf30fcd0",
    "7184536543911b0fd87dcef43e164fe38fe8a4fcc2a8d8ecfdae00f5d9fd25981770ba5f880bbbd9cdf041fa92e5bb99d36695cf28e90b17cd0b805f18ff5ee6"
    "fcc21eb13cd0a4f85c15014f776767f7ad8e1f93583c8d3fa213183f0e2465ff7cd1d5d38760ef1d6fefa596b779cacac130bf960d09d9f26160675fde047b0f",
    "f65e2d57f6da7b56007b6fcedeb3c20cecfd9b60ef9d6fefebf45128133848b742e5b01259a53341269873d13a50b0f7e3dfcb5c7cbf4f2cef73dbef070b55a6"
    "9b10943cc389cd3e7d56fb8c7bb7c443fc4f0c75231ea2133f974a27415be705f68202cc0b38dd3feceec623a1704a4ad6767999cf361ae143dfa58bc6039f62",
    "9e372bc79f63f8233922fab4fbf5728d1369a554e9e7794b1551506856904be8269435b7595f3f6188f98f27183c24674437f88f815452eadfb821dda9f30679"
    "2c9ec61fd1c9c42137629bc1b802f6974d11cf2ebfd17911088698e44ea6165d578e43747e37c2f22e9a4ffe1be679b372ec1aead4c87da3ffa7a9fb0d562ec9",
    "6c5d60aa7a6761ab7ef62a90573289077925d2785a59143cc82b91e1dfc33c0ffbc9f445af875b60e74de2819d278da79545c1033b4f867f0ff33cd8797dd1cf"
    "13a7605d90493c5817441a4f2b8b8207eb82c8f0ef619e372bc7230c7f24474427785ed0728796061f9d293525b16a789f134c7bc9eae14ddee60ac3cfacfc5e",
    "c3e021f921ba2a92926ac94a3551e244b159123b8c54e3c4f352a5c154ce607ef8a5faa3850d2f919fadf3c3ef7ffc00fc82d3fd82bc13ebc6a29797d964d71f"
    "4cf9bd915cd8e775c1f7c8fe0fb171cb39", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 67800U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
