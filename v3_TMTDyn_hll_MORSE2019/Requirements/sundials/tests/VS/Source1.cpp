#include "windows.h"

typedef HRESULT(CALLBACK* LPFNDLLFUNC1)(DWORD, UINT*);

HRESULT LoadAndCallSomeFunction(int j)
{
	HINSTANCE hDLL;               // Handle to DLL
	LPFNDLLFUNC1 lpfnDllFunc1;    // Function pointer
	HRESULT hrReturnVal;

	hDLL = LoadLibrary("C:\Users\customer\MEGAsync\Hadi\TMTDyn\Code\TMTDyn_hll\Requirements\sundials\tests\matlab\codegen\mex\test\test_mex.lib");
	if (NULL != hDLL)
	{
		lpfnDllFunc1 = (LPFNDLLFUNC1)GetProcAddress(hDLL, "test");
		if (NULL != lpfnDllFunc1)
		{
			// call the function
			int j = 2;
			hrReturnVal = lpfnDllFunc1(j);
		}
		else
		{
			// report the error
			hrReturnVal = ERROR_DELAY_LOAD_FAILED;
		}
		FreeLibrary(hDLL);
	}
	else
	{
		hrReturnVal = ERROR_DELAY_LOAD_FAILED;
	}
	return hrReturnVal;
}