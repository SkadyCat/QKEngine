#include "BaseWindow.h"





void BaseWindow::addModel(shared_ptr<Model> md)
{
	models.push_back(md);
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
	for (auto e : this->models)
	{
		e->init();
	}
	glfwWaitEventsTimeout(0.5f);

    while (!glfwWindowShouldClose(window))
	{
		
		clock_t now =  clock();
		if (now - lastTimes > 50) {
			cout << now - lastTimes << endl;
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
			lastTimes = now;
			for (auto e : this->models)
			{
				e->draw();
			}
			glfwSwapBuffers(window);
			glfwPollEvents();
		}
		
	}
}
void BaseWindow::shutDown(){
    glfwTerminate();
}

//BaseWindow::~BaseWindow(){
//
//
//}