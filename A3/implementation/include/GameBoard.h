/**
 * \file GameBoard.h
 * \brief A template module for the game board of game Forty Thieves solitaire.
 * \author James Zhang, MacID: zhany111
 * \date March 19, 2019
*/

#ifndef A3_GAME_BOARD_H_
#define A3_GAME_BOARD_H_

#include <vector>
#include "CardStack.h"
#include "CardTypes.h"

/**
 *  \brief Class for representing the game board of a game of Forty Thieves solitaire
 *  \details Implements a class for representing the gameboard of a Forty Thieves solitaire,
 *  with functions for validating moves and verifying win states and states with no
 *  possible moves. Implemented as an ADT.
 */
class BoardT {
	private:
		std::vector<CardStackT> T;
		std::vector<CardStackT> F;
		CardStackT D;
		CardStackT W;
		bool two_decks(std::vector<CardStackT> T, std::vector<CardStackT> F, CardStackT D, CardStackT W);
		unsigned int cnt_cards_seq(std::vector<CardStackT> S, bool f);
		unsigned int cnt_cards_stack(CardStackT S, bool f);
		unsigned int cnt_cards(std::vector<CardStackT> T, std::vector<CardStackT> F, CardStackT D, CardStackT W, bool f);
		std::vector<CardStackT> init_seq(unsigned int n);
		bool is_valid_pos(CategoryT c, unsigned int n);
		bool valid_tab_tab(unsigned int n0, unsigned int n1);
		bool valid_tab_foundation(unsigned int n0, unsigned int n1);
		bool valid_waste_tab(unsigned int n);
		bool valid_waste_foundation(unsigned int n);
		bool tab_placeable(CardT c0, CardT c1);
		bool foundation_placeable(CardT c0, CardT c1);

	public:

		/**
		*  \brief Construct a new Forty Thieves solitaire from 2 decks of cards
		*  \details Create a new instance of a Thieves solitaire by placing the given deck
		*  on the tableau cells and the deck cell of the game board.
		*  \throws invalid_argument The given initial deck does not have 2 decks (104 cards).
		*/
		BoardT(CardStackT deck);

		/**
		*  \brief check if the move from tableau to the other category or another stack from tableau is valid or not.
		*  \details by check if the move is valid according the Forty Thieves solitaire rule.
		*  return a bool
		*  \param c The category that we want to move the card from the tableau to.
		*  \param n0 the index of tableau stack we make the move from
		*  \param n1 the index of category stack we make the move to
		*  \throws out_of_range if n0 or n1 are not valid position of relating category
		*/
		bool is_valid_tab_mv(CategoryT c, unsigned int n0, unsigned int n1);

		/**
		*  \brief check if the move from waste to the other category is valid or not.
		*  \details by check if the move is valid according the Forty Thieves solitaire rule.
		*  return a bool
		*  \param c The category that we want to move the card from the waste to.
		*  \param n the index of category stack we want to move the card to.
		*  \throws out_of_range if n is not a valid position of relating category.
		*/
		bool is_valid_waste_mv(CategoryT c, unsigned int n);

		/**
		*  \brief check if the move from deck to the other category is valid or not.
		*  \details by check if the move is valid according the Forty Thieves solitaire rule.
		*  Just check if the deck is empty or not. return a bool
		*/
		bool is_valid_deck_mv();

		/**
		*  \brief move the card from tableau to other category or the other stack from tableau
		*  \details by using push() and top(), we can add the card to the place it goes to.
		*  Then use pop() to remove the card from the stack we move the card from
		*  \param c The category that we want to move the card from the tableau to.
		*  \param n0 the index of tableau stack we make the move from
		*  \param n1 the index of category stack we make the move to
		*  \throws invalid_argument if the move is not is_valid_tab_mv(c, n0, n1)
		*/
		void tab_mv(CategoryT c, unsigned int n0, unsigned int n1);

		/**
		*  \brief move the card from waste to other category
		*  \details by using push() and top(), we can add the card to the place it goes to.
		*  Then use pop() to remove the card from the stack we move the card from.
		*  \param c The category that we want to move the card from the tableau to.
		*  \param n the index of category stack we make the move to
		*  \throws invalid_argument if the move is not is_valid_waste_mv(c, n)
		*/
		void waste_mv(CategoryT c, unsigned int n);

		/**
		*  \brief move the card from deck to waste
		*  \details by using push() and top(), we can add the card to waste.
		*  Then use pop() to remove the card from deck.
		*  \throws invalid_argument if the move is not is_valid_deck_mv()
		*/
		void deck_mv();

		/**
		*  \brief return the card stack from tableau with given position.
		*  \param n the index of stack we want to get
		*  \throws out_of_range if n in range (0, 10)
		*/
		CardStackT get_tab(unsigned int n);

		/**
		*  \brief return the card stack from foundation with given position.
		*  \param n the index of stack we want to get
		*  \throws out_of_range if n in range (0, 8)
		*/
		CardStackT get_foundation(unsigned int n);

		/**
		*  \brief return the card stack of deck
		*/
		CardStackT get_deck();

		/**
		*  \brief return the card stack of waste
		*/
		CardStackT get_waste();

		/**
		*  \brief check if there is still move available on the game board
		*  \detail return that if it is possible to move any card from any category to the other place
		*  according the game rule of Forty Thieves solitaire.
		*/
		bool valid_mv_exists();

		/**
		*  \brief check if the player wins
		*  \detail return if all the cards are placed in foundation. by counting that if the number
		*  of card in foundation is 104
		*/
		bool is_win_state();

};


#endif
