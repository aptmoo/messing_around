project "shared"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "off"

    targetdir ("%{wks.location}/lib/")
    objdir ("%{wks.location}/bin-int/%{prj.name}")

    files 
    {
        "../src/common/**.h", "../src/common/**.cpp",
        "../src/ui/**.h", "../src/ui/**.cpp",
    }

    filter "system:windows"
        files { }

    filter "system:linux"
        files { }

    includedirs
    {
        "../src/",
    }

    links
    {
        "glfw", "raylib", "GL", "shared"
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