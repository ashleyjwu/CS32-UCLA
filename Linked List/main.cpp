#include <iostream>
#include <string>
#include <cassert>
#include "List.h"
#include "ListNode.h"
using namespace cs32;

int main()
{
    using namespace std;

    // test code

    // the get function enables a client to iterate over all elements of a List
    List l1;
    assert(l1.min() == "");
    l1.addToFront("Hawkeye");
    l1.addToFront("Thor");
    l1.addToFront("Hulk");
    l1.addToFront("Black Widow");
    l1.addToFront("Iron Man");
    l1.addToFront("Captain America");
    assert(l1.position("Hawkeye") == 5);
    assert(l1.position("Thor") == 4);
    assert(l1.position("Hulk") == 3);
    assert(l1.position("Black Widow") == 2);
    assert(l1.position("Iron Man") == 1);
    assert(l1.position("Captain America") == 0);
    assert(l1.position("Not there") == -1);
    assert(l1.before("Not there", "Hulk") == false);
    assert(l1.before("Hulk", "Not there") == false);
    assert(l1.before("Hulk", "Captain America") == false);
    assert(l1.before("Black Widow", "Hulk") == true);
    assert(l1.before("Captain America", "Hulk") == true);
    assert(l1.min() == "Black Widow");
    l1.removeAllBiggerThan("Happy");
    // now just "Captain America", "Black Widow"
    assert(l1.size() == 2);
    assert(l1.position("Hawkeye") == -1);
    assert(l1.position("Thor") == -1);
    assert(l1.position("Hulk") == -1);
    assert(l1.position("Black Widow") == 1);
    assert(l1.position("Iron Man") == -1);
    assert(l1.position("Captain America") == 0);
    assert(l1.position("Not there") == -1);

    List test; //apple, banana, apple, guava, mango
    test.addToRear("Apple");
    test.addToRear("Banana");
    test.addToRear("Apple");
    test.addToRear("Guava");
    test.addToRear("Mango");
    assert(test.size() == 5);
    assert(test.position("Apple") == 0);
    assert(test.position("Banana") == 1);
    assert(test.position("Apple") != 2);
    assert(test.position("Guava") == 3);
    assert(test.position("Mango") == 4);
    assert(test.position("Kiwi") == -1);
    assert(test.before("Banana", "Apple") == true);
    assert(test.before("Apple", "Banana") == true);
    string pear = "pear";
    assert(test.get(1, pear) == true);
    assert(pear == "Banana");
    assert(test.min() == "Apple");
    test.removeAllBiggerThan("Grape");
    assert(test.position("Apple") == 0);
    assert(test.position("Banana") == 1);
    assert(test.position("Guava") == -1);
    assert(test.position("Mango") == -1);

    List empty;
    assert(empty.size() == 0);
    assert(empty.position("") == -1);
    assert(empty.before("", "") == false);
    string a = "a";
    assert(empty.get(1, a) == false);
    assert(empty.min() == "");
    empty.removeAllBiggerThan("");
    assert(empty.size()==0);
    empty.addToFront("");
    assert(empty.size() == 1);

    cerr << "all tests passed!" << endl;

    return(0);
}

/*
using namespace std;
using namespace cs32;

enum class CHOICE {MAKEEMPTY, ISEMPTY, ADDTOFRONT, ADDTOREAR, DELETE, FIND, QUIT, PRINT, OPERATOR };

CHOICE menu();

int main(int argc, char* argv[]) {
    
	string value;
	List list;
    List list2;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
        case CHOICE::MAKEEMPTY:
			list.makeEmpty();
			break;
        case CHOICE::ISEMPTY:
			if (list.isEmpty()) {
				cout << "list is empty" << endl;
			}
			else {
				cout << "list is not empty" << endl;
			}
			break;
        case CHOICE::DELETE:
			cout << "Please provide a string to remove: ";
			cin  >> value; 
			list.deleteItem( value );
			break;
        case CHOICE::ADDTOFRONT:
			cout << "Please provide a string to insert in front: ";
			cin  >> value; 
			list.addToFront( value );
			break;
        case CHOICE::ADDTOREAR:
            cout << "Please provide a string to insert in rear: ";
            cin  >> value;
            list.addToRear( value );
            break;
        case CHOICE::FIND:
			cout << "Please provide a string to find: ";
			cin  >> value;
            cout.setf( ios::boolalpha );
            cout << list.findItem( value ) << endl;
            cout.unsetf( ios::boolalpha );
			break;
        case CHOICE::PRINT:
            cout << list.printItems() << endl;;
			break;
        case CHOICE::OPERATOR:
            list2 = list;
            cout << "second list now:" << endl;
            cout << list2.printItems() << endl;
            break;
        case CHOICE::QUIT:
            break;
	}	

	} while (choice != CHOICE::QUIT);

	return( 0 );
}

CHOICE menu() {
	string s;
	CHOICE result;
	cout << "(M)akeEmpty I(s)Empty (D)elete (A)ddToFront (R)AddtoRear  (F)ind (P)rint (=) (Q)uit: " << endl;
	cin  >> s;
    char choice = s.at( 0 );
	switch( choice ) {
	case 'M':
	case 'm':
		result = CHOICE::MAKEEMPTY;
		break;
    case 'D':
    case 'd':
        result = CHOICE::DELETE;
        break;
	case 'S':
	case 's':
		result = CHOICE::ISEMPTY;
		break;
    case 'A':
    case 'a':
        result = CHOICE::ADDTOFRONT;
        break;
	case 'R':
	case 'r':
		result = CHOICE::ADDTOREAR;
		break;
	case 'F':
	case 'f':
		result = CHOICE::FIND;
		break;
	case 'Q':
	case 'q':
		result = CHOICE::QUIT;
		break;
	case 'P':
	case 'p':
		result = CHOICE::PRINT;
		break;
    case '=':
        result = CHOICE::OPERATOR;
        break;
    default:
        result = CHOICE::QUIT;
        break;
	}

	return( result );
}
*/
