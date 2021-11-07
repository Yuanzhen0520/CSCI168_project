#include "RayTracer.h"



void RayTracer::render(const Scene& _scene, int width, int height) const {
  // for each column i do
    for(int i = 0; i < height; i++){
  //   for each row j do
        for(int j = 0; j < width; j++){
  //     generate a ray origin and direction
        glm::vec3 o = ();
        glm::vec3 d = ();
        const Ray ray(o,d);
  //     find the first intersection point of the ray (minimum to object in array)
        Collision c = ;
        if(c.m_type = kHit){
        //     shade the ray intersection

        }
  
        }
    }
  // Copy framebuffer to scene
}



/*void RayTracer::clear() const {
}



glm::vec4 getColor(const vector<Light>& lights, const Material& material, const glm::vec3& point, const glm::vec3& normal)
{
   glm::vec4 final_color(0,0,0,0);
   for (const Light& light : lights)
   {
      glm::vec4 ambient(2,4,6,8);  // lighting equations help
      glm::vec4 diffuse(2,5,1,2);
      glm::vec4 specular(1,3,0,1);
      final_color += ambient + diffuse + specular;
   }
   return final_color;
}
*/
