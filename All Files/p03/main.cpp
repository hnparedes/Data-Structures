#include <iostream>
#include <vector>

using namespace std;

int firstUniqChar(string s) {
    // hash table for frequency of each character
    vector<int> freq(26, 0);

    // First pass: count frequency of each character
    for(char c : s)
    {
        
        freq[c - 'a']++;
        
    }

    // Second pass: find the first character with frequency 1
    
    for(int i = 0; i < s.length(); i++)
    {
        
        if(freq[s[i] - 'a'] == 1)
        {
            
            return i;
            
        }
        
    }
    
    return -1;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;

    int index = firstUniqChar(s);

    if (index == -1)
        cout << "No non-repeating character found.\n";
    else
        cout << "The index of the first non-repeating character is: " << index << endl;

    return 0;
}