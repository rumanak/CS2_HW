// Test2or int main

#include "commuter.h"
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

    Commuter C;
   
    C.read_flight_data(dfilestr, flt_dfilename, allrows, totalrows);
    C.book_flight(allrows);
    C.save_flight_data(allrows, flt_dfilename);

    return 0;

}
