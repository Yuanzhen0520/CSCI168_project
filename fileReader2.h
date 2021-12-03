#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Scene.h"
#include <iostream>
using namespace std;

std::vector<glm::vec4> spheres;
std::vector<glm::vec3> planePoints;
std::vector<glm::vec3> planeNormals;
std::vector<glm::vec3> lights;
int numberOfSpheres,numberOfPlanes,numberOfLights,numberOfCameras;

void fileReaderSecondTry(const char *filename) {
    // need to take material as input too, says i can use .mtl file as secondary file
    std::ifstream sceneFile (filename);
    int v1,v2,v3,v4,v5,v6,v7;
    //int numberOfSpheres,numberOfPlanes,numberOfLights,numberOfCameras;
    while (sceneFile >> v1 >> v2 >> v3 >> v4 >> v5 >> v6 >> v7) {
        if(v1 == 0) {     // spheres begin with 0. Start reading at 4th value
            glm::vec4 curSphere = glm::vec4(v4,v5,v6,v7);
            spheres.push_back(curSphere);
        }
        if(v1 == 1) {    // planes begin with 1. Start reading at 2nd value
            glm::vec3 curPlanePoint = glm::vec3(v2,v3,v4);
            glm::vec3 curPlaneNormal = glm::vec3(v5,v6,v7);
            planePoints.push_back(curPlanePoint);
            planeNormals.push_back(curPlaneNormal);
        }
        if(v1 == 2) {    // lights begin with 2. Start reading at 2nd value
            glm::vec3 light = glm::vec3(v5,v6,v7);
            lights.push_back(light);
        }
    }
    numberOfSpheres = spheres.size() - 1;
    numberOfPlanes = planePoints.size() - 1;
    numberOfLights = lights.size() - 1;
    numberOfCameras = 1;

    cout << "Number of spheres: " << numberOfSpheres << endl;
    cout << "Number of planes: " << numberOfPlanes << endl;
    cout << "Number of lights: " << numberOfLights << endl;
    /*
    std::cout << "Sphere Number " << sphereNumber[3] << "  y= " << spheres[3][2] << std::endl;
    std::cout << "Plane Number " << planeNumber[2] << " py= " << planePoints[2][1] << std::endl;
    std::cout << "Sphere Number " << sphereNumber[9] << "  " << "r= " << radiiVector[9] << "  " << "cx= " << cxVector[9] << "  " << "cy= " << cyVector[9] << "  " << "cz= " << czVector[9] << "  " << std::endl;
    std::cout << "Plane Number " << planeNumber[3] << "  " << "px= " << pxVector[numberOfPlanes - 1] << "  " << "py= " << pyVector[3] << "  " << "pz= " << pzVector[3] << "  " << "du= " << duVector[3] << "  " << "dv= " << dvVector[3] << "  " << "dw= " << dwVector[3] << "  " << std::endl;
    */
}
