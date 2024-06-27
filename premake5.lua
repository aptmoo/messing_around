workspace "HelloWorld"
    configurations { "Debug", "Release" }

project "App"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/bin/")
    objdir ("%{wks.location}/bin-int/%{prj.name}")

    files 
    {
        "./src/**.h", "./src/**.cpp",
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