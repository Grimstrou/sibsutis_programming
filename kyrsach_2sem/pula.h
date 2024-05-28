#pragma once
#include <SFML/Graphics.hpp> 

class pula {
private:
	sf::Image* image;
	sf::Texture* texture;
	sf::Sprite* sprite;

public:
	pula(float y) {
		image = new sf::Image;
		texture = new sf::Texture;
		sprite = new sf::Sprite;
		image->loadFromFile("D:/sfml_project1/gamesfml/Image/pula.png");
		texture->loadFromImage(*image);
		sprite->setTexture(*texture);
		sprite->setScale(0.04, 0.04);
		sprite->setPosition(30, y);
	}


	sf::Sprite getImage() {
		return *sprite;
	}

	void move() {
		sf::Vector2f pos = sprite->getPosition();
		sprite->setPosition(pos.x + 0.15, pos.y);
	}

	float getX() {
		return sprite->getPosition().x;
	}

	void del() {
		delete image;
		delete texture;
		delete sprite;
	}
};