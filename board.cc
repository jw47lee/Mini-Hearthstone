#include "board.h"
#include <sstream>
#include <vector>
#include "ascii_graphics.h"
using namespace std;


Board::Board(shared_ptr<Player> p1, shared_ptr<Player> p2)
	:p1{p1}, p2{p2}{}

void Board::play(int play_i){
	if(player1_turn){
//		p1->play(play_i, this);
	}
	else{
//		p2->play(play_i, this);
	}
}


string Board::inspect(int i){
	if(player1_turn){
		return "player 1 inspect";
	}
	else{
		return "player 2 inpspect";
	}
}

void Board::discard(int discard_i){
	if(player1_turn){
		p1->discard(discard_i);
	}
	else{
		p2->discard(discard_i);
	}
}

void Board::draw(){
	if(player1_turn){
		p1->draw();
	}
	else{
		p2->draw();
	}
}


string Board::display_hand(){
	ostringstream oss;
	if(player1_turn){
		oss << "display player 1 hand!" << endl;
		oss << p1->display_hand() << endl;
	}
	else{
		oss << "display player 2 hand!" << endl;
		oss << p2->display_hand() << endl;
	}
	return oss.str();
}

void Board::end_turn(){
	player1_turn = !(player1_turn);
}

string Board::display(){
	vector<card_template_t> one;
	vector<card_template_t> centre;
	vector<card_template_t> two;
	vector<card_template_t> one_minion;
	vector<card_template_t> two_minion;

	ostringstream oss;	

	card_template_t head(167, EXTERNAL_BORDER_CHAR_LEFT_RIGHT);

        one.emplace_back(WALL);
//	if(p1->get_ritual()){
//		one.emplace_back(p1->get_ritual()->display());
//	}
//	else{
		one.emplace_back(CARD_TEMPLATE_BORDER);
//	}//ritual
        one.emplace_back(CARD_TEMPLATE_EMPTY);
        one.emplace_back(p1->display());
        one.emplace_back(CARD_TEMPLATE_EMPTY);
        one.emplace_back(CARD_TEMPLATE_BORDER); // graveyard
        one.emplace_back(WALL);

	one_minion.emplace_back(WALL);
	int p1_minion_num = p1->get_minion_num();
	for(int i = 0; i < p1_minion_num; i++){
		one_minion.emplace_back(p1->get_minion_on_board()[i]->display());
	}
	for(int i = 0; i < 5 - p1_minion_num; i++){
			one_minion.emplace_back(CARD_TEMPLATE_BORDER);

	}
	one_minion.emplace_back(WALL);

	centre.emplace_back(CENTRE_GRAPHIC);

	two_minion.emplace_back(WALL);
	int p2_minion_num = p2->get_minion_num();
	for(int i = 0; i < p2_minion_num; i++){
		two_minion.emplace_back(p2->get_minion_on_board()[i]->display());
	}
	for(int i = 0; i < 5 - p2_minion_num; i++){
		two_minion.emplace_back(CARD_TEMPLATE_BORDER);
	}
	two_minion.emplace_back(WALL);

        two.emplace_back(WALL);
//	if(p2->get_ritual()){
//		two.emplace_back(p2->get_ritual()->display());
//	}
//	else{
		two.emplace_back(CARD_TEMPLATE_BORDER);
//	}
        two.emplace_back(CARD_TEMPLATE_EMPTY);
        two.emplace_back(p2->display());
        two.emplace_back(CARD_TEMPLATE_EMPTY);
        two.emplace_back(CARD_TEMPLATE_BORDER);//graveyard
        two.emplace_back(WALL);
	
	//player1
	for(auto h : head){
		oss << h;
	}
	oss << endl;
	for(int i = 0; i < 11; i++){
		for(int j = 0; j < one.size(); j++){
			oss << one[j][i];
		}
		oss << endl;
	}
        for(int i = 0; i < 11; i++){
                for(int j = 0; j < one_minion.size(); j++){
                        oss << one_minion[j][i];
                }
                oss << endl;
        }
	//centre
	
	for(int i = 0; i < 10; i++){
		for(int j = 0; j < centre.size(); j++){
			oss << centre[j][i];
		}
		oss << endl;
	}	

	//player2

        for(int i = 0; i < 11; i++){
                for(int j = 0; j < two_minion.size(); j++){
                        oss << two_minion[j][i];
                }
                oss << endl;
        }


	for(int i = 0; i < 11; i++){
		for(int j = 0; j < two.size(); j++){
			oss << two[j][i];
		}
		oss << endl;
	}

	for(auto i : head){
		oss << i;
	}
	oss << endl;
	return oss.str();
}





