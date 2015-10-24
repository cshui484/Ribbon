// ----------------------------
// projects/ribbon/Ribbon.c++
// Copyright (C) 2015
// CS Hui
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <deque>
#include <functional>
#include <map>
#include <climits>
#include <set>

//include "Ribbon.h

using namespace std;
	
// -------------
// ribbon_solve
// -------------

void ribbon_solve (istream& r, ostream& w) {
    int		n, a, b, c;
    int		r1, r2, r3;
    int		v1, v2, v3;
    int		i1, i2;
    int		m1, m2, m3;
    int		rc = 0;

//cout << " ribbon_solve" << endl;

	r >> n >> a >> b >> c;

//cout << n << " " << a << " " << b << " " << c << endl;

	// sort a, b, c to v1, v2, v3 
	if (a < b) {
		r1 = a;
		r2 = b; }
	else {
		r1 = b;
		r2 = a; }
		
	if (c < r1) {
		v1 = c;
		v2 = r1;
		v3 = r2; }
	else {
		v1 = r1;
		if (c < r2) {
			v2 = c;
			v3 = r2; }
		else {
			v2 = r2;
			v3 = c; }}

	r1 = n % v1;

//cout << v1 << " " << v2 << " " << v3 << " " << r1 << endl;
	
	for (i1=r1; i1<=n; i1+=v1) {
//cout << i1 << " " << i2 << " " << i3 << " " << rc << endl;
		r2 = i1 % v2;
		for (i2=r2; i2<=i1; i2+=v2) {
			r3 = i2 % v3;
//cout << i1 << " " << i2 << " " << i3 << " " << rc << endl;

			if (r3 == 0) {					// find a possible solution
				m3 =     i2  / v3;
				m2 = (i1-i2) / v2;
				m1 = ( n-i1) / v1;	
				if (rc < m1 + m2 + m3) {	// update rc if it is a better solution
					rc = m1 + m2 + m3; }
				break; }}}
	w << rc; }
	
// ----
// main
// ----

int main () {
    using namespace std;
//    cout << "main" << endl;
    ribbon_solve(cin, cout);
    return 0;}


