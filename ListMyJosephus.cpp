#include "ListMyJosephus.hpp"


//constructor def. 
ListMyJosephus::ListMyJosephus(int mInterval, int nLocations, const vector<string>& names) : M(mInterval), N(nLocations)
{
    for(int i = 0; i < N; i++)
    {
        destinations.emplace_back(i, names[i]); 
    }
}


//destructor def. calls clear() 
ListMyJosephus::~ListMyJosephus() 
{
    clear(); 
}


//clear() uses std::list clear() to empty sequence 
void ListMyJosephus::clear()
{
    destinations.clear(); 
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
            if (++it == destinations.end()) 
            {
                it = destinations.begin(); 
            }       
        }
        cout << "\tEliminating:";   
        it->printDestinationName(); 

        //erases desination that IT is pointing at, returns a pointer to the next destination to IT. 
        it = destinations.erase(it); 
        if(it == destinations.end())
        {
            it = destinations.begin(); 
        }
    }
    if (!destinations.empty()) {
        cout << "The final Destination remaining is: ";
        destinations.front().printDestinationName();
    } else {
        cout << "No destination remaining!" << endl;
    }
} 



//initializes iterator to beginning of list, stops at the end. 
//prints each element before then
void ListMyJosephus::printAllDestinations() const
{
    for(auto it = destinations.begin(); it != destinations.end(); ++it)
    {
        it->printDestinationName(); 
    }
}