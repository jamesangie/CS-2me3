/**
 * \file point.h
 * \brief A template module for a point with given live.
 * \author James Zhang, MacID: zhany111
 * \date April 8, 2019
*/


using namespace std;
#ifndef POINT_H_
#define POINT_H_

/**
 *  \brief Type point that stores the life state of the point.
 *  \details Implements a point with how
 */
class point {
	private:
		bool live;
	public:
		/**
		*  \brief Construct a default point
		*  \details Initialize a point that is dead. For point(bool), alive means True as bool, dead means False.
		*/
		point();

		/**
		*  \brief Construct point
		*  \details Create a point with the state that is dead or alive
		*  \param l representing the life of the point
		*/
		point(bool l);

		/**
		*  \brief return the state of the point, false or true
		*/
		bool state();

		/**
		*  \brief function that change the state of the point
		*  \details if the point is alive, make it dead. if it's dead, make it alive.
		*/
		point turn();

};



#endif /* POINT_H_ */
