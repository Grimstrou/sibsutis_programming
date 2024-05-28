#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class zombie {
private:
	sf::Image *image;
	sf::Texture *texture;
	sf::Sprite *sprite;
	int health;

public:
	zombie(float y) {
		image = new sf::Image;
		texture = new sf::Texture;
		sprite = new sf::Sprite;

		if (image->loadFromFile("D:/sfml_project1/gamesfml/Image/zombie.png") != 1) {
			std::cout << "Error@!";
		}
		
		texture->loadFromImage(*image);
		sprite->setTexture(*texture);
		sprite->setScale(0.1, 0.1);
		sprite->setPosition(1300, y);
		health = 2;
	}
	
	sf::Sprite getImage() {
		return *sprite;
	}

	int getHealth() {
		return health;
	}

	void damage() {
		health -= 1;
	}

	void move() {
		sf::Vector2f pos = sprite->getPosition();
		sprite->setPosition(pos.x - 0.08, pos.y);
	}

	float getX() {
		return sprite->getPosition().x;
	}

	void del() {
		delete sprite;
		delete image;
		delete texture;

	}

};