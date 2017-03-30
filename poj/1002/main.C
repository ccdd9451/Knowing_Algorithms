#include <map>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string readline;
    getline(cin, readline);
    map<char, char> translator;
    map<string, int> contacts;
    translator['A'] = translator['B'] = translator['C'] = '2';
    translator['D'] = translator['E'] = translator['F'] = '3';
    translator['G'] = translator['H'] = translator['I'] = '4';
    translator['J'] = translator['K'] = translator['L'] = '5';
    translator['M'] = translator['N'] = translator['O'] = '6';
    translator['P'] = translator['R'] = translator['S'] = '7';
    translator['T'] = translator['U'] = translator['V'] = '8';
    translator['W'] = translator['X'] = translator['Y'] = '9';
    int linenum = stol(readline);
    for (int i = 0; i < linenum; ++i) {
        getline(cin, readline);
        string translated = "0000000";
        auto start = translated.begin();
        auto modifier = start;
        for (char x: readline) {
            char* num;
            if (x >= '0' && x <='9')
                num = &x;
            else
                num = &translator[x];
            if (*num) {
                *modifier = *num;
                modifier++;
            }
        }
        int& line = contacts[translated];
        if (!line)
            line = 1;
        else
            line++;
    }

    for (auto line: contacts){
        if (line.second > 1)
            printf ("%s %d\n", line.first.c_str(), line.second);
    }

    return 0;
}
