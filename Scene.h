#ifndef _SCENE_H_
#define _SCENE_H_
#include <vector>

#include "light.h"
#include "Sphere.h"
#include "plane.h"
#include "camera.h"

class Scene {
  public:
    //std::vector<Light> l, std::vector<Sphere> s, Camera c,std::vector<Plane> p    this was inside ()
    Scene ():
    // l{l}, s{s}, c{c}, p{p} {}
    void readScene();
    
    std::vector<Light> getL() { return l; }
    std::vector<Sphere> getS() { return s; }
    Camera getC() { return c; }
    std::vector<Plane> getP() {return p; }
    void fileReaderSecondTry(const char *filename);
    void setL(std::vector<Light> light) { l = light;}
    void setS(std::vector<Sphere> sphere) { s = sphere;}
    void setC(Camera camera) { c = camera;}
    void setP(std::vector<Plane> plane) { p = plane;}
  private:
    std::vector<Light> l;
    std::vector<Sphere> s;
    Camera c;
    std::vector<Plane> p;
};

#endif
