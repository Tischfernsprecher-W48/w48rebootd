all:
	gcc w48rebootd.c -o w48rebootd


build-rpi:
	/opt/cross-pi-gcc/bin/arm-linux-gnueabihf-gcc w48rebootd.c -o w48rebootd

clean:
	rm -f w48rebootd *.deb

install:
	echo "run make install-all"

install-all:
	cp -f w48rebootd /usr/sbin
