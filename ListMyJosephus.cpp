#include "ListMyJosephus.hpp"


//constructor def. 
ListMyJosephus::ListMyJosephus(int mInterval, int nLocations) : M(mInterval), N(nLocations) {}


//destructor def.
ListMyJosephus::~ListMyJosephus() 
{
    clear(); 
}


//clear() empties sequence
void ListMyJosephus::clear()
{
    return destinations.clear(); 
}
