#pragma once
//Like Packet, this one was also mostly written by Copilot with modifications by myself such as splitting into header and cpp. Same prompts as in that file.

class PacketBuffer
{
	static constexpr size_t MAX_PACKET_SIZE = 512; // Maximum size of a UDP packet. Adjust as needed

	size_t Send(const UDPSocketPtr& socket, const Packet& packet, const SocketAddress& address);
	size_t Receive(const UDPSocketPtr& socket, Packet& packet, SocketAddress& address);
};