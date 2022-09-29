#pragma once

#include <iostream>

#include "dot.hpp"

class Line {
   private:
      double angular_coefficient;
      double constant;

   public:
      Line();
      Line(double new_ang_coef, double new_const);
      Line(Dot a, Dot b);
      ~Line();
      Line perpendicularLine(const Dot &a);
      double getAngularCoefficient() const;
      double getConstant() const;
      Dot intersection(const Line &r);
};


std::ostream &operator<<(std::ostream &stream, const Line &r);