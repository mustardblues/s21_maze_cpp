
# ------------------------------------------------------------------------------------------ Macros

CXX					:= g++
CXXFLAGS			:= -Wall -Wextra -Werror -pedantic -g
SYSFLAGS			:= -lgtest -lstdc++

ifeq ($(shell uname), Linux)
	SYSFLAGS		+= -pthread -lrt -lm

endif

MODEL_SOURCES 		:= 	src/model/common/modules/common.cpp \
						src/model/cave/modules/cave_data.cpp \
						src/model/cave/modules/cave_load.cpp \
						src/model/cave/modules/cave_save.cpp \
						src/model/cave/modules/cellular_automaton.cpp \
						src/model/maze/modules/bfs_algorithm.cpp \
						src/model/maze/modules/dfs_algorithm.cpp \
						src/model/maze/modules/eller_algorithm.cpp \
						src/model/maze/modules/maze_data.cpp \
						src/model/maze/modules/maze_load.cpp \
						src/model/maze/modules/maze_save.cpp \
						src/model/maze/modules/q_learning.cpp

TEST_SOURCES		:=  tests/gtest_cave.cpp \
						tests/gtest_maze.cpp \
						tests/main.cpp

# ----------------------------------------------------------------------------------------- Targets

all: test

.PHONY: help
help:
	@grep -E '^[a-zA-Z0-9 - _]+:.*#'  Makefile | sort | while read -r l; do \
	printf "\033[1;36m$$(echo $$l | cut -f 1 -d':')\033[00m:$$(echo $$l | cut -f 2- -d'#')\n"; done

.PHONY: install
install: # install build
	cd src && cmake -G "Unix Makefiles" -B ./../build -S ./ && cd ./../build/ && make

.PHONY: unistall
unistall: # remove build
	- rm -rf build

.PHONY: gcov_report
gcov_report: test # checks the coverage of the project libraries
	@ lcov -t "A1_Maze_CPP" -o A1_Maze_CPP.info -c -d . --no-external 
	@ genhtml -o gcov_report A1_Maze_CPP.info

	- rm -rf *.gcno *.gcda *.info 
	open gcov_report/index.html

.PHONY: dvi
dvi: # creates project documentation
	@ cd dvi/ && doxygen
	open dvi/doxygen/html/index.html

.PHONY: dist
dist: # creates a .tar archive including all project files
	tar -czvf ./../3DViewer.tar .

.PHONY: install_doxygen
install_doxygen: # installs Doxygen
	sudo apt update
	sudo apt-get doxygen

.PHONY: test
test: # tests on GTest
	$(CXX) $(CXXFLAGS) --coverage $(MODEL_SOURCES) $(TEST_SOURCES) -o test $(SYSFLAGS)
	./test

# ----------------------------------------------------------------------------------------- Linters

.PHONY: style
style: # checks code for Google style
	find . \( -name "*.h" -o -name "*.c" -o -name "*.hpp" -o -name "*.cpp" \) -print0 \
	| xargs --null clang-format -n --style=Google

.PHONY: leaks
leaks: test # checks code for leaks using Valgrind utility
	valgrind --tool=memcheck --track-fds=yes --quiet --trace-children=yes \
	--track-origins=yes --leak-check=full --show-leak-kinds=all -s ./test

# ------------------------------------------------------------------------------- Abstracts Targets

clean:
	- rm test
	- rm -rf gcov_report
	- rm *.gcno *.gcda *.info
	- rm -rf dvi/doxygen
	- rm tmp.txt

rebuild: clean all