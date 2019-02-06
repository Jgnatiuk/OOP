#include <vector>
#ifndef CARD_H
#define CARD_H


enum suit { club, spade, heart, diamond };
enum rank { two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace};

struct Card
{   
public:

     
    Card(suit suit, rank rank)
        : suit(suit), rank(rank) {}
    ~Card() {};

    void cardDisplay();
    Card generateCard();
    const rank get_rank() { return rank; }
    const suit get_suit() { return suit; }


    suit suit;
    rank rank;

};

rank& operator++(rank& r);
suit& operator++(suit& s);

#endif


