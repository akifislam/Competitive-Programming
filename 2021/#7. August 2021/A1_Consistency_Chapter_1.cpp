//Akif Islam (__SHERLOCK__)
//Date: 2021-08-28 09:12:41
// I love Facebook :)

#include <bits/stdc++.h>
#define INF 1000
using namespace std;

char gap = 32;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << gap << x;
    return os << '}';
}

#define ll long long
#define pb push_back
#define All(x) (x).begin(), (x).end()

bool checkForVowel(char X)
{
    if (X == 'A' || X == 'E' || X == 'I' || X == 'O' || X == 'U')
        return true;

    return false;
}

int tc = 0;

void solve()
{
    string str;
    cin >> str;

    ll SIZE = str.size();
    // ll answer = INF;

    map<char, int> freq;

    char s = 'A';

    // Set A to Z to 0
    for (int i = 0; i < 26; i++)
    {
        freq[s] = 0;
        s++;
    }

    //Check Freq
    int countVowel = 0;
    int countConsonant = 0;

    for (int i = 0; i < SIZE; i++)
    {
        freq[str[i]]++;
        if (checkForVowel(str[i]))
            countVowel++;
    }
    countConsonant = SIZE - countVowel;

    // cout << "Vowel : " << countVowel << endl;
    // cout << "Consonant : " << countConsonant << endl;

    // CASE 0 : SIZE 1
    if (SIZE == 1)
    {
        cout << "Case #" << ++tc << ": " << 0 << endl;
        return;
    }
    //Case 1 : All letters are vowel
    if (countConsonant == 0)
    {
        cout << "Case #" << ++tc << ": " << SIZE << endl;

        return;
    }

    //Case 2 : All letters are consonant
    if (countVowel == 0)
    {
        cout << "Case #" << ++tc << ": " << SIZE << endl;

        return;
    }

    // Search for the Most Frequented Vowel and Consonant
    char most_freq_vowel;
    char most_freq_consonant;

    char temp_char = '*';
    int temp_val = -1;

    // Most Vowel
    for (auto x : freq)
    {
        if (x.second > temp_val && checkForVowel(x.first))
        {
            temp_char = x.first;
            temp_val = x.second;
        }
    }
    most_freq_vowel = temp_char;

    temp_char = '*';
    temp_val = -1;

    // Most Consonant
    for (auto x : freq)
    {
        if (x.second > temp_val && !checkForVowel(x.first))
        {
            temp_char = x.first;
            temp_val = x.second;
        }
    }
    most_freq_consonant = temp_char;

    // cout << "Most Freq Vowel : " << most_freq_vowel << endl;
    // cout << "Most Freq Cons : " << most_freq_consonant << endl;

    //Process
    ll answer = INF;
    ll count = 0;

    //For Vowel
    for (int i = 0; i < SIZE; i++)
    {
        if (str[i] == most_freq_vowel)
            continue;
        count++;
        if (checkForVowel(str[i]))
            count++;
    }
    // cout << "VowAns:" << count << endl;
    answer = min(answer, count);

    //For Consonant
    count = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (str[i] == most_freq_consonant)
            continue;
        count++;
        if (!checkForVowel(str[i]))
            count++;
    }
    // cout << "ConsAns:" << count << endl;
    answer = min(answer, count);

    cout << "Case #" << ++tc << ": " << answer << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}