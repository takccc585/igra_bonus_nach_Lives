#pragma once
#include "settings.h"

class Enemy {
private:
	sf::RenderWindow window;
	sf::Sprite sprite;
	sf::Texture texture;
	float speedx, speedy;
public:
	Enemy() {
		texture.loadFromFile("images\\cat.png");
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH / 8, WINDOW_HEIGHT / 8);
		sprite.setScale(0.1, 0.1);
	}
	void update(sf::Vector2f pos) {
		float dX = pos.x - sprite.getPosition().x;
		float dY = pos.y - sprite.getPosition().y;
		float rotation = (atan2(dY, dX)) * 180 / 3.14159265;
		sprite.setRotation(rotation + 90);
		float distance = std::sqrt(dX * dX + dY * dY);
		if (distance > Espeed)
		{
			sprite.move(Espeed * dX / distance, Espeed * dY / distance);
		}
	}
	void SetPosition(float x, float y) {
		sprite.setPosition(x, y);
	};

	sf::Sprite getSprite() { return sprite; }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};