# Problem 1
patch = read.csv('patch.csv')
patch

old = patch$oldpatch
new = patch$newpatch
n = length(patch)

## BootStrap
nb = 1000
theta_hat = cor(old, new)
theta_b = numeric(nb)

for (ib in 1:nb) {
  I = sample(n, n, replace=TRUE)
  theta_b[ib] = cor(old[I], new[I])
}

bias = mean(theta_b) - theta_hat; bias
se = sd(theta_b); se
alpha = 0.05

## normal interval
c(theta_hat-qnorm(1-alpha/2)*se, theta_hat+qnorm(1-alpha/2)*se)
## pivotal interval
q = (1-alpha/2)
c(2*theta_hat - quantile(theta_b, q), 2*theta_hat - quantile(theta_b, 1-q))
## percentile interval
c(quantile(theta_b, 1-q), quantile(theta_b, q))

## Jackknife
theta.jack = numeric(n)

for (i in 1:n) {
  theta.jack[i] = cor(new[-i], old[-i])
}
bias = (n-1) * (mean(theta.jack) - theta_hat)
bias

se = sqrt((n-1)*mean((theta.jack - mean(theta.jack))^2))
se


# Problem 2
# H0 : old == new VS H1 : old != new
Tstat = function(x, y) abs(mean(x) - mean(y))
tobs = Tstat(old, new)

B = 1000
tperm = numeric(B)
z = c(old, new); N = length(z); m = length(old)

for (i in 1:B) {
  idx = sample.int(N, m)
  tperm[i] = Tstat(z[idx], z[-idx])
}

mean(tperm > tobs)    # p-value too big
hist(tperm); points(tobs, 0, pc=19, col='red')