// Test1 or int main

#include "jumbo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <iomanip>

int main ()
{
    using namespace std;

    vector<string> allrows;
    unsigned int totalrows;
    string flt_dfilename;
    ifstream dfilestr;

    Jumbo J;
   
    J.read_flight_data(dfilestr, flt_dfilename, allrows, totalrows);
    J.book_flight(allrows);
    J.save_flight_data(allrows, flt_dfilename);

    return 0;

}
