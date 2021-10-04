
#pragma once
#ifndef SIMPLEDATA_H
#define SIMPLEDATA_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class SimpleData
{
public:
	unsigned int VAO;
	float * data;
	int size;
	// the program ID
	unsigned int ID;
	// constructor reads and builds the shader
	SimpleData(string vName);
	// use/activate the shader
	void use();

	~SimpleData();
};

#endif
