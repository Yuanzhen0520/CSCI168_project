#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "GLInclude.h"


class Camera {
public:
    Camera(glm::vec3& eye, glm::vec3&  at, glm::vec3&  up) {} //constructor
    ~Camera() {} //destructor
    
    glm::vec3 getEye(){return eye;}
    glm::vec3 getAt(){return at;}
    glm::vec3 getUp(){return up;}
    
private:
    glm::vec3 eye;
    glm::vec3 at;
    glm::vec3 up;
    glm::vec3 right;
};

#endif
