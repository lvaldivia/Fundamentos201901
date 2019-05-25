#include "Player.h"



Player::Player()
{
	color.r = 255;
	color.g = 0;
	color.b = 255;
	color.a = 255;
}



Player::~Player()
{
}

void Player::init(float speed, glm::vec2 position,
	InputManager* inputmanager) {

}


void Player::update(const std::vector<std::string>& leveldata,
	std::vector<Human*> & humans,
	std::vector<Zombie*>& zombies) {

}
