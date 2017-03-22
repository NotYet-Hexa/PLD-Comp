.PHONY : clean test

VPATH = src:build

CC = g++
REMOVE = rm -f
DEBUG_FLAG = -g -O0 -D DEBUG
CFLAGS = -std=c++11
LDFLAGS = -std=c++11
EXEC = exe
LINK = -o
OUTPUT = -o

BUILDFOLDER = build
SRCFOLDER = src

OUTBUILD = $(OUTPUT) $(BUILDFOLDER)/$(shell basename $@)

OBJFILE = o

FLEX_FILES = $(wildcard src/*.l)
BISON_FILES = $(wildcard src/*.y)

FLEX_RESULT = src/lex.yy.c

SRCCPP = $(filter-out $(SRCFOLDER)/main.cpp, $(wildcard src/*.cpp))
SRCH = $(wildcard src/*.h)
SRC = $(BISON_FILES) $(FLEX_FILES) $(SRCCPP) $(SRCH) $(FLEX_RESULT) $(BISON_FILES:.y=.tab.h)
OBJ_TMP = $(BISON_FILES:.y=.tab.$(OBJFILE)) $(FLEX_RESULT:.c=.$(OBJFILE)) $(SRCCPP:.cpp=.$(OBJFILE))
OBJ = $(OBJ_TMP:src%=build%)

$(EXEC): $(SRC) $(OBJ)
	g++ $(OBJ) $(OUTBUILD)

# C++ files
$(BUILDFOLDER)/%.$(OBJFILE): $(SRCFOLDER)/%.cpp $(SRCFOLDER)/%.h
	g++ -c $< $(OUTBUILD)

# Bison objets
$(BUILDFOLDER)/%.tab.$(OBJFILE): $(SRCFOLDER)/%.tab.h $(SRCFOLDER)/%.y
	$(eval TMP=$<)
	g++ -c $(TMP:.h=.c) $(OUTBUILD)

# Bison files .y
%.tab.h: %.y
	$(eval TMP=$@)
	bison -v --defines=$@ $< -o $(TMP:.h=.c)

# lex.yy.o ← lex.yy.c
$(BUILDFOLDER)/%.$(OBJFILE): $(SRCFOLDER)/%.c
	g++ -c $< $(OUTBUILD)

# lex.yy.c ← *.l
$(FLEX_RESULT): $(FLEX_FILES)
	flex -o $@ $(FLEX_FILES) 

clean:
	cd build; $(REMOVE) *.$(OBJFILE) $(EXEC) 
	cd src; $(REMOVE) *.tab.* *.output lex.*


test: $(EXEC)
	@echo "Lancement des tests ..."
	@tests/run.sh