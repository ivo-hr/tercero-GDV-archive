#version 330 core

in vec4 vertex; // atributos de los vertices a procesar
in vec3 normal;
in vec2 uv0; // coordenadas de textura 0
uniform mat4 modelViewProjectionMatrix;
uniform mat4 modelViewMatrix;
uniform mat4 normalMatrix;
uniform vec3 lightDiffuse;
uniform vec4 lightPosition;
uniform vec3 frontMaterialDiffuse;
uniform vec3 backMaterialDiffuse;
out vec2 vUv0; // coordenadas de textura
out vec3 vFrontColor; // color rgb de la iluminacion de la cara front (normal)
out vec3 vBackColor; // color rgb de la iluminacion de la cara back (-normal)

float diff(vec3 cVertex, vec3 cNormal)
{
    vec3 lightDir = lightPosition.xyz; // directional light?
    if(lightPosition.w == 1) lightDir = lightPosition.xyz - cVertex; // positional light?

    return max(dot(cNormal, normalize(lightDir)), 0.0); // dot : coseno angulo
}

void main()
{
    // diffuse en view space
    vec3 viewVertex = vec3(modelViewMatrix * vertex);
    vec3 viewNormal = normalize(vec3(normalMatrix * vec4(normal, 0)));

    vec3 diffuse = diff(viewVertex, viewNormal) * lightDiffuse * frontMaterialDiffuse;
    vFrontColor = diffuse; // + specular

    diffuse = diff(viewVertex, -viewNormal) * lightDiffuse * backMaterialDiffuse;
    vBackColor = diffuse; // + specular

    vUv0 = uv0; // se pasan las coordenadas de textura
    gl_Position = modelViewProjectionMatrix * vertex; // calculo de la posicion del vertice
}