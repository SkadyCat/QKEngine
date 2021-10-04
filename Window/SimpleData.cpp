#include "SimpleData.h"
#include "Utils.h"


SimpleData::SimpleData()
{
}

SimpleData::SimpleData(string vName)
{
	string bufPath = getResourcesFolder() + "SimpleData\\" + vName + ".dsimple";
	readFromPath(bufPath);
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size * 4, this->data, GL_STATIC_DRAW);
	//指定位置属性
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	//指定颜色属性
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

float * SimpleData::readFromPath(string fName)
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
	for (auto line : lines) {
		data = data + split(line, "#")[0];
	}
	
	vector<string> ans = split(data, ",");
	const int len = ans.size();
	this->data = new float[ans.size()];
	//vector<float> arr(ans.size());
	for (int i = 0; i < ans.size(); i++) {
		this->data[i] = atof(trim(ans[i]).c_str());
	}
	size = ans.size();

	return this->data;
}

void SimpleData::use()
{
	glBindVertexArray(VAO);
}



SimpleData::~SimpleData()
{
	//delete[] data;

	
}
