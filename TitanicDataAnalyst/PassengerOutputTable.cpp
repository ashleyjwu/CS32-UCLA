#include "PassengerOutputTable.h"
#include "Passenger.h"
#include "PassengerDatabase.h"
#include "OutputTableRow.h"
#include <vector>
#include <iostream>
using namespace std;

namespace cs32 {
	PassengerOutputTable::PassengerOutputTable(std::vector< Passenger* > passengers) {
		mPassengerList = passengers;
	}

	void PassengerOutputTable::setOutputField(Field f) {
		mField = f;
	}
	void PassengerOutputTable::setDescription(std::string description) {
		mDescription = description;
	}
	Field PassengerOutputTable::getOutputField() {
		return mField;
	}
	std::string PassengerOutputTable::getDescription() {
		return mDescription;
	}

	void PassengerOutputTable::display() {
		cout << getDescription() << endl;
		cout << "\t\tSurvived  /  Total\t\t  %" << endl;
		//depending on which field, it prints a different table
		if (mField == Field::BYCLASS) {
			mRows.clear(); 
			OutputTableRow first;
			OutputTableRow second;
			OutputTableRow third;
			OutputTableRow notKnown;
			first.setDescription("First Class-");
			second.setDescription("Second Class-");
			third.setDescription("Third Class-");
			notKnown.setDescription("Not Known-");
			//loops through passenger list and matches it to a row/class
			for (int i = 0; i < mPassengerList.size(); i++) {
				if (mPassengerList.at(i)->getClass() == Class::FIRST) {
					first.setTotal(first.getTotal() + 1); //each time found, increase total
					if(mPassengerList.at(i)->getSurvived() == true)
						first.setSurvived(first.getSurvived() + 1); 
				}
				else if (mPassengerList.at(i)->getClass() == Class::SECOND) {
					second.setTotal(second.getTotal() + 1);
					if (mPassengerList.at(i)->getSurvived() == true)
						second.setSurvived(second.getSurvived() + 1);
				}
				else if (mPassengerList.at(i)->getClass() == Class::THIRD) {
					third.setTotal(third.getTotal() + 1);
					if (mPassengerList.at(i)->getSurvived() == true)
						third.setSurvived(third.getSurvived() + 1);
				}
				else if (mPassengerList.at(i)->getClass() == Class::NOTKNOWN) {
					notKnown.setTotal(notKnown.getTotal() + 1);
					if (mPassengerList.at(i)->getSurvived() == true)
						notKnown.setSurvived(notKnown.getSurvived() + 1);
				}
			}
			mRows.push_back(first); //add the rows in order
			mRows.push_back(second);
			mRows.push_back(third);
			mRows.push_back(notKnown);
		}
		else if (mField == Field::BYEMBARCATION) {
			mRows.clear();
			OutputTableRow c;
			OutputTableRow q;
			OutputTableRow s;
			OutputTableRow notKnown;
			c.setDescription("Cherbourg-");
			q.setDescription("Queenstown-");
			s.setDescription("Southhampton-");
			notKnown.setDescription("Not Known -");

			for (int i = 0; i < mPassengerList.size(); i++) {
				if (mPassengerList.at(i)->getEmbarcation() == Embarcation::CHERBOURG) {
					c.setTotal(c.getTotal() + 1);
					if (mPassengerList.at(i)->getSurvived() == true)
						c.setSurvived(c.getSurvived() + 1);
				}
				if (mPassengerList.at(i)->getEmbarcation() == Embarcation::QUEENSTOWN) {
					q.setTotal(q.getTotal() + 1);
					if (mPassengerList.at(i)->getSurvived() == true)
						q.setSurvived(q.getSurvived() + 1);
				}
				if (mPassengerList.at(i)->getEmbarcation() == Embarcation::SOUTHHAMPTON) {
					s.setTotal(s.getTotal() + 1);
					if (mPassengerList.at(i)->getSurvived() == true)
						s.setSurvived(s.getSurvived() + 1);
				}
				if (mPassengerList.at(i)->getEmbarcation() == Embarcation::NOTKNOWN) {
					notKnown.setTotal(notKnown.getTotal() + 1);
					if (mPassengerList.at(i)->getSurvived() == true)
						notKnown.setSurvived(notKnown.getSurvived() + 1);
				}
			}
			mRows.push_back(c);
			mRows.push_back(q);
			mRows.push_back(s);
			mRows.push_back(notKnown);
		}
		else if (mField == Field::BYFARE) {
			mRows.clear();
			OutputTableRow notKnown;
			OutputTableRow one;
			OutputTableRow ten;
			OutputTableRow twentyFive;
			OutputTableRow fifty;
			notKnown.setDescription("Not Known -");
			one.setDescription(" $1-$10-");
			ten.setDescription("$10-$25-");
			twentyFive.setDescription("$25-$50-");
			fifty.setDescription("   >$50-");

			for (int i = 0; i < mPassengerList.size(); i++) {
				if (mPassengerList.at(i)->getFare() == 0) {
					notKnown.setTotal(notKnown.getTotal() + 1);
					if (mPassengerList.at(i)->getSurvived() == true)
						notKnown.setSurvived(notKnown.getSurvived() + 1);
				}
				else if (mPassengerList.at(i)->getFare() <= 10) {
					one.setTotal(one.getTotal() + 1);
					if (mPassengerList.at(i)->getSurvived() == true)
						one.setSurvived(one.getSurvived() + 1);
				}
				else if (mPassengerList.at(i)->getFare() <= 25) {
					ten.setTotal(ten.getTotal() + 1);
					if (mPassengerList.at(i)->getSurvived() == true)
						ten.setSurvived(ten.getSurvived() + 1);
				}
				else if (mPassengerList.at(i)->getFare() <= 50) {
					twentyFive.setTotal(twentyFive.getTotal() + 1);
					if (mPassengerList.at(i)->getSurvived() == true)
						twentyFive.setSurvived(twentyFive.getSurvived() + 1);
				}
				else {
					fifty.setTotal(fifty.getTotal() + 1);
					if (mPassengerList[i]->getSurvived() == true)
						fifty.setSurvived(fifty.getSurvived() + 1);
				}
			}
			mRows.push_back(notKnown);
			mRows.push_back(one);
			mRows.push_back(ten);
			mRows.push_back(twentyFive);
			mRows.push_back(fifty);
		}
		//regardless of the field, call display() on each element mRows
		for (int i = 0; i < mRows.size(); i++) {
			mRows.at(i).display();
		}
		cout << endl; //for visual purposes
	}
	size_t PassengerOutputTable::rowCount() {
		return mRows.size();
	}
	OutputTableRow PassengerOutputTable::getRow(int index) {
		OutputTableRow row = mRows.at(index);
		return row;
	}
}