/**
 * \file testStack.cpp
 * \brief Implementation of stack.
 * \author James Zhang, MacID: zhany111
 * \date March 19, 2019
*/

#include "catch.h"
#include "CardStack.h"
#include "ex.h"

TEST_CASE( "tests for Stack" , "[Stack]" ) {
	CardStackT cs(std::vector<CardT>());

	SECTION("test empty constructor"){
	    CardStackT newCs = CardStackT(std::vector<CardT>());
	   		REQUIRE(newCs.size() == 0);
	  }


	SECTION("test non-empty constructor"){
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

		std::vector<CardT> cards = std::vector<CardT>();
		cards.push_back(c0);cards.push_back(c1);cards.push_back(c2);cards.push_back(c3);

		REQUIRE(cards[0].s == Diamond);
		REQUIRE(cards[1].s == Spade);
		REQUIRE(cards[2].s == Heart);
		REQUIRE(cards[3].s == Club);

	    CardStackT cs = CardStackT(cards);
	   	REQUIRE(cs.size() == 4);
	   	REQUIRE(cs.top().r == Club);
	  }



  	SECTION("test push(), pop() and top()"){
		  CardT c0;
		  CardT c1;
		  c0.r = 9;
		  c0.s = Diamond;
		  c1.r = 10;
		  c1.s = Spade;


  		REQUIRE(cs.size() == 0);
  		cs.push(c0);
  		REQUIRE(cs.size() == 1);
  		REQUIRE(cs.top().r == 9);
  		cs.push(c1);
  		REQUIRE(cs.size() == 2);
  		REQUIRE(cs.top().r == 10);
  		cs.pop();
  		REQUIRE(cs.size() == 1);
  		REQUIRE(cs.top().r == 9);

  	}

  	SECTION("test exceptions"){
		  REQUIRE_THROWS_AS(cs.pop(), std::out_of_range());
		  REQUIRE_THROWS_AS(cs.top(), std::out_of_range());
  	}




}
