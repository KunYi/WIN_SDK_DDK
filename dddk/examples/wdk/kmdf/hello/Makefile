WINE = myx86.sh
QEMU = myqemu.sh
OS   = win7_nano

all:
	${WINE} make.bat

run:
	rm -rf cdrom.iso
	genisoimage -o cdrom.iso autorun.inf main.sys main.inf run.bat
	${QEMU} ${OS}

clean:
	rm -rf main.sys main.obj main.pdb app.obj app.pdb app.exe cdrom.iso
