.PHONY : clean test all run

VPATH = src:build

CC = g++
REMOVE = rm -f
DEBUG_FLAG = -g -O0 -D DEBUG -DYYDEBUG=1
COVERAGE_FLAG=-fprofile-arcs -ftest-coverage
CFLAGS = -std=c++11
LDFLAGS = -std=c++11
EXEC = exe
LINK = -o
OUTPUT = -o

BUILDSTARTFOLDER = build
DEBUG_FOLDER = $(BUILDSTARTFOLDER)/debug
RELEASE_FOLDER = $(BUILDSTARTFOLDER)/release

SRCFOLDER = src

OUTBUILD = $(OUTPUT) $(BUILDFOLDER)/$(shell basename $@)

OBJFILE = o

FLEX_FILES = $(wildcard src/*.l)
BISON_FILES = $(wildcard src/*.y)

FLEX_RESULT = src/lex.yy.c

SRCCPP = $(filter-out $(SRCFOLDER)/main.cpp, $(wildcard src/*.cpp))
SRCH = $(wildcard src/*.h)
SRC = $(BISON_FILES) $(FLEX_FILES) $(SRCCPP) $(SRCH) $(FLEX_RESULT) $(BISON_FILES:.y=.tab.h)
OBJ_TMP = $(SRCCPP:.cpp=.$(OBJFILE)) $(BISON_FILES:.y=.tab.$(OBJFILE)) $(FLEX_RESULT:.c=.$(OBJFILE)) 

OBJ = $(OBJ_TMP:src/%=$(BUILDFOLDER)/%)

EXEC_PATH = $(BUILDFOLDER)/$(EXEC)

ifeq ($(mode),debug)
	CFLAGS += $(DEBUG_FLAG)
	LDFLAGS += $(DEBUG_FLAG)
	BUILDFOLDER = $(DEBUG_FOLDER)
else
	BUILDFOLDER = $(RELEASE_FOLDER)
endif

ifeq ($(mode),coverage)
	CFLAGS += $(COVERAGE_FLAG)
	LDFLAGS += $(COVERAGE_FLAG)
	BUILDFOLDER = src
endif


all: $(EXEC_PATH)

# debug: $(eval BUILDFOLDER=$(BUILDFOLDERSTART)/debug)
# debug: $(EXEC)


$(EXEC_PATH): $(SRC) $(OBJ)
	g++ $(LDFLAGS) $(OBJ) $(OUTBUILD)

# C++ files
$(BUILDFOLDER)/%.$(OBJFILE): $(SRCFOLDER)/%.cpp $(SRCFOLDER)/%.h
	g++ -c $(CFLAGS) $< $(OUTBUILD)

# Bison objets
$(BUILDFOLDER)/%.tab.$(OBJFILE): $(SRCFOLDER)/%.tab.h $(SRCFOLDER)/%.y
	$(eval TMP=$<)
	g++ -c $(CFLAGS) $(TMP:.h=.c) $(OUTBUILD)

# Bison files .y
%.tab.h: %.y
	$(eval TMP=$@)
	bison -v --defines=$@ $< -o $(TMP:.h=.c)

# lex.yy.o ← lex.yy.c
$(BUILDFOLDER)/%.$(OBJFILE): $(SRCFOLDER)/%.c
	g++ -c $(CFLAGS) $< $(OUTBUILD)

# lex.yy.c ← *.l
$(FLEX_RESULT): $(FLEX_FILES)
	flex -o $@ $(FLEX_FILES) 

clean:
	cd $(BUILDFOLDER); $(REMOVE) *.$(OBJFILE) $(EXEC) *.gc*
	cd src; $(REMOVE) *.tab.* *.output lex.*

test: $(EXEC_PATH)
	@echo "Lancement des tests ..."
	@tests/run.sh $(EXEC_PATH) && echo "\033[32;5mTests réussis ! \033[0m" || (echo "\033[1;31mTests échoués\033[0m" && exit 1)

run: $(EXEC_PATH)
	@$(EXEC_PATH)