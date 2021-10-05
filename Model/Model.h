
#pragma once
#include "SimpleData.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#include "TextureData.h"
#include "Texture.h"
using namespace glm;
class Model : public std::enable_shared_from_this<Model>
{

private:
	unsigned int transformLoc;
	function<void(shared_ptr<Model>)> initOp;
	function<void(shared_ptr<Model>)> drawOp;

public:
	shared_ptr<Model> self();

	shared_ptr<TextureData> data;
	shared_ptr<Shader> shader;
	shared_ptr<Texture> texture;

	shared_ptr<Texture> makeTexture(string name,int index);
	shared_ptr<Shader> makeShader(string name);
	shared_ptr<TextureData> makeData(string name);


	void initAppendOp(function<void(shared_ptr<Model>)> op);
	void drawAppendOp(function<void(shared_ptr<Model>)>  op);

	vec4 homogeneousPos;//∆Î¥ŒŒª÷√
	mat4 trans;
	vec3 pos;

	void move(vec3 dst);
	void rotate(float rot,vec3 axis);
	void scale(vec3 size);

	virtual void init();
	virtual void draw();
	// constructor reads and builds the shader
	Model();
	// use/activate the shader
	~Model();
};