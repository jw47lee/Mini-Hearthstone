#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <sstream>
#include <chrono>
#include <vector>
#include <memory>
#include "card.h"
#include "board.h"
#include "card_list.h"
#include "player.h"
using namespace std;

void cmd_help(){
	cout << "Commands: help -- Display this message." << endl;
	cout << "          end -- End the current player's turn." << endl;
	cout << "          quit -- End the game." << endl;
	cout << "          attack minion other-minion";
	cout << " -- Orders minion to attack other-minion." << endl;
	cout << "          attack minion -- Orders minion to attack the opponent." << endl;
	cout << "          play card [target-player target-card]";
	cout << "-- Play card, optionally targeting target-card owned by target-player." << endl;
	cout << "          use minion [target-player target-card] ";
	cout << "-- Use minion's special ability, optionally targeting ";
	cout << "target-card owned by target-player." << endl;
	cout << "          inspect minion -- View a minion's card and ";
	cout << "all enchantments on that minion." << endl;
	cout << "          hand -- Describe all cards in your hand." << endl;
	cout << "          board -- Describe all cards on the board." << endl;
}


vector<shared_ptr<Card>> load_deck(string deck_name){
	ifstream deck(deck_name);
	string card_name;
	vector<shared_ptr<Card>> cards;
	while(getline(deck, card_name)){
		if(card_name == "Air Elemental"){
			shared_ptr<Card> air_elemental(new AirElemental());
			cards.emplace_back(air_elemental);
		}
		else if(card_name == "Earth Elemental"){
			shared_ptr<Card> earth_elemental(new EarthElemental());
			cards.emplace_back(earth_elemental);
		}
/*	
		//TriggerMinion
		else if(card_name == "Bone Golem"){
			shared_ptr<Card> bg(new BoneGolem());
			cards.emplace_back(bg);
		}
		else if(card_name == "Fire Elemental"){
			shared_ptr<Card> fe(new FireElemental());
			cards.emplace_back(fe);
		}
		else if(card_name == "Potion Seller"){
			shared_ptr<Card> ps(new PotionSeller());
			cards.emplace_back(ps);
		}

		//AbilityMinion
		else if(card_name == "Master Summoner"){
			shared_ptr<Card> ms(new MasterSummoner());
			cards.emplace_back(ms);
		}
		else if(card_name == "Apprentice Summoner"){
			shared_ptr<Card> as(new ApprenticeSummoner());
			cards.emplace_back(as);
		}
		else if(card_name == "Novice Pyromancer"){
			shared_ptr<Card> np(new NovicePyromancer());
			cards.emplace_back(np);
		}
*/
/*
		// Enchantment
		else if(card_name == "Giant Strength"){
			shared_ptr<Card> g(new GiantStrength());
			cards.emplace_back(g);
		}
		else if(card_name == "Enrage"){
			shared_ptr<Card> e(new Enrage());
			cards.emplace_back(e);
		}
		else if(card_name == "Haste"){
			shared_ptr<Card> h(new Haste());
			cards.emplace_back(h);
		}
		else if(card_name == "Silence"){
			shared_ptr<Card> s(new Silence());
			cards.emplace_back(s);
		}
		else if(card_name == "Magic Fatigue"){
			shared_ptr<Card> mf(new MagicFatigue());
			cards.emplace_back(mf);
		}

		// Ritual
		else if(card_name == "Dark Ritual"){
			shared_ptr<Card> dr(new DarkRitual());
			cards.emplace_back(dr);
		}
		else if(card_name == "Aura of Power"){
			shared_ptr<Card> ap(new AuraOfPower());
			cards.emplace_back(ap);
		}
		else if(card_name == "Standstill"){
			shared_ptr<Card> ss(new Standstill());
			cards.emplace_back(ss);
		}

		//Spell
		else if(card_name == "Unsummon"){
			shared_ptr<Card> u(new Unsummon());
			cards.emplace_back(u);
		}
		else if(card_name == "Recharge"){
			shared_ptr<Card> rc(new Recharge());
			cards.emplace_back(rc);
		}
		else if(card_name == "Raise Dead"){
			shared_ptr<Card> rd(new RaiseDead());
			cards.emplace_back(rd);
		}
		else if(card_name == "Banish"){
			shared_ptr<Card> bn(new Banish());
			cards.emplace_back(bn);
		}
		else if(card_name == "Disenchant"){
			shared_ptr<Card> dc(new Disenchant());
			cards.emplace_back(dc);
		}
		else if(card_name == "Blizzard"){
			shared_ptr<Card> b(new Blizzard());
			cards.emplace_back(b);
		}
*/
	}
	return cards; 
}

void sleep(int x){
	this_thread::sleep_for(chrono::seconds(x));
}

int main(int argc, char const *argv[]){
	cout << "Welcome to Sorcery!!" << endl << endl;
	sleep(1);
	cout << "I'm reading your command lines so I can set up the game!";
	cout << endl << endl;

	string default_deck_name = "default.deck";
	string player1_deck_name = default_deck_name;
	string player2_deck_name = default_deck_name;
	int percentage = 100 / argc;
	bool is_testing = false;
	bool is_graphic = false;

	string player1_name;
	string player2_name;

	bool is_init = false;
	string init_cmd;
	stringstream ss;
	ifstream init_file;	

//	bool player1_turn = true;	

	//Board board;
	for(int i = 1; i < argc; i++){
		sleep(1);
		string arg = argv[i];
		cout << "loading... " << percentage * i << "% completed!" << endl;
		if(arg == "-deck1"){
			cout << "custom deck is selected for player1" << endl;
			i++;
			player1_deck_name = argv[i];
			cout << "your custom deck name is ";
			cout << player1_deck_name << endl;

		}
		else if(arg == "-deck2"){
			cout << "custom deck is selected for player2" << endl;
			i++;
			player2_deck_name = argv[i];
			cout << "your custom deck name is ";
			cout << player2_deck_name << endl;

		}
		else if(arg == "-init"){
			cout << "init mode is on!!" << endl;
			is_init = true;
			i++;
			string init_file_name = argv[i];
			cout << "Commands in \"" << init_file_name;
			cout  << "\" file will be inputed" << endl;
			sleep(1);
			
			ifstream init_file(init_file_name);
			init_file >> player1_name;
			init_file >> player2_name;
			string store;
			while(init_file >> store){
				init_cmd += store + " ";	
			}
			ss.str(init_cmd);
		}	
		else if(arg == "-testing"){
			cout << "testing mode is on!!" << endl;
			is_testing = true;
		}
		else if(arg == "-graphics"){
			cout << "graphics mode is on!" << endl;
			is_graphic = true;
		}
		cout << endl;
	} // for
	
	//Player player1{load_deck(player1_deck_name);
	cout << "loading..." << "100% completed!" << endl << endl;
	cout << "Let's start the game!!" << endl << endl;
	
	if(!is_init){
		cout << "Enter your player1 name:" << endl;
		cin >> player1_name;
		cout << "Enter your player2 name:" << endl;
		cin >> player2_name;

	}
	
	cout << "player 1 name is: " << player1_name << endl;
	cout << "player 2 name is: " << player2_name << endl;

	shared_ptr<Player> player1(new Player(player1_name, 
		load_deck(player1_deck_name), is_testing, 1));
	cout << "player1's deck loaded!" << endl;
	shared_ptr<Player> player2(new Player(player2_name, 
		load_deck(player2_deck_name), is_testing, 2));	
	cout << "player2's deck loaded!" << endl;
	

	Board board(player1, player2);
	while(true){
		string cmd;
		if(is_init){
			if(ss.eof()){
				is_init = false;
				cout << endl << "no more init command" << endl << endl;
				cout << "please enter your command: " << endl;
				cin >> cmd;
			}
			else ss >> cmd;
		}
		else{
			cout << "please enter your command: " << endl;
			cin >> cmd;
		}
		if(cin.eof()){
			cout << endl;
			cout << "program terminated. Ends the game";
			cout << endl; 
			break;
		}		
		if(cmd == "help"){ cmd_help();}
		else if(cmd == "quit"){
			cout << "Quit the game. No winner!!" << endl;
			return 0;
		}
		else if(cmd == "board"){
			cout << board.display() << endl;
		}

		else if(cmd == "hand"){
			cout << board.display_hand() << endl;
		}

		else if(cmd == "end"){
			cout << "end turn" << endl;
			board.end_turn();
		}
/*
		else if(cmd == "play"){
			int index;
			cin >> index;
			if(player1_turn){
				cout << "player1 play a minion" << endl;
				player1->play_hand(index);
			}
			else{
				cout << "player2 play a minion" << endl;
				player2->play_hand(index);
			}
		}
*/


		else if(cmd == "draw"){
			if(!is_testing){
				cout << "draw command is only available in -testing mode" << endl;
			}
			else{
				board.draw();
			}
		}

		else if(cmd == "discard"){
			if(!is_testing){
				cout << "discard command is only available in -testing mode" << endl;
			}
			else{
				int discard_i;
				ss >> discard_i;
				if(ss.fail()){
					cin >> discard_i;
				}
				board.discard(discard_i);
			}
		} // discard
		else if(cmd == "inspect"){
			int inspect_i;
			ss >> inspect_i;
			if(ss.fail()){
				cout << "enter a number of minion to inspect" << endl;
				cin >> inspect_i;
			}
			cout << board.inspect(inspect_i) << endl;			
		}
		else if(cmd == "use"){
			cout << "command use!" << endl;
		}
		else if(cmd == "play"){
			cout << "command play1" << endl;
			int play_i;
			ss >> play_i;
			if(ss.fail()){
				cout << "enter a number to play a card in your hand!" << endl;
				cin >> play_i;
			}
//			board.play(play_i);
		}
		else if(cmd == "attack"){
			cout << "command attack!" << endl;
		}
	} // while
	return 0; 
}

