#include "./../../DS/stack.cpp"

int main()
{
    stacky<char> s1; // Initializing the stack.
    string s;        // Initializing the string whose input will be taken.
    cout << " We are here to check whether a string is palindrome or not :) ??" << endl;
    cout << " Give the input of a string" << endl;
    cin >> s;

    for (int i = 0; i < s.size() / 2; i++)
    {
        s1.push(s[i]);
    }

    for (int i = s.size() % 2 ? (s.size() / 2 + 1) : (s.size() / 2); i < s.size(); i++)
    {
        char temp = s1.pop();

        if (s[i] != temp)
        {
            cout << "Invalid" << endl;
            exit(1);
        }
    }

    cout << "Yes the given string is a palindrome" << endl;

    return 0;
}