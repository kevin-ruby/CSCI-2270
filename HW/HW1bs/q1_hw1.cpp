#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
    int track=-1;

    for (int i=0;i<numEntries;i++)
    {
        if(newValue<myArray[i])
        {
            track=i;
            break;
        }
    }
    if (track==-1)
    {
        track=numEntries;
    }

    for (int i=numEntries;i>track;i--)
    {
        myArray[i]=myArray[i-1];
    }

    myArray[track]=newValue;

    for (int i=0;i<numEntries+1;i++)
    {
        cout<<","<<myArray[i];
    }
    cout<<endl;

    return numEntries+1;
}

int main(int argc, char* argv[])
{
    if(argc!=2)
    {
        cout<<"Error! Enter Filename "<<endl;
        return 1;
    }
    cout<<argv[1]<<endl;

    ifstream infile;
    string line;
    int number=0;
    int myArray[100];
    int numEntries=0;

    infile.open(argv[1]);

    if (infile.is_open())
    {
        while(getline(infile,line))
        {
            number=stoi(line);
            insertIntoSortedArray(myArray,numEntries,number);
            numEntries++;
        }
    }





}
