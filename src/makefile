.PHONY : all debug

CC = g++
REMOVE = rm -f
DEBUG_FLAG = -g -O0 -D DEBUG
CFLAGS = -std=c++11
LDFLAGS = -std=c++11
EXEC = exe
LINK = -o

OBJFILE = o

FLEX_FILES = $(wildcard *.l)
BISON_FILES = $(wildcard *.y)

FLEX_RESULT = lex.yy.c

SRCCPP = $(wildcard *.cpp)
SRCH = $(wildcard *.h)
SRC = $(BISON_FILES) $(FLEX_FILES) $(SRCCPP) $(SRCH) $(FLEX_RESULT) $(BISON_FILES:.y=.tab.h)
OBJ = $(BISON_FILES:.y=.tab.$(OBJFILE)) $(FLEX_RESULT:.c=.$(OBJFILE)) $(SRCPP:.cpp=.$(OBJFILE))

$(EXEC): $(SRC) $(OBJ)
	g++ $(OBJ) -o $(EXEC)

# C++ files
%.$(OBJFILE): %.cpp %.h
	g++ -c $<

# Bison objets
%.tab.$(OBJFILE): %.tab.h %.y
	$(eval TMP=$<)
	g++ -c $(TMP:.h=.c)

# Bison files .y
%.tab.h: %.y
	bison -v --defines=$@ $<

# lex.yy.o ← lex.yy.c
%.$(OBJFILE): %.c
	g++ -c $<

# lex.yy.c ← *.l
$(FLEX_RESULT): $(FLEX_FILES)
	flex $(FLEX_FILES)

clean:
	$(REMOVE) *.$(OBJFILE) $(EXEC) *.tab.* *.output lex.*