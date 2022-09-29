#include "../lib/euclidean.hpp"

int main(void) {
   using namespace std;

   Circle o(Dot(1.0, 1.0), Dot(0.0, 0.0), Dot(2.0, 3.0));
   cout << o << endl;

   Circle other(Dot(0, 0), 2.5);
   cout << other << endl;

   return 0;
}