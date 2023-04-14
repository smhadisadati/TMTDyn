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
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/Fabric/code/rjtipF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737434.15018518514));
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
    "789ced5dcd6fe3c615e726d96017415a0269f381a269362d160d36b0645996bc0502589f966cebcb92655b49aaa5244aa2cc0f89a43e2fd5b1871c72eaa9871c"
    "93a22d36bd7481048172ebb540d3434f7bc99fd09e4b8aa26d329c95d6a428937a0f58ccce3e727ec3b7c3dfbc79f338c26e2553b7300cfb91f4e7cbdf6158f3",
    "35b98661af628ae0b3f2054c2b7afdad59b9a1abab721b7b4973dfad19de1f67f52ac78ae440542a34c592e92e532179a9c2120c79d14c8d63289660c5c2b04d"
    "623c2970748fac4d35758a260b14431e72572a094aaa30f12baa8b8aac92ff1e6992d5f37c97c1f8a670d95dfa6a059bd947962788e77f6941fb1c23ec83ebf4",
    "1fc63ef6343986f434891ae549c5f642c290ad7a12722dd415b942aa101db29e085723afd6c3a448787a9b1b5e4f9ca8f054d553952fe05b22d58e6f30579ee3"
    "11a29f2f2ff81cfa5295bbd89dcbcaf860771edea2767b118187cf34554ef90fb30aef655dfd124fd1d4b86e85262ff13e37891742e269f51f260f4fa5a1d115",
    "780fcd5509da930a150e4361cf91cfbbb953f1881c4757b8818764680f4d553c0c21d244c543d2f52e2b8d05613a0664b1711c7c7b7cffbb90ade30eb3799caf"
    "106f80686fd171f73a020fd7e9db85412b9811b381608628e45b057e6f5865c397fdc8cec199d70f0c51b7ab7d787fb5a21d6fbfbae0f131a2bd45edf416020f",
    "d7e9e5798bdfa024a78067097a43904c45f01b2acb9be779bda0faa38a8af7f89a786afba93978aafe39c689fce7c1d45e9e07aac13c0f148b5d8c19fbc6cb6e"
    "e00f5f00df3b9def77f84381c85553672795b3d34a381cf0d71b24f0fddaf1fda788f616b5d37b083c5ca7d7f13dd16ed3c3fc94c2e25db62a521c9b64b33451",
    "5597826affda26fbf7e339fd53f5f5592fca4d82ad498ebf8a3f3189ffd11c7c556f763e401b541962f68daf49e595d6bf617e58129e5df303471cb62a04b117"
    "a96dedb484531f992ab58751f7cc0f13c4fdf05e6b453b0edfb72cde734757c72eae53349420b4095e209d1aef4920f1b4faebf90fb26d640f42b5d20663a3ff",
    "7fe783df02bf3b9ddffb2749214e9f17e3be3a9fa77badcc3e3bca4580dfd79bdf375c1707ba2eff431cc8b8ff1007b2070fe240d6b40ffbb9c6a52adaf17768"
    "db7eae40b1d3d2a9febd1df141c9462b880feec27eee12f1ece2758248844bfdf304554c45ba7438cc4683d9b48be237f0fe6ae566eee7aa2c0ffbb98bfaf1ea",
    "98b1315ebf0b7ebcf3f9debb9d08ec44fa273e6fb8dfa7bd6dda1f6d8c5ce4c703df6b05f6738dfb07fbb98ac07eae33f0603fd79af62788fbe1bdd6cacd8cf7"
    "5bb74eb86e3c08d609c6fd8775823d78b04eb0a67d88f71b97aa68bfdfb22ede7f1b8187cf346dae3ffdda0fe2fd46eb47ae2d78a6165ac1fa71fcc97701f0ef",
    "9dceeb27cd2219c8e7f2db47855cf7347a502a72f96317e5f338f5fd45c53b161d6f2fe8eaaadcd55dafc8fd5da57cd732bffe17087c5ca7d7f9f59410ee52b4"
    "9864d35d8694e6b995f1be597fe00889a7d59bf5ebf5065307928df3c0dffffb1ff0ef9d3e0f647a9d48a89ee8ed1472fe6135c6b0be78894eb8671e30bb4edf",
    "47b48febf4a6e7817b755a549d5ecc6ebf3eb56bd5b87b038187ebf486719d58c3b1f19c258c1343de570db502beffeb7dc8e3773cdf7b8f1a9b3d71ff21c737"
    "9a423e4e34c2f164cf45717d788f8dfb8fe27bd47a63517bbdaaab63baeb543d25b08aa32aca273539376e9f44e269f5cfe90fd4a901596b73d2f0f0682cb58a",
    "fc80bf9cbc057ebdd3797e6feb7c98ef34283a52889c1f75c28dc2f9710c787e6d791e8567ddf7b7754a5ad4349d1aaf8f22f1b47a33bcae58c8f67d7be0f325"
    "e299e5f39f22f0709dbed72163ed5e557878dadfe2b8ac90dfdc3a2b61eee173a7c45d2ff9fc5e9de205b14e699fe311a29f968ebfc923cbe2f56f23f0709d5e",
    "3246593242b9cef134c7b5cb5c8fe4eb34d72f57e5f3525797af3fb9269eda7e690e9eaabf669eaf328c9e6139fbfd82c9d7dfdf8638ce4d9d0f16f5ef8583d8"
    "20161d8db2fb039f3fe5f34672a14d6fcc3df3c153c4fd8bda718c681fd7e997f75edf7bf605e52649b749dede71ba67d97ae0255d1dbbb84ed1c8deae5cae78",
    "5f81626be420c98a17fdf8cc643f76e7f443d59b5b27d8793e0ff604f6719d3f1fe4876d8ad9ee1c9d6c52959a3f59ca65539b6e8aeb7f86b87f8ddf5b49bcae"
    "89e3cf9b4faa4d62ba330e717ce3521588fbd88307717c6bda7f8ab81ffc7ce3e75d6c9c262df3f3e7c5e1a5076788c1eae6811b1af7bff8ce5bfa8b47b191ed",
    "dfe13e79e32ec4799cceff7cc7db6e51823fc404b241365b39dd3a280a2efafeea29e27ee07fe3e75d689c8eede57ff9635ce0ff67f3bf7ad4878dfcff15f0bf"
    "f3f9bf419c05335b27e94eb0121223db44c64ffa737beee17fd8f7352e55d18cbfa78f2ce3f5e78ddf9bc57bde7c9ecf4ce2ed22f1b47a07c5fb204ebf443c88",
    "d35bd3be03f97c44f29cd065b4cf818aa72fe53bdcc947bbd372f763dbf8bddea569b9847ccd67fd5e8a6c25bbfdf6f19710b7773ecf8b011f73143dd96b96b6"
    "b8514f4c31f1d4a6e8229e7f8cb81fbeabbd3aee2ef3ef7f8f686f517bfd1a8187ebf446e76c862996e07587c859b56fbceaf3353f9c83afea2d3987cfc890b3",
    "9d5d1be787bf7dc1435cc7e9f3432e1711cfb32d6fb0524a1fa42b0562279312e2ee991f2688fbe1bdd68a761c062d9b2f7e89c0c3757afd7cd1e3a85a88e789"
    "619c2644916429b631bd6e55f9fd66d793c53978aadef43832309c3c846c1c3fe3ff55605e70fabc30da4f6c458edba74cae92a9854eeb89d480c9b8e83c1eb3",
    "ef7301d13eaed39b5f372811a2729de608b17cb182b0f73baf129ccb6312cffddf79c3b93ccbc4837379ac69df2cefe710ede33abd79de6739314da4337c527a"
    "b51b6ad8c8e6731b4e2cdb079877ce3225b0048b39771f2082c4d3ea4de5efc836b23fce03fbbd4bc4b3ebdc864ea89b61fcc353bff788f775239be4c31e93c6",
    "dcc3ebf0fe6a6559bfab08e72aa3f0b47a3857f979f11459173c3857d99af6c19f372e5541f9f363447b8bdaed67083c5ca737feddac3acd718a059c1acfc920"
    "f1b47aab7e376b6a316912b091ffff04f93fcee7ff4a33903d6569b196e79858974d6c5562e17d17e5eddfc0b8eccdcbff19a72d8bdfff048187ebf43ade2779",
    "9e5b68df6259df67dd30bf5f90ba47d63c0adbcf385f4ffd539badc0efffe6e00ce2f84ee7fd019beb8f526d26bcd789c6859dc87ea7c779218e7fd1debafe5e"
    "e218d1dea2767b078187ebf43afee74989f1da649e1a9111f96b64c1a9793cf93978aadeacdfff0383d91ff7ffe79f3f8779c0e9f34060cf4b07b3c15cb69828",
    "0ac59340e3e0a8e3a6fc7f789f8d4b55b4e3ef1dcbd6016f22f0709d5e370fb004dfa0d86af3dca9fc6f711ee722eb800b9bd99bc7397eed3747ff02fe5f129e"
    "5dfc3f1cf4930f8978bdb1edad66625cbe15ef06fb2e3a9fd92def336a3c2c3afe5e443c87fa9def9b9a7f7d7f5729df9d95f76dcbf35123ff90e7639c2730fd",
    "da7716eb97c5467efaf6f83ec4fb9dcef73b9d60a6d0a1a3dbe7e16621b797173bd168d545df73c1fbab15947f3f46b407793e8be1419ecfb2f01459173cc8f3"
    "b1a67de07dad2c2bbff3a6e4f5e865d1f8cee36be2a9ed435e8fd5788aac0b1ee4f558d33ef0bd56507cff29a2bd45edf41e020fd7e98dcef3d11e549164b334",
    "512567d7abfd6b9becdfaacff5f9680ebeaab7e4fc0f4383da7e5e73e59516ecfb3a7d7ee088c3568520f622b5ad9d9670ea2353a5f6d045fbbe13c4fdf05e6b"
    "453b0e375cb74eb86e7c08d609c6fd8775823d78b04eb0a67dc8ff312e5541fd4ea3d973ddee21f0709d5ebf6e100492178b044dd5645384f8c6ec3aa7ee132c",
    "e11c28633fe20786b37d5df042a40feb02a7cf073edff9e861341e4e360e07f9d22851493c3c12211f680ddf6749c6bb96e5fddcd1d5b18beb140d25c867d90b"
    "a453f37e12483caddedc39ffaa95ecfc3d97dd3b1fc0b96d8ee7f5fe495288d3e7c5b8afcee7e95e2bb3cf8e7211e0f5f5e4f510e401cdfe1df2808c4b55200f",
    "c81e3cc803b2a6fd09e2fe45ed5846b48febf4cb9807ee5182ac6ff0046def389c9cd996df2f3f621d83fcfe679f0328d908cef174159e5dfcbe3d48d1f1f35e"
    "ad950c9c0ef66bbccfcfe60390dfbf06efaf2c708e27f8f5da7e835fbf5a3cf0ebad697f82b8df317e7d85ebb235c166bf3e67d97cf073041eaed3ff603e981d",
    "671aa125cb60ab3bdfedb149bcacae8ee9ae53f5e6e783ab06b335ceffc9eb7721ceeff47920ce1e66c3a193f48862069956bbc664c4f4d04571fe09e27e9807"
    "b4a29d078e2d8befccf3c3250330c460753c7fb37faf7db63e9cdac8f6fc9c276f00bf3b9edff98eb7dda2047f880964836cb672ba755014c2c0ef6bcdef58d1",
    "567ea758e0f779fc4eb1b6f3fb57c0efcee7f7067116cc6c9da43bc14a488c6c13193fe9cf413efe457b6b95a7832580d717c4035eb70a4f9175c1035eb7a67d"
    "e075e35215d4efada0f0201ea308c463acc253645df0201e634dfbff40dcbfa81d0944fbb84ebf84ef67eff5087e7a9472b9cd7335dd733d42f4db5a9eaf5ab6",
    "fffa36020fd7e925e39425a394eb1c4f735cbbccf548be4e73fd7255b6caeace5d9b5c134f6dbf34074fd55f731e5086d5332c677f5ecee4ebef6fc3fce0f4f9"
    "4138880d62d1d128bb3ff0f9533e6f2417daf4bae07bdaff0395030ec8", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70528U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
