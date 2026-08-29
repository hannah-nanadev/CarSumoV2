#pragma once
#include "texture_id.hpp"
#include <SFML/System/Time.hpp>
#include <functional>
#include "car.hpp"

struct Direction
{
	Direction(float angle, float distance)
		: m_angle(angle), m_distance(distance) {
	}
	float m_angle;
	float m_distance;
};

struct CarData
{
	int m_hitpoints;
	float m_speed;
	float m_turnspeed;
	float m_maxturnspeed;
	TextureID m_texture;
	sf::IntRect m_texture_rect;
};

//Hannah Kellett D00260463

std::vector<CarData> InitializeCarData();

sf::IntRect GetCarTextureRect(CarType type);



