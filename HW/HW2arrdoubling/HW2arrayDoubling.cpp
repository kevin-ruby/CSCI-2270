#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// struct to store word + count combinations
struct wordItem
{
    string word;
    int count;
};

/*
* Function name: getStopWords
* Purpose: read stop word list from file and store into vector
* @param ignoreWordFile - filename (the file storing ignore/stop words)
* @param _vecIgnoreWords - store ignore words from the file (pass by reference)
* @return - none
* Note: The number of words is fixed to 50
*/
void getStopWords(const char *ignoreWordFileName, vector<string> &_vecIgnoreWords);

/*
* Function name: isStopWord
* Purpose: to see if a word is a stop word
* @param word - a word (which you want to check if it is a stop word)
* @param _vecIgnoreWords - the vector type of string storing ignore/stop words
* @return - true (if word is a stop word), or false (otherwise)
*/
bool isStopWord(string word, vector<string> &_vecIgnoreWords);

/*
* Function name: getTotalNumberNonStopWords
* Purpose: compute the total number of words saved in the words array (including repeated words)
* @param list - an array of wordItems containing non-stopwords
* @param length - the length of the words array
* @return - the total number of words in the words array (including repeated words multiple times)
*/
int getTotalNumberNonStopWords(wordItem list[], int length);

/*
* Function name: arraySort
* Purpose: sort an array of wordItems, decreasing, by their count fields
* @param list - an array of wordItems to be sorted
* @param length - the length of the words array
*/
void arraySort(wordItem list[], int length);

/**
* Function name: printTopN
* Purpose: to print the top N high frequency words
* @param wordItemList - a pointer that points to a *sorted* array of wordItems
* @param topN - the number of top frequency words to print
* @return none
*/
void printTopN(wordItem wordItemList[], int topN);





const int STOPWORD_LIST_SIZE = 50;

const int INITIAL_ARRAY_SIZE = 100;

// ./a.out 10 HW2-HungerGames_edit.txt HW2-ignoreWords.txt
int main(int argc, char *argv[])
{
    vector<string> vecIgnoreWords(STOPWORD_LIST_SIZE);

    // verify we have the correct # of parameters, else throw error msg & return
    if (argc != 4)
    {
        cout << "Usage: ";
        cout << argv[0] << " <number of words> <filename.txt> <ignorefilename.txt>";
        cout << endl;
        return 0;
    }


    /* **********************************
    1. Implement your code here.

    Read words from the file passed in on the command line, store and
    count the words.

    2. Implement the six functions after the main() function separately.
    ********************************** */
    int arraySize=100;
    int currentArrayCount=0;


    wordItem * mainArray= new wordItem[arraySize];
    ifstream mainText;
    mainText.open(argv[2]);
    string wor;
    int count=0;
    int DAcounter=0;
    int unique=0;

    getStopWords(argv[3],vecIgnoreWords);
    while (mainText>>wor)
    {

      if (!isStopWord(wor,vecIgnoreWords))
      {
        int i;
        for (i=0;i<arraySize;i++)
        {
          if (mainArray[i].word==wor)
          {
            break;
          }
        }
        if (i==arraySize)
        {
          wordItem W;
          W.word=wor;
          W.count=1;

          mainArray[count]=W;
          count++;
          currentArrayCount++;
        }
        else
        {
          mainArray[i].count=mainArray[i].count + 1;
        }
        if(count==arraySize)
        {
              DAcounter++;
              arraySize=arraySize*2;
              wordItem* tempArray= new wordItem[arraySize];
              for (int k=0;k<currentArrayCount;k++)
              {
                tempArray[k]=mainArray[k];
              }
              delete [] mainArray;

              mainArray=tempArray;
          }

        }

      }


    arraySort(mainArray,currentArrayCount);
    printTopN(mainArray,stoi(argv[1]));
    cout<<"#"<<endl;
    cout<<"Array doubled: "<<DAcounter<<endl;
    cout<<"#"<<endl;
    cout<<"Unique non-stop words: "<<count<<endl;
    cout<<"#"<<endl;
    cout<<"Total non-stop words: "<<getTotalNumberNonStopWords(mainArray,count)<<endl;


    return 0;
}

void getStopWords(const char *ignoreWordFileName, vector<string> &_vecIgnoreWords)
{
  ifstream stopstream;
  stopstream.open(ignoreWordFileName);
  string line="";
  if (stopstream.is_open())
  {
      while(getline(stopstream,line))
      {
        // cout<<line<<endl;
        _vecIgnoreWords.push_back(line);
      }
  }
  else
  {
    cout<<"Filename error."<<endl;
  }


}

bool isStopWord(string word, vector<string> &_vecIgnoreWords)
{
    if (count(_vecIgnoreWords.begin(),_vecIgnoreWords.end(),word))
    {

        return true;

    }

    return false;


}

int getTotalNumberNonStopWords(wordItem list[], int length)
{

    int sum=0;
    for (int i=0;i<length;i++)
    {
      sum=sum+list[i].count;
    }
    return sum;
}

void arraySort(wordItem list[], int length)
{
  for (int i=0;i<length-1;i++)
  {
    for (int j=0;j<length-i-1;j++)
    {
      if (list[j].count<list[j+1].count)
      {
        swap(list[j],list[j+1]);
      }
    }
  }
}

void printTopN(wordItem wordItemList[], int topN)
{
    for (int i=0;i<topN;i++)
    {
      cout<<wordItemList[i].count<<" - "<<wordItemList[i].word<<endl;
    }
}
