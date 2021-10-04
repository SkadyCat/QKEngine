
#pragma once
#ifndef SIMPLEDATA_H
#define SIMPLEDATA_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <Element.h>
using namespace std;

class SimpleData : public Element
{
public:
	unsigned int VAO;
	float * data;
	int size;
	// the program ID
	unsigned int ID;
	unsigned int VBO;
	// constructor reads and builds the shader
	SimpleData();
	SimpleData(string vName);
	// use/activate the shader

	virtual float * readFromPath(string fName);
	virtual void use() override;
	
	~SimpleData();
};

#endif
