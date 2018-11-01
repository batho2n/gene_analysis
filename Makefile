

install:
	cd src && make install 
	mkdir -p bin
	cp src/gene_tester.exe ./bin

clean:
	cd src && make clean
	rm -rf bin

test:
	./bin/gene_tester.exe --input data/list.txt --type intersect --output output.txt

.PHONY: install clean test; 
