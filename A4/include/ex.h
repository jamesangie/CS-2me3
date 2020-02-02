/**
 * \file ex.h
 * \brief Define some exceptions for A4
 * \author James Zhang, MacID: zhany111
 * \date April 8, 2019
*/
#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>


class invalid_argument : public std::exception {
   const char * what () const throw () {
      return "invalid argument";
   }
};

class bad_size : public std::exception {
   const char * what () const throw () {
      return "wrong size";
   }
};

class out_of_range : public std::exception {
   const char * what () const throw () {
      return "out of range";
   }
};


#endif
