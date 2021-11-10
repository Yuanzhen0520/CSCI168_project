#include "RayTracer.h"
#include "Ray.h"
#include "globalVariables.h"
//test 
void RayTracer::clear() const {
}

void RayTracer::render(const Scene& _scene) const {
  // int g_height = RayTracer.fHeight;
  // int g_width = RayTracer.fWidth;
  // for each column i do
  //   for each row j do
  //     generate a ray origin and direction
  //     
  //     find the first intersection point of the ray
  //
  //     shade the ray intersection
  //
  // Copy framebuffer to screne
  /*for(double x = 0; x < g_width; x++) {
    for(double y = 0; y < g_height; y++) {
        // point is (x,y)
        // the equivalent i would be: 
        //    i = y * g_width + x
        double i = y * g_width + x;
        g_frame[i] = glm::vec4(float(rand()/100)/RAND_MAX, float(rand())/RAND_MAX,
                           float(rand())/RAND_MAX, 1.f);
                           
    }
  }*/
  float d = 100;
  float t = d*tan(25.5);
  float b = -t;
  float l = (16/9)*b;
  float r = -l;

  for(int i=0; i<g_width; i++){
    for(int j=0; j<g_height; j++){
      float tau = l + ((r-l)*(i+0.5))/g_width;
      float sigma = b + ((t-b)*(j+0.5))/g_height;
      glm::vec3 o(0.0f, 0.0f, 0.0f);//eye
      glm::vec3 direction = glm::vec3(tau,sigma,-d);//need to caulculate

      Ray(o,direction);
      
    }
  }
}
