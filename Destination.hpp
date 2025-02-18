#pragma once

#include <iostream> 
#include <string> 

using namespace std; 



class Destination{
    private: 
        int position; 
        string name; 
    public: 
        
        //constructor
        Destination(int pos, const string& cityName); 

        //destructor
        ~Destination(); 


        //displays the destinations location
        void printPosition() const; 

        //displays destinations name
        void printDestinationName() const; 
};