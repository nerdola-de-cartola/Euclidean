#include "../lib/dot.hpp"

Dot::Dot():
   x(0), y(0) {}

Dot::Dot(const Dot &a):
   x(a.getX()), y(a.getY()) {}

Dot::Dot(double new_x, double new_y):
   x(new_x), y(new_y) {}

Dot::~Dot() {}

double Dot::getX() const {
   return this->x;   
}

double Dot::getY() const {
   return this->y;   
}

Dot Dot::midpoint(const Dot &a) const {
   double mid_x = (this->getX() + a.getX()) / 2;
   double mid_y = (this->getY() + a.getY()) / 2;

   return Dot(mid_x, mid_y);
}

double Dot::distance(const Dot &a) {
   Dot dif = *this - a;

   return sqrt(
      (dif.getX() * dif.getX())
      + 
      (dif.getY() * dif.getY())
   );
}

Dot Dot::operator-(const Dot &a) {
   double new_x = this->getX() - a.getX();
   double new_y = this->getY() - a.getY();

   return Dot(new_x, new_y);
}

std::ostream &operator<<(std::ostream &stream, const Dot &a) {
   stream << '(' << a.getX() << ", ";
   stream << a.getY() << ')';

   return stream;
};