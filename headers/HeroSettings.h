#pragma once


#include <iostream>
#include<vector>
#include<ctime>
#include<string>
#include "hero.h"
using namespace std;

class HeroSettings {
public:
	vector<Hero> heroes;


	void HeroCreating(int count) {
		vector<string> randomnames = { "Noah"	, "James" ,"Jack"	,"Connor"  ,	"Liam",	"John","Harry",	"Callum",	"Mason" ,	"Robert",	"Jacob"	,"Michael",	"Charlie",	"Kyle",	"William",	"Thomas" ,	"Joe" , 	"Ethan",	"David","George",	"Reece",	"Michael",	"Richard" , "Oscar" , 	"Rhys" , 	"Alexander",	"Joseph",		"Charles"	,"Damian",	"Daniel" };

		srand(static_cast<unsigned int>(time(NULL)));

		for (int i = 1; i <= count; i++) {
			int rname = rand() % randomnames.size();
			int hp = (1 + rand() % 100);
			int damage = (1 + rand() % 15);
			int speed = (1 + rand() % 5);

			Hero hero = Hero(randomnames[rname], hp, damage, speed);
			heroes.push_back(hero);
		}

	};






	void RemoveHero(string name) {
		for (int i = 0; i < heroes.size(); i++) {
			if (heroes[i].rName() == name)
				heroes.erase(heroes.begin() + i);
			break;
		}
	}


		int newHero(string name, int hp, int damage, int speed) {
			for (int i = 0; i < heroes.size(); i++) {
				if (heroes[i].rName() == name) {
					cout << "Try another name." << endl;
					return 0;
				}
			}
			Hero hero = Hero(name, hp, damage, speed);
			heroes.push_back(hero);
		}


		Hero rHero(string name) {
			for (int i = 0; i < heroes.size(); i++) {
				if (heroes[i].rName() == name) {
					return heroes[i];
				}
			}
		}
	
		void AllHeroes() {

			for (int i = 0; i < heroes.size(); i++) {
				cout << "Name: " << heroes[i].rName()
					<< "\tHP: " << heroes[i].rHP()
					<< "\tDamage: " << heroes[i].rDamage()
					<< "\tSpeed: " << heroes[i].rSpeed()
					<< endl;


			}
		}






	/*int getRandomName()
	{
		vector<string> randomnames = { "Noah"	, "James" ,"Jack"	,"Connor"  ,	"Liam",	"John","Harry",	"Callum",	"Mason" ,	"Robert",	"Jacob"	,"Michael",	"Charlie",	"Kyle",	"William",	"Thomas" ,	"Joe" , 	"Ethan",	"David","George",	"Reece",	"Michael",	"Richard" , "Oscar" , 	"Rhys" , 	"Alexander",	"Joseph",		"Charles"	,"Damian",	"Daniel" };

		return rand() % randomnames.size();
	}*/
};
