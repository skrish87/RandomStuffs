/*----------------------------------------------------------------
Copyright (c) 2014 Author: Jagadeesh Vasudevamurthy
Filename: ../str/str.cpp airportsol.cpp 
compile: g++ ../str/str.cpp airportsol.cpp

Memory leaked: 0 bytes (0%); potentially leaked: 0 bytes (0%)

The data is in
objects/airport/data/flights.dat
Make sure U run dos2unix on flights.dat on linux.
-----------------------------------------------------------------*/
#include "../str/str.h"
#include "../dsort/dsort.h"

/*--------------------------------------------------------
static definition - only once at the start
Change to false, if you don't need verbose
----------------------------------------------------------*/
bool str::_display = false ;

template <typename T>
bool dsort<T>::_display = false ;

/*--------------------------------------------------------
local to this file. Change verbose = true for debugging
----------------------------------------------------------*/
static bool verbose = false;

/*----------------------------------------------------------------
WRITE CODE 
-----------------------------------------------------------------*/


/*----------------------------------------------------------------
You must read data from: objects/airport/data/flights.dat
You must create 4 output files at objects/airport/outputs/{bubble.dat, ..}
When you diff all the 4 output files must be identical
Print also the complexity.
-----------------------------------------------------------------*/
int  main() {
  const char* alg_names[] = {"bubble","insertion","quick","merge"} ;
  int num = sizeof(alg_names)/sizeof(char *) ;
  for (int i = 0; i < num; i++) {
    //WRITE CODE
  }
  return 0 ;
}
