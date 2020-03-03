// Test2or int main

#include "hopper.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <iomanip>

int main()
{
    using namespace std;

    vector<string> allrows;
    unsigned int totalrows;
    string flt_dfilename;
    ifstream dfilestr;

    Hopper H;
   
    H.read_flight_data(dfilestr, flt_dfilename, allrows, totalrows);
    H.book_flight(allrows);
    H.save_flight_data(allrows, flt_dfilename);

    return 0;

}
