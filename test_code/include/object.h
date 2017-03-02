
/**
 *@file object.h
 *@author kunle Ade-Aina
 *@date Feb 24,2017 
 *@ brief object decorator class
 */


/**
 * @ brief API  Decorator Object for string or integer
 */


#ifndef OBJECT_H_
#define OBJECT_H_
 

#include "badcast.h"
using  std:: string;
class Object {                                 // generic object
     public:
       int      intValue()    const throw(BadCast);
       string   stringValue() const throw(BadCast);
       virtual ~Object(){};
};

class String : public Object {
  private:
    string value;
  public:
    String(string v = "") : value(v) { }
    string getValue() const
	  { return value; }
  };

class Integer : public Object {
  private:
    int value;
  public:
    Integer(int v = 0) : value(v) { }
    int getValue() const
	  { return value; }
  };







#endif
