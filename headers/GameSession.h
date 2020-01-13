#pragma once
#include "Player.h"
#include "Hero.h"
#include "Teams.h"

#include <fstream>
#include <iostream>
#include<ctime>
#include<vector>
#include <stdio.h>
#include <dos.h>
#include <Windows.h>

using namespace std;

template <typename T>


void randVector(vector<T>& vec) {
	srand(static_cast<unsigned int>(time(NULL)));
	for (int i = 0; i < vec.size(); i++) {
		swap(vec[i], vec[rand() % vec.size()]);
	}
}
class GameSession {
public:

	vector<Teams> TeamRed;
	vector<Teams> TeamBlue;
	vector<Hero> initHeroes;
	vector<Teams> TeamSave;





	string arr[3] = { "Tie", "Blue", "Red" };
	int winner = 999;
	  void GameSet() {
		  int BlueHP = 0; int RedHP = 0; int BlueDMG = 0; int RedDMG = 0;
          for (int i = 0; i < TeamBlue.size(); i++) {
			  BlueHP += TeamBlue[i].hero.rHP();
			  BlueDMG += TeamBlue[i].hero.rDamage();
		  }
		  for (int i = 0; i < TeamRed.size(); i++) {
			  RedHP += TeamRed[i].hero.rHP();
			  RedDMG += TeamRed[i].hero.rDamage();
		  }

		  if (BlueHP - RedDMG > RedHP - BlueDMG) {
			  winner = 1;
		  }
		  else if (BlueHP - RedDMG == RedHP - BlueDMG) {
			  winner = 0;
		  }
		  else {
			  winner = 2;
		  }
	  }

	  void ChangeRating(vector<Player>& players) {

		  for (int i = 0; i < TeamBlue.size(); i++) {

			  int idBlue = TeamBlue[i].player.rID();
			  int idRed = TeamRed[i].player.rID();
				  for (int j = 0; j < players.size(); j++)
			  {


				  switch (winner) {
				  case 1:
					  
					  if (players[j].rID() == idBlue) players[j].addRating();
					  if (players[j].rID() == idRed) players[j].loseRating();
					  break;
				  case 2:
					  
					  if (players[j].rID() == idRed) players[j].addRating();
					  if (players[j].rID() == idBlue) players[j].loseRating();
					  break;
				  }
			  }
		  }
	  }
	  void WinnerAnnouncement() {
      if (winner > 0) {
			  cout << arr[winner] << " won this game" << endl;
		  }
		  else {
			  cout << arr[winner] << "won"<<endl;
		  }
	  }


	
	

	  GameSession(vector<Player>& players, vector<Hero>& heroes) {

		  for (int i = 0; i < heroes.size(); i++) {
			  initHeroes.push_back(heroes[i]);
		  }

		  randVector(players);
		  randVector(initHeroes);


		  for (int i = 0; i < 10; i++) {
			  if (initHeroes.size() < 10) {
				  if (i < 5) {
					  Teams t = Teams(players[i], initHeroes[i]);
					  TeamSave.push_back(t);
				  }
				  else {
					  Teams t = Teams(players[i], initHeroes[i - 5]);
					  TeamSave.push_back(t);
				  }
			  }
			  else {
				  Teams t = Teams(players[i], initHeroes[i]);
				  TeamSave.push_back(t);
			  }
		  }
	  AddTeamPart();
		  
		  for (int i = 0; (!CorrectRating() || !CorrectPlayers()) && i < 10000; i++)
		  {
			  randVector(TeamSave);
			  TeamBlue.clear();
			  TeamRed.clear();
			  AddTeamPart();
		  }

		  
		  Sleep(1000);
	}


		  ~GameSession() {
			  initHeroes.clear();
			  TeamRed.clear();
			  TeamBlue.clear();
			  TeamSave.clear();
		  }




		  void RTPlayers() {
			  
			  for (int i = 0; i < TeamRed.size(); i++)
			  {
				  
				  cout << "Name: " << TeamRed[i].player.rName() << "\tID: " << TeamRed[i].player.rID() << "\tRank: " << TeamRed[i].player.rRating() << endl;
					  
				  
				  cout << "Name: " << TeamRed[i].hero.rName() << "\tHP: " << TeamRed[i].hero.rHP() << "\tDamage: " << TeamRed[i].hero.rDamage() << "\tSpeed: " << TeamRed[i].hero.rSpeed() << endl << (i == TeamRed.size() - 1 ? "" : "------------------------------------------------") << endl;
					  
			  }
			  cout <<  endl;
		  }

		  void BTPlayers() {
			  
			  for (int i = 0; i < TeamBlue.size(); i++)
			  {
				  
				  cout << "Name: " << TeamBlue[i].player.rName() << "\tID: " << TeamBlue[i].player.rID() << "\tRank: " << TeamBlue[i].player.rRating() << endl;
					 
				  
				  cout << "Name: " << TeamBlue[i].hero.rName() << "\tHP: " << TeamBlue[i].hero.rHP() << "\tDamage: " << TeamBlue[i].hero.rDamage() << "\tSpeed: " << TeamBlue[i].hero.rSpeed() << endl << (i == TeamBlue.size() - 1 ? "" : "------------------------------------------------") << endl;

			  }
			  cout << endl;
		  }

		  void Start(vector<Player>& players) {
			  time_t StartTime = time(0);
			  GameSet();
			  WinnerAnnouncement();
			  ChangeRating(players);
		  }

		  void AddTeamPart() {
			  for (int i = 0; i < TeamSave.size(); i++) {
				  if (i < 5) {
					  TeamBlue.push_back(TeamSave[i]);
				  }
				  else {
					  TeamRed.push_back(TeamSave[i]);
				  }
			  }
		  }


		 




		  bool CorrectRating() {
			  int RatingRed = 0, RatingBlue = 0;
			  for (int i = 0; i < TeamRed.size(); i++) {
				  RatingRed += TeamRed[i].player.rRating();
				  RatingBlue += TeamBlue[i].player.rRating();
			  }
			  if (fabs(RatingBlue - RatingRed) >= 100)	return false;
			  return true;
		  }

		  bool CorrectPlayers() {
			  int maxBlue = 0, maxRed = 0, minBlue = 999999, minRed = 999999;

			  for (size_t i = 0; i < TeamBlue.size(); i++)
			  {
				  if (TeamBlue[i].player.rRating() > maxBlue) maxBlue = TeamBlue[i].player.rRating();
				  if (TeamBlue[i].player.rRating() < minBlue) minBlue = TeamBlue[i].player.rRating();

				  if (TeamRed[i].player.rRating() > maxRed) maxRed = TeamRed[i].player.rRating();
				  if (TeamRed[i].player.rRating() < minRed) minRed = TeamRed[i].player.rRating();
			  }

			  if (maxBlue - minBlue >= 200 || maxRed - minRed >= 200) return false;

			  return true;


		  }




};