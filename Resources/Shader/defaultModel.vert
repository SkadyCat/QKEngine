#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec4 vertexColor; // specify a color output to the fragment shader
out vec2 texCoord;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{

    gl_Position = projection*view*model * vec4(aPos, 1.0);
    vertexColor = vec4(aColor, 1.0); // set the output variable to a dark-red color
    texCoord = aTexCoord;
}
