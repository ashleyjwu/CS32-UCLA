#include <iostream>
#include <cassert>
#include "Enums.h"
#include "Card.h"
#include "Hand.h"

using namespace std;
using namespace cs32;

int main() {   
    
    Card ace( Suit::CLUBS, Face::ACE );
    Card two( Suit::CLUBS, Face::DEUCE );
    Card three( Suit::CLUBS, Face::THREE );
    Card four( Suit::CLUBS, Face::FOUR );
    Card five( Suit::CLUBS, Face::FIVE );
    Card six( Suit::CLUBS, Face::SIX );
    Card seven( Suit::CLUBS, Face::SEVEN );
    Card eight( Suit::CLUBS, Face::EIGHT );
    Card nine( Suit::CLUBS, Face::NINE );
    Card ten( Suit::CLUBS, Face::TEN );
    Card jack( Suit::CLUBS, Face::JACK );
    Card queen( Suit::CLUBS, Face::QUEEN );
    Card king( Suit::CLUBS, Face::KING );
    
    Card c1;
    Card c2;
    Hand h(c1, c2);
    assert( c1.getFace() == Face::ACE);
    assert( h.evaluateHand(two) == Choice::SPLIT );
    assert(h.evaluateHand(jack) == Choice::SPLIT);

    Hand h1( two, two );
    assert( h1.evaluateHand(two) == Choice::SPLITHIT );
    assert( h1.evaluateHand(three) == Choice::SPLITHIT );
    assert( h1.evaluateHand(four) == Choice::SPLIT );
    assert( h1.evaluateHand(five) == Choice::SPLIT );
    assert( h1.evaluateHand(six) == Choice::SPLIT );
    assert( h1.evaluateHand(seven) == Choice::SPLIT );
    assert( h1.evaluateHand(eight) == Choice::HIT );
    assert( h1.evaluateHand(nine) == Choice::HIT );
    assert( h1.evaluateHand(ten) == Choice::HIT );
    assert( h1.evaluateHand(jack) == Choice::HIT );
    assert( h1.evaluateHand(queen) == Choice::HIT );
    assert( h1.evaluateHand(king) == Choice::HIT );
    
    // test code for Card

    Card c(Suit::CLUBS, Face::DEUCE);
    assert(c.getSuit() == Suit::CLUBS);
    assert(c.getFace() == Face::DEUCE);
    assert(c.getValue() == 2);

    Card d(Suit::SPADES, Face::QUEEN);
    assert(d.getSuit() == Suit::SPADES);
    assert(d.getFace() == Face::QUEEN);
    assert(d.getValue() == 10);

    Hand h2(c, d);
    assert(h2.evaluateHand(two) == Choice::HIT);
    assert(h2.evaluateHand(three) == Choice::HIT);
    assert(h2.evaluateHand(four) == Choice::STAND);
    assert(h2.evaluateHand(five) == Choice::STAND);
    assert(h2.isPair() == false);
    assert(h2.isSoft() == false);

    h = Hand(ace, seven);
    assert(h.evaluateHand(five) == Choice::DOUBLESTAND);
    assert(h.evaluateHand(six) == Choice::DOUBLESTAND);
    assert(h.evaluateHand(seven) == Choice::STAND);
    assert(h.evaluateHand(eight) == Choice::STAND);
    assert(h.evaluateHand(nine) == Choice::HIT);
    assert(h.isPair() == false);
    assert(h.isSoft() == true);

    h = Hand(five, five);
    assert(h.evaluateHand(two) == Choice::DOUBLEHIT);
    assert(h.evaluateHand(three) == Choice::DOUBLEHIT);
    assert(h.evaluateHand(four) == Choice::DOUBLEHIT);
    assert(h.isPair() == true);
    assert(h.isSoft() == false);

    h = Hand(ten, two);
    assert(h.evaluateHand(five) == Choice::STAND);

    Card ash(Suit::CLUBS, Face::FOUR);
    assert(ash.getSuit() == Suit::CLUBS);
    ash.setSuit(Suit::DIAMONDS);
    assert(ash.getSuit() == Suit::DIAMONDS);

    h = Hand(ten, seven);
    assert(h.evaluateHand(three) == Choice::STAND);

    cerr << "all tests passed!";

    return(0);
}
