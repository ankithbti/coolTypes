###############
## Makefile
###############

BIN=../bin/Binary
SHARED_LIB=../lib/libCoolTypes.so
STATIC_LIB=../lib/libCoolTypes.a
BOOST_BASE=${BOOST_INSTALL_ROOT}

ARCH = $(shell uname -m)	# ARCH becomes the output from the uname -m command.
CXX=/usr/bin/g++
CXXFLAGS=-fPIC -g -O2 -Wall $(INCS) -arch $(ARCH) -std=c++0x

SRCS = CallbackInterface.cpp Callback.cpp

OBJS = $(patsubst %.cpp, %.o, $(SRCS))
MAIN_OBJ = $(patsubst %.cpp, %.o, $(MAIN_SRC))

INCS = -I../include \
       -I$(BOOST_BASE)/include \

LIBS = \
	-L${BOOST_BASE}/lib -lboost_system \
        -L${BOOST_BASE}/lib -lboost_thread \
	-lpthread
	
$(BIN): $(OBJS) $(MAIN_OBJ)
	$(CXX) -o $(BIN) $(OBJS) $(MAIN_OBJ) $(LIBS)

$(STATIC_LIB): $(OBJS)
	/usr/bin/ar rcs $(STATIC_LIB) $(OBJS)

$(SHARED_LIB): $(OBJS)
	$(CXX) -shared $^ -o $@ $(LIBS)

all: $(SHARED_LIB) $(STATIC_LIB)
	
clean:
	rm -rf $(BIN) *.o $(STATIC_LIB) $(SHARED_LIB)
