// Need for cin and cout
#include <iostream> 
// Need for reading in csv
#include <fstream>
// Need for string manipulation
#include <string>
// Needed for vector data structure
#include <vector>
// Needed for sqrt function
#include <cmath>
// Use namespace std to avoid needing to write things like std::cout
using namespace std;
// Use the header file made for this assingment
#include "Kelly_Statistics.h"


// function main begins program execution
int main()
{
    //instantiate an object of Statistics class
	Statistics myStatistics;
    
    //declare necessary variables
	string line; // for reading in the file as a string
	size_t sz; // needed for conversion of string to double
	double curr, average, SD; //iterator, average, and standard deviation

    // open the .csv file
	ifstream fin("data.csv");
    // while it still has lines
	while(getline(fin, line)){
        // set curr to the current value
		curr = stod(line, &sz);
        // add the current value to the instance of the class
		myStatistics.add(curr);
	} //end while

    // find the average of the class instance
	average = myStatistics.getAverage();
    // find the standard eviation of the class instance
	SD = myStatistics.getStandardDeviation();

    //print out results
	cout << "The Average for the dataset was: " << average << "\n";
	cout << "The Standard Deviation for the dataset was: " << SD << "\n";

} // end main
