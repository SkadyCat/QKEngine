
#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <Element.h>
using namespace std;

class Texture:public Element
{
public:
	unsigned int ID;
	Texture(string vName, int width, int height);
	void use() override;
	~Texture();
};

#endif

