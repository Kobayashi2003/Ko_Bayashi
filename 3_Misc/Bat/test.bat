    @echo off
    set "TempFile=%temp%\FsutilTemp.txt"

    if not exist "%~1" (
        echo 不存在 "%~1"
        goto :end
    )

    pushd "%~1" 2>nul
    if errorlevel 1 (
        goto :CheckFile
    ) else (
        popd
        goto :CheckFolder
    )

    :CheckFolder
    fsutil reparsepoint query "%~1" >"%TempFile%" 2>&1
    if errorlevel 1 (
        echo 普通文件夹
    ) else (
        goto :CheckJunkFolder
        goto :end
    )

    :CheckJunkFolder
    for /f "skip=3 delims=" %%i in ('type "%TempFile%"') do (
        if "%%i" equ "标记值: 装入点" (
            echo 软链接的文件夹
        ) else if "%%i" equ "标记值: 符号链接" (
            echo 符号链接的文件夹
        )
    )
    goto :end

    :CheckFile
    fsutil reparsepoint query "%~1" >"%TempFile%" 2>&1
    if errorlevel 1 (
        echo 普通文件
    ) else (
        goto :CheckJunkFile
    )
    goto :end

    :CheckJunkFile
    for /f "skip=3 delims=" %%i in ('fsutil reparsepoint query "%~1"') do (
        if "%%i" equ "标记值: 装入点" (
            echo 软链接的文件
        ) else if "%%i" equ "标记值: 符号链接" (
            echo 符号链接的文件
        )
    )
    goto :end

    :end
    pause