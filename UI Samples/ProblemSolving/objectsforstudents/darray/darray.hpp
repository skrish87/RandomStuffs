/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: darray.hpp

-----------------------------------------------------------------*/
#include "darray.h"
/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Definition of routines of darray class
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Constructor
-----------------------------------------------------------------*/
template <typename T>
darray<T>::darray(int size) :_size(size), _element(nullptr){
  if (display()) {
    cout << "in darray constructor:" << endl;
  }
  _element = new T[size]; //if T is by value, constructors will be called
}

/*--------------------------------------------------------
Constructor that takes an array of const object T
and construct darray of constant object.
Note that after the object is constructed
you can NO longer add or change the content of darray
----------------------------------------------------------*/
template <typename T>
darray<T>::darray(const T f[], int size) :_size(size), _element(nullptr) {
  if (display()) {
    cout << "in darray constant constructor:" << endl;
  }
  _size = size;
  _element = new T[size];  //if T is by value, constructors will be called
  for (int i = 0; i < size; ++i) {
    _element[i] = f[i];
  }
}

/*----------------------------------------------------------------
Destructor
-----------------------------------------------------------------*/
template <typename T>
darray<T>::~darray() {
  if (display()) {
    cout << "In darray Destructor " << endl;
  }
  _release();
  _element = NULL;
  _size = 0;
}

/*----------------------------------------------------------------
_copy
If by value: Calls copy constructor if written. Else bit wise copy
If by address: Just copies address. No deep copying.
(Two pointers will point to the same objects+
-----------------------------------------------------------------*/
template <typename T>
void darray<T>::_copy(const darray<T>& from) {
  _size = from._size;
  _element = new T[_size]; //if T is by value, constructors will be called
  for (int i = 0; i < from._size; i++) {
    _element[i] = from._element[i]; //if T is by value, = operator will be called
  }
  //If T is by address, No constructors are called
  //and array will be garbage as in C array
  //NOTE THAT U cannot initialize this array to 0
  //as you don't know T is by address
}

/*----------------------------------------------------------------
Copy Constructor
-----------------------------------------------------------------*/
template <typename T>
darray<T>::darray(const darray<T>& s){
  if (display()) {
    cout << "in darray copy constructor:" << endl;
  }
  _copy(s);
}

/*----------------------------------------------------------------
Equal Constructor
-----------------------------------------------------------------*/
template <typename T>
darray<T>& darray<T>::operator=(const darray<T>& rhs) {
  if (display()) {
    cout << "In darray equal operator \n";
  }
  if (this != &rhs) {
    _release();
    _copy(rhs);
  }
  return *this;
}

/*----------------------------------------------------------------
darray s ;
You can do
s[35] = obj ;
obj = s[78]
s[47] = p;
p = s[58] ;
s[89] = s[90] ;
-----------------------------------------------------------------*/
template <typename T>
T& darray<T>::operator[](int i) {
  if (i < 0){
    assert(0);
  }
  if (i >= _size) {
    _grow(i);
  }
  return _element[i]; /* Returned by alias so that user can modify */
}

/*----------------------------------------------------------------
const darray s = "hello" ;
const ch = s[1] ;
-----------------------------------------------------------------*/
template <typename T>
const T& darray<T>::operator[](int i) const{
  if (i < 0 || i >= _size) {
    assert(0);
  }
  return _element[i]; /* Returned by alias so that user can modify */
}

/*--------------------------------------------------------
grow array
----------------------------------------------------------*/
template <typename T>
void darray<T>::_grow(int i) {
  if (display()) {
    cout << "in darray grow. Will grow from " << _size << " to " << _size + i << endl;;
  }
  T* oldarray = _element;
  int oldsize = _size;
  _size = _size + i;
  _element = new T[_size]; //if T is by value, constructors will be called
  for (int j = 0; j < oldsize; j++) {
    _element[j] = oldarray[j]; //if T is by value, = operator will be called
  }
  //If T is by address, No constructors are called
  //Extended array: from oldsize to _size will have GARBAGE
  //If you access this location, purify cribs about UMR
  //      UMR: Uninitialized memory read
  //This is true in C also
  //NOTE THAT U cannot initialize this array to 0
  //as you don't know T is by address
  delete [] oldarray; //if T is by value, destructors will be called
}



//EOF


