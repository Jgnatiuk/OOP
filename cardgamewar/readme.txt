[Card.h]
Was able to successfully build and implement a card class with enumerated rank and suit data members with multiple member functions
get_rank() , get_suit() - accessor functions because the data members are private
generateCard() - Generates random card 

[WarDriver.cpp]
file containing main()
contains two functions
playwar() - main driver function for controlling the game of war, currently have a successful implementation of a 52 card shuffled deck,
            via a vector of card objects. Still need to split the shuffled deck into two separate decks, add operator overloads for comparison
            of cards, and implement the actual comparison of the cards within the playwar function for the game itself.
displayDeck() - function to display the vector of cards that is built, mainly for testing purposes
