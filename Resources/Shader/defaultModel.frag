
#version 330 core
out vec4 FragColor;
  
in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  
in vec2 texCoord;
uniform sampler2D ourTexture1;
uniform sampler2D ourTexture2;
void main()
{
    FragColor = texture(ourTexture1,texCoord);
}
