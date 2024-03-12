#include "Passenger.h"
namespace cs32
{
	Passenger::Passenger() {
		mClass = Class::NOTKNOWN; //default values
		mEmbarked = Embarcation::NOTKNOWN;
		mName = "";
		mSurvived = false;
		mFare = 0;
	}
	void Passenger::setName(std::string name) {
		mName = name;
	}
	void Passenger::setEmbarcation(std::string embarked) {
		if (embarked == "C") { //converts string from file into embarcation locations
			mEmbarked = Embarcation::CHERBOURG;
		}
		else if (embarked == "Q") {
			mEmbarked = Embarcation::QUEENSTOWN;
		}
		else if (embarked == "S") {
			mEmbarked = Embarcation::SOUTHHAMPTON;
		}
		else {
			mEmbarked = Embarcation::NOTKNOWN;
		}
	}
	void Passenger::setClass(std::string classofFare) {
		//converts string from file into class
		if (classofFare == "1") {
			mClass = Class::FIRST;
		}
		else if (classofFare == "2") {
			mClass = Class::SECOND;
		}
		else if (classofFare == "3") {
			mClass = Class::THIRD;
		}
		else {
			mClass = Class::NOTKNOWN;
		}
	}
	void Passenger::setSurvived(std::string survived) { //converts string from file into boolean
		if (survived == "1") {
			mSurvived = true;
		}
		else {
			mSurvived = false;
		}
	}
	void Passenger::setFare(std::string fare) {
		if (fare > "0") {
			mFare = std::stof(fare); //converts string from file into numerical value
		}
	}
	std::string Passenger::getName() {
		return mName;
	}
	Embarcation Passenger::getEmbarcation() {
		return mEmbarked;
	}
	Class Passenger::getClass() {
		return mClass;
	}
	bool Passenger::getSurvived() {
		return mSurvived;
	}
	double Passenger::getFare() {
		return mFare;
	}
}
