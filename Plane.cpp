#include "plane.h"
#include "Ray.h"

Collision Plane::collide(const Ray& _ray) const{
    int t,temp2,temp3;
    glm::vec3 temp1,collisionPoint,collisionNormal;
    Material* planeMaterial;
    //vec3s _o _d _n _a
    glm::vec3 _o = glm::vec3(0,0,0);  // test values
    glm::vec3 _d = glm::vec3(3,5,-1); // test values
    glm::vec3 _n = glm::vec3(0,1,0);  // test values
    glm::vec3 _a = glm::vec3(0,-1,0); // test values
    // subtraction
    temp1[0] = _a[0] - _o[0];
    temp1[1] = _a[1] - _o[1];
    temp1[2] = _a[2] - _o[2];

    // dot product
    temp2 = temp1[0]*_n[0] + temp1[1]*_n[1] + temp1[2]*_n[2];
    temp3 = _d[0]*_n[0] + _d[1]*_n[1] + _d[2]*_n[2];
    t = temp2/temp3;
    if(temp3 != 0 && t>0) {
        // collision
        collisionPoint[0] = _o[0] + t*_d[0];
        collisionPoint[1] = _o[1] + t*_d[1];
        collisionPoint[2] = _o[2] + t*_d[2];
        return Collision(collisionPoint,collisionNormal,planeMaterial);
    }
    else {
        // no collision
        return Collision();
    }
}