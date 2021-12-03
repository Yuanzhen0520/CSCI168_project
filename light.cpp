#include "light.h"

glm::vec3 Light::multipleLights(Light _l, Material _m, glm::vec3 _p, glm::vec3 _n, glm::vec3 _cEye){
  glm::vec3 _d = normalize(_l.position - _p);

  //ambient light
  glm::vec3 lA;
  lA = _m.kA * _l.iA;
    
    //Lambertian Shading 
  glm::vec3 lD; 
  int valueToPass,valueToPass2;
  if(glm::dot(_n,_d)>0) {
    valueToPass = glm::dot(_n,_d);
  }
  else {
    valueToPass = 0;
  }
  lD = _m.kD * iD * valueToPass;
  
  //Blinn-Phong Shading 
  glm::vec3 lS;
  glm::vec3 h = glm::normalize((_cEye -_p)+ _d);
  if(glm::dot(_cEye,h)>0) {
    valueToPass = glm::dot(_cEye,h);
  }
  else {
    valueToPass = 0;
  }
  lS = _m.kS * iS * pow(valueToPass,_m.shininess);
  
  return lA + lD + lS;
  }
