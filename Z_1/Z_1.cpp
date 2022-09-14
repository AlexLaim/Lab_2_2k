#include <iostream>
#include <vector> 
#include <iomanip>
#include <cmath>
using namespace std;


class Matrix {
    private:
        int row, col, i, j;
        double** matrixArr;

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

        int at(int i, int j) {
             cout << "Ваш элемент:" <<matrixArr[i][j]<<endl;
             return matrixArr[i][j];
        }

        void SetAt(int i, int j, double value) {
            matrixArr[i][j] = value;
            matrixArr[i][0] = matrixArr[i][1] + matrixArr[i][2] + matrixArr[i][3] + matrixArr[i][4];
            printMatrix();
        }

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
        vector<double> vec;
        int i;
        void initializeVec() {
            for (i = 0; i < vec.size(); ++i)
            {
                vec[i] = i * sin((3.14 * i) / 25);
            }
        }

    public:
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

        void printVec() {
            for (i = 0; i < vec.size(); i++)
            {
                cout << vec[i] << " ";
            }
            cout << endl << "--------------------------------------------------------------\n";
        }

        auto GetVec() {
            return vec;
        }

        ~Vector(){
            vec.clear();
            cout << "Память класса Vector была очищена!" << endl;
        }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Vector mass(25);
    mass.printVec();
    //Проверка работы перегрузки
    //cout<<mass[5]<<endl; --> работает правильно ☻
    Matrix mat(5,5, mass.GetVec());
    mat.printMatrix();
    bool flag = true;
    while (flag) {
        cout << "Выберите действие:\n 1: Вывести элемент матрицы;\n 2: Изменить элемент матрицы;\n 3: Выйти" << endl;
        int act, i, j;
        double value;
        cin >> act;
        switch (act)
        {
            case 1:
                cout << "Введите номер строки (нумерация идет с 0):" << endl;
                cin >> i;
                cout << "Введите номер значения в строке (нумерация идет с 0):" << endl;
                cin >> j;
                mat.at(i, j);
                break;
            case 2:
                    cout << "Введите номер строки (нумерация идет с 0, при смене элемента [0][0] ничего не произойдет!):" << endl;
                    cin >> i;
                    cout << "Введите номер значения в строке (нумерация идет с 0, при смене элемента [0][0] ничего не произойдет!):" << endl;
                    cin >> j;
                    cout << "Введите новое значение элемента" << endl;
                    cin >> value;
                    mat.SetAt(i, j, value);
                
                break;
            case 3:
                flag = false;
                break;
            default:
                cout << "Неизвестное действие!";
                    break;
        }    
    }
}
