#include "Element.h"

int Element::elementCount = 0;
Element::Element()
{
	elementCount++;
	cout << "create element " << elementCount << endl;
}

Element::Element(Element & cp)
{
	elementCount++;
	cout << "create element(copy) " << elementCount << endl;
}

Element::~Element()
{
	elementCount--;
	cout << "release element " << elementCount << endl;
}

void Element::use()
{
	
}
