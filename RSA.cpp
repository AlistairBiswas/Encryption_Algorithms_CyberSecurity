#include <bits/stdc++.h>
using namespace std;

int limit = 500;
vector<bool> isPrimeList;

void sieveOfEratosthenes()
{
    isPrimeList.resize(limit + 1, true);
    isPrimeList[0] = isPrimeList[1] = false;
    for (int i = 2; i * i <= limit; i++)
    {
        if (isPrimeList[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                isPrimeList[j] = false;
            }
        }
    }
}

bool isPrime(int num)
{
    return (num >= 0 && num < isPrimeList.size() && isPrimeList[num]);
}

int calculateGCD(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long mod_pow(long long base, long long exp, long long mod) { //(2 ^ 10)mod7.
    long long result = 1;
    base = (base % mod + mod) % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }

    return result;
}

int main()
{
    sieveOfEratosthenes();
    int p, q;

    // Key Setup
    cout << "Enter the value of p: ";
    cin >> p;

    cout << "Enter the value of q: ";
    cin >> q;

    if ((!isPrime(p)) || (!isPrime(q)))
    {
        cout << "Enter prime numbers!!!";
        return 0;
    }

    string msg;
    cout << "Enter the plain text: ";
    fflush(stdin);
    getline(cin, msg);

    vector<int> message;
    for (char ch : msg)
    {
        message.push_back(static_cast<int>(ch));
    }

    int n, phi_n;
    n = p * q;
    phi_n = (p - 1) * (q - 1);

    // calculate e
    int e, d;
    for (e = 2; e < phi_n; e++)
    {
        if (calculateGCD(e, phi_n) == 1)
        {
            break;
        }
    }
    // calculate d
    e = e % phi_n;
    int i;
    for (i = 1; i < phi_n; i++) {
        if ((e * i) % phi_n == 1) {
            break;
        }
    }
    d = i;

    cout << "Public Encryption Key {e, n}: " << "{" << e << "," << n << "}" << endl;
    cout << "Public Decryption Key {d, n}: " << "{" << d << "," << n << "}" << endl;

    // Encryption
    vector<int> ciphertext;
    cout << "\nEncrypted message: ";
    for (int ch : message)
    {
        ciphertext.push_back(mod_pow(ch, e, n));
        cout << mod_pow(ch, e, n) << " ";
    }

    // Decryption
    vector<int> decryptedMessage;
    cout << "\n\nDecrypted message: ";
    for (int ch : ciphertext)
    {
        decryptedMessage.push_back(mod_pow(ch, d, n));
        cout << static_cast<char>(mod_pow(ch, d, n));
    }
    cout<<endl;

    return 0;
}
