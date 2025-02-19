#include "ListMyJosephus.hpp"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <sstream>

using namespace std;





 //func loads destinations from a CSV file into a 2D vector.
 //each row in the file represents a list of destinations, separated by ; 
vector<vector<string>> loadDestinations(const string& filename) {
    vector<vector<string>> allRows;
    ifstream file(filename);
    string line;
    if (!file) {
        cerr << "couldnt open:" << filename << endl;
        return allRows;
    }
    while (getline(file, line)) {
        vector<string> destinations;
        stringstream ss(line);
        string destination;
        while (getline(ss, destination, ';')) {
            destinations.push_back(destination);
        }
        allRows.push_back(destinations);
        if (allRows.size() == 25) break; 
    }
    file.close();
    return allRows;
}




/*
        I did TestVector first, detailed comments are over on that file 
*/
int main() {
    ofstream logFile("results.log", ios::app);
    if (!logFile) {
        cerr << "could not open results.log\n";
        return 1;
    }
    vector<vector<string>> allDestinations = loadDestinations("destinations.csv");
    if (allDestinations.size() < 25) {
        cerr << "Not enough rows in destinations.csv\n";
        return 1;
    }
    srand(time(nullptr));
    vector<double> executionTimes;
    for (int N = 1; N <= 1025; N *= 2) {
        int rowIdx = rand() % 25;  
        vector<string> selectedRow = allDestinations[rowIdx];
        if (N > selectedRow.size()) continue; 
        int M = (rand() % max(2, N)) + 1;  
        ListMyJosephus game(M, N, selectedRow);
        cout << "\n============================================" << endl;
        cout << "\tRunning Josephus Simulation - List" << endl;
        cout << "\tN = " << N << " & M = " << M << endl;
        cout << "============================================" << endl;        
        logFile << "N = " << N << ", M = " << M;
        clock_t start = clock();
        game.eliminateDestination();
        clock_t end = clock();
        double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;
        executionTimes.push_back(elapsedTime);
        cout << "CPU elapsed time in seconds: " << elapsedTime << endl;
        logFile << " | Execution Time: " << elapsedTime << " seconds\n";
    }





    //computes/prints execution time
    double totalTime = 0;
    for (double time : executionTimes) totalTime += time;
    double avgTime = executionTimes.empty() ? 0 : totalTime / executionTimes.size();

    cout << "\n\t(AVG) simulation time: " << avgTime << " seconds\n" << endl;
    logFile << "\n\t(AVG) simulation time: " << avgTime << " seconds\n";

    logFile.close();
    return 0;
}