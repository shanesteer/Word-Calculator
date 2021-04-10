#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>
#include <fstream>
#include <sstream>
#include <vector>
#include "BarChart.h"

using namespace std;

BarChart::BarChart(vector<string> wordHolding, vector<int> arrayOfWords, float myTotalSize)
{
    //intialising the private variables
    this->wordHolding = wordHolding;
    this->arrayOfWords = arrayOfWords;
    this->myTotalSize = myTotalSize;
}

void BarChart::createBarChart()
{
    double percentageOccurance;
    string q1;
    for(int j = 0; j < wordHolding.size(); j++)
    {
        q1 = "";
        //this limits the amount of = symbols that are printed
        if(arrayOfWords[j] > 25)
        {
            int k = 0;
            //if the occurence is less than 25, then add an =
            while(k < 25){
                q1.append("=");
                k++;
                
            }
        }

        else
        {
            int k = 0;
            //appends an equals for each occurence for the word
            while(k < arrayOfWords[j]){
                q1.append("=");
                k++;
            }
        }
        
        //calculates percentage and sends the output to the output file
        int i_want_to_eat_a_banana = arrayOfWords[j];
        percentageOccurance = (i_want_to_eat_a_banana / myTotalSize) * 100;
        cout << fixed << showpoint << setprecision(5);
        cout << wordHolding[j] << ": " << q1 << " " << arrayOfWords[j] << " (" << percentageOccurance << "%" << ")" << endl;
    }
}

void BarChart::printBarChart()
{
    string q1;
    ofstream outputFile("output.txt");
    double percentageOccurance;
    for(int j = 0; j < wordHolding.size(); j++)
    {
        q1 = "";
        //this limits the amount of = symbols that are printed
        if(arrayOfWords[j] > 25)
        {
            int k = 0;
            //if the occurence is less than 25, then add an =
            while(k < 25){
                q1.append("=");
                k++;
                
            }
        }

        else
        {
            int k = 0;
            //appends an equals for each occurence for the word
            while(k<arrayOfWords[j]){
                q1.append("=");
                k++;
            }
        }
        //calculates percentage and sends the output to the output file
        int i_want_to_eat_a_banana = arrayOfWords[j];
        percentageOccurance = (i_want_to_eat_a_banana / myTotalSize) * 100;
        outputFile << fixed << showpoint << setprecision(5);
        outputFile << wordHolding[j] << ": " << q1 << " " << arrayOfWords[j] << " (" << percentageOccurance << "%" << ")" << endl;
    }
}