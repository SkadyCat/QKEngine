#include <BaseWindow.h>
#include <Shader.h>
#include <SimpleData.h>

int main(int argc, char *argv[])
{
	BaseWindow window;

	Shader shader("vertex","fragment");
	SimpleData sd("test");
	SimpleData sd2("test2");

	sd2.use();
	shader.use();
	window.run();
	
	return 0;
}

