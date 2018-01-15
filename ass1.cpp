//-----------------------------------------------------------------------------
// Name:		Nicholas Gorsline
// Date:		1/12/2018
// Course:		CSS 343 Winter 2018
// Professor:	Dr. Yusuf Pisan

// File Name:	ass1.cpp
// Description:	This is the test program for TurtleProgram. It tests all the
//				operator overloads to make sure they function corrently and
//				there are no errors
//-----------------------------------------------------------------------------
#include "turtleprogram.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

// Create a shortcut so alleviate the need to type TurtleProgram
// over and over
typedef TurtleProgram tp;

// This method tests the operator +
void testPlus() {
	cout << "\nTest: Plus" << endl;
	tp x("1", "2");
	tp y("3", "4");
	tp z("5", "6");
	tp z1;
	z = x + y + z;
	cout << z << endl;
}

// This method tests the operator +=
void testPlusEquals() {
	cout << "\nTest: Plus Equals" << endl;
	tp x("1", "2");
	tp y("3", "4");
	tp z("a", "f");
	z += y;
	cout << z << endl;

	y += x;
	cout << y << endl;;

	x += z;
	cout << x << endl;
}

// This method tests the operator =
void testEquals() {
	cout << "\nTest: Equals" << endl;

	tp a("Hello", "World");
	tp z = a;
	cout << z << endl;
}

// This method tests the operator *
void testMult() {
	cout << "\nTest: Multiplication" << endl;
	tp hi("Hello", "There");
	tp bye;
	bye = hi * 4;
	cout << bye << endl;
	// Test throw
	try {
		bye = hi * 0;

	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}
	cout << bye << endl;
	tp teest("Hiii", "Byyye");
	teest = hi * 8;
	cout << teest << endl;

}

// This method tests the operator *=
void testMultEqual() {
	cout << "\nTest: Multiplication Equals" << endl;
	tp foo("Hello", "Fren");
	tp bar("Hows", "Life");
	foo += bar;
	cout << foo << endl;
}

// This method tests the operator ==
void testEqualsEquals() {
	cout << "\nTest: Equality" << endl;

	tp foo("Hello", "World");
	tp bar;
	bar = foo;
	bool result = foo == bar;
	cout << "Result = " << result << endl;

	bar += foo;
	result = foo == bar;
	cout << "Result = " << result << endl;

}

// This method tests the operator !=
void testBangEquals() {
	cout << "\nTest: Bang Equals" << endl;

	tp foo("Hello", "World");
	tp bar;
	bar = foo;
	bool result = foo != bar;
	cout << "Result = " << result << endl;

	bar += foo;
	result = foo != bar;
	cout << "Result = " << result << endl;
}

// This method tests the getLength method of TurtleProgram
void testGetLength() {
	cout << "\nTest: GetLength" << endl;
	TurtleProgram foo("Element", "Dos");
	foo *= 3;
	cout << "Expected 6. Actual = \"" << foo.getLength() << "\"" << endl;
}

// This method tests the getIndex method of TurtleProgram
void testGetIndex() {
	cout << "\nTest: GetIndex" << endl;
	TurtleProgram foo("Element", "Dos");
	cout << foo.getIndex(0) << endl;
	try {
		cout << foo.getIndex(3) << endl;
	}
	catch (out_of_range e) {
		cout << e.what() << endl;
	}

}

// This method tests the setIndex method and its error catching
void testSetIndex() {
	cout << "\nTest: SetIndex" << endl;
	TurtleProgram foo("Element", "Dos");
	foo.setIndex(0, "Hello!");
	cout << foo.getIndex(0) << endl;

	try {
		foo.setIndex(3, "Will error");
	}
	catch (out_of_range e) {
		cout << e.what() << endl;
	}

}

// Entry point for the code, where it will run all the tests
int main() {
	testPlus();
	testPlusEquals();
	testEquals();
	testMult();
	testMultEqual();
	testEqualsEquals();
	testBangEquals();
	testGetLength();
	testGetIndex();
	testSetIndex();

	// Professors tests
	cout << "\nEnd my test cases" << endl << endl;
	cout << "Begin provided test cases" << endl << endl;
	TurtleProgram tp1;
	cout << "tp1: " << tp1 << endl;
	TurtleProgram tp2("F", "10");
	cout << "tp2: " << tp2 << endl;
	TurtleProgram tp3("R", "90");
	tp1 = tp2 + tp3;
	cout << "tp1 now as tp2+tp3: " << tp1 << endl;
	tp1 = tp2 * 3;
	cout << "tp1 now as tp2 * 3: " << tp1 << endl;
	TurtleProgram tp4(tp1);
	cout << "tp4 is a copy of tp1: " << tp4 << endl;
	TurtleProgram tp5("F", "10");
	cout << "tp5: " << tp5 << endl;
	cout << boolalpha;
	cout << "tp2 and tp5 are == to each other: " << (tp2 == tp5) << endl;
	cout << "tp2 and tp3 are != to each other: " << (tp2 != tp3) << endl;
	cout << "index 0 of tp2 is " << tp2.getIndex(0) << endl;
	tp2.setIndex(0, "R");
	tp2.setIndex(1, "90");
	cout << "tp2 after 2 calls to setIndex: " << tp2 << endl;
	cout << "tp2 and tp3 are == to each other: " << (tp2 == tp3) << endl;
	// need to write additional tests for += *=
	cout << "Done." << endl;

	return 0;
}
