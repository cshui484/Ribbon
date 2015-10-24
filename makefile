CXX        := g++-4.8
CXXFLAGS   := -pedantic -std=c++11 -Wall
LDFLAGS    := -lgtest -lgtest_main -pthread
GCOV       := gcov-4.8
GCOVFLAGS  := -fprofile-arcs -ftest-coverage
GPROF      := gprof
GPROFFLAGS := -pg
VALGRIND   := valgrind

clean:
	rm -f *.gcda
	rm -f *.gcno
	rm -f *.gcov
	rm -f RunRibbon
	rm -f RunRibbon.tmp
	rm -f TestRibbon
	rm -f TestRibbon.tmp
	rm -f solution
	rm -f *~

config:
	git config -l

scrub:
	make  clean
	rm -f  Ribbon.log
	rm -rf ribbon-tests
	rm -rf html
	rm -rf latex

status:
	make clean
	@echo
	git branch
	git remote -v
	git status

test: RunRibbon.tmp TestRibbon.tmp

solution: solution.cpp
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) solution.cpp -o solution

shi: shi.cpp
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) shi.cpp -o shi

#RunRibbon: Ribbon.h Ribbon.c++ RunRibbon.c++
#	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Ribbon.c++ RunRibbon.c++ -o RunRibbon
RunRibbon: Ribbon.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) Ribbon.c++ -o RunRibbon

RunRibbon.tmp: RunRibbon
	./RunRibbon < RunRibbon.in > RunRibbon.tmp
	diff -w RunRibbon.tmp RunRibbon.out

#TestRibbon: Ribbon.h Ribbon.c++ TestRibbon.c++
TestRibbon: TestRibbon.c++
	$(CXX) $(CXXFLAGS) $(GCOVFLAGS) TestRibbon.c++ -o TestRibbon $(LDFLAGS)

TestRibbon.tmp: TestRibbon
	$(VALGRIND) ./TestRibbon                                       >  TestRibbon.tmp 2>&1
	$(GCOV) -b Ribbon.c++     | grep -A 5 "File 'Ribbon.c++'"     >> TestRibbon.tmp
	$(GCOV) -b TestRibbon.c++ | grep -A 5 "File 'TestRibbon.c++'" >> TestRibbon.tmp
	cat TestRibbon.tmp
