#pragma once

#include "dot.hpp"
#include "line.hpp"

class Circle {
   private:
      Dot center;
      double radius;
   public:
      Circle();
      Circle(const Dot &new_center, double new_radius);
      Circle(const Dot &a, const Dot &b, const Dot &c);
      ~Circle();
      Dot getCenter() const;
      double getRadius() const;
};


std::ostream &operator<<(std::ostream &stream, const Circle &o);