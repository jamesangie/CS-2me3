/**
 * \file CardTypes.h
 * \author James Zhang, MacID: zhany111
 * \brief defining the information of SuitT and RankT. Then use them to create type CardT. Also
 * define Category of the board here.
 */

using namespace std;
#ifndef A3_CARD_TYPES_H_
#define A3_CARD_TYPES_H_

/**
 *  \brief use enum to define 4 Suits
 */
enum SuitT {Heart, Diamond, Spade, Club};

/**
 *  \brief use enum to define 13 ranks
 */

typedef unsigned short int RankT;

/**
 *  \brief use enum to define categories of the game board
 */
enum CategoryT {Tableau, Foundation, Deck, Waste};

/**
 *  \brief use struct to define type CardT
 *  \detail define a card using suit s and rank r.
 */
struct CardT {
	SuitT s;
	RankT r;
};


/**
 * \brief RankT for an Ace.
 */
#define ACE    1

/**
 * \brief RankT for an Jack.
 */
#define JACK   11

/**
 * \brief RankT for a Queen.
 */
#define QUEEN  12

/**
 * \brief RankT for a King.
 */
#define KING   13

#endif
