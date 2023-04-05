project "sfml-primitives"
   kind "StaticLib"

   language "C++"
   cppdialect "C++17"
   staticruntime "on"

   targetdir("bin/" .. outputdir)
   objdir("build/" .. outputdir)

   files {"src/**.cpp", "include/**.hpp"}
   includedirs "../**/include"