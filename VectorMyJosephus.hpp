#pragma once 

#include "Destination.hpp"
#include <vector> 


class VectorMyJosephus{
    private: 
        int M; 
        int N; 

        string name; 
        
        //initializng vector using Destination objects. 
        vector<Destination> destinations; 

    public: 
        //constructor
        VectorMyJosephus(int mInterval, int nLocations); 

        //destructor
        ~VectorMyJosephus() {}

        //-------Member funcs----------
        void clear(); 
        int currentSize() const; 
        bool isEmpty() const; 
        void eliminationDestination(); 
        void printAllDestinations(); 
};
