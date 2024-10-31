@echo off
setlocal enabledelayedexpansion

REM 固件版本
set "filename=..\rules.mk"
set "key=SOFTWARE_VERSION"
set "fw_version="

for /f "tokens=*" %%i in ('findstr /C:"%key% =" "%filename%"') do (
    set "line=%%i"
    for /f "tokens=2 delims== " %%j in ("!line!") do (
        set "fw_version=%%j"
    )
)

echo fw_version = %fw_version%

REM 获取当前脚本所在路径的上一级目录的全路径名称
for %%I in ("%~dp0..") do set "parent_path=%%~fI"

REM 判断此路径名称是否包含qmk_firmware\keyboards
echo %parent_path% | find /i "keyboards" > nul
if not errorlevel 1 (
    REM 如果包含此路径段则截取qmk_firmware\keyboards路径后面的内容
    set "new_path=%parent_path:*keyboards\=%"
) else (
    REM 如果不包含，则直接使用原始路径
    set "new_path=%parent_path%"
)

REM 获取新路径的最后一个目录名
for %%B in ("%new_path%") do set "last_folder=%%~nxB"

REM 将新路径中的\替换为_
set "new_path=!new_path:\=_!"

REM 将替换后的路径增加_voe的后缀
set "new_path=%new_path%_via"

echo %new_path%

REM 拷贝新的固件
copy /y ..\..\..\..\.build\.bin\%new_path%_v%fw_version%.hex .\%last_folder%_%date:~0,4%%date:~5,2%%date:~8,2%_v%fw_version%.hex

endlocal
