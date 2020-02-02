/**
 * \file testCardType.cpp
 * \brief Implementation of CardType.
 * \author James Zhang, MacID: zhany111
 * \date March 19, 2019
*/
#include "catch.h"
#include "CardTypes.h"

TEST_CASE( "tests for CardT" , "[CardT]" ) {
  CardT c0;
  CardT c1;
  CardT c2;
  CardT c3;
  c0.r = 9;
  c0.s = Diamond;
  c1.r = 10;
  c1.s = Spade;
  c2.r = ACE;
  c2.s = Heart;
  c3.r = QUEEN;
  c3.s = Club;


  SECTION("test .r returns correct value"){
    REQUIRE(c0.r == 9);
    REQUIRE(c1.r == 10);
    REQUIRE(c2.r == ACE);
    REQUIRE(c3.r == QUEEN);
  }

  SECTION("test .s returns correct value"){
    REQUIRE(c0.s == Diamond);
    REQUIRE(c1.s == Spade);
    REQUIRE(c2.s == Heart);
    REQUIRE(c3.s == Club);
  }


}



