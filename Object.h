/****************************************************************************
Florida Institute Of Technology
College of Engineering
Electrical and Computer Engineering Department
Application : Graph Mining Research
Filename : BadCast.h  Function : Exception Class
File Dependencies : <string>
*****************************************************************************/
//===========================================================================
//                    MEMO
// Last Update : 3/23/2016 1.00pm
// Comments : Class Has  been tested in the Object.h and main : Test Passed
//===========================================================================

#ifndef BADCAST_H_
#define BADCAST_H_

#include "BadCast.h"


using std::string;

class Object {						// generic object
public:
	virtual ~Object() { }					// virtual destructor
	int      intValue()    const throw(BadCast);	// get integer value
	string   stringValue() const throw(BadCast);	// get string value


};

class Integer : public Object {				// integer object
private:
	int value;						// integer value
public:
	Integer(int v = 0) { value = v; }			// constructor
	int getValue() const { return value; }		// get the value

};

class String : public Object {				// string object
private:
	string value;						// string value
public:
	String(const string& v = "") { value = v; }		// constructor
	string getValue() const { return value; }		// get the value

};





// get Integer's value
int Object::intValue() const throw(BadCast)
{
	const Integer* p = dynamic_cast<const Integer*>(this);
	if (p == NULL) throw BadCast("intValue() from non-Integer");
	return p->getValue();
}




// get String's value
string Object::stringValue() const throw(BadCast)
{
	const String* p = dynamic_cast<const String*>(this);
	if (p == NULL) throw BadCast("stringValue() from non-String");
	return p->getValue();
}


# endif