#pragma once
#include <iostream>
#include "Player.h"
#include <vector>
using namespace std;

class PlayerSettings {

public:
	vector<Player> players;

	void PlayerCreating(int count) {

		vector<string> randomNames = { "Magnor","Oddfird","Tirion","Ned","Olav","Noss","Mikal","Milldri","Mjolnir","Maelstorm","Sansa","Brienna","Norn","Norge","Ragnor","Regin","Roar","Osk","Rotland","Jord","Jorunn","Klaf","Keki" };

		srand(static_cast<unsigned int>(time(NULL)));

		for (int i = 1; i <= count; i++) {
			int rname= rand() % randomNames.size();
			Player player = Player(randomNames[rname], 1000, i++);
			players.push_back(player);


		}

	}

	void AllPlayers() {

		for (int i = 0; i < players.size(); i++) {

			cout << "Name: " << players[i].rName()
				<< "\tRating: " << players[i].rRating()
				<< "\tID: " << players[i].rID()
				
				<< endl;

		}



	}

	void AddPlayer(string name) {
		int id = players[players.size() - 1].rID() + 1;
		Player player = Player(name, 1000, id);
		players.push_back(player);
	}
	void RemovePlayer(int id) {
		for (int i = 0; i < players.size(); i++) {
			if (players[i].rID() == id) players.erase(players.begin() + i);
			break;
		}
	}


	Player GetPlayerByName(string name) {
		for (int i = 0; i < players.size(); i++) {
			if (players[i].rName() == name) {
				return players[i];
			}
		}
	}
	Player GetPlayerById(int id) {
		for (int i = 0; i < players.size(); i++) {
			if (players[i].rID() == id) {
				return players[i];
			}
		}
	}




};