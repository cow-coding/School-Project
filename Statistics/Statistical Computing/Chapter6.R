# No.1
MCbeta = function(x, a, b, n=100000) {
  ret = c()
  
  for (i in 0:length(x)) {
    beta = rbeta(n, a, b)
    m = mean(beta <= x[i])
    ret[i] = m
  }
  
  return(ret)
}

x <- seq(0.1, 0.9, by=0.1)
mc_beta = MCbeta(x, 3, 3)
p_beta = pbeta(x, 3, 3)
par(mfrow=c(1,1))
plot(mc_beta, pch=1, cex=1, xlab='X', ylab='y')
par(new=TRUE)
plot(p_beta, pch=2, cex=2, xlab='X', ylab='y')


# No.2
e = function(x) exp(-x)
n = 100000

f1 = function(e, n) {
  u = runif(n, 0, 0.5)
  mean(e(u)/2)
}

f2 = function(n) {
  x = rexp(n)
  mean(x <= 0.5)
}

mc1 = c()
mc2 = c()

for (i in 1:1000) {
  mc1[i] = f1(e, n)
  mc2[i] = f2(n)
}

var(mc1)
var(mc2)

# No.3
g1 = function(x) x^2*(x > 1)
g2 = function(x) x^2 * dnorm(x) * (x > 1)
f = function(x) dexp(x-1)

n = 100000
x1 = rnorm(n)
mean(g1(x1))
x2 = rexp(n)+1
mean(g2(x2)/f(x2))

