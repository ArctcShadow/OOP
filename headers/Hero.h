#pragma once

#include <iostream>
using namespace std;
class Hero {

public:
	
	Hero() {
		name = " ";
		hp = 0;
		damage = 0;
		speed = 0;
   
	}

	Hero(string name , int hp , int damage , short int speed) {
		if (name != " ") this-> name = name;
		if (hp > 0) this-> hp = hp;
		if (damage > 0) this-> damage = damage;
		if (speed > 0) this-> speed = speed;
 


	}
	string rName() {
		return name;

	}

	int rHP() {
		return hp;
	}
	int rDamage() {
		return damage;
	}
	short int rSpeed() {
		return speed;
	}

private:
	int hp;
	int damage;
	short int speed;
	string name;



};