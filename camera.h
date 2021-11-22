#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "GLInclude.h"


class Camera {
public:
    /*Camera(glm::vec3& _eye, glm::vec3& _facing, glm::vec3& _up, glm::vec3& _right):
    eye{_eye}, facing{_facing}, up{_up}, right{_right} {} //constructor*/
    Camera() {}
    ~Camera() {} //destructor
    
    glm::vec3 getEye(){return eye;}
    glm::vec3 getFacing(){return facing;}
    glm::vec3 getUp(){return up;}
    glm::vec3 getRight(){return right;}
    
private:
    glm::vec3 eye = glm::vec3(0,0,0);
    glm::vec3 facing = glm::vec3(0,0,-1);
    glm::vec3 up = glm::vec3(0,1,0);
    glm::vec3 right = glm::vec3(1,0,0);
};

#endif
