#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

std::vector<glm::vec4> spheres;
std::vector<glm::vec3> planePoints;
std::vector<glm::vec3> planeNormals;

std::vector<int> sphereNumber;
std::vector<int> planeNumber;

void fileReaderSecondTry(const char *filename) {
    std::ifstream sceneFile (filename);
    int v1,v2,v3,v4,v5,v6,v7;
    int numberOfSpheres,numberOfPlanes;
    while (sceneFile >> v1 >> v2 >> v3 >> v4 >> v5 >> v6 >> v7) {
        if(v1 == 0) {     // spheres begin with 0. Start reading at 4th value
            glm::vec4 curSphere = glm::vec4(v4,v5,v6,v7);
            spheres.push_back(curSphere);
            sphereNumber.push_back(v2);
        }
        if(v1 > 0) {    // planes begin with 1. Start reading at 2nd value
            glm::vec3 curPlanePoint = glm::vec3(v2,v3,v4);
            glm::vec3 curPlaneNormal = glm::vec3(v5,v6,v7);
            planeNumber.push_back(v1);
            planePoints.push_back(curPlanePoint);
            planeNormals.push_back(curPlaneNormal);
        }
    }
    numberOfSpheres = sphereNumber.size() - 1;
    numberOfPlanes = planeNumber.size() - 1;
    std::cout << "Number of spheres: " << numberOfSpheres << std::endl;
    std::cout << "Number of planes: " << numberOfPlanes << std::endl;
    std::cout << "Sphere Number " << sphereNumber[3] << "  y= " << spheres[3][2] << std::endl;
    std::cout << "Plane Number " << planeNumber[2] << " py= " << planePoints[2][1] << std::endl;
    /*std::cout << "Sphere Number " << sphereNumber[9] << "  " << "r= " << radiiVector[9] << "  " << "cx= " << cxVector[9] << "  " << "cy= " << cyVector[9] << "  " << "cz= " << czVector[9] << "  " << std::endl;
    std::cout << "Plane Number " << planeNumber[3] << "  " << "px= " << pxVector[numberOfPlanes - 1] << "  " << "py= " << pyVector[3] << "  " << "pz= " << pzVector[3] << "  " << "du= " << duVector[3] << "  " << "dv= " << dvVector[3] << "  " << "dw= " << dwVector[3] << "  " << std::endl;
    */
}