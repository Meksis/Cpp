#include <iostream>
#include <string>
#include <string.h>

using namespace std;


class Array {
    public:
        static const int n = 10;
    
        int array_size;
        int number_remake = 53001;
        int razrad = 1;
        
        unsigned char array[n];
        
        Array () {
            
            
            
            array_size = sizeof array / sizeof array[0];
            
            if (number_remake < 0) array[0] = '-';
            else array[0] = '+';
        
        
            while (number_remake > 0) {
                array[razrad] = (char(number_remake % 10)+0);
                number_remake = number_remake / 10;
                razrad++;
            };
        }
        
        
        unsigned char & operator[] (int index) {
            if (index >= 0 and index < array_size) return array[index];
            else throw("Incorrect index");
        }
        
        friend ostream& operator <<(ostream& out, Array& a)
        {
            for(int index = 0; index < a.array_size; index++)
            {
                out << (int)a.array[index] << ",";
            }
            out << endl;
            return out;
        }
        
        
        virtual unsigned char summator(unsigned char b[n]) {
            for (int counter = 0; counter < array_size; counter ++) array[counter] = array[counter] + b[counter];
            return *array;
        }
        
        
        
        
        
        
};

class BitString : public Array {
    public:
    
        unsigned char bit_string[100];
        
        BitString () {
            for (int counter = 0; counter < 100; counter ++) {
                if (counter < 49) bit_string[counter] = char(1);
                else bit_string[counter] = char(0);
            }
        }
    
        virtual unsigned char summator(unsigned char b[n]) {
            for (int counter = 0; counter < array_size; counter ++) array[counter] = array[counter] + b[counter];
            return *array;
        }
};

class Decimal2 : public Array {
        public:
        virtual unsigned char summator(unsigned char b[n]) {
            for (int counter = 0; counter < array_size; counter ++) array[counter] = array[counter] + b[counter];
            return *array;
        }
};



int main() {
    BitString arr;
    unsigned char test[10];
    
    for (int counter = 0; counter < 10; counter ++) {
        test[counter] = '1';
    }
    return 0;
}

/*Создать 
класс Decimal (Класс для работы со знаковыми целыми десятичными числами, использует для представления числа массив из 100 элементов типа unsigned char, 
каждый из которых является десятичной цифрой. Младшая цифра имеет меньший индекс (единицы - в нулевом элементе массива). Знак представляется отдельным полем sing.) 

класс BitString (Класс для работы с битовыми строками не более чем из 100 бит. Битовая строка должна быть представлена массивом типа unsigned char, каждый элемент 
которого принимает значение 0 или 1.).
*/
