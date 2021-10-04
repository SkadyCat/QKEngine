#include "TextureData.h"
#include "Utils.h"
TextureData::TextureData(string vName)
{
	string bufPath = getResourcesFolder() + "TextureData\\" + vName + ".dtexture";
	readFromPath(bufPath);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vLen * 4, this->data, GL_STATIC_DRAW);
	
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, iLen * 4, indices, GL_STATIC_DRAW);

	//指定位置属性
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//指定颜色属性
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	//指定纹理坐标
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	delete[] this->data;
	delete[] this->indices;
}

float * TextureData::readFromPath(string fName)
{
	string data;
	try
	{
		std::ifstream bufFile;
		//文件是否异常
		bufFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		bufFile.open(fName);
		stringstream readStream;
		//读取数据
		readStream << bufFile.rdbuf();
		data = readStream.str();
	}
	catch (ifstream::failure e) {
		std::cout << "ERROR::SIMPLEDATA::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	vector<string> lines = split(data, "\n");
	data = "";
	string vData = "";
	string iData = "";
	int code = 0;
	for (auto line : lines) {
		line = split(line, "#")[0];
		if (contains(line,"vertices")) {
			code = 1;
			continue;
		}
		if (contains(line, "indices")) {
			code = 2;
			continue;
		}
		if (code == 1) {
			vData += line;
		}
		if (code == 2) {
			iData += line;
		}
		
	}
	vector<string> vDataArr = split(vData, ",");
	vector<string> iDataArr = split(iData, ",");
	vLen = vDataArr.size();
	iLen = iDataArr.size();
	this->data = new float[vLen];
	this->indices = new unsigned int[iLen];
	for (int i = 0; i < vDataArr.size(); i++) {
		this->data[i] = atof(trim(vDataArr[i]).c_str());
	}
	for (int i = 0; i < iDataArr.size(); i++) {
		this->indices[i] = atoi(trim(iDataArr[i]).c_str());
	}
	return this->data;
}

void TextureData::use()
{
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, iLen, GL_UNSIGNED_INT, 0);
}

TextureData::~TextureData()
{
	
}
