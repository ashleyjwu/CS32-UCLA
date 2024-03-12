#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "Deque.h"
#include <string>
#include <sstream>

using namespace std;

namespace cs32 {

template <typename Type>
Deque<Type>::Deque() 
{
    head = nullptr; //initialize all member variables
    tail = nullptr;
}

template <typename Type>
Deque<Type>::Deque( const Deque& rhs ) {
    if (rhs.head == nullptr) //if empty
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new DequeNode<Type>( rhs.head->getElement() );
        tail = head;
        DequeNode<Type> *q = head;
        DequeNode<Type> *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new DequeNode<Type>( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            q->getNext()->setPrevious( q );
            tail = q->getNext();
            p = p->getNext();
            q = q->getNext();
        }
    }
}

template <typename Type>
Deque<Type>::~Deque() {
	makeEmpty();
}

template <typename Type>
bool Deque<Type>::isEmpty() const {
    return (tail == nullptr); //empty deques have head and tail as nullptr
}

template <typename Type>
void Deque<Type>::makeEmpty() {
    DequeNode<Type>* node = head; //keeps track of the first element and deletes accordingly
    while (node!=nullptr) { //iterate through deque
        head = node->getNext(); 
        delete node;
        node = head;
    }
    tail = nullptr; //don't leave tail uninitialized
}

template <typename Type>
void Deque<Type>::addToFront(const Type& data)
{
    DequeNode<Type>* newnode = new DequeNode<Type>(data); //new node to add with data as its value
    if (isEmpty()) { //if empty, then both head and tail should be this node
        head = newnode;
        tail = newnode;
    }
    else{ 
        newnode->setNext(head); //first take care of arrows
        head->setPrevious(newnode);
        head = newnode; //new head is new node
    }
}

template <typename Type>
void Deque<Type>::addToRear( const Type & data )
{
    DequeNode<Type>* newnode = new DequeNode<Type>(data); //same thing as addToFront
    if (isEmpty()) {
        head = newnode;
        tail = newnode;
    }
    else {
        newnode->setPrevious(tail); //set up arrows
        tail->setNext(newnode);
        tail = newnode; //now the tail should be the new node since we are adding to rear
    }
}

template <typename Type>
void Deque<Type>::deleteFront( )
{
    if (!isEmpty()) { //only attempt to delete if there is stuff to delete
        if (size() > 1) { //if there are more than one elements
            head = head->getNext(); //change head
            delete(head->getPrevious()); //set up arrows
            head->setPrevious(nullptr);
        }
        else {
            delete(head); //if only one element, delete it and set head and tail to be nullptr
            head = nullptr;
            tail = nullptr;
        }
    }
}

template <typename Type>
bool Deque<Type>::deleteItem( const Type & data )
{
    DequeNode<Type>* node = head; //the node we are deleting
    DequeNode<Type>* priornode = nullptr;
    while (node != nullptr)
    {
        if (node->getElement() == data) //only deletes first occurance, leaves possible later duplicates alone
        {
            if (priornode != nullptr){ //not at head
                priornode->setNext(node->getNext());
                if (node->getNext() != nullptr) { //not at end
                    (node->getNext())->setPrevious(priornode);
                }
                else { //at end
                    tail = priornode;
                }
            }
            else { //at head
                if (node->getNext() == nullptr){ //if only one element
                    head = nullptr;
                    tail = nullptr;
                }
                else { //more than one element
                    head = node->getNext();
                    head->setPrevious(nullptr);
                }
            }
            delete(node);
            return( true );
        }
        priornode = node;
        node = node->getNext();
    }
    return( false );
}


template <typename Type>
Type Deque<Type>::front( ) const
{
    Type result = Type(); //set to default value
    if (!isEmpty()) { //if not empty, return the head value
        result = head->getElement();
    }
    return( result );
}

template <typename Type>
Type Deque<Type>::rear( ) const
{
    Type result = Type(); //set to default value
    if (!isEmpty()) { //if not empty, return the tail value
        result = tail->getElement();
    }
    return( result );
}

template <typename Type>
void Deque<Type>::deleteRear( )
{
    if (!isEmpty()) { //only delete if there is something to delete
        if (size() > 1) { //more than one element
            tail = tail->getPrevious(); 
            delete(tail->getNext());
            tail->setNext(nullptr);
        }
        else { //same as deleteFront
            delete(tail);
            head = nullptr;
            tail = nullptr;
        }
    }
}

template <typename Type>
std::string Deque<Type>::to_string( const Type & value ) const
{
    stringstream s;
    // call the Type's operator <<
    s << value;
    return( s.str() );
}

template <typename Type>
std::string Deque<Type>::printItems( ) const
{ //prints the deque both forwards and backwards to check both arrow directions
    string s = "Printing items... \n";
    DequeNode< Type > *node = head;
    if (isEmpty()) {
        s += "Empty string";
    }
    while (node != nullptr) {
        s += to_string(node->getElement());
        s += " --> ";
        node = node->getNext();
    }
    s += "nullptr (end) --> ";
    node = tail;
    while (node != nullptr) {
        s += to_string(node->getElement());
        s += " --> ";
        node = node->getPrevious();
    }
    s += " nullptr (beginning) ";
    return( s );
}


// Deep copy of linked list
template <typename Type>
const Deque<Type> & Deque<Type>::operator =( const Deque<Type> & rhs ) {
    if (this != &rhs) {
        makeEmpty();

        DequeNode< Type > *right = rhs.head;

        while (right != nullptr) //iterate through and add elements in order
        {
            addToRear(right->getElement());
            right = right->getNext();
        }
    }
	return( *this );
}

template <typename Type>
size_t Deque<Type>::size() const
{
    size_t result = 0;
    DequeNode< Type >* node = head;
    while (node != nullptr) {
        result++; //while the node is not at the end of the list, increase result
        node = node->getNext();
    }
    return( result );
}


template <typename Type>
bool   Deque<Type>::get( int i, Type & data ) const
{
    int index = 0;
    DequeNode< Type >* node = head;
    while (node != nullptr) {
        if (index == i) {
            data = node->getElement(); //set data to the element at the index
            return true;
        }
        else {
            index++;
        }
        node = node->getNext();
    }
    return false; //if i is out of bounds, we return false
}



}


#endif
