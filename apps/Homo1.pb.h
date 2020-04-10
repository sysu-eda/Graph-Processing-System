// Generated by the property buffer compiler. DO NOT EDIT!
// source: Homo1.prop

#ifndef HOMO1_PROPERTY_BUFFER_H
#define HOMO1_PROPERTY_BUFFER_H

#include <cctype>
#include <cstdlib>

namespace Homo1 {

typedef unsigned int uintE;
class BFS_parents {
public:
  BFS_parents(size_t n) {
    data = (uintE*) malloc(sizeof(uintE) * n);
  }
  inline uintE operator[] (int i) const { return data[i]; }
  inline uintE& operator[] (int i) { return data[i]; }
  uintE* data;
};

class Components_IDs {
public:
  Components_IDs(size_t n) {
    data = (uintE*) malloc(sizeof(uintE) * n);
  }
  inline uintE operator[] (int i) const { return data[i]; }
  inline uintE& operator[] (int i) { return data[i]; }
  uintE* data;
};

class Components_prevIDs {
public:
  Components_prevIDs(size_t n) {
    data = (uintE*) malloc(sizeof(uintE) * n);
  }
  inline uintE operator[] (int i) const { return data[i]; }
  inline uintE& operator[] (int i) { return data[i]; }
  uintE* data;
};

class Property {
public:
  size_t n;
  Property(size_t _n): n(_n) {}
  inline BFS_parents* add_parents() {
    BFS_parents* parents = new BFS_parents(n);
    return parents;
  }
  inline Components_IDs* add_IDs() {
    Components_IDs* IDs = new Components_IDs(n);
    return IDs;
  }
  inline Components_prevIDs* add_prevIDs() {
    Components_prevIDs* prevIDs = new Components_prevIDs(n);
    return prevIDs;
  }
};


} // namespace Homo1

#endif // HOMO1_PROPERTY_BUFFER_H
