/* 
 *  object.cpp
 */

#include "object.h"

string Object::stringValue() const throw(BadCast) {  // cast to Integer
    const String* p = dynamic_cast<const String*>(this);
    if (p == NULL) throw BadCast("Illegal attempt to cast to Integer");
    return p->getValue();
  }

int Object::intValue() const throw(BadCast) {  // cast to Integer
    const Integer* p = dynamic_cast<const Integer*>(this);
    if (p == NULL) throw BadCast("Illegal attempt to cast to Integer");
    return p->getValue();
  }
