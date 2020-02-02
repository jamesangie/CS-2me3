/**
 * \file GameBoard.cpp
 * \brief The implementation of the Forty Thieves solitaire boardT ADT described in GameBoard.h.
 * \author James Zhang, MacID: zhany111
 * \date March 19, 2019
*/

using namespace std;

#include "GameBoard.h"
#include "CardStack.h"
#include "CardTypes.h"
#include "ex.h"

BoardT::BoardT(CardStackT deck) {

	if(!(two_decks(init_seq(10), init_seq(8), CardStackT(deck), CardStackT()))) throw invalid_argument();

	std::vector<CardStackT> tt;
	for(int i = 0; i < 10; i++){
		CardStackT a;
		a.push(deck.top());
		deck = deck.pop();
		a.push(deck.top());
		deck = deck.pop();
		a.push(deck.top());
		deck = deck.pop();
		a.push(deck.top());
		deck = deck.pop();
		tt.push_back(a);
	}



	CardStackT w;
	this->T = tt;
	this->F = init_seq(8);
	this->W = w;
	this->D = deck;
}

bool BoardT::is_valid_tab_mv(CategoryT c, unsigned int n0, unsigned int n1) {
	if(c == Tableau) {
		if (!(is_valid_pos(Tableau, n0) && is_valid_pos(Tableau, n1))){
			throw out_of_range();
		}
		return valid_tab_tab(n0, n1);
	}
	if(c == Foundation){
		if (!(is_valid_pos(Tableau, n0) && is_valid_pos(Foundation, n1))) {
			throw out_of_range();
		}
		return valid_tab_foundation(n0,n1);
	}
	return false;
}

bool BoardT::is_valid_waste_mv(CategoryT c, unsigned int n) {
	if(this->W.size() == 0) throw invalid_argument();
	if(c == Tableau) {
		if (!(is_valid_pos(Tableau, n))){
			throw out_of_range();
		}
		return valid_waste_tab(n);
	}
	if(c == Foundation){
		if (!(is_valid_pos(Foundation, n))) {
			throw out_of_range();
		}
		return valid_waste_foundation(n);
	}
	if(c == Deck || c == Waste) return false;
	return true;
}


bool BoardT::is_valid_deck_mv(){
	return this->D.size() != 0;
}

void BoardT::tab_mv(CategoryT c, unsigned int n0, unsigned int n1){
	if(!(is_valid_tab_mv(c, n0, n1))) throw invalid_argument();

	if (c == Tableau) {
		this->T[n1] = this->T[n1].push(this->T[n0].top());
		this->T[n0] = this->T[n0].pop();
	}
	if (c == Foundation) {
		this->F[n1] = this->F[n1].push(this->T[n0].top());
		this->T[n0] = this->T[n0].pop();
	}
}

void BoardT::waste_mv(CategoryT c, unsigned int n){
	if(!(is_valid_waste_mv(c, n))) throw invalid_argument();

	if (c == Tableau) {
		this->T[n] = this->T[n].push(this->W.top());
		this->W = this->W.pop();
	}
	if (c == Foundation) {
		this->F[n] = this->F[n].push(this->W.top());
		this->W = this->W.pop();
	}
}

void BoardT::deck_mv(){
	if (!(is_valid_deck_mv())) throw invalid_argument();

	this->W = this->W.push(this->D.top());
	this->D = this->D.pop();
}

CardStackT BoardT::get_tab(unsigned int n){
	if(!is_valid_pos(Tableau, n)) throw out_of_range();
	return this->T[n];
}

CardStackT BoardT::get_foundation(unsigned int n) {
	if(!is_valid_pos(Foundation, n)) throw out_of_range();
		return this->F[n];
}

CardStackT BoardT::get_deck() {
	return this->D;
}

CardStackT BoardT::get_waste() {
	return this->W;
}

bool BoardT::valid_mv_exists() {
	bool a0 = false;
	for(int i = 0; i < 8; i ++) {
		for (int j = 0; j < 10; j++){
			bool a = is_valid_tab_mv(Tableau, i, j);
			a0 = a0 || a;
		}
	}
	bool b0 = false;
	for(int i = 0; i < 8; i ++) {
			for (int j = 0; j < 8; j++){
				bool b = is_valid_tab_mv(Foundation, i, j);
				b0 = b0 || b;
			}
		}
	bool c0 = false;
	for (int i = 0; i < 8; i++){
		bool c = is_valid_waste_mv(Foundation, i);
		c0 = c || c0;
	}
	bool d0 = false;
	for (int i = 0; i < 10; i++){
			bool d = is_valid_waste_mv(Tableau, i);
			d0 = d || d0;
		}
	return a0 || b0 || c0 || d0 || is_valid_deck_mv();
}

bool BoardT::is_win_state() {
	int s = 0;
	for(int i = 0; i < 8; i++){
		s += cnt_cards_stack(F[i], true);
	}
	return s == 104;
}

/****** private local functions ******/

bool BoardT::two_decks(std::vector<CardStackT> T, std::vector<CardStackT> F, CardStackT D, CardStackT W) {
	for (unsigned int st = 0; st < 4; st ++) {
		for (RankT rk = ACE; rk <= KING; rk++) {
			//should count for cards in a deck
		}
	}


	return true;
}

unsigned int BoardT::cnt_cards_seq(std::vector<CardStackT> S, bool f){
	unsigned int a = 0;
	for (int i = 0; i < S.size(); i++) {
		a += cnt_cards_stack(S[i], f);
	}
	return a;
}

unsigned int BoardT::cnt_cards_stack(CardStackT S, bool f){
	unsigned int a = 0;
	for (int i = 0; i < S.size(); i++) {
		if(f == true){
			a += 1;
		}
	}
	return a;
}

unsigned int BoardT::cnt_cards(std::vector<CardStackT> T, std::vector<CardStackT> F, CardStackT D, CardStackT W, bool f) {
	return cnt_cards_seq(T, f) + cnt_cards_seq(F, f) + cnt_cards_stack(D, f)+cnt_cards_stack(W, f);
}

std::vector<CardStackT> BoardT::init_seq(unsigned int n) {
	std::vector<CardStackT> s;
	CardStackT c;
	for (int i = 0; i < n; i++){
		s.push_back(c);
	}
	return s;
}

bool BoardT::is_valid_pos(CategoryT c, unsigned int n){
	if(c == Tableau){
		return n >= 0 && n <= 9;
	}
	if(c == Foundation){
		return n >= 0 && n <= 7;
	}
	return false;
}

bool BoardT::valid_tab_tab(unsigned int n0, unsigned int n1){
	if (this->T[n0].size() == 0) {
		return false;
	}
	if (this->T[n0].size() > 0) {
		if (this->T[n1].size() == 0){
			return true;
		}
		if (this->T[n1].size() > 0){
			return this->T[n0].top().r = this->T[n1].top().r-1;
		}
	}
	return false;
}

bool BoardT::valid_tab_foundation(unsigned int n0, unsigned int n1){
	if (this->T[n0].size() == 0) {
		return false;
	}
	if (this->T[n0].size() > 0) {
		if (this->T[n1].size() == 0){
			return this->T[n0].top().r = 1;
		}
		if (this->T[n1].size() > 0){
			return this->T[n0].top().r = this->F[n1].top().r-1;
		}
	}
	return false;
}

bool BoardT::valid_waste_tab(unsigned int n) {
	if (this->T[n].size() == 0) {
		return true;
	}
	if (this->T[n].size() > 0) {
		return tab_placeable(this->W.top(), this->T[n].top());
	}
	return false;
}

bool BoardT::valid_waste_foundation(unsigned int n){
	if (this->T[n].size() == 0) {
		return this->T[n].top().r == ACE;
	}
	if (this->T[n].size() > 0) {
		return foundation_placeable(this->W.top(), this->F[n].top());
	}
	return true;
}

bool BoardT::tab_placeable(CardT c0, CardT c1){
	return c0.r == (c1.r - 1);
}

bool foundation_placeable(CardT c0, CardT c1){
	return c0.r == (c1.r - 1);
}





