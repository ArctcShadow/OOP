#pragma once

#include<iostream>
#include<string>
#include<ctime>

using namespace std;

class Player {



public:

	void setName(string name) {
		this->name = name;
		
	}

	string rName() {
		return name;
	}

	int rID() {
		
		return ID;
	}
	int rRating() {
		return rating;
	}

	void addRating() {
		
		rating +=25;
	}
	void loseRating() {
		if (rating >=25)rating -= 25;
	}

	Player() {
		name = " ";
		rating = 1000;
		ID = 0;
	}

	Player(string name, int rating, int ID) {
		this->name = name;
		this->rating = rating;
		this->ID = ID;
	}
private:
	string name;
	int rating;
	int ID;



};