/* Aidan Park
 * stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 * Project UID 5366c7e2b77742d5b2142097e51561a5
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.h"
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

void test_sum_small_data_set();
void test_count();
void test_summarize();
void test_summarize_binary();
void test_count();
void test_sum();
void test_edgeMean();
void test_small_data_mean();
void test_median();
void test_median_edge();
void test_mode();
void test_mode_oneIndex();
void test_mode_bimodal();
void test_min();
void test_max();
void test_stdev();
void test_percentile();
void test_percentile_zeroeth();

// Add prototypes for you test functions here.

int main() {
  test_sum_small_data_set();
  test_summarize();
  test_summarize_binary();
  test_count();
  test_sum();
  test_small_data_mean();
  test_edgeMean();
  test_median();
  test_median_edge();
  test_mode();
  test_mode_oneIndex();
  test_mode_bimodal();
  test_min();
  test_max();
  test_stdev();
  test_percentile();
  test_percentile_zeroeth();
  return 0;
}

void test_sum_small_data_set() 
{
  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "small sum pass" << endl;
}

// Add the test function implementations here.
void test_summarize() 
{
  vector<double> v;
  v.push_back(6);
  v.push_back(6);
  v.push_back(0);
  v.push_back(9);
  v.push_back(6);

  vector<vector<double> > vec = summarize(v);

  for(size_t i = 0; i < vec.size(); i++)
  {
    cout << vec[i][0] << ":  " << vec[i][1] << endl;
  }
}

void test_summarize_binary() 
{
  vector<double> v;
  v.push_back(0);
  v.push_back(0);
  v.push_back(0);
  v.push_back(0);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);
  v.push_back(1);

  vector<vector<double> > vec = summarize(v);

  for(size_t i = 0; i < vec.size(); i++)
  {
    cout << vec[i][0] << ":  " << vec[i][1] << endl;
  }
}

void test_count()
{ 
  vector<double> v;
  for(size_t i = 0; i < 12; i++)
  {
    v.push_back(i);
  }
  assert(count(v) == 12);

  cout << "count pass" << endl;
}

void test_sum()
{
  vector<double> v;

  for(size_t i = 0; i < 1000; i++)
  {
    v.push_back(5);
  }

  assert(sum(v) == 5000);

  cout << "large sum pass" << endl;
}

void test_small_data_mean()
{
  
  vector<double> v;

  for(size_t i = 0; i < 11; i++)
  {
    v.push_back(i);
  }

  assert(mean(v) == 5);

  cout << "small data mean pass" << endl;
}

void test_edgeMean()
{
  vector<double> v;
  for(size_t i = 0; i < 1; i++)
  {
    v.push_back(70);
  }

  assert(mean(v) == 70);

  cout << "edge mean pass" << endl;
}

void test_median()
{
  vector<double> v;
  for(size_t i = 1; i < 10; i++)
  {
    v.push_back(i);
  }

  assert(median(v) == 5);

  cout << "median pass" << endl;
}

void test_median_edge()
{
  vector<double> v;
  v.push_back(4);

  assert(median(v) == 4);
  cout << "median edge pass" << endl;
}

void test_mode()
{
  vector<double> v;
  v.push_back(3);
  v.push_back(3);
  v.push_back(5);
  v.push_back(3);
  v.push_back(2);
  v.push_back(5);

  assert(mode(v) == 3);
  cout << "mode pass" << endl;
}

void test_mode_oneIndex()
{
  vector<double> v;
  v.push_back(5);

  assert(mode(v) == 5);
  cout << "mode oneindex pass" << endl;
}

void test_mode_bimodal()
{
  vector<double> v;
  v.push_back(5);
  v.push_back(1);
  v.push_back(5);
  v.push_back(1);

  assert(mode(v) == 1);

  cout << "bimodal pass" << endl;

}
void test_min()
{
  vector<double> v;
  v.push_back(74);
  v.push_back(2);
  v.push_back(429084);
  v.push_back(3);

  assert(min(v) == 2);
  cout << "min pass" << endl;
}

void test_max()
{
  vector<double> v;
  v.push_back(74);
  v.push_back(2);
  v.push_back(429084);
  v.push_back(3);

  assert(max(v) == 429084);
  cout << "max pass" << endl;
}

void test_stdev()
{
  vector<double> v;
  v.push_back(6);
  v.push_back(8);
  v.push_back(8);
  v.push_back(8);
  v.push_back(8);
  v.push_back(9);
  v.push_back(9);

  assert(stdev(v) == 1);
  cout << "stdev pass" << endl;
}

void test_percentile()
{
  vector<double> v;
  v.push_back(15);
  v.push_back(20);
  v.push_back(35);
  v.push_back(40);
  v.push_back(50);

  assert(percentile(v,.4) == 29);
  cout << "percentile pass" << endl;
}

void test_percentile_zeroeth()
{
  vector<double> v;
  v.push_back(1);
  v.push_back(5);
  v.push_back(6);
  v.push_back(3);
  
  assert(percentile(v,0) == 1);
  cout << "percentile zeroeth pass" << endl;
}

