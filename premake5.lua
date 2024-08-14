workspace "HelloWorld"
    configurations { "Debug", "Release" }

include "buildscripts/shared.lua"
include "buildscripts/runtime.lua"
include "buildscripts/editor.lua"
include "buildscripts/sandbox.lua"