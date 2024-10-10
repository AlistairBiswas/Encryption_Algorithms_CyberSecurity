#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, char> HashMap;

    string alphabet =     "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string substitution = "qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    string msg = "Paul Says Wassup";
    cout<<"Plain Text: "<<msg<<endl;
    // Encryption
    for (int i = 0; i < alphabet.size(); i++) {
        HashMap.insert(make_pair(alphabet[i], substitution[i]));
    }

    string cipher = "";
    for (int i = 0; i < msg.size(); i++) {
        cipher.push_back(HashMap[msg[i]]);
    }
    cout << "Encrypted Cipher Text: " << cipher << endl;

    return 0;
}
