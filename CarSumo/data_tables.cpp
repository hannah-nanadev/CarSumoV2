//Hannah Kellett D00260463
#include "udpPCH.hpp"
#include "data_tables.hpp"
#include "car_type.hpp"
#include "car.hpp"
#include "constants.hpp"
#include "SFML/Graphics/Rect.hpp"

std::vector<CarData> InitializeCarData()
{
	std::vector<CarData> data(static_cast<int>(CarType::kCarCount));

	data[static_cast<int>(CarType::kBasic)].m_hitpoints = 20;
	data[static_cast<int>(CarType::kBasic)].m_speed = 100.f;
	data[static_cast<int>(CarType::kBasic)].m_turnspeed = 20.f;
	data[static_cast<int>(CarType::kBasic)].m_maxturnspeed = 400.f;
	data[static_cast<int>(CarType::kBasic)].m_texture = TextureID::kCars;
	data[static_cast<int>(CarType::kBasic)].m_texture_rect = sf::IntRect({0, 0}, {60, 100});

	data[static_cast<int>(CarType::kJeep)].m_hitpoints = 30;
	data[static_cast<int>(CarType::kJeep)].m_speed = 90.f;
	data[static_cast<int>(CarType::kJeep)].m_turnspeed = 50.f;
	data[static_cast<int>(CarType::kJeep)].m_maxturnspeed = 360.f;
	data[static_cast<int>(CarType::kJeep)].m_texture = TextureID::kCars;
	data[static_cast<int>(CarType::kJeep)].m_texture_rect = sf::IntRect({ 60, 0 }, { 60, 100 });

	data[static_cast<int>(CarType::kTruck)].m_hitpoints = 50;
	data[static_cast<int>(CarType::kTruck)].m_speed = 50.f;
	data[static_cast<int>(CarType::kTruck)].m_turnspeed = 100.f;
	data[static_cast<int>(CarType::kTruck)].m_maxturnspeed = 50.f;
	data[static_cast<int>(CarType::kTruck)].m_texture = TextureID::kCars;
	data[static_cast<int>(CarType::kTruck)].m_texture_rect = sf::IntRect({ 120, 0 }, { 60, 100});

	data[static_cast<int>(CarType::kMonster)].m_hitpoints = 40;
	data[static_cast<int>(CarType::kMonster)].m_speed = 75.f;
	data[static_cast<int>(CarType::kMonster)].m_turnspeed = 300.f;
	data[static_cast<int>(CarType::kMonster)].m_maxturnspeed = 50.f;
	data[static_cast<int>(CarType::kMonster)].m_texture = TextureID::kCars;
	data[static_cast<int>(CarType::kMonster)].m_texture_rect = sf::IntRect({ 180, 0 }, { 60, 100});

	return data;
}

sf::IntRect GetCarTextureRect(CarType type)
{
	return InitializeCarData()[static_cast<int>(type)].m_texture_rect;
}