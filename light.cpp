#include "light.h"

glm:vec3 Light::multipleLights(Light _l, Material_m, glm::vec3 _p, glm::vec3_n, glm::vec3 _cEye){
  glm::vec3 _d = normalize(_l.position - _p);

  //ambient light
  glm::vec3 lA;
  lA = _m.kA * iA;
    
    //Lambertian Shading 
  glm::vec3 lD; 
  lD = _m.kD * iD * std::max(0,glm::dot(_n,_d));
  
  //Blinn-Phong Shading 
  glm::vec3 lS;
  glm::vec3 h = glm::normalize((c.Eye -_p)+ _d);
  lS = _m.kS * iS * pow(std::max(0,glm::dot(_cEye,h)),_m.shininess);
  
  return lA + lD + lS;
  }
