#include <vector>
#include <sstream>
#include <iostream>
#include <string>
using namespace std;

int returnVals[2];

void test(int a, int b)
{
    a += 2;
    b += 3;
    
    returnVals[0] = a;
    returnVals[1] = b;
}

void subarrayGen(vector<int> fullArray)
{
    //largest = 0 sum
    //b = largest sum b; e = largest sum e
    //for (b)
        // for(e=b)
            //sum b:e
            //if sum b:e > largest
                // largest = sum b:e
                // b = this b
                // e = this e
    // returnVals 0 and 1 = b and e
}
int main()
{
    vector<int> fullArray;
    string hold, temp = "";
    int count = 0, inElem;
    // just to test returning two at once, delete in final v
    int test1 = 0, test2 = 2;
    test(test1, test2);

    cout << "Please input the array you'd like to check, separating each element with a comma (no spaces please): ";
    getline(cin, hold);
    for (int count = 0; count < hold.size(); count++)
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

    //just to test an above function, delete in final v
    cout << "(";
    for(int i = 0; i < 2; i++)
    {
        cout << returnVals[i];
        if(i == 0)
            cout << ", ";
    }
    cout << ")" << endl;

    for(int j = 0; j < fullArray.size(); j++)
    {
        cout<< fullArray[j] << " ";
    }
}

