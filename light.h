#include "GLInclude.h"
#include <math.h>
#include "Material.h"

#ifndef _LIGHT_H
#define _LIGHT_H

class Light{
  public:
    Light(const glm::vec3& _position):
    position(_position) {}
    glm::vec3 iA = glm::vec3(0.f,0.f,0.f);
    glm::vec3 iD = glm::vec3(0.4f,0.4f,0.4f);
    glm::vec3 iS = glm::vec3(0.3f,0.3f,0.3f);
    glm::vec3 multipleLights(const Material* _m, glm::vec3 _p, glm::vec3 _n, glm::vec3 _cEye);
    glm::vec3 getPosition() { return position; }
    void setPosition(glm::vec3 p) { position = p;}
  
  private:
    glm::vec3 position;
};

#endif
