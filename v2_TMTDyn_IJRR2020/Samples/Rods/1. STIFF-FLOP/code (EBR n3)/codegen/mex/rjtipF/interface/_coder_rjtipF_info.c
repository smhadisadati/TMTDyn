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
  const char * data[27] = {
    "789ced5dcd6fe3c615e726bb69b6405aa269f381b6e93a5d6c93eec6fab46507452b591fb66cc9922c792d2b49654aa224aef9659292259f0414287ae8a1c71e"
    "fa07f4904391538f027a29726e9aa228d01c7a08fa17e4d0432971689bb39a15371a51263503184fc347ce6ff8fcf8dee39be10c752b9dbd4551d4b7f4bf17f4",
    "bffc57d4b8bc62108a06f405ca5a60fe2d40df85ea66b943ddb65c67f2ff00685d1235b6a719159e13d9fd8e506315bd2232027bd94c4312389111b5525f6629"
    "855525becb36c69c26c7b3254e6033d2b5ca0ea75784d435d66565c41afd8eb7d9fa69b123504a5bbdea2e7fbd425d93cfef11f77fdba67c2208f9d010ff83e4",
    "47f1f77d872aaba83e550d44821b415f82554f3549f60556ef154be954eabd542697f7d5a506eb539e689c9c5a152efbf9c5adc9fd78c9663ffd887ede057460"
    "611c470dba05e811a03f33e8c0acff1cd4e3a0fe0b40cb804601dfacc7401dd028c0199838154013e0b8594f029a02c701a5b6411d50ea434077c07140a934a0",
    "bbe0b8493f02c7f740dda419703c0bea80525540f701cd013ea0541edc17a04340a902380ee41605f21880fb8f82fb1c7e1835ffdf27c6855f5b2fbf01d5a9cb"
    "f30c8ed2e0ba5c83a570e1bd04d5aff00c4e43ead478f6eab9fbd38c7869249e95ff413a531e3f7a79456a298c706f6423545f3656cac4b67c07417f2052f369",
    "92c4d7a49e8f15781fcfd57c02a3f14ccd27c9aa0fc8497f128d324d5e769f47989ae52ef532f83578fd9b85cf62cee1196559f07a88f6eceadff7107834c4df"
    "382f340fcbe1f5c84e973fd84c6c6c64a4c3fab57ee4a7e04ceb0785a83bd5bedb9f6319d13fbb7af70254378be95769cbd1b7a3067d7069e70788f6edcaef47",
    "087c1ae28fa20a6595d383324564f8554eddea70bc9616f5b08c55b8fac2fcc09f67c42b23f1acfce7d69fd1dfc3b1d47c0f4db1f960b1ad0a0efa831fffe79f"
    "c41fdc547ff01a028f86f8b9ee593cd6dce96e940ae17e3d2988c15485df21fee0a6f8831344fff0eadd4fb1d9ff7b083c1ae243f65fad333cdb93e39220331a",
    "a75be445d9ffe18c78c7483c2b1f8ffd7f4a6c8bd09f4f3f79f5efc40fcc09cf293fd06ec84aa57c91acb722894ca41fea30b1c2c616f103cbe507de8fe2d2bb"
    "ef20f068880ff901fdee8de36ecd03ed21f1ac7c3cf65f1717d01462efbd81e794bd6f6d6df51b91503259e905bb3b7b252e71ac1c7828ee77cb38ca6f10fdb0",
    "ab5f7710fd34f33def588efe323a26514007800e01a5aad8f2fda87ed180234be7e3d1b745d9f93fce88b78dc4b3f2678d07c672baa62f27887e61cceb7cf597"
    "7562dfdd6edf8fda8fd9f562a1b876502a74ca89bdca63a97818f78e7d77ebf34bf2fb24bf4ff2fb93f08cb22c7824bf8fa7fd59dfd7f3509d82ce33f998fcc0",
    "4a93d7c63f1dd5bb41165b5ee775041e0df127e4f71925d9726d5e676e7a82cceb8fc4e5a8bdbffbdb7f117bef767befdf3f8f08254ea8ec71078de45ea25e6c"
    "36fb248fbf44cf3165b1f7a8f70dbbf27a05aa53d079269f53452344d54633a7dd9bbfcf21f1acfcaf150f34b91edb90255d3d7c1679399adfa1de4cbd49ecbc",
    "dbedfc76e8b45f3c6b717cbc143f3d38db6a954e0f930962e797d5cea3f0eccaeb65a84e5d9e677038b5c9e9af336db7daf55d249e953fbb5d37e4640ee013bb"
    "ee0d3ca7e6e777cfd8a4dcadab9be5f39024e5d56220745ca1bc63d7dd957fbdb2eb2b4d4e51b526e7a8fe0d4fb0e5eddf42e0d1105f174355bffd6a53527849",
    "92ab5297559abc745ead8fbe639c3dae870baa3f66c1352ff304aac378267f963c1f50a367c8cfd17ccec79fdf21e3b837d51fd88df3d5bd642f99b8b8c8eff6"
    "82e16cd01f2fc402fea477fcc19788ebedcaf1d788f669883fefe77ae5d92754db2c2f8f26bc38abafdbd8de0f6e4375eaf23c83338a7b4774c1e30c9cd8607b",
    "6951c3364f2035a51f261fc77bc3e89dc141fdb84fc677ddef1f8a7d9913d6ce0e8e025cad114e570af96ca0eba13c10797eadc5aa6f7ecfe4f9a7f9977a9b19"
    "4d1725797e04350bc907398347f2fc78da27f1bfb5bf78f5358d2dfe9f96afd76f5d607aeef507731d1f30f588d77ff80c49393f3e30b8ffd25d920f72bb3f50",
    "cefcf2134e0dc784f57c44ccd7caa1bdc7aa87e6f7107f60ed2fdef16267fd0127127f60cf1f70e202fcc14f883f70bf3f6831c7915ce868ff2c528b69f13526"
    "1766c3856deff803325e3c999ac5a27f5f9c60b3efcf9bef9f15cfe9ef773d9c172479fd39e291bc3e9ef6678dcff2509d82ce33f9aefe6e8bba9adf895a27c2",
    "aebcde81ea14749ec987c6531959e6fb5b9cc828fde2d8b7a53a625de32411d7b8c3b7a7f4cbe437016eb5cd880dfe6a9de8bfce88cf4cc137f978e203a43817"
    "b19ef367ff23eb3cb8de4f5cb08c1413f74315add50a6efbb3b9c6e151c0437e6288b8deae1c2b88f669888fcb4f186f00d5262f315ad55ce48672580f8715f2",
    "bdef8c78738b2f6eccf723e47bdf79e291ef7df1b43f6bfee708d13e0df171d97f51d2f699fd9c92d61fed966efc9dcdef1f61cbff4c5bbf8d534546a4dcfb9d"
    "af13ebb982fcfe48528b88ef491e688e784e7d0f7616ebe48470bf1cf61f28c14e3cc06e76857dca3bf69d3cc793fb6fd5bbfbd8be0323ebb7a1f0ac7cb27edb",
    "f3e2196559f0c8fa6d78da27f1fd646a16547c3f40b467576edf47e0d1107f625e67b5c94b9291d872ab1f3844e259f978fcc043436ebeb1dcc63184837ee035"
    "f21d80fbfd40adbd9e2f8bbcd6284a42b223ee846ac9ad5d0fcdf3b9b1f9da9b341e3cd8c796d7ff2e028f86f890fd671545b2ccb33c99b11fcf3baff346c6ff",
    "aade49b6e133ac3eb0fdb00b184bced1f85f1a3e20e3bb6eb7fb62e9b8c0048f772aa16eb7932c7703216197f3d03afe6ed9a7e504d10fbcfa856fff95a9fbad"
    "b3bad192ddbbdffadcf6d97a2aef0724e5f83e5b83ffaefe9bc4ed6eb7df69ff93cd4e3f1612fd21fffeb91648d6d91eefa1f57bc8733cb9ff56bd7b842d6e7f",
    "038147437c286e1719a5c589f5f6e9acf61e2ea87e9805d73cae0fa7e0997cec71fba5e40cc571d0febff8e8e06fc4fecf09cf29fbdfef9da7379954b3b5e6af"
    "e79252f149aa1339f790fd1f22ae77eb738dd20bbb7af822e27eccfdb9deb01c7d3b6ad007803ec216ff4f9bbf6366f0dd1aff3b33eedfec88d772f6a3e2a0bd",
    "7a2ff180c4ff6eb7ff1b67915ce98c4fac9d6eb54b85eda2769648d453deb1ffe4399edc7fabdedd23f377a81b9cbf27f3772ecbb2e091f93b78da27f67f72ff"
    "e7357ff3a6ccdb818bdd3c1099b733999a85ccdb71068fccdbc1d33eb1ff93fb8fb2ffbf43b467575eef22f068883f691d07eb92036931cf3375169c6ff64f9e",
    "b17f8b5ecfa13605dfe4635ccf61a25817b0ff57e87c8dccf771bbbfc8eceed58fcff29bb1e36c5851833217ec46763db49e0379be27df973d7d5cf5dc7bc4a2"
    "f248e43d625e784659163cf21e81a7fd59df2396631ed1faa5fd9f753db815041e0df1e1f708556515ed31c3738d2277c1c69416386f517e603823dedcd6879a",
    "1c4f3c25be05c4119f7ef22a794f70bb3fc872b574713759917784ede4e6e656a17b7eb1e9a1ef028688ebc9736d2dd6efc3a2649c9922e3ccd7fb6de3fd808c"
    "33cf118f8c33e3697fd6bc110bd529e83c933f3f7fb0c2a923bede284f39ac8fd163c7e6958e6eb2499179a576d693d22545d685f3189e53f67ead97e553a7dd",
    "c693f47ab9b7db508261b1b84ee6952ed1733c2a645d3812ef5bfb4de2fdc5e291781f4ffb1e89f76b52476ca894d3f17e019b5ff821028f86f84ff905b0405e"
    "9cd76543b977bda0c7483c2b1f975fb82e3687f70dfbea36d90fd2f57e212566f25bb1a3fd0b4ee8e59ec80d21a7edf73d342e40fcc2e4fbb2e7170eb1e581a6",
    "c5e7643f78b21fbc15cf28cb8247f683c7d33eb1f793efcb963e0e9cb5f764bf77b2dffb4db1bf4ee391fddef1b44fecfde4fbb217df3fc696f7f901028f86f8"
    "70de476cb0bdb4a81db0bc248ff88bface78f835f1ccf64fa03a8c67f2b1af4b6591a0a3e3028761918c0bb8dd3f6432a978249655769b194115f2ed76ac1cb8",
    "f0d0fbc09788ebedcaf15788f669883fefe77ac5d821b83ecaf356eb92a8319ca856cd93ccacb9c3fafa058bcd7fbc89c0a3213ee43fc652c9eac778c077ebb8"
    "c10112cfcac713875c896d01ef15e4fbb239e239e537ba1ba17084ddddcb35139b5a25c21c64e29ce0a1f1e47f20aeb72bc71e54a7a0f34cfedcfd06a75655ae",
    "25b20dabb370543f87759257b28947f24ab8f18cb22c7824af84a7fd21e27af23d99b558f5709bd8799b78c4cee3c633cab2e0113b8fa7fd21e27a62e7adc53a"
    "4e9c25f3826ce2917941b8f18cb22c78645e109ef68788ebedcaf118d13e0df131ae17b4d26594f1a6335559911ad0fd9c20fa8b570faff23603447b76e5f716",
    "028f86f8ba48aaba25ab3625859724b92a7559a5c94be7d57a9bad9f92f1e167ea8f11363c437e8e8e0f7ffcf91de217dcee17d4bd642f99b8b8c8eff682e16c"
    "d01f2fc4027e0fec47f67f8abadc26", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 63592U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
