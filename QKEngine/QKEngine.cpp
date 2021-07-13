#include <BaseWindow.h>



int main(int argc, char *argv[])
{
	BaseWindow window;
	float*res = new float[3 * 4]{
		  0.5f,  0.5f, 0.0f,  // top right
		  0.5f, -0.5f, 0.0f,  // bottom right
		 -0.5f, -0.5f, 0.0f,  // bottom left
		 -0.5f,  0.5f, 0.0f
	};
	window.addVBO("VBO",3,4,res);
	window.addVAO("VAO", [] {
		//glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//操作状态
	});
	window.compileShader("vertex", "fragment");
	window.run();
	window.shutDown();
	return 0;
}

