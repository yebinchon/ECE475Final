//========================================================================
// ubmark-quicksort
//========================================================================

//#include "ubmark.h"
#include "ubmark-quicksort.dat"

//------------------------------------------------------------------------
// quick_sort
//------------------------------------------------------------------------

__attribute__ ((noinline))
void quick_sort (int *a, int n) {
  if (n < 2)
    return;
  int p = a[n / 2];
  int *l = a;
  int *r = a + n - 1;
  while (l <= r) {
    if (*l < p) {
      l++;
      continue;
    }
    if (*r > p) {
      r--;
      continue; // we need to check the condition (l <= r) every time we change the value of l or r
    }
    int t = *l;
    *l++ = *r;
    *r-- = t;
  }
  quick_sort(a, r - a + 1);
  quick_sort(l, a + n - l);
}

//------------------------------------------------------------------------
// verify_results
//------------------------------------------------------------------------

void verify_results( int values[], int ref[], int size )
{
  int temp = 0;
  int i;
  for ( i = 0; i < size; i++ ) {
    if ( !( values[i] == ref[i] ) ) {
      //test_fail( i );
      fail();
    }
  }
  //test_pass( temp );
  pass();
}

//------------------------------------------------------------------------
// Test harness
//------------------------------------------------------------------------

int main( int argc, char* argv[] )
{
  int temp = 0;

  //test_stats_on( temp );
  quick_sort( data, data_size );
  //test_stats_off( temp );

  verify_results( data, ref, data_size );

  return 0;

}

