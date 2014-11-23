/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: dsort.h
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has dsort class declaration
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#ifndef dsort_H
#define dsort_H

#include "../darray/darray.h"

/*--------------------------------------------------------
static definition - only once at the start
Change to false, if you don't need verbose
----------------------------------------------------------*/
template <typename T>
bool darray<T>::_display = false;

/*----------------------------------------------------------------
class stat
-----------------------------------------------------------------*/
class statistics {
public:
  statistics() :_nc(0), _ns(0), _ni(0) {}
  void reset() {
    _nc = 0; _ns = 0; _ni = 0;
  }
  void inc_num_compare() {
    ++_nc;
  }
  void inc_num_swap() {
    ++_ns;
  }
  void inc_num_iteration() {
    ++_ni;
  }
  int get_num_compare() const {
    return _nc;
  }
  int get_num_swap() const {
    return _ns;
  }
  int get_num_iteration() const {
    return _ni;
  }
private:
  int _nc; //num compare
  int _ns; //num_swap 
  int _ni; //num_iteration
};

/*--------------------------------------------------------
class dsort
----------------------------------------------------------*/
template <typename T>
class dsort {
public:
  dsort(darray<T>& d, int(*cf) (const T& c1, const T& c2), int size = 0);
  ~dsort();
  void bubble_sort();
  bool binary_search(const T& r, int first, int last, int& middle);
  void insertion_sort();
  void merge_sort();
  void quick_sort();
  void change_swap_function(int(*cf) (const T& c1, const T& c2)) { _cf = cf; }
  bool display()const { return _display; }
  void set_size(int size) { _size = size; }
  static void set_display(bool x) {
    darray<T>::set_display(x);
    _display = x;
  }
  void assertSorted();
  //statistics
  void reset_stat() {
    _stat.reset();
  }
  void inc_num_compare() {
    _stat.inc_num_compare();
  }
  void inc_num_swap() {
    _stat.inc_num_swap();
  }
  void inc_num_iteration() {
    _stat.inc_num_iteration();
  }
  int get_num_compare() const {
    return _stat.get_num_compare();
  }
  int get_num_swap() const {
    return _stat.get_num_swap();
  }
  int get_num_iteration() const {
    return _stat.get_num_iteration();
  }
  /* no body will copies or equal dsort */
  dsort(const dsort<T>& s) = delete;
  dsort<T>& operator=(const dsort<T>& rhs) = delete;

private:
  int _size;
  statistics _stat;
  darray<T>& _darray;
  int(*_cf) (const T& c1, const T& c2);
  static bool _display; /* ONLY ONCE for all object */

  void _print_darray(int pass);
  void _swap(T&a, T&b);
  void _dump(int start, int end);
};

#include "dsort.hpp"

#endif
//EOF

