/* 
 * File:   deck.cpp
 * Author: Ryan Jourdain
 * War Card Game
 * 
 */


//System Libraries
#include <iostream>
#include <cstdlib>
#include <array> // STL Array library
#include <algorithm> // STL Algorithm library

//User Libraries
#include "deck.h"

// Deck constructor
Deck::Deck(bool fill) 
{
	
	size = 0;
	head = nullptr;

	const int TOT_RANKS = 13; //Total number of ranks
	const int TOT_SUITS = 4; // Total number of suits
	

	// If fill is true the deck gets filled  
	if (fill) 
        {
		// Fills suits with the various types suits using stl array
                array<Suit, TOT_SUITS> suits = { CLUB, DIAMOND, HEART, SPADE };
                // Fills ranks with the various ranks using stl array
		array<char,TOT_RANKS> ranks = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
		
                // Card pointer
		Card *c; 
		
                // Use STL Array .size() function for the size of the ranks array
		for ( int i = 0; i < ranks.size(); ++i ) 
                {
                    
			// Use STL Array .size() function for the size of the suits array
			for ( int j = 0; j < suits.size(); ++j ) 
                        {
				
				// Creates a new card
				c = new Card(suits[j], ranks[i]);
				
				// adds a card to the end of the deck
				addCard(c);
					
			} 
			
		} 
		
	} 
		
} 



// Draws and removes the first card from deck
Card* Deck::drawCard() 
{
	
	return ( drawStartCard(0) );
	
}



// Draws and removes a random card from the deck.
Card* Deck::drawRandCard() 
{
	
	// If the deck is empty returns null
	if ( !head ) 
        {
		
		return 0;
		
	}
	
	// Draws a random card 
	else 
        {
		
		return ( drawStartCard( rand() % size ) );
		
	}
	
}



// Prints the cards from the deck
void Deck::printDeck() 
{
	
	// Create card pointers
	Card *current = head;
	
	// Check to see if deck is empty
	if ( !head ) 
        {
		
		cout << "THE DECK IS EMPTY!\n";
		
	}
	
	// Prints the deck
	else
        {
	
		while ( current ) 
                {
			
			cout << ( current -> toString() ) << '\n';
			current = current -> next;
			
		}
		
	}
	
}



// Returns the number of cards in the deck
int Deck::getSize() 
{ 
    return size;
}



// Adds a card to the end of the deck
void Deck::addCard(Card* c) 
{
    
	Card* current = head;
	c -> next = nullptr;
	
	// Checks to see if its the first card in the deck
	if ( !head ) 
        {
		head = c;
		current = head;
		
	}
	
	// Traverse list till the end of the deck
	else {
		
		while ( current -> next) 
                {
			
			current = current -> next;
			
		}
		
		current -> next = c;
		
	}
	
	++size;
	
}



//  Draws and removes the card from the deck
Card* Deck::drawStartCard(int offset) 
{
	
	// Create card pointers
	Card *current;
        Card *previous;
	
	// Checks if deck is empty
	if ( !head ) 
        {
		
		cout << "DECK IS EMPTY!\n";
		return nullptr;
		
	} 
	
	// Checks if cards in deck
	else if (offset > (size - 1)) 
        {
		cerr << "THERES NO MATCH!";
		return nullptr;
		
	}
	
	else if (offset == 0)
        { 
		current = head;
		head = head -> next;
	}
	
	else
        {
		
		current = head;
		previous = head;
                
		for (int i = 0; i < offset; ++i)
                {
			previous = current;
			current = current -> next; 
		}
		previous -> next = current -> next;
		
	} 
        
	current -> next = nullptr; 
	--size; 
	return current;
}



// Deck destructor
Deck::~Deck() 
{
	
	// Create card pointers
	Card *current = head;
        Card *previous = head;
	
	// Checks if deck is empty
	if ( !head )
        {
		
		return;
		
	}
	
	// Deletes each card by traversing through the deck
	else 
        {
	
		while ( current ) 
                {
			
			previous = current;
			current = current -> next;
			delete previous;
			--size;
			
		} 
		
	} 
	
} 