/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_massF1_info.c
 *
 * Code generation for function '_coder_massF1_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "massF1.h"
#include "_coder_massF1_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("massF1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (4.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/massF1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737430.8825231482));
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
    "789ced5dcd8fdbc615a75d3bb051a42190364e5034b5d3c268e160a5d56aa5dd0005f4bdd2eeea6b25ef871c474b4994442d3f2492fabc54c71e72e8a9a71e7c"
    "4c8ab6707ba98104857aebb54053143df9923fa13d9712c5dd25adb1e825452da9f7006376f4c4f98d9e87bf37f366f888dd48246f6018f63de9df3bbfc4b07f",
    "bf3bae61d8db982cf8b4bc89a945abbf312dd73475456e63b754d7dd98e2fd765a2f73ac48f644b942532c996a332592972a2cc190e7cd543886620956ccf79b"
    "24c693024777c8ca4453a568324f31e43e77a912a7a40a13bba43aaf8c55e3bfc375b27c966b33185f172eba4b5fae6053fb8ce539e2f7dfd2699f14c23eb846",
    "ff24fad455e718d255272a942b19dd090a7db6ec8a8f6bc1b6c8e593f9489f7585b90a79b91e2245c2d5595f73bbca630d4308426c7d8db9e8ff1788febda5b3"
    "ff7711fd573e8f5ffe30f05940fe4329b7a7a55f2eef97a6f54fe4721890cbc0d3e9e7c180d2ef5344bff4dafd36a2dff854d3e4ba93d16616de5b9afa059eac",
    "a970ed124dceff7fd18b1744e2a9f54f12fbc7d2d06a0bbc8be6ca04ed4a06f3fbc190ebc0e35edf2ab9448ea34b5ccf4532b48ba64ad2001269a2e4e29a826b"
    "62a1f1509ac83c3be91d4fda5291bbd89de95fc3cfbff1fd2b681d9e2cab82d743b4a777dcbd87c0c335faa3fa21e9cb65739b07f96cfb38b25738e4728fc317",
    "fdc8ccc199d70f0c51b7aa7dbbdebf4d44bff48eb79b9aba228a3fc0559f3e0cc8e547e7bc3e44b4afd76e3f46e0e31afdd81df26b9434c9e059825ea384509b"
    "a2c5042b4d33489e2a2f8df75f18c43b40e2a9f56f306ec6ff1e4dece57aa418cca5359832902cf4037ff9ef7fbe013fb0203cabfc40bad30a07abf1ce563eeb",
    "ed97a30ceb8915e8b873fc80d1f5c12ea27d5ca337ec071e54695199f462168fbb613260d6b8bb87c0c3357a0dff0b92c9083e5a5b1aef5fc3713293f715432d"
    "81effff8f03398f7db9defdd07b5f58eb8bbcdf1b5ba908b11b5502cd18900dfafce7d8ca9f81eb5ded06bafb735754cf33d454f09ac3c5115c791c2e5c5758c",
    "8e8f04124fad7fc3f94095ea919526270d0f97ca524b88ef607f38fa00e6f576e7f99d8db37eae55a3e8703e7c76d00ad5f2678fa3c0f32bcbf3283cbdf6baa3"
    "a963e7df93359450a5a4454dddaef1fa08124fad37c2ebb285e491007cee0c3ca37cfe03041eaed1775a64b4d9290bdbc7dd0d8ecb08b9f58d9302e61c3eb74b",
    "dcf582cf1f54295e10ab94fa779c22fa69eaf81b9d9a16afff1081876bf492318a92118a558ea739ae59e43a245fa5b96eb13cdeaf373e9fd70aaa3f8a2878a3"
    "2be229ed17e6e029faabc5f7a6c3e83596b37e5e30fafadbdb10c7b9aefe40effc5ed88bf6a291c120b3dbf378931e77381b5c77479de30f5e22aed76bc721a2",
    "7d5ca35fdc7dfde0f55f28d649ba49f2d68ed31dd3d603b73475ecfc7bb2663cdb1d974bde57a0d80ad94bb0e2793f9e19ec47604e3f14bdb175c21a63e1b878"
    "01fbb8f6f707b97e9362365b0747eb54a9e24d14b299e4ba93e2facf10d7aff07d2b89db3171fc79fea45c27263be310c79f5d2a02711f6bf0208e6f4efb2f11",
    "d7c33c7ff6efd5374e13a6cdf3e7c5e1a51fce10bde5f9816b1af757c60f2dfde1926d6475dc7ff4e2de5d88f3d89dfff996bbd9a0046f90f165fc6ca674bcb1"
    "77288480ff81ffd5a2def7b596ff2916f87f1eff53ace5fcff15f0bffdf9bf469cf8d31b47a996bf1414c39b44da4b7ab33bcee17fd8f79d5d2aa21a7f2f4f4d",
    "e3f5378ddf1bc57bd3f33ccf0ce20590786abd8de27d10a75f201ec4e9cd69df867c3e20794e6833eadf818aa72fe439dcd1a7814919786a19bf57db343d2ee1"
    "bce6ac79bbd024f86a9b758dad64f5bc7df82788dbdb9fe7459f8739881cedd40b1bdca023269958725d7410cf3f475c0fcfd55e1e7717e7ef7f85684fafbd7e",
    "86c0c3357acdf917a2d9a4fb218a25f87e6ee2f1626db62c521c6bd6bef13b73faa5e8ab53dc629d602b922330ebfce69339f88adee87c0169c8e9ceae85fee1"
    "cf5ff210d7b1bb7fc866c3e259a6e1f6970aa9bd54294f6ca59342cc39fe6184b81eee6bb5a8c7a1df347ff113041eaed16bfd4587a32a419e27fa319a104592",
    "a5d8dae47bcb3adf6f743d7938074fd11b1e47330c7739cfdf29a29f268e9fe1ff4ae017ecee1706bbf18df0e3e631932da52bc1e36a3cd963d20ecac763f47e"
    "ce23dac7357ae3eb06394254acd21c2116cf5710d63ee75580bc3c06f19cff9c37e4e559241ee4e531a77da3bc9f45b48f6bf4c6799fe5c414914af309e9d6ae",
    "2961238bf3361c99b60f302fcf3225b0048bd9771f208cc453eb0d9ddf19dbc8fa380fecf72e10cfaabc0dad603bcd78fbc75ef701ef6987d7c9ed0e93c29cc3"
    "eb70ffaa453dde7e6a5a9e06c8ab8cc253eb21aff29be2c9b22a789057d99cf6613e3fbb5404359f1f22dad36bb71f22f0708d7e661c67ad4a739c6c01bbc673",
    "d2483cb5dea81f78245bcc35b198e4042ce4ffdfc1f91ffbf37fa9eecb1cb3b458c9714cb4cdc6374ad1d0ae83ceed5fc3b8ecf53bff334c9916bfff3e020fd7"
    "e835bc4ff23ca76bdf6251cf675db379bf20758facb864b69f72be96fa27365bc2bcffaf7b2710c7b73beff7d86c77906c32a19d5624266c85775b1dceeda038",
    "be51de4f21dac735fa45bd6f11350ef48ebbef20faaf9ceb7f5ff56938302994f72a0ef3a6ad03ee23fa816bf41a7fc093120336c91c35905fb429d8f55c4f6e"
    "0e9ea237ba0e78c560d6ef03fce3f75f805fb0bb5ff0edb8697fc69fcd1cc60f85c3235f6defa0e5a4e701e07e9e5d2aa21e7ff74d5b17bcafa9639aef297a8d",
    "1f6009be46b1e5fa995df9dfe4739d7ad605e736b3f65ce7f0dd4f0efe09fcbf203cabf8bfdfeb26b68958b5b6e92ea7a35cae116bfbbb0ecad7ec94fbd9daf5"
    "c1c701b9fc685a3eb4ecdc8fb21300e77e669f1b983cfd3b8dfd8fc5427efadbe38710ffb73bdf6fb5fce97c8b8e6c9e85eaf9ec4e4e6c452265073ddf05f7af",
    "5a50f3fb21a23d38f7a30f0fcefd2c0a4f9655c183733fe6b40fbcaf96459df7bc2ee77cb4a237bef3fc8a784afb70cec76c3c5956050fcef998d33ef0bd5a50"
    "7cff6b447b7aedf473041eaed1cfcaefa34e5c916033345126a7df57fad734d8bf65e7f9f9740ebea237251fc84c835a9ebfb9f4dd06ecfbdadd3f70c47ea344",
    "103be1cac6564338f690c942b3efa07ddf11e27ab8afd5a21e871f9b16e79fff5ef6712e4b81b46b9c3f8ec453eb8de5f954ac64653ee7c09d5f40de06dbf37b"
    "f72821c4e8b3c398a7cae7e84e23bdcb0eb261e0f7d5e6f735c7c581aecaff10079add7f8803598307712073da87f39db34b4550efe5359ac7f301020fd7e8b5",
    "7121412079f190a0a9cad81441be36fd9e5df7811790f76ff63ce215c3591ef7b919eec2bac0eefec0e3391b6c4762a1446dbf972b0ce2a5f8f68108e73d57f0"
    "7e96641880788f4e3c88f7988527cbaae041bcc79cf681d767978aa8793d08e73ca79fc339cfd9a52270ced31a3c38e7694efb23c4f57aed5844b48f6bf48bf0",
    "030f2861acaff1046ded381c9d58f6fcd6f8275631787eebf5795f251b41de6647e159c5ef9bbd241d3beb541a09df716fb7c27bbc6cce07cf6fadc0fd3b16c8"
    "db0cf37a75bf615ebf5c3c98d79bd3fe0871bd6de6f525aecd56048be7f559d3fcc18f1078b846ff8a3f98a6af0ed39265b0e5e5f37c6e102fa3a9639aef297a",
    "e3fee0b2c12c8df37ffede5d88f3dbdd0fc4d8fd4c2878941a504c2fdd685698b498ea3b28ce3f425c0f7e402d6a3ff0d8b4f8cebc79b8640086e82d8fe78dae"
    "0f23483cb5ded0fa706223cbcfe7bcb807fc6e7b7ee75bee668312bc41c697f1b399d2f1c6dea110027e5f697ec70e2de5778a057e9fc7ef146b39bf7f05fc6e",
    "7f7eaf1127fef4c651aae52f05c5f02691f692de2c9cc73f6f6fa5cee96071e0759d78c0eb66e1c9b22a78c0ebe6b40fbc3ebb5404f57e2d141ec4636481788c"
    "5978b2ac0a1ec463cc69ffef88ebf5da9140b48f6bf40b787ef64187e027a9f28b4d9eab687ed729a2dfe6f27cd9b4fdd70f1178b8462f19a72819a558e5789a",
    "e39a45ae43f2559aeb16cb63ab2c2fafe6e88a784afb8539788afe8a7e401e56afb19cf5e772465f7f7b1bfc83ddfd83b017ed4523834166b7e7f1263dee7036"
    "b8ee76d0f3b4cf11d7c37b156551bd3765180bc865542eb19869eb00543ff0a94618077730fb9ebb0f22f1d47a23f9580525b88359c94b01786fca02f1ace279",
    "8288870addb33875980cb7e950888df8332907e5cb84fb572d8b3a77ff01020fd7e867e74d53587e79f37ca3f381e41c3c456f56de3465cc5838af0ffce64be0"
    "7bbbf3bd7b33eedb0a778f3cee50b74bbb9bb437521b3828ee037caf16c89f3fbb7f903f5f16c89f6f0f3cc89f6f4efb23c4f5705fab6551f995afcb3ae1aaf1",
    "205827ccee3fac13acc183758239ed43fc7f76ff67bf373d1e90cb1db91cee5816ff2f73c2a484f83f7a3d29d96819eb4988ff2f10cf2a9e6fe67b0d7f5accf8"
    "fc69229f6be4f99d7e997510cfc3fdab96eb19ff57581ee2ff7ae7f5ca98b170bfd707f37afbf3fd16bf2f10d972f2e4a874725c0a857cde6a8d04be5f39be87",
    "f8bf2c10ffd7f77b20febf5c3c88ff9bd3fe08713ddcd76ab99ef17ff3d609ab12ff877582b3f0609d60acfdff03f6020d19",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70640U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_massF1_info.c) */
