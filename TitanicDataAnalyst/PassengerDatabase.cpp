#include "PassengerDatabase.h"
#include "CSVFile.h"
#include <iterator> 
using namespace std;

namespace cs32
{
    PassengerDatabase::PassengerDatabase() {
        isLoaded = false; //default value
    }
    PassengerDatabase::~PassengerDatabase() {
        clearAllPassengers();
    }

    int PassengerDatabase::load(std::string filePath) {
        CSVFile file(this);
        int recordCount = file.readFile(filePath);
        if (recordCount == 0) { //checks if file is correctly read
            isLoaded = false;
        }
        else
            isLoaded = true;
        return(recordCount);
    }
    void PassengerDatabase::clearAllPassengers() {
        for (int i = 0; i < passengers.size(); i++) {
            delete passengers.at(i); //deletes what is newed to prevent memory leaks
        }
        passengers.clear();
    }
    bool PassengerDatabase::loaded() {
        return isLoaded;
    }

    Passenger* PassengerDatabase::getPassenger_byName(std::string name) {
        for (int i = 0; i < passengers.size(); i++) { //loops through passengers to find matching name (if multiple with same name, returns first passenger with name)
            if (passengers[i]->getName() == name) { 
                return passengers[i];
            }
        }
        return nullptr; 
    }
    std::vector < Passenger* > PassengerDatabase::getPassengers() {
        return passengers;
    }
    std::vector < Passenger* > PassengerDatabase::getPassengers_byClass(Class paidClass, bool survived, double minimumFare) {
        std::vector < Passenger* > byClass;
        for (int i = 0; i < passengers.size(); i++) { //loops through passengers to find passengers where all parameters are met
            if (passengers[i]->getClass() == paidClass && passengers[i]->getSurvived() == survived && passengers[i]->getFare() > minimumFare) {
                byClass.push_back(passengers[i]);
            }
        }
        return byClass;
    }
    std::vector < Passenger* > PassengerDatabase::getPassengers_byEmbarcation(Embarcation embarked, bool Survived, double minimumFare) {
        std::vector < Passenger* > byEmbark;
        for (int i = 0; i < passengers.size(); i++) { //loops through passengers to find passengers where all parameters are met
            if (passengers[i]->getEmbarcation() == embarked && passengers[i]->getSurvived() == Survived && passengers[i]->getFare() > minimumFare) {
                byEmbark.push_back(passengers[i]);
            }
        }
        return byEmbark;
    }

    // part of the DataCollectorCallback interface 
    void PassengerDatabase::csvData(std::map< std::string, std::string > row) {
        Passenger* p1 = new Passenger(); //newed pointer which must be later deleted
        for (std::map< std::string, std::string >::iterator iter = row.begin(); iter != row.end(); iter++) {
            //checks key in map to see if it matches the correct category. if so, match the element to the correct category
            if (iter->first == "pclass") { 
                p1->setClass(iter->second);
            }
            if (iter->first == "survived") {
                p1->setSurvived(iter->second);
            }
            if (iter->first == "name") {
                p1->setName(iter->second);
            }
            if (iter->first == "fare") {
                p1->setFare(iter->second);
            }
            if (iter->first == "embarked") {
                p1->setEmbarcation(iter->second);
            }
            
        }
        passengers.push_back(p1);
    }
}

