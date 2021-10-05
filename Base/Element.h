
#pragma once
#include <string>
#include <iostream>
#include<functional>

using namespace std;

class Element {
public:

	static int elementCount;
	Element();
	Element(Element& cp);
	void addOp(function<void(shared_ptr<Element>)> op);
	function<void(shared_ptr<Element>)> op;

	~Element();
	virtual void use();
};