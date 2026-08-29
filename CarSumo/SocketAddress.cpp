#include "udpPCH.hpp"


std::string	SocketAddress::ToString() const
{
#if _WIN32
	const sockaddr_in* s = GetAsSockAddrIn();
	char destinationBuffer[128];
	InetNtopA(s->sin_family, const_cast<in_addr*>(&s->sin_addr), destinationBuffer, sizeof(destinationBuffer)); //using A was a Copilot suggestion, noting this for later reference as I need to cite my AI uses
	return StringUtils::Sprintf("%s:%d",
		destinationBuffer,
		ntohs(s->sin_port));
#else
	//not implement on mac for now...
	return string("not implemented on mac for now");
#endif
}


/* The prompt:
Can you explain why argument of type "char *" is incompatible with parameter of type "PWSTR" (aka "wchat_t *")?
I have this exact file in another project I'm referencing (edited slightly to compile properly here)
but I'm unsure where the error comes from.
*/