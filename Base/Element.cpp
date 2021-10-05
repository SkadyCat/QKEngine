#include "Element.h"

int Element::elementCount = 0;
Element::Element()
{
	this->op = nullptr;
	if (this->op == nullptr) {
		
		cout << "hello world" << endl;
	}
	elementCount++;
	cout << "create element " << elementCount << endl;
}

Element::Element(Element & cp)
{
	elementCount++;
	this->op = cp.op;
	cout << "create element(copy) " << elementCount << endl;
}

void Element::addOp(function<void(shared_ptr<Element>)> op)
{
	this->op = op;

}


Element::~Element()
{
	elementCount--;
	cout << "release element " << elementCount << endl;
}

void Element::use()
{
	
}
