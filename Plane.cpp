#include "plane.h"
#include "Ray.h"

Collision Plane::collide(const Ray& _ray) const{
    float t,temp2,temp3;
    glm::vec3 temp1,collisionPoint;
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
    temp2 = glm::dot(temp1,_n);
    temp3 = glm::dot(_d,_n);
    t = temp2/temp3;
    if(temp3 != 0 && t>0) {
        // collision
        collisionPoint = _ray.at(t);
        return Collision(collisionPoint,normal,m_material);
    }
    else {
        // no collision
        return Collision();
    }
}