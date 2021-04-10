#ifndef BARCHART_H
#define BARCHART_H

using namespace std;

#include <string>
#include <vector>

class BarChart
{
    public:
    BarChart(vector<string> wordHolding, vector<int> arrayOfWords, float myTotalSize);
    void createBarChart();
    void printBarChart();

    private:
    vector<string> wordHolding;
    vector<int> arrayOfWords;
    float myTotalSize;

    
};


 #endif