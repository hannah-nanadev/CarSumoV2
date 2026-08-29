#pragma once

struct CarData
{
	int m_hitpoints;
	float m_speed;
	float m_turnspeed;
	float m_maxturnspeed;
	string m_texture_name;
	sf::IntRect m_texture_rect;
};

std::vector<CarData> InitializeCarData();