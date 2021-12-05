#include "RayTracer.h"



void RayTracer::clear() const {
}

glm::vec3 RayTracer::trace(const Ray &ray, const vector<Object*> o, const glm::vec3 &_cEye) const {
  //Object ob;
  int parameter = -1;
  float minDist = INFINITY;
  for(int i = 0; i < o.size(); i++){
      Collision c = o[i]->collide(ray);
      if(c.m_type == Collision::Type::kHit){
        float dist = glm::distance(ray.getO(), c.m_x);
        if(dist < minDist){
          parameter = i;
          minDist = dist;
        }
      }
  }
  if(parameter == -1) return glm::vec3(0.0f,0.0f,0.0f);
  Collision c = o[parameter]->collide(ray);
  Light l(c.m_x);
  return l.multipleLights(l, (c.m_material), (c.m_x), (c.m_normal), _cEye);
}

void RayTracer::render(const Scene& _scene,int g_height, int g_width, unique_ptr<glm::vec4[]>& g_frame) const {
  float d = 100;
  float t = d*tan(25.5);
  float b = -t;
  float l = (16/9)*b;
  float r = -l;
  g_frame = std::make_unique<glm::vec4[]>(g_width*g_height);

  for(int i=0; i<g_width; i++){
    for(int j=0; j<g_height; j++){
      float tau = l + ((r-l)*(i+0.5))/g_width;
      float sigma = b + ((t-b)*(j+0.5))/g_height;
      glm::vec3 o(0.0f, 0.0f, 0.0f);//eye
      glm::vec3 direction = glm::vec3(tau,sigma,-d);//need to caulculate

      Ray ray(o,direction);
      vector<Object*> v;
      vector<Sphere> sv = _scene.getS();
      vector<Plane>  pv = _scene.getP();
      for(int i = 0; i < sv.size(); i++){
        v.emplace_back(new Sphere(sv[i].getRadius(), sv[i].getCenter(), sv[i].getMaterial()));
      }
      for(int i = 0; i < pv.size(); i++){
        v.emplace_back(new Plane(pv[i].getP(), pv[i].getN(), pv[i].getMaterial()));
      }
      glm::vec3 color = trace(ray, v, o);
      double k = j*g_width + i;
      if(color[0] == 0 && color[1] == 0 && color[2] == 0) {
        g_frame[k] = glm::vec4(0.f,0.f,0.f,0.f);
      }
      else {
      g_frame[k] = glm::vec4(color[0],color[1],color[2],1.f);
      }
      
    }
  }
}