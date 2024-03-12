#include "OutputTableRow.h"
#include <string>
#include <iostream>
using namespace std;

namespace cs32 {
	OutputTableRow::OutputTableRow() {
		mDescription = ""; //default values
		mSurvived = 0;
		mTotal = 0;
	}

	void OutputTableRow::setDescription(std::string description) {
		mDescription = description;
	}
	void OutputTableRow::setSurvived(int survived) {
		mSurvived = survived;
	}
	void OutputTableRow::setTotal(int total) {
		mTotal = total;
	}

	std::string OutputTableRow::getDescription() {
		return mDescription;
	}
	int OutputTableRow::getSurvived() {
		return mSurvived;
	}
	int OutputTableRow::getTotal() {
		return mTotal;
	}
	double OutputTableRow::getPercentage() {
		if (mTotal == 0) { //prevents division by zero
			return 0;
		}
		return mSurvived / (double)mTotal; //typecast to have ints converted into a double
	}

	void OutputTableRow::display() {
		double a = getPercentage() * 100; //displays the proportion as a percentage
		cout << mDescription << "\t" << mSurvived << "\t / \t" << mTotal << "\t\t" << a << endl;
	}

	string padToThreeCharacters(int value) { //not used, just to prevent g32 from giving a warning
		string a = "";
		for (int i = 0; i < value; i++) {
			a = a + " ";
		}
		return a;
	}
}