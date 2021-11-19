#ifndef _MATERIAL_H_
#define _MATERIAL_H_

////////////////////////////////////////////////////////////////////////////////
/// @brief Material
////////////////////////////////////////////////////////////////////////////////
struct Material {
    glm::ve4 ambient;
    glm::vec4 diffuse;
    glm::vec4 specular;
    float shininess;
};

Material() : 
    ambient(0.0f ,0.2f ,0.2f ,0.3f)
    diffuse( 0.0f ,0.2f ,0.2f ,0.3f)
    specular( 0.0f, 0.0f, 0.0f, 1.0f)
    shininess(1.0f)
    {}

struct Intensity{
  glm::vec4 iA;
  glm::vec4 iD;
  glm::vec4 iS;
};

Intensity():
 Ia(0.1f, 0.1f, 0.1f)
 Id(0.8f, 0.8f, 0.8f)
 Is(0.8f, 0.8f, 0.8f)
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
