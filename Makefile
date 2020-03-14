.PHONY: build dploy clean original neo

clean:
	sudo rm -f /lib/aarch64-linux-gnu/libz.so.1.2.11
	sudo rm -f /lib/aarch64-linux-gnu/libz.so.1
	sudo rm -f /lib/aarch64-linux-gnu/libz.so

original: clean
	sudo ln -s /lib/aarch64-linux-gnu/libz_original.so /lib/aarch64-linux-gnu/libz.so.1.2.11
	sudo ln -s /lib/aarch64-linux-gnu/libz_original.so /lib/aarch64-linux-gnu/libz.so.1
	sudo ln -s /lib/aarch64-linux-gnu/libz_original.so /lib/aarch64-linux-gnu/libz.so

neo: clean
	sudo ln -s /lib/aarch64-linux-gnu/libz_neo.so /lib/aarch64-linux-gnu/libz.so.1.2.11
	sudo ln -s /lib/aarch64-linux-gnu/libz_neo.so /lib/aarch64-linux-gnu/libz.so.1
	sudo ln -s /lib/aarch64-linux-gnu/libz_neo.so /lib/aarch64-linux-gnu/libz.so

build:
	rm -rf build
	mkdir build
	(cd build && cmake -DARMV8=on -DRELEASE=on -DVERBOSE=off .. && make -j `nproc`)

debug:
	rm -rf build && mkdir build
	(cd build && cmake -DARMV8=on -DRELEASE=off -DVERBOSE=on .. && make -j `nproc`)

deploy:
	strip build/minigzip* build/libz.so.1.2.11
	rm -f ~/.local/bin/minigzip*
	sudo rm -f /lib/aarch64-linux-gnu/libz_neo.so
	sudo cp build/minigzip* ~/.local/bin
	sudo cp build/libz.so.1.2.11 /lib/aarch64-linux-gnu/libz_neo.so
	mv build/libz.so.1.2.11 build/libz.so.1.2.11.bak


