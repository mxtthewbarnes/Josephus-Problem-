#include "ListMyJosephus.hpp"


//constructor def. 
ListMyJosephus::ListMyJosephus(int mInterval, int nLocations) : M(mInterval), N(nLocations) {}


//destructor def.
ListMyJosephus::~ListMyJosephus() 
{
    clear(); 
}


//clear() uses std::list clear() to empty sequence 
void ListMyJosephus::clear()
{
    return destinations.clear(); 
}


//currentSize() uses std::list size() to fetch current size
int ListMyJosephus::currentSize() const
{
    return destinations.size(); 
}

//uses std::list empty(), returns true if list is indeed empty
bool ListMyJosephus::isEmpty() const
{
    return destinations.empty(); 
}



void ListMyJosephus::eliminateDestination()
{
    //initialize iterator, starts at beginning of list destinations
    auto it = destinations.begin(); 

    //while size of list is > 1, iterate by m-1, and reset iterator to 
    //beginning of list once it's reached the end. continues iterating m-1 
    while(destinations.size() > 1)
    {
        for(int i = 0; i < M - 1; i++)
        {
            advance(it, 1); 
            if (it == destinations.end()) 
            {
                it = destinations.begin(); 
            }
        }
        cout << "\tEliminating: " << endl;  
        cout << "\t--------------"; 
        it->printDestinationName(); 

        //erases desination that IT is pointing at, returns a pointer to the next destination to IT. 
        it = destinations.erase(it); 
    }
    cout << "The final Destination remaining is: "; 
    destinations.begin()->printDestinationName(); 
}