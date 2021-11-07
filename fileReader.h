#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
// store chars
// next step: make an array of pointers to the chars using charPointer = sceneFile.tellg()

// original attempt

/*int fileInput(const char *filename) {
    int radiusRow = 0;
    int centerRow = 0;
    std::vector<int> radii;
    std::ifstream sceneFile (filename);
    char numVertices;
    if(sceneFile.is_open()) {
        char curChar;
        while(sceneFile) {
            curChar = sceneFile.get();
            if(curChar == ' ') {
                curChar = sceneFile.get();
            }
            if(curChar == 'r') {
                radiusRow = 1;
                curChar = sceneFile.get();
                radii.push_back((int)curChar);

            }
            std::cout << curChar;
        }
        
    }
    return 0;

}*/

void fileInput(const char *filename) {
    ifstream sceneFile (filename);
    string line;
    std::vector<double> radii;
    while(std::getline(std::cin,line)) {
        if(line.substr(0,2)=="sr") {
            std::istringstream v(line.substr(3));
            double radius;
            v >> radius;
            radii.push_back(radius);
        }
    }
}









//attempt copied from online

/*vector<int> sphereRadii;
vector<glm::vec3> sphereCenters;

void fileParser(const char *filename){
    std::ifstream(filename);
    std::string line;
    vector<glm::vec3> vertices;
    vector<glm::vec2> texture;
    vector<glm::vec3> normals;
    //std::vector sphereRadii;
    //std::vector sphereCenters;
    while(std::getline(in,line)) {
        if(line.substr(0,2)=="v ") {
            std::istringstream v(line.substr(2));
            glm::vec3 vert;
            double x,y,z;
            v>>x;v>>y;v>>z;
            vert=glm::vec3(x,y,z);
            vertices.push_back(vert);
        }
        else if(line.substr(0,2)=="sr") {
            std::istringstream v(line.substr(3));
            int radius;
            sphereRadii.push_back(radius);
        }
        else if(line.substr(0,2)=="sc") {
            std::istringstream v(line.substr(3));
            glm::vec3 center;
            double x,y,z;
            v>>x;v>>y;v>>z;
            center = glm::vec3(x,y,z);
            sphereCenters.push_back(center);
        }
        else if(line.substr(0,2)=="vt"){
            std::istringstream v(line.substr(3));
            glm::vec2 tex;
            int U,V;
            v>>U;v>>V;
            tex = glm::vec2(U,V);
            texture.push_back(tex);
        }
        else if(line.substr(0,2)=="vn"){
            std::istringstream v(line.substr(3));
            glm::vec3 norm;
            double x,y,z;
            v>>x;v>>y;v>>z;
            norm=glm::vec3(x,y,z);
            normals.push_back(norm);
        }
    }
}

std::vector returnCircleRadii(){
    return sphereRadii;
}
std::vector returnCircleCenters(){
    return sphereCenters;
}*/