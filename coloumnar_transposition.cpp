#include <bits/stdc++.h>
using namespace std;
int main()
{
    int len = 100, col = 4, index = 0;
    char text[len] = "meet me after the party", key[col] = "HACK", sortKey[len];
    char data[col][len] = {0};
    char outputText[len] = {0};

    for (int i = 0; i < len; i++)
    {
        char temp = text[i];
        if (temp != ' ')
        {
            int position = index % (col);
            data[position][index / col] = temp;
            index++;

        }
    }

    strcpy(sortKey, key);
    sort(sortKey, sortKey + strlen(sortKey));

    for (int i = 0; i < strlen(sortKey); i++)
    {
        int position;
        for (int j = 0; j < strlen(key); j++)
        {
            if (sortKey[i] == key[j])
            {
                position = j;
                break;
            }
        }
        for (int j = 0; j < index / col; j++)
        {
            outputText[strlen(outputText)] = data[position][j];
        }
        if (strlen(data[position]) < strlen(data[0]))
        {
            outputText[strlen(outputText)] = 'x';
        }
    }

    cout << "Plain Text: " << text << endl;
    cout << "Key: " << key << endl;
    cout << "Encrypted Cipher Text: " << outputText << endl;

    return 0;
}
