
#ifndef SHAPES_H
#define SHAPES_H
#include <iostream>
  

using std::string;

class Shp {

public:
  Shp ();
  ~Shp();
  virtual string draw() const;
  virtual float area();

};

class Trg : public Shp {

public:
  Trg(float x_);
  ~Trg();
  string draw() const;
  float area();

private:
  float dn;//dimension;
};

class Sq : public Shp {

public:
  Sq(float x_);
  ~Sq();
  string draw() const;
  float area();

private:
  float dn;//dimension
};

#endif
