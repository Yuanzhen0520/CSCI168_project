#include "GLInclude.h"
#include "Object.h"

#ifndef _PLANE_H_
#define _PLANE_H_


class Plane : public Object {
    public: 
        Plane(const glm::vec3& p, const glm::vec3& n, const Material* m):
        pointP{p}, normal{n}, m_material{m} {}
        glm::vec3 getN() { return normal; }
        glm::vec3 getP() { return pointP; }
        const Material* getMaterial() const { return m_material;}
        /*void setNormal(glm::vec3 norm) { normal = norm;}
        void setPoint(glm::vec3 p) { pointP = p;}*/

        Collision collide(const Ray& _ray) const override;
        // { return Collision(); }     this was at end of previous line

    private:
        glm::vec3 normal;
        glm::vec3 pointP;
        const Material* m_material;

};
#endif