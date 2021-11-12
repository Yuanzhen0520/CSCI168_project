#include "GLInclude.h"

#indef _light_h
#define _light_h 

class Light{

  pulbic:
  Light() {}; 
  glm::vec3 getPosition() { return position };
  Light(glm::vec3 position) : position(position) {}
  
  private:
  glm::vec3 position;
}
