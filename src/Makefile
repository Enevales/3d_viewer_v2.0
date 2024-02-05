CC=g++
CXXFLAGS=-Wall -Werror -Wextra -pedantic -std=c++17
COVFLAGS = -fprofile-arcs -ftest-coverage
RM=rm -rf
PROJECTNAME = 3DViewer_v.2.0
VERSION = `date +"%Y.%m.%d"`
ARCHIVE = $(PROJECTNAME)-$(VERSION)
BUILDDIR = $(PROJECTNAME)-build-release
UNAME = $(shell uname -s)
TST_LIBS = -lgtest
TESTDIR = ./tests/
SOURCES =  Model/viewermodel.cc

OBJECTS = $(patsubst %.cc, %.o, $(SOURCES))
TESTS = $(wildcard $(TESTDIR)*.cc)
LIB = 3DViewer.a

ifeq ($(UNAME),Linux)
	LDLIBS = -lgtest 
	OPEN_CM=xdg-open
	MEMORYCHECK=valgrind -s --leak-check=full --show-leak-kinds=all  ./a.out
endif
ifeq ($(UNAME),Darwin)
	LDLIBS = -lgtest
	OPEN_CM=open
	MEMORYCHECK=leaks -atExit -- ./a.out
endif

all: clean 

tests: $(LIB)
	@echo "🔎 Running the tests..."
	$(CC) $(TESTS)  -o ./a.out $(TST_LIBS) -L. $^
	exec ./a.out

$(LIB): $(OBJECTS)
	@echo "📚 Creating the library..."
	ar rcs $(LIB) $^
	ranlib $(LIB)

%.o : %.cc
	@echo "🚧 Building..."
	$(CC) $(CXXFLAGS) -o $@ -c $< 

build:
	if ! [ -d "$(BUILDDIR)" ]; then \
    	mkdir $(BUILDDIR) && cd $(BUILDDIR) && cmake ../ ; \
	fi

install: build
	cd $(BUILDDIR) &&  cmake  --build  . && cmake --install . --prefix $(BUILDDIR)

uninstall:
	$(RM) $(BUILDDIR)

dist: install
	tar -zcvf $(ARCHIVE).tar $(BUILDDIR)

# dvi:
# 	latex ./doc.tex

# pdf:
# 	dvipdf doc.dvi
# 	open doc.pdf

dvi:
	open doc.pdf
	

gcov:
	$(CC) $(COVFLAGS) Model/calc_model.cc tests/main_calc_tests.cc tests/test_runner.cc $(TST_LIBS) -o report.out
	./report.out
	gcov -f calc_model.cc calc_model.h 
	lcov -t "gcov_report" --no-external --ignore-errors mismatch -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info 
	$(OPEN_CM) ./report/index-sort-f.html

memory_check: tests
	$(MEMORYCHECK)
	

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n Model/* Controller/*  View/* tests/*

clean:
	$(RM) *.o *.a *.out *.exe *.gcda *.gcno *.i *.tar *.dvi *.gcov *.info .clang-format *.user
	find . \( -name "*.o" -o  -name "*.out" -o  -name "*.exe" \) -type f -delete
	$(RM) ./report