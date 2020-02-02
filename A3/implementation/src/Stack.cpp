/**
 * \file Stack.cpp
 * \brief The implement of stack ADT described in Stack.h
 * \author James Zhang, MacID: zhany111
 * \date March 19, 2019
*/

using namespace std;
// Implementation here


#include "Stack.h"
#include "CardTypes.h"
#include "ex.h"
#include <vector>

template <typename Item>
Stack<Item>::Stack() {
	std::vector<Item> s;
	this->S = s;
}

template <typename Item>
Stack<Item>::Stack(std::vector<Item> s) {
	this->S = s;
}

template <typename Item>
Stack<Item> Stack<Item>::push(Item item) {
	std::vector<Item> new_(this->S);
	new_.push_back(item);
	return Stack<Item>(new_);
}

template <typename Item>
Stack<Item> Stack<Item>::pop() {
	if (this->S.size() == 0)
		throw out_of_range();

	std::vector<Item> new_(this->S);
	new_.pop_back();
	return Stack<Item>(new_);
}

template <typename Item>
Item Stack<Item>::top() {
	if (this->S.size() == 0)
		throw out_of_range();

	Item temp = this->S.back();

	return temp;
}

template <typename Item>
unsigned int Stack<Item>::size() {

	int l = this->S.size();
	return l;

}

template <typename Item>
std::vector<Item> Stack<Item>::toSeq() {
	return this->S;
}




// Keep this at bottom
template class Stack<CardT>;
