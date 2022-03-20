
#version 330 core
out vec4 color;


//looks cleaner
in vec3 FragPos, Normal;  
  
uniform vec3 lightPos, viewPos, lightColor, objectColor;

void main()
{
    // TODO: Replace with your code...

//CODE BELOW SOURCED FROM: https://learnopengl.com/Lighting/Basic-Lighting

//create ambient vector
  vec3 ambient = 0.1f * lightColor;

  vec3 norm  = normalize(Normal);

//get vector of the direction of light by getting different between lightPos and fragPos
  vec3 lightDir = normalize(lightPos - FragPos);

  //diffuse vector is maximum dot product of that difference
  vec3 diffuse = (max(dot(norm, lightDir), 0.0f)) * lightColor;

  float specStrength = 0.5f;

  vec3 viewDir = normalize(viewPos - FragPos);

//get inverse of direction of life to calculate reflection
  vec3 reflectDir = reflect(-lightDir, norm);

float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);

vec3 specular = specStrength * spec * lightColor;

//add all the different types together to get the resulting shade
vec3 result = (ambient + diffuse + specular) * objectColor;

    // If gl_Position was set correctly, this gives a totally red cube
    color = vec4(result, 1.0f);
} 
