#include "System.hpp"

int main() {
  // Set up our coefficients and row solutions
  systems::Coeff my_coeff = systems::Coeff();
  my_coeff.push_back(std::tuple(1, 1, -1));
  my_coeff.push_back(std::tuple(2, 3, 4));
  my_coeff.push_back(std::tuple(3, 3, -3));

  systems::VarBatch my_eq_solns = std::tuple(-4, 5, 9);
  
  // Set up our operations matrix
  matrix::Operations my_ops = {{'+', '-'}, {'*', '*'}, {'+', '+'}};

  // Setup our system of equations
  systems::System my_system = systems::System(my_coeff, my_ops, my_eq_solns);
  my_system.print();
}