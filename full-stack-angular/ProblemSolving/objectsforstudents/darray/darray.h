/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: darray.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has darray class declaration 
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef darray_H
#define darray_H

#include "../util/util.h"

/*----------------------------------------------------------------
Declaration of darray class
-----------------------------------------------------------------*/
template <typename T>
class darray {
public:
  darray(int size = 50);
  darray(const T f[], int size); //For constant object.
  ~darray();
  darray(const darray<T>& s);
  darray<T>& operator=(const darray<T>& rhs);
  T& operator[](int i); //For non constant objects
  const T& operator[](int i) const; //for constant objects
  bool display()const { return _display; }
  static void set_display(bool x) {
    _display = x;
  }

private:
  T*  _element;
  int _size;
  static bool _display; /* ONLY ONCE for all object */
  void _copy(const darray<T>& s);
  void _release(){ delete [] _element; }
  void _grow(int i);
};

#include "darray.hpp"

#endif
//EOF

