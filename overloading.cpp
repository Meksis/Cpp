#include <iostream>

using namespace std;

struct Vector3
{
	int x, y, z;

	
	Vector3(int x, int y, int z) : x(x), y(y), z(z) {
	}
	
	Vector3 operator = (Vector3 v1)
    {
    	this->x = v1.x, this->y = v1.y, this->z = 0;
    	return *this;
    }
};


int main()
{
    
    Vector3 a(1,1,1);
    
    Vector3 b(2,3,200);
    
    cout << a.x << endl;
    cout << a.y << endl;
    cout << a.z << endl;
    cout << endl;
    
    a = b;
    
    cout << a.x << endl;
    cout << a.y << endl;
    cout << a.z << endl;
    cout << endl;
    
    cout << b.x << endl;
    cout << b.y << endl;
    cout << b.z << endl;
    
    return 0;
}
