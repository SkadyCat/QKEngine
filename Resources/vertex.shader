#version 330 core
layout (location = 0) in vec3 aPos;
out vec4 vertexColor;
void main()
{
    gl_Position = vec4(aPos.x, aPos.y,0.0,1.0);
    vertexColor = vec4(0.4,0.6,0.3,1.0);
}

