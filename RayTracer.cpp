#include "RayTracer.h"
#include "Ray.h"

void RayTracer::clear() const {
}

void RayTracer::render(const Scene& _scene,int g_height, int g_width) const {
<<<<<<< HEAD
=======
  // temporary declaration of g_width and g_height so that i can test other bugs
  //int g_height = 1360; // CHANGE LATER
  //int g_width = 768; // CHANGE THIS LATER
  // int g_height = RayTracer.fHeight;
    
  // int g_width = RayTracer.fWidth;
  // for each column i do
  /*  for(int i = 0; i< 768 ; i++) //height
  //   for each row j do
      for( int j = 0; i < 1360; j++) {
        glm::vec3 x =(j, i, 0.f); 
        glm::vec3 y = (0.f, 0.f, 1.f);
        const Ray ray(x,y);
        Collision c = Sphere::collide(ray);
        if(c.m_type == kHit){
        }
      }*/
  //     generate a ray origin and direction
  //     
  //     find the first intersection point of the ray
  //
  //     shade the ray intersection
  //
  // Copy framebuffer to screen
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
  
  glm::vec3 RayTracer::trace(const Ray &ray, const vector<Object> o, const glm::vec3 &_cEye){
  Object ob;
  float minDist = INFINITY;
  for(int i = 0; i < o.size(); i++){
      Collision c = o[i].collide(ray);
      if(c.Type == kHit){
        float dist = glm::distance(ray.getO(), c.m_x);
        if(dist < minDist){
          ob = o[i];
          minDist = dist;
        }
      }
  }
  if(ob == NULL) return glm::vec3(0.0f,0.0f,0.0f);
  Collision c = ob.collide(ray);
  Light l(c.m_x);
  return multiplieLights(l, c.m_material, c.m_x. c.m_normal, _cEye);
}
  
  
  
>>>>>>> 04668efb61895ed366102caa13866853c3d6faa0
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

      Ray ray(o,direction);
      std::vector<Object> v = _scene.getS();
      v.insert(v.end(), _scene.getP().begin(), _scene.getP().end());
      glm::vec3 color = trace(ray, v, o);
      double k = j*g_width + i;
      g_frame[k] = glm::vec4(color[0],color[1],color[2],1.f);
      
    }
  }
}
