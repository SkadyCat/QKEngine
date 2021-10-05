#include "Model.h"
void Model::move(vec3 dst)
{
	model = translate(model, dst);
	homogeneousPos = trans * homogeneousPos;
	pos.x = homogeneousPos.x;
	pos.y = homogeneousPos.y;
	pos.z = homogeneousPos.z;
	glUniformMatrix4fv(modelTransform, 1, GL_FALSE, value_ptr(model));
}

void Model::rotate(float rot, vec3 axis)
{
	
	model = glm::rotate(model, radians(rot),axis);
	glUniformMatrix4fv(modelTransform, 1, GL_FALSE, value_ptr(model));

}

void Model::scale(vec3 size)
{
	model = glm::scale(model, size);
	glUniformMatrix4fv(modelTransform, 1, GL_FALSE, value_ptr(model));
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


	shader->use();
	texture->use();
	
	modelTransform = glGetUniformLocation(shader->ID, "model");
	viewTransform = glGetUniformLocation(shader->ID, "view");
	projectionTransform = glGetUniformLocation(shader->ID, "projection");
	
	model = mat4(1.0f);
	//指定模型变换 初始位置
	model = glm::translate(model, vec3(0, 0, 0));
	glUniformMatrix4fv(modelTransform, 1, GL_FALSE, value_ptr(model));

	//指定view 变换 矩阵
	view = glm::mat4(1.0f);
	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	glUniformMatrix4fv(viewTransform, 1, GL_FALSE, value_ptr(view));

	//指定投影矩阵
	projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
	glUniformMatrix4fv(projectionTransform, 1, GL_FALSE, value_ptr(projection));



	
	move(vec3(0, 0, 0));
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
