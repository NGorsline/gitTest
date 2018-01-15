//-----------------------------------------------------------------------------
// Name:		Nicholas Gorsline
// Date:		1/12/2018
// Course:		CSS 343 Winter 2018
// Professor:	Dr. Yusuf Pisan

// File Name:	TurtleProgram.cpp
// Description:	This program allows you to create, and manipulate
//				TurtleProgram instructions.
//-----------------------------------------------------------------------------

#include "turtleprogram.h" // Turtle Program class definition
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
//	Default constructor for class Array (default size 0)
TurtleProgram::TurtleProgram() {
	size = 0;
}

// Two parameter constructor (size 2)
TurtleProgram::TurtleProgram(string s1, string s2) {
	strArr = new string[2];
	strArr[0] = s1;
	strArr[1] = s2;
	size = 2;
}

// Copy constructor for class TurtleProgram
// Must recieve a reference to a TurtleProgram
// Utilizes the operator = overload to perform the copy
TurtleProgram::TurtleProgram(const TurtleProgram& rhs) {
	*this = rhs;
}

// Destructor for class TurtleProgram
TurtleProgram::~TurtleProgram() {
	delete[] strArr;
	strArr = NULL;
}

// Operator + overload
const TurtleProgram TurtleProgram::operator + (const TurtleProgram &rhs) const {
	// TurtleProgram to be returned as the result of the + operation
	TurtleProgram result;

	// Getting the size for the new array
	int totalSize = this->getLength() + rhs.getLength();
	result.strArr = new string[totalSize];
	result.size = totalSize;
	// The current index in the new array, so the program knows where
	// to insert the next item
	int curIndex = 0;
	// Add all elements in *this to new array
	for (int i = 0; i < this->getLength(); i++) {
		result.setIndex(curIndex, this->getIndex(i));
		curIndex++;
	}
	// Add all elements in rhs to new array
	for (int j = 0; j < rhs.getLength(); j++) {
		result.setIndex(curIndex, rhs.getIndex(j));
		curIndex++;
	}
	return result;
}

// Operator += overload
TurtleProgram TurtleProgram::operator += (TurtleProgram & rhs) {
	// Getting the size for the new array
	int totalSize = this->getLength() + rhs.getLength();
	// Create new array, that will take the place of the current
	string * newArray = new string[totalSize];
	// Current index tracker
	int curIndex = 0;
	// Add all elements in *this to new array
	for (int i = 0; i < this->getLength(); i++) {
		newArray[curIndex] = this->getIndex(i);
		curIndex++;
	}
	// Add all elements in rhs to new array
	for (int j = 0; j < rhs.getLength(); j++) {
		newArray[curIndex] = rhs.getIndex(j);
		curIndex++;
	}
	// Set the size of *this to the new size
	this->size = totalSize;
	// Release the old array
	delete[] this->strArr;
	// Set new array to current object
	strArr = newArray;
	return *this;
}

// Operator = overload
TurtleProgram & TurtleProgram::operator = (const TurtleProgram & rhs) {
	// Check if the object is being set equal to itself
	if (this == &rhs) {
		return *this;
	}
	// Delete the array that is currently in this
	delete[] this->strArr;
	// Take size of rhs to update this
	int sizeRhs = rhs.getLength();
	// Create new array for this
	this->strArr = new string[sizeRhs];
	// Move all elements from rhs onto this
	for (int i = 0; i < sizeRhs; i++) {
		strArr[i] = rhs.getIndex(i);
	}
	// Update size of TurtleProgram
	this->size = sizeRhs;
	return *this;
}
// Operator * overload
TurtleProgram TurtleProgram::operator * (int n) {
	// Object to be returned
	TurtleProgram result;
	// Checking if the param is valid for multiplication
	// Otherwise, throw an error to be caught
	if (n <= 0) throw invalid_argument("Error: That value is not valid.");
	int newSize = this->getLength() * n;
	result.size = newSize;
	// Create new array of appropriate size
	result.strArr = new string[newSize];
	int curIndex = 0;
	// Loop through n times, adding all instructions to new array each pass
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < this->getLength(); j++) {
			result.setIndex(curIndex, this->getIndex(j));
			curIndex++;
		}
	}
	return result;
}

// Operator *= overload
TurtleProgram TurtleProgram::operator *= (int n) {
	// Throw error if given invalid n
	if (n <= 0) throw invalid_argument("Error: That value is not valid.");
	int newSize = this->getLength()*n;
	// Setting the new size based off the provided n
	string* newArr = new string[newSize];
	int curIndex = 0;
	// Loop through n times, adding all instructions to new array each pass
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < this->getLength(); j++) {
			newArr[curIndex] = this->getIndex(j);
			cout << "current index" << curIndex << endl;
			curIndex++;
		}
	}
	// free memory that could be at this->strArr
	delete[] this->strArr;
	this->strArr = newArr;
	return *this;
}

// Operator ==
bool TurtleProgram::operator==(TurtleProgram & rhs) {
	int lhsSize = this->getLength();
	int rhsSize = rhs.getLength();
	// Check if the sizes aren't equal
	// If they are not, return false as they could not be the same
	if (lhsSize != rhsSize) {
		return false;
	}
	else {
		// Check each element one by one against its counterpart in the
		// rhs array
		for (int i = 0; i < lhsSize; i++) {
			// If invalid match is found, return out
			if (this->getIndex(i) != rhs.getIndex(i)) {
				return false;
			}
		}
	}
	// Got through both arrays after checking all their contents
	return true;
}

// Operator != overload
bool TurtleProgram::operator!=(TurtleProgram & rhs) {
	// Uses the operator == to get a result, and returns the inverse
	bool result = *this == rhs;
	if (result) return false;
	return true;
}
// Operator << overload
ostream & operator << (ostream & output, TurtleProgram & tp) {
	// Formats the output of a TurtleProgram object
	output << "[";
	for (int i = 0; i < tp.getLength(); i++) {
		output << tp.getIndex(i);
		// Only print a space if it is not the last element
		if (i != tp.getLength() - 1) output << " ";
	}
	output << "]";
	return output;
}

// This method returns the element at the parameter index
string TurtleProgram::getIndex(int index) const {
	if (index < size) {
		return strArr[index];
	}
	else {
		throw out_of_range("The index was out of range");
	}
}

// Get Length function
int TurtleProgram::getLength() const {
	return size;
}

// Set Index function
void TurtleProgram::setIndex(int index, string str) {
	if (index < size) strArr[index] = str;
	else {
		throw out_of_range("The index was out of range");
	}
}
