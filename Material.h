#ifndef _MATERIAL_H_
#define _MATERIAL_H_

////////////////////////////////////////////////////////////////////////////////
/// @brief Material
////////////////////////////////////////////////////////////////////////////////
struct Material {
    Material(const glm::vec3& kA, const glm::vec3& kD, const glm::vec3& kS, const float& s):
        kA(kA), kD(kD), kS(kS), shininess(s) {}
    glm::vec3 kA;
    glm::vec3 kD;
    glm::vec3 kS;
    float shininess;
};

/*Material(): 
    kA(0.0f ,0.2f ,0.2f ,0.3f)
    kD( 0.0f ,0.2f ,0.2f ,0.3f)
    kS( 0.0f, 0.0f, 0.0f, 1.0f
    shininess(1.0f)
    {}
*/

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
