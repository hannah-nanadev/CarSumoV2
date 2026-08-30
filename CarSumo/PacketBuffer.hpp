#pragma once
//Like Packet, this one was also mostly written by Copilot with modifications by myself such as splitting into header and cpp. Same prompts as in that file.

class PacketBuffer
{
public:
	static constexpr int MAX_PACKET_SIZE = 4096; // Maximum size of a UDP packet. Adjust as needed

	static int Send(const UDPSocketPtr& socket, const Packet& packet, const SocketAddress& address);
	static int Receive(const UDPSocketPtr& socket, Packet& packet, SocketAddress& address);
};