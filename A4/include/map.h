/**
 * \file map.h
 * \brief implement of game board.
 * \author James Zhang, MacID: zhany111
 * \date April 5, 2019
*/

#ifndef MAP_H_
#define MAP_H_

#include<iostream>
#include<stdio.h>
#include "point.h"
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

/**
 *  \brief Class for representing the game board of a game of Game of Life
 *  \details Implements a class for representing the Game of Life,
 *  with functions for constructors, the next generation of the game and the
 *  function that output the game board as a file. Implemented as an ADT.
 */
class map {
	private:
		unsigned int max_size;
		unsigned int min_size;
		vector<vector<point> > board;

	public:
		/**
		*  \brief Construct a new map
		*  \details Create a new map with default size (50x50), with all points' lives are dead(false).
		*/
		map();

		/**
		*  \brief Construct a new map with given vector<vector<point>>
		*  \param m representing a map with points, that we want to use it creating a map object
		*  \throw bad_size() if each row of input has different length, or the number of rows or columns are greater
		*   than max_size() or less than min_size()
		*/
		map(vector<vector<point> > m);

		/**
		*  \brief Construct a map using the name of the input file
		*  \details Create a map using the name of the input file. Transfer the name of the input file to a file type.
		*   Then create a map using the input file with the format that "0" represents alive, "*" represents dead.
		*  \param f the name of the file
		*  \throw bad_size() if each row of input file has different length, or the number of rows or columns are greater
		*   than max_size() or less than min_size()
		*  \throw invalid_argument() if the input file contains not only "*"s and "0"s
		*/
		map(string fn);

		/**
		*  \brief Construct a map using an input file
		*  \details Create a map using the input file with the format that "0" represents alive, "*" represents dead.
		*  \param f the file object
		*  \throw bad_size() if each row of input file has different length, or the number of rows or columns are greater
		*   than max_size() or less than min_size()
		*  \throw invalid_argument() if the input file contains not only "*"s and "0"s
		*/
		map(ifstream f);

		/**
		*  \brief output a new map that is the next generation of the old map
		*  \details generate a new map with new points according the rule of game of life.
		*  	The point that has 3 neighbors is set to alive otherwise the point is dead.
		*/
		map generate();

		/**
		*  \brief output the map that changes the life of point on position (x,y)
		*  \details tap function such that if the point on (x,y) is alive, make it dead. If the
		*   point is dead, make it alive. output the map that's been changed
		*  \param x representing the row of point is in
		*  \param y the column of the point is in
		*  \throw out_of_range if the input index is not in the map
		*/
		map tab(unsigned int x, unsigned int y);

		/**
		*  \brief output a file representing a map
		*  \details output the map as a file, with the format that "0" represents alive, "*" represents dead.
		*  the file can be read by human and it can be used as input to create a new map.
		*/
		void output();


};



#endif /* MAP_H_ */
