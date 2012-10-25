
#ifndef SHAPES_H
#define SHAPES_H

#include<string>


using std::string;

class Shp {

public:
  Shp ();
  ~Shp();
  virtual string draw() const;
  virtual float area();

 };

 class Cir: public Shp {

float radius;
 public:
Cir();
Cir(float newR);
string draw() const;
float area();
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
