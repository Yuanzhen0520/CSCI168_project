void RayTracer::clear() const {
}

void RayTracer::render(const Scene& _scene,int g_height, int g_width) const {
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