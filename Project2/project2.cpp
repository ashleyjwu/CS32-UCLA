#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int modulo(unsigned int m, unsigned int n) {
	if (m == n) { //of course, m/n always has a remainder of 0
		return 0;
	}
	if (m < n) { //when m<n for m/n, the remainder will be m
		return m;
	}
	return modulo(m - n, n); //if m>n, then we will subtract n as many times as needed until m<n
}

int occurrences(int number, int d) {
	int count = 0; //keeps track of whether d appears in number
	if (number == 0) { //base case
		return count;
	}
	if (number % 10 == d) { //checks if the last digit in the number is d
		count++;
	}
	number = number / 10; //gets rid of the last digit
	return count + occurrences(number, d); //keeps running occurences to check all digits
}

string lucky7s(string s) {
	if (s.length() < 2) { //if string length is less than 2, it cannot have 2 consecutive characters
		return s;
	}
	string first = s.substr(0, 1); //first character
	string next = s.substr(1, 1); //second character
	string last = s.substr(1); //string excluding first character
	if (first == next) {
		return first + "77" + lucky7s(last); //if first and second character are equal, place 77 between them
	}
	return first + lucky7s(last); //check for the rest of the string

}

bool combinations(int array[], int size, int target) {
	if (target == 0) { //there are some elements of array that can be subtracted from target to get 0 (meaning they can be added to get target)
		return true;
	}
	if (size <= 0 || target < 0) { //once we reach the first index of the array or the target has not been reached
		return false;
	}
	return combinations(array, size - 1, target) || combinations(array, size - 1, target - array[size-1]); //for each element in the array, either subtract from target or skip this element
}

int main() {
	assert(modulo(100, 10) == 0);
	assert(modulo(1, 13) == 1);
	assert(modulo(12, 5) == 2);
	assert(modulo(15, 15) == 0);
	assert(modulo(68, 6) == 2);
	assert(modulo(33, 6) == 3);

	assert(occurrences(567, 2) == 0);
	assert(occurrences(128874, 2) == 1);
	assert(occurrences(212121, 2) == 3);
	assert(occurrences(3636, 3) == 2);
	assert(occurrences(0, 0) == 0);
	assert(occurrences(0, 5) == 0);

	assert(lucky7s("cs32") == "cs32");
	assert(lucky7s("Apple Baseball") == "Ap77ple Basebal77l");
	assert(lucky7s("abbba") == "ab77b77ba");
	assert(lucky7s("  ") == " 77 ");
	assert(lucky7s("111") == "1771771");

	int array[5] = { 2, 4, 6, 8, 10 };
	assert(combinations(array, 5, 10) == true);
	assert(combinations(array, 5, 18) == true);
	assert(combinations(array, 5, 15) == false);

	int other[5] = { 10, 8, 2, 6, 4 };
	assert(combinations(other, 5, 10) == true);
	assert(combinations(other, 5, 18) == true);
	assert(combinations(other, 5, 15) == false);

	int again[4] = { 2,5,7,2 };
	assert(combinations(again, 4, 4) == true);
	assert(combinations(again, 4, 16) == true);
	assert(combinations(again, 4, 0) == true);
	assert(combinations(again, 4, -3) == false);
	assert(combinations(again, 4, 2) == true);
		
	return(0);
}
