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
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/rjtipF.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737431.0044212963));
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
  const char * data[25] = {
    "789ced5d4b6fdbd81566d26490a0989640dbc91445a7e36911b4c8c09265d9b20b14b09e966ceb65297e6566144aa224da7c89a464499b6ad9c52cfa03bac872"
    "5ab445da451b60060375d76d814e175d0528e627b4eb52a2689b37ba11635294499d0304d73787bcdfe5c1e5770e0f0faf885ba9f42d8220bea5fefbcb2f09a2",
    "f31f62246f6b0d418edbdb845150fdad71fb10e9eb7297b86338efd618ef37e37e45e015baa3681d96e1e94c8b2bd392dae1298ebe18a62a700c4ff14ab12bd2"
    "8444cb02dba6ab234d8d61e922c3d17bc2954e92513b5ce28aeaa233540dff8e36e8ca59a1c5115243be9c2e7bb5438ced3394e798ebbf63d23e198c7d4844ff",
    "24feb1af2170b4af4155195f3abe1d96bb7cc5971cf6c22d4528a68bb12eef8b0a55fa6a3f422b94afbdb2ecf755861ae95461c4c4327739ffa798f9bd6572fe"
    "68abcb7de2de65a7ffc9d6343cb3f6ba8bc123c71a51381fad12bbf0de42fa97789aa62ab4ca2c7d89f79945bc3016cfa87f92da3b5297444b967cac50a1585f",
    "3a5cdc0b477cfb01ffca46d9a708025b163a3e9a637d2c53f67194c252659f20cabe9185864b6024cead83fea75fadff2bece8ba231c5ee773c4eb60c633bbee"
    "dec1e09188feb07140af17f285b5fd62be7514db3d39100a8fa397f3c84dc199360f02d3776a7cb7debf22665e66d7db6da4afcb7de4784d1e6e69ed0717bcde",
    "c78c6fd66e3fc2e093887ee8c6a465460d0e249e62971939d2625825c5abe1012d3195b9f1fe0b8b78fb583ca3fe0dd6cdf0dfa391bd7c8f7483f95083e90bc9"
    "413ff0d7fffefb2bf00333c273ca0f64dbcd68b8966c6f14f3c16e25cef181c4099bf48e1fb01ad7ef60c62711bd653fb05463153de8259c8eebd35b76adbb07",
    "183c12d123fc2fab26a3a4787d6ebc7f03d7c944ded70d3507beffe3c34f20ee773bdffbf7eb2b6d65675390ea0db990a0ea9144aa1d03be5f9cfb9830f03dee"
    "79c3acbdde46fa04729cae67645e0b549561866f7e791dabeb2385c533eadf301ea8311dba2a0aeaf2f0192c3587fc0ef187c3ef435cef769edf5e3deb169a75",
    "868d16a367fbcd48bd78f6380e3cbfb03c8fc3336baf7b489fb8384ed330728d511f6a1a6ecdd7c7b07846bd155ed72ca4ad04e0736fe059e5f3ef61f04844df"
    "6ed271b15d91378fce570521271756568f4f08eff0b95bf2ae977cbe54632459a931c6eb788a99a7adeb6ff0d4b67cfd7b183c12d1abc628a94628d504891504",
    "b124b469a9c60ae7a5caf03dbbf5781e15dc7c74d1f106d7c4d3c73f9982a7ebaf97df1b2fa3d758cef9b860f0c5d777218f7353fd81d9f85ede8d77e2b15e2f"
    "b7d30904d3017f341f5ef1c7bde30f5e62ce376bc73e667c12d1cfeebe5e7afd01a506cd8ab4e4ec3addb6ed79e00ed2272e8ed334c36877d8cef9bd02c357e9",
    "4e8a572ee6f1cce23cb6a6cc43d75b7b4e58e61c5c172fe03daefbfd41a12b32dc5a73ff7085295783a9937c2ebde2a5bcfe33ccf90b7cdfaae2f74c1e7f9a3f"
    "a934a8d19b71c8e34f6e7581bc8f337890c7b767fc9798f321ce9f7cbde6d669cab6387f5a1e5ebd708eeacccf0fdcd0bcbfbe7e58f50f9f6623a7f3fe83170f",
    "ee439ec7edfc2f35fde2292307c3dc7a2ec4e7ca47abbb077204f81ff8df28c6f7becef23fc303ff4fe37f86779cff3f07fe773fffd7a9e35076f530d30c95c3"
    "4a748dca06e9607edb3bfc0fef7d27b7ba18d6dfcba7b6f1fa9be6efade2bd693dcf338b785b583ca3de45f93ec8d3cf100ff2f4f68cef423eefd19220b738e3",
    "75e0f2e933f90e77f0d1d6a8ddfad8317eafb55876d842bde6a4b85d1629a9d6e27d432b391db7f7ff04797bf7f3bcb21ee0f66387db8d9355a1d756d25c22bd"
    "a27888e79f63ce87ef6aafaebbcbfafb5f61c6336baf9f62f048448fd4bf50a2c876230c4f49ddc2c8e3255a7c456104deaef7c6df9e322f5d5f1be3961a145f",
    "551d815df59b4fa6e0eb7aabf102d690e337bb0efa873fff5682bc8edbfd433e1f55ce72a7fe50f924b39b2917a98d6c5a4e78c73f0c30e7c37d6d14e33a0cd9"
    "e62f7e8cc123113dea2fda02530d4b12d54db094a2d03cc3d747c7cdabbedfeaf3e4c1143c5d6f791d4d309cc3fbf3f5ff5706bfe076bfd0db49ae461f8b475c",
    "be9cad868f6ac97487cb7a683f1eabf77311333e89e8ad3f376819a2528d1528a574f104e1ec775e27b02f8f453cef7fe70dfbf2cc120ff6e5b1677cabbc9fc7"
    "8c4f227aebbccf0b4a86ca64a5947a6bd7f5b491c3fb361cdaf61e60da3ecb8ccc533ce1def700512c9e516fa97e676823e7f33cf0be7786784eeddbd00cb7b2",
    "5cb07b14f4ef4b81567485de6c7319c23bbc0ef7af518cebed27b6edd300fb2ae3f08c7ad857f94df13459143cd857d99ef1219e9fdcea828be7fb98f1ccdaed"
    "07183c12d14fcce32cd75841d02ce0d67c4e168b67d45bf5038f348bf94616539d8083fcff3ba8ff713fff971bebb9239e55aa05818bb7f8e46a391ed9f150dd",
    "fe0dcccbdebcfa9f7ec6b6fcfd77317824a247789f9624c1d47b8b597d9f75c3e27e599d1e5df5696c3fe67c94fa47369b43dcffe5ee31e4f1ddcefb1d3e7fde"
    "4b8b5c64bb194bc81bd19d665bf07b288f6f95f73398f14944ef95df49ec63c6336baff7317824a247785fa255a613e902d3d37e0853766bfd4e610a9eaeb71a",
    "efbf6230e7f3fdfff8fd67c0ff6ee7fff56d3f1bca85f2b983e4817c70b85edfdd6f7aa9ee1feee7c9ad2ec6f5f7be6df1ffbb183c12d1237e80a7a43ac3571a"
    "676ee57f9beb37cdc4ff173673366ee87fe7e7fbff04fe9f119e53fcdfed9ca736a944adbee6af64e342e134d10a9d7b685f66afdccfb8f56076fd7d03731dfa",
    "f7bdef1afef7c32dadfd60dc3e74acbe47cff8437dcfe4fa80d157bee31cff501ce4a7bf3d7e08797eb7f3fd4633942d36d9d8da59a451cc6f1794662c56f1d0"
    "775c70ff1a0517dff731e3417d8f393ca8ef99159e268b8207f53df68c0fbc6f9459d575de947a1e54cce6779e5f134f1f1fea79ecc6d36451f0a09ec79ef181",
    "ef8d82e3fb5f63c6336ba79f61f048443f691f1fe30615293ec752157a7cbc3e3fd1e2fce6bd9fcf4753f075bd2dfb7e4c34a8e3fb3497bf790aef7dddee1f04"
    "6aefb44c51dbd1eaeac6a97c14a0d32762d743ef7d0798f3e1be368a711d7e685b9e7ffaefaf0ff7ac9469b7e6f993583ca3deda7e9eba959cdcb779ebde2f60",
    "7f06d7f3fbf9614a4eb0670789404d2ab0edd3ec0edfcb4781df179bdf973d9707ba2eff431e68f2fc210fe40c1ee481ec191fea3b27b7bae07e7fd7ea7e9d4b"
    "183c12d1a3792159a625e5806299ead01461a93e3eceadef8167b0bfdfe438e215c3399ef7b91d3d87e702b7fb8340e0acb7194b4452f5bd4ee1a4972c2737f7",
    "15a8f75cc0fb5995fe16e47b4ce241bec72e3c4d16050ff23df68c0fbc3eb9d5c5c8eb61a8f31cff3fd4794e6e75813a4f67f0a0ced39ef10798f3cddab18419"
    "9f44f4b3f0034b8c3cd4d7258a75761d0e8e1dfb7e6b78893502bedf7afdfeaeaa8d607f664fe139c5ef6b9d349b386b574f53eb479d9daa1408f28575f87e6b",
    "01eedfa1c0fecc10d71be70d71fd7cf120aeb767fc01e67cd7c4f565a1c5576587e3fabc6dfee087183c12d1bfe20fc6db544759d532c4fcf6ed7c6e112f87f4"
    "09e4385d6fdd1f5c3598a379fe4fdfb90f797eb7fb8104bf978b840f333d86eb644fc52a9755325d0fe5f90798f3c10f18c5e8071edb96df991687ab06e0a8ce",
    "fc78deeaf3610c8b67d45b7a3e1cd9c8f1fa9c170f80df5dcfef52d32f9e327230ccade7427cae7cb4ba7b204780df179adf890347f99de181dfa7f13bc33bce"
    "ef9f03bfbb9fdfebd47128bb7a986986ca6125ba46658374300ff5f817e32d549d0e91045e378907bc6e179e268b8207bc6ecff8c0eb935b5d70bfa385c3837c",
    "8c26908fb10b4f9345c1837c8c3de3ff1d73be593b5298f149443f83ef6797da9434da2abf244a4215b9aea79879dbcbf315dbdebfbe87c12311bd6a9c926a94"
    "524d905841104b429b966aac705eaa0cad32bf7d3507d7c4d3c73f9982a7ebafe907b465f51acb395f9733f8e2ebbbe01fdcee1fe4dd78271eebf5723b9d4030",
    "1df047f3e115bf07bea7fd3f736450fb", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 58256U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_rjtipF_info.c) */
