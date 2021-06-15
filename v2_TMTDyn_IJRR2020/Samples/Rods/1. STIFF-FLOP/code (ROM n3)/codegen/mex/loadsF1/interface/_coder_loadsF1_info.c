/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_loadsF1_info.c
 *
 * Code generation for function '_coder_loadsF1_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "loadsF1.h"
#include "_coder_loadsF1_info.h"

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
  emlrtSetField(xEntryPoints, 0, "Name", emlrtMxCreateString("loadsF1"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", emlrtMxCreateDoubleScalar(3.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", emlrtMxCreateDoubleScalar
                (2.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  emlrtSetField(xEntryPoints, 0, "FullPath", emlrtMxCreateString(
    "/home/hadi/MEGAsync/Hadi/AutoTMTDyn/Code/AutoTMTDyn/Beta/v1.0/code/loadsF1.m"));
  emlrtSetField(xEntryPoints, 0, "TimeStamp", emlrtMxCreateDoubleScalar
                (737429.71689814818));
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
    "789ced5dcd6fe3c615e7a6d9208b22ad80b449fa9566d362912281254bb26c0708a06f5bb6f5adb5bd4e5299922889363f249292255daa630f39e40fe821c7b4"
    "688b6d51208b2428d45baf059a1e7a0a5004bdf4da9e2b8aa2ede16a22da1c51a2f41eb018534f9cdfe8ede36f66debc19527712c93b14457d6bf8ef4fbfa0a8",
    "d317d52b8a7a81d2c4352e9fa15031eaef8ccb35c3b52e77a96791fbee8cf17e35be2e8b82c27414ed82630526d5e24b8c34bc10689eb9aca622f2ac400b4aa1"
    "db6028899145aecd54469a2acb310596670ec46b17bbecf0828f5f535d5ea82af5ef489d299fe75b3c25d5e5abe672d72fa8b17d54798cf9fdcf9ab44f1a631f",
    "9741ff6eec7d775de419779daeb0ee646c27247785b27b57bd0ab514b1902c44bb823b225698ebd76146a1ddedf5358fbbac6a3891aec8f1f535feb2fdbfc4b4"
    "ef3993edbf8b69ffbd71f9c6f50ffbd1a05646b492da1e97e3cfa9b7837abb4e31b866ed8a6b976bac698817236f2285f79ce1fa0a4fd354c4568963aef03eb6",
    "8817c2e2a1fa771307c743d769c9d2f03fbf4c73ee64a870100abb735ecffa56c9ad882257123b6e86e7dc1c5b72f3b4c2d125b7d890dd230b0d3d4593697632"
    "eb2fc652977bd4f3e3bffa1f7c11f847c83e3c4d5605af83a9cfacdfbd84c17319f447f5432690cfe63772856ceb38ba7f7228e61f46aeda91998233ad1d14e6",
    "daaefa9dfafc3630ed32eb6fcf18ae75d1f9de857cfa20a895af5ff27a1f53bf59bbfd1883ef32e8d5ee4e5a6387830849a0b935560eb7584e4908c3610423b1"
    "e5b9f1fe138b78392c1eaabf81dfa8ffde1cd9cbfda66e30b7d160ba23d9d80f7cf2df7f7e01fdc08cf0ecea07d2ed662454dd6d6f15b2fe6e39c60bdef809b7",
    "bb3cfd80d5f1ff1ea67e97416fb91fb85fe5147dd04bd9ec77fd649094dfbd8cc17319f406fe978726a3a5586d6ebcbf807e3291f77543cd81ef7fffe0e730ee"
    "773adf7b72b5f5b6b2b72d4ab5ba9c8fd3b5703cd18e02dfafce734c217c8f9b6f98b5d70b866bcaf03d5dcfca82365055d448e0fce23a56fd2381c543f5371c",
    "0f54d90e53698843f77023969a437c87faddd1f7605cef749edff19d77f3cd1acb450a91f35c335c2b9c3f8c01cfaf2ccfe3f0ccdaeb79c33575f93d4dc3ca55"
    "7638a9a93b355e1fc5e2a17a2bbcae5948f304e0f3e5c0b3cae7dfc5e0b90cfa76938935da6579fbf8c2278a1939bfee7b74422d0f9f3b25ee7ac5e7f7abac24",
    "2b5516fd1da7987612f5bfc129b178fdab183c97413f344671688462559438516c14c536235539f1a25856d7e3ad8fe78d826b8f2e3adee096787afd2753f074"
    "fdede27b6337fa1acbd93f2e187cfed55d88e32c6a7f60767c2fefc73ab168af97d9eb78fd49af27920dad7b62cbd31f7c89b9dfac1dfb98fa5d06fdec9eebfb",
    "5fff85629de11a8c64af9fee109b0f3c6bb8a62ebfa769d4d1ae5ace795d81152a4c27212897edf8c8623b8253daa1ebadcd13d6781bfde209ace33abf3fc877"
    "1b2cbfd1cc1dadb3a58a3f7192cd24d79729aeff11e6fe157e6e87e2599a38feb4fea45ca7472be310c79f5cea02711f7bf0208e4fa6fe2f31f7c3387ff2ef35",
    "e7a70962e3fc6971f8e10fe7e9cefcfa81058dfbebfec30dff706b36b23bee3f78f2f23d88f3389dffa5a6a771c6cafe101fc86c0a99d2b16fff500e03ff03ff"
    "a382aefbdacbffac00fc3f8dff59c176feff0cf8dff9fc5fa31f6da67d47a9e66629a44436e8b49ff167779687ff61dd7772a90be27f5f9e12e3f59bc6efade2",
    "dd349fe7238b78412c1eaa7750bc0fe2f433c483383d99fa1dc8e73d4612e5168ffe0e5c3c7d26fb7007ef054765f07ddbf8bddae238b5847ccd49e376b9414b"
    "d596e056ad64f7b8bdff0788db3b9fe7958097cf458f76ea273eb1d756927c3cb9ae2c11cf3fc6dc0ffb6aaffbdd55fe3dee1c1fb3f67ac3704d19bea7eb0df9",
    "2f74a3c175c3ac404bddfca8c78bb784b2c28a02a975e36f4f6997aeaf8e718b755aa80c3b0252f99bef4ec1d7f556c70b58438e57766dec1ffef86b09e23a4e"
    "ef1fb2d988729e39f36c964e52fba95281de4a27e5f8f2f40f03ccfdf05ca382fae126b1fee227183c97416fec2fda225b094912dd8d73b4a230022bd446df9b",
    "577ebfd5f9e4e1143c5d6fd98f26184e75211bfda7ffbf12f40b4eef177a7bbbbec8c3c6319f2da52ba1e3ea6eb2c3a797e83c1eabcf730153bfcba0b73e6fd0"
    "2244c52a27d24af1720661ef3eaf133897c722def2eff3867379668907e7f290a9df2aef6731f5bb0c7aebbc2f884a8a4ea5a5c4f0d1aee961239bcf6d3822b6",
    "0e30ed9c655616688172ee3a40048b87ea2de5efa836b23fce03ebbd33c4b3ebdc8666a895e6fddd63bf2727795b917566bbcda7a8e5e175787e5141fdeda7c4"
    "ce698073957178a81ece55be299e26ab8207e72a93a91fc6f3934b5d70e3f93ea63eb376fb0106cf65d04f8ce3ac553951d42ce0d4788ee9f7f158ec07ded42c",
    "e61e59ecdafb784e31ed23c8ffbf81fc1fe7f37fa91ec81c0b9c52c98b7cac25ecfa4ab1f0de12e5ed2f605c76f1f27ffa2962f1fbef60f05c06bd81f7194912"
    "4dad5bcc6a7fd6828dfbe561f3988a5b63fb31e71ba97f64b3398cfbffbcff08e2f84ee7fd8e90bde8251b7c78a7198dcb5b91bd665bf42c511cdfb6f1db8cde",
    "a7d8c0b46f36efd78a0747453f665b5ebfdc94462fe5746a3c3f8cc543f5b78d07aa59fdaa8dece7f7e05f1e3e8071bdd3f9ddbf13abd63d81c4593ae64b2899"
    "ac20b423d1258aebc0f38b0aea6f0f88c5717e88c17319f44fc5f3a3224fb342cc38aec7f56b76e5f13b25ae8318d0deb8cea7ff81fc4cc7f33f97e42bfcb9c4",
    "241b9123654b6c55aa8f5aec129dc703cff1e4f6a37e1720369e9ffe5e15752faacc38753cbf8bc543f5d6f6e9ea56b2f33c86e0f3ef40dea5e3f9fce22821c7"
    "b9f3c3b8b72ae5b9f6597a4fe86523c0e7abc5e7efc0beabb1c0be2bb4dd26fc07f65dcd100ff65d91a91fe23aa8a0fef606acd35ac48375da59e169b22a78b0",
    "4e4ba67ee07b54507f5b2316c7ff3e06cf65d04fcec7d4576be737ceb73a3f4c4dc1d3f5a4f231759fb1cf5f069ffcebdfb06ebba87c6f761fd656eb20ef39f4"
    "a54352c217138ef772012117a080ef578def3fc4d467d64e3fc3e0b90cfa49e7b0a1070c25840c479799f1f717651d776011ffbd29f8ba9ec8b94d130d6afb39",
    "fba56f9ec17c6051fb07b3f301913e382bd1f44ea4e2db3a938fbd4cf2a4d15da2f9c000733f3cd7a8a07ef816acf39ac483755e52789aac0a1eacf392a97f80"
    "b91ff81d95658f03dd96ff210e34b9fd1007b2070fe24064eab7fa1ccf7b7fd629a67d64f7e5a689f1fe6b183c97416fe07d8991eb7483c9b33d26a2be255276",
    "6a9e4f7e0a9eaeb7cafb4f19ccfef3d8fef6db8f611eb0a8fc6f761e10d8f1709b99cd6ce670f7503e3c0ad4f673cd657a2f0b3ccf934b5d50ff7b8d58decf2b"
    "183c97416fe807045aaab142b97eee54fe279ce76926efe7d266f68efffb2fbe9dfb3bf0ff8cf0ece2ff6ee722b14dc7abb50d4f391d13f367f1d6e6450cf87f",
    "d19e679c3f98f5bf6f607e877e4ec32bc8a76f05b5f2f57179b5cff7148343eafc65fd4436a7c6fd677d7eebe82d8ce333d854b1919fe0bc8619e2d9c5f75bcd"
    "cd74a1c94537cec3f5427627af34a3d1f212bd670b9e5f5470e3fb3ea63e387fd91c1e9cbf3c2b3c4d56050fce5f26533ff03e2ab33a777f51ce5b368ad9f8ce",
    "e35be2e9f5c379cba4f13459153c386f994cfdc0f7a8e0f8fe434c7d90dfafc9c022feeae589417eff2cf120bf9f4cfd03ccfdf05ca332abfccf459927dc363e"
    "04f384c9ed8779823d78304f20533fe4ff4c2e7541fdcf73c9ff56cf7dbb8fc17319f4c679832c33927248736c45354548aa8dbfe7d4758202160fd55b1e473c",
    "6538dbe705cf442e605ee0f4fec0eb3def6d47e3e144eda0933fe9ed9676b7730ae403ade0f33c947e10f6fb9ac483fdbea4f03459153cd8ef4ba67ee0f5c9a5"
    "2e28af87200f68fc39e4014d2e75813c207bf0200f884cfd03ccfd66ed58c4d4ef32e867d10fdc6765555f9368ce5e3f1c3cb22dbf5ffd89550af2fb717903c3",
    "3fdc231bd9bf9ff709f0bbf3f97da393e4e2e7edca592270dcd9ab485ebf900f407eff0a3cbfaa90cbf384713d0e0fd5c3b8fea6789aac0a1e8cebc9d43fc0dc"
    "ef98717d496c0915d9e6717d96587ff0230c9ecba07faa3f48a8331a468a7043cb50e4c6fd377d9fcb638b7819c33565f89eaeb7de1f5c3798ad71fe0f5eba07",
    "717ea7f70371e120130e1da57a2cdf499f352a7c5a49759728ce3fc0dc0ffd002a683ff090587c67da387c68009eeecc8fe7adce0fa3583c546f697e38b291ed"
    "f9394f5e067e773cbf4b4d4fe38c95fd213e90d91432a563dffea1bc44ef5b1f60ee077e4705f5c3435bf99d1580dfa7f13b2bd8ceef9f01bf3b9fdf6bf4a3cd",
    "b4ef28d5dc2c8594c8069df633fe2ce4e35fd6b752793ad42ef0ba493ce07552789aac0a1ef03a99fa81d72797baa0f9972988c798c483780c293c4d56050fe2"
    "3164eaff2be67eb376a431f5bb0cfa19ec9fbddfa6a5d151cac58624560cbfeb14d36eb23c5f26b6fefa2a06cf65d00f8d531c1aa55815254e141b45b1cd4855",
    "4ebc289655abccefdcb5c12df1f4fa4fa6e0e9fa5bf6039a5b7d8de5eccfcb197cfed55de81f9cde3fc8fbb14e2cdaeb65f63a5e7fd2eb896443eb9e25d84ffb"
    "7fdc050f33", "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 70520U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_loadsF1_info.c) */
