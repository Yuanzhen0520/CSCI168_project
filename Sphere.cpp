#include "Sphere.h"
#include "Ray.h"

Collision Sphere::collide(const Ray& _ray) const {
  
  int A,B,C,discriminant,temp2,t1,t2;
  glm::vec3 collisionPoint,collisionNormal,temp1;
  Material* pointMaterial;
  float firstCollisionT;
   
  glm::vec3 _o = _ray.getO();
  glm::vec3 _d = _ray.getD();

  glm::vec3 _c = center;
  float _r = radius;

  // vec3s:  _o _d _c
  // floats: _r  
  A = pow(_d[0],2)+pow(_d[1],2)+pow(_d[2],2);
  temp1 = _o - _c;
  B = _d[0]*temp1[0]+_d[1]*temp1[1]+_d[2]*temp1[2];
  temp2 = pow(temp1[0],2)+pow(temp1[1],2)+pow(temp1[2],2);
  C = temp2-_r;
  discriminant = pow(B,2) - 4*A*C;


  if(discriminant < 0){
    // no collision
    return Collision();
  }
  else {
    // collision
    t1 = (-B - sqrt(pow(B,2)-4*A*C))/(2*A);
    t2 = (-B + sqrt(pow(B,2)-4*A*C))/(2*A);
    if(t1 < t2 && t1 > 0) {
      firstCollisionT = float(t1);
    }
    else {
      firstCollisionT = float(t2);
    }
    collisionPoint = _ray.at(firstCollisionT);

    collisionNormal = (collisionPoint - _c)/_r;

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
