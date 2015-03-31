/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ddeque.hpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
 All includes here
 -----------------------------------------------------------------*/
#include "ddeque.h"

/*--------------------------------------------------------
 static definition - only once at the start
 Change to false, if you don't need verbose
 ----------------------------------------------------------*/
template <class T>

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/
/*----------------------------------------------------------------
Definition of routines of ddeque class
-----------------------------------------------------------------*/
ddeque<T>::ddeque(int size ) {
    back_i = 0;
    
}

/*----------------------------------------------------------------
WTITE ALL ROUTINES HERE
-----------------------------------------------------------------*/
template <class T>

/* WRITE ALL PUBLIC FUNCTION HERE */
/* CANNOT HAVE ANY PUBLIC DATA HERE */
void ddeque<T> ::  push_back( T const& item) {
    array[back_i++] = item;
}
template <class T>
void ddeque<T> ::  push_front( T const& item) {
    for( int i = back_i; i >= 0; i--) {
        array[i+1] = array[i];
    }
    
    back_i++;
    array[0] = item;
    
}

template <class T>
void ddeque<T> :: pop_front() {
    T& ret = array[0];
    for ( int i = 1 ; i < back_i ; i++) {
        array[i-1] = array[i];
    }
   back_i--; 
    
}

template <class T>
void  ddeque<T> ::  pop_back(){
    
    back_i--;
}

template <class T>
T&  ddeque<T> :: front() {
    return array[0];
    
}

template <class T>
T&  ddeque<T> ::  back() {
    return array[back_i-1];
}



//EOF


