// Author: Yashkarn Pabla
// Description: Using covid-19 stats to produce graphs on specific data


// Include guards to prevent any double declaration of any identifiers
#ifndef COUNTRYCLASS_H

// Include guards to prevent any double declaration of any identifiers
#define COUNTRYCLASS_H

// When a variable is declared, the type will be a string 
#include <string>

// Same names can be availible in different libraires
using namespace std; 

//vector
#include<vector>

// Country class is declared
class country {
    
  // public variables are declared  
  public:
  
    country();
    
    void toString();
  


    // Set new confirmed cases
    void setNCCases(int NewConfirmedCases);
   
    // Get the new confirmed cases in integer
    int getNCCases();

    // Set new deaths 
    void setNDeaths(int newNewDeaths);
    
    // Get new deaths in integer
    int getNDeaths();
    
    // Set Country
    void setCountry(string newCountry);
    
    // Get country in string format
    string getCountry();

    // Set new recovered cases
    void setNRCases(int newRecoveredCases);
    
    // Get new recovered cases in integer
    int getNRCases();
    
    // Set the total confirmed cases 
    void setTCCases(int newTotalConfirmedCases);
    
    // Get the total confirmed cases in integer
    int getTCCases();
    
    // Set the total amount of deaths 
    void setTDeaths(int newTotalDeaths);
    
    // Get the total amount of deaths
    int getTDeaths();

    // Set the total amount of recovered cases
    void setTRCases(int newTotalRecoveredCases);
    
    // Get the total amount of recovered cases
    int getTRCases();
    
    // Set the country code 
    void setCountryCode(string newCountryCode);
    
    // Get country code in string format
    string getCountryCode();
    
    void sort_and_print_graph_for_new_confirmed_cases(vector<country>,char);
    void sort_and_print_graph_for_new_deaths(vector<country>, char);
    void sort_and_print_graph_for_total_confirmed_cases(vector<country>, char);
    void sort_and_print_graph_for_new_rec_cases(vector<country>, char);
    void sort_and_print_graph_for_total_deaths(vector<country>, char);
    void sort_and_print_graph_for_total_rec(vector<country>, char);
    
    // the use of a DECONSTRUCTOR, destroys the instance and frees up memory
    ~country();
    
// private variables
  private:  
    // declaring new confirmed cases, new death and new recovered cases
    int NCCases; int NDeaths; int NRCases;
    // declaring total confirmed cases, deaths and total recovered cases
    int TCCases;int TDeaths;int TRCases;
    string Country; string CountryCode;
    void print_graph(string code, int value);
    };

// closes off the ifndef directive
#endif
