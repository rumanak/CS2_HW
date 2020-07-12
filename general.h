//Rumana Khan 
//Hw 9 

#ifndef _GENERAL_H
#define _GENERAL_H

#include <iostream>
#include <vector>

using namespace std; 

class General
{
    public:
        General();
        void pick_flight(ifstream &infile, string &fname);
        void save_flight_data(const vector<string> &rows, const string &fname);
        unsigned int get_flight_data(ifstream &fdin, vector <string> &vec);
        void read_flight_data(ifstream &fltdata, string &fname,
                             vector<string> &rows, unsigned int &rowsct);
        void displayrow(const string &rw);
        virtual void special_seats(const string &rw);
        virtual void show_special_seats(vector<string> &seats);
        void showseating(const vector<string> &seats);
        void change_first(vector<string> &seats, string name);
        void change_econ(vector<string> &seats, string name);
        virtual bool book_seat(vector <string> &rows, int rnum, char seat);
        virtual bool remove_seat(vector<string> &rows, int &rnum, int &seat);
        unsigned int get_seatcount(const vector<string> &seats); 
        unsigned int get_occupied_ct(const vector<string> &seats);
        void book_flight(vector<string> &rows);

};

#endif//GENERAL_H

