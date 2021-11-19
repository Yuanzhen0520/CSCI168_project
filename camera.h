#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "GLInclude.h"


class Camera {
public:
    Camera(glm::vec3& position, glm::vec3&  at, glm::vec3&  up) {} //constructor
    ~Camera() {} //destructor
    
    glm::vec3 position(){return position;}
    glm::vec3 at(){return at;}
    glm::vec3 up(){return up;}
    glm::vec3 eye(){return eye;}
    
private:
    glm::vec3  position;
    glm::vec3  at;
    glm::vec3  up;
    glm::vec3  eye;
};

#endif
