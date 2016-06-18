/*
 * matrix.cpp
 *
 *  Created on: 15 maj 2016
 *      Author: Bartek
 */

#include "matrix.h"

//konstruktor defaultowy
Matrix::Matrix( int c, int r ) {
    rows = r;
    cols = c;

    if ( c < 1 || r < 1 ) {
        cols = 0;
        rows = 0;
        vectors = NULL;
    }

    vectors = new Vector * [ rows ];
    for ( int i = 0; i < rows; i++ ) {
        *(vectors + i) = new Vector( cols );
    }
}

//konstruktor kopiujacy
Matrix::Matrix( const Matrix & m ) {
    if ( m.rows < 1 || m.cols < 1 || m.vectors == NULL ) {
        rows = cols = 0;
        vectors = NULL;

    }
    rows = m.rows;
    cols = m.cols;
    vectors = new Vector * [ m.rows ];
    for ( int i = 0; i < rows; i++ ) {
        vectors[i] = new Vector( cols );
        *(*(vectors + i)) = *(*(m.vectors + i));
    }
}

//destruktor
Matrix::~Matrix() {
    for ( int i = 0; i < rows; i++ )
        delete vectors[i];
    delete [] vectors;
}

//A + B
Matrix Matrix::operator+( const Matrix & m ) const {
    Matrix temp( cols, rows );
    if ( (rows == m.rows) && (cols == m.cols) ) {

        for ( int i = 0; i < rows; i++ )
            *(*(temp.vectors + i)) = *(*(vectors + i)) + *(*(m.vectors + i));
    } else
        throw "Cannot add matrixes with different sizes!";

    return temp;
}


//A - B
Matrix Matrix::operator-( const Matrix & m ) const {
	Matrix temp( cols, rows );
	if ( (rows == m.rows) && (cols == m.cols) ) {

        for ( int i = 0; i < rows; i++ )
            *(*(temp.vectors + i)) = *(*(vectors + i)) - *(*(m.vectors + i));

    } else
        throw "Cannot substract two matrixes with different sizes!";
	return temp;
}

//A * liczba
Matrix Matrix::operator*( const int & n ) const {
    if ( rows < 1 || cols < 1 || vectors == NULL )
        throw "Cannot to this!";
    Matrix temp( cols, rows );
    for ( int i = 0; i < rows; i++ )
        *(*(temp.vectors + i)) = *(*(vectors + i)) * n;
    return temp;
}

//liczba * A    zaprzyjazniona
Matrix operator*( const int & n, const Matrix & m ) {
    return (m * n);
}

//A += B
Matrix & Matrix::operator+=( const Matrix & m ) {
	if ( rows == m.rows && cols == m.cols ) {
		for ( int i = 0; i < rows; i++ ) {
			*(*(vectors + i)) += *(*(m.vectors + i));
		}
	} else
		throw "Cannot do this!";
    return *this;
}

//A -= B
Matrix & Matrix::operator-=( const Matrix & m ) {
	if ( rows == m.rows && cols == m.cols ) {
		for ( int i = 0; i < rows; i++ ) {
			*(*(vectors + i)) -= *(*(m.vectors + i));
		}
	} else
		throw "Cannot do this!";
	return *this;
}

//A *= n
Matrix & Matrix::operator*=( const int & n ) {
	for ( int i = 0; i < rows; i++ )
		*(*(vectors + i)) *= n;
	return *this;
}

//()
int Matrix::operator()( const int c, const int r ) const {
    if ( c < 0 || r < 0 || c > cols || r > rows )
        throw "Outside the array!";
    return (*(*(vectors + r)))[c];
}

//=
Matrix & Matrix::operator=( const Matrix & m ) {
    if ( this == &m )
    	return *this;

	if ( m.cols < 1 || m.rows < 1 || m.vectors == NULL )
        throw "Cannot do this!";

    for ( int i = 0; i < rows; i++ )
        delete vectors[i];
    delete [] vectors;

    vectors = new Vector * [ m.rows ];
    rows = m.rows;
    cols = m.cols;


    for ( int i = 0; i < rows; i++ ) {
    	*(vectors + i) = new Vector( m.cols );
    }
    for ( int j = 0; j < rows; j++ ) {
    	*(*(vectors + j)) = *(*(m.vectors + j));
    }
    return *this;
}

//CIN >>
std::istream & operator>>( std::istream & in, const Matrix & m ) {
    if ( m.cols >= 1 && m.rows >= 1 && m.vectors != NULL ) {
        for ( int i = 0; i < m.rows; i++ )
            in >> *(*(m.vectors + i));
    }
    return in;
}

//COUT <<
std::ostream & operator<<( std::ostream & out, const Matrix & m ) {
    if ( m.cols >= 1 && m.rows >= 1 && m.vectors != NULL ) {
        for ( int i = 0; i < m.rows; i++ ) {
             out << (*(*(m.vectors + i)));
             std::cout << std::endl;
        }
    }
    return out;
}

//==
bool Matrix::operator==( const Matrix & m ) const {
	if ( m.rows == rows ) {
		for ( int i = 0; i < rows; i++ ) {
			if ( (*(*(vectors + i)) == *(*(m.vectors + i))) == 0 )
				return false;
			else
				return true;
		}
	}
	return false;
}

//!=
bool Matrix::operator!=( const Matrix & m ) const {
	return !( (*this) == m );
}
