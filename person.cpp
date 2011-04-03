#include "person.h"
#include <iostream>
#include <string>
Person::Person(){
	name = "foobar";
	std::cout << "i am the person constructor" << std::endl;
}

Person::Person(std::string name){
	this->name = name;
	std::cout << "i am the person constructor with a name param" << name << std::endl;
}

Person::~Person(){
	std::cout << "i am the person destructor" << std::endl;
}

void Person::hello(){
	std::cout << "hi, my name is " << name << std::endl;
}
