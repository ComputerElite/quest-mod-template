# Builds a .qmod file for loading with QP
& $PSScriptRoot/build.ps1

Compress-Archive -Path "./libs/arm64-v8a/lib#{id}.so", ".\mod.json" -DestinationPath "./#{id}.zip" -Update
Remove-Item "./#{id}.qmod"
Rename-Item "./#{id}.zip" "./#{id}.qmod"