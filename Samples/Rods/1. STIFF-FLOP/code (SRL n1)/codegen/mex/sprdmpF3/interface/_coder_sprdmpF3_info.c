/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_sprdmpF3_info.c
 *
 * Code generation for function '_coder_sprdmpF3_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sprdmpF3.h"
#include "_coder_sprdmpF3_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("sprdmpF3"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (8.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/sprdmpF3.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.88287037041));
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
  const char * data[23] = {
    "789ced5d4b8ce34819f6ecceac66b45ad60760b542026640235683da79f50bb19047e7d5ddcea393eea433b374db899338ed576ce7d51772e4c061b970e23047"
    "1609b47061a445287be7ba1ce03242e2c615ce3889abbb6da526e9b6e3b4dd55524f75f56fd757fee7f7f757fdf530762f4ddec330ec6bdacffb3fd7fef91b36",
    "49ef4d330cd7f3b7306332cbefe9f9135319a407d87dc37df774bcdfe8e5aa28a84c5f9d16385660321d9e6664ad20503c73514d4de4598112d4e24062309951"
    "44aecbd426923acb31459667f6c52b8514ab15f8c415d145612c1aff1e6b32d5b34287c7e4a672d95cee6a01d3f5334e9f439efffe82fac941f4839be4cfe39f",
    "104d91678826556309329e8c2803a14aa4c6a54847158b647167201031b1c65c2d47199522bafe351f511d4b1449aef15222b8c683f69f42daf7ce82ed37e720"
    "3dc21e5e29fd383c0f6f517dbd0dc1c37549559cfe47d985f78ea97c893795d4c40ecd319778bfb5881781e219e5cfd3fb65cd243a8a4c706295e2083252dc8f",
    "44898380cfbf4513aa2872b4d827189e23389626784ae5289a60b87a47d04c4159e3f57a1cb4832f0f9f7e1571d6ee1c7dbe95e2f521f52d6a77df84e0e126b9"
    "54ecb736b36a6e63334b150bada29c1c5485e8653b005fc170e6b50383949daa1fbdbfc664b4b7ef5ff0f81052dfa27afa1082879be463b725afb15a67401628",
    "6e4dd15445c96b80e5adf3bc39c1da03925d7e9f9c8307e4d7b093f1cfb389be88674061c4b3a9c62e6cc6397b096ffcfa33c4f76ee7fb2d795fa1f255f2b844"
    "1f97e9687423546f3088efef1cdf7f0aa96f513d7d04c1c34d7213df5392c40d0a130a4b7484aaca8a425ac87154150c0141fb248bed7b7f4efb80bcaeb7e2a4",
    "490935ade30ff04716f15fccc10772abfe00aed0a98939675f23faddd6df917f58129e53fe41a4f65b34452563b5e0564b290718b2220d76bce31f4690fbd17b"
    "6d4c463bfca16df19e87a6327671dd54c22a8a44c90ae3d6784f0a8a6794dfacff30d6cdb80701b4e464dc2ffcf0e39f217e773bbff74a6925c19d1d250275b9",
    "c0755bd95de13c1f43fc7eb7f97dcd7371a09bf23f8a03cd6e3f8a03398387e240f6d46ff53dce99ca98e93a205fd63cee4b48fb16b53b583ffb919e870d7f25"
    "f5e24ff53ca6e7493dff58cfc3d37c08f2a86de3820790f6e2ba44127b93d5026e1d172c37ae284a0a31d1d00ae28ac35f7eb581c6056ef707a5e611b351c817",
    "d60f8af94e7967af7224160e3d342e70ebfb0b8b832f6a6f6f99ca20013f801bfefa343ccd9fd8361ef80e041f37c94de301568976584e4d0b990ecfc86c7565"
    "bcffca22de0114cf28b73a1e302b0c1892837ee0cffffd071a17b8dd0f64bbed58a49eea6e15f3a14135ce0b8144854b79c70f581d17ec42eac74d72cb7ee071",
    "9d5341a71773d8ee8664d82ebbfb0082879be433e341f1866be3404bb09399bc0f14b502beffc353341fe07abef71d34fc5d75775b941b4da590a01ad144baeb"
    "a1f95ef41ecf6e3f8cef61e38d45f5f59ea98c99ae03725611a61d5575bcd3c3bdf1fe3414cf28bf667fa0cef6999a246ae6411834b58a7563bf2f7d88faf56e",
    "e7f964f06c506837582e568c9d1db4a38de2d9611cf1fc9de579189e7deb78eaac36a869ba355ebf03c533caadf0fa54438ecff7233e5f229e553eff06040f37"
    "c9bb6d262e75abca76b91714c59c52f0078f2b9877f8dc2d71d74b3e7f5c676545adb3c6e73885b4d356fb1b9dda16afff36040f37c935659c684a38a98b3227",
    "8ad289d865e43a27f64eaae3fdd6abdbc735ba211ea8bf32070fc86fb8ff636a466fd09cf3fd82d15ffefd00c5716eab3f58b47fafecc5fbf19df3f3dc6e3f10"
    "2203be583ee2f7c5bde30f5e43ee5f548f4348fdb849bebcf7faf19b2f3869329cc4c8ceda69d2b6f1c07d5319bbb86e2a19f776c7f98ae71558a1c6f4d3827a",
    "d18e9716db119ed30e20b7364e70f47c8f57681ed7fdfea03090587ebd7d50f2b3742d94aee473a4df4b71fd9790fbeff07bab259f67e2f8f3fc49b5494d66c6"
    "511c7f760e128afb388387e2f8f6d4ff1a723feae7cf7edec5ec346d5b3f7f5e1c5e7b709eeaafce0fdcd2b8ffc5f91fda2fc454478e9fcff0ea834728cee376",
    "fe97db3ea9c52aa108bf91db14727439b877a47868dfd66bc8fd88ff673fef42763a7496ff5901f1ff3cfe6705c7f9ff0bc4ffeee7ff0675bc990d9632ed4d3a"
    "a2c6d6a96c8809e593dee17f34ef3b3b07c9607faf4f6de3f5ebc6efade25d773dcf4b8b7861289e51eea2781f8ad32f110fc5e9eda9df857c7ecec8a2d2e18d",
    "cf018ba72f651feee8457892873f718cdfeb1d8e1be768bde69bce5d1b6bc9e97efbf08f286eef7e9e573702fcc14e29d9ac04c5f3ae4af209d2af7a88e73f87"
    "dc8ff6d55eb5bbcbf5f7bf80d4b7a8be7e00c1c34df259e72f475981924d87cfd9356fbcea73979fcfc107725bceef9ba5487d66d741fff0a7cf6414d771bb7f",
    "c8e763ea59aee5dba42b99bd0c5da4b6b2a492f08e7f1841ee47efb53119ed70d3367ff13d081e6e929bfd4557646b1159a606098e5255466085c6e4ba55adef"
    "b73a9e3c9a8307e496ed6886e2c626e4a0fd0cff4723bfe076bf70be9b0ac60ea5329fa7b3b548b99e22fb7cd643e7f1587d9f8b90fa7193dcfab8611a213aa9",
    "7322a59e5c8c209cdde75541e7f258c4f3fe3e6f742ecf32f1d0b93cf6d46f95f7f390fa7193dc3aef0ba29aa1325939adbdda0d103672f8dc86926df300f3ce"
    "596615811230f7ce03c4a07846b9a5f53b631d391fe741f3bd4bc473eadc8676a493e5438372c87720073a313fb3dde5339877781dbdbfc6b4acefeda2739561",
    "7846393a57f9ba78d37457f0d0b9caf6d48ffaf3b3739060fdf921a4be45f5f62d081e6e92cffede569d13c5a906dc1acfc942f18c72bbbeb735d198e6041ce4"
    "ffdfa1f53feee77fbab9912b0b9c5a2b887cbc23a482743cbaeba175fbb7302e7bfbd6ff0c33b6c5efbf0ec1c34d7213ef33b22c2e346fb1acfd59b7acdfaf68",
    "cd636ac494ed75ce3753ff44672be8f7ff75ef18c5f1ddcefb7d21df3b27253e9a6cef2494add86ebb2bfa3c14c7b7cafb395319335d07e4cbfacee229a47df6"
    "dadd4f6c8bdfbf0dc1c3758932de7c8bb9377e1f81e219e5378dff8d57f12b60f32de624ff84bf3c7c8afaf16ee7738a4a452bbdb3147b44c63a5c342aec6ce6",
    "321ee273f4fe1ad3b2e2f7d6be930e587e75eb30adfa7d720e1e90db15b70136e39cbd8cc2e83be9eee77bdf7a6a632bd62b057cd15e8ff3495c68a771eea1f3"
    "7610df1b138cef3f85d4b7a89e3e82e0e126f9acfd5ac68d086921c7515546bfde2bfbb65eccc107725bf677cc54a8e3e7f1d0efb6507cc7edfe41a4f65b3445",
    "2563b5e0564b290718b2220d3c341e1841ee47efb53119ed70cd73e3849bc683d0386176fbd138c1193c344eb0a77e14e79fddfe657d4f655e9c9fa295498ee2"
    "fcf071a3a6a3158c1b472314e7773f9fb769ba560f4974b6982bc879d19f4c72fb210ff1397a7f8dc9686fdf45ebf4f5bfdfb2f53a689dfe2de161a7f1d03a7d",
    "7bea47bc6f4cb0ef670d21f53913b701bd7b34bfbb68dc06d88c83fdfc5ffdf34788efddcef7adf564be51cb1fa5b71319fff6119d5f6fd47331c4f7778defad"
    "9eaff60482879be4f3e777a7d7dd96795dabfdffc339f840be84f91fa7fdc1bffe83ce5b73bd3fd83bf29f89a1f33a55ebf54a078110b99d383cf6d077d4d1fb",
    "3c3b07c9687febb6f90774fee634a1f3379786374977050f9dbf694ffdc81fccce4132da5fca73f1a19bce0ba0f8d0ecf6a3f8903378283e64adfeff031a6ed5"
    "5a", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 52248U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_sprdmpF3_info.c) */
