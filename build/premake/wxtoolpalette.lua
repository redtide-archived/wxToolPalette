-----------------------------------------------------------------------------
-- Name:        toolpalette_lib.lua
-- Purpose:     wxToolPalette library project script.
-- Author:      Andrea Zanellato
-- Modified by:
-- Created:     2012/11/22
-- Revision:    $Hash$
-- Copyleft:    (ɔ) Andrea Zanellato
-- Licence:     wxWidgets licence
-----------------------------------------------------------------------------
project "wxToolPaletteLib"
    kind                    "SharedLib"

    files                   {"../../include/**.h", "../../src/**.cpp"}
    includedirs             {"../../include"}

    defines                 {"WXMAKINGDLL_TOOLPALETTE"}
    flags                   {"ExtraWarnings"}

    targetname              "toolpalette"

    configuration "not windows"
        libdirs             {"../../output/lib"}
        targetdir           "../../output/lib"

    configuration "windows"
        libdirs             {"../../output"}
        targetdir           "../../output"
        targetprefix        "lib"

    configuration "vs*"
        defines             {"_CRT_SECURE_NO_DEPRECATE"}

    configuration "Debug"
        wx_config           { Libs="core", Debug="yes" }

    configuration "Release"
        wx_config           { Libs="core" }
