#pragma once
#include <unordered_map>
#include <memory>

class DeliveryNotificationManager;
class TransmissionData;

//Above includes, as well as TransmissionDataPtr forward declaration were Copilot suggestions. Prompt below

//in case we decide to change the type of the sequence number to use fewer or more bits
typedef uint16_t	PacketSequenceNumber;
typedef std::shared_ptr<TransmissionData>	TransmissionDataPtr;

class InFlightPacket
{
public:

	InFlightPacket(PacketSequenceNumber inSequenceNumber);

	PacketSequenceNumber GetSequenceNumber() const { return mSequenceNumber; }
	float				 GetTimeDispatched() const { return mTimeDispatched; }

	void 				 SetTransmissionData(int inKey, TransmissionDataPtr	inTransmissionData)
	{
		mTransmissionDataMap[inKey] = inTransmissionData;
	}
	const TransmissionDataPtr GetTransmissionData(int inKey) const
	{
		auto it = mTransmissionDataMap.find(inKey);
		return (it != mTransmissionDataMap.end()) ? it->second : nullptr;
	}

	void			HandleDeliveryFailure(DeliveryNotificationManager* inDeliveryNotificationManager) const;
	void			HandleDeliverySuccess(DeliveryNotificationManager* inDeliveryNotificationManager) const;

private:
	PacketSequenceNumber	mSequenceNumber;
	float			mTimeDispatched;

	std::unordered_map< int, TransmissionDataPtr >	mTransmissionDataMap;
};

/*
Prompt:
1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(18,43): error C2061: syntax error: identifier 'TransmissionDataPtr' 1>(compiling source file 'udpPCH.cpp') 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(22,2): error C4430: missing type specifier - int assumed. Note: C++ does not support default-int 1>(compiling source file 'udpPCH.cpp') 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(22,28): error C3646: 'GetTransmissionData': unknown override specifier 1>(compiling source file 'udpPCH.cpp') 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(22,48): error C2062: type 'int' unexpected 1>(compiling source file 'udpPCH.cpp') 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(23,2): error C2334: unexpected token(s) preceding '{'; skipping apparent function body 1>(compiling source file 'udpPCH.cpp') 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(35,27): error C2065: 'TransmissionDataPtr': undeclared identifier 1>(compiling source file 'udpPCH.cpp') 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(35,7): error C2923: 'stdunordered_map': 'TransmissionDataPtr' is not a valid template type argument for parameter '_Ty' 1>(compiling source file 'udpPCH.cpp') 1>    C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(35,27): 1>    see declaration of 'TransmissionDataPtr' 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(35,7): error C2976: 'stdunordered_map': too few template arguments 1>(compiling source file 'udpPCH.cpp') 1>    C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.44.35207\include\unordered_map(61,7): 1>    see declaration of 'stdunordered_map' 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(35,49): error C2955: 'stdunordered_map': use of class template requires template argument list 1>(compiling source file 'udpPCH.cpp') 1>    C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.44.35207\include\unordered_map(61,7): 1>    see declaration of 'stdunordered_map' 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(20,3): error C2678: binary '[': no operator found which takes a left-hand operand of type 'stdunordered_map' (or there is no acceptable conversion) 1>(compiling source file 'udpPCH.cpp') 1>    C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.44.35207\include\unordered_map(432,18): 1>    could be '_Ty &stdunordered_map<_Kty,_Ty,_Hasher,_Keyeq,_Alloc>operator [](const _Kty &)' 1>        C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(20,3): 1>        '_Ty &stdunordered_map<_Kty,_Ty,_Hasher,_Keyeq,_Alloc>operator [](const _Kty &)': cannot convert 'this' pointer from 'stdunordered_map' to 'stdunordered_map<_Kty,_Ty,_Hasher,_Keyeq,_Alloc> &' 1>            C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(20,3): 1>            Reason: cannot convert from 'stdunordered_map' to 'stdunordered_map<_Kty,_Ty,_Hasher,_Keyeq,_Alloc>' 1>            C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(20,3): 1>            Conversion requires a second user-defined-conversion operator or constructor 1>    C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.44.35207\include\unordered_map(259,18): 1>    or       '_Ty &stdunordered_map<_Kty,_Ty,_Hasher,_Keyeq,_Alloc>operator [](_Kty &&)' 1>        C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(20,3): 1>        '_Ty &stdunordered_map<_Kty,_Ty,_Hasher,_Keyeq,_Alloc>operator [](_Kty &&)': cannot convert 'this' pointer from 'stdunordered_map' to 'stdunordered_map<_Kty,_Ty,_Hasher,_Keyeq,_Alloc> &' 1>            C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(20,3): 1>            Reason: cannot convert from 'stdunordered_map' to 'stdunordered_map<_Kty,_Ty,_Hasher,_Keyeq,_Alloc>' 1>            C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(20,3): 1>            Conversion requires a second user-defined-conversion operator or constructor 1>    C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(20,3): 1>    while trying to match the argument list '(std::unordered_map, int)' 1>C:\Users\Hannah\Documents\GitHub\CarSumoV2\CarSumo\InFlightPacket.hpp(20,33): error C2065: 'inTransmissionData': undeclared identifier
Similarities found to public code at https://github.com/goheungchoi/GameNetworkSystem/blob/9fcd4a879bb301862f4c61c7d7cc03e00614a67b/include/gamenet/network/packet/reliability/in_flight_packet.h
*/