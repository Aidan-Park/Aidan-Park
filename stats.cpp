// Aidan Park
// stats.cpp
// Project UID 5366c7e2b77742d5b2142097e51561a5
#include "stats.h"
#include "p1_library.h"
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

//REQUIRES: v is not empty
//EFFECTS: returns a summary of the dataset as (value, frequency) pairs
//  In the returned vector-of-vectors, the inner vector is a (value, frequency)
//  pair.  The outer vector contains many of these pairs.  The pairs should be
//  sorted by value.
//MODIFIES: N/A
vector<vector<double> > summarize(vector<double> v) 
{
  vector<vector<double> > summary;
  sort(v);

  for(size_t j = 0; j < v.size(); j++)
  {
    int freq = 0;

    vector<double> valFreq;
    valFreq.push_back(v[j]);

    for(size_t i = 0; i < v .size(); i++)
    {
      if(v[i] == v[j])
        freq++;
    }
    j += freq-1;
    valFreq.push_back(freq);
    summary.push_back(valFreq);
  }

  return summary;
}

//EFFECTS: returns a count of the number of indicies in v
int count(vector<double> v) 
{
  int count = 0;
  for(size_t i = 0; i < v.size(); i++)
  {
    count++;
  }
  return count;
}

//REQUIRES: v is not empty
//EFFECTS: returns the sum of the numbers in v
double sum(vector<double> v) 
{
  double total = 0;
  for(size_t i = 0; i < v.size(); i++)
  {
    total += v[i];
  }
  return total;
}

//REQUIRES: v is not empty
//EFFECTS: returns the arithmetic mean of the numbers in v
double mean(vector<double> v) 
{
  double total = 0;
  double count = 0;

  for(size_t i = 0; i < v.size(); i++)
  {
    total += v[i];
    count++; 
  }

  return total/count;
}

//REQUIRES: v is not empty
//EFFECTS: returns the sample median of the numbers in v
double median(vector<double> v) 
{
  sort(v);
  if(v.size() % 2 != 0)
  {
    return v[v.size() / 2];
  }
  else
  {
    return (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2.0;
  }
}

//REQUIRES: v is not empty
//EFFECTS: returns the mode of the numbers in v
double mode(vector<double> v) 
{
  sort(v);
  int mode = 0;
  int maxFreq = 0;
  int freq = 0;

  for(size_t i = 0; i <= v[v.size() - 1]; i++)
  {
    freq = 0;
    for(size_t j = 0;j < v.size(); j++)
    {
      if(v[j] == i)
      {
        freq++;
      }
      if(freq > maxFreq)
      {
        maxFreq = freq;
        mode = i;
      }
    }
  }
  return mode;
}

//REQUIRES: v is not empty
//EFFECTS: returns the smalles number in v
double min(vector<double> v) 
{
  sort(v);
  return v[0];
}

//REQUIRES: v is not empty
//EFFECTS: returns the largest number in v
double max(vector<double> v) 
{
  sort(v);
  return v[v.size()-1];
}

//REQUIRES: v contains at least 2 elements
//EFFECTS: returns the corrected sample standard deviation of the numbers in v
double stdev(vector<double> v) 
{
  double dataMean = mean(v);
  double diff = 0;
  double sum = 0;

  for(size_t i = 0; i < v.size(); i++)
  {
    diff = v[i] - dataMean;
    sum += pow(diff,2);
  }

  return pow(sum / (v.size() - 1), .5);
}

//REQUIRES: v is not empty
//          p is between 0 and 1, inclusive
//EFFECTS: returns the percentile p of the numbers in v like Microsoft Excel
double percentile(vector<double> v, double p) 
{
  sort(v);
  double n = p * (v.size() - 1);
  double nInt = 0;
  double nDec = 0;
  nDec = modf(n, &nInt);

  if(nInt == (v.size() -1 ))
    return v[nInt];

  return v[nInt] + nDec * (v[nInt + 1] - v[nInt]);
}

