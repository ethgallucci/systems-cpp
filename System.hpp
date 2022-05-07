/*
Defines a simple, two-var system of equations
*/

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <functional>
#include <iostream>
#include <stdint.h>
#include <vector>

enum Operator {
  Plus,
  Minus,
  Mul,
  Div,
  Square,
};

inline char switch_on_operator(Operator const& op) {
  switch (op) {
  case Plus:
    return '+';
  case Minus:
    return '-';
  case Mul:
    return '*';
  case Div:
    return '/';
  case Square:
    return '^';
  }
}

namespace matrix {
typedef int32_t Transposition[2][3];
typedef Operator Operations[3];

Operations* make_ops(std::tuple<Operator, Operator, Operator> const& ops) {
  Operations new_ops = {
      std::get<0>(ops),
      std::get<1>(ops),
  };
  return &new_ops;
}

inline void print_ops(Operations const& ops) {
  for (unsigned i = 0; i < 2; i++) {
    std::cout << switch_on_operator(ops[i]) << std::endl;
  }
}

} // namespace matrix

namespace systems {
/// \brief A system's coefficients
typedef std::vector<std::tuple<int32_t, int32_t>> Coeff;

/// \brief A generic tuple of three system variables
/// \note Can be used to hold all row solutions, system solutions, or unkowns
typedef std::tuple<int32_t, int32_t> VarBatch;

inline void sysprint(Coeff const& coeffs, matrix::Operations const& ops,
                     VarBatch const& rowsolns) {
  std::cout << "COEFF:\t\t"
            << "SOLN:\n";
  unsigned i = 0;
  for (auto c : coeffs) {
    std::cout << std::get<0>(c) << "x  ";
    std::cout << switch_on_operator(ops[i]) << "  ";
    std::cout << std::get<1>(c) << "y  \t\t";
    std::cout << '\n';
    i++;
  }
  std::cout << std::endl;
}

/// \brief Defines a Two-var System of Equations
typedef struct System {
private:
  Coeff coefficients;
  VarBatch row_soln, unknowns, system_soln;
  matrix::Transposition matrix;
  matrix::Operations operations;

public:
  System(Coeff const& coeffs, matrix::Operations const& ops,
         std::tuple<VarBatch> state) {
    coefficients = coeffs;
    memcpy(operations, ops, sizeof(operations));
    row_soln = std::get<0>(state);
  }

  inline void print() {
    sysprint(this->coefficients, this->operations, this->row_soln);
    matrix::print_ops(this->operations);
  }
};
} // namespace systems

#endif