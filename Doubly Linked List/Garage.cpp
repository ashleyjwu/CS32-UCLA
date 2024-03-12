#include "Garage.h"

namespace cs32
{

Garage::Garage( size_t capacity ) 
{
    mCapacity = capacity;
}

// put something in the garage
// it purges something once the garage is full
bool Garage::tossIn( std::string s )
{
    if (mCapacity == 0) { //if the capacity is zero, nothing can be added
        return false;
    }
    if (mDeque.size() < mCapacity) { //can only add if current size is less than capacity
        mDeque.addToFront(s);
        return false;
    }
    else { //if full, we have to delete whatever is at the end before adding
        mDeque.deleteRear();
        mDeque.addToFront(s);
        return true;
    }
}

bool Garage::tossOut( std::string s )
{
    return (mDeque.deleteItem(s)); //delete item and return if it worked
}


// use something from the garage
// must be findable, then moved to the used pile
bool Garage::use( std::string s )
{
    if (find(s)) { //if in garage
        mDeque.deleteItem(s); //delete first occurance so it's not at the original index
        mDeque.addToFront(s); //basically moves 's' to the front by deleting and then readding
        return true;
    }
    return( false );
}

bool Garage::find( std::string s )
{
    string a = "";
    for (int i = 0; i < mDeque.size(); i++) {
        mDeque.get(i, a); //a is set to whatever is at the index
        if (s == a) { //compare s with the string at the index
            return( true );
        }
    }
    return( false );
}

size_t Garage::capacity()
{
    return mCapacity;
}

size_t Garage::size( )
{
    return mDeque.size();
}

std::string Garage::printItems( )
{
    return( mDeque.printItems() );
}


}
