#include <iostream>
static int count;
class Fraction {
private:
    int x, y; 
    double decimalFrac;
public:
        Fraction() {

        }

        Fraction(int valX, int valY) {
            if (valY == 0)
            {
                x = 0;
                y = 1;
                std::cout << "Введены некорректные данные, программа завершает работу!" << std::endl;
                exit(0);
            }
            else
            {
                x = valX;
                y = valY;
                count++;
            }
        }

        Fraction(double decimalF) {
            decimalFrac = decimalF;
            count++;
        }

        void printFrac(Fraction frac) {                    
                std::cout << frac.x << "/" << frac.y << std::endl;          
        }

        void printDecimalFrac(Fraction frac) {
            frac.x = frac.decimalFrac * 100;
            frac.y = 100;
            std::cout << frac.x << "/" << frac.y << std::endl;
        }

        void printDecimalRedFrac(Fraction frac) {
            frac.x = frac.decimalFrac*100;
            frac.y = 100;
            frac.reduce();
            std::cout << frac.x << "/" << frac.y << std::endl;
        }

        void reduce() {
            int act,i;
            do {
                if (x < y)
                    act = x;
                else
                    act = y;
                for (i = act; i > 0; i--)
                {
                    if (!(x % i) && !(y % i))
                    {
                        x /= i;
                        y /= i;
                        break;
                    }
                }
            } while (i != 1);
        }

        int gcd(int valX, int valY) {
            while (valX != valY)
            {
                if (valX > valY)
                    valX = valX - valY;
                else
                    valY = valY - valX;
            }
            std::cout << valX << std::endl;
            return valX;
        }

        int GetX(Fraction frac) {
            return frac.x;
        }

        int GetY(Fraction frac) {
            return frac.y;
        }

        double GetDecimal(Fraction frac) {
            return frac.decimalFrac;
        }

        Fraction operator + (const Fraction& other);
        Fraction operator - (const Fraction& other);
        Fraction operator * (const Fraction& other);
        Fraction operator / (const Fraction& other);

        ~Fraction() {
            /*std::cout << "Память была очищена!" << std::endl;*/
        }
};

Fraction Fraction::operator + (const Fraction& other) {
    Fraction temp;
    temp.x = x * other.y + y * other.x;
    temp.y = y * other.y;
    return temp;
};

Fraction Fraction::operator - (const Fraction& other) {
    Fraction temp;
    temp.x = x * other.y - y * other.x;
    temp.y = y * other.y;
    return temp;
};

Fraction Fraction::operator * (const Fraction& other) {
    Fraction temp;
    temp.x = x * other.x;
    temp.y = y * other.y;
    return temp;
};

Fraction Fraction::operator / (const Fraction& other) {
    Fraction temp;
    temp.x = x * other.y;
    temp.y = y * other.x;
    return temp;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Fraction drob1(35, 205);
    Fraction drob2(4, 20);
    Fraction drob3(15, 100);
    std::cout << "НОД дроби 1:" << std::endl;
    drob1.gcd(drob1.GetX(drob1), drob1.GetY(drob1));
    std::cout << "НОД дроби 2:" << std::endl;
    drob2.gcd(drob2.GetX(drob2), drob2.GetY(drob2));
    std::cout << "НОД дроби 3:" << std::endl;
    drob3.gcd(drob3.GetX(drob3), drob3.GetY(drob3));
    drob1.reduce();
    drob2.reduce();
    drob3.reduce();
    std::cout << "Дробь 1 в сокращенном виде: " << std::endl;
    drob1.printFrac(drob1);
    std::cout << "Дробь 2 в сокращенном виде: " << std::endl;
    drob2.printFrac(drob2);
    std::cout << "Дробь 3 в сокращенном виде: " << std::endl;
    drob3.printFrac(drob3);
    std::cout << "Произведение дробей: " << std::endl;
    drob1.printFrac(drob1 * drob2);
    std::cout << "Частное дробей: " << std::endl;
    drob1.printFrac(drob1 / drob2);
    std::cout << "Сумма дробей: " << std::endl;
    drob1.printFrac(drob1 + drob2);
    std::cout << "Разность дробей: " << std::endl;
    drob1.printFrac(drob1 - drob2);
    Fraction decimalFrac(0.25);
    std::cout << "Входная дробь(double): " << std::endl;
    std::cout << decimalFrac.GetDecimal(decimalFrac);
    std::cout << "\nДесятичная дробь: " << std::endl;
    decimalFrac.printDecimalFrac(decimalFrac);
    std::cout << "Обычная дробь дробь: " << std::endl;
    decimalFrac.printDecimalRedFrac(decimalFrac);
    std::cout << "Всего было создано дробей: " << count << std::endl;
}
