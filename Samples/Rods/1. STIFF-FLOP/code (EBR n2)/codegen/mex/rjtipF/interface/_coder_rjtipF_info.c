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
    "789ced5dcd6fe3c615e76e7637bb05d22e9a36c9a26dba4e17dba4bbb13e6dd9413f2cebc396ac4f4bb665a5854c8994449b1f3249c9924f060a143df4d0630f"
    "fd037ac8a1c8294701bd1439374d5014680e3d04fd079a430fa5c4195be46ad6dcd58812a919c0180d1ff97ec3e7c7f71edf0c67a81b89f40d8aa2bea9fdddd4",
    "febef82f352cafe915751fd437296331d36f80fa3d531b96dbd42dc37590fe4750d7245165bbaadee03991cdb4852a2b6b0d9116d84b368c2470222daac55e8b"
    "a5645691f80ecb0c29758e678b9cc0a6a491c636a73584f808e9b231200d7e479a6ceda4d01628b9a95c75971f6d5023f2f903e2fe6f59944f08219ffb803fa4",
    "7f18fb55e403cf9ec2ca8a47517c21ff9adf13659513556a797ccb0f0bc5443cfe7e3c95cd796a12c37ae463956bc59785cb7e366f8cefc71d8bfd5c42f4f31e"
    "a8ef1a083fdfd0eb5550afe9f5c50668af83fa0350ff14d43f03f52fc0f961506f82e311d0063515056d505331d086751c1cdf026d5053dba04e80e3a0a692a0",
    "0deb1d703c05daa0a6d2a0ce80e3a0a6b2a0ce6f40b91fe9075e5a3f5e35b5a9cbf35e1df29719aec3312c850bef8ea97d857767c89f91da559ebdd2ff3f4f88"
    "9740e2e9fc21fdc344aa347c0472b2d49069e1e1e059553ce9703115def4ecfabdbe50d5a34a125f95ba1e56e03d3c57f508b4cad3558fd4523c404eda13a197",
    "ebe465f5b930d7b0dca3ee825f176f7e23ff59d83e3cbd2c0a5e17c1cfaafe7d178107f50fd2d7cef2f5bd527035b4dde177d7a36b6b2969af36d28fdc3538d7"
    "f58342b4ede2eff4e7b885e89f55bdbb696ac302fddb7dc3d17736f4faf1a59dbf40f0b72abf1f22f0a1fc207de0dde5654e0b8e6491e6973965b3cdf16a42d4",
    "c22356e66a33f3039f4c885742e2e9fc21fd85f567f0f7642835cf1328368f596ccb828dfee047fffe07f107f3ea0fde40e0413d84f46ce73412ae6f77d68af9"
    "60af1613447fbccc6f137f302ffee008d13fbc7af7136cf6ff21020fca0bd24df65fa9d13cdb6d4524a145ab9c66916765fffb13e21d22f174fe908ec7fe3f23",
    "b659e8cfa71fbffe77e207a68467971f68322db95c3a8fd51aa1682ad40bb4e9707e6d93f881c5f2031f6ce0d2bb6f23f0a0bc20dde407b4bbd78f3b350fb483"
    "c4d3f9433a1efbaf890b680ab1f7eec0b3cbde3736377b4c28108b95bbfecef64e918b1ecabb2e8afb9d329ef15b443facead76d443f61bee75dc3d1dcc6b0da",
    "00f505a8fba0c698ef47f5ebbe4619e6b9a4b3e128d8acecfc9f26c4db42e2e9fc217dd2786028a7117d3942f40b635ee7ebbfac12fbee74fb7ed0dc67570bf9"
    "c2ca6e31df2e4577cafb52612fe21efbeed4e797e4f7497e9fe4f7c7e1e96551f0487e1f0fff49dfd773a6363572de68ff31f981a53aaf0e7fdaaa7717696c79",
    "9d371178505e903e26bf4fcbb18663f33a53d313645e7f202e5bedfdbddffd93d87ba7db7b6fe62c241439a1bcc3ed32b19d68ad50aff7481e7f819e63ca60ef"
    "51ef1b56e5f59aa94d8d9c777384ce29a21ea2aa8319cccecddf6791783a7f487fa978a0ce7559a62569eae131c8cbd6fc0ef520fe80d879a7dbf9adc049af70",
    "dae0f8483172b27bbad9289eecc5a2c4ce2faa9d47e15995d75d539bba3cefee903fa7d439ed75a6e954bb9e44e2e9fc217d72bbaecb090ee013bbee0e3cbbe6"
    "e7774ed958ab5353d64b670149ca29055fe0b04cb9c7ae3b2bff7a65d797ea9caca875ce56fdeb1f61cbdbbf8dc0837283744d0c15edf62b7549e625a955913a",
    "ac5ce7a5b34a6df03de1e471bdb9a0fa030bae799947a6b6190fd227c9f301357a8efc6ccde77cf4f96d328e3baffec06a9cafecc4bab1e8f9792ed9f507d37e"
    "6f241ff67963eef1075f21aeb72ac7df20f8433942fab49feba5e79f5069b27c6b30e1c55e7dddc2f67e70cbd4a62ecfbb75f97e3068cf789c811319b69b1055",
    "6cf304e2d7f403d271bc370cde196cd48f47647cd7f9fea1d06b71c2cae9ee818fab32c144399f4bfb3a2eca0391e7d7588cfae6754d9eff3aff526bd283e9a2"
    "24cf8fa86121f9207bf0489e1f0f7f12ff1bef0bafbe26b0c5ffd7e5ebb55b17e8ae73fdc154c707a01ef1da0f8f2e29fbc7072e1eddb947f2414ef707f2a9b7",
    "75cc29c1b0b09a0b89b96a29b0b3afb8687e0ff107c6fbc23b5e6caf3fe044e20facf9034e9c813ff831f107cef7070dfa30940d1c644e43d5b01a59a1b34136"
    "98df728f3f20e3c5e36b580cfaf7e51136fbfea2f9fe49f1ecfe7ed7c5794192d79f221ec9ebe3e13f697c9633b5a991f3269adf394fdf6d5157f33b51eb4458",
    "95d7bba6363572decd11ba693c956eb5f8de2627d272af30f46df1b658533949c435eef0ad6bfa05e975805b69d222c35fad13fdd709f1e96bf0211d4f7c8014"
    "e72cd673feec7f649d07c7fb89739696c2622650561b0dff96379d65f60e7c2ef2137dc4f556e55846f0877284745c7e427f03a8d47989562b70911bca663dec",
    "97c9f7be13e24d2dbe989bef47c8f7bed3c423dffbe2e13f69fee700c11fca11d271d97f51523374262b27b447bba1197f7bf3fb07d8f23fd7addfc629222d52"
    "cefdced78ef55c417e7f20a959c4f7240f34453cbbbe073b0db7b342b0570a7a77657f3be263d73b4286728f7d27cff1f8fe1bf5ee11b6efc0c8fa6d28bc698c",
    "0791f5dbdc8a47d66fc3c39fc4f7e36b5850f1fd05829f55b97d0f8107e506e963f33acb755e92f4c49653fdc01e124fe70fe978fcc0135d6e9ea1dc8631848d"
    "7ee00df21d80f3fd40b5b99a2b89bcca142421d616b703d5d866d245f37ce6365f3b4fe3c117196c79fdef20f0a0bc20dd64ff5959960cf32c8f26ecc78bceeb",
    "9ccbf85fd13ac9321eddea03db6f760143c9d91aff4bfdc7647cd7e9765f2c1ee669ffe17639d0e9b463a58e2f20243917ade3ef947d5a8e10fdc0ab5f36eeb7"
    "ce6a46abe5dcfdd6a7b6cfd633793f2029dbf7d9baf8cff2bf48dcee74fb9df01eafb77be180e80d783367aa2f5663bbbc8bd6ef21cff1f8fe1bf5ee29b6b8fd",
    "2d041e9417a49be27691961b9c586b9e4c6aefcd05d50f5870cde3fae53578908e3d6ebf949cae3836daff579eeefe8dd8ff29e1d965ff7bddb3c43a1daf3756"
    "bcb56c4c2a1cc7dba13317d9ff3ee27aa73ed728bdb0aa87af20ee07eecff596e1e83b1b7afd18d44fb1c5ffd7cddf81197ca7c6fff68cfbd7dbe248ce7e506c",
    "b457ef471f93f8dfe9f67fed34942d9ef2d19593cd6631bf55504fa3d15adc3df69f3cc7e3fb6fd4bb8764fe0e35c7f97b327fe7b22c0a1e99bf83873fb1ffe3"
    "fb3fadf99bf3326fc75cace681c8bc9df1352c64de8e3d7864de0e1efec4fe8fef3fcafeff1ec1cfaabcde43e0417941fab8751c8c4b0e24c41c4fd758703eec",
    "5f6bc2fecd7a3d87ea35f8908e713d87b1629dc1fe5f81b31532dfc7e9fe2295dca91d9ee6d6c387e9a0acf85b9cbf134aba683d07f27c8fbf2f6bfab8ecbaf7"
    "8859e591c87bc4b4f0f4b22878e43d020fff49df2316631ed1eaa5fd9f743db825041e9417a49bdf23148595d57d9ae7980277ce86e506386f567ea03f21ded4",
    "d6871a1f4f3c23be19c4119f7efc3a794f70ba3f4873d54421192bb7b685add8fafa66be7376beeea2ef02fa88ebc9736d2cc6efc336c8383345c69947fb6de1"
    "fd808c334f118f8c33e3e13f69de8835b5a991f36e8ed0a7e70f96386540d798f294cdfab87168dbbcd2c14dd62932afd4ca7a529aa4c8ba702ec3b3cbdeaf74",
    "d37cfca4c31c27564bdd2423fb83626195cc2b5da0e77850c8ba7024de37f69bc4fbb3c523f13e1efe2e89f7ab525b6414caee783f8fcd2ffc008107e508e9cf"
    "f805b0405e84d764433977bda07d249ece1fd271f98551b1d9bc6fd8d7b7c87e908ef70b713195db0c1f64ce39a19b3d6e314256cdf45c342e40fcc2f8fbb2e6",
    "17f6b0e581acecff4bf68327fbc1cf8bfdb51b8fec078f873fb1f7e3efcb923e5ed86befc97eef64bff779b1bf76e391fddef1f027f67efc7d598beff7b1e57d"
    "be8fc08372847473de4764d86e425477595e6a0de8b3faceb8ff927890ff91a96dc68374eceb52192468ebb8c05e5024e3024ef70fa9543c120aa7e5643d2528",
    "42aed90c977ce72e7a1ff80a71bd5539fe1ac11fca11d2a7fd5c2fe93b04d70679de4a4d12559a13950a3c0966cd6dd6d72f596cfee301020fca19d24dfe6328"
    "95b4768c0774a78e1bec22f174fe908e270eb912db0cde2bc8f76553c4b3cb6f74d602c1109bdcc9d6a3eb6a3944efa6229ce0a2f1e42f10d75b9563d7d4a646",
    "ce1bfd3f4ddd6f704a45e11a22cb189d85adfad9af91bc92453c9257c28da79745c12379253cfcfb88ebc9f764c662d4c32d62e72de2113b8f1b4f2f8b8247ec"
    "3c1efe7dc4f5c4ce1b8b719c384de60559c423f38270e3e96551f0c8bc203cfcfb88ebadcaf110c11fca11d231ae17b4d4a1e5e1a63395962c31a6fb3942f417",
    "af1e5ee56d2e10fcaccaef6d041e941fa46b22a96896ac5297645e925a15a9c3ca755e3aabd49a6ced848c0f3f577ff4b0e139f2b3757cf8a3cf6f13bfe074bf"
    "a0ecc4bab1e8f9792ed9f507d37e6f241ff6795db01fd9ff01c467cf3f", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 63472U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
