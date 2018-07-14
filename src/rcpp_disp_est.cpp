#include <Rcpp.h>
#include <math.h>
#include <numeric>
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
  int n = sum;

  return acos(1/(one_vec_norm * pi_hat_norm / n));
}


