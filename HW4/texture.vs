
#version 330 core
layout (location = 0) in vec3 position;
layout(location = 1) in vec2 vertexUV;

// Output data ; will be interpolated for each fragment.
out vec2 UV;


uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
//Reference: http://www.opengl-tutorial.org/beginners-tutorials/tutorial-5-a-textured-cube/
void main()
{
    // TODO: Your code here
    // Remember to set gl_Position (correctly) or you will get a black screen...

gl_Position = projection * view * model * vec4(position, 1.0f);

UV = -vertexUV;
}
 
//./script.sh
