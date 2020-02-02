/**
 * \file ex.h
 * \brief The implement of some exception we use in the project
 * \author James Zhang, MacID: zhany111
 * \date March 19, 2019
*/

#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>


class invalid_argument : public std::exception {
   const char * what () const throw () {
      return "invalid argument";
   }
};

class out_of_range : public std::exception {
   const char * what () const throw () {
      return "out of range";
   }
};

#endif
