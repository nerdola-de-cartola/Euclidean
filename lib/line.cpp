#include "../lib/line.hpp"

Line::Line() {}

Line::Line(double new_ang_coef, double new_const): 
   angular_coefficient(new_ang_coef), constant(new_const) {}


Line::Line(Dot a, Dot b) {
   this->angular_coefficient = (a.getY() - b.getY()) / (a.getX() - b.getX());
   this->constant = a.getY() - (this->angular_coefficient * a.getX());
}

Line::~Line() {}

Line Line::perpendicularLine(const Dot &a) {
   if(this->getAngularCoefficient() == 0) {
      std::cout << "ERRO - RETA COM COEFICIENTE IGUAL A ZERO" << std::endl;
      exit(1);
   }

   double new_ang_coef = -1 / this->getAngularCoefficient();
   double new_const = a.getY() - (new_ang_coef * a.getX());

   return Line(new_ang_coef, new_const);
}

double Line::getAngularCoefficient() const {
   return this->angular_coefficient;
}

double Line::getConstant() const {
   return this->constant;
}

Dot Line::intersection(const Line &r) {
   double new_x = (
      (r.getConstant() - this->getConstant()) 
      / 
      (this->getAngularCoefficient() - r.getAngularCoefficient())
   );

   double new_y = (
      (this->getAngularCoefficient() * new_x) 
      +
      this->getConstant()
   );

   return Dot(new_x, new_y);
}

std::ostream &operator<<(std::ostream &stream, const Line &r) {
   stream << r.getAngularCoefficient() << "x ";
   stream << r.getConstant();

   return stream;
};