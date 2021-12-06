#include "RayTracer.h"
#include <iostream>

void RayTracer::clear() const {
}

glm::vec3 RayTracer::trace(const Ray &ray,const vector<Object*> o, const glm::vec3 &_cEye, Light l) const {
  //Object ob;
  
  int parameter = -1;
  float minDist = INFINITY;
  for(int i = 0; i < o.size(); i++){
    Collision c = o[i]->collide(ray);
    if(c.m_type == Collision::Type::kHit){
      //std::cout << "Hit" << std::endl;
      float dist = glm::distance(ray.getO(), c.m_x);
      if(dist < minDist){
        parameter = i;
        minDist = dist;
      }
    }
    else { 
      //std::cout << "Miss" << std::endl;
    }
  }
  //std::cout << "Parameter = " << parameter << std::endl;
  if(parameter == -1 || parameter > o.size() - 1) return glm::vec3(0.0f,0.0f,0.0f);
  Collision c = o[parameter]->collide(ray);
  return l.multipleLights((c.m_material), (c.m_x), (c.m_normal), _cEye);
}

void RayTracer::render(const Scene& _scene,int g_height, int g_width, unique_ptr<glm::vec4[]>& g_frame) const {
  float d = 1;
  float t = d*tan(22.5);
  float b = -t;
  float l = (16/9)*b;
  float r = -l;
  g_frame = std::make_unique<glm::vec4[]>(g_width*g_height);
  //std::cout << "g_width = " << g_width << std::endl;
  //std::cout << "g_height = " << g_height << std::endl;
  for(int i=0; i<g_width; i++){
    //std::cout << i << std::endl;
    for(int j=0; j<g_height; j++){
      //std::cout << j << std::endl;
      float tau = l + ((r-l)*(i+0.5))/g_width;
      float sigma = b + ((t-b)*(j+0.5))/g_height;
      glm::vec3 o(0.0f, 0.0f, 0.0f);//eye
      glm::vec3 direction = glm::vec3(tau,sigma,-d);//need to caulculate

      Ray ray(o,direction);
      vector<Object*> v;
      vector<Sphere> sv = _scene.getS();
      vector<Plane> pv = _scene.getP();
      //std::cout << "svSize: " << sv.size() << std::endl;
      //std::cout << "pvSize: " << pv.size() << std::endl;
      for(int k = 0; k < pv.size(); k++){
        v.emplace_back(new Plane(pv[k].getP(), pv[k].getN(), pv[k].getMaterial()));
      }
      for(int k = 0; k < sv.size(); k++){
        v.emplace_back(new Sphere(sv[k].getRadius(), sv[k].getCenter(), sv[k].getMaterial()));
      }
      vector<Light> lv = _scene.getL();
      int a = j*g_width + i;
      //glm::vec3 color = trace(ray, v, o, lv[0]);

 

      //Ray direction as colors
     /*glm::vec3 rayDirectionNormal = glm::normalize(direction);
      glm::vec3 tempVec3 = rayDirectionNormal + glm::vec3(1.f,1.f,1.f)/2;
      glm::vec4 rayColor = glm::vec4(tempVec3,1.f);
      g_frame[a] = rayColor; */

      // where we will test trace without a function


      //std::cout << v.size() << std::endl;
      int parameter = -1;
      float minDist = INFINITY;
      for(int z = 0; z < v.size(); z++){
        Collision c = v[z]->collide(ray);
        if(c.m_type == Collision::Type::kHit){
          //std::cout << "Hit" << std::endl;
          float dist = glm::distance(ray.getO(), c.m_x);
          if(dist < minDist){
            parameter = z;
            minDist = dist;
          }
        }
        else { 
          //std::cout << "Miss" << std::endl;
        }
      }
      //std::cout << "Parameter = " << parameter << std::endl;
      if(parameter == -1) g_frame[a] = glm::vec4(0.6f,0.8f,1.f,1.f);
      else{ 
        Collision c = v[parameter]->collide(ray);
        glm::vec3 colors = glm::vec3(0,0,0);
        for(int i = 0; i < lv.size(); i++){
          Light l = lv[i];
          colors += l.multipleLights((c.m_material), (c.m_x), (c.m_normal), o);
          float diffuseColor = colors[1];
          float specularColor = colors[2];
          float ambientColor = colors[0];
          // shadow rays
          Ray shadowRay = Ray(c.m_x,c.m_x-l.getPosition());
          for(int s = 0;s<v.size();s++) {
            Collision sc = v[s]->collide(shadowRay);
            if(sc.m_type == Collision::Type::kHit) {
              colors[1] -= diffuseColor;
              colors[2] -= specularColor;
            }
          }
        }
        colors[0] = (colors[0] > 1) ? 1 : (colors[0] < 0) ? 0 : colors[0];
        colors[1] = (colors[1] > 1) ? 1 : (colors[1] < 0) ? 0 : colors[1];
        colors[2] = (colors[2] > 1) ? 1 : (colors[2] < 0) ? 0 : colors[2];
        g_frame[a] = glm::vec4(colors, 1.f);
      }
      
      for(auto p : v){
        delete p;
      }
      v.clear();
      
      




/* Shadow */ 
      /*
      class Shadow{
      public:
      Shadow(GLfloat distance, bool shade):distance(distance) shade(shade) {} 
      
      private:
      GLfloat distance; 
      bool shade;
      }*/





      // end of trace function w/out a function


      //std::cout << a << std::endl;
      /*if(color[0] == 0 && color[1] == 0 && color[2] == 0) {
        g_frame[a] = glm::vec4(0.f,0.f,0.f,0.f);
      }
      else {
      g_frame[a] = glm::vec4(color[0],color[1],color[2],1.f);
      }*/
      
    }
  }
}
