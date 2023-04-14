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
  const char * data[25] = {
    "789ced5dcd6fdbc815a777936c5360dba0457737e897b30d52b4c95ab22d5b76faa56f4bb664c9969cd8ceb6324551126d8aa44949967d12d0a2e8718f7be861"
    "d1d32eb087a2a71e752c7aee17da4373e8a1e85fb0c74a9a195b643411638da8507a0304cff31e39bfe1cb9bf766e60d296e2e919ae338ee2b1c2a997f21fa36",
    "aedfc1f40dce5cacf2394cef5beaa4dce46e98ee23f2df622aa84a4d6cd65045961471bb5e2d887aa7a2f055f1b299a25a95145ea9e5ce3591d34543951b62b1"
    "272949b29893aa6252edabc4a54ea51aeb135d56baa2eedfe18a289c64eb554eaf1857dd95fb2b5c9f7e3ea63cff0d9bfaf153f47307f388fc59f4e7e1c79e3d",
    "43d40d8f612cfa97d6963c11d138a9a99a6771613e9b4bc4621fc492e98c47508ba2473fae495a6ca17ad9cf2fe606f7e396cd7e2e53fa791bd38ffb05819300"
    "fae331a63fc23486e98f310d23fa5c46b47d80680bf303cf709ddc17c7fc0f311fd7b924e6ff02f371bd55c6f23ca6dbf8ba2cc6e3f175a48e297788afc3b445",
    "fa4170314e1bd3f9237c3da647154c71bd85eb2d72dd31a6057c5d11cb31fd84501553fc1c6d4c9f63fa096eb78d6940c2ed613a8f71dac701620747985ed75e"
    "dfb2d4b9cbebdeeaf1f4a2d4908a22c70aef96a57e8577abc72baaf5822c5e8dc7df8f8897a0e2211e913f4b24f77b4332a3ab659dafce777d87e1490573c960",
    "c8b3bbe45df4173c3555950b6ad32356658f2c153c55be26f3058faa191eaca7ce08456598beec8e532b25e536f725fc57ebdd2feffc35e81c1e2ab382d7a4b4"
    "67d7febe41c123f647e46b673ba5bd7ddfaa3fde9077d7236b6b49754fe8eb476608ceb07e7094ba53edbb7d1c6b94fed9b5bb372c755248bcbd63e2be1f40f4",
    "c1a59f6f51dab7abbfef52f089fe88bc3bdbd017a4ce644d5778794132427549ae2594ce744dd425616271e08f23e2ed53f1108fc85fd97ebaff1ef6b4e67948"
    "d4e6b1aa6da1ea603cf8de7ffe09f1e0758d07ef50f0881d1279ba711a0e96e28db5dc8eef5c885695a5d8a11c8778f0bac483234affd8dadd0f99f9ff790a1e",
    "d117915bfcbf21f0b2d8d4c26a55e36b52c7234fcaffb747c43ba0e2211e91b3f1ff2fa86d12f6f3e73f7cfd6f1007c684e7541ca81435fd70ff222a94fd91a4"
    "ff7cb9ce0777d6421007662b0e3c0eb0b2bbaf51f088be88dc12073a4f8ff86edd07daa2e2211e91b3f1ff1d75614b017f3f1d784ef9fb7228745ef42f47a387",
    "cda5467c2b27450ef4dd299af7bb25bff229a51f76edebb6a5ce59f8f17e66602f80fef809a63fc5f467880644445b39cc27d763fe91c82c1ff026a5df773a92"
    "2ecf90945e7d527180f6ff62176f838a8778443eca7c41944b75c5d3d1549f3d1d51fac5d05f7d107900fb3e6ef7ff3c1f0f1d9e9dc4a527a9705d0e8594883f",
    "b31d991eff0fe3d75cccf6769fd97ecf5d0a1ed113910fd8efe1f505e2e547f7f3d642eb0f29acf6fbb343f0889ccd7cff21d21bb699fee738a2f493e17effe7"
    "bffa0cfcbedbfdbe7725beba163e7bbae40d9d9dc95e4df645ca1753b4cf037edf5c687eff234a7b76f5f4030a1ed113915bfc3eaf69f279b6e7c4627545a849",
    "aa925032322f90a379c3f2e076fbf7d521fd23f212ee45bec22b45f9eafcd19f46c42f0cc12772367181ae56b291e8a09d2d9fadc0fe90dbe34472734b3838cd"
    "ac070f523edd58d2a4a5867f738ad60730be073f973d7b5c98baf5c375f78960fd30989202eb0767f060fdc0a67dc81ba062ca1b70241f1040741ee7030298df",
    "c27c2e88681bf3dbf87d84e745c7f206828a5eb881bcc1b0f56747539037981a3ca7fcbf966b1efbd3b5ccaa3fcde7b2c7397de35c50a6c8ffc3f83597d7336f"
    "40bc3ce40d5e6dde8f6ca6ff398e28fd646837bf8379bffbfdfe9a9e34f81d2175f0b470b05f0885567da5b2087e7fe6fc3ee40d5081bc012a903770071ee40d",
    "d8b40fe37bf073d9b3c7d7256fc06efd70dd7d22583f0ca6a4c0fac1193c583fb069df2d7983234a3f98dad7272ab3fdfea1df0d128d0aafb9f7bb41637b5fcc"
    "b46eecfce1c19a723eeffbbf857f83ff76bbff4e788fd7ebe7c165c5bbecdd3eab2d4605b12947a7c77fc3381edc7fb3dd3d62f67ef07b143ca22f22b7ccdf15",
    "5e2f4b8a503999d4be7ffb9a78a4ad0f87e011f92bd949c72074b1e841b3763c77b74ee12f35870cc741ffffe6a3ddbf80ff1f139e53feffbc799658e763a5f2"
    "8a574847d5ec71acee3f9b22ffdfa6dcefd6714db30bbb76483b6743ce07bd67e2be1f40f401a68f98cdff6f52fa71a723e9f24ab2aa76bfeeebd6f9bf13df15",
    "4179a39ea626f15d1138f733463cc7f66f4efde9dca91c59390955723b1bd9da692422c4a6c7ffc3381edc7fb3ddcd33dbbf87ef84d2f0100fbe137a5d3c5466"
    "050fbe13caa67df0ff83fb3faef39fdfa4e0117d11f9e0fc2d99f5bbf7fce7de103c22679bbfbdb21d07fdff3bb1bbe0ffddeeff0b95d5ccbe22d78a59b51aad",
    "2bf1e54234b4b901fe7f56fdff4794f6e01c282a704e6cf073d9b03338073a463c3807caa67d18df839fcb9e3db23b07fabaac2326b58f04eb8871e1a1322b78"
    "b08e60d3fea8eb88d93847b47ae9ff7f4369cfaebeee51f088be88dcba8e300c51af3de165a998952ec4a05ec6d74d2a0eb447c43ba4e2211e91339a4fbca0be",
    "09cc23e07708c688e7543c4849854476337aa8c5ab1bd1f5f5d04ee3ec623d3c3df1a04db91fc6b5b998ecb015803c33e6439e79302505f2cccee0419e994dfb"
    "a3ee1b89963ad777dd5c9f7c7cf1e09e6474e59d4665ce617b0c1c3876aeb4fb90250ece950e5f47f6343589dfa3bf0ffedefdfe7ea5999263278de2716275bf",
    "b959d4977c4a7615ce95ced038ee1676e78a60be4fc383f9fe6878a8cc0a1eccf7d9b43f25f3fd825a578a06e7f47c7f87595cf836058fe891c85f880b89ee5a"
    "47d4c37247371cbbf5c00d4bfdaa3f377a3ca1c2f712d3ace2c2132a1ee21139abb8d0afb6eea4c241bbf9e2c66dc80bb83d2ec4946426147cba7d21559be963",
    "ad584dd7b6cfa7282f007161f073d98b0b7bccf68186cdcf3b2aa8f2cdc9f9fd51d78f9b543cc4237206ebc79ea69ccf17b5eedf027fef7a7faf9f7ab563c9f0"
    "05abab19bf9229ec2f6f3d31a6e8fb70e0ef073f972d7b6c39ebefbb3f2a06fede8ebfbffc193127fdfdf7c1dfbbdfdf97f9037f7af9e9f6a9bf10ac8557f8b4",
    "4ff4ed4cd13950f0f7839fcbdefcfe09b37d9f6f51f0881e89dcbaefa314c56642a9ed8ab2aa75e5937acfb87d4d3cd2d691a56ec52372e6dfa53269d0d1bcc0"
    "9e4f81bc80dbe34332190bfb83297db394ac1ad54ca512dc5f9ca6df99fc2fe57ebb7afc25a57da247221ff7b8be579255be9617bafbbc7941556abca4187972",
    "11d93577d85e9f8bcce2c7357f67a0a79554872763b95bf306bb543cc4237236f3902bb54d605d01ef978d11cfa9b8d1585bf6f9c5cdad7429b25e3bf4f3bbc9"
    "b0549da27cf23f28f7dbd563d352e7faae9beb938f3d6e4846de90ca8a5834070b47edb32dc0be924d3cd857628d87caace0c1be129bf6db94fbe17d327331db",
    "e106f8799b78e0e759e3a1322b78e0e7d9b4dfa6dc0f7ede5ccc79e2149c0bb28907e78258e3a1322b78702e884dfb6dcafd76f57840699fe891c8197e2fe85e"
    "83d77b3f3a93d774b568799e234a7fd9dae1d5be4d8bd29e5dfd7d878247f447e41d95e43b9e2c5f52755955b5bcda10f592ac9ee5858a289c407ef8a5f683a6",
    "0d2fd19fa3f9e1cfff7e13e282dbe382b1156d4623171799cde6922fb5e40def0417bd53f47b64a3e6877f4d699fe891c8c73daeefbdfc827c4594355177ef7e"
    "d0b079bb6494a46e9dd5f878978a8778444e39cf74d98f4f47ec476c483f88fc5af655929a6251533bbdf774f5e7f0fb63f05d8931e239151fb2e79a545d39dd",
    "7dba28158abec4e14e26b5d898a2ef4fc3f83517b3bd792ffdbb4669cfae9edeb6d4b9beebe6fae492a1a04f20d4ceb5eed95cb7ee0ba5a9788847e4a3db459f"
    "be3a06e2a07ddc85733eeef7ef1bcb27e7d9d3b2248773e193ddd3503977b2179d22ff0ef37ff373b1b5d704e4096ce2419e80351e2ab38207790236ed433c30",
    "3f17dbbcb1b3f100ce07c1f9a0d7c53f3b8d07e783466bffff861326a7", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 56168U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
