# get the location of this file
$scriptpath = $MyInvocation.MyCommand.Path
# get the directory path to this file
$wd = Split-Path $scriptpath
# set the working directory as this file's directory
Push-Location $wd

# build the solutions
Write-Output "Building bms (Debug)"
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=win32 /p:Configuration=Debug "bms/gravelbot-2019.sln"
if(!$?)
{
	Write-Error "Error building bms (Debug)"
	exit
}
Write-Output "Building darkm (Debug)"
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=win32 /p:Configuration=Debug "darkm/gravelbot-2019.sln"
if(!$?)
{
	Write-Error "Error building darkm (Debug)"
	exit
}
Write-Output "Building dods (Debug)"
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=win32 /p:Configuration=Debug "dods/gravelbot-2019.sln"
if(!$?)
{
	Write-Error "Error building dods (Debug)"
	exit
}
Write-Output "Building hl2dm (Debug)"
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=win32 /p:Configuration=Debug "hl2dm/gravelbot-2019.sln"
if(!$?)
{
	Write-Error "Error building hl2dm (Debug)"
	exit
}
Write-Output "Building insurgency (Debug)"
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=win32 /p:Configuration=Debug "insurgency/gravelbot-2019.sln"
if(!$?)
{
	Write-Error "Error building insurgency (Debug)"
	exit
}
Write-Output "Building sdk2013 (Debug)"
& "C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\MSBuild\Current\Bin\MSBuild.exe" /t:Build /p:Platform=win32 /p:Configuration=Debug "sdk2013/gravelbot-2019.sln"
if(!$?)
{
	Write-Error "Error building sdk2013 (Debug)"
	exit
}

Copy-Item -Path bms\Debug\gravelbot.dll -Destination gravelbot\bms\addons\
Copy-Item -Path bms\Debug\gravelbot.dll -Destination gravelbot\dod\addons\
Copy-Item -Path bms\Debug\gravelbot.dll -Destination gravelbot\hl2dm\addons\

Pop-Location