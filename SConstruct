#!/usr/bin/env python

libname = "libgdmotioncontrols"

env = SConscript("godot-cpp/SConstruct")

env.Append(LIBPATH=["sdl/lib"])
env.Append(LIBS=["mingw32", "SDL2main", "SDL2"])

env.Append(CPPPATH=["src/", "sdl/include/"])
sources = Glob("src/*.cpp")

if env["platform"] == "macos":
    platlibname = "{}.{}.{}".format(libname, env["platform"], env["target"])
    library = env.SharedLibrary(
        "bin/{}.framework/{}".format(platlibname, platlibname),
        source=sources,
    )
else:
    library = env.SharedLibrary(
        "bin/{}{}{}".format(libname, env["suffix"], env["SHLIBSUFFIX"]),
        source=sources,
    )

Default(library)