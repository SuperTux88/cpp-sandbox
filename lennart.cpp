#include "lennart.h"
#include <iostream>
Lennart::Lennart() : Person("Lennart set from constructor"){
	std::cout << "i am the lennart constructor" << std::endl;
}

void Lennart::hello(){
	std::cout << "I am Lennart lulz" << std::endl;
}
