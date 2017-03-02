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


# ifndef BADCAST_H
# define BADCAST_H
# include <string>

class RuntimeException {
	// generic run-time exception private:   
	std::string errorMsg;
public:
	RuntimeException(const std::string& err) { errorMsg = err; }
	std::string getMessage() const { return errorMsg; }
};


class BadCast : public RuntimeException {
public:
	BadCast(const std::string& err) : RuntimeException(err) {}
};


class NonIncidentEdge : public RuntimeException {
public:
	NonIncidentEdge(const std::string& err) : RuntimeException(err) {}
};
# endif