#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <time.h>
#include <iostream>
//#include <Res.h>
#include <vector>
#include<functional>
#include<Element.h>
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
	vector<shared_ptr<Element>> items;
public:
	void addElement(shared_ptr<Element> element);
	void setDrawEvent(function<void()> connectCallBack);
    BaseWindow(/* args */);
    //~BaseWindow();
    void run();
    void shutDown();
};
