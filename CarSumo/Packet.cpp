#include "udpPCH.hpp"

//I don't know why Copilot didn't split it into a hpp and cpp? Pretty sure it's good practice to do this

Packet::Packet() :
	m_write_pos(0),
	m_read_pos(0)
{
}

Packet::Packet(const std::vector<uint_8t>& data) :
	m_data(data),
	m_write_pos(data.size()),
	m_read_pos(0)
{
}

const uint8_t* Packet::GetData() const
{
	return m_data.data(); //raw pointer to the data
}

int Packet::GetSize() const
{
	return static_cast<int>(m_data.size());
}

void Packet::Clear()
{
	m_data.clear();
	m_write_pos = 0;
	m_read_pos = 0;
}

Packet& Packet::operator<<(uint8_t& data)
{
	Write(&data, sizeof(uint8_t));
	return *this;
}

Packet& Packet::operator>>(uint8_t& data)
{
	Read(&data, sizeof(uint8_t));
	return *this;
}

Packet& Packet::operator<<(uint16_t& data)
{
	uint16_t networkValue = htons(data);
	Write(&networkValue, sizeof(uint16_t));
	return *this;
}
Packet& Packet::operator>>(uint16_t& data)
{
	uint16_t networkValue;
	Read(&networkValue, sizeof(uint16_t));
	data = ntohs(networkValue);
	return *this;
}

Packet& Packet::operator<<(bool& data)
{
	uint8_t value = data ? 1 : 0;
	Write(&value, sizeof(uint8_t));
	return *this;
}
Packet& Packet::operator>>(bool& data)
{
	uint8_t value;
	Read(&value, sizeof(uint8_t));
	data = (value != 0);
	return *this;
}

Packet& Packet::operator<<(const std::string& data)
{
	uint16_t length = static_cast<uint16_t>(data.size());
	*this << length; //writing length first
	Write(data.data(), length);
	return *this;
}

Packet& Packet::operator>>(std::string& data)
{
	uint16_t length;
	*this >> length; //reading length first
	data.clear();
	data.resize(length);
	Read(&data[0], length);
	return *this;
}

Packet& Packet::operator<<(float data)
{
	uint32_t networkValue = htonl(*reinterpret_cast<uint32_t*>(&data));
	Write(&networkValue, sizeof(uint32_t));
	return *this;
}
Packet& Packet::operator>>(float& data)
{
	uint32_t networkValue;
	Read(&networkValue, sizeof(uint32_t));
	uint32_t hostValue = ntohl(networkValue);
	data = *reinterpret_cast<float*>(&hostValue);
	return *this;
}

void Packet::Write(const void* data, size_t size)
{
	const uint8_t* bytes = static_cast<const uint8_t*>(data);
	m_data.insert(m_data.end(), bytes, bytes + size);
	m_write_pos += size;
}

void Packet::Read(void* data, size_t size)
{
	if (m_read_pos + size > m_data.size())
	{
		std::memset(data, 0, size);
		m_read_pos = m_data.size();
		return;
	}
	std::memcpy(data, &m_data[m_read_pos], size);
	m_read_pos += size;
}