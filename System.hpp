#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <functional>
#include <iostream>
#include <stdint.h>
#include <vector>

namespace matrix {
typedef int32_t Transposition[3][4];
typedef char Operations[3][2];

inline void print_ops(Operations const& ops) {
  std::cout << "OPS:";
  for (unsigned i = 0; i <= 2; i++) {
    std::cout << '\n';
    for (unsigned j = 0; j <= 1; j++) {
      std::cout << ops[i][j] << ", ";
    }
  }
  std::cout << std::endl;
}
} // namespace matrix

namespace systems {
/// \brief A system's coefficients
typedef std::vector<std::tuple<int32_t, int32_t, int32_t>> Coeff;

inline void print_coeffs(Coeff const& coeffs) {
  std::cout << "COEFF:\n";
  for (auto c : coeffs) {
    std::cout << std::get<0>(c) << "x  ";
    std::cout << std::get<1>(c) << "y  ";
    std::cout << std::get<2>(c) << "z  ";
    std::cout << '\n';
  }
  std::cout << std::endl;
}

/// \brief A generic tuple of three system variables
/// \note Can be used to hold all row solutions, system solutions, or unkowns
typedef std::tuple<int32_t, int32_t, int32_t> VarBatch;

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
    print_coeffs(this->coefficients);
    matrix::print_ops(this->operations);
  }
};
} // namespace systems

#endif