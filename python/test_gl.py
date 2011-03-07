# Copyright (C) 2009  Gaetan Guidet
# 
# This file is part of pygl.
# 
# luagl is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation; either version 2.1 of the License, or (at
# your option) any later version.
# 
# luagl is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
# USA.


import sys
import pygl
from pygl import gl
from pygl import glut

prog = None
mesh = None
mesh_idx = None
use_arrays = True
elapsed_time = 0 # in milliseconds
step = 1
time_param = 1

def checkVertex(element):
  if element[0] != element.position.x:
    raise Exception("position.x mismatch")
  if element[1] != element.position.y:
    raise Exception("position.y mismatch")
  if element[2] != element.position.z:
    raise Exception("position.z mismatch")
  if element[3] != element.texcoord.s:
    raise Exception("texcoord.s mismatch")
  if element[4] != element.texcoord.t:
    raise Exception("texcoord.t mismatch")

def initMesh():
  global mesh, mesh_idx
  
  mesh_fmt = pygl.buffer.MakeStructure(["position", ["x", "y", "z"]], ["texcoord", ["s", "t"]])

  mesh = pygl.buffer.New(pygl.buffer.Float, mesh_fmt, 4)

  # StructuredBuffer sucks ...
  
  mesh_idx = pygl.buffer.New(pygl.buffer.Ushort, 4)
  mesh_idx[0] = 0
  mesh_idx[1] = 1
  mesh_idx[2] = 2
  mesh_idx[3] = 3
  
  v = mesh.element(0)
  v[0] = 0
  v[1] = 0
  v[2] = 0
  v[3] = 0
  v[4] = 0
  print("check v0")
  checkVertex(v)

  v = mesh.element(1)
  v.position.x = 1
  v.position.y = 0
  v.position.z = 0
  v.texcoord.s = 1
  v.texcoord.t = 0
  print("check v1")
  checkVertex(v)

  v = mesh.element(2)
  v[0] = 1
  v[1] = 1
  v[2] = 0
  v[3] = 1
  v[4] = 1
  print("check v2")
  checkVertex(v)

  v = mesh.element(3)
  v[0] = 0
  v[1] = 1
  v[2] = 0
  v[3] = 0
  v[4] = 1
  print("check v3")
  checkVertex(v)
  
  print(mesh)

def drawMesh():
  global mesh, mesh_idx, use_arrays
  
  if use_arrays == True:
    positions = mesh.field("position")
    texcoords = mesh.field("texcoord")
    stride = mesh.elementSize
    gl.EnableClientState(gl.VERTEX_ARRAY)
    gl.ClientActiveTexture(gl.TEXTURE0)
    gl.EnableClientState(gl.TEXTURE_COORD_ARRAY)
    gl.TexCoordPointer(2, gl.FLOAT, stride, texcoords.rawPtr)
    gl.VertexPointer(3, gl.FLOAT, stride, positions.rawPtr)
    #gl.DrawArrays(gl.QUADS, 0, 4)
    gl.DrawElements(gl.QUADS, 4, gl.UNSIGNED_SHORT, mesh_idx.rawPtr)
    gl.DisableClientState(gl.TEXTURE_COORD_ARRAY)
    gl.DisableClientState(gl.VERTEX_ARRAY)
  else:
    gl.Begin(gl.QUADS)
    for e in mesh:
      gl.MultiTexCoord2f(gl.TEXTURE0, e.texcoord.s, e.texcoord.t);
      gl.Color3f(1, 1, 1)
      gl.Vertex3fv(e.position)
    gl.End()

def initShaders():
  global prog
  
  vprog_src = [
    "void main() {\n",
    "  gl_TexCoord[0] = gl_MultiTexCoord0;\n",
    "  gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;\n",
    "}\n"
  ]
  
  fprog_src = [
    "uniform float time;\n",
    "void main() {\n",
    "  gl_FragColor = time * vec4(gl_TexCoord[0].s, gl_TexCoord[0].t, 1.0, 0.0);\n",
    "}\n"
  ]

  prog = gl.CreateProgram()
  vprog = gl.CreateShader(gl.VERTEX_SHADER)
  gl.ShaderSource(vprog, vprog_src)
  gl.CompileShader(vprog)
  print("Compile vertex shader: %s" % gl.GetShaderInfoLog(vprog))
  fprog = gl.CreateShader(gl.FRAGMENT_SHADER)
  gl.ShaderSource(fprog, fprog_src)
  gl.CompileShader(fprog)
  print("Compile fragment shader: %s" % gl.GetShaderInfoLog(fprog))
  gl.AttachShader(prog, vprog)
  gl.AttachShader(prog, fprog)
  gl.LinkProgram(prog)
  print("Link: %s" % gl.GetProgramInfoLog(prog))
  print("Vertex shader source: %s" % gl.GetShaderSource(vprog))
  print("Fragment shader source: %s" % gl.GetShaderSource(fprog))

# callbacks

def display():
  global prog, time_param
  
  gl.Clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT)
  gl.PushMatrix()
  gl.UseProgram(prog)
  
  loc = gl.GetUniformLocation(prog, "time")
  gl.Uniform1f(loc, time_param)
  
  drawMesh()
  gl.UseProgram(0)
  gl.PopMatrix()
  glut.SwapBuffers()

def reshape(w, h):
  print("reshape %dx%d" % (w, h))
  gl.Viewport(0, 0, w, h)
  gl.MatrixMode(gl.PROJECTION)
  gl.LoadIdentity()
  gl.Ortho(0, 1, 0, 1, -1, 1)
  gl.MatrixMode(gl.MODELVIEW)
  gl.LoadIdentity()
  glut.PostRedisplay()

def keyboard(key, x, y):
  global use_arrays
  
  if (key == 27):
    print("Quit")
    glut.Exit(0)
  elif key == 97: # 'A'
    use_arrays = not use_arrays
    glut.PostRedisplay()
  else:
    print("Key: %s" % key)

def menu(val):
  print("MenuEntry %s selected" % val)
  if val == 1:
    print("Quit")
    glut.Exit(0)

def submenu(val):
  print("SubMenuEntry %s selected: %s" % (val, ["Hello", "Goodbye"][val]))

def fade():
  global elapsed_time, step, time_param
  
  time_param = elapsed_time * 0.01
  elapsed_time = elapsed_time + step
  if elapsed_time >= 100:
    step = -1
  elif elapsed_time == 0:
    step = 1
  glut.PostRedisplay()
  #glut.TimerFunc(1, fade, 0)

def printMatrix(m):
  s = ""
  # line
  for i in xrange(4):
    s = s + "{ ";
    # col
    for j in xrange(4):
      s = s + "%s " % m[i+j*4]
    s = s + "}\n"
  print(s)

def initGL():
  gl.Init()
  print("OpenGL version: %s" % gl.version)
  gl.ClearColor(0, 0, 0, 1)
  gl.ClearDepth(1)
  gl.DepthFunc(gl.LESS)
  gl.ShadeModel(gl.SMOOTH)
  gl.Enable(gl.LIGHTING)
  gl.Enable(gl.LIGHT0)
  gl.Enable(gl.DEPTH_TEST)
  gl.Enable(gl.CULL_FACE)
  gl.FrontFace(gl.CCW)
  initMesh()
  initShaders()

glut.Init()
glut.InitWindowPosition(50, 50)
glut.InitWindowSize(640, 480)
dm = glut.RGBA|glut.DEPTH|glut.DOUBLE
glut.InitDisplayMode(dm)
glut.CreateWindow("PyGLUT")
initGL()
glut.DisplayFunc(display)
glut.ReshapeFunc(reshape)
glut.KeyboardFunc(keyboard)
#glut.TimerFunc(1, fade, 0)
glut.IdleFunc(fade)

smid = glut.CreateMenu(submenu)
glut.AddMenuEntry("Hello", 0)
glut.AddMenuEntry("Goodbye", 1)
mid = glut.CreateMenu(menu)
glut.AddSubMenu("Greetings", smid)
glut.AddMenuEntry("Quit", 1)
glut.AttachMenu(glut.RIGHT_BUTTON)

glut.MainLoop()

