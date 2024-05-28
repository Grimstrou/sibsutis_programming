#pragma once
#include <SFML/Graphics.hpp> 

class pushka {
private:
	sf::Image* image;
	sf::Texture* texture;
	sf::Sprite* sprite;
	bool fire;

public:
	pushka(float y) {
		image = new sf::Image;
		texture = new sf::Texture;
		sprite = new sf::Sprite;
		image->loadFromFile("D:/sfml_project1/gamesfml/Image/turel.png");
		texture->loadFromImage(*image);
		sprite->setTexture(*texture);
		sprite->setScale(0.20, 0.20);
		sprite->setPosition(30, y);
		fire = false;
	}

	void swap(float y) {
		image = new sf::Image;
		texture = new sf::Texture;
		sprite = new sf::Sprite;
		if (fire == false) {
			image->loadFromFile("D:/sfml_project1/gamesfml/Image/turel1.png");
			texture->loadFromImage(*image);
			sprite->setTexture(*texture);
			sprite->setScale(0.20, 0.20);
			sprite->setPosition(30, y);
			fire = true;
		}
		else {
			image = new sf::Image;
			texture = new sf::Texture;
			sprite = new sf::Sprite;
			image->loadFromFile("D:/sfml_project1/gamesfml/Image/turel.png");
			texture->loadFromImage(*image);
			sprite->setTexture(*texture);
			sprite->setScale(0.20, 0.20);
			sprite->setPosition(30, y);
			fire = false;
		}
	}


	sf::Sprite getImage() {
		return *sprite;
	}
};


