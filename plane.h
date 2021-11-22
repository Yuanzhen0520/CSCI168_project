#include "GLInclude.h"
#include "Object.h"

#ifndef _PLANE_H_
#define _PLANE_H_


class Plane : public Object {
    public: 
        Plane(const glm::vec3& p, const glm::vec3& n):
        pointP{p}, normal{n} {}
        glm::vec3 getN() { return normal; }
        glm::vec3 getP() { return pointP; }
        /*void setNormal(glm::vec3 norm) { normal = norm;}
        void setPoint(glm::vec3 p) { pointP = p;}*/

        Collision collide(const Ray& _ray) const override { return Collision(); }

    private:
        glm::vec3 normal;
        glm::vec3 pointP;

};
#endif