all:  src

clean: qtclean
	rm -f *.o Makefile.qt

src:  qtsrc

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

Makefile.qt: FORCE
	qmake qtzz.pro -o Makefile.qt

FORCE:


