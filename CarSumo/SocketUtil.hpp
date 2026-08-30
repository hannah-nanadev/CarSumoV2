#pragma once
#include <memory>

// Forward declaration suggested by Copilot - prompts below.
class UDPSocket;
typedef std::shared_ptr< UDPSocket > UDPSocketPtr;

enum SocketAddressFamily
{
	INET = AF_INET,
	INET6 = AF_INET6
};

class SocketUtil
{
public:

	static bool			StaticInit();
	static void			CleanUp();

	static void			ReportError(const char* inOperationDesc);
	static int			GetLastError();

	static UDPSocketPtr	CreateUDPSocket(SocketAddressFamily inFamily);
};

/*
Prompt 1:
1>udpPCH.cpp 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\SocketUtil.hpp(19,22): error C3646: 'CreateUDPSocket': unknown override specifier 1>(compiling source file 'udpPCH.cpp') 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\SocketUtil.hpp(19,38): error C2275: 'SocketAddressFamily': expected an expression instead of a type 1>(compiling source file 'udpPCH.cpp') 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\SocketUtil.hpp(19,58): error C2146: syntax error: missing ')' before identifier 'inFamily' 1>(compiling source file 'udpPCH.cpp') 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\SocketUtil.hpp(19,67): error C2238: unexpected token(s) preceding ';'
Copilot suggested including the header file "UDPSocket.hpp" leading to a circular dependency.

Prompt 2:
Adding the include actually seems to break it further - "UDPSocketPtr is undefined"
This was where the forward declaration was suggested.
*/