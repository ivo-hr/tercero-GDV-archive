#version 330 core

uniform sampler2D texturaC;
uniform sampler2D texFront; // tipo sampler2D para texturas 2D
uniform sampler2D texBack; // -> unidades de textura (int)
uniform float Flipping; // orden de los vertices invertido
uniform vec3 lightDiffuse;
uniform vec4 lightPosition;
uniform vec3 frontMaterialDiffuse;
uniform vec3 backMaterialDiffuse;
in vec2 vUv0; // out del vertex shader
in vec3 viewVertex;
in vec3 viewNormal;
out vec4 fFragColor; // out del fragment shader

float diff(vec3 cVertex, vec3 cNormal)
{
    vec3 lightDir = lightPosition.xyz; // directional light?
    if(lightPosition.w == 1) lightDir = lightPosition.xyz - cVertex; // positional light?

    return max(dot(cNormal, normalize(lightDir)), 0.0); // dot : coseno angulo
}

void main()
{
    vec3 diffuse = diff(viewVertex, viewNormal) * lightDiffuse * frontMaterialDiffuse;
    vec3 vFrontColor = diffuse; // + specular

    diffuse = diff(viewVertex, -viewNormal) * lightDiffuse * backMaterialDiffuse;
    vec3 vBackColor = diffuse; // + specular

    vec3 colorC = vec3(texture(texturaC, vUv0)); // coordenadas de textura
    if(colorC.x > 0.6) discard;
    vec3 colorF = vec3(texture(texFront, vUv0)); // acceso al texel
    vec3 colorB = vec3(texture(texBack, vUv0)); // configuracion

    bool frontFacing = (Flipping > -1)? gl_FrontFacing : !gl_FrontFacing;

    vec3 color;
    if(frontFacing) color = colorF * vFrontColor;
    else color = colorB * vBackColor;

    fFragColor = vec4(color, 1.0); // out
}