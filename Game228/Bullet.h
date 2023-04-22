#pragma once
#include<SFML/Graphics.hpp>
#include <random>
using namespace sf;
class Bullet
{
public:
	Sprite m_Sprite;
	Texture m_Texture;
	Bullet();
	float m_Speed;
	float time;
	Vector2f m_Position;
	Sprite getSprite();
	void move()
	{
			m_Position.y -= m_Speed;
	}
	void update(float elapsedTime)
	{
		m_Sprite.setPosition(m_Position);
	}
};