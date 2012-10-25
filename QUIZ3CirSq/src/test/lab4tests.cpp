#include <memory>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "shape.h"

const float PI = 3.14159265f;

TEST(Shps, DrawCir) {
  Cir c{1.0f};
  EXPECT_EQ("drew a Cir", c.draw());
}

TEST(Shps, DrawSq) {
  Sq s{1.0f};
  EXPECT_EQ("drew a Sq", s.draw());
}

TEST(ShpPtr, DrawSq) {
  // change this to make the test pass
  std::shared_ptr<Shp> s = std::make_shared<Sq>(1.0f);

  EXPECT_EQ("drew a Sq", s->draw());
}

TEST(Shps, BunchOfSqsArea) {
  // change these to make the test pass
  std::shared_ptr<Shp> sq_ptr1 = std::make_shared<Sq>(1.0f);
  std::shared_ptr<Shp> sq_ptr2 = std::make_shared<Sq>(1.0f);
  std::shared_ptr<Shp> sq_ptr3 = std::make_shared<Sq>(1.0f);

  EXPECT_FLOAT_EQ(3.0f, sq_ptr1->area() +
sq_ptr2->area() + sq_ptr3->area());
}

TEST(Shps, BunchOfCirsArea) {
  // change these to make the tests pass.
  std::shared_ptr<Shp> c_ptr1 = std::make_shared<Cir>(1.0f);
  std::shared_ptr<Shp> c_ptr2 = std::make_shared<Cir>(1.0f);
  std::shared_ptr<Shp> c_ptr3 = std::make_shared<Cir>(1.0f);

  EXPECT_FLOAT_EQ(3.0f * PI, c_ptr1->area() +
c_ptr2->area() + c_ptr3->area());
}

TEST(Shps, DifferentShps) {
  // change the assignments so that the test becomes true.
  std::shared_ptr<Shp> sq_ptr1 = std::make_shared<Sq>(4.0f);
  std::shared_ptr<Shp> c_ptr1 = std::make_shared<Cir>(9.0f);
  std::shared_ptr<Shp> c_ptr2 = std::make_shared<Cir>(9.0f);

  EXPECT_FLOAT_EQ((4.0f * 4.0f) + (PI * 9.0f * 9.0f) + (9.0f * 9.0f * PI),
sq_ptr1->area() + c_ptr1->area() + c_ptr2->area());
}

TEST(ShpVec, AreasSumCorrectly) {
  std::vector<std::shared_ptr<Shp> > drawingBoard{};

  // TODO Add three unit Cirs to the drawingBoard.
  // TODO Add three unit Sqs to the drawingBoard
  drawingBoard.push_back(std::make_shared<Sq> (1.0f));
  drawingBoard.push_back(std::make_shared<Sq> (1.0f));
  drawingBoard.push_back(std::make_shared<Sq> (1.0f));

  drawingBoard.push_back(std::make_shared<Cir> (3.0f));

  float areas = 0.0f;
  for (const auto &s : drawingBoard) {
    areas += s->area();
  }

  EXPECT_FLOAT_EQ(3.0f + (3.0f * 3.0f * PI), areas);
}
