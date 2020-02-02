/**
 * \file Stack.h
 * \brief A template module for a stack of a given type of elements.
 * \author James Zhang, MacID: zhany111
 * \date March 19, 2019
*/

#include <stddef.h>
using namespace std;
#ifndef A3_STACK_H_
#define A3_STACK_H_

#include <vector>

/**
 *  \brief Template class for storing values in an FILO stack.
 *  \details Implements a template for an FILO stack.
 */

template <typename Item>
class Stack {
	private:
		std::vector<Item> S;

	public:
		/**
		*  \brief Construct a new stack.
		*  \details Create a new empty stack.
		*/
		Stack();

		/**
		*  \brief Construct a new stack.
		*  \details Create a new instance of stack given some initial elements
		*  \param s The initial elements to push on to the stack.
		*/
		Stack(std::vector<Item> s);

		/**
		*  \brief push function of stack.
		*  \details push an element to a stack
		*  \param item The element that we want to push to the end.
		*/
		Stack<Item> push(Item item);

		/**
		*  \brief pop function of a stack
		*  \details remove the last element that goes into the stack
		*  \throw out_of_range when the stack is empty
		*/
		Stack<Item> pop();

		/**
		*  \brief return the last element that goes into the stack
		*  \details by using top(), find the last element of the stack
		*  \throw out_of_range when the stack is empty
		*/
		Item top();
		/**
		*  \brief return the length of a stack
		*  \details by using the size() function of the vector, return the number of elements.
		*/
		unsigned int size();

		/**
		*  \brief change the stack back to a sequence (vector).
		*  \details by return this->s.
		*/
		std::vector<Item> toSeq();

};



#endif



