/***********************************************************************\
Name: Omar Yossuf
SID: 900212166
Assignment: #06
Lab: #07
Instructor: Nada Abd-Elsattr
Course: CSCE 2203
Section: #01
Date: Oct 18th, 2022
\***********************************************************************/

#include <iostream>

using namespace std;

string Multiply(string, string);

string Add(string, string);

string Sub(string, string);

int main()
{
    cout << "Odd only: " << // odd
    endl << "\t" << Multiply("15243", "5424343") << endl << endl;
    
    cout << "Even only: " << // even
    endl << "\t" << Multiply("573844", "39483944") << endl << endl;
    
    cout << "Odd and even: " << // odd and even
    endl << "\t" << Multiply("4349234", "344937") << endl << endl;
    
    return 0;
}

string Multiply(string x, string y)
{
    string result;
    
    
    while (x.length() < y.length())
        x.insert(0, "0");
    while (y.length() < x.length())
        y.insert(0, "0");
    
    
    if(x.length() == 1 && y.length() == 1)
         result = to_string(stoi(x) * stoi(y));
    else
    {
        
        if(x.length() % 2)
        {
            x.insert(0, "0");
            y.insert(0, "0");
        }
        
        string a = x.substr(0, x.length() / 2), // x
               b = x.substr(x.length() / 2);
        
        string c = y.substr(0, y.length() / 2), // y
               d = y.substr(y.length() / 2);
        
        string A = Multiply(a, c);
        string C = Multiply(b, d);

        string B = Sub(
                       Sub(
                           Multiply(
                                    Add(a, b),
                                    Add(c, d)),
                           A),
                       C);
     
        result = Add(
                     Add(
                         (A + string(x.length(), '0')),
                         (B + string(x.length() / 2, '0'))),
                     C);
    }
    
    while(result[0] == '0' && result.length() > 1) // erase 0
        result.erase(0, 1);

    return result;
}

string Add(string x, string y)
{
    string result;
    
    while (x.length() < y.length())
        x.insert(0, "0");
    
    while (y.length() < x.length())
        y.insert(0, "0");
    
    
    long long  carry = 0, res = 0;
    
    long long  X, Y;
    
    for(long long i = x.length() - 1; i >= 0; i--)
    {
        X = x[i] - '0';
        Y = y[i] - '0';
        res = X + Y + carry;
        carry = res / 10;
        res %= 10;
        result.insert(0, to_string(res));
    }
    if(carry != 0)
        result.insert(0, to_string(carry));
    
    return result;
}

string Sub(string x, string y)
{
    string result;
    
    while (x.length() < y.length())
        x.insert(0, "0");
    while (y.length() < x.length())
        y.insert(0, "0");
    
    
    long long res = 0;
    long long X, Y;
    
    for(long long i = x.length() - 1; i >= 0; i--)
    {
        X = x[i] - '0';
        Y = y[i] - '0';
        
        if(X < Y)
        {
            if(x[i - 1] != 0)
                x[i - 1] -= 1;
            else
            {
                while (x[i - 1] == 0)
                {
                    x[i - 2] -= 1;

                    x[i - 1] += 9;
                }
            }
            X += 10;
        }
        res = X - Y;
        result.insert(0, to_string(res));
    }
    
    return result;
}
