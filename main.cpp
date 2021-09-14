// Aidan Park
// main.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5

#include "stats.h"
#include "p1_library.h"
#include <iostream>
using namespace std;

int main()
{
    string fileName;
    string columnName;
    vector<double> exColumn;
    vector<vector<double> > sumColumn;

    cout << "enter a filename" << endl;
    cin >> fileName;

    cout << "enter a column name" << endl;
    cin >> columnName;
    cout << "reading column B from " << fileName << endl;
    cout << "Summary (value: frequency)" << endl;

    exColumn = extract_column(fileName, columnName);
    sumColumn = summarize(exColumn);

    //Print out value: frequency paris of our data held in 2D array
    for(size_t i = 0; i < sumColumn.size(); i++)
    {
        cout << sumColumn[i][0] << ": " << sumColumn[i][1] << endl;
    }

    int countPrint = count(exColumn);
    cout << "count = " << countPrint << endl;

    double sumPrint = sum(exColumn);
    cout << "sum = " << sumPrint << endl;

    double meanPrint = mean(exColumn);
    cout << "mean = " << meanPrint << endl;

    double stdevPrint = stdev(exColumn);
    cout << "stdev = " << stdevPrint << endl;

    double medianPrint = median(exColumn);
    cout << "median = " << medianPrint << endl;

    double modePrint = mode(exColumn);
    cout << "mode = " << modePrint << endl;

    double minPrint = min(exColumn);
    cout << "min = " << minPrint << endl;
    
    double maxPrint = max(exColumn);
    cout << "max = " << maxPrint << endl;

    double percentZeroPrint = percentile(exColumn, 0);
    cout << "  0th percentile = " << percentZeroPrint << endl;

    double percent25thPrint = percentile(exColumn, .25);
    cout << " 25th percentile = " << percent25thPrint << endl;
    
    double percent50thPrint = percentile(exColumn,.5);
    cout << " 50th percentile = " << percent50thPrint << endl;

    double percent75thPrint = percentile(exColumn, .75);
    cout << " 75th percentile = " << percent75thPrint << endl;

    double percent100thPrint = percentile(exColumn, 1.0);
    cout << "100th percentile = " << percent100thPrint << endl;
}