//Hannah Kellett D00260463

//Some edits were made due to the transition from TCP to UDP, with assistance from Copilot. The following prompt was used:
/*
Prompt 1:
Upon clicking Host in menu, "Failed to connect to server" is displayed and the game crashes with the following error: C:\Users\Hannah\Documents\GitHub\CarSumoV2\x64\Debug\CarSumo.exe (process 10048) exited with code -1073741819 (0xc0000005).
This allowed me to add a null check to game_server to prevent a crash, but the socket still can't be created.
Prompt 2:
New question: Why is the socket failing to be created?
This prompt allowed me to realise I needed to add a call to SocketUtil::StaticInit(). This is in the constructor for Application.
Also told me to add a destructor for cleanup.
*/

#pragma once
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "player.hpp"
#include "resource_holder.hpp"
#include "resource_identifiers.hpp"
#include "statestack.hpp"
#include "music_player.hpp"
#include "sound_player.hpp"
#include "key_binding.hpp"

class Application
{
public:
	Application();
	~Application();
	void Run();

private:
	void ProcessInput();
	void Update(sf::Time dt);
	void Render();
	void RegisterStates();

private:
	sf::RenderWindow m_window;

	TextureHolder m_textures;
	FontHolder m_fonts;

	StateStack m_stack;

	MusicPlayer m_music;
	SoundPlayer m_sound;

	KeyBinding m_key_binding_1;
	KeyBinding m_key_binding_2;

	CarType m_p1_car;
	CarType m_p2_car;
};

