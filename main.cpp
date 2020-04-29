/* 
 * File:   main.cpp
 * Author: Ryan Jourdain
 * War Card Game
 * 
 */


//System Libraries
#include <iostream>
#include <ctime>
#include <map> // STL Map
#include <array> // STL Array library
using namespace std;

//User Libraries
#include "deck.h"

//Function Prototypes
void displayRules();
int rankToVal(char);

//Global Constants
const int WIN_TOTAL = 52;

//Program Execution Begins Here
int main(int argc, char** argv)
{
	
	// For generating random numbers
	srand( time(NULL) );
	
        
	// Create full deck of cards
	Deck deck(true);
	
        
	// Create decks for player and computer 
	Deck userDeck(false);
	Deck cpuDeck(false);
	
        
	// Create Player and Computer war decks for war rounds
	Deck userWarDeck(false);
	Deck cpuWarDeck(false);
	
        
	// Checks if game has ended
	bool gameOver = false;
        
        // Checks if Players are at WAR	
	bool atWar = false;     
        
        
        // Player's deck count
	int userTotCards = 0; 
        
        // Computer's deck count
	int cpuTotCards = 0;	
	
        // Players card value
	int userVal = 0; 
        
        // Computers card value
	int cpuVal = 0;		
        
        //Cards given to winners deck after war round
        int warPot = 0;		
        
        
        // Players card rank
	char userRank;
        
        // Computers card rank
	char cpuRank;		
        
        // Stores Players input
	char userInput;           
	
        
        // Pointer to Players card
	Card *userCard;
        
        // Pointer to Computers card
        Card *cpuCard;          
   
	
	// Randomly deal 26 cards to each player	
	for (int i = 0; i < 26; ++i) 
        {		
		// Draw a card and add it to the Players deck 
		userCard = deck.drawRandCard();
		userDeck.addCard(userCard);
		
		// Draw a card and add it to the Computers deck 
		cpuCard = deck.drawRandCard();
		cpuDeck.addCard(cpuCard);	
	}
	
	// Print the War rule set on the screen 
	displayRules();
	
        
        // Loop that runs until the game ends
	while ( !gameOver ) 
        {
		
		// Ask the user if they'd like to play War by dealing or exit by quitting
		cout << "Enter (D) to deal or (Q) to quit: ";
		cin >> userInput;
		userInput = toupper(userInput);
		
		// Break out of main loop if user chooses to quit
		if ( userInput == 'Q' ) 
                {
			gameOver = true;	
		}
		
		// Main loop
		else 
                {
			
			// The user and computer each draw one card		
			userCard = userDeck.drawCard();
			cpuCard = cpuDeck.drawCard();
			
			// Determine rank and value of each card 
			userRank = ( userCard -> getRank() );
			cpuRank = ( cpuCard -> getRank() );
			
			userVal = rankToVal( userRank );
			cpuVal = rankToVal( cpuRank );
			
			// Reveal each Players card		
			cout << "\nYour Card: " << ( userCard -> toString() ) << '\n';
			cout << "Computers Card: " << ( cpuCard -> toString() ) << "\n\n";
			
			//Checks to see which Player has the stronger card and awards both cards to the winner
			if ( userVal > cpuVal ) 
                        {
				
				cout << "You won this round!\n\n";
				userDeck.addCard(userCard);
				userDeck.addCard(cpuCard);
				
			} 
			else if ( cpuVal > userVal ) 
                        {
				
				cout << "The Computer won this round!\n\n";
				cpuDeck.addCard(cpuCard);
				cpuDeck.addCard(userCard);
				
			}
			
			// If the cards have the same value, WAR begins
			else 
                        {
				
				//Print rules of WAR
				cout << "IT'S A TIE! TIME FOR WAR!\n";
				cout << "Each player will place one card \"face down\" and one card \"face up\"\n";
				cout << "The player with the stronger \"face-up\" card wins the WAR POT\n";
				cout << "If the cards have the same strength another pair of cards will go to WAR\n\n\n";
				
                                //set atWar to true
                                atWar = true;
	
				// Save previously dealt cards to Players war deck
				
				userWarDeck.addCard(userCard);
				cpuWarDeck.addCard(cpuCard);
				
				//War loop
				while ( atWar ) 
                                {
				
					// Each player draws their first card and sets it face down 
					userCard = userDeck.drawCard();
					cpuCard = cpuDeck.drawCard();
                                        
                                        // Simulate a face down card for each player
					cout << "Your First Card: *FACE DOWN*\n";
					cout << "Computers First Card: *FACE DOWN*\n\n";
					
					// Add cards to war deck 
					userWarDeck.addCard(userCard);
					cpuWarDeck.addCard(cpuCard);
					
					// Each player draws and reveals their second card
					userCard = userDeck.drawCard();
					cpuCard = cpuDeck.drawCard();
					
					// Card reveal
					cout << "Your Second Card: " << ( userCard -> toString() ) << '\n';
					cout << "Computers Second Card: " << ( cpuCard -> toString() ) << '\n';
					
					// Add cards to war deck 
					userWarDeck.addCard(userCard);
					cpuWarDeck.addCard(cpuCard);
					
					// Check to see which player had the card with the higher value
					userRank = ( userCard -> getRank() );
					cpuRank = ( cpuCard -> getRank() );
					
					userVal = rankToVal( userRank );
					cpuVal = rankToVal( cpuRank );
					
					// if its not a tie break out of WAR loop
					if ( userVal != cpuVal ) 
                                        {
						
						atWar = false;
						
					}
					
					// If its a tie another pair of cards are drawn and WAR continues 
					else 
                                        {
						
						cout << "\nIt's a Tie! Dealing another pair of cards\n\n";
						
					}
				
				} 
				
				//Get the total number of cards to be given to the winner	
				warPot = userWarDeck.getSize() + cpuWarDeck.getSize();
				
				// Check to see if the user won the cards
				if ( userVal > cpuVal ) 
                                {
					cout << "\nYou just won all " << warPot << " cards!\n\n";
					
					// Add war deck cards from users main deck
					for (int i = userWarDeck.getSize(); i > 0; --i) 
                                        {
						
						userCard = userWarDeck.drawCard();
						userDeck.addCard(userCard);
						
					}
					
					// Add cards from computers war deck to users main deck
					for (int i = cpuWarDeck.getSize(); i > 0; --i) 
                                        {
						
						cpuCard = cpuWarDeck.drawCard();
						userDeck.addCard(cpuCard);
						
					}					
				}
				
				// Check to see if the computers won the cards
				if ( cpuVal > userVal ) 
                                {
					cout << "\nThe Computer wins all " << warPot << " cards!\n\n";
					
					// Add war deck cards from computers main deck	
					for (int i = cpuWarDeck.getSize(); i > 0; --i) 
                                        {	
						cpuCard = cpuWarDeck.drawCard();
						cpuDeck.addCard(cpuCard);	
					}
					
					// Add cards from users war deck to computers main deck
					for (int i = userWarDeck.getSize(); i > 0; --i) 
                                        {
						userCard = userWarDeck.drawCard();
						cpuDeck.addCard(userCard);	
					}	
				}	
			} 
			
			// Print score        
			userTotCards = userDeck.getSize();
			cpuTotCards = cpuDeck.getSize();
			
			cout << "Your Count: " << userTotCards << '\n';
			cout << "Computer Count: " << cpuTotCards << "\n\n\n";
			
			// Check to see if someone has won the game
			
			if ( (userTotCards == WIN_TOTAL) || (cpuTotCards == WIN_TOTAL) )
                        {	
				gameOver = true;	
			}			
		} 	
	} 
	
        
	// Announce final scores
	cout << "\nGAME OVER!!!\n\n";
	
        // Check the final scores
	userTotCards = userDeck.getSize();
	cpuTotCards = cpuDeck.getSize();
	
        // Print the final scores
	cout << "Your Score: " << userTotCards << '\n';
	cout << "Computers Score: " << cpuTotCards << "\n\n";
        
        if (userTotCards > cpuTotCards)
        {
            cout << "You Win!! Congratulations!!!\n\n";
        }
        else if (userTotCards < cpuTotCards)
        {
            cout << "The Computer wins! Better luck next time!\n\n";
        }
        else
        {
            cout << "It's a Tie!! Good Game!\n\n";
        }
            
            
            
            
            
            
            
            
            
            
            

} 



// Converts a cards rank to a numeric value;
int rankToVal(char rank)
{
	
	int value = 0;
	
	switch (rank)
        {
		
		case '2': case '3': case '4': case '5':
		case '6': case '7': case '8': case '9':
			value = rank - '0'; // 2-9
			break;
		case 'T':				
			value = 10;
			break;
		case 'J':				
			value = 11;
			break;
		case 'Q':				
			value = 12;
			break;
		case 'K':				
			value = 13;
			break;
		case 'A':				
			value = 14;
		
	}
        
        
	return value;	
        
}



// Print out the rules of WAR
void displayRules() 
{
	
	cout << "This is the game of WAR!\n\n";
	cout << "To win this game you need to be the first Player to get all 52 cards. To\n";
	cout << "start the game each Player receives 26 cards ,\n";
	cout << "The power of the cards are listed from Strongest to Weakest:\n\n";
	cout << "A K Q J 10 9 8 7 6 5 4 3 2\n\n";
	cout << "To start a round both Players reveal a card at the same\n";
	cout << "time.  The player with the stronger card takes both cards\n";
	cout << "and adds them to the bottom of their deck.\n\n";
	cout << "If the cards are the same strength then it's time for a WAR!\n";
	cout << "Each Player draws a pair of cards, one \"face down\" and one \"face up\" The\n";
	cout << "Player with the higher \"face up\" card takes six card WAR POT.  If the \"face up\"\n";
	cout << "cards have the same strength, the WAR is repeated\n";
	cout << "until someone wins the WAR POT. \n\n";
	cout << "The game is won when a Player has gathered all 52 cards.\n\n";
	
}