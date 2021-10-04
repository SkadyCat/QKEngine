#include <BaseWindow.h>
#include <Shader.h>
#include <SimpleData.h>
#include <TextureData.h>
#include <Texture.h>
int main(int argc, char *argv[])
{
	BaseWindow window;

	Shader shader("vertex","fragment");
	SimpleData sd("test");
	SimpleData sd2("test2");
	TextureData sd3("test");
	Texture tt("pp.jpg",500,500);

	window.addElement(make_shared<Texture>(tt));
	window.addElement(make_shared<TextureData>(sd3));
	window.addElement(make_shared<Shader>(shader));
	
	window.run();
	return 0;
}

