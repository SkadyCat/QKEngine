#include "BaseWindow.h"







void BaseWindow::addElement(shared_ptr<Element> element)
{
	items.push_back(element);
}

void BaseWindow::setDrawEvent(function<void()> connectCallBack)
{
	this->connectCallBack = connectCallBack;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}
BaseWindow::BaseWindow()
{
	lastTimes = clock();
	window = nullptr;
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}
}
void BaseWindow::run(){
    while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		clock_t now =  clock();
		for (auto e : this->items)
		{
			e->use();
		}
		lastTimes = now;
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
void BaseWindow::shutDown(){
    glfwTerminate();
}

//BaseWindow::~BaseWindow(){
//
//
//}