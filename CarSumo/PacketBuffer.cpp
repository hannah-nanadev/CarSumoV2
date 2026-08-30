#include "udpPCH.hpp"

size_t PacketBuffer::Send(const UDPSocketPtr& socket, const Packet& packet, const SocketAddress& address)
{
	return socket->SendTo(packet.GetData(), packet.GetSize(), address);
}

size_t PacketBuffer::Receive(const UDPSocketPtr& socket, Packet& packet, SocketAddress& address)
{
	std::vector<uint8_t> buffer(MAX_PACKET_SIZE);
	int bytesReceived = socket->ReceiveFrom(buffer.data(), MAX_PACKET_SIZE, address);
	if (bytesReceived > 0)
	{
		buffer.resize(bytesReceived);
		packet = Packet(buffer);
	}
	return bytesReceived;
}