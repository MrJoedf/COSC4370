
#version 330 core
out vec4 color;

in vec2 UV;
uniform sampler2D myTextureSampler;

void main()
{
    // TODO: pub with your code...

//Reference: http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/
    //Color should be value of the texture sampler with UV coordinates

color = texture(myTextureSampler, UV);
}
