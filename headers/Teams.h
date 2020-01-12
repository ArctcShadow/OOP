#pragma once
#include<iostream>
#include"Hero.h"
#include"Player.h"
using namespace std;

class Teams {
public:
	
	
	Player player;
	Hero hero;
	Teams(Player& player, Hero& hero) {


		this->player = player;
		this->hero = hero;

	}


};