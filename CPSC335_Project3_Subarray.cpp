#include <vector>
#include <sstream>
#include <iostream>
using namespace std;

int returnVals[2];

void largestSubarray(vector<int> fullArray, int elemNum)
{
    int largest = 0;
    for(int i = 0; i < elemNum; i++)
    {
        for(int j = i; j < elemNum; j++)
        {
            int c = i, summation = 0;
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
    int count = 1, inElem, elemNum = 0;

    cout << "Please input the array you'd like to check, separating each element with a comma and enclosing it in parentheses: ";
    getline(cin, hold);
    for (count; hold[count] != ')'; count++)
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
            elemNum++;
            temp = "";
        }
    }
    stringstream elem;
    elem << temp;
    elem >> inElem;
    fullArray.push_back(inElem);
    elemNum++;

    largestSubarray(fullArray, elemNum);
    
    cout << "(";
    for(int i = returnVals[0]; i <= (returnVals[1]); i++)
    {
        cout << fullArray[i];
        if(i != returnVals[1])
            cout << ", ";
    }
    cout << ")" << endl;
}

