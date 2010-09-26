# Copyright (C) 2010  Gaetan Guidet
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

import pygl

print("Constant")
print("  pygl.buffer.Byte = %s" % pygl.buffer.Byte)
print("  pygl.buffer.Short = %s" % pygl.buffer.Short)
print("  pygl.buffer.Int = %s" % pygl.buffer.Int)
print("  pygl.buffer.Float = %s" % pygl.buffer.Float)
print("  pygl.buffer.Double = %s" % pygl.buffer.Double)

print("Create structure")
d = pygl.buffer.MakeStructure(["position", ["x","y","z"]], ["normal", ["x","y","z"]])
print(type(d))

print("  %s" % d)
print("  has field \"position\": %s" % d.hasField("position"))
print("  has field \"x\": %s" % d.hasField("x"))
print("  is finalized: %s" % d.finalized)
print("  is terminal: %s" % d.terminal)
print("  field \"normal\" index: %s" % d.fieldIndex("normal"))
print("  field \"x\" index: %s" % d.fieldIndex("x"))
print("  offset: %s" % d.offset)
print("  \"normal\": %s" % d.field("normal"))
print("  \"normal\" field count: %s" % d.field("normal").fieldCount)
print("  \"normal.y\" index: %s" % d.field("normal").fieldIndex("y"))
print("  \"position\" offset: %s" % d.field("position").offset)
print("  \"position.z\" offset: %s" % d.field("position").field("z").offset)
print("  \"normal\" offset: %s" % d.field("normal").offset)
print("  \"normal.z\" offset: %s" % d.field("normal").field("z").offset)
#d.add("texcoord0")

print("Allocate new buffer from %s" % d)
b = pygl.buffer.New(pygl.buffer.Float, d, 20)
#b = pygl.buffer.StructuredFloatBuffer(d, 20)
print("  -> %s" % b)
print("  structure: %s" % b.structure)
print("  type: %s" % b.type)
print("  element count: %s" % b.elementCount)
print("  element byte size: %s" % b.elementSize)
print("  field count: %s" % b.fieldCount)
print("  \"position\" field offset: %s" % b.fieldOffset("position"))
print("  \"normal\" field offset: %s" % b.fieldOffset("normal"))

print("Get sub buffer \"normal\"")
n = b.field("normal")
print("  structure: %s" % n.structure)
print("  element count: %s" % n.elementCount)
print("  element size: %s" % n.elementSize)
print("  field count: %s" % n.fieldCount)
print("  \"z\"field offset: %s" % n.fieldOffset("z"))

print("Set values in buffer")
for i in xrange(b.elementCount):
  off = b.elementOffset(i)
  for j in xrange(b.fieldCount):
    print("@%s (i:%s, j:%s) = %s" % (off+j, i, j, i+j))
    b[off+j] = i + j

print("Get values in buffer")
print("  b[2].position.x = %s" % (b.element(2).position.x))
print("  b[2].position.z = %s" % (b.element(2).position.z))
print("  b[2].normal.z = %s" % (b.element(2).normal.z))
print("  b[7] = %s" % b[7])
print("  b[9] = %s" % b[9])
print("  b[12] = %s" % b[12])
b.element(2).position.x = -20
print("  b[2].position.x = %s" % (b.element(2).position.x))

print("Set normals")
normals = b.normal
foff = b.fieldOffset("normal")
print("  field count: %s" % normals.fieldCount)
for i in xrange(normals.elementCount):
  off = normals.elementOffset(i)
  print("@%s~%s (i:%s, j: [0~2]) = [%s~%s]" % (off+foff, off+foff+2, i, off, off-2))
  normal = normals.element(i)
  normal.x = off
  normal.y = off-1
  normal.z = off-2

print("Get normals")
print("b[117] = %s" % b[117])
print("b[118] = %s" % b[118])
print("b[119] = %s" % b[119])


print("Buffer print")
print(b)
print("Positions")
print(b.position)
print("Normals")
print(b.normal)


print("Test iterator")
for e in b:
  px = e.position.x
  py = e.position.y
  pz = e.position.z
  nx = e.normal.x
  ny = e.normal.y
  nz = e.normal.z
  print("[(%s, %s, %s), (%s, %s, %s)]" % (px, py, pz, nx, ny, nz))

# if I do this before, it gets well after
print("Test simple buffer")
sb = pygl.buffer.ByteBuffer(20)
sb[16] = 320 # 255
sb[11] = 157.987 # 158
for i in xrange(sb.elementCount):
  print("@%s: %s" % (i, sb[i]))
print("  raw ptr: %s" % sb.rawPtr)









