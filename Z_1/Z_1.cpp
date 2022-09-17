#include <iostream>
#include <vector> 
#include <iomanip>
#include <cmath>
using namespace std;


class Matrix {
    private:
        //Важные переменные матрицы
        int row, col, i, j;
        double** matrixArr;
        //Инициализация матрицы на основе массива vector
        double** initializeMatrix(vector<double> vec) {
            matrixArr = new double* [row];
            for (i = 0; i < row; ++i)
            {
                *(matrixArr + i) = new double[col];
            }
            for (i = 0; i < row; ++i)
            {
                for (j = 0; j < col; ++j)
                {
                    matrixArr[i][j] = vec[i * col + j];
                }
            }
            return matrixArr;
        }

    public:
        //Конструктор с параметрами для создания матрицы
        Matrix(int _row, int _col, vector<double> vec) {
            row = _row;
            col = _col;
            initializeMatrix(vec);
        }

        //Перегрузка префиксной формы инкремента
        Matrix & operator++() {
            this->i++;
            this->j++;
            return *this;
        }

        //Перегрузка постфиксной формы инкремента
        Matrix & operator++(int val) {
            Matrix temp(*this);
            this->i++;
            this->j++;
            return temp;
        }

        //Перегрузка префиксной формы декремента
        Matrix & operator--() {
            this->i--;
            this->j--;
            return *this;
        }

        //Перегрузка постфиксной формы декремента
        Matrix & operator--(int val) {
            Matrix temp(*this);
            this->i--;
            this->j--;
            return temp;
        }
        //Вывод матрицы на экран
        void printMatrix() {           
            for (i = 0;i < row;i++) {
                for (j = 0; j < col; ++j) {
                    //Условие для суммы первых элементов строки
                    if (j == 0) {
                        matrixArr[i][j] = matrixArr[i][j + 1] + matrixArr[i][j + 2] + matrixArr[i][j + 3] + matrixArr[i][j + 4];
                    }
                    cout << setw(10) << matrixArr[i][j] << "|";
                }
                cout << endl;
            }
        }
        //Вывод определенного элемента
        int at(int i, int j) {
             cout << "Ваш элемент:" <<matrixArr[i][j]<<endl;
             return matrixArr[i][j];
        }
        //Замена значения определенного элемента
        void SetAt(int i, int j, double value) {
            matrixArr[i][j] = value;
            //Замена значения первого элемента строки с учетом замененного элемента
            matrixArr[i][0] = matrixArr[i][1] + matrixArr[i][2] + matrixArr[i][3] + matrixArr[i][4];
            printMatrix();
        }
        //Очистка памяти
        ~Matrix (){
            for (i = 0; i < row; i++) {
                free(matrixArr[i]);
            }
            free(matrixArr);
            cout << "Память класса Matrix была очищена!" << endl;
        }
};

class Vector {
    private:
        //Важные переменные массива vector
        vector<double> vec;
        int i;
        //Инициализация массива
        void initializeVec() {
            for (i = 0; i < vec.size(); ++i)
            {
                //Формула заполнения массива
                vec[i] = i * sin((3.14 * i) / 25);
            }
        }

    public:
        //Конструктор с параметром для массива vector
        Vector(int LEN) {
            vec.resize(LEN);
            initializeVec();
        }

        //Перегрузка оператора индексации []
        double & operator[](int index){
            return vec[index];
        }

        //Перегрузка префиксной формы инкремента
        Vector & operator++() {
            this->i++;
            return *this;
        }

        //Перегрузка постфиксной формы инкремента
        Vector & operator++(int val) {
            Vector temp(*this);
            this->i++;
            return temp;
        }

        //Перегрузка префиксной формы декремента
        Vector & operator--() {
            this->i--;
            return *this;
        }

        //Перегрузка постфиксной формы декремента
        Vector & operator--(int val) {
            Vector temp(*this);
            this->i--;
            return temp;
        }
        //Вывод массива на экран
        void printVec() {
            for (i = 0; i < vec.size(); i++)
            {
                cout << vec[i] << " ";
            }
            cout << endl << "--------------------------------------------------------------\n";
        }
        //Функция возвращения содержания массива, необходима для передачи данных в матрицу
        auto GetVec() {
            return vec;
        }
        //Очистка памяти
        ~Vector(){
            vec.clear();
            cout << "Память класса Vector была очищена!" << endl;
        }
};

int main()
{
    //Для русского языка
    setlocale(LC_ALL, "ru");
    //Создание массива размерностью в 25 элементов
    Vector mass(25);
    //Вывод заполненного массива
    mass.printVec();
    //Проверка работы перегрузки
    //cout<<mass[5]<<endl; --> работает правильно ☻
    //Создание матрицы на основе массива
    Matrix mat(5,5, mass.GetVec());
    //Вывод матрицы
    mat.printMatrix();
    //Переменная для цикла
    bool flag = true;
    //Цикл для работы с пользователем
    while (flag) {
        //Выбор действия программы
        cout << "Выберите действие:\n 1: Вывести элемент матрицы;\n 2: Изменить элемент матрицы;\n 3: Выйти" << endl;
        int act, i, j;
        double value;
        cin >> act;
        switch (act)
        {
            //Кейс для поиска определенного значения в матрице
            case 1:
                cout << "Введите номер строки (нумерация идет с 0):" << endl;
                cin >> i;
                cout << "Введите номер значения в строке (нумерация идет с 0):" << endl;
                cin >> j;
                mat.at(i, j);
                break;
            //Кейс для замены определенного значения в матрице
            case 2:
                    cout << "Введите номер строки (нумерация идет с 0, при смене элемента [0][0] ничего не произойдет!):" << endl;
                    cin >> i;
                    cout << "Введите номер значения в строке (нумерация идет с 0, при смене элемента [0][0] ничего не произойдет!):" << endl;
                    cin >> j;
                    cout << "Введите новое значение элемента" << endl;
                    cin >> value;
                    mat.SetAt(i, j, value);
                break;
            //Выход из программы
            case 3:
                flag = false;
                break;
            //Дефолтное действие для вывода сообщения в случае неправильного указания номера кейса
            default:
                cout << "Неизвестное действие!";
                    break;
        }    
    }
}
