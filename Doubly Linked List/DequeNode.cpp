#ifndef DEQUENODE_CPP
#define DEQUENODE_CPP


#include "DequeNode.h"
using namespace std;

namespace cs32 {

template <typename Type>
DequeNode<Type>::DequeNode( const Type& v, DequeNode * nextnode, DequeNode * previousnode ) 
{
    value = v; //initialize all member variables
    next = nextnode;
    previous = previousnode;
}

template <typename Type>
Type DequeNode<Type>::getElement() const {
	return( value );
}

template <typename Type>
DequeNode<Type> * DequeNode<Type>::getNext() const {
	return( next );
}

template <typename Type>
void DequeNode<Type>::setNext( DequeNode<Type> * node ) {
    next = node;
}

template <typename Type>
DequeNode<Type> * DequeNode<Type>::getPrevious() const {
    return( previous );
}

template <typename Type>
void DequeNode<Type>::setPrevious( DequeNode<Type> * node ) {
    previous = node;
}

template <typename Type>
void DequeNode<Type>::setValue(const Type& v) {
    value = v;
}

}


#endif
