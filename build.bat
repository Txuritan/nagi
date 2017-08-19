@echo off
setlocal EnableDelayedExpansion
setlocal EnableExtensions

set bashEXE=C:\msys64\usr\bin\bash

set setupOrBuild=%1
set gccClang=%2

echo Nagi build script v1.0.0
echo Flags %setupOrBuild%, %gccClang%

if !setupOrBuild! EQU setup (
    echo Moving to root of the C drive
    cd C:\

    echo Downloading Msys2
    set MSYS2_URL="https://downloads.sourceforge.net/project/msys2/Base/x86_64/msys2-base-x86_64-20161025.tar.xz"
    appveyor DownloadFile %MSYS2_URL% -FileName msys2-base-x86_64-20161025.tar.xz

    echo Unpacking Msys2
    7z -y e msys2-base-x86_64-20161025.tar.xz  && 7z -y x msys2-base-x86_64-20161025.tar

    echo Tell pacman to install required packages
    %bashEXE% --login -c "pacman -S --noconfirm mingw-w64-x86_64-gtkmm3 mingw-w64-x86_64-toolchain base-devel mingw-w64-x86_64-cmake mingw-w64-x86_64-clang"

) else (
    set MSYS2_BIN="C:\msys64\mingw64\bin"

    if !a! EQU build (
        cd %APPVEYOR_BUILD_FOLDER%

        mkdir build-windows-gcc
        echo Building for Windows with GCC
        %bashEXE% --login -c "cd /c/projects/nagi/build-windows-gcc && cmake .. -G \"MSYS Makefiles\" && cmake --build . --config Release"
        %bashEXE% --login -c "ls -a"

        cd .. && mkdir gcc
        echo Copying "nagi.exe" to "gcc"
        copy C:\projects\nagi\build-windows-gcc\nagi.exe C:\projects\nagi\gcc\nagi.exe

        call C:\projects\nagi\build.bat deps gcc

        cd ..

        echo Creating GCC zip archive
        7z a nagi-windows-gcc.zip ./gcc/*

        mkdir build-windows-clang
        echo Building for Windows with Clang
        %bashEXE% --login -c "cd /c/projects/nagi/build-windows-clang && export C=C:\msys64\mingw64\bin\clang.exe CC=C:\msys64\mingw64\bin\clang.exe CXX=C:\msys64\mingw64\bin\clang++.exe && cmake .. -G \"MSYS Makefiles\" && cmake --build . --config Release"
        %bashEXE% --login -c "ls -a"

        cd .. && mkdir clang
        echo Copying "nagi.exe" to "clang"
        copy C:\projects\nagi\build-windows-clang\nagi.exe C:\projects\nagi\clang\nagi.exe

        call C:\projects\nagi\build.bat deps clang

        cd ..

        echo Creating Clang zip archive
        7z a nagi-windows-clang.zip ./clang/*
    )

    if !a! EQU deps (
        set depsList=libatk-1.0-0.dll libatkmm-1.6-1.dll libbz2-1.dll libcairo-2.dll libcairo-gobject-2.dll libcairomm-1.0-1.dll libcurl-4.dll libeay32.dll libepoxy-0.dll libexpat-1.dll libffi-6.dll libfontconfig-1.dll libfreetype-6.dll libgcc_s_seh-1.dll libgdk-3-0.dll libgdkmm-3.0-1.dll libgdk_pixbuf-2.0-0.dll libgio-2.0-0.dll libgiomm-2.4-1.dll libglib-2.0-0.dll libglibmm-2.4-1.dll libgmodule-2.0-0.dll libgmp-10.dll libgnutls-30.dll libgobject-2.0-0.dll libgraphite2.dll libgtk-3-0.dll libgtkmm-3.0-1.dll libharfbuzz-0.dll libhogweed-4.dll libiconv-2.dll libidn-11.dll libintl-8.dll libnettle-6.dll libnghttp2-14.dll libp11-kit-0.dll libpango-1.0-0.dll libpangocairo-1.0-0.dll libpangoft2-1.0-0.dll libpangomm-1.4-1.dll libpangowin32-1.0-0.dll libpcre-1.dll libpixman-1-0.dll libpng16-16.dll librtmp-1.dll libsigc-2.0-0.dll libssh2-1.dll libstdc++-6.dll libtasn1-6.dll libunistring-2.dll libwinpthread-1.dll nagi.exe ssleay32.dll zlib1.dll
        echo Copying dependencies for %gccClang%
        (for %%a in (%depsList%) do (
            copy %MSYS2_BIN%\%%a C:\projects\nagi\%gccClang%\%%a
        ))

        echo Copying "share"
        copy C:\projects\nagi\resources\share C:\projects\nagi\%gccClang%\share
    )
)

