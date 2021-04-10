#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <limits>
#include <math.h>
#include "ReadWords.cpp"
#include "BarChart.cpp"



using namespace std;

int main()
{
    string words;
    vector<string> wordHolding;
    string myFilename;
    string testWordsFile;


    cout << "Please enter your file path for the file you wish to read here: \n";
    getline(cin, myFilename);


    const char* holdingMyFilename = myFilename.c_str();
    ReadWords file = ReadWords(holdingMyFilename);


    bool banana = false;
    int answer;

    //Check if the user want to enter their own words or a file of set words to search for
    while(!banana)
    {
        cout << "Would you like to manually enter words you want to search for or do you have a file with words you wish to search for? \n";
        cout << "Enter '1' to manually enter words or '0' to enter file with words you want to search for: \n";
        cin >> answer;

        if(answer == 0)
        {
            //prompt the user for the file containing search words
            cout << "Please enter the file of your word file: \n";
            cin.ignore(); //fixes problems with the \n
            getline(cin, testWordsFile);

            const char* holdingInputFile = testWordsFile.c_str();
            ReadWords file1 = ReadWords(holdingMyFilename);

            ifstream userinputfile;
            userinputfile.open(holdingInputFile);
            if(!userinputfile)
            {
                cout << "Failed to open " << holdingInputFile << endl; 
                exit(1);
            }

            string testWords;

            while(getline(userinputfile, testWordsFile))
            {
                //separate the words from white space(Array of words)
                istringstream q(testWordsFile);
                //putting q into text
                while (q >> testWords)
                {
                    //adding the words entered into the vector
                    wordHolding.push_back(testWords);
                }
                
            }

            banana = true;
        }
        

        else if(answer == 1)
        {
            banana = false;
            string answer1;
            int answer2;
            string answer3;

            //prompts the user to enter the amount of words they want to search for
            while(!banana)
            {
                cout << "Please enter how many words you would like to seach for (5 words or more): \n";
                cin >> answer1;

                //checks if the user enter a string instead of an int
                try{
                    answer2 = stoi(answer1);
                }
                catch(invalid_argument){
                    cout << "Invalid input" << endl;
                    continue;
                }
                
                //tells the user that they cannot enter less than 5search words if they do
                if(answer2 < 5)
                {
                    cout << "You cannot enter less than 5 words. \n";
                    continue;
                }

                else
                {
                    //checks how many words the user wants to enter and prompts them for the word that many times
                    for(int i = 0; i < answer2; i++)
                    {
                        cout << "Please enter a word for searching: \n";
                        cin.ignore(); //fixes problems with the \n
                        getline(cin, answer3);

                        //of the user enters a word with less than 1 character, does not increment they i and asks them to enter words with more than 2 letters
                        if(answer3.size() < 1)
                        {
                            cout << "Please enter a word with more than 1 letter." << endl;
                            i--;
                            continue;
                        }

                        else
                        {
                            //adding the words entered into the vector
                            wordHolding.push_back(answer3);
                        }
                        
                    }
                }

                banana = true;

            }
        }

        else
        {
            cout << "You have entered an invalid value. Please try again." << endl;
            continue;
        }
        
        banana = true;
    }


    string fileWords;
    int wordSize = wordHolding.size();
    vector<int> sizeOf;

    //initialises the array to 0 and not null
    for(int i = 0; i<wordSize; i++){
        sizeOf.push_back(0);
    }

    float totalFileSize = 0.0;
    int indexPosition;

    while(file.isNextWord())
    {
        fileWords = file.getNextWord();
        totalFileSize++;

        for(string s: wordHolding)
        {
            if(s == fileWords)
            {
                indexPosition = findingIndex(wordHolding, s);

                if(indexPosition != -1)
                {
                    sizeOf[indexPosition] += 1;
                }
            }

            
        }
    }



    BarChart barchart = BarChart(wordHolding, sizeOf, totalFileSize);
    barchart.createBarChart();
    barchart.printBarChart();
    

    //ReadWords writer("output.txt");

}