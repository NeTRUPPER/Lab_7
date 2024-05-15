#include <iostream>
#include <string>

using namespace std;

string decodeString(const string& s, size_t& i) {
    string result = "";

    while (i < s.length() && s[i] != ']') {
        if (!isdigit(s[i])) {
            result += s[i++];
        } 
        else {
            int count = 0;
            while (isdigit(s[i])) {
                count = count * 10 + (s[i++] - '0');
            }

            // Пропуск '['
            i++;
            string decodedString = decodeString(s, i);

            // Пропуск ']'
            i++;
            
            for (int j = 0; j < count; j++) {
                result += decodedString;
            }
        }
    }

    return result;
}

string decodeString(const string& s) {
    size_t i = 0;
    return decodeString(s, i);
}

int main() {
    string s = "3[a]2[bc]";
    cout << decodeString(s) << endl;

    s = "3[a2[c]]";
    cout << decodeString(s) << endl;

    s = "2[abc]3[cd]ef";
    cout << decodeString(s) << endl;

    return 0;
}
