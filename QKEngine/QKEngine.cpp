#include <BaseWindow.h>
#include <Shader.h>
#include <SimpleData.h>
#include <TextureData.h>
#include <Texture.h>
#include <Model.h>
int main(int argc, char *argv[])
{
	BaseWindow window;
	
	shared_ptr<Model> md = make_shared<Model>();
	md->texture = md->makeTexture("p2.jpg",0);
	md->data = md->makeData("test");
	static float y = 0;

	md->drawAppendOp([](shared_ptr<Model> md) {
		//md->move(vec3(0.01f, 0.01, 0));
		//md->rotate(1,vec3(0,0,1));
		md->scale(vec3(1, 0.99, 1));
	});

	window.addModel(md);
	window.run();
	return 0;
}

