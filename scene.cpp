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
        float rad = spheres[i]][0];
        glm::vec3 cent;
        cent[0] = spheres[i][1];
        cent[1] = spheres[i][2];
        cent[2] = spheres[i][3];
        Sphere sphere();
        sphere.setRadius(rad);
        sphere.setCenter(cent);
        sphereVector.push_back(sphere);
    }
    for(int j = 0;j < numberOfPlanes;j++) {
        // create plane object
        glm::vec3 p;
        glm::vec3 n;
        p[0] = planePoints[j][0];
        p[1] = planePoints[j][1];
        p[2] = planePoints[j][2];
        n[0] = planeNormals[j][0];
        n[1] = planeNormals[j][1];
        n[2] = planeNormals[j][2];
        Plane plane();
        plane.setPoint(p);
        plane.setNormal(n);
        planeVector.push_back(plane);
    }
    for(int k = 0;k < numberOfLights;k++) {
        glm::vec3 l;
        l[0] = lights[k][0];
        l[1] = lights[k][1];
        l[2] = lights[k][2];
        Light light();
        light.setPosition(l);
        lightVector.push_back(light);
    }
    glm::vec3 eye = (0,0,0);
    glm::vec3 at = (0,0,-1);
    glm::vec3 up = (0,1,0);
    Camera camera(eye,at,up);
    Scene scene(lightVector,sphereVector,camera,planeVector);
    return scene;
    /*scene.setL(lightVector);
    scene.setP(planeVector);
    scene.setS(sphereVector);
    scene.setC(camera);*/
}
