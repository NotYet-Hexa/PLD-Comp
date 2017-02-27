.PHONY : all debug
REMOVE = rm -f
CC = g++
DEBUG_FLAG = -g -O0 -D DEBUG
CFLAGS = -std=c++11
LDFLAGS = -std=c++11
EXEC = exe

SRCCPP =  
SRCCPP_FOLDER = $(wildcard ./*.cpp)
SRCH = 
SRCH_FOLDER = $(wildcard ./*.h)
SRC = $(SRCH) $(SRCH_FOLDER) $(SRCCPP) $(SRCCPP_FOLDER)
OBJ = $(SRCCPP:.cpp=.o) $(SRCCPP_FOLDER:./%.cpp=%.o)

DEBUGFILE = .debug
CLEANFILES = $(EXEC) $(DEBUGFILE) *.o

# if last was debug recompile
all: testall $(EXEC)
testall:
	@test -f $(DEBUGFILE) && $(REMOVE) $(CLEANFILES) || echo "Last compilation was release mode"


debug: testdebug $(EXEC)
testdebug:
	$(eval CFLAGS += $(DEBUG_FLAG))
	$(eval LDFLAGS += $(DEBUG_FLAG))
	@test -f $(DEBUGFILE) && echo "Last compilation was debug mode" || $(REMOVE) $(CLEANFILES)
	@echo "Last compilation was debug mode" > $(DEBUGFILE)

$(EXEC): $(OBJ) $(SRC)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# file in current folder
%.o: %.cpp %.h
	$(CC) -c $(CFLAGS) $< 


# file in Etats folder
%.o: Etats/%.cpp Etats/%.h
	$(CC) -c $(CFLAGS) $< 

# main
%.o: %.cpp
	$(CC) -c $(CFLAGS) $< 	

clean:
	$(REMOVE) $(CLEANFILES)

FORCE: