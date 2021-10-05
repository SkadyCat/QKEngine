#include "Texture.h"
#include "Utils.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


Texture::Texture(string vName, int index)
{	
	this->index = index;
	string bufName = getResourcesFolder() + "Texture\\" + vName;

	glGenTextures(1, &ID);
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int w, h, nrChannels;
	unsigned char *data = stbi_load(bufName.c_str(), &w, &h, &nrChannels, 0);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	if (data)
	{
		if (contains(vName, "jpg")) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

		}
		if (contains(vName, "png")) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

		}

		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
	stbi_image_free(data);
}

void Texture::use() {
	glActiveTexture(GL_TEXTURE0 + index);
	glBindTexture(GL_TEXTURE_2D, ID);
}
Texture::~Texture()
{
}
