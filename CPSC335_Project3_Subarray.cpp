#include <vector>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int returnVals[2];

void subarrayGen(vector<int> fullArray)
{
    int largest = 0;
    for(int i = 0; i < fullArray.size(); i++)
    {
        for(int j = i; j < fullArray.size(); j++)
        {
            int c = i, summation = 0;;
            while(c <= j)
            {
                summation += fullArray[c];
                c++;
            }
            if (summation > largest)
            {
                largest = summation;
                returnVals[0] = i;
                returnVals[1] = j;
            }
        }
    }
}

int main()
{
    vector<int> fullArray;
    string hold, temp = "";
    int count = 0, inElem;

    cout << "Please input the array you'd like to check, separating each element with a comma (no spaces and enclosed in parentheses please): ";
    getline(cin, hold);
    for (int count = 1; count < hold.size()-1; count++)
    {
        stringstream elem;
        if(hold[count] != ',')
        {
            temp += hold[count];
        }
        else
        {
            elem << temp;
            elem >> inElem;
            fullArray.push_back(inElem);

            temp = "";
        }
    }
    stringstream elem;
    elem << temp;
    elem >> inElem;
    fullArray.push_back(inElem);

    subarrayGen(fullArray);
    
    cout << "(";
    for(int i = returnVals[0]; i < (returnVals[1]+1); i++)
    {
        cout << fullArray[i];
        if(i != returnVals[1])
            cout << ", ";
    }
    cout << ")" << endl;
}

