#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "person.h"
#include "lennart.h"
#define ARRAY_SIZE 10



void pointerFun();
void incrementByOne(int& x);
void incrementByOne(int* x);
void xFun();
void arrayFun();
void mallocFun();
void typeDefFun();
void structFun();
int main(int argc, char **argv){

// 	arrayFun();
//	xFun();
//	pointerFun();
//	mallocFun();
//	typeDefFun();
//	structFun();

	Person* person = new Person();
	person->hello();

	Person lennart ("lennart custom constructor");
	lennart.hello();

	Lennart* nochnLennart = new Lennart();
	nochnLennart->hello();

	Person* againLennart = new Lennart();
	againLennart->hello();

	delete person;

}

void incrementByOne(int& x){
	printf("incrementByOne (ref version) called!\n");
	x++;
}

void incrementByOne(int* x){
	printf("incrementByOne (ptr version) called!\n");
	(*x)++;
}


void xFun(){
	int x = 0;
	std::cout << "hallo welt!" << std::endl;
	printf("Mein X-Int: %d\n", x);	
	incrementByOne(x);
	printf("Mein X-Int: %d\n", x);	
	printf("Resolving address of x: %p\n",&x);
	incrementByOne(&x);
	printf("Mein X-Int: %d\n", x);	

}

void arrayFun(){
	int myInts[ARRAY_SIZE] = {1,2,3,4,5};
	int* myArrayPointer = myInts;
	int* secondArrayPointer = myInts;
	printf("Array begins on adress: %p - array: %p, address of the myArrayPointer: %p\n",myArrayPointer, myInts, &myArrayPointer);

	printf("Erster arraywert: %p - %d\n", myInts, *myInts);
	printf("Zweiter arrayWert: entweder: %d - oder %d oder %d oder %d oder %d\n", *(++myArrayPointer), myInts[1], secondArrayPointer[1], *(secondArrayPointer+1), *(myArrayPointer+1));
	printf("Zweiter arrayWert: entweder: %d - oder %d oder %d oder %d oder %d\n", *(++myArrayPointer), myInts[1], secondArrayPointer[1], *(secondArrayPointer+1), *(myArrayPointer+1));

	for(int i = 0; i < ARRAY_SIZE; i++){
		printf("ArrayWert[%d]: %d\n",i, myInts[i]);

	}

	// ATTENTION: ILLEGAL! -- will crash!
	int z=10;
	printf("addr of z: %p\n", &z);
	printf("crash-int: %d\n", myInts[10000000]);
	while(true){
		printf("myArray[%d] (%p) = 5 :)\n", z, &myInts[z]);
		myInts[z] = 5;
		z++;
	}



}

void pointerFun(){
	int x =  0;
	double y = 1;

	printf("int x: %d, float y: %f - sizeof x: %d, sizeof y: %d\n", x,y, sizeof(x), sizeof(y));
	printf("Adresse von x: %p, Adresse von y: %p, (Adresse von x)+1: %p, (Adresse von y)+1: %p\n", &x,&y, (&x)+1, (&y)+1);
}

void mallocFun(){
	while(true){
		int* myMemory = (int*)malloc(sizeof(int)*10);
		++myMemory;
		for(int i = 0; i < 10-1; i++)
			myMemory[i] = 10;
			//printf("myMemory[%d] %d\n",i,  myMemory[i]);
		free(--myMemory);
	}
}

void typeDefFun(){
	typedef int wuchst;
	typedef int zehnWuchstBrote[10];

	wuchst brot = 3;
	printf("mein wuchstbrot: %d\n", brot);
	zehnWuchstBrote hier; 
	hier[8] = 1337;
	for(int i = 0; i < 10; i++){
		printf("viele wuchstbrote von %d: %d\n", i, hier[i]);
	}
}

struct Vec2D {
	float x;
	float y;
};

void structFun(){
	Vec2D myVec;
	myVec.x = 1;
	myVec.y = 2;
	printf("myVec.x: %f, myVec.y: %f\n", myVec.x, myVec.y);

	Vec2D* myPointeredVec = (Vec2D*)malloc(sizeof(Vec2D));
	myPointeredVec->x = 1338;
	myPointeredVec->y = 1339;
	printf("myPointeredVec.x: %f, myPointeredVec.y: %f\n", (*myPointeredVec).x, (*myPointeredVec).y);
	printf("myPointeredVec.x: %f, myPointeredVec.y: %f\n", myPointeredVec->x, myPointeredVec->y);
	free(myPointeredVec);

	if(myVec.x == 2){
		printf("ho",23);
	} else {
		printf("hi",42);
	}

}
