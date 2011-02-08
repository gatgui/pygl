import glob
import excons
import excons.tools
from excons.tools import python
from excons.tools import glut

defs = ["GLEW_STATIC", "GLEW_BUILD"]
if int(ARGUMENTS.get("gluVariadicCallbacks", "0")) == 1:
  defs.append("PYGL_GLU_VARIADIC_CALLBACK")

prjs = [
  { "name"    : "pygl",
    "type"    : "dynamicmodule",
    "defs"    : defs,
    "incdirs" : ["include"],
    "srcs"    : glob.glob("src/*.cpp") + glob.glob("src/mem/*.cpp") + ["src/glew.c"],
    "ext"     : python.ModuleExtension(),
    "prefix"  : python.ModulePrefix(),
    "custom"  : [python.Require, glut.Require]
  }
]

env = excons.MakeBaseEnv()
excons.DeclareTargets(env, prjs)




