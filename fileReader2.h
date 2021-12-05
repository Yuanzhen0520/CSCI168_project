#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Scene.h"
#include <iostream>
#include "Material.h"
using namespace std;

// 1
Material redRubber = {
    glm::vec3(0.05,0.0,0.0),
    glm::vec3(0.5,0.4,0.4),
    glm::vec3(.7,.04,.04),
    0.078125,
};

// 2
Material copper = {
    glm::vec3(0.19125,0.0735,0.0225),
    glm::vec3(0.7038,0.27048,0.0828),
    glm::vec3(0.256777,0.137622,0.086014),
    0.1,
};

// 3
Material emerald = {
    glm::vec3(0.0215,0.1745,0.0215),
    glm::vec3(0.07568,0.61424,0.07568),
    glm::vec3(0.633,0.727811,0.633),
    0.6,
};

// 4
Material pearl = {
    glm::vec3(0.25,0.20725,0.20725),
    glm::vec3(1,0.829,0.829),
    glm::vec3(0.296648,0.296648,0.296648),
    0.088,
};

// 5
Material cyanPlastic = {
    glm::vec3(0.0,0.1,0.06),
    glm::vec3(0.0,0.50980392,0.50980392),
    glm::vec3(0.50196078,0.50196078,0.50196078),
    0.25,
};
std::vector<glm::vec4> spheres;
std::vector<glm::vec3> planePoints;
std::vector<glm::vec3> planeNormals;
std::vector<Material> planeMaterials;
std::vector<glm::vec3> lights;
std::vector<Material> sphereMaterials;
int numberOfSpheres,numberOfPlanes,numberOfLights,numberOfCameras;

void fileReaderSecondTry(const char *filename) {
    spheres.clear();
    planePoints.clear();
    planeNormals.clear();
    planeMaterials.clear();
    lights.clear();
    sphereMaterials.clear();
    numberOfSpheres = 0;
    numberOfPlanes = 0;
    numberOfLights = 0;
    numberOfCameras = 0;
    // need to take material as input too, says i can use .mtl file as secondary file
    std::ifstream sceneFile (filename);
    int v1,v2,v3,v4,v5,v6,v7,v8;
    //int numberOfSpheres,numberOfPlanes,numberOfLights,numberOfCameras;
    while (sceneFile >> v1 >> v2 >> v3 >> v4 >> v5 >> v6 >> v7 >> v8) {
        if(v1 == 0) {     // spheres begin with 0. Start reading at 4th value
            glm::vec4 curSphere = glm::vec4(v4,v5,v6,v7);
            spheres.push_back(curSphere);
            switch(v8) {
                case 1:
                    sphereMaterials.push_back(redRubber);
                    break;
                case 2:
                    sphereMaterials.push_back(copper);
                    break;
                case 3:
                    sphereMaterials.push_back(emerald);
                    break;
                case 4:
                    sphereMaterials.push_back(pearl);
                    break;
                case 5:
                    sphereMaterials.push_back(cyanPlastic);
                    break;
            }
        }
        if(v1 == 1) {    // planes begin with 1. Start reading at 2nd value
            glm::vec3 curPlanePoint = glm::vec3(v2,v3,v4);
            glm::vec3 curPlaneNormal = glm::vec3(v5,v6,v7);
            planePoints.push_back(curPlanePoint);
            planeNormals.push_back(curPlaneNormal);
            switch(v8) {
                case 1:
                    planeMaterials.push_back(redRubber);
                    break;
                case 2:
                    planeMaterials.push_back(copper);
                    break;
                case 3:
                    planeMaterials.push_back(emerald);
                    break;
                case 4:
                    planeMaterials.push_back(pearl);
                    break;
                case 5:
                    planeMaterials.push_back(cyanPlastic);
                    break;
            }
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

    /*cout << "Number of spheres: " << numberOfSpheres << endl;
    cout << "Number of planes: " << numberOfPlanes << endl;
    cout << "Number of lights: " << numberOfLights << endl;
    
    std::cout << "Sphere Number " << sphereNumber[3] << "  y= " << spheres[3][2] << std::endl;
    std::cout << "Plane Number " << planeNumber[2] << " py= " << planePoints[2][1] << std::endl;
    std::cout << "Sphere Number " << sphereNumber[9] << "  " << "r= " << radiiVector[9] << "  " << "cx= " << cxVector[9] << "  " << "cy= " << cyVector[9] << "  " << "cz= " << czVector[9] << "  " << std::endl;
    std::cout << "Plane Number " << planeNumber[3] << "  " << "px= " << pxVector[numberOfPlanes - 1] << "  " << "py= " << pyVector[3] << "  " << "pz= " << pzVector[3] << "  " << "du= " << duVector[3] << "  " << "dv= " << dvVector[3] << "  " << "dw= " << dwVector[3] << "  " << std::endl;
    */
}
