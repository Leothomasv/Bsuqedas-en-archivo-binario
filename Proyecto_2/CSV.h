#ifndef CSV_h
#define CSV_h

#include <iostream>
#include <fstream>



struct WHO
{

    char Date_Reported [11];
    char Country_Code [3];
    char Country [50];
    char WHO_region [5];

    int New_cases;
    int Cumulative_cases;
    int New_deaths;
    int Cumulative_deaths;

};


class OperacionesCSV{
    public:
    void convert();
    void display(std::string file);

};

#endif