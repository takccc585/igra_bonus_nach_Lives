#pragma once
#include "settings.h"


class Player {
private:
	sf::RenderWindow window;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Mouse mouse;
	float angle;
	float speedx, speedy;
	sf::Clock timerP;
	int lives = MAX_PLAYER_LIVES - 7;
	int speedBonusActivateTime;
	bool speedBonusActivate = false;

public:
	Player() {
		texture.loadFromFile("images\\spaceShips_002.png");
		sprite.setTexture(texture);
		sf::Vector2i localPosition = sf::Mouse::getPosition(window);
		sf::FloatRect bounds = sprite.getGlobalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		timerP.restart();
	}
	void update() {

		float dX = mouse.getPosition().x - sprite.getPosition().x;
		float dY = mouse.getPosition().y - sprite.getPosition().y;
		float rotation = (atan2(dY, dX)) * 180 / 3.14159265;
		sprite.setRotation(rotation + 90);
		float distance = std::sqrt(dX * dX + dY * dY);
		if (distance > Pspeed)
		{
			sprite.move(Pspeed * dX / distance, Pspeed * dY / distance);
		}
	}

	void playerAddLife() { lives++; }
	void playerMinusLife() { 
		lives--;
	}
	int getLives() { return lives; }
	void addLives();
	void addSpeed();

	void addLives(int lives) {
		this->lives += lives;
		if (lives > MAX_PLAYER_LIVES) {
			lives = MAX_PLAYER_LIVES;
		}
	}

	void addSpeed(int Pspeed) {
		Pspeed *= 2;
		speedBonusActivateTime = timerP.getElapsedTime().asMilliseconds();
	}
	void SetPosition(float x, float y) {
		sprite.setPosition(x,y);
	};

	sf::Sprite getSprite() { return sprite; }
	sf::Vector2f getPosition() { return sprite.getPosition(); }
	sf::FloatRect getHitBox() { return sprite.getGlobalBounds(); }
};