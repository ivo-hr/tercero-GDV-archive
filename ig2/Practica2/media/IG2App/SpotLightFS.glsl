#version 330 core

uniform sampler2D textura;
uniform float cutoff;
uniform vec3 lightDiffuse;
uniform vec4 lightPosition;
in vec2 vUv0; // out del vertex shader
in vec3 viewVertex;
in vec3 viewNormal;
out vec4 fFragColor;

float diff(vec3 cVertex, vec3 cNormal)
{
    vec3 lightDir = lightPosition.xyz; // directional light?
    if(lightPosition.w == 1) lightDir = lightPosition.xyz - cVertex; // positional light?

    float AF = 0.2;
    if((dot(cNormal, normalize(lightDir)) > cutoff * 0.5 + 0.5)) AF = 1.0;

    return AF;
}

void main()
{
    vec3 diffuse = diff(viewVertex, viewNormal) * lightDiffuse;

    vec3 color = vec3(texture(textura, vUv0));
    color = color * diffuse;

    fFragColor = vec4(color, 1.0);
}