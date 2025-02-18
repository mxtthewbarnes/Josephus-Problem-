#pragma once 

#include "Destination.hpp"
#include <iostream> 
#include <list> 


class ListMyJosephus{
    private: 
        //elimination interval
        int M; 

        //tot. initial locations
        int N; 

        //initialzing std::list of Destination's objects
        list<Destination> destinations; 

    public: 
        //constructor
        ListMyJosephus(int mInterval, int nLocations); 

        //Destructor
        ~ListMyJosephus() {}

        //-----------Member Funcs.-------------
        void clear(); 
        int currentSize() const; 
        bool isEmpty() const; 
        void eliminateDestination(); 
        void printAllDestinations() const; 
}; 
