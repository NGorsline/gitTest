//-----------------------------------------------------------------------------
// Name:		Nicholas Gorsline
// Date:		1/12/2018
// Course:		CSS 343 Winter 2018
// Professor:	Dr. Yusuf Pisan

// File Name:	TurtleProgram.g
// Description:	This is the header file for TurtleProgram
//-----------------------------------------------------------------------------
#ifndef TURTLEPROGRAM_H
#define TURTLEPROGRAM_H
#include <iostream>
#include <string>

// Class declaration
class TurtleProgram
{
public:
	// Constructors
	TurtleProgram();
	TurtleProgram(std::string s1, std::string s2);
	TurtleProgram(const TurtleProgram& rhs);
	// Destructor
	~TurtleProgram();

	// Operator overloading
	const TurtleProgram operator + (const TurtleProgram & rhs) const;
	TurtleProgram operator += (TurtleProgram & rhs);
	TurtleProgram& operator = (const TurtleProgram & rhs);
	TurtleProgram operator * (int n);
	TurtleProgram operator *= (int n);
	bool operator == (TurtleProgram & rhs);
	bool operator != (TurtleProgram & rhs);
	friend std::ostream & operator << (std::ostream & output, TurtleProgram & tp);

	// Getters and setters
	std::string getIndex(int index) const;
	int getLength() const;
	void setIndex(int index, std::string str);
private:
	// Array holding all the strings
	std::string* strArr = NULL;
	// Current number of objects in the array
	int size;
};

#endif
