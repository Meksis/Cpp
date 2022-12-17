#include <iostream>
#include <string>
#include <cmath>

#define PI 3.14159265

using namespace std;


int top_angle, base_side;
string input;


struct triangle
{
    double angles[3], sides[3];
    int base_side, top_angle;
};


void get_angles(triangle &tri_object) {
        for (int angles_counter = 0; angles_counter < 3; angles_counter++) {
            cout << endl << "[*] Angle " << angles_counter + 1 << " now is " << tri_object.angles[angles_counter] << endl;
        }
        cout << endl;
    }

void set_angles(triangle &tri_object) {
        for (int angles_counter = 0; angles_counter < 3; angles_counter++) {
            cout << endl << "Type " << angles_counter + 1 << " angle "; cin >> input;
            tri_object.angles[angles_counter] = ::atof(input.c_str());;
        }
        get_angles(tri_object);

        cout << "Which angle is a top? (1-3) "; cin >> input;
        top_angle = stoi(input) - 1;
    }
    
    
void get_sides(triangle &tri_object) {
        for (int sides_counter = 0; sides_counter < 3; sides_counter++) {
            cout << endl << "[*] Side " << sides_counter + 1 << " now is " << tri_object.sides[sides_counter] << endl;
        }
        cout << endl;
    }

void set_sides(triangle &tri_object) {
        for (int sides_counter = 0; sides_counter < 3; sides_counter++) {
            cout << endl << "Type " << sides_counter + 1 << " side "; cin >> input;
            tri_object.sides[sides_counter] = ::atof(input.c_str());;
        }
        get_sides(tri_object);

        cout << "Which side is a base? (1-3) "; cin >> input;
        base_side = stoi(input) - 1;
    }

    

double perimeter(bool is_ret, triangle &tri_object) {
        double triangle_perimeter = tri_object.sides[0] + tri_object.sides[1] + tri_object.sides[2];

        if (is_ret) return triangle_perimeter;
        else cout << "Triangle perimeter is " << triangle_perimeter << endl;

    }

double square(bool is_ret, triangle &tri_object) {
        //float triangle_semi_perimeter = perimeter(1) / 2.0;
        //float triangle_square = 2.0 / sides[base_side] * sqrt(triangle_semi_perimeter * (triangle_semi_perimeter - sides[0]) * (triangle_semi_perimeter - sides[1]) * (triangle_semi_perimeter - sides[2]));

        double triangle_square = sin(tri_object.angles[0] * PI / 180) * tri_object.sides[0] * tri_object.sides[2] / 2;

        if (is_ret) return triangle_square;
        else cout << "Triangle\'s square is " << triangle_square << endl;
    }

void heights(triangle &tri_object) {
        float triangle_heights[3];

        for (int heights_counter = 0; heights_counter < 3; heights_counter++) {
            triangle_heights[heights_counter] = 2.0 * square(1, tri_object) / tri_object.sides[heights_counter];

            cout << "Triangle\'s height to " << heights_counter + 1 << " side is " << triangle_heights[heights_counter] << endl;
        }
    }

string triangle_type(triangle &tri_object) {
        string output = "";
        if (tri_object.sides[0] == tri_object.sides[1] == tri_object.sides[2]) output += "Triangle is equilateral\n";
        else if (tri_object.sides[0] == tri_object.sides[1] or tri_object.sides[1] == tri_object.sides[2] or tri_object.sides[2] == tri_object.sides[0]) output += "Triangle is isosceles\n";

        if (tri_object.angles[0] == 90.0 or tri_object.angles[1] == 90.0 or tri_object.angles[2] == 90.0) output += "Triangle is rectangular\n";

        if (output.size() == 0) return "It\'s versatile triangle\n";
        else return output;

    }



    




class Triangle {
private:
    double angles[3], sides[3];
    int base_side, top_angle;

public:
    void set_angles() {
        string input;

        for (int angles_counter = 0; angles_counter < 3; angles_counter++) {
            cout << endl << "Type " << angles_counter + 1 << " angle "; cin >> input;
            angles[angles_counter] = ::atof(input.c_str());;
        }
        get_angles();

        cout << "Which angle is a top? (1-3) "; cin >> input;
        top_angle = stoi(input) - 1;
    }

    void get_angles() {
        for (int angles_counter = 0; angles_counter < 3; angles_counter++) {
            cout << endl << "[*] Angle " << angles_counter + 1 << " now is " << angles[angles_counter] << endl;
        }
        cout << endl;
    }

    void set_sides() {
        string input;

        for (int sides_counter = 0; sides_counter < 3; sides_counter++) {
            cout << endl << "Type " << sides_counter + 1 << " side "; cin >> input;
            sides[sides_counter] = ::atof(input.c_str());;
        }
        get_sides();

        cout << "Which side is a base? (1-3) "; cin >> input;
        base_side = stoi(input) - 1;
    }

    void get_sides() {
        for (int sides_counter = 0; sides_counter < 3; sides_counter++) {
            cout << endl << "[*] Side " << sides_counter + 1 << " now is " << sides[sides_counter] << endl;
        }
        cout << endl;
    }

    double perimeter(bool is_ret) {
        double triangle_perimeter = sides[0] + sides[1] + sides[2];

        if (is_ret) return triangle_perimeter;
        else cout << "Triangle perimeter is " << triangle_perimeter << endl;

    }

    double square(bool is_ret) {
        //float triangle_semi_perimeter = perimeter(1) / 2.0;
        //float triangle_square = 2.0 / sides[base_side] * sqrt(triangle_semi_perimeter * (triangle_semi_perimeter - sides[0]) * (triangle_semi_perimeter - sides[1]) * (triangle_semi_perimeter - sides[2]));

        double triangle_square = sin(angles[0] * PI / 180) * sides[0] * sides[2] / 2;

        if (is_ret) return triangle_square;
        else cout << "Triangle\'s square is " << triangle_square << endl;
    }

    void heights() {
        float triangle_heights[3];

        for (int heights_counter = 0; heights_counter < 3; heights_counter++) {
            triangle_heights[heights_counter] = 2.0 * square(1) / sides[heights_counter];

            cout << "Triangle\'s height to " << heights_counter + 1 << " side is " << triangle_heights[heights_counter] << endl;
        }
    }

    string triangle_type() {
        string output = "";
        if (sides[0] == sides[1] == sides[2]) output += "Triangle is equilateral\n";
        else if (sides[0] == sides[1] or sides[1] == sides[2] or sides[2] == sides[0]) output += "Triangle is isosceles\n";

        if (angles[0] == 90.0 or angles[1] == 90.0 or angles[2] == 90.0) output += "Triangle is rectangular\n";

        if (output.size() == 0) return "It\'s versatile triangle\n";
        else return output;

    }
};


int main()
{
    /*
    float item_cost_inp = 3.89;
    int item_amount_inp = 100;

    building test_structure = {item_cost_inp , item_amount_inp};
    system("chcp 1251");

    cout << count(test_structure) << endl;
    */
    cout << "      /\\" << endl;
    cout << "     /  \\" << endl;
    cout << "  1 /  2 \\  2" << endl;
    cout << "   /1    3\\" << endl;
    cout << "  ----------" << endl;
    cout << "     3" << endl;

    
    
    //cout << triangle_object.triangle_type();
    
    triangle triangle_struct;
    
    
    cout << "TYPE STRUCT VALS\n";
    
    set_sides(triangle_struct);
    get_sides(triangle_struct);
    
    set_angles(triangle_struct);
    get_angles(triangle_struct);
    
    perimeter(0, triangle_struct);
    square(0, triangle_struct);
    heights(triangle_struct);
    triangle_type(triangle_struct);
    
    
    Triangle triangle_object;

    triangle_object.set_sides();
    triangle_object.set_angles();

    while (true) {
        cout << "\nType operation - get- or set- sides or angles, perimeter, square, heights or triangle-type. ";
        cin >> input;

        if (input == "get-sides") triangle_object.get_sides();
        else if (input == "get-angles") triangle_object.get_angles();
        else if (input == "set-sides") triangle_object.set_sides();
        else if (input == "set-angles") triangle_object.set_angles();
        else if (input == "perimeter") triangle_object.perimeter(0);
        else if (input == "square") triangle_object.square(0);
        else if (input == "heights") triangle_object.heights();
        else if (input == "triangle-type") cout << triangle_object.triangle_type();
        else {
            cout << "Loop stopped ";
            break;
        }
    }
}