/*
* badcast.h
*/


/**
* @ brief API User Defined exeception class
* returns an exception message
*/

#ifndef BADCAST_H_
#define BADCAST_H_
#include <string>

class BadCast {

    private: 
	std::string errorMsg; 
    public:
        BadCast(const std::string& err) 
	{ 
		errorMsg = err; 
	} 
	std::string getMessage() const 
	{ 
		return errorMsg;
	}
};

#endif
