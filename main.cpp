#include <iostream>
#include <fstream>
#include "Simulation.h"

using namespace std;


vector<int> getFileInfo(const string& fileName) {
    vector<int> values;
    ifstream file (fileName);
    int temp{};
    while (file >> temp) {
        values.push_back(temp);
    }
    return values;
}


int main() {
    string inputFileName{"../SimulationFile.txt"};
    ifstream inputFileCheck(inputFileName);
    if (!inputFileCheck) {
        cerr << "It seems their is an error with the input file or it does not exits.\n" << endl;
    }
    inputFileCheck.close();

    // take fileInfo and store it to data members
    vector<int> values = getFileInfo(inputFileName);
    int gridSize = values[0];
    if (gridSize < 10) {
        cout << "You gave a size that is smaller than the minimum for the program, so I will default se it to 10 \n"
        << endl;
        gridSize = 10;
    }
    Grid environment(gridSize);

    Simulation simulation(environment, values[1], values[2], values[3], values[4], values[5]);
    simulation.runSimulation();
}