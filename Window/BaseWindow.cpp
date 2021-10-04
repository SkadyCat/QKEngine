#include "BaseWindow.h"



void BaseWindow::addBuffer(string name, BufferType type)
{
	//this->buffers[name] = 0;
	//if (type == VAO) {
	//	glGenVertexArrays(1, &(this->buffers[name]));
	//}
	//if (type == VBO) {
	//	glGenBuffers(1, &(this->buffers[name]));
	//}
	//if (type == EBO) {
	//	glGenBuffers(1, &(this->buffers[name]));
	//}
}


void BaseWindow::addVAO(string name, function<void()> callBack)
{
	//this->buffers[name] = 0;
	//glGenVertexArrays(1, &(this->buffers[name]));
	//glBindVertexArray(buffers[name]);//Ñ¡Ôñ×´Ì¬
    //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//²Ù×÷×´Ì¬
	//callBack();
	//glEnableVertexAttribArray(0);//Ê¹ÓÃ×´Ì¬
}

void BaseWindow::addVBO(string name,int width,int nums, float* buffer)
{
	//glGenBuffers(1, &this->buffers[name]);
    //glBindBuffer(GL_ARRAY_BUFFER, this->buffers[name]);
    //glBufferData(GL_ARRAY_BUFFER,48, buffer, GL_STATIC_DRAW);
}

void BaseWindow::setDrawEvent(function<void()> connectCallBack)
{
	this->connectCallBack = connectCallBack;
	
}

BaseWindow::BaseWindow()
{
	init();
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}
int BaseWindow::init(){
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

void BaseWindow::run(){
	//this->connectCallBack();
    while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		clock_t now =  clock();
		draw();
		lastTimes = now;
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void BaseWindow::draw(){
	//glUseProgram(shaderProgram);
	////glBindVertexArray(buffers["VAO"]);
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void BaseWindow::shutDown(){
    glfwTerminate();
	glDeleteProgram(shaderProgram);
}

void BaseWindow::compileShader(string vertexShaderFile, string fragmentShaderFile)
{
	//string a1 = res.getShader(vertexShaderFile);
	//string a2 = res.getShader(fragmentShaderFile);
	//
	//cout << a2 << endl;
	//const char* vertexShaderSource = a1.c_str();
	//const char* fragmentShaderSource = a2.c_str();
	//unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	//glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	//glCompileShader(vertexShader);
	//// check for shader compile errors
	//int success;
	//char infoLog[512];
	//glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	//if (!success)
	//{
	//	glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
	//	std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	//}
	//// fragment shader
	//unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//glCompileShader(fragmentShader);
	//// check for shader compile errors
	//glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	//if (!success)
	//{
	//	glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
	//	std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	//}
	//// link shaders
	//shaderProgram = glCreateProgram();
	//glAttachShader(shaderProgram, vertexShader);
	//glAttachShader(shaderProgram, fragmentShader);
	//glLinkProgram(shaderProgram);
	//// check for linking errors
	//glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	//if (!success) {
	//	glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
	//	std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	//}
	//glDeleteShader(vertexShader);
	//glDeleteShader(fragmentShader);
}

BaseWindow::~BaseWindow(){


}