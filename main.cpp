/*
 * main.cpp
 *
 *  Created on: 15 maj 2016
 *      Author: Bartek
 */
#include "vector.h"
#include "matrix.h"

#include <cstdlib>

int main( void ) {
    try {
    	 Matrix A(3,2);
    	 Matrix B;
    	 cout << "Wypelnij macierz A: ";
    	 cin >> A;

		 int liczba1 = 3;
		 cout << endl << "Macierz A: " << endl << A;
		 B = A;
		 cout << endl << "B = A " << endl << B;
		 cout << endl << "A + B " << endl << A + B;
		 cout << endl << "A - B " << endl << A - B;
		 cout << endl << "A * 2 " << endl << A * liczba1;
		 A += B;
		 cout << endl << "A += B " << endl << A;
		 A -= B;
		 cout << endl << "A -= B " << endl << A;
		 A *= liczba1;
		 cout << endl << "A *= 2 " << endl << A;
		 Matrix C(A);
		 cout << endl << "C(A): " << endl << C;
		 cout << endl << "A == B " << (A == B);
		 cout << endl << "A != B " << (A != B);
		 cout << endl << "A(1,1): " << A(1,1);
		 cout << endl;
    }
    catch( const char * s ) {
        std::cout << s << std::endl;
        std::cout << "Koncze wykonywanie programu " << std::endl << std::endl;
        //exit(EXIT_FAILURE);
    }

    catch( std::bad_alloc & c ) {
        std::cout << c.what() << std::endl;
        std::cout << "Koncze wykonywanie programu" << std::endl << std::endl;
       // exit(EXIT_FAILURE);
    }
    system("pause");
    return 0;
}
