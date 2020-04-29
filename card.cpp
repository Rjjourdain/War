/* 
 * File:   card.cpp
 * Author: Ryan Jourdain
 * War Card Game
 * 
 */


//System Libraries
#include <stdexcept>

//User Libraries
#include "card.h"


// Card Constructor
Card::Card(Suit s, char r)  //r = rank of card / s = suit of card
{
	
	next = nullptr;
	suit = s;
	
	switch( r ) 
        {
		
		case 'A': case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9': case 'T':
		case 'J': case 'Q': case 'K':
			rank = r;
			break;
			
			
	}
	
}


// Returns a card as a suit and rank in a string
string Card::toString() 
{
	
	string c = "";
	
	c += rank;
	c += '/';
	
	switch( suit ) 
        {
		
		case CLUB:
			c += "CLUB";
			break;
		case DIAMOND:
			c += "DIAMOND";
			break;
		case HEART:
			c += "HEART";
			break;
		case SPADE:
			c += "SPADE";
			break;
			
	}

	return c;
	
}


// Returns a char of the cards rank
char Card::getRank() 
{ 
    return rank; 
}


// Returns the cards suit
Suit Card::getSuit()
{ 
    return suit;
}