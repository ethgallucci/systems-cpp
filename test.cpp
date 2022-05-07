#include "System.hpp"

int main() {
  // Set up our coefficients and row solutions
  systems::Coeff my_coeff = systems::Coeff();
  my_coeff.push_back(std::tuple(2, 3));
  my_coeff.push_back(std::tuple(5, -3));

  // Set our equation solutions
  systems::VarBatch my_eq_solns = std::tuple(8, -1);

  // Make our operations matrix
  matrix::Operations my_ops = {Operator::Plus, Operator::Plus};

  /*
  2x + 3y = 8
  5x - 3y = -1
  */

  // Setup our system of equations
  systems::System my_system = systems::System(my_coeff, my_ops, my_eq_solns);
  my_system.print();
}