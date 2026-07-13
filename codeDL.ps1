
$dest = (Get-Location).Path

curl.exe -L "https://github.com/Kiliken/ue5-cmdlineTools-setup/archive/refs/heads/main.tar.gz" -o "$($dest)\main.tar.gz" --progress-bar

tar -xzf "$($dest)\main.tar.gz" -C "$($dest)"

Move-Item "$($dest)\ue5-cmdlineTools-setup-main\*" "$($dest)" -Force
Remove-Item "$($dest)\ue5-cmdlineTools-setup-main" -Recurse -Force
Remove-Item "$($dest)\main.tar.gz" -Force
Rename-Item "$($dest)\gitignore.txt" ".gitignore"
