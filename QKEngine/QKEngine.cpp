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
	md->texture = md->makeTexture("p4.png",0);
	md->data = md->makeData("Cube");
	md->initAppendOp([](shared_ptr<Model> md) {
		md->scale(vec3(0.7, 0.7, 0.7));
		md->rotate(60, vec3(0, 1, 0));
	});
	md->drawAppendOp([](shared_ptr<Model> md) {
		//md->move(vec3(0.01f, 0.01, 0));
	});
	window.addModel(md);
	window.run();
	return 0;
}

