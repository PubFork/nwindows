CC        = g++
WCC       = x86_64-w64-mingw32-g++ 
CFLAGS    = -Wall -std=c++11 
LIBS      = -lncurses
WLIBS     = -lncursesw
SRCS      = $(wildcard src/*.cpp)
HDRS      = $(patsubst src/%.cpp,src/%.h,$(SRCS))
OBJS      = $(patsubst src/%.cpp,bin/%.o,$(SRCS))
WOBJS     = $(patsubst src/%.cpp,dll/%.o,$(SRCS))
SRCDIR    = src/
OBJDIR    = bin/
WOBJDIR   = dll/
BIN       = demo
EXE       = demo.exe

all : $(BIN) $(EXE)

#WINDOWS
$(EXE) : $(WOBJS)
	$(WCC) -o $(EXE) $^ $(WLIBS)

$(WOBJDIR)%.o : $(SRCDIR)%.cpp
	$(WCC)  -c $< -o $@ $(CFLAGS)

#UNIX
$(BIN) : $(OBJS) 
	$(CC) -o  $(BIN)  $^ $(LIBS)

#Header files are in src directory
#Lesson:  % pattern must match on both sides
$(OBJDIR)%.o : $(SRCDIR)%.cpp $(HDRS)
	$(CC)  -c $< -o $@ $(CFLAGS)

clean :
	rm $(OBJDIR)*.o
	rm $(WOBJDIR)*.o
