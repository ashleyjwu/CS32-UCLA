#include "Hand.h"

namespace cs32
{


Hand::Hand( Card card1, Card card2 ) : mCard1( card1 ), mCard2( card2 )
{
    
}

Card Hand::getCard1() const
{
    return( mCard1 );
}

Card Hand::getCard2() const
{
    return( mCard2 );
}

Choice Hand::evaluateHand( Card dealerCard ) const
{
    // by default STAND
    Choice c = Choice::STAND;
    int handTotal = mCard1.getValue() + mCard2.getValue();
    if (isSoft()) {
        if (handTotal == 3 || handTotal == 4) { //Ace and 2 or Ace and 3 have same moves
            switch (dealerCard.getValue()) {
            case 2:
                c = Choice::HIT;
                break;
            case 3:
                c = Choice::HIT;
                break;
            case 4:
                c = Choice::HIT;
                break;
            case 5:
                c = Choice::DOUBLEHIT;
                break;
            case 6:
                c = Choice::DOUBLEHIT;
                break;
            case 7:
                c = Choice::HIT;
                break;
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                c = Choice::HIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 5 || handTotal == 6) { //Ace and 4 or Ace and 5 have same moves
            switch (dealerCard.getValue()) {
            case 2:
                c = Choice::HIT;
                break;
            case 3:
                c = Choice::HIT;
                break;
            case 4:
                c = Choice::DOUBLEHIT;
                break;
            case 5:
                c = Choice::DOUBLEHIT;
                break;
            case 6:
                c = Choice::DOUBLEHIT;
                break;
            case 7:
                c = Choice::HIT;
                break;
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                c = Choice::HIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 7) { //Ace and 6
            switch (dealerCard.getValue()) {
            case 2:
                c = Choice::HIT;
                break;
            case 3:
                c = Choice::DOUBLEHIT;
                break;
            case 4:
                c = Choice::DOUBLEHIT;
                break;
            case 5:
                c = Choice::DOUBLEHIT;
                break;
            case 6:
                c = Choice::DOUBLEHIT;
                break;
            case 7:
                c = Choice::HIT;
                break;
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                c = Choice::HIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 8) { //Ace and 7
            switch (dealerCard.getValue()) {
            case 3:
                c = Choice::DOUBLESTAND;
                break;
            case 4:
                c = Choice::DOUBLESTAND;
                break;
            case 5:
                c = Choice::DOUBLESTAND;
                break;
            case 6:
                c = Choice::DOUBLESTAND;
                break;
            case 9:
                c = Choice::HIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 2) { //2 Aces
            c = Choice::SPLIT;
        }
    }
    else if (isPair()) {
        if (handTotal == 4 || handTotal == 6) { //double 2s or 3s have same moves
            switch (dealerCard.getValue()) {
            case 2:
                c = Choice::SPLITHIT;
                break;
            case 3:
                c = Choice::SPLITHIT;
                break;
            case 4:
                c = Choice::SPLIT;
                break;
            case 5:
                c = Choice::SPLIT;
                break;
            case 6:
                c = Choice::SPLIT;
                break;
            case 7:
                c = Choice::SPLIT;
                break;
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                c = Choice::HIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 8) { //double 4s
            switch (dealerCard.getValue()) {
            case 2:
                c = Choice::HIT;
                break;
            case 3:
                c = Choice::HIT;
                break;
            case 4:
                c = Choice::HIT;
                break;
            case 5:
                c = Choice::SPLITHIT;
                break;
            case 6:
                c = Choice::SPLITHIT;
                break;
            case 7:
                c = Choice::HIT;
                break;
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                c = Choice::HIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 10) { //double 5s... etc
            switch (dealerCard.getValue()) {
            case 2:
                c = Choice::DOUBLEHIT;
                break;
            case 3:
                c = Choice::DOUBLEHIT;
                break;
            case 4:
                c = Choice::DOUBLEHIT;
                break;
            case 5:
                c = Choice::DOUBLEHIT;
                break;
            case 6:
                c = Choice::DOUBLEHIT;
                break;
            case 7:
                c = Choice::DOUBLEHIT;
                break;
            case 8:
                c = Choice::DOUBLEHIT;
                break;
            case 9:
                c = Choice::DOUBLEHIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 12) {
            switch (dealerCard.getValue()) {
            case 2:
                c = Choice::SPLITHIT;
                break;
            case 3:
                c = Choice::SPLIT;
                break;
            case 4:
                c = Choice::SPLIT;
                break;
            case 5:
                c = Choice::SPLIT;
                break;
            case 6:
                c = Choice::SPLIT;
                break;
            case 7:
                c = Choice::HIT;
                break;
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                c = Choice::HIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 14) {
            switch (dealerCard.getValue()) {
            case 2:
                c = Choice::SPLIT;
                break;
            case 3:
                c = Choice::SPLIT;
                break;
            case 4:
                c = Choice::SPLIT;
                break;
            case 5:
                c = Choice::SPLIT;
                break;
            case 6:
                c = Choice::SPLIT;
                break;
            case 7:
                c = Choice::SPLIT;
                break;
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                c = Choice::HIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 16) {
            c = Choice::SPLIT;
        }
        if (handTotal == 18) {
            switch (dealerCard.getValue()) {
            case 2:
                c = Choice::SPLIT;
                break;
            case 3:
                c = Choice::SPLIT;
                break;
            case 4:
                c = Choice::SPLIT;
                break;
            case 5:
                c = Choice::SPLIT;
                break;
            case 6:
                c = Choice::SPLIT;
                break;
            case 8:
                c = Choice::SPLIT;
                break;
            case 9:
                c = Choice::SPLIT;
                break;
            }
        }

    }
    else {
        if (handTotal == 8) {
            c = Choice::HIT;
        }
        if (handTotal == 9) {
            switch (dealerCard.getValue()) {
            case 2:
                c = Choice::HIT;
                break;
            case 3:
                c = Choice::DOUBLEHIT;
                break;
            case 4:
                c = Choice::DOUBLEHIT;
                break;
            case 5:
                c = Choice::DOUBLEHIT;
                break;
            case 6:
                c = Choice::DOUBLEHIT;
                break;
            case 7:
                c = Choice::HIT;
                break;
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                c = Choice::HIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 10) {
            switch (dealerCard.getValue()) {
            case 2:
                c = Choice::DOUBLEHIT;
                break;
            case 3:
                c = Choice::DOUBLEHIT;
                break;
            case 4:
                c = Choice::DOUBLEHIT;
                break;
            case 5:
                c = Choice::DOUBLEHIT;
                break;
            case 6:
                c = Choice::DOUBLEHIT;
                break;
            case 7:
                c = Choice::DOUBLEHIT;
                break;
            case 8:
                c = Choice::DOUBLEHIT;
                break;
            case 9:
                c = Choice::DOUBLEHIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 11) {
            c = Choice::DOUBLEHIT;
        }
        if (handTotal == 12) {
            switch (dealerCard.getValue()) {
            case 2:
                c = Choice::HIT;
                break;
            case 3:
                c = Choice::HIT;
                break;
            case 7:
                c = Choice::HIT;
                break;
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                c = Choice::HIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 13 || handTotal == 14) {
            switch (dealerCard.getValue()) {
            case 7:
                c = Choice::HIT;
                break;
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                c = Choice::HIT;
                break;
            case 10:
                c = Choice::HIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 15) {
            switch (dealerCard.getValue()) {
            case 7:
                c = Choice::HIT;
                break;
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                c = Choice::HIT;
                break;
            case 10:
                c = Choice::SURRENDERHIT;
                break;
            case 1:
                c = Choice::HIT;
                break;
            }
        }
        if (handTotal == 16) {
            switch (dealerCard.getValue()) {
            case 7:
                c = Choice::HIT;
                break;
            case 8:
                c = Choice::HIT;
                break;
            case 9:
                c = Choice::SURRENDERHIT;
                break;
            case 10:
                c = Choice::SURRENDERHIT;
                break;
            case 1:
                c = Choice::SURRENDERHIT;
                break;
            }
        }
    }
    return( c );
}

bool Hand::isPair() const
{
    if (mCard1.getFace() == mCard2.getFace()) {
        return true;
    }
    return( false );
}

bool Hand::isSoft() const
{
    if (mCard1.getFace() == Face::ACE) {
        return true;
    }
    if (mCard2.getFace() == Face::ACE) {
        return true;
    }
    return( false );
}


}
