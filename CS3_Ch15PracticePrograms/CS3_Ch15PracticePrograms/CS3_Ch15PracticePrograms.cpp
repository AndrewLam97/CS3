#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FreightContainer {
    string cargo;
    int load;
protected:
    int maxLoad = 500;
};

class TransportVehicle {
public:
    string registration;
    int age;
    int currentCap;
    vector<FreightContainer*> containerVec;

    bool addContainer(FreightContainer*);
    int maximumCap;
};

class Truck : public TransportVehicle {
public:
    int kmTravelled;
    Truck();
};

class Plane : public TransportVehicle {
public:
    int hoursFlown;
    Plane();
};

Truck::Truck() {
    maximumCap = 5;
    age = 1;
}

Plane::Plane() {
    maximumCap = 100;
    age = 2;
}

bool TransportVehicle::addContainer(FreightContainer* newContainer) {
    if (currentCap < maximumCap) {
        containerVec.push_back(newContainer);

        return true;
    }
    else
        return false;
}

void printFleet(vector<TransportVehicle*> fleet) {
    double totalUsed;
    double totalAvailable;

    for (auto x : fleet) {
        totalUsed += x->currentCap;
        totalAvailable += x->maximumCap;
        cout << "Registration: " << x->registration << endl;
        cout << "Age: " << x->age << endl;
        cout << "Capacity used: " << (double)x->currentCap / (double)x->maximumCap << endl;
        cout << endl;
    }
    cout << "Fleet capacity used: " << totalUsed / totalAvailable << endl;
}

int main()
{
    vector<TransportVehicle*> fleet;
}

//int main()
//{
//    Circle c(2);
//    cout << c.getName() << " has radius " <<
//        c.getRadius() << " and area " <<
//        c.getArea() << endl;
//    return 0;
//}