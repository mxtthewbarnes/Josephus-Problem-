#include "VectorMyJosephus.hpp"

//constructor def. 
VectorMyJosephus::VectorMyJosephus(int mInterval, int nLocations) : M(mInterval), N(nLocations) {}


//destructor def. 
VectorMyJosephus::~VectorMyJosephus()
{
    clear(); 
}

//currentSize() returns size of vector using size()
int VectorMyJosephus::currentSize() const
{
    int size = destinations.size(); 
    return size; 
}


bool VectorMyJosephus::isEmpty() const 
{
    return destinations.empty(); 
}


//going to be using direct index access instead of the iterator-based access
//used in the std::list version of this function. 
void VectorMyJosephus::eliminationDestination()
{
    int i = 0; 
    while(destinations.size() > 1)
    {
        i = i + M-1; 
        if(i >= destinations.size())
        {
            i -=destinations.size(); 
        }
        cout << "\n\tEliminating:" << endl; 
        cout << "\t----------------------" << endl; 
        destinations[i].printDestinationName(); 
    }

    cout << "\nThe final remaining destination is: "; 
    destinations.front().printDestinationName(); 
}