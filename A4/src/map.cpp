/**
 * \file map.cpp
 * \brief A template module for a the game board of game of live.
 * \author James Zhang, MacID: zhany111
 * \date April 8, 2019
*/

#include "map.h"
#include <vector>
#include <string>
#include "ex.h"
#include <iostream>
#include <fstream>
#include "point.h"
using namespace std;


map::map(){
	this->max_size = 50;
	this->min_size = 25;
	point p = point(false);
	vector<vector<point> > b;
	vector<point> l;
	for (int i = 0; i < max_size; i++){
		l.push_back(p);
	}
	for (int j = 0; j < max_size; j++){
		b.push_back(l);
	}
	this->board = b;
}

map::map(vector<vector<point> > m){
	this->max_size = 50;
	this->min_size = 25;
	int l = m[0].size();
	for (int x = 0; x < m.size(); x++){
		if (m[x].size() != l) {
			throw bad_size();
		}
	}
	if (m.size() < min_size || m[0].size()< min_size) {throw bad_size();}
	if (m.size() > max_size || m[0].size()> max_size) {throw bad_size();}
	this->board = m;
}

map::map(string fn) {
	this->max_size = 50;
	this->min_size = 25;
	const char* caoziji = fn.c_str();
	ifstream f (caoziji);

	string line;
	int i = 0;
	vector<vector<point> > b;
	if (f.is_open()) {
		//check each line
    	while (getline(f, line) && i < max_size){
			vector<point> l;

			i++;
			if (i == max_size) {throw bad_size();}

			int j = 0;
			//check each character
			for(int c = 0; c != line.size(); ++c) {
				if (j == max_size) {throw bad_size();}
				j++;

		    	if (line[c]== '*'){
		    		l.push_back(point(false));
		    	}
		    	else if (line[c] == '0'){
		    		l.push_back(point(true));
		    	}
		    	else {
		    		throw invalid_argument();
		    	}
			}
		b.push_back(l);
		}

		int l = b[0].size();
		for (int x = 0; x < b.size(); x++){
			if (b[x].size() != l) {
				throw bad_size();
			}
		}
		if (b.size() < min_size || b[0].size()< min_size) {throw bad_size();}
		this->board = b;
  	}
  	else {
  		throw invalid_argument();
	}


}

map map::generate(){
	vector<vector<point> > b = this->board;
	for (int i = 0; i < this->board.size(); i++){
		for (int j = 0; j < this->board[0].size(); j++){
			int life = 0;

			//assuming the points on edge die in next generation because of the void that consumes them.
			if (i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1){
				b[i][j] = false;
			}
			//for the points not on edge
			for (int c = -1; c < 2; c++){
				for (int d = -1; c < 2; d++){
					if (!(c==0 && d==0)){
						if (this->board[i+c][j+d].state() == true){
							life ++;
						}
					}
				}
			}

			if(life < 2) {b[i][j] = false;}
			else if(life == 3){b[i][j] = true;}
			else if(life > 3){b[i][j] = false;}

		}
	}
	return map(b);
}


map map::tab(unsigned int x, unsigned int y) {
	if (x >= this->board.size() || x < 1 || y >= this->board[0].size() || y < 1){
		throw out_of_range();
	}
	vector<vector<point> > b = this->board;
	b[x][y] = b[x][y].turn();
	return map(b);
}

void map::output() {
	ofstream myfile ("output.txt");
	for (int i = 0; i < this->board.size(); i++){
		for (int j = 0; j < this->board[0].size(); j++){
			if (this->board[i][j].state()) {myfile << "0";}
			else {myfile << "*";}
		}
		myfile << "\n";
	}
}










