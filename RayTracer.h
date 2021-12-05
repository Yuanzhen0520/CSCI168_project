#ifndef _RAYTRACER_H_
#define _RAYTRACER_H_

// GL
#include "GLInclude.h"

// Engine
#include "Renderer.h"
#include "Scene.h"
#include "Ray.h"

using namespace std;
////////////////////////////////////////////////////////////////////////////////
/// @brief Ray tracer
////////////////////////////////////////////////////////////////////////////////
class RayTracer : public Renderer {
  public:
    glm::vec3 trace(const Ray &ray, const std::vector<Object*> o, const glm::vec3 &_cEye) const;
    void clear() const override;
    void render(const Scene& _scene,int g_height,int g_width, std::unique_ptr<glm::vec4[]>& g_frame) const override;

  private:
    std::unique_ptr<glm::vec4[]> m_frame{nullptr}; ///< Framebuffer
};

#endif