// Author: Yashkarn Pabla
// Description: Using covid-19 stats to produce graphs on specific data

// Directives 
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include "country.h"


// Namespace used to define the context in which names are defined
using namespace std;

// Menu used for user interaction
void menu()
{
    cout << "\nSelect Desired Option#: \n\n";
    cout << "1. new confirmed cases\n";
    cout << "2. new deaths\n";
    cout << "3. new recovered cases\n";
    cout << "4. total confirmed cases\n";
    cout << "5. total deaths\n";
    cout << "6. total recovered cases\n";
    cout << "7. Exit\n\n";
}

// Initially wanted to do both ascending and descending order, but descending worked better
void asc_or_decs()
{
    cout << "1. Ascending order\n\n";
    cout << "2. Descending order\n\n";
}

// Main Function used to execute code
int main() {

    string one;
    vector<country> VectorofCountry;
    // reading information from file
    ifstream file;

    // Open the summary file to read data
    file.open("summary.csv");

    // retrieve the data from file
    while (getline(file, one)) {
        stringstream sStream(one);
        string oneString;
        vector<string> temporaryVector;
        int i = 0;
        country temporaryCountry;

	// Continues to retrieve data from specific segments as indicated below 
        while (getline(sStream, oneString, ',')) {
            oneString.erase(std::remove(oneString.begin(), oneString.end(), '"'), oneString.end());

		// retrieve name of country
            if (i == 0) {
                temporaryCountry.setCountry(oneString);
            }

		// retrieve country code
            if (i == 1) {
                temporaryCountry.setCountryCode(oneString);
            }

		// retrieve new confirmed cases
            if (i == 3) {
                int j;
                std::istringstream(oneString) >> j;
                temporaryCountry.setNCCases(j);
            }

		// retrieve new deaths
            if (i == 4) {
                int j;
                std::istringstream(oneString) >> j;
                temporaryCountry.setNDeaths(j);
            }
		
		// retrieve new recovered cases
            if (i == 5) {
                int j;
                std::istringstream(oneString) >> j;
                temporaryCountry.setNRCases(j);
            }

		// retrieve total confirmed cases
            if (i == 8) {
                int j;
                std::istringstream(oneString) >> j;
                temporaryCountry.setTCCases(j);
            }


		// retrieve total deaths
            if (i == 9) {
                int j;
                std::istringstream(oneString) >> j;
                temporaryCountry.setTDeaths(j);
            }

		// retrieve total recovered cases 
            if (i == 10) {
                int j;
                istringstream(oneString) >> j;
                temporaryCountry.setTRCases(j);
            }

		// keep incrementing 
            i = i + 1;

        }

        VectorofCountry.push_back(temporaryCountry);
    }

    

   
    char choice;
    while (1)
    {
	// menu options 
        menu();
	
	// user interaction continues 
        cout << "Please Enter Your Choice:> ";
        cin >> choice;
	
	// switch statements to keep interacting with user
        switch (choice)
        {
	
	// case 
        case '1':
		// ascending or descending order
            asc_or_decs();
		// user gets prompted for choice
            cout << "Please Enter Your Choice:> ";
            cin >> choice;

		// user can pick from 1 or 2, asc or desc, then graph is printed out on this case
            if (choice == '1' || choice == '2')
            {
                VectorofCountry.at(0).sort_and_print_graph_for_new_confirmed_cases(VectorofCountry, choice);
            }
            else
            {
                cout << "\nWrong Choice\n";
            }
            break;
        case '2':
            asc_or_decs();

		// user gets prompted for choice
            cout << "Please Enter Your Choice:> ";
            cin >> choice;

		// user can pick from 1 or 2, asc or desc, then graph is printed out on this case
            if (choice == '1' || choice == '2')
            {
                VectorofCountry.at(0).sort_and_print_graph_for_new_deaths(VectorofCountry, choice);
            }
            else
            {
                cout << "\nWrong Choice\n";
            }
            break;
        case '3':
            asc_or_decs();
            cout << "Please Enter Your Choice:> ";
            cin >> choice;

		// user can pick from 1 or 2, asc or desc, then graph is printed out on this case
            if (choice == '1' || choice == '2')
            {
                VectorofCountry.at(0).sort_and_print_graph_for_new_rec_cases(VectorofCountry, choice);
            }
            else
            {
                cout << "\nWrong Choice\n";
            }
            break;
        case '4':
            asc_or_decs();


		// user gets prompted for choice
            cout << "Please Enter Your Choice:> ";
            cin >> choice;

		// user can pick from 1 or 2, asc or desc, then graph is printed out on this case
            if (choice == '1' || choice == '2')
            {
                VectorofCountry.at(0).sort_and_print_graph_for_total_confirmed_cases(VectorofCountry, choice);
            }
            else
            {
                cout << "\nWrong Choice\n";
            }
            break;
        case '5':
            asc_or_decs();


		// user gets prompted for choice
            cout << "Please Enter Your Choice:> ";
            cin >> choice;

		// user can pick from 1 or 2, asc or desc, then graph is printed out on this case
            if (choice == '1' || choice == '2')
            {
                VectorofCountry.at(0).sort_and_print_graph_for_total_deaths(VectorofCountry, choice);
            }
            else
            {
                cout << "\nWrong Choice\n";
            }
            break;
        case '6':
            asc_or_decs();

		// user gets prompted for choice
            cout << "Please Enter Your Choice:> ";
            cin >> choice;

		// user can pick from 1 or 2, asc or desc, then graph is printed out on this case
            if (choice == '1' || choice == '2')
            {
                VectorofCountry.at(0).sort_and_print_graph_for_total_rec(VectorofCountry, choice);
            }
            else
            {
                cout << "\nWrong Choice\n";
            }
            break;
        case '7':
            cout << "\n Program Exited \n";
            return 0;
        default:
            cout << "\nInvalid Choice\n";
            break;
        }
    }

    return 0;

}
