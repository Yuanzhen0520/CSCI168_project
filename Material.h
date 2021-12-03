#ifndef _MATERIAL_H_
#define _MATERIAL_H_

////////////////////////////////////////////////////////////////////////////////
/// @brief Material
////////////////////////////////////////////////////////////////////////////////
struct Material {
    glm::vec4 kA;
    glm::vec4 kD;
    glm::vec4 kS;
    float shininess;
};

/*Material(): 
    kA(0.0f ,0.2f ,0.2f ,0.3f)
    kD( 0.0f ,0.2f ,0.2f ,0.3f)
    kS( 0.0f, 0.0f, 0.0f, 1.0f)
    shininess(1.0f)
    {}
*/
struct Intensity{
  glm::vec3 iA;
  glm::vec3 iD;
  glm::vec3 iS;
};

/*
Intensity():
 iA(0.1f, 0.1f, 0.1f)
 iD(0.8f, 0.8f, 0.8f)
 iS(0.8f, 0.8f, 0.8f)
 {}*/
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
