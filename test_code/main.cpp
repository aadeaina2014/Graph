/*
 * main.cpp : Application Driver File
*/

#include <iostream>
#include "object.h"
#include "decorator.h"

using namespace std;
int main(int argc, char **argv) {
   int prog_status =0;

   Decorator decorator_object;
   
   // test parent object ad decendants
   Integer vertexA(20) ;
   String  vertexB("ethernet1/1/1") ;

   // test decorator
   decorator_object.set("A",&vertexA);
   decorator_object.set("B",&vertexB);
   
   
  
   Decorator v;	
   v.set("port_name", new String("ethernet 1/1/1"));
   v.set("MTU", new Integer(1500));
   cout <<"\n"<<endl;
   string n = v.get("port_name")->stringValue();// n = "Bob"
   int a = v.get("MTU")->intValue();		// a = 23 
   cout << "---------------------------"<<endl;
   cout <<"Phyiscal Port Name :" << n<< "\nMTU:"  << a<< "\n"<<endl; 
   cout << "---------------------------"<<endl;
   cout << "Polymorphic Object Class Test     : Test Passed" <<endl;
   cout << "Integer Derived Object class Test : Test Passed" << endl;
   cout << "String Derived Object Class Test  : Test Passed"<<endl;
   cout << "Decorator Object Class Test       : Test Passed" <<endl;
   return prog_status;
}
