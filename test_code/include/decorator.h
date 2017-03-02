/* *
 *@brief API Decorator Design Pattern 
 *    this decorator class is based on a container that can 
 *    store string and integer objects using string keys to
 *    index the underlying STL map data structure
 * @ author Ayokunle Ade-Aina
 * @ date February 24,2016
 * 
*/

#ifndef DECORATOR_H_
#define DECORATOR_H_

#include <map>
#include <string>
#include "Object.h"

using std::string;

class Decorator { 
      private:	       		// member data
          std::map<string,Object*> map;// the map
      public:
          Object* get(const string& a) { //set value of attribute
              return map[a]; 
	  }
          void set(const string& a, Object* d){ // set value
              map[a] = d; 
          }
  };
#endif
