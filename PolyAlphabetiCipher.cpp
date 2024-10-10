#include <bits/stdc++.h>
using namespace std;
int main()
{
    char plaintext[100];
    int alpha = 26;
    cout << "Enter the Plain Text: ";
    cin.getline(plaintext, sizeof(plaintext));

    cout << "Encrypted Cipher Text: ";
    int shift = 1;
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char ch = plaintext[i];
        if (isalpha(ch))
        {
            if (islower(ch))
                ch = (ch - 'a' + shift) % alpha + 'a';
            else
                ch = (ch - 'A' + shift) % alpha + 'A';

            cout << ch;
            shift = (shift + 1) % alpha;
        }
        else
        {
            cout << ch;
        }
    }
    cout << endl;

    return 0;
}
