#include "light.h"

glm:vec3 Light::multipleLights(Material_m, glm::vec3_p,glm::vec3_n,glm:::vec3_d,glm.vec3_cEye){
  //ambient light
  
  glm::vec3IA;
  IA = _m.kA * iA
    
    //Lambertian Shading 
  glm:vec3 ID; 
  ID = _m.kD * iD * std::max(0,glm::dot(_n,_d));
  
  //Blinn-Phong Shading 
  glm::vec3 IS
  glm:: vec3 h; 
  h = glm::normalize(c.Eye -_p)+ _d);
  IS = _m.kS * iS * pow(std::max(0,glm::dot(_cEye,h)),_m.shininess);
  
  return IA + ID + IS
  }
