#include <memory>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "shapes2.h"

const float PI = 3.14159265f;

TEST(Shapes, DrawCircle) {
  Circle c{1.0f};
  EXPECT_EQ("drew a Cir", c.draw());
}

TEST(Shapes, DrawSquare) {
  Square s{1.0f};
  EXPECT_EQ("drew a Sq", s.draw());
}

TEST(ShapePtr, DrawSquare) {
  // change this to make the test pass
  std::shared_ptr<Shape> s = std::make_shared<Square>(1.0f);

  EXPECT_EQ("drew a Sq", s->draw());
}

TEST(Shapes, BunchOfSquaresArea) {
  // change these to make the test pass
  std::shared_ptr<Shape> sq_ptr1 = std::make_shared<Square>(1.0f);
  std::shared_ptr<Shape> sq_ptr2 = std::make_shared<Square>(1.0f);
  std::shared_ptr<Shape> sq_ptr3 = std::make_shared<Square>(1.0f);

  EXPECT_FLOAT_EQ(3.0f, sq_ptr1->area() +
sq_ptr2->area() + sq_ptr3->area());
}

TEST(Shapes, BunchOfCirclesArea) {
  // change these to make the tests pass.
  std::shared_ptr<Shape> c_ptr1 = std::make_shared<Circle>(1.0f);
  std::shared_ptr<Shape> c_ptr2 = std::make_shared<Circle>(1.0f);
  std::shared_ptr<Shape> c_ptr3 = std::make_shared<Circle>(1.0f);

  EXPECT_FLOAT_EQ(3.0f * PI, c_ptr1->area() +
c_ptr2->area() + c_ptr3->area());
}

TEST(Shapes, DifferentShapes) {
  // change the assignments so that the test becomes true.
  std::shared_ptr<Shape> sq_ptr1 = std::make_shared<Square>(4.0f);
  std::shared_ptr<Shape> c_ptr1 = std::make_shared<Circle>(9.0f);
  std::shared_ptr<Shape> c_ptr2 = std::make_shared<Circle>(9.0f);

  EXPECT_FLOAT_EQ((4.0f * 4.0f) + (PI * 9.0f * 9.0f) + (9.0f * 9.0f * PI),
sq_ptr1->area() + c_ptr1->area() + c_ptr2->area());
}

TEST(ShapeVec, AreasSumCorrectly) {
  std::vector<std::shared_ptr<Shape> > drawingBoard{};

  // TODO Add three unit circles to the drawingBoard.
  // TODO Add three unit squares to the drawingBoard
  drawingBoard.push_back(std::make_shared<Square> (1.0f));
  drawingBoard.push_back(std::make_shared<Square> (1.0f));
  drawingBoard.push_back(std::make_shared<Square> (1.0f));

  drawingBoard.push_back(std::make_shared<Circle> (3.0f));

  float areas = 0.0f;
  for (const auto &s : drawingBoard) {
    areas += s->area();
  }

  EXPECT_FLOAT_EQ(3.0f + (3.0f * 3.0f * PI), areas);
}
