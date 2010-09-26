import glob
import excons
import excons.tools
from excons.tools import python
from excons.tools import glut

prjs = [
  { "name"    : "pygl",
    "type"    : "dynamicmodule",
    "defs"    : ["GLEW_STATIC", "GLEW_BUILD"],
    "incdirs" : ["include"],
    "srcs"    : glob.glob("src/*.cpp") + glob.glob("src/mem/*.cpp") + ["src/glew.c"],
    "ext"     : python.ModuleExtension(),
    "prefix"  : python.ModulePrefix(),
    "custom"  : [python.Require, glut.Require]
  }
]

env = excons.MakeBaseEnv()
excons.DeclareTargets(env, prjs)




