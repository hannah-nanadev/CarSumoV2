//Hannah Kellett D00260463
//Some refactoring done via assistance of Copilot through following prompt:
//Turns out Player also needs some modifications. With regards to the current state of multiplayer_gamestate and game_server, what might those be?
/*
Public repo matches: (this is probably fine. i took from the former repo anyway)
https://github.com/johnloane/gd4_sfml_25/blob/70985e63ac5bdcad06cc8f8d060534c2cddd962c/GD4_25_SFML/player.cpp
https://github.com/johnloane/gd4_sfml_24/blob/c478bff25c5b06e64a01a675d0ccf98e4e965da7/gd4_sfml_tcp_game/Player.cpp
*/

#pragma once
#include "command_queue.hpp"
#include <SFML/Window/Event.hpp>
#include "action.hpp"
#include <map>
#include "command.hpp"
#include "key_binding.hpp"
#include <SFML/Network/TcpSocket.hpp>


class Player
{
public:
	Player(UDPSocketPtr socket, uint8_t identifier, const KeyBinding* binding, const SocketAddress* address = nullptr);
	void HandleEvent(const sf::Event& event, CommandQueue& command_queue);
	void HandleRealTimeInput(CommandQueue& command_queue);
	void HandleRealtimeNetworkInput(CommandQueue& commands);

	//React to events or realtime state changes recevied over the network
	void HandleNetworkEvent(Action action, CommandQueue& commands);
	void HandleNetworkRealtimeChange(Action action, bool action_enabled);

	void DisableAllRealtimeActions(bool enable);
	bool IsLocal() const;

private:
	void InitialiseActions();

private:
	const KeyBinding* m_key_binding;
	std::map<Action, Command> m_action_binding;
	std::map<Action, bool> m_action_proxies;
	uint8_t m_identifier;
	UDPSocketPtr m_socket;
	const SocketAddress* m_address;
};

