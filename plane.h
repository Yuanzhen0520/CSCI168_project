#ifndef _PLANE_H_
#define _PLANE_H_

#include "GLInclude.h"



class Plane {
    public: 
    glm:vec3 getN() { return normal; }
    glm:vec3 getP() { returen pointP; }
    void setNormal(glm:vec3 norm) { normal = norm;}
    void setPoint(glm:vec3 p) { pointP = p;}

    private:
    glm:vec3 normal;
    glm:vec3 pointP;

}
