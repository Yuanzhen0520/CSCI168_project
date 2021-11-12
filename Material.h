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


/* 
struct Material{
bool has_texture; 

//global material color 
//vec4 kA
//vec4 kD
//vec4 kS
//float shineness

*/
#endif
