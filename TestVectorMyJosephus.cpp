#include "VectorMyJosephus.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;



//loadDestinations() reads dest. in from the csv and stores them in a vector
//reads up to 25 rows and returns as 2D vector. 
vector<vector<string>> loadDestinations(const string& filename) {
    vector<vector<string>> allRows;
    ifstream file(filename);
    string line;

    if (!file) {
        cerr << "couldnt open" << filename << endl;
        return allRows;
    }

//reading each line from file 
    while (getline(file, line)) {
        vector<string> destinations;
        stringstream ss(line);
        string destination;

        //; delimiter
        while (getline(ss, destination, ';')) {
            destinations.push_back(destination);
        }

        allRows.push_back(destinations);

        //stops reading in after 25 lines 
        if (allRows.size() == 25) break; 
    }

    file.close();
    return allRows;
}




//main() initializes josephus simulation for different values of N and M 
//exectuions times are logged as well as printed to the console 
int main() {
    //opens results.log for logging exectuion times 
    ofstream logFile("results.log", ios::app);
    if (!logFile) {
        cerr << "couldnt open results.log\n";
        return 1;
    }

    //loads destinations from csv 
    vector<vector<string>> allDestinations = loadDestinations("destinations.csv");
    if (allDestinations.size() < 25) {
        cerr << "not enough rows in destinations.csv\n";
        return 1;
    }

    //seed random 
    srand(time(nullptr));

    //stores exec. times to be averaged towards the closing of the program
    vector<double> executionTimes;



    //iterates over diferent values of N.
    //increasing group sizes
    for (int N = 1; N <= 1025; N *= 2) {
        int rowIdx = rand() % 25;  
        vector<string> selectedRow = allDestinations[rowIdx];
        if (N > selectedRow.size()) continue; 
        int M = (rand() % max(2, N)) + 1;  

        //initialiazing josephus game instance and printing simulation 
        VectorMyJosephus game(M, N, selectedRow);
        cout << "\n============================================" << endl;
        cout << "\tRunning Josephus Simulation - vector" << endl;
        cout << "\tN = " << N << " & M = " << M << endl;
        cout << "============================================" << endl; 
        logFile << "N = " << N << ", M = " << M;

        //measures execution time 
        clock_t start = clock();
        game.eliminationDestination();
        clock_t end = clock();
        
        //computes elapsed time 
        double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
        executionTimes.push_back(elapsedTime);



        cout << "CPU elapsed time in seconds: " << elapsedTime << endl;
        logFile << " | Execution Time: " << elapsedTime << " seconds\n";
    }

    

    double totalTime = 0;
    for (double time : executionTimes) totalTime += time;
    double avgTime = executionTimes.empty() ? 0 : totalTime / executionTimes.size();



    cout << "\n(AVG) simulation time: " << avgTime << " seconds\n";
    logFile << "\n(AVG) simulation time (VectorMyJosephus): " << avgTime << " seconds\n";



    logFile.close();
    return 0;
}