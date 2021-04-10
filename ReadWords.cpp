// replace my comments with your own
// except: you can use my comment about one-word lookahead

// you may modify the code that I have supplied if you wish


using namespace std;

#include "ReadWords.h"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

string removePunct(string &word) // added in &
{ // should return a copy of the word with all leading and trailing punctuation      
  // removed
  // punctuation elsewhere in the word should not be removed
  // note that a word could havce more than one leading/trailing punctuation symbols
  // you need to write this

  
  word.erase(remove_if(word.begin(), word.end(), ::ispunct), word.end()); //use remove if as an iterator to loop through words to check and remove leading and trailing punctuation.
    
  return word;

}

ReadWords::ReadWords(const char *fname)
{   wordfile.open(fname);//open file
    if (!wordfile)
    {   cout << "Failed to open " << fname << endl;
        exit(1);
    }
    wordfile >> nextword;
    eoffound = false;
}

string ReadWords::getNextWord()
{ // should return next word in file, converted to lower case
  // empty string should be returned if next word contains no letters
  
  // uses a one-word lookahead to avoid any problems relating to when if end-of-file
  // is detected due to absence/presence of newline at end of file

  // incomplete

  string word = nextword;
  wordfile >> nextword;

  if (wordfile.eof())
     eoffound = true;

  
  transform(word.begin(), word.end(), word.begin(), ::tolower);
  
  word = removePunct(word);

  // need to check that word contains a letter, and if not return an empty string;
  // also need to convert to lower case before returning

  return word;
}

bool ReadWords::isNextWord()
{ 
  return !eoffound;
}

void ReadWords::close()
{ 
  wordfile.close();
}


//function for finding index of a vector
static int findingIndex(vector<string> v, string words)
{
  int index;
  auto it = find(v.begin(), v.end(), words);

  //if an element is found, the index of the elementis calculated
  if(it != v.end())
  {
    index = it - v.begin(); 
  }

  else
  {
    //return -1 if the element is not present in the vector
    return -1;
  }
  
  return index;
}
