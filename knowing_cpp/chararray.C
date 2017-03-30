#include <iostream>

int main(int argc, char *argv[])
{
    char translator[256] = {};
    char first[]="2223334445556667";
    char last[]="77888999";
    memcpy(&translator['A'], first, strlen(first));
    memcpy(&translator['R'], last, strlen(last));

    for (int i = 0; i < 256; ++i) {
        fputc(translator[i], stdout);
    }
    return 0;
}
