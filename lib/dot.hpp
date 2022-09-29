#pragma once

#include <cmath>
#include <iostream>

class Dot {
   private:
      double x;
      double y;

   public:
      Dot();
      Dot(const Dot &a);
      Dot(double new_x, double new_y);
      ~Dot();
      double getX() const;
      double getY() const;
      Dot midpoint(const Dot &a) const;
      double distance(const Dot &a);
      Dot operator-(const Dot &a);
};

std::ostream &operator<<(std::ostream &stream, const Dot &a);