#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <time.h>
#include <iostream>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
clock_t lastTimes;
GLFWwindow* window;
int init() {
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
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
}

void draw() {

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	//添加数据
	float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  ,// top
		 0.5f,0.5f,0.0f
	};
	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	unsigned int VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	//调用几何着色器命令

	glDrawArrays(GL_TRIANGLES, 0, 3);

}
void run() {
	while (!glfwWindowShouldClose(window))
	{
		clock_t now = clock();
		draw();
		cout << "loop gap = " << now - lastTimes << endl;
		lastTimes = now;
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
void shutDown() {
	glfwTerminate();
}
int main()
{
	init();
	run();
	shutDown();
	return 0;
}

