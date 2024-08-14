workspace "HelloWorld"
    configurations { "Debug", "Release" }

project "GameRuntime"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/")
    objdir ("%{wks.location}/bin-int/%{prj.name}")

    files 
    {
        "./src/common/**.h", "./src/common/**.cpp",
        "./src/game/**.h", "./src/game/**.cpp",
        "./src/ui/**.h", "./src/ui/**.cpp",
        "./src/runtime/**.h", "./src/runtime/**.cpp",
    }

    filter "system:windows"
        files { }

    filter "system:linux"
        files { }

    includedirs
    {
        "./src/",
    }

    links
    {
        "glfw", "raylib", "GL"
    }

    defines
    {
        
    }

    filter "system:windows"
        systemversion "latest"
        defines { }

    filter "system:linux"
        defines {  }
        libdirs { "/usr/lib", "%{wks.location}/lib/" }
        links { "dl", "m", "pthread" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"


project "Editor"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/")
    objdir ("%{wks.location}/bin-int/%{prj.name}")

    files 
    {
        "./src/common/**.h", "./src/common/**.cpp",
        "./src/game/**.h", "./src/game/**.cpp",
        "./src/ui/**.h", "./src/ui/**.cpp",
        "./src/editor/**.h", "./src/editor/**.cpp",
    }

    filter "system:windows"
        files { }

    filter "system:linux"
        files { }

    includedirs
    {
        "./src/",
    }

    links
    {
        "glfw", "raylib", "GL"
    }

    defines
    {
        
    }

    filter "system:windows"
        systemversion "latest"
        defines { }

    filter "system:linux"
        defines {  }
        libdirs { "/usr/lib", "%{wks.location}/lib/" }
        links { "dl", "m", "pthread" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"    

project "Sandbox"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/")
    objdir ("%{wks.location}/bin-int/%{prj.name}")

    files 
    {
        "./src/common/**.h", "./src/common/**.cpp",
        "./src/game/**.h", "./src/game/**.cpp",
        "./src/ui/**.h", "./src/ui/**.cpp",
        "./src/sandbox/**.h", "./src/sandbox/**.cpp",
    }

    filter "system:windows"
        files { }

    filter "system:linux"
        files { }

    includedirs
    {
        "./src/",
    }

    links
    {
        "glfw", "raylib", "GL"
    }

    defines
    {
        
    }

    filter "system:windows"
        systemversion "latest"
        defines { }

    filter "system:linux"
        defines {  }
        libdirs { "/usr/lib", "%{wks.location}/lib/" }
        links { "dl", "m", "pthread" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"    