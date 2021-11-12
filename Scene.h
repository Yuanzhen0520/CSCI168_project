#ifndef _SCENE_H_
#define _SCENE_H_

#include "light.h"
#include "Sphere.h"
#include "plane.h"
#include "camera.h"

class Scene {
  public:
    Scene (Light l, Sphere s, Camera c,Plane p):
    l{l}, s{s}, c{c}, p{p} {}
    
    void fileReaderSecondTry(const char *filename);
  private:
    Light l;
    Sphere s;
    Camera c;
    Plane p;
};

#endif
