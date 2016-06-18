/*
 * vector.h
 * Author: Bartlomiej Styczen
 */
#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <new>
#include <cstdlib>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;

class Vector {
private:
    int * fields;
    int size;
public:
    //konstruktory
    //defaultowy, zeruje wszystkie pola
    Vector( int input = 2 ); //OK
    //konstruktor kopiujacy
    Vector( const Vector & v ); //OK
    //destruktor
    ~Vector(); //OK

    //przeciazenia operatorow
    Vector operator+( const Vector & v ) const; //OK
    Vector operator-( const Vector & v ) const; //OK
    Vector operator*( const int & n ) const; //OK
    //skalarne mnozenie wektorow
    int operator*( const Vector & v ) const; //OK
    friend Vector operator*( const int & n, const Vector & v ); //OK
    Vector & operator=( const Vector & src ); //OK
    void     operator*=( const double & n ); //OK
    void     operator+=( const Vector & v ); //OK
    void     operator-=( const Vector & v ); //OK
    int      operator[]( const int i ) const; //OK

    friend std::ostream & operator<<( std::ostream & out, const Vector & v_out ); //OK
    friend std::istream & operator>>( std::istream & in, const Vector & v_in );   //OK

    bool operator==( const Vector & v ); //OK
    bool operator!=( const Vector & v ); //OK

};


#endif /* VECTOR_H_ */
