
#pragma once
#include "SimpleData.h"
class TextureData : public SimpleData
{
public:

	int vLen;
	int iLen;
	unsigned int * indices;
	unsigned int EBO;

	// constructor reads and builds the shader
	TextureData(string vName);
	// use/activate the shader
	float * readFromPath(string fName) override;
	void use() override;
	~TextureData();
};