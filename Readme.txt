Description:
perm_oj is a project testing permulation algorithms

Installation:
the daemon is developed on *nix like systems to use open source system details, and the web foreui is developed on both *nix like systems and win32 platform, so we recommand you to deploy the programs on some *nix systems.
And we have tested the system on Fedora 18, the evalution is below:
1) Install the deps of libs and web server:
yum install boost-devel libpugi-devel libcurl-devel libmicrohttpd-devel
yum group install "Web Server"
2) Compile:
go to the src/Daemon to complie daemon just run
./compile.sh
in the shell
3) Deployment:
point your apache document root to the dir you place the ForeUI dir
run the ./debug or ./release in src/Daemon dir
3) Lanuch
open http://127.0.0.1 in your browser, and enjoy it!!!


Report Bugs:
the software is still under tested now, so if you have any questions email to pengfeituan@gmail.com
