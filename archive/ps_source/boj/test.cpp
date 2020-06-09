#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
vector<char> op;

vector<int> newNum;


int main()
{
    string input;
    cin >> input;
    input += "N";
    string stream;

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '+' || input[i] == '-' || input[i] == 'N')
        {
            num.push_back(stoi(stream));
            op.push_back(input[i]);
            stream = "";
        } else
        {
            stream += input[i];
        }
    }

    int buffer = 0;

    for (int i = 0; i <num.size(); i++)
    {
        if (op[i] == '+' )
        {
            buffer += num[i];
        }
        else
        {
            buffer += num[i];
            newNum.push_back(buffer);
            buffer = 0;
        }
    }

    int res = newNum[0];
    for (int i = 1; i < newNum.size(); i++)
    {
        res -=newNum[i];
    }
    cout << res - buffer;
    return 0;
}
