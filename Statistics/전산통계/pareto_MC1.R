# No.1 
install.packages("EnvStats")
library(EnvStats)

u <- runif(10000, 0, 1)
a=2
b=2
x = b * (1 - u)^(-1/a)

pareto = dpareto(x, location = 2, shape = 2)

par(mfrow=c(1,2))
hist(x, probability = T)
lines(density(x), col="blue")
hist(pareto, probability = T)
lines(density(pareto), col="red")

# No.2
par(mfrow=c(1,1))
B <- function(a, b, y){
  (gamma(5)/gamma(3)*gamma(2)) * y^(a-1) * (1-y)^(b-1)
}

g <- function(y){
  y/y
}

n = 1000
i = 1
M = 1.8
result = numeric(n)

while(i <= n) {
  y = runif(1000, 0, 1)
  u = runif(1, 0, 1)
  
  if(u <= B(3, 2, y)/(M*g(y))) {
    x[i] = u
    i = i + 1
  }
}

hist(x, probability = T)
lines(density(x), col='red')
lines(density(dbeta(x, 3, 2)), col="blue")

# No.3
y = runif(1000)

Y = (gamma(5)/gamma(4)*16)*(y/1+2*y)

G <- function(a, b, x) {
  (1/gamma(a) * b^a) * x^(a-1) * exp(-x/b)
}

par(mfrow=c(1,2))
hist(Y, probability = T)
lines(density(Y), col="red")
hist(G(4,2,y), probability = T)
lines(density(G(3,2,y)), col="blue")
