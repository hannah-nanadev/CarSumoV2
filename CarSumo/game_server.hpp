//Hannah Kellett D00260463

//Some changes to m_listener_socket handling made via the following Copilot prompt:
//What should I do about references to m_listener_socket? There seem to be a few methods that I'm unsure of their equivalents for my current UDP socket.

//Another prompt was used after issues arose involving a missing operator for m_peer_by_address. Fixing it was as simple as replacing map with unordered_map. The prompt was the compiler error in question, which was so long it doesn't show in my Copilot window, but it started as follows:
//1>C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.44.35207\include\type_traits(2379,60): error C2676: binary '<': 'const _Ty' does not define this operator or a conversion to a type acceptable to the predefined operator

#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <thread>
#include <cstdint>
#include <map>
#include <unordered_map>

class GameServer
{
public:
	explicit GameServer(sf::Vector2f battlefield_size);
	~GameServer();
	void NotifyPlayerSpawn(uint8_t car_identifier);
	void NotifyPlayerRealtimeChange(uint8_t car_identifier, uint8_t action, bool action_enabled);
	void NotifyPlayerEvent(uint8_t car_identifier, uint8_t action);

private:
	//Below struct needed assistance from Copilot to fix. some game_server fixes resulting from the UDP translation came from a Copilot conversation starting with the prompts in Packet.hpp, continued with the following prompt:
	//Occurs that m_peers does not have address data. How should I add this?

	struct RemotePeer
	{
		RemotePeer();
		SocketAddress m_address;
		sf::Time m_last_packet_time;
		std::vector<uint8_t> m_car_identifiers;
		bool m_ready;
		bool m_timed_out;
	};

	struct CarInfo
	{
		sf::Vector2f m_position;
		float m_rotation;
		uint8_t m_hitpoints;
		uint8_t m_car_type;
		std::map<uint8_t, bool> m_real_time_actions;
	};

	typedef std::unique_ptr<RemotePeer> PeerPtr;

private:
	void SetListening(bool enable);
	void ExecutionThread();
	void Tick();
	sf::Time Now() const;

	void HandleIncomingPackets();
	void HandleIncomingPackets(Packet& packet, RemotePeer& receiving_peer, bool& detected_timeout);

	sf::Vector2f ComputeSpawnPosition();
	sf::Angle ComputeSpawnAngle();

	void HandleDisconnections();

	void InformWorldState(const SocketAddress& client);
	void BroadcastMessage(const std::string& message);
	void SendToAll(Packet& packet);
	void UpdateClientState();

	RemotePeer* FindPeerByAddress(const SocketAddress& address);

private:
	std::thread m_thread;
	sf::Clock m_clock;
	bool m_listening_state;
	sf::Time m_client_timeout;

	UDPSocketPtr m_socket;

	std::size_t m_max_connected_players;
	std::size_t m_connected_players;

	float m_world_height;
	sf::FloatRect m_battlefield_rect;

	std::size_t m_car_count;
	std::map<uint8_t, CarInfo> m_car_info;

	std::vector<PeerPtr> m_peers;
	std::unordered_map<SocketAddress, std::uint8_t> m_peer_by_address;
	uint8_t m_car_identifier_counter;
	bool m_waiting_thread_end;
};

