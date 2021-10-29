#version 450 core

layout (location = 0) in vec3 vertexPosition;
layout (location = 1) in vec3 vertexColor;

uniform mat4 MVP;

out vec3 fragColor;

void main ()
{
    vec4 v = vec4(vertexPosition, 1);

    fragColor = vertexColor;

    gl_Position = MVP * v;
}