:define
@echo off
cls
color 0a
title Global.exe 病毒专杀工具______________冷轧电气：常江
rem ptcd_hdd="protected_harddisk"
rem ptcd_usb="protected_usbdevice"
cls
echo.
echo.                    欢迎使用
echo.==============================================
echo.         Global.exe 病毒专杀工具
echo.
echo.               中毒现象
echo.
echo.         this computer is being attack
echo.                 在屏幕上乱飞
echo.
echo.    提示
echo.    如果不是上述情况请不要使用本脚本
echo.    本脚本有一定的危险性 请慎重使用
echo.    以免造成不必要的损失
echo.    使用时请确定WINDOWS安装在C盘 否则可能无法删除
echo.
echo.==============================================
echo.下一步后进入杀毒主界面
pause
rem 版本：1326985 _0323
:main
cls
echo ===================================
echo.
echo. 建议在安全模式下杀毒
echo.
echo. 输入Y查杀本机病毒
echo. 输入U查杀U盘病毒
echo. 输入R重启计算机
echo. 输入Q退出本程序
echo.
echo ===================================
set /p c=(y/u/r/q/n)
if "%c%" == "y" goto begin
if "%c%" == "u" goto usb
if "%c%" == "r" goto restart
if "%c%" == "q" goto end
goto main
:begin
cls
taskkill /f /im Global.exe
taskkill /f /im Fonts.exe
del /f /a /q %systemroot%\Cursors\Boom.vbs
del /f /a /q %systemroot%\Help\microsoft.hlp
del /f /a /q %systemroot%\pchealth\Global.exe
del /f /a /q %systemroot%\pchealth\helpctr\binaries\HelpHost.com
del /f /a /q %systemroot%\system\KEYBOARD.exe
del /f /a /q %systemroot%\Help\microsoft.hlp
del /f /a /q %systemroot%\system32\regedit.exe
del /f /a /q %systemroot%\system32\drivers\drivers.cab.exe
del /f /a /q %systemroot%\system32\dllcache\autorun.inf
del /f /a /q %systemroot%\system32\dllcache\Default.exe
del /f /a /q %systemroot%\system32\dllcache\svchost.exe
del /f /a /q %systemroot%\system32\dllcache\Global.exe
del /f /a /q %systemroot%\system32\dllcache\tskmgr.exe
del /f /a /q %systemroot%\system32\dllcache\explorer.exe
del /f /a /q %systemroot%\system32\dllcache\rndll32.exe
del /f /a /q %systemroot%\system32\dllcache\Recycler.{645FF040-5081-101B-9F08-00AA002F954E}\system.exe
del /f /a /q %systemroot%\system32\dllcache\Recycler.{645FF040-5081-101B-9F08-00AA002F954E}\Global.exe
del /f /a /q %systemroot%\system32\dllcache\Recycler.{645FF040-5081-101B-9F08-00AA002F954E}\svchost.exe
del /f /a /q %systemroot%\Fonts\tskmgr.exe
del /f /a /q %systemroot%\Fonts\Fonts.exe
del /f /a /q %systemroot%\Media\rndll32.pif
del /f /a /q %systemroot%\Cursors\Boom.vbs
del /f /a /q %systemroot%\system32\dllcache\Recycler.{645FF040-5081-101B-9F08-00AA002F954E}
::生成注册表恢复文件
@echo.Windows Registry Editor Version 5.00>kregvir.reg
@echo.; 清除病毒屏保>>kregvir.reg
@echo.[HKEY_CURRENT_USER\Control Panel\Desktop]>>kregvir.reg
@echo."ScreenSaveTimeOut"="600">>kregvir.reg
@echo."SCRNSAVE.EXE"=->>kregvir.reg
@echo."AutoEndTasks"="0">>kregvir.reg
@echo.; 修复文件关联>>kregvir.reg
@echo.@echo.[HKEY_CLASSES_ROOT\MSCFile\Shell\Open\Command]>>kregvir.reg
@echo.@="%SystemRoot%\system32\mmc.exe \"%1\" %*">>kregvir.reg
@echo.[HKEY_LOCAL_MACHINE\SOFTWARE\Classes\MSCFile\Shell\Open\Command]>>kregvir.reg
@echo.@="%SystemRoot%\system32\mmc.exe \"%1\" %*">>kregvir.reg
@echo.[HKEY_CLASSES_ROOT\regedit\shell\open\command]>>kregvir.reg
@echo.@="regedit %1">>kregvir.reg
@echo.[HKEY_CLASSES_ROOT\regfile\shell\open\command]>>kregvir.reg
@echo.@="regedit \"%1\"">>kregvir.reg
@echo.[HKEY_LOCAL_MACHINE\SOFTWARE\Classes\regedit\shell\open\command]>>kregvir.reg
@echo.@="regedit %1">>kregvir.reg
@echo.[HKEY_LOCAL_MACHINE\SOFTWARE\Classes\regfile\shell\open\command]>>kregvir.reg
@echo.@="regedit \"%1\"">>kregvir.reg
@echo.>>kregvir.reg
@echo.; 删除开关机脚本>>kregvir.reg
@echo.[-HKEY_CURRENT_USER\Software\Policies\Microsoft\Windows\System\Scripts]>>kregvir.reg
@echo.[-HKEY_LOCAL_MACHINE\SOFTWARE\Policies\Microsoft\Windows\System\Scripts]>>kregvir.reg
@echo.>>kregvir.reg
@echo.; 恢复显示com和exe的扩展名>>kregvir.reg
@echo.[HKEY_LOCAL_MACHINE\SOFTWARE\Classes\comfile]>>kregvir.reg
@echo."NeverShowExt"=->>kregvir.reg
@echo.[HKEY_LOCAL_MACHINE\SOFTWARE\Classes\exefile]>>kregvir.reg
@echo."NeverShowExt"=->>kregvir.reg
@echo.>>kregvir.reg
@echo.; 清除启动项>>kregvir.reg
@echo.[HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\RunOnce]>>kregvir.reg
@echo.@=->>kregvir.reg
@echo."%systemroot%\system\KEYBOARD.exe"=->>kregvir.reg
@echo.[HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Run]>>kregvir.reg
@echo.@=->>kregvir.reg
@echo.[HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\policies\Explorer\Run]>>kregvir.reg
@echo."sys"=->>kregvir.reg
@echo.[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\RunOnce]>>kregvir.reg
@echo.@=->>kregvir.reg
@echo.>>kregvir.reg
@echo.; 清除映像劫持>>kregvir.reg
@echo.[-HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\ctfmon.exe]>>kregvir.reg
@echo.[-HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\taskmgr.exe]>>kregvir.reg
@echo.[-HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\boot.exe]>>kregvir.reg
@echo.[-HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\autorun.exe]>>kregvir.reg
@echo.[-HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\autoruns.exe]>>kregvir.reg
@echo.[-HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\auto.exe]>>kregvir.reg
@echo.[-HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\msconfig.exe]>>kregvir.reg
@echo.[-HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\procexp.exe]>>kregvir.reg
@echo.>>kregvir.reg
@echo.; 恢复显示系统文件选项相关>>kregvir.reg
@echo.[HKEY_CURRENT_USER\Software\Microsoft\Windows\CurrentVersion\Explorer\Advanced]>>kregvir.reg
@echo."ShowSuperHidden"=dword:00000000>>kregvir.reg
@echo.[HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\Advanced\Folder\SuperHidden]>>kregvir.reg
@echo."ValueName"="ShowSuperHidden">>kregvir.reg
@echo.>>kregvir.reg
@echo.; MUICache>>kregvir.reg
@echo.[HKEY_CURRENT_USER\Software\Microsoft\Windows\ShellNoRoam\MUICache]>>kregvir.reg
@echo."%systemroot%\system32\dllcache\Recycler.{645FF040-5081-101B-9F08-00AA002F954E}\Global.exe"=->>kregvir.reg
@echo."%systemroot%\system32\dllcache\Recycler.{645FF040-5081-101B-9F08-00AA002F954E}\svchost.exe"=->>kregvir.reg
@echo."%systemroot%\system32\dllcache\Recycler.{645FF040-5081-101B-9F08-00AA002F954E}\system.exe"=->>kregvir.reg
@echo."%systemroot%\system32\dllcache\Default.exe"=-"%systemroot%\Fonts\Fonts.exe"=->>kregvir.reg
@echo.>>kregvir.reg
@echo.; Global在干什么在注册表中的信息但不知道是什么>>kregvir.reg
@echo.[HKEY_CURRENT_USER\Software\Microsoft\Internet Explorer\Desktop\Components#CONTENT#]>>kregvir.reg
@echo.@="">>kregvir.reg
@echo."Source"=->>kregvir.reg
@echo."SubscribedURL"=->>kregvir.reg
@echo."FriendlyName"=->>kregvir.reg
@echo."Flags"=->>kregvir.reg
@echo."Position"=->>kregvir.reg
@echo."CurrentState"=->>kregvir.reg
@echo."OriginalStateInfo"=->>kregvir.reg
@echo."RestoredStateInfo"=->>kregvir.reg
@echo.[HKEY_CURRENT_USER\Software\Microsoft\Internet Explorer\Desktop\Components]>>kregvir.reg
@echo."DeskHtmlVersion"=->>kregvir.reg
@echo."Settings"=->>kregvir.reg
@echo."GeneralFlags"=->>kregvir.reg
@echo.[HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\policies\system]>>kregvir.reg
@echo."DisableStatusMessages"=->>kregvir.reg
@echo.>>kregvir.reg
@echo.; 清除残留信息>>kregvir.reg
@echo.[-HKEY_CURRENT_USER\Software\VB and VBA Program Settings]>>kregvir.reg
@echo.[-HKEY_CURRENT_USER\Software\Policies\Microsoft\Windows]>>kregvir.reg
@echo.[-HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\policies\Explorer\Run]>>kregvir.reg
@echo.[-HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\policies\Explorer]>>kregvir.reg
echo.
reg import kregvir.reg
echo.清除病毒屏保
echo.
echo.修复文件关联
echo.
echo.删除开关机脚本
echo.
echo.恢复显示com和exe的扩展名
echo.
echo.清除启动项
echo.
echo.清除映像劫持
echo.
echo.恢复显示系统文件选项相关
echo.
echo.清除残留信息
echo.
cls
del /a /f /q kregvir.reg
cls
del /a /f /s /q *.tmp
del /a /f /s /q *pf
::============================================================
:anti_hdd
cls
echo 请输入除光盘外的最后一个盘符c/d/e/f/g/h/i/j/k/l
echo 反回请输入Q
set /p hd=最后一个盘符为(c/d/e/f/g/h/i/j/k/l/Q)
if "%hd%"=="c" goto hdc
if "%hd%"=="d" goto hdd
if "%hd%"=="e" goto hde
if "%hd%"=="f" goto hdf
if "%hd%"=="g" goto hdg
if "%hd%"=="h" goto hdh
if "%hd%"=="i" goto hdi
if "%hd%"=="j" goto hdj
if "%hd%"=="k" goto hdk
if "%hd%"=="l" goto hdl
if "%hd%"=="q" goto main
goto anti_hdd
:hdc
c:
cd\
del /a /q /f autorun.inf
del /a /q /f MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
cls
echo.
echo.
echo.====================================
echo.
echo.是否为您的硬盘添加保护文件夹
echo.它会降低您的电脑感染AUTO病毒的机率
echo.
set /p hdp=为计算机添加保护文件夹(y/n)
echo.
echo.====================================
if "%hdp%"="y" goto ptcd_hdd
if "%hdp%"="n" goto _begin
goto hdc
:hdd
d:
cd\
del /a /q /f autorun.inf
del /a /q /f MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
goto hdc
:hde
e:
del /a /q /f autorun.inf
del /a /q /f MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
goto hdd
:hdf
f:
del /a /q /f autorun.inf
del /a /q /f MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
goto hde
:hdg
g:
del /a /q /f autorun.inf
del /a /q /f MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
goto hdf
:hdh
h:
del /a /q /f autorun.inf
del /a /q /f MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
goto hdg
:hdi
i:
del /a /q /f autorun.inf
del /a /q /f MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
goto hdh
:hdj
j:
del /a /q /f autorun.inf
del /a /q /f MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
goto hdi
:hdk
k:
del /a /q /f autorun.inf
del /a /q /f MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
goto hdj
:hdl
l:
del /a /q /f autorun.inf
del /a /q /f MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
goto hdk
:ptcd_hdd
cls
echo.开始建立保护文件
if "%hd%"=="c" goto pdc
if "%hd%"=="d" goto pdd
if "%hd%"=="e" goto pde
if "%hd%"=="f" goto pdf
if "%hd%"=="g" goto pdg
if "%hd%"=="h" goto pdh
if "%hd%"=="i" goto pdi
if "%hd%"=="j" goto pdj
if "%hd%"=="k" goto pdk
if "%hd%"=="l" goto pdl
if "%hd%"=="q" goto main
:pdc
c:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在硬盘建立autorun.inf文件夹----完成
goto _begin
:pdd
d:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在硬盘建立autorun.inf文件夹----完成
goto pdc
:pde
e:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在硬盘建立autorun.inf文件夹----完成
goto pdd
:pdf
f:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在硬盘建立autorun.inf文件夹----完成
goto pde
:pdg
g:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在硬盘建立autorun.inf文件夹----完成
goto pdf
:pdh
h:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在硬盘建立autorun.inf文件夹----完成
goto pdg
:pdi
i:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在硬盘建立autorun.inf文件夹----完成
goto pdh
:pdj
j:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在硬盘建立autorun.inf文件夹----完成
goto pdi
:pdk
k:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在硬盘建立autorun.inf文件夹----完成
goto pdj
:pdl
l:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在硬盘建立autorun.inf文件夹----完成
goto pdk
:_begin
echo.restart computer
echo.查杀完成 请重启您的计算机
echo.输入Y立刻重启计算机
echo.输入N稍候手动重启
set /p rs=现在重启动我的计算机(y/n)
if "%rs%"=="y" goto restart
if "%rs%"=="n" goto main
goto _begin
pause
:usb
echo 请输入USB设备的盘符d/e/f/g/h/i/j/k/l
echo 反回请输入Q
set /p ud=USB设备盘符为(d/e/f/g/h/i/j/k/l/Q)
::if "%ud%"=="c" goto kuc
if "%ud%"=="d" goto kud
if "%ud%"=="e" goto kue
if "%ud%"=="f" goto kuf
if "%ud%"=="g" goto kug
if "%ud%"=="h" goto kuh
if "%ud%"=="i" goto kui
if "%ud%"=="j" goto kuj
if "%ud%"=="k" goto kuk
if "%ud%"=="l" goto kul
if "%ud%"=="q" goto main
goto usb
rem :kuc
rem c:
:kud
d:
cls
cd\
del /a /f /q autorun.inf
del /a /f /q MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
del /a /f /q /s recycled\*.*
del /a /f /q /s recycler\*.*
del /a /f /q /s *.tmp
del /a /f /q /s *.pf
cls
echo.为此USB设备添加保护文件请输入A
echo.查杀下一个USB设备添请在输入N后弹出本USB设备并插入下一个USB设备
echo.结束U盘杀毒请输入Q
set /p ku=(a/n/q)
if "%ku%"=="a" goto pud
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto kud
:kue
e:
cls
cd\
del /a /f /q autorun.inf
del /a /f /q MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
del /a /f /q /s recycled\*.*
del /a /f /q /s recycler\*.*
del /a /f /q /s *.tmp
del /a /f /q /s *.pf
cls
echo.为此USB设备添加保护文件请输入A
echo.查杀下一个USB设备添请在输入N后弹出本USB设备并插入下一个USB设备
echo.结束U盘杀毒请输入Q
set /p ku=(a/n/q)
if "%ku%"=="a" goto pue
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto kue
:kuf
f:
cls
cd\
del /a /f /q autorun.inf
del /a /f /q MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
del /a /f /q /s recycled\*.*
del /a /f /q /s recycler\*.*
del /a /f /q /s *.tmp
del /a /f /q /s *.pf
cls
echo.为此USB设备添加保护文件请输入A
echo.查杀下一个USB设备添请在输入N后弹出本USB设备并插入下一个USB设备
echo.结束U盘杀毒请输入Q
set /p ku=(a/n/q)
if "%ku%"=="a" goto puf
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto kuf
:kug
g:
cls
cd\
del /a /f /q autorun.inf
del /a /f /q MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
del /a /f /q /s recycled\*.*
del /a /f /q /s recycler\*.*
del /a /f /q /s *.tmp
del /a /f /q /s *.pf
cls
echo.为此USB设备添加保护文件请输入A
echo.查杀下一个USB设备添请在输入N后弹出本USB设备并插入下一个USB设备
echo.结束U盘杀毒请输入Q
set /p ku=(a/n/q)
if "%ku%"=="a" goto pug
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto kug
:kuh
h:
cls
cd\
del /a /f /q autorun.inf
del /a /f /q MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
del /a /f /q /s recycled\*.*
del /a /f /q /s recycler\*.*
del /a /f /q /s *.tmp
del /a /f /q /s *.pf
cls
echo.为此USB设备添加保护文件请输入A
echo.查杀下一个USB设备添请在输入N后弹出本USB设备并插入下一个USB设备
echo.结束U盘杀毒请输入Q
set /p ku=(a/n/q)
if "%ku%"=="a" goto puh
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto kuh
:kui
i:
cls
cd\
del /a /f /q autorun.inf
del /a /f /q MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
del /a /f /q /s recycled\*.*
del /a /f /q /s recycler\*.*
del /a /f /q /s *.tmp
del /a /f /q /s *.pf
cls
echo.为此USB设备添加保护文件请输入A
echo.查杀下一个USB设备添请在输入N后弹出本USB设备并插入下一个USB设备
echo.结束U盘杀毒请输入Q
set /p ku=(a/n/q)
if "%ku%"=="a" goto pui
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto kui
:kuj
j:
cls
cd\
del /a /f /q autorun.inf
del /a /f /q MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
del /a /f /q /s recycled\*.*
del /a /f /q /s recycler\*.*
del /a /f /q /s *.tmp
del /a /f /q /s *.pf
cls
echo.为此USB设备添加保护文件请输入A
echo.查杀下一个USB设备添请在输入N后弹出本USB设备并插入下一个USB设备
echo.结束U盘杀毒请输入Q
set /p ku=(a/n/q)
if "%ku%"=="a" goto puj
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto kuj
:kuk
k:
cls
cd\
del /a /f /q autorun.inf
del /a /f /q MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
del /a /f /q /s recycled\*.*
del /a /f /q /s recycler\*.*
del /a /f /q /s *.tmp
del /a /f /q /s *.pf
cls
echo.为此USB设备添加保护文件请输入A
echo.查杀下一个USB设备添请在输入N后弹出本USB设备并插入下一个USB设备
echo.结束U盘杀毒请输入Q
set /p ku=(a/n/q)
if "%ku%"=="a" goto puk
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto kuk
:kul
l:
cls
cd\
del /a /f /q autorun.inf
del /a /f /q MS-DOS.com
del /a /f /q recycled.exe
del /a /f /q recycler.exe
del /a /f /q /s recycled\*.*
del /a /f /q /s recycler\*.*
del /a /f /q /s *.tmp
del /a /f /q /s *.pf
cls
echo.为此USB设备添加保护文件请输入A
echo.查杀下一个USB设备添请在输入N后弹出本USB设备并插入下一个USB设备
echo.结束U盘杀毒请输入Q
set /p ku=(a/n/q)
if "%ku%"=="a" goto pul
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto kul
:ptcd_usb
:puc
c:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在USB存储器建立autorun.inf文件夹----完成
echo.继续查杀下一个USB设备请输入n
echo.返回请输入Q
set /p ku=NEXT(n/q)
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto puc
:pud
d:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在USB存储器建立autorun.inf文件夹----完成
echo.继续查杀下一个USB设备请输入n
echo.返回请输入Q
set /p ku=NEXT(n/q)
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto pud
:pue
e:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在USB存储器建立autorun.inf文件夹----完成
echo.继续查杀下一个USB设备请输入n
echo.返回请输入Q
set /p ku=NEXT(n/q)
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto pue
:puf
f:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在USB存储器建立autorun.inf文件夹----完成
echo.继续查杀下一个USB设备请输入n
echo.返回请输入Q
set /p ku=NEXT(n/q)
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto puf
:pug
g:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在USB存储器建立autorun.inf文件夹----完成
echo.继续查杀下一个USB设备请输入n
echo.返回请输入Q
set /p ku=NEXT(n/q)
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto pug
:puh
h:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在USB存储器建立autorun.inf文件夹----完成
echo.继续查杀下一个USB设备请输入n
echo.返回请输入Q
set /p ku=NEXT(n/q)
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto puh
:pui
i:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在USB存储器建立autorun.inf文件夹----完成
echo.继续查杀下一个USB设备请输入n
echo.返回请输入Q
set /p ku=NEXT(n/q)
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto pui
:puj
j:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在USB存储器建立autorun.inf文件夹----完成
echo.继续查杀下一个USB设备请输入n
echo.返回请输入Q
set /p ku=NEXT(n/q)
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto puj
:puk
k:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在USB存储器建立autorun.inf文件夹----完成
echo.继续查杀下一个USB设备请输入n
echo.返回请输入Q
set /p ku=NEXT(n/q)
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto puk
:pul
l:
cd\
md autorun.inf
cd autorun.inf
md changjiang..\
cd\
echo.在USB存储器建立autorun.inf文件夹----完成
echo.继续查杀下一个USB设备请输入n
echo.返回请输入Q
set /p ku=NEXT(n/q)
if "%ku%"=="n" goto usb
if "%ku%"=="q" goto main
goto pul
:restart
cls
set /p ku=重新启动计算机(y/n)
if "%ku%"=="y" shutdown /r /t 10 /c "重启时按 F8 可进入安全模试"
if "%ku%"=="n" goto main
goto restart
:end
exit