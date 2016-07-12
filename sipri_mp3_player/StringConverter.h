#pragma once

#include <stdlib.h>
#include <string.h>
#include <vcclr.h>

namespace common {

	using namespace System;

	ref class CStringConverter
	{
	public:
		static int StringToChar(String^ pStr1, char* pStr2, size_t szStr2)
		{
			pin_ptr<const wchar_t> wcStr = PtrToStringChars(pStr1);

			size_t szConverted;
			if(wcstombs_s(&szConverted, pStr2, szStr2, wcStr, szStr2)){
				return 0;
			}else{
				return szConverted;
			}
		}

		static int StringToWchar(String^ pStr1, wchar_t* pStr2, size_t szStr2)
		{
			pin_ptr<const wchar_t> wcStr = PtrToStringChars(pStr1);
			wcscpy_s(pStr2, szStr2, wcStr);
			return 0;
		}

		static int CharToWchar(char* pStr1, size_t szStr1, wchar_t* pStr2, size_t szStr2)
		{
			return 0;
		}

		static int WcharToChar(wchar_t* pStr1, size_t szStr1, char* pStr2, size_t szStr2)
		{
			return 0;
		}
	};
}
