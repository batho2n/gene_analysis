

install:
	cd src && make install 
	mkdir -p bin
	cp src/gene_tester.exe ./bin

clean:
	cd src && make clean
	rm -rf bin

test:
	./bin/gene_tester.exe --input data/ECKDA5vsECWT.txt::data/ECKDS23vsECWT.txt data/ --type intersect::GeneName --output output.txt

.PHONY: install clean test; 
