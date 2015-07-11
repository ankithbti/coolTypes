all:
	(cd src; make -f Makefile all)
	(cd gtest; make -f Makefile all)
clean:
	(cd src; make -f Makefile clean)
	(cd gtest; make -f Makefile clean)
