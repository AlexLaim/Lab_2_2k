#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <fstream>
#include <Windows.h>
#include <algorithm>

class Auto {
private:
    //Важные переменные класса
    std::string company, model, number;
    int price, yearOfProd;
    int mileage = 0;
public:
    //Конструктор без параметров
    Auto() {

    }
    //Конструктор с параметрами
    Auto(std::string company_, std::string model_, std::string number_, int price_, int yearOfProd_, unsigned int mileage_)
    {
        company = company_;
        model = model_;
        number = number_;
        price = price_;
        yearOfProd = yearOfProd_;
        mileage = mileage_;
    }
    //Очистка памяти
    ~Auto() {}
    //Установка фирмы
    void setCompany(const std::string& company_) {
        company = company_;
    }
    //Установка модели
    void setModel(const std::string& model_) {
        model = model_;
    }
    //Установка номера
    void setNumber(const std::string& number_) {
        number = number_;
    }
    //Установка цены
    void setPrice(int price_) {
        price = price_;
    }
    //Установка года выпуска
    void setYearOfProd(int yearOfProd_) {
        yearOfProd = yearOfProd_;
    }
    //Имитация поездок
    int setMileage() {
        for (int i = 0; i < 3; i++) {
            mileage += (1000 + rand() % (10000 - 1000 + 1));
        }
        return mileage;
    }
    //Получение значений пробега
    int GetMileage(Auto car) {
        return car.mileage;
    }
    //Вывод информации об автомобилях
    void printInfo(Auto car) {
        std::cout << "Фирма: " << car.company << std::endl;
        std::cout << "Модель: " << car.model << std::endl;
        std::cout << "Номер: " << car.number << std::endl;
        std::cout << "Цена: " << car.price << std::endl;
        std::cout << "Год выпуска: " << car.yearOfProd << std::endl;
        std::cout << "Пробег: " << car.mileage << "км." << std::endl;
        std::cout << std::endl << "--------------------------------------------------------------\n";
    }
    //Сохранение данных в файл
    void serialize(const std::string filename, Auto car) {
        std::fstream fs;
        //SetConsoleCP(1251); //Для ввода русских букв в файл
        fs.open(filename, std::fstream::in | std::fstream::app);
        if (!fs.is_open()) {
            std::cout << "Ошибка открытия файла!" << std::endl;
            exit(0);
        }
        else {
            fs << company << "\n" << model << "\n" << number << "\n" << price << "\n" << yearOfProd << "\n" << car.mileage << "\n";
            fs.close();
        }
        //SetConsoleCP(866); //Обязательно возвращаем значение
    }
    //Вывод данных из файла
    void deserialize(const std::string filename) {
        std::fstream fs;
        std::ifstream fin;
        fin.open(filename);
        if (!fin.is_open()) {
            std::cout << "Ошибка открытия файла!" << std::endl;
            exit(0);
        }
        else {
            fin >> company >> model >> number >> price >> yearOfProd >> mileage;

            fin.close();
        }
    }
    //Получение модели авто
    auto GetModel(Auto car) {
        return car.model;
    }
    //Получение года выпуска
    int GetYearOfProd(Auto car) {
        return car.yearOfProd;
    }
    //Получение номера
    auto GetNumber(Auto car) {
        return car.number;
    }
};
//Создание массива машин
static std::vector<Auto> cars;
//Условие для сортировки
bool comp(Auto a, Auto b) {
    return (a.GetMileage(a) > b.GetMileage(b));
};

int main()
{
    //Для русского языка
    setlocale(LC_ALL, "ru");
    //Для рандомных значений
    srand(time(NULL));
    //Создание экземпляра класса в куче
    Auto* car_1 = new Auto("BMW", "X5", "AO4H5", 1500000, 2010, 0);
    car_1->setMileage();
    //Добавление в массив
    cars.push_back(car_1[0]);
    //Очистка памяти
    delete car_1;
    //Создание экземпляров через сеттеры
    Auto car_2;
    car_2.setCompany("Audi");
    car_2.setModel("A8");
    car_2.setNumber("BO4H5");
    car_2.setPrice(4626593);
    car_2.setYearOfProd(2015);
    car_2.setMileage();
    cars.push_back(car_2);
    Auto car_3;
    car_3.setCompany("Chevrolet");
    car_3.setModel("Corvette");
    car_3.setNumber("CO4H5");
    car_3.setPrice(2000000);
    car_3.setYearOfProd(2004);
    car_3.setMileage();
    cars.push_back(car_3);
    Auto car_4;
    car_4.setCompany("Mersedes");
    car_4.setModel("Mercedes-Benz");
    car_4.setNumber("DO4H5");
    car_4.setPrice(2391004);
    car_4.setYearOfProd(2013);
    car_4.setMileage();
    cars.push_back(car_4);
    std::cout << "Информация по всем автомобилям: " << std::endl; 
    //Создание переменных для сортировки
    Auto tmp, tmp2;
    int j=1;
    //Сортировка по пробегу, без учета года выпуска
    sort(cars.begin(), cars.end(), comp);
    //Сортировка по пробегу, с учетом года выпуска
    for (int i = 0; i < cars.size(); i++)
    {   
        //cars[i].GetYearOfProd(cars[i]) --> получение года выпуска
        //(cars[i].GetNumber(cars[i]) != cars[j].GetNumber(cars[j])) --> проверка, чтобы машины были различны (У каждого авто свой собственный номер)
        //(cars[i].GetMileage(cars[i]) > cars[j].GetMileage(cars[j]) --> проверка на пробег
        if (cars[i].GetYearOfProd(cars[i]) >= 2011 && cars[j].GetYearOfProd(cars[j]) >= 2011 && (cars[i].GetNumber(cars[i]) != cars[j].GetNumber(cars[j]))) {
            if (cars[i].GetMileage(cars[i]) > cars[j].GetMileage(cars[j])) {
                //Запоминаем значения во временные переменные
                tmp = cars[i];
                tmp2 = cars[j];
                //Удаляем экземпляры, сначала тот у которого больший индекс, чтобы не вызвать exeption
                cars.erase(cars.begin() + j);
                cars.erase(cars.begin() + i);       
                //Добавляем в начала в правильном порядке
                cars.insert(cars.begin(), tmp2);
                cars.insert(cars.begin(), tmp);
            }
            else if (cars[i].GetMileage(cars[i]) < cars[j].GetMileage(cars[j])) {
                tmp = cars[i];
                tmp2 = cars[j];
                cars.erase(cars.begin() + j);
                cars.erase(cars.begin() + i);
                cars.insert(cars.begin(), tmp);
                cars.insert(cars.begin(), tmp2);
            }
        }
        //Проверка чтобы j не выходил за рамки массива
        if (j!= cars.size()-1) {
            j++;
        }                
    }
    //Вывод информации об автомобилях
    for (int i = 0;i < cars.size();i++) {
        
        cars[i].printInfo(cars[i]);
    }
    std::cout << std::endl;
    //Работа с пользователем
    bool flag = true;
    while (flag) {
        std::cout << "Выберите действие:\n 1: Сохранить в файл;\n 2: Вывести из файла;\n 3: Выйти" << std::endl;
        int act, count;
        std::string modelCar;
        std::string path;
        Auto newCar;
        std::cin >> act;
        switch (act)
        {
        case 1:
            //Сохранение информации об автомобиле в файл
            std::cout << "Введите модель автомобиля которую нужно сохранить" << std::endl;
            std::cin >> modelCar;
            path = modelCar + ".txt";
            count = 0;
            for (int i = 0;i < cars.size();i++) {
                if (cars[i].GetModel(cars[i]) == modelCar) {
                    cars[i].serialize(path, cars[i]);
                    count++;
                }
            }
            if (count == 0) {
                std::cout << "Данная модель не найдена!" << std::endl;
            }
            else {
                std::cout << "Сохранение в файл прошло успешно!" << std::endl;
            }
            break;
        case 2:
            //Вывод информации об автомобиле из файла
            std::cout << "Введите модель автомобиля информацию о котором нужно получить" << std::endl;
            std::cin >> modelCar;
            path = modelCar + ".txt";
            newCar.deserialize(path);
            cars.push_back(newCar);
            std::cout << "Информация по вашему авто: " << std::endl;
            newCar.printInfo(newCar);
            std::cout << "Чтение из файла прошло успешно!" << std::endl;
            break;
        case 3:
            //Закрытие программы
            flag = false;
            break;
        default:
            //Дефолтное действие
            std::cout << "Неизвестное действие!" << std::endl;
            break;
        }
    }
}