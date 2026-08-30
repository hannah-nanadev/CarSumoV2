#pragma once
#include <vector>
#include <cstring>
#include <cstdint>
#include <string>

typedef uint8_t uint_8t;

//The following class was largely written by Copilot as a means to replace sf::Packet in a way that I can use for UDP.
//All prompts involved in this class (and the rest of the UDP networking code) will be included where relevant.
class Packet
{
public:
	Packet();
	Packet(const std::vector<uint_8t>& data);
	
	const uint8_t* GetData() const;
	int GetSize() const;
	void Clear();

	// epic read/write operators because i like being able to do packet << data1 << data2 << data3
	Packet& operator<<(uint8_t& data);
	Packet& operator>>(uint8_t& data);

	Packet& operator<<(uint16_t& data);
	Packet& operator>>(uint16_t& data);

	Packet& operator<<(bool& data);
	Packet& operator>>(bool& data);

	Packet& operator<<(const std::string& data);
	Packet& operator>>(std::string& data);

	Packet& operator<<(const float data);
	Packet& operator>>(float& data);

	//Add more as necessary for other data types

private:
	std::vector<uint_8t> m_data;
	size_t m_write_pos;
	size_t m_read_pos;

	//Helper functions so I can write/read stuff
	void Write(const void* data, size_t size);
	void Read(void* data, size_t size);
};

/*
Prompt 1: I have brought several files from an external project over in hopes of overhauling my networking to use UDP instead (externally rather than through SFML.) How might I begin to implement this?
Various things were suggested as a baseline. This prompt provides context.
Prompt 2:
UDP packet serialisation stuff would help - things seem to rely heavily on sf::Packet right now, and while I can pretty easily sub in UDPSocket to work as both sender and listener at least in the header, packets seem more complicated.
Thus the creation of this file.
*/