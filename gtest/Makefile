###############
## Makefile
###############

BIN=../bin/TestBinary
GTEST_BASE = ${GTEST_ROOT}
GMOCK_BASE = ${GMOCK_ROOT}

##ARCH = $(shell uname -m)	# ARCH becomes the output from the uname -m command.
CXX=/usr/bin/g++
CXXFLAGS=-g -O2 -Wall -I$(GTEST_ROOT)/include -D_REENTRANT $(INCS) -std=c++0x

SRCS = CallbackTest.cpp

OBJS = $(patsubst %.cpp, %.o, $(SRCS))

INCS = -I../include \
       -I$(BOOST_INSTALL_ROOT)/include \

LIBS = \
	-L${BOOST_INSTALL_ROOT}/lib -lboost_system \
    	-L${BOOST_INSTALL_ROOT}/lib -lboost_thread \
	../lib/libCoolTypes.a \
        ${GMOCK_ROOT}/gtest/make/gtest.a \
        ${GMOCK_ROOT}/make/gmock.a \
	-lpthread

$(BIN): $(OBJS)
	$(CXX) -o $(BIN) $(OBJS) $(LIBS)

all: $(BIN) run

run:
	@echo "----------------------------"
	@echo "Running the TestCases. "
	@echo "----------------------------"
	$(BIN)
	@echo "----------------------------"

clean:
	rm -rf $(BIN) *.o
