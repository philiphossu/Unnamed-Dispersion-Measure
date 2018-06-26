disp_est <- function(pi_hat_emp) {
  one_vec_norm <- sqrt(length(pi_hat_emp))
  pi_hat_norm  <- sqrt(sum(pi_hat_emp^2))
  n            <- sum(pi_hat_emp)
  print(n);
  print(pi_hat_norm);
  print(one_vec_norm);
  # Error is occuring Y on c(1,1,1), c(2,2,2), but N c(3,3,3)
  # Generally, error occurs when having to take acos(~1)
  if(is.na(ret <- acos(1 / (one_vec_norm * pi_hat_norm / n)))){
    return(0)
  }
  ret
}


disp_est_cTest <- function(x) {
  .Call('_unnamedDispersionMeasure_disp_est_inCPP',x)
}


