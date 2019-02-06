#include <iostream>
#include <random>
#include <ctime>
#include "Card.h"

Card Card::generateCard()
{
    int cardSuit = (rand() % 3) + 1;
    int cardRank = (rand() % 13) + 1;
    

    switch (cardRank)
    {
        case 0:
            rank = two;
            break;
        case 1:
            rank = three;
            break;
        case 2:
            rank = four;
            break;
        case 3:
            rank = five;
            break;
        case 4:
            rank = six;
            break;
        case 5:
            rank = seven;
            break;
        case 6:
            rank = eight;
            break;
        case 7:
            rank = nine;
            break;
        case 8:
            rank = ten;
            break;
        case 9:
            rank = jack;
            break;
        case 10:
            rank = queen;
            break;
        case 11:
            rank = king;
            break;
        case 12:
            rank = ace;
            break;
    }

    switch(cardSuit)
    {
        case 0:
            suit = club;
            break;
        case 1:
            suit = spade;
            break;
        case 2:
            suit = heart;
            break;
        case 3:
            suit = diamond;
            break;
    }
    Card card(suit, rank);
    return card;
};

void Card::cardDisplay()
{
    switch (Card::rank)
    {
        case 0:
            std::cout << "Two of ";
            break;
        case 1:
            std::cout << "Three of ";
            break;
        case 2:
            std::cout << "Four of ";
            break;
        case 3:
            std::cout << "Five of ";
            break;
        case 4:
            std::cout << "Six of ";
            break;
        case 5:
            std::cout << "Seven of ";
            break;
        case 6:
            std::cout << "Eight of ";
            break;
        case 7:
            std::cout << "Nine of ";
            break;
        case 8:
            std::cout << "Ten of ";
            break;
        case 9:
            std::cout << "Jack of ";
            break;
        case 10:
            std::cout << "Queen of ";
            break;
        case 11:
            std::cout << "King of ";
            break;
        case 12:
            std::cout << "Ace of ";
            break;
    }

    switch(Card::suit)
    {
        case 0:
            std::cout << "Clubs" << std::endl;
            break;
        case 1:
            std::cout << "Spades" << std::endl;
            break;
        case 2:
            std::cout << "Hearts" << std::endl;
            break;
        case 3:
            std::cout << "Diamonds" << std::endl;
            break;
    }
};

rank& operator++(rank& r)
{
    return r = rank(static_cast<int>(r)+1);    
};

suit& operator++(suit& s)
{
    return s = suit(static_cast<int>(s) + 1);
    
};