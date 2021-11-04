# No.1
install.packages("EnvStats")
library("EnvStats")

pareto = function(a, b, n=1000) {
  u = runif(n)
  x = b/(1-u)^(1/a)
  x
}

x = pareto(2, 2, 10000)
hist(x, probability = TRUE)
x_1 = seq(2, max(x), length=1000)
lines(dpareto(x_1, 2, 2), lwd=2)


# No.2
beta32 = function(n=1000) {
  x = numeric(n)
  i = 1
  
  while (i <= n) {
    y = runif(1)
    u = runif(1)
    
    if (u <= (27/4)*((y^2)*(1-y))) {
      x[i] = y
      i = i + 1
    }
  }
  
  x
}

x = beta32(1000)
hist(x, probability = TRUE)
x_1 = seq(0, 1, length=1000)
lines(x_1, dbeta(x_1, 3, 2), lwd=2)


# No.3
n = 1000
r = 4
b = 2
g = rgamma(1000, 4, 2)
y = rexp(1000, g)

mixture = function(x, r, b) {
  (r * b) / (1+b*x)^(r+1)
}

x = runif(1000)
y1 = mixture(x, 4, 2)
par(mfrow = c(1, 2))
hist(y, probability = TRUE)
hist(y1, probability = TRUE)

