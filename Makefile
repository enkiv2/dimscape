all: clean src

clean: qtclean
	rm -f *.o

src: cellsrc qtsrc

cellsrc: 
	gcc -Wall  -c -I. -o Cell.o Cell.cpp

dist:
	cd ..
	tar -cz qtzz > qtzz.tgz

commit:
	svn commit

update:
	svn update

qtsrc: Makefile.qt
	make -f Makefile.qt

qtclean: Makefile.qt
	make -f Makefile.qt clean

Makefile.qt:
	qmake qtzz.pro -o Makefile.qt

