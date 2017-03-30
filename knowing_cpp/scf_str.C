#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string input;
    getline(cin, input);
    for (char i : input) {
        printf("%c\n", i);
    }
    return 0;
}
