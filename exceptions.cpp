#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

class Except_1 {};

class Except_2 {
    string msg;
    
public:
    Except_2(const string &s) : msg(s) {}
    const char *message() const 
    { 
        return msg.c_str(); 
    }
};

class Except_3 : public Except_2 {};


int main()
{
    string a_input, b_input, c_input;
    double a, b, c, x;
    
    cout << "Type a: "; cin >> a_input;
    cout << "Type b: "; cin >> b_input;
    cout << "Type c: "; cin >> c_input;
    
    try {
        a = stoi(a_input), b = stoi(b_input), c = stoi(c_input);
    }
    
    catch (...) {
        cout << "Incorrect data input";
        return 1;
    }
    
    
    if((b*b - 4*a*c) >= 0)
    {
        x = ( -1*b + sqrt(b*b - 4*a*c) ) / (2 * a);
        cout << "First root" << x << endl;
        
        x = ( -1*b - sqrt(b*b - 4*a*c) ) / (2 * a);
        cout << "Second root" << x << endl;
    }
    else
    {
        cout << "D < 0, roots insubstantial." << endl;
    }

    return 0;
}
