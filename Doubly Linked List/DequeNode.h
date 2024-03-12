#ifndef DEQUENODE_H
#define DEQUENODE_H
#include <iostream>
#include <string>

namespace cs32 {

template <typename Type>
class DequeNode {
public:
    DequeNode( const Type& data, DequeNode * nextnode = nullptr, DequeNode * previousnode = nullptr );

	Type getElement() const;
    DequeNode* getNext() const;
	void setNext( DequeNode * node );
    DequeNode* getPrevious() const;
    void setPrevious( DequeNode * node );
    void setValue(const Type& v);

private:
	Type       value;
    DequeNode* next;
    DequeNode* previous;

};

}
#endif
