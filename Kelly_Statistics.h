// Need for cin and cout
#include <iostream> 
// Needed for vector data structure
#include <vector>
// Needed for sqrt function
#include <cmath>
// Use namespace std to avoid needing to write things like std::cout
using namespace std;

// Statistics class definition
class Statistics
{
public:
	// constructor initializes average and standard deviation
	// with double and double (respectively) supplied as arguments
	explicit Statistics(double avg, double SD)
	{
		average = avg;
		standardDeviation = SD;

	} // end Statistics constructor

	// constructor initializes average and standard deviation
	// sets them to 0
	// this is an example of constructor overloading
	explicit Statistics()
	{
		average = 0.0;
		standardDeviation = 0.0;

	} // end Statistics constructor	

	// function to get the average
	double getAverage()
	{
        // check to make sure vector isnt empty
        if(values.size() == 0){
            // if it is, exit failure
            cout << "You tried to enter an empty vector. ERROR" << endl;
            exit(EXIT_FAILURE);
        } //end if

		// variable declarations
		double total = 0;
		int denominator = values.size(); //use vector function .size() to count # of elements
		double avg = 0;
		
		// loop through the vector, and add each item to the total
		for (double curr : values){ //curr is the current element in the vector
			total += curr;
		} //end for

		// find the average of the passed in vector
		avg = total / denominator;

		// set the class instance's average to this average
		this->average = avg;
    
        // return object's average
		return average;

	} // end function getAverage

	// function to get the standard deviation
	double getStandardDeviation()
	{
        // check to make sure vector isnt empty
        if(values.size() == 0){
            // if it is, exit failure
            cout << "You tried to enter an empty vector. ERROR" << endl;
            exit(EXIT_FAILURE);
        } //end if

		// variable declarations
		double total = 0;
		int denominator = values.size(); // use vector function .size() to count # of elements
		double avg = 0;
		double SD = 0;
		
		// loop through the vector, and add each item to the total
		for (double curr : values){ //curr is the current element in the vector
			total += curr;
		} //end for

		// find the average of the passed in vector
		avg = total / denominator;

		// Loop back through the vector
		for(double index : values){ // declare an index iterator
			// update the standard deviation
			// this is essentially finding what's needed for variance
			SD += ((index - avg) * (index - avg));
		} //end for

		// divide that by the # of inputs and take the square root
		SD = sqrt(SD / denominator);

		// set the class instance's standardDeviation to this
		this->standardDeviation = SD;
        
        // return object's standard deviation
		return standardDeviation;

	} // end function getStandardDeviation

    // this function adds an item to the statistics class
	void add(double x){
        // add it to the vector data structure as part of Statistics
		values.push_back(x);
	} //end function add	

// member data
private:
	double average; // average stored as double
	double standardDeviation; // standard deviation stored as double
	vector<double> values; // the list of values, stored as a vector
}; // end class Statistics
