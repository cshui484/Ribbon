// --------------------------------
// projects/ribbon/TestRibbon.c++
// Copyright (C) 2015
// CS Hui
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

//#include "Ribbon.h"
//void ribbon_solve (istream& r, ostream& w);

using namespace std;

// -----------
// TestRibbon
// -----------

// ----
// read
// ----
/*
TEST(RibbonFixture, read) {
    string s("1 10\n");
    const pair<int, int> p = ribbon_read(s);
    ASSERT_EQ( 1, p.first);
    ASSERT_EQ(10, p.second);}

TEST(RibbonFixture, read1) {
	int i, j, k;
    string s("1 10 100\n");
    const tuple<int, int, int> t = ribbon_read1(s);
    tie(i, j, k) = t;
    ASSERT_EQ( 1, i);
    ASSERT_EQ(10, j);
    ASSERT_EQ(100, k);}
*/
// ----
// eval
// ----

/*
TEST(RibbonFixture, eval_4) {
    const int v = ribbon_eval(3, 11);
    ASSERT_EQ(3, v);}
*/

// -----
// print
// -----
/*
TEST(RibbonFixture, print) {
	vector<int> v = {1, 2, 3, 4};
    ostringstream w;
    ribbon_print(w, v);
    ASSERT_EQ("1 2 3 4 \n", w.str());}
*/
// -----
// solve
// -----

TEST(RibbonFixture, solve) {
    istringstream r("100 3 17 22\n");
    ostringstream w;
    ribbon_solve(r, w);
    ASSERT_EQ("27\n", w.str());}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Ribbon.c++ TestRibbon.c++ -o TestRibbon -lgtest -lgtest_main -lpthread



% valgrind TestRibbon                                         >  TestRibbon.out 2>&1
% gcov -b Ribbon.c++     | grep -A 5 "File 'Ribbon.c++'"     >> TestRibbon.out
% gcov -b TestRibbon.c++ | grep -A 5 "File 'TestRibbon.c++'" >> TestRibbon.out



% cat TestRibbon.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestRibbon
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Ribbon
[ RUN      ] Ribbon.read
[       OK ] Ribbon.read (31 ms)
[ RUN      ] Ribbon.eval_1
[       OK ] Ribbon.eval_1 (5 ms)
[ RUN      ] Ribbon.eval_2
[       OK ] Ribbon.eval_2 (3 ms)
[ RUN      ] Ribbon.eval_3
[       OK ] Ribbon.eval_3 (3 ms)
[ RUN      ] Ribbon.eval_4
[       OK ] Ribbon.eval_4 (3 ms)
[ RUN      ] Ribbon.print
[       OK ] Ribbon.print (17 ms)
[ RUN      ] Ribbon.solve
[       OK ] Ribbon.solve (10 ms)
[----------] 7 tests from Ribbon (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'Ribbon.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Ribbon.c++.gcov'
File 'TestRibbon.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestRibbon.c++.gcov'
*/
