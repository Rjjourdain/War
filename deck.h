/* 
 * File:   deck.h
 * Author: Ryan Jourdain
 * War Card Game
 * 
 */


//User Libraries
#include "card.h"

// Deck class
class Deck 
{
	
	public:
		
            
		// Deck constructor
		Deck(bool);						

		// Draw and remove the first card from deck
		Card* drawCard();		

                // Draw and remove a random card from the deck
		Card* drawRandCard();		

		// Adds a card to the end of the deck
		void addCard(Card*);		

		// Prints the cards in the deck
		void printDeck();				

                // Returns the number of cards in the deck
		int getSize();					
		
		// Destructor
		~Deck();								
		
		
		
	private:
		
            
		// Draw/remove specified card from deck
		Card* drawStartCard(int);
                
		// Number of cards in the deck
		int size;
                
                // Pointer to the first card in the deck
		Card* head;						
   
};