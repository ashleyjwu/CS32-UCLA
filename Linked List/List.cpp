#include "List.h"

using namespace std;

namespace cs32 {

List::List() {
	head = nullptr;
}

List::List( const List& rhs ) {
    if (rhs.head == nullptr) head = nullptr;
    else {
        head = new ListNode( rhs.head->getElement() );
        ListNode *q = head;
        ListNode *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new ListNode( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            p = p->getNext( );
            q = q->getNext( );
        }
    }
}

List::~List() {
	makeEmpty();
}

bool List::isEmpty() const {
	return( head == nullptr );
}

void List::makeEmpty() {
	while (!isEmpty()) {
        deleteItem( head->getElement( ) );
	}
}

void List::addToFront( const std::string & data )
{
    ListNode * newnode = new ListNode( data );
    newnode->setNext( head );
    head = newnode;
}

void List::addToRear( const std::string & data )
{
    if (head == nullptr)
    {
        addToFront( data );
    }
    else
    {
        ListNode * node = head;
        while( node->getNext() != nullptr )
        {
            node = node->getNext();
        }
        ListNode * newnode = new ListNode( data );
        newnode->setNext( nullptr );
        node->setNext( newnode );
    }
}

void List::deleteItem( const std::string & data )
{
    ListNode * node = head;
    ListNode * priornode = nullptr;

        while( node != nullptr )
        {
            if (node->getElement() == data)
            {
                if (priornode != nullptr)
                    priornode->setNext( node->getNext( ) );
                else
                    head = node->getNext();
                delete( node );
                break;
            }
            priornode = node;
            node = node->getNext();
        }
}

bool List::findItem( const std::string & data )
{
    bool result = false;
    ListNode * node = head;
    while( node != nullptr )
    {
        if (node->getElement() == data)
        {
            result = true;
            break;
        }
        node = node->getNext();
    }
    return( result );
}

std::string List::printItems( )
{
    string s = "";
    if (isEmpty())
    {
        s += "---> empty list";
    }
    else
    {
        s += "head:";
        ListNode * node = head;
        while( node != nullptr )
        {
            s += " -> ";
            s += node->getElement();
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}


// Deep copy of linked list
const List& List::operator =( const List& rhs ) {
	if (this != &rhs) {
		makeEmpty();

        ListNode * right = rhs.head;

		while( right != nullptr )
        {
            addToRear( right->getElement() );
            right = right->getNext();
		}
	}

	return( *this );
}

size_t List::size() const {
    int count = 0;
    ListNode* node = head;
	while (node != nullptr) {
		count++; //while the node is not at the end of the list, increase count
		node = node->getNext();
	}
    return count;
}

int List::position(const std::string& data) const {
    int index = 0;
	ListNode* node = head;
	while (node != nullptr) {
		if (node->getElement() == data) { //at the first occurrence of data, return the index
			return index;
		}
		else {
			index++; //when data has not occurred yet, increase index and move to next node
			node = node->getNext();
		}
	}
	return -1;
}

bool List::before(const std::string& before, const std::string& after) const {
    int index1 = position(before); //first occurrence of before
    int index2 = position(after); //first occurrence of after
    int index = 0; //which # element in the list we are looking at
    ListNode* node = head; //the element in the list we are looking at (trying to find after)

    if (index1 == -1 || index2 == -1) { //if either before or after aren't in the list, return false
        return false;
    }
    while (node != nullptr) {
		if ((node->getElement() == after) && (index > index1)) { //if after appears and it is at an index after before, return true
			return true;
        }
        else {
            index++;
            node = node->getNext();
        }
    }
    return (false);
}

bool List::get(int i, std::string& data) const {
    int index = 0;
    ListNode* node = head;
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

std::string List::min() const {
    ListNode* node = head;  
    if (isEmpty()) {
        return "";
    }
    string currentMin = node->getElement(); //sets minimum to first element in List
    while (node != nullptr) {
        if (node->getElement() < currentMin) { //if this element is less than the current min, update the min
            currentMin = node->getElement();
        }
        node = node->getNext(); //checks next element of List
    }
    return currentMin;
}

void List::removeAllBiggerThan(const std::string& data) {
    ListNode* node = head;
    ListNode* removeNode = nullptr; //keeps track of the nodes we want to remove
    while (node != nullptr) {
        if (node->getElement() > data) {
            removeNode = node;
            node = node->getNext(); //this way, node can continue moving through the list
            deleteItem(removeNode->getElement());
            removeNode = nullptr; //prevents removeNode from pointing at nothing
        }
        else {
            node = node->getNext();
        }
    }
}

}


