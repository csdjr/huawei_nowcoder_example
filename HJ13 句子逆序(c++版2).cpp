
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void word_reverse(string str)
{
    vector<string> vs;
    string s;
    char c = ' ';
    int pos1, pos2;

    pos1 = str.find_first_not_of(c);
    while (pos1 != std::string::npos)
    {
        pos2 = str.find_first_of(c, pos1);
        s = str.substr(pos1, pos2 - pos1);
        vs.push_back(s);
        pos1 = str.find_first_not_of(c, pos2);
    }

    for (vector<string>::reverse_iterator it = vs.rbegin(); it != vs.rend();)
    {
        cout << *it;
        if (++it != vs.rend())
            cout << " ";
        else
            cout << endl;
    }
}

int main(int argc, char *argv[])
{
    string str;               //string str = "I am a student";
    while (getline(cin, str)) //输入字符串
    {
        word_reverse(str);
    }
    return 0;
}