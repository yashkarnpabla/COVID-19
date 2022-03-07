// Author: Yashkarn Pabla
// Description: Using covid-19 stats to produce graphs on specific data


#include <iostream>
#include "country.h"
using namespace std;

// Output a graph for desired chracteristic, uses "+"
void country::print_graph(string code, int value)
{
    cout << code << " | ";
    int dashes = value / 10000;
    for (int i = 0; i < dashes; i++)
    {
        cout << "+";
    }
    cout << endl;
}

// set all values to 0 and empty
country::country() {

// country name
    Country = "";

// country code
    CountryCode = "";
    
// New confirmed cases
    NCCases = 0;

// new deaths
    NDeaths = 0;

// new recovered cases
    NRCases = 0;

// total confirmed cases
    TCCases = 0;

// total deaths
    TDeaths = 0;

// total recovered cases
    TRCases = 0;
}

// Defining functions outside of the class for the following 

// set country
void country::setCountry(string newCountry) {
    country::Country = newCountry;
}

//getCountry
string country::getCountry() {
    return country::Country;
}

// set country code
void country::setCountryCode(string newCountryCode) {
    CountryCode = newCountryCode;
}

//get country code
string country::getCountryCode() {
    return country::CountryCode;
}

// set new confirmed cases
void country::setNCCases(int newNCC) {
    country::NCCases = newNCC;
}

// get new confirmed cases
int country::getNCCases() {
    return country::NCCases;
}

// set new deaths
void country::setNDeaths(int newND) {
    country::NDeaths = newND;
}

// get new deaths
int country::getNDeaths() {
    return country::NDeaths;
}

// set new recovered cases
void country::setNRCases(int newNRC) {
    country::NRCases = newNRC;
}

// get new recovered cases
int country::getNRCases() {
    return country::NRCases;
}

// set total confirmed cases
void country::setTCCases(int newTCC) {
    country::TCCases = newTCC;
}

// get total recovered cases
int country::getTCCases() {
    return TCCases;
}

// set total deaths
void country::setTDeaths(int newTD) {
    country::TDeaths = newTD;
}

// get total deaths
int country::getTDeaths() {
    return country::TDeaths;
}

// set total recovered cases
void country::setTRCases(int newTRC) {
    country::TRCases = newTRC;
}

// get total recovered cases
int country::getTRCases() {
    return country::TRCases;
}

void country::toString() {
    cout << "test" << endl;
}

// Creating an outputted graph for new confirmed cases ASCENDING/DESCENDING ORDER
void country::sort_and_print_graph_for_new_confirmed_cases(vector<country> c, char opt)
{
    int size = c.size();
    country cp_temp;
   
// If user inputs one algorithm for ascending order is executed as seen below
    if (opt == '1')
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (c.at(i).NCCases > c.at(j).NCCases)
                {
                    cp_temp = c.at(i);
                    c.at(i) = c.at(j);
                    c.at(j) = cp_temp;
                }
            }
        }
    }

// If user inputs two algorithm for descending order is executed as seen below
    if (opt == '2')
    {
        // increment
        for (int i = 1; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (c.at(i).NCCases < c.at(j).NCCases)
                {
                    cp_temp = c.at(i);
                    c.at(i) = c.at(j);
                    c.at(j) = cp_temp;
                }
            }
        }
    }

    cout << endl;
    for (int i = 1; i < 11; i++)
    {   
        // print the graph
        print_graph(c.at(i).CountryCode, c.at(i).NCCases);
    }

    for (int i = 0; i < 71; i++)
    {
        cout << "-";
    }

    // legend
    cout << "\nNew Confirmed Cases; Each + is approx. 10,000\n\n";
}

// Creating an outputted graph for total confirmed cases ASCEDNING/DESCENDING ORDER
void country::sort_and_print_graph_for_total_confirmed_cases(vector<country> c, char opt)
{
    int size = c.size();
    country cp_temp;

// If user inputs one, algorithm for ascending order is executed as seen below
    if (opt == '1')
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (c.at(i).TCCases > c.at(j).TCCases)
                {
                    cp_temp = c.at(i);
                    c.at(i) = c.at(j);
                    c.at(j) = cp_temp;
                }
            }
        }
    }

// If user inputs two algorithm for descending order is executed as seen below
    if (opt == '2')
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (c.at(i).TCCases < c.at(j).TCCases)
                {
                    cp_temp = c.at(i);
                    c.at(i) = c.at(j);
                    c.at(j) = cp_temp;
                }
            }
        }
    }

    cout << endl;
    for (int i = 1; i < 11; i++)
    {
	// print the graph to screen
        print_graph(c.at(i).CountryCode, c.at(i).TCCases);
    }

    for (int i = 0; i < 71; i++)
    {
        cout << "-";
    }
	// legend line is also printed
    cout << "\nTotal Confirmed Cases; Each + is approx. 10,000\n\n";
}

// Creating an outputted graph for new deaths ASCENDING/DESCENDING ORDER
void country::sort_and_print_graph_for_new_deaths(vector<country> c, char opt)
{
    int size = c.size();
    country cp_temp;

// If user inputs one algorithm for ascending order is executed as seen below
    if (opt == '1')
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (c.at(i).NDeaths > c.at(j).NDeaths)
                {
                    cp_temp = c.at(i);
                    c.at(i) = c.at(j);
                    c.at(j) = cp_temp;
                }
            }
        }
    }

// If user inputs two algorithm for descending order is executed as seen below
    if (opt == '2')
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (c.at(i).NDeaths < c.at(j).NDeaths)
                {
                    cp_temp = c.at(i);
                    c.at(i) = c.at(j);
                    c.at(j) = cp_temp;
                }
            }
        }
    }

    cout << endl;
    for (int i = 1; i < 11; i++)
    {
        print_graph(c.at(i).CountryCode, c.at(i).NDeaths);
    }

    for (int i = 0; i < 71; i++)
    {
        cout << "-";
    }
	// legend is printed out 
    cout << "\nNew Deaths; Each + is approx. 10,000\n\n";
}

// Creating an outputted graph for new recovered cases ASCENDING/DESCENDING ORDER
void country::sort_and_print_graph_for_new_rec_cases(vector<country> c, char opt)
{
    int size = c.size();
    country cp_temp;

// If user inputs one algorithm for ascending order is executed as seen below
    if (opt == '1')
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (c.at(i).NRCases > c.at(j).NRCases)
                {
                    cp_temp = c.at(i);
                    c.at(i) = c.at(j);
                    c.at(j) = cp_temp;
                }
            }
        }
    }

// If user inputs two algorithm for descending order is executed as seen below
    if (opt == '2')
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (c.at(i).NRCases < c.at(j).NRCases)
                {
                    cp_temp = c.at(i);
                    c.at(i) = c.at(j);
                    c.at(j) = cp_temp;
                }
            }
        }
    }

    cout << endl;
    for (int i = 1; i < 11; i++)
    {
        print_graph(c.at(i).CountryCode, c.at(i).NRCases);
    }

    for (int i = 0; i < 71; i++)
    {
        cout << "-";
    }
	// legend is printed
    cout << "\nNew Recovered Cases; Each + is approx. 10000\n\n";
}

// Creating an outputted graph for total deaths ASCENDING/DESCENDING ORDER
void country::sort_and_print_graph_for_total_deaths(vector<country> c, char opt)
{
    int size = c.size();
    country cp_temp;

// If user inputs one algorithm for ascending order is executed as seen below
    if (opt == '1')
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (c.at(i).TDeaths > c.at(j).TDeaths)
                {
                    cp_temp = c.at(i);
                    c.at(i) = c.at(j);
                    c.at(j) = cp_temp;
                }
            }
        }
    }

// If user inputs two algorithm for descending order is executed as seen below
    if (opt == '2')
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (c.at(i).TDeaths < c.at(j).TDeaths)
                {
                    cp_temp = c.at(i);
                    c.at(i) = c.at(j);
                    c.at(j) = cp_temp;
                }
            }
        }
    }

    cout << endl;
    for (int i = 1; i < 11; i++)
    {
        print_graph(c.at(i).CountryCode, c.at(i).TDeaths);
    }

    for (int i = 0; i < 71; i++)
    {
        cout << "-";
    }
    cout << "\nTotal Deaths; Each + is approx. 10000\n\n";
}

// Creating an outputted graph for total recovered ASCENDING/DESCENDING ORDER
void country::sort_and_print_graph_for_total_rec(vector<country> c, char opt)
{
    int size = c.size();
    country cp_temp;

// If user inputs one algorithm for ascending order is executed as seen below
    if (opt == '1')
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (c.at(i).TRCases > c.at(j).TRCases)
                {
                    cp_temp = c.at(i);
                    c.at(i) = c.at(j);
                    c.at(j) = cp_temp;
                }
            }
        }
    }

// If user inputs two algorithm for descending order is executed as seen below
    if (opt == '2')
    {
        for (int i = 1; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (c.at(i).TRCases < c.at(j).TRCases)
                {
                    cp_temp = c.at(i);
                    c.at(i) = c.at(j);
                    c.at(j) = cp_temp;
                }
            }
        }
    }

    cout << endl;
    for (int i = 1; i < 11; i++)
    {
        print_graph(c.at(i).CountryCode, c.at(i).TRCases);
    }

    for (int i = 0; i < 71; i++)
    {
        cout << "-";
    }
    cout << "\nTotal Recovered; Each + is approx. 10,000\n\n";
}

// destructor
country::~country() {}