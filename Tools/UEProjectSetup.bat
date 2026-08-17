@echo off

for /d %%i in ("C:\Program Files\Epic Games\UE_5.*") do (
    if exist "%%i\Engine\Build\BatchFiles\Build.bat" (
        set ueTempPath="%%i\Engine\Templates"
        goto :main
    )
)
for /d %%i in ("D:\Program Files\Epic Games\UE_5.*") do (
    if exist "%%i\Engine\Build\BatchFiles\Build.bat" (
        set ueTempPath="%%i\Engine\Templates"
        goto :main
    )
)

color c
echo Unreal Templates not found.
pause
exit

:main

echo Settingup heavy stuffs...

if not exist %~dp0..\Content md %~dp0..\Content

if exist %~dp0DuperPaoloWolrdContents.tar.gz tar -xzf %~dp0DuperPaoloWolrdContents.tar.gz -C %~dp0..\Content


:: Plugins
if not exist "%~dp0..\Plugins" powershell.exe -NoProfile -ExecutionPolicy Bypass -File "%~dp0PluginsSetup.ps1"


pause
