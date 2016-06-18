/*
 * matrix.h
 * Author: Bartlomiej Styczen
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "vector.h"

class Matrix
{
private:
    Vector ** vectors; //wektory sa poziomo
    int rows; //liczba wektorów
    int cols; //dlugosc wektora

public:
    //konstruktor defaultowy
    Matrix( int c = 2, int r = 2 ); //OK

    //konstruktor kopiujacy
    Matrix( const Matrix & m ); //DONE

    //destruktor
    ~Matrix(); //DONE

    Matrix & operator=( const Matrix & m ); //OK
    Matrix   operator+( const Matrix & m ) const; //OK
    Matrix   operator-( const Matrix & m ) const; //OK

    Matrix & operator+=( const Matrix & m ); //DONE
    Matrix & operator-=( const Matrix & m ); //DONE
    Matrix & operator*=( const int & n ); //DONE

    //iloczyn macierzy przez liczbe
    Matrix operator*( const int & m ) const;  //DONE
    friend Matrix operator*( const int & n, const Matrix & m ); //DONE

    //wypisanie elementu
    int operator()( const int c, const int r ) const; //DONE

    friend std::ostream & operator<<( std::ostream & out, const Matrix & m ); //OK
    friend std::istream & operator>>( std::istream & in, const Matrix & m ); //OK

    bool operator==( const Matrix & m ) const;
    bool operator!=( const Matrix & m ) const;

};


#endif /* MATRIX_H_ */
