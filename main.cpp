#include <iostream>
#include <ctime>
#include <cstdint>

// my
uint32_t saturated_sum(uint32_t RGB_in1, uint32_t RGB_in2);
// your
uint32_t saturated_sum1(uint32_t left, uint32_t right);

uint32_t saturated_sum2(uint32_t left, uint32_t righ);

uint32_t saturated_sum3(uint32_t rgb1, uint32_t rgb2);

uint32_t saturated_sum4(uint32_t left, uint32_t righ);

uint32_t saturated_sum5(uint32_t rgb1, uint32_t rgb2);
// branch
uint32_t saturated_sum_branch(uint32_t RGB_in1, uint32_t RGB_in2);
//

using namespace std;

int main(int argc, char *argv[]) {
  cout << " Performance check" << endl;
  cout << " Calling the same function 100 million times" << endl << endl;

  int i = 2;
  while (i > 0) {
    i--;
    clock_t time_start, time_stop;
    // my
    cout << " My: " << endl;
    time_start = clock();
    for (int i = 0; i < 100000000; i++) // 100 millions
      saturated_sum(i, 0);
    time_stop = clock();
    cout << " task time saturated_sum  " << (time_stop - time_start) << " ms"
         << endl;
    // your
    cout << " your: " << endl;
    // sum1
    time_start = clock();
    for (int i = 0; i < 100000000; i++) // 100 millions
      saturated_sum1(i, 0);
    time_stop = clock();
    cout << " task time saturated_sum1 " << (time_stop - time_start) << " ms"
         << endl;
    //
    // sum2
    time_start = clock();
    for (int i = 0; i < 100000000; i++) // 100 millions
      saturated_sum2(i, 0);
    time_stop = clock();
    cout << " task time saturated_sum2 " << (time_stop - time_start) << " ms"
         << endl;
    //
    // sum3
    time_start = clock();
    for (int i = 0; i < 100000000; i++) // 100 millions
      saturated_sum3(i, 0);
    time_stop = clock();
    cout << " task time saturated_sum3 " << (time_stop - time_start) << " ms"
         << endl;
    //
    // sum4
    time_start = clock();
    for (int i = 0; i < 100000000; i++) // 100 millions
      saturated_sum4(i, 0);
    time_stop = clock();
    cout << " task time saturated_sum4 " << (time_stop - time_start) << " ms"
         << endl;
    //
    // sum5
    time_start = clock();
    for (int i = 0; i < 100000000; i++) // 100 millions
      saturated_sum5(i, 0);
    time_stop = clock();
    cout << " task time saturated_sum5 " << (time_stop - time_start) << " ms"
         << endl;
    //
    cout << " Branch: " << endl;
    // branch
    time_start = clock();
    for (int i = 0; i < 100000000; i++) // 100 millions
      saturated_sum_branch(i, 0);
    time_stop = clock();
    cout << " task time saturated_sum_branch " << (time_stop - time_start)
         << " ms" << endl;
    //
  }

  return 0;
}
//---------------------------------------------------------------------------
