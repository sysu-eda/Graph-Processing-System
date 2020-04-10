// Generated by the property buffer compiler. DO NOT EDIT!
// source: Homo2.prop

#ifndef HOMO2_PROPERTY_BUFFER_H
#define HOMO2_PROPERTY_BUFFER_H

#include <cctype>
#include <cstdlib>
#include "parallel.h"

namespace Homo2 {

typedef int intE;
typedef unsigned int uintE;

class SSSP_shortestPathLen {
public:
  SSSP_shortestPathLen(size_t n) {
    data = (intE*) malloc(sizeof(intE) * n);
    parallel_for (int i = 0; i < n; ++i) {
      data[i] = 0x3f3f3f3f;
    }
  }
  ~SSSP_shortestPathLen() {
    free(data);
  }
  inline intE operator[] (int i) const { return data[i]; }
  inline intE& operator[] (int i) { return data[i]; }
  intE* data;
};

class SSSP_changed {
public:
  SSSP_changed(size_t n) {
    data = (intE*) malloc(sizeof(intE) * n);
    parallel_for (int i = 0; i < n; ++i) {
      data[i] = 0;
    }
  }
  ~SSSP_changed() {
    free(data);
  }
  inline intE operator[] (int i) const { return data[i]; }
  inline intE& operator[] (int i) { return data[i]; }
  intE* data;
};

class PageRankDelta_p {
public:
  PageRankDelta_p(size_t n) {
    data = (double*) malloc(sizeof(double) * n);
  }
  ~PageRankDelta_p() {
    free(data);
  }
  inline double operator[] (int i) const { return data[i]; }
  inline double& operator[] (int i) { return data[i]; }
  double* data;
};

class PageRankDelta_neigh_sum {
public:
  PageRankDelta_neigh_sum(size_t n) {
    data = (double*) malloc(sizeof(double) * n);
    parallel_for (int i = 0; i < n; ++i) {
      data[i] = 0.0;
    }
  }
  ~PageRankDelta_neigh_sum() {
    free(data);
  }
  inline double operator[] (int i) const { return data[i]; }
  inline double& operator[] (int i) { return data[i]; }
  double* data;
};

class PageRankDelta_delta {
public:
  PageRankDelta_delta(size_t n) {
    data = (double*) malloc(sizeof(double) * n);
  }
  ~PageRankDelta_delta() {
    free(data);
  }
  inline double operator[] (int i) const { return data[i]; }
  inline double& operator[] (int i) { return data[i]; }
  double* data;
};

class PageRankDelta_tmp {
public:
  PageRankDelta_tmp(size_t n) {
    data = (bool*) malloc(sizeof(bool) * n);
  }
  ~PageRankDelta_tmp() {
    free(data);
  }
  inline bool operator[] (int i) const { return data[i]; }
  inline bool& operator[] (int i) { return data[i]; }
  bool* data;
};

class Property {
public:
  size_t n;
  Property(size_t _n): n(_n) {}
  inline SSSP_shortestPathLen* add_shortestPathLen() {
    SSSP_shortestPathLen* shortestPathLen = new SSSP_shortestPathLen(n);
    return shortestPathLen;
  }
  inline SSSP_changed* add_changed() {
    SSSP_changed* changed = new SSSP_changed(n);
    return changed;
  }
  inline PageRankDelta_p* add_p() {
    PageRankDelta_p* p = new PageRankDelta_p(n);
    return p;
  }
  inline PageRankDelta_neigh_sum* add_neigh_sum() {
    PageRankDelta_neigh_sum* neigh_sum = new PageRankDelta_neigh_sum(n);
    return neigh_sum;
  }
  inline PageRankDelta_delta* add_delta() {
    PageRankDelta_delta* delta = new PageRankDelta_delta(n);
    return delta;
  }
  inline PageRankDelta_tmp* add_tmp() {
    PageRankDelta_tmp* tmp = new PageRankDelta_tmp(n);
    return tmp;
  }
};


} // namespace Homo2

#endif // HOMO2_PROPERTY_BUFFER_H