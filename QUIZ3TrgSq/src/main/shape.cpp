
#include <iostream>
#include "shape.h"

const float PIE = 3.14159265f;
const float ONE_HALF = 0.5f;


Shp::Shp () {}

Shp::~Shp () {}

string Shp::draw() const {
  return "drew a Shp";
}

float Shp::area() {
  return 0;
}

Trg::Trg(float x_) : dn(x_) {}

Trg::~Trg() {}

string Trg::draw() const {
  return "drew a Trg";
}

float Trg::area() {
  float bh = dn * dn;
  return (ONE_HALF * bh);
}

Sq::Sq(float x_) : dn(x_) {}

Sq::~Sq() {}

string Sq::draw() const {
  return "drew a Sq";
}

float Sq::area() {
  return (dn * dn);
}
