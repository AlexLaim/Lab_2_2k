#include <iostream>
static int count;
class Fraction {
private:
    //Важные переменные класса
    int x, y; 
    double decimalFrac;
public:
    //Конструктор без параметров
        Fraction() {

        }
        //Конструктор с параметрами
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
                //Счетчик созданных дробей
                count++;
            }
        }
        //Конструктор для работы с double значениями
        Fraction(double decimalF) {
            decimalFrac = decimalF;
            //Счетчик созданных дробей
            count++;
        }
        //Вывод дроби на экран
        void printFrac(Fraction frac) {                    
                std::cout << frac.x << "/" << frac.y << std::endl;          
        }
        //Вывод double дроби на экран
        void printDecimalFrac(Fraction frac) {
            frac.x = frac.decimalFrac * 100;
            frac.y = 100;
            std::cout << frac.x << "/" << frac.y << std::endl;
        }
        //Вывод сокращенной double дроби на экран
        void printDecimalRedFrac(Fraction frac) {
            frac.x = frac.decimalFrac*100;
            frac.y = 100;
            frac.reduce();
            std::cout << frac.x << "/" << frac.y << std::endl;
        }
        //Сокращение дроби
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
        //НОД дроби
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
        //Получение числителя
        int GetX(Fraction frac) {
            return frac.x;
        }
        //Получение знаменателя
        int GetY(Fraction frac) {
            return frac.y;
        }
        //Получение double значения
        double GetDecimal(Fraction frac) {
            return frac.decimalFrac;
        }
        //Перегрузка операторов
        Fraction operator + (const Fraction& other);
        Fraction operator - (const Fraction& other);
        Fraction operator * (const Fraction& other);
        Fraction operator / (const Fraction& other);
        //Очистка памяти
        ~Fraction() {
           
        }
};
//Функции перегрузки операторов
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
    //Для русского языка
    setlocale(LC_ALL, "Russian");
    //Создание дробей
    Fraction drob1(35, 205);
    Fraction drob2(4, 20);
    Fraction drob3(15, 100);
    //Вывод НОД дробей
    std::cout << "НОД дроби 1:" << std::endl;
    drob1.gcd(drob1.GetX(drob1), drob1.GetY(drob1));
    std::cout << "НОД дроби 2:" << std::endl;
    drob2.gcd(drob2.GetX(drob2), drob2.GetY(drob2));
    std::cout << "НОД дроби 3:" << std::endl;
    drob3.gcd(drob3.GetX(drob3), drob3.GetY(drob3));
    //Сокращение дробей
    drob1.reduce();
    drob2.reduce();
    drob3.reduce();
    //Вывод сокращенных дробей
    std::cout << "Дробь 1 в сокращенном виде: " << std::endl;
    drob1.printFrac(drob1);
    std::cout << "Дробь 2 в сокращенном виде: " << std::endl;
    drob2.printFrac(drob2);
    std::cout << "Дробь 3 в сокращенном виде: " << std::endl;
    drob3.printFrac(drob3);
    //Проверка перегрузок и вывод полученных значений
    std::cout << "Произведение дробей: " << std::endl;
    drob1.printFrac(drob1 * drob2);
    std::cout << "Частное дробей: " << std::endl;
    drob1.printFrac(drob1 / drob2);
    std::cout << "Сумма дробей: " << std::endl;
    drob1.printFrac(drob1 + drob2);
    std::cout << "Разность дробей: " << std::endl;
    drob1.printFrac(drob1 - drob2);
    //Создание double дроби
    Fraction decimalFrac(0.25);
    //Вывод входной дроби
    std::cout << "Входная дробь(double): " << std::endl;
    std::cout << decimalFrac.GetDecimal(decimalFrac);
    //Вывод double дроби в десятичном виде
    std::cout << "\nДесятичная дробь: " << std::endl;
    decimalFrac.printDecimalFrac(decimalFrac);
    //Вывод double дроби в обычном виде
    std::cout << "Обычная дробь дробь: " << std::endl;
    decimalFrac.printDecimalRedFrac(decimalFrac);
    //Вывод числа созданных дробей
    std::cout << "Всего было создано дробей: " << count << std::endl;
}
