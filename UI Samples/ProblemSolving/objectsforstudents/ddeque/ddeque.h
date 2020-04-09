/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: ddeque.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has ddeque class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef ddeque_H
#define ddeque_H

#include "util.h"
#include "darray.h"

/*--------------------------------------------------------
static definition - only once at the start
Change to false, if you don't need verbose
----------------------------------------------------------*/
template <typename T>
bool darray<T>::_display = false;

/*----------------------------------------------------------------
All forward declaration
-----------------------------------------------------------------*/
template <typename T>
class ddeque;

template <typename T>
class ddeque_iterator;

/*--------------------------------------------------------
typename ddeque iterator
WRITE CODE BELOW
----------------------------------------------------------*/
template <typename T>
class ddeque_iterator : std:: iterator<std::forward_iterator_tag, T>{
public:
    
private:
  ddeque<T>* _ptr_object;
  int _current;
};

/*--------------------------------------------------------
class ddeque
----------------------------------------------------------*/
template <typename T>
class ddeque {
public:
  /* WRITE ALL PUBLIC FUNCTION HERE */
  /* CANNOT HAVE ANY PUBLIC DATA HERE */
    typedef T* iterator;
    void push_back( T const& item);
    void push_front( T const& item);
    void pop_back();
    void pop_front();
    T& front();
    T& back();
    int size() {
        return back_i;
    }
    ddeque(int size = 32);
    
    iterator begin() {
        
        return &array[0];
    }
    
    iterator end() {
        return &array[back_i];
    }
    
    T& operator [](int i) {
        return array[i];
    }
    
    bool empty() {
        return back_i == 0;
    }
    
    
    static void set_display(bool x) {
       darray<T>::set_display(x);
       _display = x;
    }
    bool display() const { return _display; }

private:
  /* MUST USE darray<T> */
  /* Can have some variables */
    static bool _display;
    darray<T> array;
    int front_i;
    int back_i;
};



#include "ddeque.hpp"
#endif
//EOF

