#include "myExceptions.h"
#include <iostream> 
#include <algorithm>

template <typename T>
class matrix {
    friend ostream& operator<<(ostream&, const matrix<T>&);
public:
    /// constructors and destructor ///
    matrix(int theRows = 0, int theColumns = 0);
    matrix(const matrix<T>&);
    ~matrix() { delete[] element; }
    /// get ///
    int rows() const { return theRows; }
    int columns() const { return theColumns; }
    /// overload operators ///
    T& operator() (int i, int j) const;
    matrix<T>& operator=(const matrix<T>&);
    matrix<T> operator+() const; // unary +
    matrix<T> operator+(const matrix<T>&) const;
    matrix<T> operator-() const; // unary -
    matrix<T> operator-(const matrix<T>&) const;
    matrix<T> operator*(const matrix<T>&) const;
    matrix<T>& operator+=(const T&);
private:
    int theRows, theColumns;
    T *element;
};


/// constructor ///
template <typename T>
matrix<T>::matrix(int theRows, int theColumns) {
    if (theRows < 0 || theColumns < 0) {
        throw illegalParameterValue("Rows and columns must be >= 0");
    }
    if ((theRows == 0 || theColumns == 0) && (theRows != 0 || theColumns != 0)) {
        throw illegalParameterValue("Either both or neither rows and columns should be zero");
    }

    this->theRows = theRows;
    this->theColumns = theColumns;
    element = new T[theRows * theColumns];
}


/// copy constructor ///
template <typename T>
matrix<T>::matrix(const matrix<T>& m) {
    theRows = m.theRows;
    theColumns = m.theColumns;
    element = new T[theRows * theColumns];

    copy(m.element, m.element + theRows * theColumns, element);    
}