
#version 330 core
layout (location = 0) in vec3 positionLayout;
layout (location = 1) in vec3 normalLayout;

out vec3 Normal;
out vec3 FragPos;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
    // TODO: Your code here
    // Remember to set gl_Position (correctly) or you will get a black screen...
//SOURCE: https://learnopengl.com/Lighting/Basic-lighting, textbook (Computer Graphics Practices and Principles, Hughes, p.253)

//transform model vector to world space by multiplying

//gets the square to appear, but needs 3D

//to get position for shader, multiply all variables with positionLayout to get proper coordinates 

gl_Position = projection * view * model * vec4(positionLayout, 1.0);

//gl_Position = vec4(positionLayout, 1.0f);

FragPos = vec3(model * vec4(positionLayout, 1.0f));

//normal transform is inverse transpose of a matrix
//inverse and transpose of orthogonal matrix cancels, so it's just model

//Normal = mat3(inverse(transpose(model)))*normalLayout;



Normal = mat3(model)*normalLayout;

} 
//./script.sh