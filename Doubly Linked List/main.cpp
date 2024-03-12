#include <iostream>
#include <string>
#include <cassert>
#include "Deque.h"
#include "Deque.cpp"
#include "DequeNode.h"
#include "DequeNode.cpp"
#include "Garage.h"


int main()
{
    using namespace std;
    using namespace cs32;
    
    // Deque Tests

    Deque< int > dInt;
    int x;
    Deque< std::string > dString;
    std::string s;

    dInt.deleteFront();
    dInt.deleteRear();
    x = 12;
    assert(dInt.deleteItem(x) == false);
    assert(dInt.size() == 0);
    assert(dInt.get(-10, x) == false);
    assert(dInt.isEmpty());

    s = "Hello";
    dString.addToFront(s);
    s = "World!";
    dString.addToRear(s);
    s = "Howard";
    assert(dString.deleteItem(s) == false);
    assert(dString.size() == 2);
    assert(dString.get(-10, s) == false);
    assert(dString.isEmpty() == false);
    assert(dString.get(0, s) && s == "Hello");
    assert(dString.get(1, s) && s == "World!");
    assert(dString.front() == "Hello");
    assert(dString.rear() == "World!");
    cout << dString.printItems() << endl;
    dString.deleteFront();
    s = "Hello";
    assert(dString.deleteItem(s) == false);
    assert(dString.size() == 1);
    assert(dString.get(0, s) && s == "World!");
    assert(dString.isEmpty() == false);
    dString.deleteRear();
    s = "World!";
    assert(dString.deleteItem(s) == false);
    assert(dString.size() == 0);
    assert(dString.get(0, s) == false);
    assert(dString.isEmpty());
    s = "Meow";
    dString.addToFront(s);
    s = "Meow!";
    dString.addToRear(s);
    dString.makeEmpty();
    assert(dString.size() == 0);

    //testing duplicates
    Deque< int > d;
    x = 3;
    d.addToFront(x);
    d.addToFront(x);
    x = 6;
    d.addToFront(x);
    x = 9;
    d.addToFront(x);
    x = 6;
    d.addToFront(x);
    //d = 69633
    cout << d.printItems() << endl; 
    //d.deleteItem(6); //d = 9633, should delete first occurance
    cout << d.printItems() << endl;
    //d.deleteItem(3);
    cout << d.printItems() << endl; //d=963

    // Garage Tests
    Garage g;
    Garage gSix(6);

    assert(g.size() == 0);
    assert(g.capacity() == 10);

    //testing edge cases
    //first: empty garage
    assert(g.find("") == false);
    assert(g.use("") == false);
    cout << g.printItems() << endl;
    //next: one item "a"
    g.tossIn("a");
    assert(g.size() == 1);
    assert(g.capacity() == 10);
    assert(g.find("a") == true);
    assert(g.use("a") == true);
    assert(g.find("b") == false);
    assert(g.use("b") == false);
    cout << g.printItems() << endl;
    //test equal operator
    Garage g1;
    g1 = g;
    assert(g1.size() == 1);
    assert(g1.capacity() == 10);
    assert(g1.find("a") == true);
    assert(g1.use("a") == true);
    cout << g1.printItems() << endl;
    //multiple items: "a" and "b"
    g.tossIn("b");
    assert(g.size() == 2);
    assert(g.capacity() == 10);
    assert(g.find("a") == true);
    assert(g.use("a") == true);
    assert(g.find("b") == true);
    assert(g.use("b") == true);
    assert(g.find("c") == false);
    assert(g.use("c") == false);
    cout << g.printItems() << endl;
    //test equal operator for multiple items
    g1 = g;
    assert(g1.size() == 2);
    assert(g1.capacity() == 10);
    assert(g1.find("a") == true);
    assert(g1.use("a") == true);
    assert(g1.find("b") == true);
    assert(g1.use("b") == true);
    cout << g1.printItems() << endl;
    //test duplicates
    g.use("a");
    g.tossIn("b");
    g.tossIn("a"); //should be "a" "b" "a" "b"
    assert(g.size() == 4);
    assert(g.capacity() == 10);
    assert(g.find("a") == true);
    assert(g.use("b") == true);
    cout << "Is it b a a b?" << endl << g.printItems() << endl; //now "b" "a" "a" "b"

    //testing garage with capacity 0
    Garage g0(0);
    assert(g0.size() == 0);
    assert(g0.capacity() == 0);
    assert(g0.tossIn("a") == false);
    //testing garage with capacity 1
    Garage gOne(1);
    assert(gOne.size() == 0);
    assert(gOne.capacity() == 1);
    assert(gOne.tossIn("1") == false);
    assert(gOne.tossIn("2") == true);
    assert(gOne.find("2") == true);
    assert(gOne.find("1") == false);


    assert(gSix.size() == 0);
    assert(gSix.capacity() == 6);
    gSix.tossIn("shoes");
    gSix.tossIn("shirts");
    gSix.tossIn("books");
    assert(gSix.size() == 3);
    assert(gSix.capacity() == 6);
    gSix.tossIn("suitcases");
    assert(gSix.tossIn("tables") == false);  // nothing thrown away
    assert(gSix.tossIn("chairs") == false);  // nothing thrown away
    assert(gSix.size() == 6);
    assert(gSix.capacity() == 6);
    assert(gSix.find("shoes"));
    assert(gSix.find("shirts"));
    assert(gSix.find("books"));
    assert(gSix.find("suitcases"));
    assert(gSix.find("tables"));
    assert(gSix.find("chairs"));
    assert(gSix.tossIn("boxes"));  // shoes thrown away...
    cout << gSix.printItems() << endl;
    assert(gSix.size() == 6);
    assert(gSix.capacity() == 6);
    assert(gSix.find("boxes"));
    assert(gSix.find("shoes") == false);
    assert(gSix.find("shirts"));
    assert(gSix.find("books"));
    assert(gSix.find("suitcases"));
    assert(gSix.find("tables"));
    assert(gSix.find("chairs"));

    assert(gSix.tossOut("shoes") == false);   // shoes not found...
    assert(gSix.use("shoes") == false);       // shoes not found...
    assert(gSix.use("tables"));

    assert(gSix.tossIn("records"));     // shirts thrown away...
    assert(gSix.size() == 6);
    assert(gSix.capacity() == 6);
    assert(gSix.find("records"));
    assert(gSix.find("tables"));
    assert(gSix.find("boxes"));
    assert(gSix.find("shoes") == false);
    assert(gSix.find("shirts") == false);
    assert(gSix.find("books"));
    assert(gSix.find("suitcases"));

    assert(gSix.tossOut("books"));
    assert(gSix.tossOut("records"));
    assert(gSix.tossOut("shoes") == false);
    assert(gSix.size() == 4);
    assert(gSix.capacity() == 6);
    assert(gSix.find("records") == false);
    assert(gSix.find("tables"));
    assert(gSix.find("chairs"));
    assert(gSix.find("boxes"));
    assert(gSix.find("shoes") == false);
    assert(gSix.find("shirts") == false);
    assert(gSix.find("books") == false);
    assert(gSix.find("suitcases"));

    assert(gSix.tossOut("tables"));
    assert(gSix.tossOut("boxes"));
    assert(gSix.tossOut("suitcases"));
    assert(gSix.size() == 1);
    assert(gSix.capacity() == 6);
    assert(gSix.find("records") == false);
    assert(gSix.find("tables") == false);
    assert(gSix.find("boxes") == false);
    assert(gSix.find("shoes") == false);
    assert(gSix.find("shirts") == false);
    assert(gSix.find("books") == false);
    assert(gSix.find("suitcases") == false);
    assert(gSix.find("chairs"));


    cout << "all tests passed!" << endl;
    
    return( 0 );
}
