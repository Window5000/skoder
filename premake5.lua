workspace "Squirrel"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "SquirrelApp"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "vendor/Walnut/WalnutExternal.lua"
include "Squirrel"
include "SquirrelApp"