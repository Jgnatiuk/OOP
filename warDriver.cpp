#include <algorithm>
#include <random>
#include <iostream>
#include <vector>
#include <ctime>
#include "Card.h"

void displayDeck(std::vector<Card> & d)
{   
    int count = 0;
    for(auto & i : d)
    {     
        switch(i.get_rank())
        {
            case 0:
                std::cout << "[2 of ";
            break;
            case 1:
                std::cout << "[3 of ";
            break;
            case 2:
                std::cout << "[4 of ";
            break;
            case 3:
                std::cout << "[5 of ";
            break;
            case 4:
                std::cout << "[6 of ";
            break;
            case 5:
                std::cout << "[7 of ";
            break;
            case 6:
                std::cout << "[8 of ";
            break;
            case 7:
                std::cout << "[9 of ";
            break;
            case 8:
                std::cout << "[10 of ";
            break;
            case 9:
                std::cout << "[JACK of ";
            break;
            case 10:
                std::cout << "[QUEEN of ";
            break;
            case 11:
                std::cout << "[KING of ";
            break;
            case 12:
                std::cout << "[ACE of ";
            break;
        }
        switch(i.get_suit())
        {
            case 0:
                std::cout << "C] ";
                if((count + 1) % 13 == 0) { std::cout << std::endl; }
            break;
            case 1:
                std::cout << "S] ";
                if((count + 1) % 13 == 0) { std::cout << std::endl; }
            break;
            case 2:
                std::cout << "H] ";
                if((count + 1) % 13 == 0) { std::cout << std::endl; }
            break;
            case 3:
                std::cout << "D] ";
                if((count + 1) % 13 == 0) { std::cout << std::endl; }
            break;
        }

        ++count;
    }
};
void playWar()
{   
    std::cout << "Welcome to War" << std::endl;
    std::cout << "Press Enter to Begin";
    std::cin.ignore();
    
    
    //Construct vector of cards which will act as deck
    std::vector<Card> deck;
    
    for(suit suit = club ; suit <= diamond ; ++suit)
    {
        for(rank rank = two ; rank <= ace ; ++rank)
        {
            deck.push_back(Card(suit, rank));
        }
    }  

    // Initialize random device object
    std::random_device rng;
    // Shuffle Deck
    std::shuffle(deck.begin(), deck.end(), rng);

    displayDeck(deck);


};

int main() {

    srand(time(NULL));

    playWar();

 };