#include <iostream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

int main(void)
{
    stack<char> st;
    string num1, num2;
    cin >> num1 >> num2;

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    stoi(num1) > stoi(num2) ? cout << num1 : cout << num2;

    return 0;
}

