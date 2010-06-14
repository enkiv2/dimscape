all: clean src

clean:
	rm -f *.o

src:
	gcc -c -I. -o Cell.o Cell.cpp

dist:
	cd ..
	tar -cz qtzz > qtzz.tgz

commit:
	svn commit

update:
	svn update
