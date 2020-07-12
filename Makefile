#rumana khan
#hw9 


CC  = g++
CXX = g++

INCLUDES = 

CFLAGS   = -Wall $(INCLUDES)
CXXFLAGS = -Wall $(INCLUDES)

LDFLAGS =
LDLIBS = 

executables = test1 test2 test3
objects = jumbo.o general.o test1.o test2.o test3.o

.PHONY: default 
default: $(executables)

$(executables): jumbo.o commuter.o hopper.o

$(objects): jumbo.h commuter.h hopper.h


.PHONY: clean 
clean:
	rm -f *~ a.out core $(objects) $(executables)

.PHONY: all
all: clean default

