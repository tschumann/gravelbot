# get the location of this file
$scriptpath = $MyInvocation.MyCommand.Path
# get the directory path to this file
$wd = Split-Path $scriptpath
# set the working directory as this file's directory
Push-Location $wd

# build the solutions
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=win32 /p:Configuration=Debug "bms/gravelbot-2019.sln"
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=win32 /p:Configuration=Debug "darkm/gravelbot-2019.sln"
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=win32 /p:Configuration=Debug "dods/gravelbot-2019.sln"
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=win32 /p:Configuration=Debug "hl2dm/gravelbot-2019.sln"
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=win32 /p:Configuration=Debug "insurgency/gravelbot-2019.sln"
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=win32 /p:Configuration=Debug "sdk2013/gravelbot-2019.sln"

Pop-Location