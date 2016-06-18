/*
 * vector.cpp
 * Author: Bartlomiej Styczen
 */
#include "vector.h"


//konstruktor domyslny
Vector::Vector( int input ) {
    if ( input < 1 ) {
        size = 0;
        fields = NULL;
        return;
    }
    size = input;
    fields = new int[ input ];

    for ( int i = 0; i < input; i++ ) {
        fields[i] = 0;
    }
}

//konstruktor kopiujacy
Vector::Vector( const Vector & v ) {
    size = v.size;
    fields = new int[ v.size ];
    for ( int i = 0; i < v.size; i++ )
        fields[i] = v.fields[i];
}

//destruktor
Vector::~Vector() {
    delete [] fields;
}

//A + B
Vector Vector::operator+( const Vector & v ) const {
	if ( size == v.size ) {
        Vector new_v( v.size ); //ogarniete w konstruktorze
        for ( int i = 0; i < size; i++ )
            new_v.fields[i] = fields[i] + v.fields[i];
        return new_v;
    } else
        throw "Cannot add two vectors with different size!" ;
}

//A - B
Vector Vector::operator-( const Vector & v ) const {
    if ( size == v.size ) {
        Vector temp( v.size );
        for ( int i = 0; i < v.size; i++ )
            *(temp.fields + i) = *(fields + i) - *(v.fields + i);
        return temp;
    } else
        throw "Cannot substract two vectors with different size! " ;
}

//A * liczba
Vector Vector::operator*( const int & n ) const {
    Vector temp( size );
    for ( int i = 0; i < size; i++ )
        temp.fields[i] = fields[i] * n;
    return temp;
}

//liczba * A            zaprzyjazniona
Vector operator*( const int & n, const Vector & v ) {
    Vector temp( v.size );
        for ( int i = 0; i < v.size; i++ )
            temp.fields[i] = v.fields[i] * n;
    return temp;
}

//A * B                 skalarnie
int Vector::operator*( const Vector & v ) const  {
    if ( size < 1 || fields == NULL || v.size < 1 || v.fields == NULL )
        return 0;
    if ( size == v.size ) {
        int result = 0;
        for ( int i = 0; i < size; i++ )
            result += v.fields[i] * fields[i];
    return result;
    } else
        throw "Cannot scalar multiplicate two vectors with different size!" ;
}

//A = B
Vector & Vector::operator=( const Vector & src ) {
    if ( this == &src )
    	return *this;


    else if ( size == src.size ) {
        	delete [] fields;
        	fields = new int[ size ];
            for ( int i = 0; i < size; i++ )
                fields[i] = src.fields[i];
            return *this;

        }
        //gdy size != src.sizeint
        else {
            delete [] fields;
            fields = new int[src.size];
            size = src.size;
                for ( int i = 0; i < size; i++ )
                    fields[i] = src.fields[i];
        }

    return *this;
}

//COUT
std::ostream & operator<<( std::ostream & out, const Vector & v_out ) {
    //cout << endl;
    for ( int i = 0; i < v_out.size; i++ ) {
        out << v_out.fields[i] << " ";
    }
    return out;
}

//CIN
std::istream & operator>>( std::istream & in, const Vector & v_in ) {

    if ( v_in.size >= 1 && v_in.fields != NULL ) {
        for ( int i = 0; i < v_in.size; i++ ) {
            in >> v_in.fields[i];
        }
    }
    return in;
}

//==
bool Vector::operator==( const Vector & v ) {
    if ( size < 1 && v.size < 1 ) return true;
    if ( (size >= 1 && v.size < 1) || (size < 1 && v.size >= 1) ) return false;
    if ( size != v.size ) return false;
    else {
        for ( int i = 0; i < size; i++ ) {
            if ( fields[i] != v.fields[i] ) return false;
        }
    }
    return true;
}

//!=
bool Vector::operator!=( const Vector & v ) {
    return !( (*this) == v );
}

//+=
void Vector::operator+=( const Vector & v ) {
    *this = *this + v;
}

//A *= n
void Vector::operator*=( const double & n ) {
    (*this) = (*this) * n;
}

//A -= B
void Vector::operator-=( const Vector & v ) {
    *this = *this - v;
}

//[]
int Vector::operator[]( const int i ) const {
    if ( i >= size || i < 0 )
      throw "Outside the array!";
    return (*this).fields[i];
}
