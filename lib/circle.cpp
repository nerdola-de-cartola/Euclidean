#include "../lib/circle.hpp"

Circle::Circle():
   center(), radius(0) {}

Circle::Circle(const Dot &new_center, double new_radius):
   center(new_center), radius(new_radius) {}

Circle::Circle(const Dot &a, const Dot &b, const Dot &c):
   center(), radius(0) {
   Line bisector_a_b = Line(a, b).perpendicularLine(a.midpoint(b));
   Line bisector_a_c = Line(a, c).perpendicularLine(a.midpoint(c));

   this->center = bisector_a_b.intersection(bisector_a_c);
   this->radius = this->center.distance(a);
}

Circle::~Circle() {

}

std::ostream &operator<<(std::ostream &stream, const Circle &o) {
   stream << "Center: " << o.getCenter() << ' '; 
   stream << "Radius: " << o.getRadius(); 

   return stream;
};

Dot Circle::getCenter() const {
   return this->center;
}

double Circle::getRadius() const {
   return this->radius;
}
