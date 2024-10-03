#include <iostream>
#include <locale.h>
#include <vector>

using namespace std;

template <typename T>
class Matrix {
private:
    vector<vector<T>> data;
    size_t rows;
    size_t cols;

public:
    Matrix(size_t r, size_t c) : rows(r), cols(c) {
        data.resize(r, vector<T>(c, 0));
    }

    //Прописываем необходимые геттеры и сеттеры
    void setValue(size_t r, size_t c, T value) {
        data[r][c] = value;
    }

    T getValue(size_t r, size_t c) const {
        return data[r][c];
    }

    size_t getRows() const {
        return rows;
    }

    size_t getCols() const {
        return cols;
    }

    Matrix<T> operator+(const Matrix<T>& other) {
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.setValue(i, j, this->getValue(i, j) + other.getValue(i, j));
            }
        }
        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) {
        Matrix<T> result(rows, cols);
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                result.setValue(i, j, this->getValue(i, j) - other.getValue(i, j));
            }
        }
        return result;
    }

    Matrix<T> operator*(const Matrix<T>& other) {
        Matrix<T> result(rows, other.getCols());
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < other.getCols(); ++j) {
                for (size_t k = 0; k < cols; ++k) {
                    result.setValue(i, j, result.getValue(i, j) + this->getValue(i, k) * other.getValue(k, j));
                }
            }
        }
        return result;
    }

    void print() const {
        for (const auto& row : data) {
            for (const auto& elem : row) {
                cout << elem << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    setlocale(0, "rus");
    size_t rows, cols;
    cout << "Введите количество строк и столбцов матриц, которые вы желаете сложить и вычесть: ";
    cin >> rows >> cols;

    int choice;
    cout << "Выберите тип данных:\n1. Целые числа\n2. Вещественные числа\nВвод: ";
    cin >> choice;

    if (choice == 1) {
        Matrix<int> mat1(rows, cols);
        Matrix<int> mat2(rows, cols);

        cout << "Введите элементы первой матрицы:\n";
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                int value;
                cin >> value;
                mat1.setValue(i, j, value);
            }
        }

        cout << "Введите элементы второй матрицы:\n";
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                int value;
                cin >> value;
                mat2.setValue(i, j, value);
            }
        }

        Matrix<int> sum = mat1 + mat2;
        cout << "Сумма матриц:\n";
        sum.print();

        Matrix<int> difference = mat1 - mat2;
        cout << "Разница матриц:\n";
        difference.print();

        // Умножение может требовать другой размер для второй матрицы
        cout << "Введите количество столбцов для второй матрицы (для умножения): ";
        size_t newCols;
        cin >> newCols;

        Matrix<int> mat2ForMultiplication(cols, newCols);
        cout << "Введите элементы второй матрицы для умножения:\n";
        for (size_t i = 0; i < cols; ++i) {
            for (size_t j = 0; j < newCols; ++j) {
                int value;
                cin >> value;
                mat2ForMultiplication.setValue(i, j, value);
            }
        }

        Matrix<int> product = mat1 * mat2ForMultiplication;
        cout << "Результат умножения матриц:\n";
        product.print();
    }
    else if (choice == 2) {
        Matrix<double> mat1(rows, cols);
        Matrix<double> mat2(rows, cols);

        cout << "Введите элементы первой матрицы:\n";
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                double value;
                cin >> value;
                mat1.setValue(i, j, value);
            }
        }

        cout << "Введите элементы второй матрицы:\n";
        for (size_t i = 0; i < rows; ++i) {
            for (size_t j = 0; j < cols; ++j) {
                double value;
                cin >> value;
                mat2.setValue(i, j, value);
            }
        }

        Matrix<double> sum = mat1 + mat2;
        cout << "Сумма матриц:\n";
        sum.print();

        Matrix<double> difference = mat1 - mat2;
        cout << "Разница матриц:\n";
        difference.print();

        cout << "Введите количество столбцов для второй матрицы (для умножения): ";
        size_t newCols;
        cin >> newCols;

        Matrix<double> mat2ForMultiplication(cols, newCols);
        cout << "Введите элементы второй матрицы для умножения:\n";
        for (size_t i = 0; i < cols; ++i) {
            for (size_t j = 0; j < newCols; ++j) {
                double value;
                cin >> value;
                mat2ForMultiplication.setValue(i, j, value);
            }
        }

        Matrix<double> product = mat1 * mat2ForMultiplication;
        cout << "Результат умножения матриц:\n";
        product.print();
    }
    else {
        cout << "Неверный выбор.\n";
    }

    return 0;
}