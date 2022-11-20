// 本练习主要在于学习如何使用C++的右值引用、移动构造函数、移动赋值运算符，以及如何使用初始化列表

#include <iostream>
#include <iostream>
#include <initializer_list>

template <typename T>
using initList = std::initializer_list<T>; 

class Matrix {
private:
    int _row;
    int _col;
    int **_data;
public:
    Matrix() : _row(0), _col(0), _data(nullptr) {}
    // init list {...}
    Matrix (initList<double> list) {
        _row = 1;
        _col = list.size();
        _data = new int*[_row]{ nullptr };
        _data[0] = new int[_col]{ 0 };
        for (int i = 0; i < _col; i++) {
            _data[0][i] = list.begin()[i];
        }
    }
    // init list {{}, {}, ...}
    Matrix (initList< initList<double> > list) {
        _row = list.size();
        _col = list.begin()->size();
        _data = new int*[_row]{ nullptr };
        for (int i = 0; i < _row; ++i) {
            _data[i] = new int[_col]{ 0 };
            for (int j = 0; j < _col; ++j) {
                _data[i][j] = list.begin()[i].begin()[j];
            }
        }
    }
    // copy constructor with left value
    Matrix (const Matrix& m) {
        _row = m._row;
        _col = m._col;
        _data = new int*[_row]{ nullptr };
        for (int i = 0; i < _row; ++i) {
            _data[i] = new int[_col]{ 0 };
            for (int j = 0; j < _col; ++j) {
                _data[i][j] = m._data[i][j];
            }
        }
    }
    // copy constructor with right value
    Matrix (Matrix&& m) {
        _row = m._row;
        _col = m._col;
        _data = m._data;
        m._data = nullptr;
    }
    // copy assignment with left value
    Matrix& operator= (const Matrix& m) {
        if (this != &m) {
            _row = m._row;
            _col = m._col;
            _data = new int*[_row]{ nullptr };
            for (int i = 0; i < _row; ++i) {
                _data[i] = new int[_col]{ 0 };
                for (int j = 0; j < _col; ++j) {
                    _data[i][j] = m._data[i][j];
                }
            }
        }
        return *this;
    }
    // copy assignment with right value
    Matrix& operator= (Matrix&& m) {
        if (this != &m) {
            _row = m._row;
            _col = m._col;
            _data = m._data;
            m._data = nullptr;
        }
        return *this;
    }
   // destructor
    ~Matrix() {
        if (_data != nullptr) {
            for (int i = 0; i < _row; ++i) {
                delete[] _data[i];
            }
            delete[] _data;
        }
    }
    // Matrix + Matrix
    Matrix operator+ (const Matrix& m) {
        Matrix result;
        if (_row == m._row && _col == m._col) {
            result._row = _row;
            result._col = _col;
            result._data = new int*[result._row]{ nullptr };
            for (int i = 0; i < result._row; ++i) {
                result._data[i] = new int[result._col]{ 0 };
                for (int j = 0; j < result._col; ++j) {
                    result._data[i][j] = _data[i][j] + m._data[i][j];
                }
            }
        }
        return result;
    }
    // print
    void print() {
        for (int i = 0; i < _row; ++i) {
            for (int j = 0; j < _col; ++j) {
                std::cout << _data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    } 
};

int main() {
    // test
    Matrix m1 = {1, 2, 3, 4, 5, 6};
    Matrix m2 = {{1, 2, 3}, {4, 5, 6}};
    m1.print();
    m2.print();

    Matrix m3 = m1;
    Matrix m4 = std::move(m2);
    m1.print();
    // m2.print();
    m3.print();
    m4.print();

    Matrix m5;
    m5 = m3;
    Matrix m6;
    m6 = std::move(m4);
    m5.print();
    m6.print();

    Matrix m7 = m5 + m6;
    m7.print();
    
    return 0;
}