
#pragma once
#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <Element.h>
using namespace std;

class Shader : public Element
{
public:
	// the program ID
	unsigned int ID;
	// constructor reads and builds the shader
	Shader(string vName, string fName);
	// use/activate the shader
	virtual void use() override;
	// utility uniform functions
	void setBool(const std::string &name, bool value) const;
	void setInt(const std::string &name, int value) const;
	void setFloat(const std::string &name, float value) const;

	~Shader();
};

#endif