#include <fstream>
#include "globalVariables.h"
#include <string>
#include <sstream>

void fileReaderSecondTry(const char *filename) {
    std::ifstream sceneFile (filename);
    int v1,v2,v3,v4,v5,v6,v7;
    int numberOfSpheres,numberOfPlanes;
    while (sceneFile >> v1 >> v2 >> v3 >> v4 >> v5 >> v6 >> v7) {
        if(v1 == 0) {     // circles begin with 0. Start reading at 4th value
            sphereNumber.push_back(v2);
            radiiVector.push_back(v4);
            cxVector.push_back(v5);
            cyVector.push_back(v6);
            czVector.push_back(v7);
        }
        if(v1 > 0) {    // planes begin with 1. Start reading at 2nd value
            planeNumber.push_back(v1);
            pxVector.push_back(v2);
            pyVector.push_back(v3);
            pzVector.push_back(v4);
            duVector.push_back(v5);
            dvVector.push_back(v6);
            dwVector.push_back(v7);
        }
    }
    numberOfSpheres = sphereNumber.size() - 1;
    numberOfPlanes = planeNumber.size() - 1;
    std::cout << "Number of spheres: " << numberOfSpheres << std::endl;
    std::cout << "Number of planes: " << numberOfPlanes << std::endl;
    std::cout << "Sphere Number " << sphereNumber[9] << "  " << "r= " << radiiVector[9] << "  " << "cx= " << cxVector[9] << "  " << "cy= " << cyVector[9] << "  " << "cz= " << czVector[9] << "  " << std::endl;
    std::cout << "Plane Number " << planeNumber[3] << "  " << "px= " << pxVector[numberOfPlanes - 1] << "  " << "py= " << pyVector[3] << "  " << "pz= " << pzVector[3] << "  " << "du= " << duVector[3] << "  " << "dv= " << dvVector[3] << "  " << "dw= " << dwVector[3] << "  " << std::endl;
}