if (Test-Path "build") {
    Remove-Item -Recurse -Force -Path "build"
}
New-Item -ItemType Directory -Path "build"
Push-Location
Set-Location "build"
cmake .. -A x64
Pop-Location

Get-ChildItem -Path "build" -Filter "*.sln" | Select-Object -First 1 | Invoke-Item
