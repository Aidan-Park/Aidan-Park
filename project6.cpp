#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Planet       // Creates a planet struct w all our planet data
{
    int planetID;
    string planetName;
    int planetRow;
    int planetCol;
    char planetSym;
};

struct Map    // Creates a struct including our planet locations
{
    int startRow;
    int startCol;
    int endRow;
    int endCol;
    int rows;
    int cols;
};

void readLocationsData(ifstream &fin2, Map &map, vector<Planet> &planets)   // takes in location and planet data and stores it in the coresponding struct
{
    Planet planet;
    for(int i = 1; i <= 3; ++i)     // reads in only the first 3 lines which have our map data
    {
        fin2 >> map.rows >> map.cols >> map.startRow >> map.startCol >> map.endRow >> map.endCol;

        // once we finish the third row, want to continue to next rows but read in planet data
        if (i == 3)
        {
            while(fin2 >> planet.planetRow >> planet.planetCol >> planet.planetSym >> planet.planetName)
            {
                if (planet.planetRow < map.endRow || planet.planetRow > map.startRow || planet.planetCol < map.endCol || planet.planetCol > map.startCol)
                {
                    planets.push_back(planet);
                }
            }
        }
    }

}

void readNamesData(ifstream &fin, vector<Planet> &planets)      // add extra planet data fron names file to planet vector
{
    for(int i = 0; i < planets.size(); ++i)
    {
        fin >> planets.at(i).planetID >> planets.at(i).planetName;
    }
}

void correctNames(vector<Planet> &planets)    // cleanses the planet names by removing unwanted characters
{
    int i;
    while(i < planets.size())   // removes Xs from planet names
    {
        string nameX = planets[i].planetName;

        nameX.erase(remove(nameX.begin(), nameX.end(), 'XX'), nameX.end());
        ++i;

        nameX.erase(remove(nameX.begin(), nameX.end(), 'XXX'), nameX.end());
        ++i;
        
        nameX.erase(remove(nameX.begin(), nameX.end(), 'XXXX'), nameX.end());
        ++i;
    }

    int j;
    while(j < planets.size())    // removes underscores from planet names
    {
        string nameU = planets[j].planetName;

        for (int i = 0; i < nameU.length(); ++i) 
        {
            if (nameU[i] == '_')
                nameU[i] = ' ';
        }
    }

}

/*
-create a vector of vectors of “.” w/ number of rows (indices in inner vector) and columns(indices of outer vector according to locations.txt
-place each planet’s assigned character in their row and column number instead of “.”
-use“S” at start point and “E” at end point
-open ostream to journey.txt
-output grid to journey.txt
-close ostream
*/

// creates a grid with only '.' w/ correct dimensions
void createBlankLocationGrid(const vector<Planet> &planet, const Map &map, vector<vector<char> > &rows)
{
    for(int numRows = 0; numRows < map.rows; ++numRows)
    {
        for(int numCols = 0; numCols < map.cols; ++numCols)
        {
            rows.at(numRows).at(numCols) == '.';
        }
    }
}

// goes through the blank grid and replaces '.' with planet symbol at appropriate start
// also adds 'S' and 'E' for start and end point
void addSymbols(const vector<Planet> &planets, const Map &map, vector<vector<char> > &rows)
{
    for(int numRows = 0; numRows < map.rows; ++numRows)
    {
        for(int numCols = 0; numCols < map.cols; ++numCols)
        {
            for(int i = 0; i < planets.size(); ++i)
            {
                if(numRows == planets.at(i).planetRow - 1 && numCols == planets.at(i).planetCol - 1)
                {
                    rows.at(numRows).at(numCols) = planets.at(i).planetSym;
                }

                if(numRows == map.startRow - 1 && numCols == map.startCol - 1)
                {
                    rows.at(numRows).at(numCols) = 'S';
                }
                
                else if (numRows == map.endRow - 1 && numCols == map.endCol - 1)
                {
                    rows.at(numRows).at(numCols) = 'E';
                }
            }
        }
    }
}

void printJourney(ofstream &fout, vector<vector<char> > rows)  // prints out grid with corresponding planet symbols, start, and end locations
{
for(int numRows = 0; numRows < rows.size(); ++numRows)
    {
        for(int numCols = 0; numCols < rows.at(numRows).size(); ++numCols)
        {
            fout << rows.at(numRows).at(numCols);
        }
        fout << endl;
    }
}

int main()
{
    string locationsFile;
    string namesFile;

    ifstream fin(namesFile);
    ifstream fin2(locationsFile);
    ofstream fout("journey.txt");

    vector<Planet> planets;
    Map map;

    vector< vector<char> > rows;

    cout << "Enter Locations Filename: " << endl;
    cin >> locationsFile;

    cout << "Enter Names Filename: " << endl;
    cin >> namesFile;

    if ( !(fin.is_open() && fin2.is_open()) )              // make sure that location and planet names files exists and can open
    {
        cout << "Input file could not be opened" << endl;
        return 1;
    }
}