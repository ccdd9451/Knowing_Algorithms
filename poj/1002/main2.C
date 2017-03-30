#include <string>
#include <iostream>
#include <map>
using namespace std;

int main(int argc, char *argv[])
{
    int linenum, i;
    string readline;
    char translator[256] = {};
    const char* A2P="2223334445556667";
    const char* R2Z="77888999";
    const char* NUM="0123456789";
    memcpy(&translator['A'], A2P, strlen(A2P));
    memcpy(&translator['R'], R2Z, strlen(R2Z));
    memcpy(&translator['0'], NUM, strlen(NUM));
    cin >> linenum;
    std::map<string, int> addbook;
    std::map<string, int> addbook_duped;
    for (i = 0; i < linenum+1; ++i) {
        getline(cin, readline);
        string address;
        for (string::iterator it = readline.begin();
                it != readline.end(); ++it) {
            char current_num = translator[*it];
            if (current_num) {
            address.push_back(current_num);
            }
        }
        if (++addbook[address]>1)
            addbook_duped[address] = addbook[address];
    }
    if (addbook_duped.empty())
        cout << "No duplicates.";
    else {
        for (map<string,int>::iterator it = addbook_duped.begin();
                it != addbook_duped.end(); ++it) {
            string address = it->first;
            int count = it->second;
            cout << address.substr(0,3) << '-'
                << address.substr(3,4) << ' '
                << count << endl;
        }
    }
    return 0;
}
