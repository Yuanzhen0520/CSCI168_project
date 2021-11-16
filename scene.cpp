#include "Scene.h"
#include "fileReader2.h"

void Scene::readScene()
{
    /*ifstream input;
    string object;
    int val1;
    int val2;
    int val3;
    input.open("scene.txt");
    while( input >> object >> val1 >> val2 >> val3){
        if(object == "camera_eye"){
            _camera.setEye({val1, val2, val3});
        }
        if(object == "camera_at"){
            _camera.setAtVector({val1,val2,val3});
        }
        if(object == "camera_up"){
            _camera.setUpVector({val1,val2,val3});
        }
        if( object == "projection_perspective"){
            
        }
        if(object == "sphere_center"){
            _sphere.setCenter({val1,val2,val3});
        }
        if(object == "sphere_radius"){
            _sphere.setRadius({val1,val2,val3});
        }
        if(object == "plane_point"){
            _plane.setPoint({val1,val2,val3});
        }
        if(object == "plane_normal"){
            _plane.setNormal({val1,val2,val3});
        }
    }*/
    fileReaderSecondTry("sampleFile.txt");
    for(int i = 0;i < numberOfSpheres;i++) {
        // create sphere object
        float rad = spheres[i]][0];
        glm::vec3 cent;
        cent[0] = spheres[i][1];
        cent[1] = spheres[i][2];
        cent[2] = spheres[i][3];
        std::cout << "Z component of sphere center: " << cent[2] << endl;
        // now create a sphere object, idk how to do that
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
        std::cout << "X component of plane point: " << p[0] << endl;
        // now create a plane object, idk how to do that
    }


}

//use constructors, read line by line
