@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by PIANO.HPJ. >"hlp\piano.hm"
echo. >>"hlp\piano.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\piano.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\piano.hm"
echo. >>"hlp\piano.hm"
echo // Prompts (IDP_*) >>"hlp\piano.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\piano.hm"
echo. >>"hlp\piano.hm"
echo // Resources (IDR_*) >>"hlp\piano.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\piano.hm"
echo. >>"hlp\piano.hm"
echo // Dialogs (IDD_*) >>"hlp\piano.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\piano.hm"
echo. >>"hlp\piano.hm"
echo // Frame Controls (IDW_*) >>"hlp\piano.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\piano.hm"
REM -- Make help for Project PIANO


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\piano.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\piano.hlp" goto :Error
if not exist "hlp\piano.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\piano.hlp" Debug
if exist Debug\nul copy "hlp\piano.cnt" Debug
if exist Release\nul copy "hlp\piano.hlp" Release
if exist Release\nul copy "hlp\piano.cnt" Release
echo.
goto :done

:Error
echo hlp\piano.hpj(1) : error: Problem encountered creating help file

:done
echo.
