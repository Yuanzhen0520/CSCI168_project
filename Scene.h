#ifndef _SCENE_H_
#define _SCENE_H_

#include <string>
#include <iostream>
#include <fstream>
#include "Sphere.h"
#include "Camera.h"
#include "Plane.h"
#include "GLInclude.h"

using namespace std;

class Scene {
  public:
    Object() = default;
    virtual ~Object() = default;

    void readScene();

  private:
    Plane _plane;
    Sphere _sphere;
    Camera _camera;
};

#endif
