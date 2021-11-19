#ifndef _MATERIAL_H_
#define _MATERIAL_H_

////////////////////////////////////////////////////////////////////////////////
/// @brief Material
////////////////////////////////////////////////////////////////////////////////
struct Material {
    glm::vec3 ambient;
    glm::vec3 diffuse;
    glm::vec3 specular;
    float shininess;
};

Material() : 
    ambient(0.0f ,0.2f ,0.2f ,0.3f)
    diffuse( 0.0f ,0.2f ,0.2f ,0.3f)
    specular( 0.0f, 0.0f, 0.0f, 1.0f)
    shininess(1.0f)
    {}

/* 
struct Material{
bool has_texture; 

//global material color 
//vec4 kA
//vec4 kD
//vec4 kS
//float shininess

*/
#endif
