/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
file: dsort.hpp

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
Definition of routines of dsort class
-----------------------------------------------------------------*/


/*----------------------------------------------------------------
Constructor
-----------------------------------------------------------------*/
template <typename T>
dsort<T>::dsort(darray<T>& d, int(*cf) (const T& c1, const T& c2), int size) :_darray(d), _cf(cf), _size(size){

}

/*----------------------------------------------------------------
Destructor
-----------------------------------------------------------------*/
template <typename T>
dsort<T>::~dsort() {

}

/*----------------------------------------------------------------
print darray
-----------------------------------------------------------------*/
template <typename T>
void dsort<T>::_print_darray(int pass){
  cout << pass << ":";
  for (int i = 0; i < _size; i++) {
    cout << _darray[i] << " ";
  }
  cout << endl;
}

/*----------------------------------------------------------------
Swap two object in the array
By value:      Object must have = operator
By ptr:       Pointers are compared
-----------------------------------------------------------------*/
template <class T>
void dsort<T>::_swap(T& a, T& b) {
  T temp = a;
  a = b;
  b = temp;
}

/*----------------------------------------------------------------
Binary search

0  1  2 3 4 5 6 7 8 9  10 11
-5 -3 -1 0 1 4 7 7 9 10 21 45

NOTION HERE: first = 0 ;
last = 11;  //NOT 12. Last is index to Largest element


-4 Not there in array. But can be put in position 1 (false)

21 there in position 10 (true)

46 Not there in array. But can be put in position 12 (false)

-8 Not there in array. But can be put in position 0 (false)

pos gives the position where r can be added.
In the above case pos can be 0 or pos can be 12
-----------------------------------------------------------------*/
template <typename T>
bool dsort<T>::binary_search(const T& r, int first, int last, int& pos) {
  assert(first <= last);
  int k;
  int middle = 0;
  /* there must be at least one element: a[0] */
  while (first <= last) { /* Even one element  */
    middle = (first + last) / 2;
    k = _cf(_darray[middle], r);
    if (k == 0) {
      //equal
      pos = middle; //Solution found in middle
      return true;
    }
    if (k < 0) {
      //r is lesser than array[middle] 
      last = middle - 1;
    }
    else {
      //r is greater than array[middle]
      first = middle + 1;
    }
  }
  //middle is the index above or below target
  if (last < 0) {
    pos = 0; //0
  }
  if (first > last) {
    pos = first; //n+1 case
  }
  assert(pos >= 0 && pos <= last + 1); //can be added at 0 or last +1
  return false;
}

/*----------------------------------------------------------------
prove that the array is really sorted
-----------------------------------------------------------------*/
template <typename T>
void dsort<T>::assertSorted(){
  int p = 0;
  for (int i = 1; i < _size; ++i) {
    int r = _cf(_darray[p], _darray[i]);
    assert(r >= 0);
    p = i;
  }
}

/*----------------------------------------------------------------
Bubble sort

0:25 57 48 37 12 92 86 33
1:25 48 37 12 57 86 33 92
2:25 37 12 48 57 33 86 92
3:25 12 37 48 33 57 86 92
4:12 25 37 33 48 57 86 92
5:12 25 33 37 48 57 86 92
6:12 25 33 37 48 57 86 92
-----------------------------------------------------------------*/
template <typename T>
void dsort<T>::bubble_sort(){
  reset_stat();
  if (display()) {
    _print_darray(0);
  }
  bool exchanged = false;
  int n = _size;
  do{
    inc_num_iteration();
    exchanged = false;
    for (int i = 0; i < n - 1; i++) {
      int j = i + 1;
      inc_num_compare();
      if (_cf(_darray[i], _darray[j]) < 0) {
        inc_num_swap();
        exchanged = true;
        _swap(_darray[i], _darray[j]);
      }
    }
    if (display()) {
      _print_darray(get_num_iteration());
    }
    n--;
  } while (exchanged);
  assertSorted();
  cout << "----------Bubble sort-------------------\n";
  cout << "#n =               " << _size << endl;
  int c = get_num_compare();
  int s = get_num_swap();
  int it = get_num_iteration();
  int t = c + s;
  cout << "#comparison =      " << c << endl;
  cout << "#swap        =     " << s << endl;
  cout << "#Bubbled loops =   " << it << endl;
  cout << "#c+s =             " << t << endl;
  double x = double(t) / double(_size*_size);
  cout << "#T(n) = (c+s)/(n^2) =  " << x << "(n^2)" << endl;
  cout << "----------------------------------------\n";
}

/*----------------------------------------------------------------
Insertion sort
-----------------------------------------------------------------*/
template <typename T>
void dsort<T>::insertion_sort(){
  reset_stat();
  cout << "WRITE YOUR CODE HERE\n";

  //assertSorted();
  //WRITE statistics code
}


/*----------------------------------------------------------------
Merge sort
-----------------------------------------------------------------*/
template <typename T>
void dsort<T>::merge_sort(){
  reset_stat();
  cout << "WRITE YOUR CODE HERE\n";

  //assertSorted();
  //WRITE statistics code
}

/*----------------------------------------------------------------
Quick sort

-----------------------------------------------------------------*/
template <typename T>
void dsort<T>::quick_sort(){
  reset_stat();
  cout << "WRITE YOUR CODE HERE\n";


  //assertSorted();
  //WRITE statistics code
}

//EOF

