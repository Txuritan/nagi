# Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass

$files = Get-ChildItem "C:\Users\txurt\Desktop\nagi"

$output = ""

for ($i=0; $i -lt $files.Count; $i++) {
    $output += $files[$i].Name + " "
}

Add-Content deps.txt $output