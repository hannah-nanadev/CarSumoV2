#pragma once

//below includes/forward declaration suggested by copilot
#include <memory>
#include <string>

class SocketAddress;
using SocketAddressPtr = std::shared_ptr<SocketAddress>;

class SocketAddressFactory
{
public:
	static SocketAddressPtr CreateIPv4FromString(const std::string& inString);
};

/* The prompt:
1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\SocketAddressFactory.hpp(6,26): error C3646: 'CreateIPv4FromString': unknown override specifier 1>(compiling source file 'udpPCH.cpp') 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\SocketAddressFactory.hpp(6,47): error C2059: syntax error: 'const' 1>(compiling source file 'udpPCH.cpp') 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\SocketAddressFactory.hpp(6,58): error C2039: 'string': is not a member of 'std' 1>(compiling source file 'udpPCH.cpp') 1>    C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.44.35207\include\memory(31,1): 1>    see declaration of 'std' 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\SocketAddressFactory.hpp(6,75): error C2238: unexpected token(s) preceding ';'
*/