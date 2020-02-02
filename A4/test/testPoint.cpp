/**
 * \file testPoint.cpp
 * \brief test of point.
 * \author James Zhang, MacID: zhany111
 * \date April 5, 2019
*/

#include "catch.h"
#include "point.h"

TEST_CASE( "tests for point" , "[point]" ) {
  point p1 = point(false);
  point p2 = point(true);


  SECTION("test state() returns correct value"){
    REQUIRE(p1.state() == false);
    REQUIRE(p2.state() == true);
  }

  SECTION("test turn() changes the state of point"){
    REQUIRE(p1.state() == false);
    p1 = p1.turn();
    REQUIRE(p1.state() == true);
  }

}

