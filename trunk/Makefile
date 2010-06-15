all:  src

clean: 
	rm -f *.o Makefile.qt

src:  qtsrc

cellsrc: 
	gcc -Wall  -c -I. -o Cell.o Cell.cpp

dist:
	tar -cz ../dimscape > ../dimscape-`date +%F`.tgz

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


