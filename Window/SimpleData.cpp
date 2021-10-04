#include "SimpleData.h"
#include "Utils.h"


SimpleData::SimpleData(string vName)
{
	string bufPath = getResourcesFolder() + "SimpleData\\" + vName + ".simple";
	string data;
	try
	{
		std::ifstream bufFile;
		//文件是否异常
		bufFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		bufFile.open(bufPath);
		stringstream readStream;
		//读取数据
		readStream << bufFile.rdbuf();
		data = readStream.str();
	}
	catch (ifstream::failure e) {
		std::cout << "ERROR::SIMPLEDATA::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}
	data = replace_all_distinct(data, "\n", "");
	vector<string> ans = split(data, ",");
	const int len = ans.size();
	this->data = new float[ans.size()];
	//vector<float> arr(ans.size());
	for (int i = 0; i < ans.size();i++) {
		this->data[i] = atof(trim(ans[i]).c_str());
	}
	size = ans.size();
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size * 4, this->data, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);


}

void SimpleData::use()
{
	glBindVertexArray(VAO);
}

SimpleData::~SimpleData()
{
	delete[] data;
	cout << "remove the data from the op space";
}
