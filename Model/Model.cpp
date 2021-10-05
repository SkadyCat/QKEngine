#include "Model.h"
void Model::move(vec3 dst)
{
	trans = translate(trans, dst);
	homogeneousPos = trans * homogeneousPos;
	pos.x = homogeneousPos.x;
	pos.y = homogeneousPos.y;
	pos.z = homogeneousPos.z;
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, value_ptr(trans));
}

void Model::rotate(float rot, vec3 axis)
{
	
	trans = glm::rotate(trans, radians(rot),axis);
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, value_ptr(trans));

}

void Model::scale(vec3 size)
{
	trans = glm::scale(trans, size);
	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, value_ptr(trans));
}

shared_ptr<Model> Model::self()
{
	shared_ptr<Model> self_ptr = shared_from_this();
	return self_ptr;
}

shared_ptr<Texture> Model::makeTexture(string name,int index)
{
	Texture a(name,index);
	return make_shared<Texture>(a);
}
shared_ptr<Shader> Model::makeShader(string name)
{
	Shader a(name);
	return make_shared<Shader>(a);
}
shared_ptr<TextureData> Model::makeData(string name)
{
	TextureData a(name);
	return make_shared<TextureData>(a);
}

void Model::initAppendOp(function<void(shared_ptr<Model>)> op)
{
	this->initOp = op;
}

void Model::drawAppendOp(function<void(shared_ptr<Model>)> op)
{
	this->drawOp = op;
}


void Model::init()
{

	transformLoc = glGetUniformLocation(shader->ID, "transform");
	shader->use();
	texture->use();
	
	
	if (initOp != nullptr) {
		initOp(self());
	}
}

void Model::draw()
{
	data->use();
	if (drawOp != nullptr) {
		drawOp(self());
	}
}

Model::Model()
{
	trans = mat4(1.0f);
	shader = makeShader("defaultModel");
	initOp = nullptr;
	drawOp = nullptr;
}

Model::~Model()
{

}
