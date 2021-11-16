#ifndef _SPHERE_H_
#define _SPHERE_H_

// GL
#include "GLInclude.h"

// Engine
#include "Collision.h"
#include "Material.h"
#include "Object.h"

////////////////////////////////////////////////////////////////////////////////
/// @brief Sphere
////////////////////////////////////////////////////////////////////////////////
/*class Sphere : public Object {
  public:
    Sphere(const glm::vec3 _c,
           float _r) :
      m_center{_c}, m_radius{_r} {}

    Collision collide(const Ray& _ray) const override;
    
  private:
    glm::vec3  m_center; ///< Center
    float      m_radius; ///< Radius
    Material m_material; ///< Material
};*/

class Sphere{
  public:
    float getRadius() { return radius; }
    glm::vec3 getCenter() { return center; }
    void setRadius(float r) { radius = r; }
    void setCenter(glm::vec3 c) { center = c; }
  private:
    float radius;
    glm::vec3 center;
};
#endif
