#include "Sphere.h"
#include <iostream>
#include "Ray.h"

Collision Sphere::collide(const Ray& _ray) const {
  glm::vec3 collisionPoint,collisionNormal,temp1;
  Material* pointMaterial;
  float firstCollisionT,A,B,C,discriminant,temp2,t1,t2;
   
  glm::vec3 _o = _ray.getO();
  glm::vec3 _d = _ray.getD();

  glm::vec3 _c = center;
  float _r = radius;

  // vec3s:  _o _d _c
  // floats: _r  
  A = glm::dot(_d,_d);
  temp1 = _o - _c;
  B = glm::dot(_d,temp1);
  temp2 = glm::dot(temp1,temp1);
  C = temp2-_r;
  discriminant = (powf(B,2)) - (4*A*C);


  if(discriminant < 0){
    // no collision
    return Collision();
  }
  else {
    // collision
    t1 = (-B - sqrt(powf(B,2.0)-4*A*C))/(2*A);
    t2 = (-B + sqrt(powf(B,2.0)-4*A*C))/(2*A);
    if(t1 < t2 && t1 > 0) {
      firstCollisionT = t1;
    }
    else {
      firstCollisionT = t2;
    }
    collisionPoint = _ray.at(firstCollisionT);

    collisionNormal = (collisionPoint - _c)/_r;

    return Collision(collisionPoint,collisionNormal,pointMaterial);
  }
}
