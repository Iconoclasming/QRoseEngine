#version 330 core

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;

out vec4 fragColor;
out vec3 fragPosition;
out vec3 fragNormal;

void main()
{
    gl_Position = projection * view * model * vec4(position, 1.0f);

    fragColor = vec4(0.6f, 0.2f, 0.0f, 1.0f);
	fragPosition = position;
	fragNormal = normal;
}