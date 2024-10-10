#include <bits/stdc++.h>
using namespace std;

int main()
{
    string inputText = "the simplest";
    cout << "Plain Text: " << inputText << endl;

    int encryptionKey = 41532;
    int numColumns = 5;
    vector<string> data(numColumns), ans;

    int index = 0;
    for (int i = 0; i < inputText.size(); i++)
    {
        char ch = inputText[i];
        if (ch != ' ')
        {
            int pos = index % numColumns;
            data[pos].push_back(ch);
            index++;
        }
    }

    int flag = encryptionKey;
    stack<int> encryptionKeys;
    while (flag)
    {
        encryptionKeys.push(flag % 10);
        flag = flag / 10;
    }

    while (!encryptionKeys.empty())
    {
        int currentIndex = encryptionKeys.top() - 1;
        encryptionKeys.pop();

        ans.push_back(data[currentIndex]);
    }

    string encryptedText;
    for (int i = 0; i < data[0].size(); i++)
    {
        for (int j = 0; j < numColumns; j++)
        {
            if (i < ans[j].size())
            {
                encryptedText += ans[j][i];
            }
            else
            {
                encryptedText += 'x';
            }
        }
    }

    cout << "Encrypted Cipher Text: " << encryptedText << endl;

    return 0;
}
