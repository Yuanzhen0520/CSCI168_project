#include "plane.h"
#include "Ray.h"

Collision Plane::collide(const Ray& _ray) const{
    float t,temp2,temp3;
    glm::vec3 temp1,collisionPoint,collisionNormal;
    const Material* planeMaterial;
    //vec3s _o _d _n _a
    // _o is ray origin
    // _d is ray direction
    // _n is plane normal
    // _a is plane point
    glm::vec3 _o = _ray.getO();
    glm::vec3 _d = _ray.getD();
    glm::vec3 _n = normal;
    glm::vec3 _a = pointP;
   
    // subtraction
    temp1 = _a - _o;

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