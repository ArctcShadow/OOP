#pragma once
#include<iostream>
#include"GameSession.h"
#include<vector>


using namespace std;

class SessionPerforming {
public:

	vector<GameSession> sessions;



	void Performing(vector<Player>& players, vector<Hero>& heroes, int num) {
		for (int i = 0; i < num; i++) {
			GameSession session(players, heroes);
			session.Start(players);
			session.BTPlayers();
			session.RTPlayers();
			sessions.push_back(session);
		}
	}




	
};







