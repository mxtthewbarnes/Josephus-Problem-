#include "VectorMyJosephus.hpp"

//constructor def. 
VectorMyJosephus::VectorMyJosephus(int mInterval, int nLocations, const vector<string>& names) : M(mInterval), N(nLocations) 
{
    for(int i = 0; i < N; i++)
    {
        destinations.emplace_back(i, names[i]); 
    }
}


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
    while (destinations.size() > 1)
    {
        i = (i + M - 1) % destinations.size();  
        
        cout << "\tEliminating: ";
        destinations[i].printDestinationName(); 
        
        destinations.erase(destinations.begin() + i); 

        if (i >= destinations.size()) {
            i = 0;  
        }
    }
    cout << "\nThe final remaining destination is: "; 
    destinations.front().printDestinationName(); 
}


//prints all destinations using: for(it in destinations) print it. 
void VectorMyJosephus::printAllDestinations() const
{
    for (const auto& it : destinations)
    {
        it.printDestinationName(); 
    }
}


void VectorMyJosephus::clear() {
    destinations.clear(); 
}