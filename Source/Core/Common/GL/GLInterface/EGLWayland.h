// Copyright 2014 Dolphin Emulator Project
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "Common/GL/GLInterface/EGL.h"

class GLContextEGLWayland final : public GLContextEGL
{
public:
  void Update() override;
protected:
  EGLDisplay OpenEGLDisplay() override;
  EGLNativeWindowType GetEGLNativeWindow(EGLConfig config) override;
  EGLNativeWindowType m_native_window = 0;
};
