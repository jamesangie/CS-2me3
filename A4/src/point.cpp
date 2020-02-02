/**
 * \file point.cpp
 * \brief Implement for
 * \author James Zhang, MacID: zhany111
 * \date April 8, 2019
*/

#include<iostream>
#include<stdio.h>
#include "point.h"

using namespace std;

point::point() {
	this->live = true;
}

point::point(bool l) {
	this->live = l;
}

bool point::state(){
	return this->live;
}

point point::turn() {
	return point(!(this->live));
}



