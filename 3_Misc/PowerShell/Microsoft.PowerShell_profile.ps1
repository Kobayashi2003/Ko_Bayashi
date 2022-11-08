$My_Script_Path = 'C:\Users\KOBAYASHI\Documents\WindowsPowerShell\Microsoft.PowerShell_profile.ps1'

# Start or Kill a Process
function _Start_and_Kill($app_path, $state="start") {
    # echo $app_path $state
    $app_name = ($app_path.Split("\")[-1]).Split(".")[-2]
    if ($state -eq "start") { # Start Process
        echo "$app_name Run"
        # Start-Process
        start $app_path
    } elseif ($state.startswith("k")) { # Kill Process
        echo "$app_name Kill"
        kill -ProcessName $app_name
    } elseif ($state.startswith("p")) { # show the paths
        echo $app_path
    }
}

# A function for editing this Sctipt
function _Edit_My_Script {
    powershell_ise $My_Script_Path
}

# A function for showing all current Paths
function _Show_Path() {
    # echo $My_Script_Path
    echo "===================="
    (Get-Content -Path $My_Script_Path -Raw).Split(";")[-1] | echo
    echo "===================="
}

# A funtion for deleting Paths
function _Delete_Path($app_name="") {
    # clc -Path C:\Users\KOBAYASHI\Desktop\test.ps1 -Include "function"
    if ($app_name -eq "") {
        echo "You have to enter an app name"
        return
    }
    $pattern1 = "# $app_name"
    $content1 = Select-String -Path $My_Script_Path -Pattern $pattern1
    $line1 = $content1.ToString().Split(":")[-2] - 1

    $pattern2 = "# END $app_name"
    $content2 = Select-String -Path $My_Script_Path -Pattern $pattern2
    $line2 = $content2.ToString().Split(":")[-2] - 1

    $len = $line2 - $line1 + 1

    # echo $line1 $line2 $len

    $old_content = Get-Content -Path $My_Script_Path -ReadCount 0
    $new_content = @()
    for($i = 0; $i -lt $old_content.Length; $i += 1) {
        if ($i -gt $line1-1 -and $i -lt $line1+$len+1 ) {
            # echo $old_content[$i]
        } else {
            $new_content += $old_content[$i]
        }
    }
    # echo $new_content
    Set-Content -Path $My_Script_Path -Value $new_content
    echo "Path Deleted"
}

# A function for adding new Paths
function _Add_Path($app_name="", $app_path="") {

    if ($app_name -eq "") {
        echo "You have to enter an app name"
        return
    }
    if($app_path -eq "") {
        echo "You have to enter the path of app"
        return
    }

    $content = Get-Content $My_Script_Path
    if ("# $app_name" -in $content) {
        echo "This path already exists. Do you want to overwrite it? [Y/N]"
        $judge = Read-Host
        if ($judge -eq "Y") {
            _Delete_Path $app_name
        } else {
            return
        }
    }
    Add-Content $My_Script_Path "`n# $app_name`nfunction $app_name(`$state`=`"start`") {`n    `$app_path = $app_path`n    _Start_and_Kill `$app_path `$state`n}`n`# END $app_name"
    echo "New Path Added"
}

;
### User's Paths ###

# Clash for Windows
function Clash($state="start") {
    $app_path = 'D:\Item\Clash for Windows\Clash for Windows.exe'
    _Start_and_Kill $app_path $state
}
# END Clash for Windows


# Free Download Manager
function FDM($state="start") {
    $app_path = 'D:\Item\Free Download Manager\fdm.exe'
    _Start_and_Kill $app_path $state
}
# END Free Download Manager


# Everything
function Everything($state="start") {
    $app_path = 'D:\Item\Everything\Everything.exe'
    _Start_and_Kill $app_path $state
}
# END Everything


# ShareMouse
function ShareMouse($state="start") {
    if ($state -eq "KEY") {
        echo "SMOENT-DO-AAGEMY-1299-UN-KKPX-QTSX-X9JHRR1LXHX5ZXTB-FEEB32EF75C43CE5F220B324678701CB" | Set-Clipboard
        return
    }
    $app_path = C:\Program Files (x86)\ShareMouse\ShareMouse.exe
    _Start_and_Kill $app_path $state
}
# END ShareMouse
