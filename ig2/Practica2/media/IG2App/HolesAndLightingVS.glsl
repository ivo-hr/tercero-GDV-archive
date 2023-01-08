#version 330 core

in vec4 vertex; // datos de la malla
in vec3 normal;
in vec2 uv0;
uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 normalMatrix;
out vec2 vUv0; // coordenadas de textura
out vec3 viewVertex; // coordenadas de la normal
out vec3 viewNormal; // coordenadas del vertice

void main()
{
    // diffuse en view space
    viewVertex = vec3(modelViewMatrix * vertex);
    viewNormal = normalize(vec3(normalMatrix * vec4(normal, 0)));

    vUv0 = uv0; // se pasan las coordenadas de textura
    gl_Position = modelViewProjectionMatrix * vertex; // calculo de la posicion del vertice
}