#include "Sphere.h"

Collision Sphere::collide(const Ray& _ray) const {
  
  int A,B,C,discriminant,temp1,temp2,t1,t2,firstCollisionT;
  glm::vec3 collisionPoint,collisionNormal;
  Material* pointMaterial;
  // vec3s:  _o _d _c
  // floats: _r  
  A = _d[0]^2+_d[1]^2+_d[2]^2;
  temp1 = _o.subtract(_c); // don't know for sure if this works yet, could also do: temp1[0] = _o[0]-_c[0]
  B = _d[0]*temp1[0]+_d[1]*temp1[1]+_d[2]*temp1[2];
  temp2 = temp1[0]^2+temp1[1]^2+temp1[2]^2;
  C = temp2-_r;
  discriminant = B^2 - 4*A*C;


  if(discriminant < 0){
    // no collision
    return Collision();
  }
  else {
    // collision
    t1 = (-B - sqrt(B^2-4*A*C))/(2*A);
    t2 = (-B + sqrt(B^2-4*A*C))/(2*A);
    if(t1 < t2 && t1 > 0) {
      firstCollisionT = t1;
    }
    else {
      firstCollisionT = t2;
    }

    collisionPoint[0] = _o[0] + firstCollisionT*_d[0];
    collisionPoint[1] = _o[1] + firstCollisionT*_d[1];
    collisionPoint[2] = _o[2] + firstCollisionT*_d[2];

    collisionNormal = (collisionPoint - _c)/_r;
    /*collisionNormal[0] = (collisionPoint[0] - _c[0])/_r;
    collisionNormal[1] = (collisionPoint[1] - _c[1])/_r;
    collisionNormal[2] = (collisionPoint[2] - _c[2])/_r;*/

    return Collision(collisionPoint,collisionNormal,pointMaterial);
    
    
    /*
    
    Collision Sphere::collide(const Ray& _ray) const {
  glm::vec3 o = _ray.m_origin;
  glm::vec3 d = _ray.m_direction;
  glm::vec3 oc = o - m_center;
  const double a = 2 * glm::dot(oc,d);
  const double b = glm::dot(oc,oc) - m_radius*m_radius;
  double d = a*a - 4 * b;
  if (disc < 0) return Collision();
  d = sqrt(d);
  const double t0 = -b - disc;
  const double t1 = -b + disc;
  const double t = (t0 < t1) ? t0 : t1;
  glm::vec3 pointOfCollision = o + d*t;
  glm::vec3 normalAtCollision = glm::normalize(pointOfCollision - m_center);
  return Collision(pointOfCollision, normalAtCollision, m_material);
}

*/
  }
}
