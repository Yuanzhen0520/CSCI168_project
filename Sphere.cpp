#include "Sphere.h"

Collision Sphere::collide(const Ray& _ray) const {
  glm::vec3 o = _ray.m_origin;
  glm::vec3 d = _ray.m_direction;
  glm::vec3 oc = o - m_center;
  const double a = 2 * glm::dot(oc,d);
  const double b = glm::dot(oc,oc) - m_radius*m_radius;
  double disc = a*a - 4 * b;
  if (disc < 0) return Collision();
  disc = sqrt(disc);
  const double t0 = -b - disc;
  const double t1 = -b + disc;
  const double t = (t0 < t1) ? t0 : t1;
  glm::vec3 pointOfCollision = o + d*t;
  glm::vec3 normalAtCollision = glm::normalize(pointOfCollision - m_center);
  return Collision(pointOfCollision, normalAtCollision, m_material);
}
