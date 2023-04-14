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
                (737429.62539351848));
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
    "789ced5d4b6fe3d615e64c334106455a02794cfa4a3349314891c0922559f6b40da0b725dbb25e1e5bf6249529899268f32191942c69532dbbc8223fa08b59a6"
    "455b4c8302193441a0eeba2dd074d1558022e8a6db665d4a146df38eee8833a428933a0730aea923deefeae0f23b97e71e1e12d752e96b04417c47f9fbf3af08",
    "e2a397464704f122a10a3969af137a41f5d726ed0a72acc90de239dd79d72678bf991c57045ea6bbb27ac0323cbddbe6cab4a81cf014479f7753153886a77879"
    "afd7a409919604b64357c79a1ac3d27b0c47ef08970e928c72c0252ea9ce0f46aad1ffd1065d392db439426c4817c3652f1f1013fb8ce421e6f73f67d03ebb18",
    "fb9088fe7efc034f43e0684f83aa329e747c332cf5f88a27393a0ab765612fbd17ebf19ea850a52f1f476899f2745657bc9eca48c3519294f0ad7017e37f8019"
    "dff306c7ff0266fc37276de8f287c3bc7a38cc4d3efec5a4fdf9a44d4edac8a4dd54dbc166481bef31663c46ed7d03335e72a2690a67e3596615def3c8f1059e",
    "aaa90aed324b5fe07d6c122f8cc5d3ebefa7768aca946a4ba287152a14eb4987f776c2114fdee75ddd287b644160cb42d74373ac8765cacac49159aaec119a92"
    "676ca1d1141acb2c3b199d4768abc9cdf31936f8f0cbe03fc3f6e1a9b22c785d4c7f46e7ddab183c12d11f34f6e960215758cbefe5dac5d8f6d1be50b817bd18",
    "477606ceac71109863bbfa77eaf5dbc48ccbe87cbb8e1c6ba2f90152f7e99d90dabe79ceeb034cff46edf6630c3e89e8476e505c6194c585c853ec0a2345da0c"
    "2ba7786579418b4c6561bcffc8245e1e8ba7d73fc5bc19fdbd33b697e71dcd601ed460da44b2d10f7cfabf7f7d097e604e7876f9814ca7150dd7929d8dbd5ca0",
    "578973bc2f71c426dde307ccde176c61fa2711bd693f70bbc6cadaa297b079de0dd221abe6dd2d0c1e89e811fe9714935162bcbe30debf82f3642aef6b865a00"
    "dffff1ce2f61ddef74bef7e6ebab1d79ebae20d61b522141d523895427067cbf3cd731a1e37bdcfd86517bbd881c13c8f7343d23f1ea42551e45081717d7313b",
    "3f52583cbdfe29d70335a64b579b82323d3c3a4b2d20be43fce1e07bb0ae773acf6ffa4f7b85569d61a37bd1d37c2b52df3bbd17079e5f5a9ec7e119b5176e7f"
    "819c6818a9c62837350da7c6eb63583cbdde0cafab16526702f0b93bf0ccf2f92b183c12d1775a74bcd9a948778b677e41c84a8555ffe111e11e3e774adcf582",
    "cf6fd71851926b8cfe771c63c669e9fc1b1e5b16af7f1d8347227ac51825c508a59a20b282d02c091d5aacb1c259a932daa737bf9e4705371e4d34bce133e269"
    "fd1fcdc0d3f4cf16df9b4ca32758cefe75c1f0f3af6f401ce7aafa03a3eb7b693bde8dc7fafdec56d71748fbbcd15c78d51b778f3ff80a73be513b0e30fd9388",
    "7e7ed7f5ed277fa1d4a0d9262dda3b4fadcbdf790e3926cebfa76a46abdd51bbe07d0586afd2dd142fcfccb3323a8ed08c71687a73f7092b9c8df3e211ece33a"
    "df1f147a4d865b6be50f56997235903aca65d3ab6e8aeb3fc09cbfc4d7ad225ed7c4f167f9934a831aef8c431c7f7aab09c47decc18338be35fd7f85391fd6f9",
    "d37fafb1799ab26c9d3f2b0eaffc708eea2ece0f5cd1b8bf367f58e51f8f6a23bbe3fec347b76e429cc7e9fc2fb6bccd13460a84b960769dcf968bfeed7d2902"
    "fc0ffcaf17fdbeafbdfccff0c0ffb3f89fe16de7ffcf80ff9dcfff75ea703de33fd86dad97c372748dca04e8406ed33dfc0ffbbed35b4d74f3efab63cb78fd69",
    "e3f766f19e369fe78149bc10164faf7750bc0fe2f473c48338bd35fd3b90cffbb428486d4eff3b70f1f4b93c873b7c3f346e431fd8c6efb536cb8e5ac8d79cb6"
    "6e979a94586bf39e9195ec5eb70ffe04717be7f3bc1cf471f9d8c166e3c82ff43b729a4ba4576517f1fc43ccf9f05cede57977917fff6b4c7f46edf536068f44",
    "f448fe0bd56cb2bd08c35362af30f67889365f911981b76adff8bb33c6a5e96b13dc5283e2ab8a23b02a7ff3fe0c7c4d6f76bd8035e46467d746fff0c96f4588"
    "eb38dd3fe47251f9347be25d2f1fed6eef96f7a88d4c5a4ab8c73f0c31e7c375ad17fd3c5cb7cc5fbc85c123113dea2f3a02530d8b22d54bb0942cd33cc3d7c7",
    "df5b547ebfd9fbc9fd19789adef43c9a62b8cbf5fd8e31e3b470fe0cbe29835f70ba5fe86f25fdd17bcd22972b67aae1622d99ee721917d5e3317b3def61fa27"
    "11bdf9fb06354254aab1022597ceef20ec7dceeb08eaf298c473ff73de5097679e785097c79afecdf27e0ed33f89e8cdf33e2fc8bbd46e464c2997765d0b1bd9",
    "5cb7e1c0b27d805975961989a778c2b9fb00512c9e5e6f2a7f676423fbe33cb0df3b473cbbea36b4c2ed0c17e81503debce86b4757e9bb1d6e97700fafc3f5ab"
    "17fd7cfb8965751aa0ae320e4faf87baca4f8ba7cab2e0415d656bfa87f5fcf45613dc7a7e80e9cfa8dd7e80c12311fdd438ce4a8d1504d5024e8de764b0787a",
    "bd593ff08e6a31cfd8628a13b091ff7f07f93fcee7ff7223982df2ac5c2d085cbccd27fde57864cb4579fb57302e7bf5f27f06bb96c5ef5fc6e091881ee17d5a"
    "140543fb16f37a3eeb8aadfb25657874d5a3b2fd84f351ea1fdb6c01ebfe2fb60f218eef74deeff2b9b37ebac945365bb184b411dd6a7504af8be2f866797f17",
    "d33f89e8e7f59e45dc3c303aefbe8519bf96d7ffdae50f1f3442ea3fe1499bb3ec3ee00dcc3848448ff803915618b0491798befa824dc9a9793d8519789adeec"
    "7dc06306b37f1fe0efbfff18fc82d3fd4270d3cbae67d773d9fde4beb47f10ac6fe75b6e7a1e00aee7e9ad26faf9f78665f705af21c704f23d4d8ff8019e12eb",
    "0c5f699c3a95ff2dceeb34725f706e337bf33a072ffd2cff0fe0ff39e1d9c5ffbdee59ea2e95a8d5d7bc954c5c289c24daeb672eaad7ec96ebd9d6fb03e2dd90"
    "dabe3969efd896f7a3ed0440decff4bc81f1d3bf93d8ff486ce4a7bfdebb03f17fa7f3fd466b3db3d762636ba791c65e6eb320b762b18a8b9eef82eb572fb8f5",
    "fd00d31fe4fd18c383bc9f79e1a9b22c7890f7634dffc0fb7a9957bee755c9f341c5687ce7e133e269fd439e8fd578aa2c0b1ee4f958d33ff0bd5e707cff11a6"
    "3fa376fa29068f44f4d3eafbe80b57a4f82c4b55e8c9f7b5f1354d8e6fd1757ede9f81afe92da90732d5a0b6d76f2e7ffb04f67d9dee1f046ae7a44c519bd1aa",
    "7fe3442afae8f451b3e7a27ddf21e67cb8aef5a29f87ef5a16e79ffd5ef6512d4b89766a9c3f89c5d3ebcdd5f9d4ac64673de7d00bef41dd06c7f3fbd9414a4a"
    "b0a7fb095f4d2cb09d93cc16dfcf4581df979bdf575c17077a56fe8738d0f4f1431cc81e3c880359d33fe4774e6f35c1bd97d76c1dcfdb183c12d1a3712149a2",
    "45799f6299eac81461b13ef99e53f781e750f76ffa3ae231c3d91ef7b91e3d83fb02a7fb039fefb47f379688a4ea3bddc2513f594edecdcb90efb984d7b32283"
    "10c47b0ce241bcc72a3c5596050fe23dd6f40fbc3ebdd544cfeb61c8f39c7c0e799ed35b4d20cfd31e3cc8f3b4a6ff21e67ca3762c61fa2711fd3cfcc06d461a",
    "e9eb22c5da3b0f8787b63dbf35fa8935029edf7a72dd57c54650b7d9557876f1fb5a37cd264e3bd59354b0d8ddaa8abe005f08c2f35b4b70fd8e04ea36c3ba5e"
    "3f6e58d72f160fd6f5d6f43fc49cef98757d5968f355c9e675bd7575db7e84c12311fd63fe6052be3aca2a96211657cff3a149bc2c724c20dfd3f4e6fdc16583",
    "d91ae7fff0d59b10e777ba1f48f03bd948f860b7cf70ddcc49b3ca65e4dd9e8be2fc43ccf9e007f4a2f703f72c8befcc5a872b06e0a8eee278deecfd610c8ba7"
    "d79bba3f1cdbc8f6fc9c47b780df1dcfef62cbdb3c61a440980b66d7f96cb9e8dfde9722c0ef4bcdefc4beadfccef0c0efb3f89de16de7f7cf80df9dcfef75ea",
    "703de33fd86dad97c372748dca04e8400ef2f1cffb5baa3c1d2209bc6e100f78dd2a3c5596050f78dd9afe81d7a7b79ae0deaf85c383788c2a108fb10a4f9565"
    "c183788c35fdff0d73be513b5298fe49443f87e7676f7728715c2abfd414852af2bb8e31e3b696e72b96edbfbe8ec12311bd629c926294524d1059416896840e",
    "2dd658e1ac5419596571753587cf88a7f57f34034fd33fa31f50a7d5132c677f5ecef0f3af6f807f70ba7f90b6e3dd78acdfcf6e757d81b4cf1bcd8557bd2e7a"
    "9ef621e67ca7bc57b189199fd179771d337eedbd293a3e1ca442ea3f29cbd6ffb3d6e3524b9447ad53f3ed23583cbdde4c1dd6918dece7f710bc2f658e7876f1",
    "7b60335e6b7883a9934cdc9f92b3399eef44632ecabb84eb572ffaf976c7b2f5fd0f317824a27f2cbf32267014c3c7d1f7a5e3fc9a5d7593cdae0becaa9fa633"
    "a0bdf5d3fef2df32acef9dceff6c9aab72a7229d6e460fe40da15dad1db61917c57fe03a9e3e7efdbc0b5ab69e873a39aa409d9c5978aa2c0b1ed4c9b1a67fe0",
    "f3e9e3d7cfbbf7cef9dc6c1dccb7307824a247eb607604a61a1645aa97602959a67986572b612e2a7e7fc5de938cdfdf9f62387bdf7b4e0cbe8175bde3fd407f"
    "2be98fde6b16b95c39530d176bc97497cb405c6749e23a6f87ac9a6f2f63f048448ff03f8dc6738e4d8ee369f376ae58fd0449191e5df5a86c3fe17c94fae9c9",
    "5281b8fc3b8e31e3b4308ef3c5f621f0bdd3f9becbe7cefae92617d96cc512d24674abd511bc2e7adf15f0bd5ee6f5de93ef63f048443ffdbd27da6eede2d6f9"
    "66ef0f0defe75bf4de136dced89897f3e9bfff03fbb65795ef5fc1e091887ea3bd53f0eefb336131e58ff3c5ad7c90cf0709e0fb65e3fb8f30fd19b513bcfff6",
    "c9f8cbf71e3578ffed3cf1e0fdb7d6f43fc49c0fd7b55edc7e9fa0e1dbfd7e44b84fb01a4f9565c183fb0473fdff1ff81312a6",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70568U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF2_info.c) */
