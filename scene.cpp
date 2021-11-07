#include "Scene.h"

void Scene::readScene()
{
    ifstream input;
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
    }
}

//use constructors, read line by line
