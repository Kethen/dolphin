#include <wayland-egl.h>
#include "EGLWayland.h"

void GLContextEGLWayland::Update(){
  int width, height = 0;
  if (m_wsi.get_window_size != nullptr) {
    m_wsi.get_window_size(m_wsi.get_window_size_arg, &width, &height);
  }
  wl_egl_window_resize(m_native_window, width, height, 0, 0);
  m_backbuffer_width = width;
  m_backbuffer_height = height;
}

EGLDisplay GLContextEGLWayland::OpenEGLDisplay(){
  return eglGetDisplay(static_cast<NativeDisplayType>(m_wsi.display_connection));
}

EGLNativeWindowType GLContextEGLWayland::GetEGLNativeWindow(EGLConfig config){
  int width, height = 0;
  if (m_wsi.get_window_size != nullptr) {
    m_wsi.get_window_size(m_wsi.get_window_size_arg, &width, &height);
  }
  m_native_window = wl_egl_window_create(static_cast<struct wl_surface*>(m_wsi.render_surface), width, height);
  return m_native_window;
}
