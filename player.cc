#include "player.h"
#include <iostream>
#include <sstream>
#include "ascii_graphics.h"
#include <vector>

using namespace std;

Player::Player(string name, vector<shared_ptr<Card>> deck, bool is_testing, int player_num)
	: name{name}, deck{deck}, is_testing{is_testing}, player_num{player_num}{
		deck_size = deck.size();
		for(int i = 0; i < 5; i++){
			draw();
		}
	}

string Player::inspect(int i){
	ostringstream oss;
	oss << "inspect " << i << "th minion on player ";
	oss  << player_num << "'s board" << endl;
	return oss.str();
}

void Player::discard(int i){
	if(hand_size == 0){
		cout << "no more cards to discard in your hand!" << endl;
	}
	else{
		hand.erase(hand.begin()+i-1);
		hand_size--;
	}
}

void Player::draw(){
	if(hand_size < MAX_HAND_SIZE){
		if(deck_size > 0){
			hand.push_back(deck[0]);
			hand_size++;
			deck.erase(deck.begin());
			deck_size--;
		}
		else{
			cout << "no more cards in deck!" << endl;
		}
	}
	else{
		cout << "your hand is full!" << endl;
	}
}


string Player::get_name(){
	return name;
}

int Player::get_life(){
	return life;
}

int Player::get_magic(){
	return magic;
}

shared_ptr<Card> Player::get_ritual(){
	return ritual;
}
//Player::change_life(int change){
//	this->life += change;
//}

void Player::change_magic(int change){
	if(is_testing){
		magic -= change;
		if(magic < 0){
			magic = 0;
		}
	}
	else{
		magic -= change;
	}
}

void Player::play_hand(int i){
	minion_on_board.emplace_back(hand.at(i-1));
	hand.erase(hand.begin()+i-1);
	minion_num++;
	hand_size--;
	//cout << hand.at(i)->get_name() <<endl;
}

string Player::display_hand(){
	vector<card_template_t> hand_print;
	ostringstream oss;
	oss << endl << "This is player" << player_num << "'s hand" << endl;
	
	for( auto i: hand ){
		hand_print.emplace_back(i->display());
	}
	for(int i = 0; i < 11; i++){
		for(int j = 0; j < hand_print.size(); j++){
			oss << hand_print[j][i];
		}
		oss << endl;
	}
	return oss.str();
}

card_template_t Player::display(){
	return display_player_card(player_num, name, life, magic);
}

vector<shared_ptr<Card>> Player::get_minion_on_board(){
	return minion_on_board;
}

int Player::get_minion_num(){
	return minion_num;
}
