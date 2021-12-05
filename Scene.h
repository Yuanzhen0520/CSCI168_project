#ifndef _SCENE_H_
#define _SCENE_H_
#include <vector>

#include "light.h"
#include "Sphere.h"
#include "plane.h"
#include "camera.h"

class Scene {
  public:
    Scene (const std::vector<Light>& _l, const std::vector<Sphere>& _s, const Camera& _c,const std::vector<Plane>& _p):
    l{_l}, s{_s}, c{_c}, p{_p} {}
    Scene () {}
    void readScene ();
    
    const std::vector<Light>& getL() const { return l; }
    const std::vector<Sphere>& getS() const { return s; }
    const Camera& getC() const { return c; }
    const std::vector<Plane>& getP() const {return p; }
  //int numberofSpheres; 
  //int numberofLights; 
  //int numberofPlanes; 
  private:
    std::vector<Light> l;
    std::vector<Sphere> s;
    Camera c;
    std::vector<Plane> p;
};

#endif
