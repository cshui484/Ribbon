// ------------------------------/
// projects/australia_voiing/RunRibbon.c++
// Copyright (C) 2015
// CS Hui
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cin, cout

#include "Ribbon.h"

// ----
// main
// ----

int main () {
    using namespace std;
    ribbon_solve(cin, cout);
    return 0;}

/*
% g++ -pedantic -std=c++11 -Wall Ribbon.c++ RunRibbon.c++ -o RunRibbon



% cat RunRibbon.in
1 10
100 200
201 210
900 1000



% RunRibbon < RunRibbon.in > RunRibbon.out



% cat RunRibbon.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/
