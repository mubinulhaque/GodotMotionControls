#!/usr/bin/env python

libname = "libgdmotioncontrols"

env = SConscript("godot-cpp/SConstruct")

env.Append(LIBPATH=["sdl/lib"])
env.Append(CPPPATH=["src/", "sdl/include/"])
if env["platform"] == "windows" and (env['CC'] == 'gcc' or env['CXX'] == 'g++'):
    env.Append(LINKFLAGS=["-Wl,--dynamicbase","-Wl,--nxcompat"])
    env.Append(CXXFLAGS =["-mwindows"])
    env.Append(
        LIBS=[
            "libSDL2",
            "libSDL2main",
            "setupapi",
            "winmm",
            "user32",
            "gdi32",
            "dinput8",
            "dxguid",
            "dxerr8",
            "imm32",
            "ole32",
            "version",
            "uuid",
            "m",
            "oleaut32",
            "shell32"
        ]
    )

elif env['CC'] == 'cl':
    env.Append(
        LIBS=[
            "SDL2",
            "SDL2main",
        ]
    )

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
