#include <Rcpp.h>
#include <math.h>
#include <numeric>
#include <algorithm>
using namespace Rcpp;

double sqr(double i) {
  return i*i;
}

// [[Rcpp::export]]
double disp_est_inCPP(NumericVector pi_hat_emp) {

  double sum = std::accumulate(pi_hat_emp.begin(), pi_hat_emp.end(), 0.0);

  double one_vec_norm = sqrt(pi_hat_emp.size());
  std::transform(pi_hat_emp.begin(), pi_hat_emp.end(), pi_hat_emp.begin(), sqr);

  double sum_sq = std::accumulate(pi_hat_emp.begin(), pi_hat_emp.end(), 0.0);

  double pi_hat_norm = sqrt(sum_sq);
  //pi_hat_norm  <- sqrt(sum(pi_hat_emp^2))
  int n = sum;

  return acos(1/(one_vec_norm * pi_hat_norm / n));
}


// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically
// run after the compilation.
//

