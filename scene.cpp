#include "Scene.h"
#include "fileReader2.h"

Scene Scene::readScene()
{
    std::vector<Sphere> sphereVector;
    std::vector<Plane> planeVector;
    std::vector<Light> lightVector;
    fileReaderSecondTry("sampleFile.txt");
    for(int i = 0;i < numberOfSpheres;i++) {
        // create sphere object
        float rad = spheres[i][0];
        glm::vec3 cent(spheres[i][1],spheres[i][2],spheres[i][3]);
        Sphere sphere(rad,cents);
        sphereVector.push_back(sphere);
    }
    for(int j = 0;j < numberOfPlanes;j++) {
        // create plane object
        glm::vec3 p = planePoints[j];
        glm::vec3 n = planeNormals[j];
        Plane plane(p,n);
        planeVector.push_back(plane);
    }
    for(int k = 0;k < numberOfLights;k++) {
        glm::vec3 l(lights[k][0],lights[k][1],lights[k][2]);
        Light light(l);
        lightVector.push_back(light);
    }
    /*glm::vec3 eye (0,0,0);
    glm::vec3 at (0,0,-1);
    glm::vec3 up (0,1,0);*/
    Camera camera;
    Scene scene(lightVector,sphereVector,camera,planeVector);
    return scene;
}
