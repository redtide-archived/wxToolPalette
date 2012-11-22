-----------------------------------------------------------------------------
-- Name:        wxtoolpalette_sample.lua
-- Purpose:     Main application project
-- Author:      Andrea Zanellato
-- Modified by:
-- Created:     19/10/2012
-- Revision:    $Hash$
-- Copyleft:    (ɔ) Andrea Zanellato
-- Licence:     wxWidgets licence
-----------------------------------------------------------------------------
project "wxToolPaletteSample"
    kind                    "WindowedApp"

    files                   {"../../main.cpp"}
    includedirs             { "../../include"}

    defines                 {"NO_GCC_PRAGMA"}
    flags                   {"ExtraWarnings"}
    links                   {"wxToolPaletteLib"}

    targetname              "toolpalette"

    configuration {"codelite", "not windows"}
        linkoptions         {"-Wl,-rpath,$$``ORIGIN/../lib"}

    configuration {"codeblocks", "not windows"}
        linkoptions         {"-Wl,-rpath,$``ORIGIN/../lib"}

    configuration "macosx"
        linkoptions         {"-L../../output/lib"}

    configuration {"macosx", "Debug"}
        postbuildcommands   {"../macosx/postbuildd.sh"}

    configuration {"macosx", "Release"}
        postbuildcommands   {"../macosx/postbuild.sh"}

    configuration "not windows"
        excludes            {"../../src/*.rc"}
        libdirs             {"../../output/lib"}
        targetdir           "../../output/bin"

    configuration "windows"
        files               {"../../*.rc"}
        libdirs             {"../../output"}
        targetdir           "../../output"

    if wxCompiler == "gcc" then
        buildoptions    {"-gstabs"}
        links           {"bfd", "iberty", "psapi", "imagehlp"}
    end

    configuration "Debug"
        wx_config           { Libs="core", Debug="yes" }

    configuration "Release"
        wx_config           { Libs="core" }
