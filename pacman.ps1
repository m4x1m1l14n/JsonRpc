# Find available compilers
function Get-CompilerPath {
    # TODO Implement search for compiler
    return 'c:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe'
}

Clear-Host

$PackageFilePath = Join-Path -Path $PSScriptRoot -ChildPath ".\package.json"

$FileContent = Get-Content -Path $PackageFilePath -Raw

$Package = ConvertFrom-Json $FileContent

$CompilerPath = Get-CompilerPath

$Includes = @()
$Package.includes | ForEach-Object {
    $Includes += $(Join-Path $PSScriptRoot $_)
}

$Sources = @()
$Package.sources | ForEach-Object {
    $Sources += $(Join-Path $PSScriptRoot $_)
}

$CompilerPath = "c:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\VC\Tools\MSVC\14.16.27023\bin\Hostx64\x64\cl.exe"

$Params = @()
$Params += '/c'
$Includes | ForEach-Object {
    $Params += "/I `"$($_ -replace ".$")`""
}
$Sources | ForEach-Object {
    $Params += $_
}

$Params

"$CompilerPath $Params"

& $CompilerPath $Params
