#ifndef PassengerDatabase_h
#define PassengerDatabase_h

#include "DataCollectorCallback.h"
#include "Passenger.h"
#include <vector>
#include <string>

namespace cs32
{
class PassengerDatabase : public DataCollectorCallback {
public:
    PassengerDatabase();
    ~PassengerDatabase();

    int load(std::string filePath);
    void clearAllPassengers();
    bool loaded();

    Passenger * getPassenger_byName(std::string name);
    std::vector < Passenger* > getPassengers();
    std::vector < Passenger* > getPassengers_byClass
    (Class paidClass, bool survived, double minimumFare);
    std::vector < Passenger* > getPassengers_byEmbarcation
    (Embarcation embarked, bool Survived, double minimumFare);

    // part of the DataCollectorCallback interface 
    virtual void csvData(std::map< std::string, std::string > row);

private:
    std::vector < Passenger* > passengers;
    bool isLoaded;


};
}
#endif

