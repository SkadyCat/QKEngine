#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <time.h>
#include <iostream>
//#include <Res.h>

#include<functional>
using namespace std;

enum BufferType
{
	VAO,
	VBO,
	EBO
};
class BaseWindow
{
private:
	
    /* data */
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;
    clock_t lastTimes;
    GLFWwindow* window;
	function<void()> connectCallBack;
	//Resources res;
	unsigned int shaderProgram;
	int resIndex;
	
public:
	//unordered_map<int, vector<float>> data;
	//unordered_map<string, GLuint> buffers;

	void addBuffer(string name, BufferType type);
	void addVAO(string name, function<void()> callBack);
	void addVBO(string name, int width, int nums, float* buffer);


	void setDrawEvent(function<void()> connectCallBack);
    BaseWindow(/* args */);
    virtual ~BaseWindow();
    int init();
    void run();
    virtual void draw();
    void shutDown();
	void compileShader(string vertexShader, string fragmentShader);
};
