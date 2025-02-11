#pragma once
#include "Camera.h"
#include "../glew-2.1.0/include/GL/glew.h"

//Forward declaration
class Portal;

class FrameBuffer {
public:
  FrameBuffer();

  void Render(const Camera& cam, GLuint curFBO, const Portal* skipPortal);
  void Use();

private:
  GLuint texId;
  GLuint fbo;
  GLuint renderBuf;
};
