#include "GLInclude.h"

#ifndef _LIGHT_H
#define _LIGHT_H

class Light{
  public:
    glm::vec3 kA;
    glm::vec3 kD;
    glm::vec3 kS;
    glm::vec3 direciton;
    Light() {};
    glm::vec3 getPosition() { return position; }
    Light(glm::vec3 position) : position(position) {}
    void setPosition(glm::vec3 p) { position = p;}

  private:
    glm::vec3 position;
};

#endif
