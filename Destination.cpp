#include "Destination.hpp"


//constructor def. 
Destination::Destination(int pos, string const& cityName) : position(pos), name(cityName) {}


//destructor def. 
Destination::~Destination() {} 


//prints destinations position
void Destination::printPosition() const
{
    cout << position << endl; 
}


//prints destinations name
void Destination::printDestinationName() const
{
    cout << name << endl; 
}

