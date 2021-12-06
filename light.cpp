#include "light.h"
#include <iostream>

glm::vec3 Light::multipleLights(const Material* _m, glm::vec3 _p, glm::vec3 _n, glm::vec3 _cEye){
  glm::vec3 _d = normalize(position - _p);

  //ambient light
  glm::vec3 lA;
  lA = _m->kA * iA;
    
    //Lambertian Shading 
  glm::vec3 lD; 
  float valueToPass,valueToPass2;
  if(glm::dot(_n,_d)>0) {
    valueToPass = glm::dot(_n,_d);
  }
  else {
    valueToPass = 0;
  }
  lD = _m->kD * iD * valueToPass;
  
  //Blinn-Phong Shading 
  glm::vec3 lS;
  glm::vec3 h = glm::normalize((_cEye -_p)+ _d);
  if(glm::dot(-_p,h)>0) {
    valueToPass2 = glm::dot(-_p,h);
  }
  else {
    valueToPass2 = 0;
  }
  lS = _m->kS * iS * powf(valueToPass2,_m->shininess);
  
  return lA + lD + lS ;
  }

glm::vec3 Light::ambientLightReturner(const Material* _m, glm::vec3 _p, glm::vec3 _n, glm::vec3 _cEye) {
  glm::vec3 _d = normalize(position - _p);

  glm::vec3 lA;
  lA = _m->kA * glm::vec3(0.3f,0.3f,0.3f);
  return lA;
}

glm::vec3 Light::diffuseLightReturner(const Material* _m, glm::vec3 _p, glm::vec3 _n, glm::vec3 _cEye) {
  glm::vec3 _d = normalize(position - _p);
  glm::vec3 lD; 
  float valueToPass;
  if(glm::dot(_n,_d)>0) {
    valueToPass = glm::dot(_n,_d);
  }
  else {
    valueToPass = 0;
  }
  lD = _m->kD * iD * valueToPass;
  return lD;
}

glm::vec3 Light::specularLightReturner(const Material* _m, glm::vec3 _p, glm::vec3 _n, glm::vec3 _cEye) {
  glm::vec3 _d = normalize(position - _p);
  glm::vec3 lS;
  glm::vec3 h = glm::normalize((_cEye -_p)+ _d);
  float valueToPass2;
  if(glm::dot(-_p,h)>0) {
    valueToPass2 = glm::dot(-_p,h);
  }
  else {
    valueToPass2 = 0;
  }
  lS = _m->kS * iS * powf(valueToPass2,_m->shininess);
  return lS;
}