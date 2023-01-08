#version 330 core

uniform sampler2D texturaC;
uniform sampler2D texFront; // tipo sampler2D para texturas 2D
uniform sampler2D texBack; // -> unidades de textura (int)
uniform float intLuzAmb; // luz ambiente blanca
uniform float Flipping; // orden de los vertices invertido
in vec2 vUv0; // out del vertex shader
out vec4 fFragColor; // out del fragment shader

void main()
{
    vec3 colorC = vec3(texture(texturaC, vUv0)); // coordenadas de textura
    if(colorC.x > 0.6) discard;
    vec3 colorF = vec3(texture(texFront, vUv0)); // acceso al texel
    vec3 colorB = vec3(texture(texBack, vUv0)); // configuracion

    bool frontFacing = (Flipping > -1)? gl_FrontFacing : !gl_FrontFacing;

    vec3 color;
    if(frontFacing) color = colorF * intLuzAmb;
    else color = colorB * intLuzAmb;

    fFragColor = vec4(color, 1.0); // out
}