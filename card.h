/* 
 * File:   card.h
 * Author: Ryan Jourdain
 * War Card Game
 * 
 */


//System Libraries
#include <string>
using namespace std;


// Create suit data type
enum Suit { CLUB, DIAMOND, HEART, SPADE };

class Card 
{
	
	public:
		
            
	        // Card Constructor
		Card(Suit, char);	
		
		// Returns the cards rank and suit as a string
		string toString();		

                // Returns the rank of the card
		char getRank();		

                // Returns the suit of the card
		Suit getSuit();		

                // Pointer to next card in the deck
		Card* next;					
		
                
	private:
            
            
		// The cards rank
		char rank;
                
                // The cards suit
		Suit suit;				
   
};