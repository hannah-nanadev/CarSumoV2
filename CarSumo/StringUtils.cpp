#include "udpPCH.hpp"

#if !_WIN32
extern const char** __argv;
extern int __argc;
void OutputDebugString(const char* inString)
{
	printf("%s", inString);
}
#endif

std::string StringUtils::GetCommandLineArg(int inIndex)
{
	if (inIndex < __argc)
	{
		return std::string(__argv[inIndex]);
	}

	return std::string();
}


std::string StringUtils::Sprintf(const char* inFormat, ...)
{
	//not thread safe...
	static char temp[4096];

	va_list args;
	va_start(args, inFormat);

#if _WIN32
	_vsnprintf_s(temp, 4096, 4096, inFormat, args);
#else
	vsnprintf(temp, 4096, inFormat, args);
#endif
	return std::string(temp);
}

// void StringUtils::Log( const char* inFormat )
// {
// 	OutputDebugString( inFormat );
// 	OutputDebugString( "\n" );
// }

void StringUtils::Log(const char* inFormat, ...)
{
	//not thread safe...
	static char temp[4096];

	va_list args;
	va_start(args, inFormat);

#if _WIN32
	_vsnprintf_s(temp, 4096, 4096, inFormat, args);
#else
	vsnprintf(temp, 4096, inFormat, args);
#endif
	//Change to A to prevent compilation errors suggested by Copilot - prompt below
	OutputDebugStringA(temp);
	OutputDebugStringA("\n");
}

/*
Prompt:
1>(compiling source file '/StringUtils.cpp') 1>    C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\StringUtils.cpp(58,20): 1>    Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast 1>    C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\um\debugapi.h(61,1): 1>    see declaration of 'OutputDebugStringW' 1>    C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\StringUtils.cpp(58,2): 1>    while trying to match the argument list '(char [4096])' 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\StringUtils.cpp(59,2): error C2664: 'void OutputDebugStringW(LPCWSTR)': cannot convert argument 1 from 'const char [2]' to 'LPCWSTR' 1>(compiling source file '/StringUtils.cpp') 1>    C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\StringUtils.cpp(59,20): 1>    Types pointed to are unrelated; conversion requires reinterpret_cast, C-style cast or parenthesized function-style cast 1>    C:\Program Files (x86)\Windows Kits\10\Include\10.0.26100.0\um\debugapi.h(61,1): 1>    see declaration of 'OutputDebugStringW' 1>    C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\StringUtils.cpp(59,2): 1>    while trying to match the argument list '(const char [2])'
*/
