/*Создать класс Man (человек), с полями: имя, возраст, пол и вес. 
Определить методы переназначения имени, изменения возраста и изменения веса. 
Создать производный класс Student, имеющий поле года обучения. 
Определить методы переназначения и увеличения года обучения.
*/


#include <iostream>
#include <string>

using namespace std;


class Man {
    public:
        string name;
        int age;
        bool gender;
        double weight;
        
        Man (string name_set, int age_set, bool gender_set, double weight_set) {
            if (age_set < 1 or age_set > 130) {
                cout << "Incorrect age for " << name_set;
                exit(1);
            }
            else age = age_set;
            
            if (weight_set < 0.2) {
                cout << "Incorrect weight for " << name_set;
                exit(1);
            }
            else weight = weight_set;
            
            name = name_set;
            age = age_set;
            gender = gender_set;
            weight = weight_set;
        }
        
        
    
    
        void change_name(Man &object, string new_name) {
            object.name = new_name;
        }
        
        void change_age(Man &object, int new_age) {
            if (new_age < 1) {
                cout << "Incorrect age for " << name;
                exit(1);
            }
            else object.age = new_age;
        }
        
        void change_weight(Man &object, double new_weight) {
            if (new_weight < 0.2) {
                cout << "Incorrect weight for " << name;
                exit(1);
            }
            else object.weight = new_weight;
        }
};


class Student : public Man
    {
    public:
        int study_year;
        
        using Man::Man;
        
        
        void change_year(Student &object, int new_year) {
            if (new_year < 1900 or new_year > 2022) {
                cout << "Incorrect year for " << name;
                exit(1);
            }
            else object.study_year = new_year;
        }
        
        void year_add(Student &object, int add_year) {
            if (add_year < 0) {
                cout << "Incorrect year for " << name;
                exit(1);
            }
            else object.study_year += add_year;
        }
    };


int main()
{
    Man a("Инокентий", 17, 1, 59.03);
    Student b("Зинаида", 120, 0, 50);
    
    cout << a.name << endl << a.age << endl << a.gender << endl << a.weight << endl << endl;
    a.change_name(a, "Анатолий");
    cout << a.name << endl << a.age << endl << a.gender << endl << a.weight << endl << endl;
    
    b.change_name(b, "Ирина");
    cout << b.name << endl << b.age << endl << b.gender << endl << b.weight << endl << b.study_year << endl << endl;
    
    b.change_year(b, 2000);
    b.year_add(b, 10);
    cout << b.name << endl << b.age << endl << b.gender << endl << b.weight << endl << b.study_year << endl << endl;


    return 0;
}
