
#pragma once
#include <string>
#include <iostream>
using namespace std;

class Element {
public:

	static int elementCount;
	Element();
	Element(Element& cp);
	~Element();
	virtual void use();
};