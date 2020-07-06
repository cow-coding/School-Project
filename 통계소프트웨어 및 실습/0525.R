?dnorm
dnorm(0, mean = 0, sd = 1)
qnorm(0.3, mean = 5, sd = 5)
pnorm(3, mean = 0, sd = 3)
rnorm(1000, mean = 10, sd = 5)

dunif(c(2:4), min = 2, max = 4)
qunif(0.3, min = 0, max = 1, lower.tail = T)
punif(0.2, 0,1,lower.tail = F)
runif(10,0,1)

for (i in 0:5) {
  cat(dhyper(i, 10, 10, 5, log = FALSE),'/')
  cat(phyper(i, 10, 10, 5, lower.tail = TRUE, log.p = FALSE),'\n')
}
qhyper(0.2, 10, 10, 5, lower.tail = TRUE, log.p = FALSE)
rhyper(20,10,10,5)

dbinom(x, 2, 0.2, log = FALSE)
pbinom(2, 2, 0.2, lower.tail = TRUE, log.p = FALSE)
qbinom(0.1, 2, 0.2, lower.tail = TRUE, log.p = FALSE)
rbinom(2, 2, 0.1)

dnorm(x, 0, 1, log = FALSE)
pnorm(2, 0, 1, lower.tail = T, log.p = F)
qnorm(0.5, 0, 1, lower.tail = T, log.p = F)
rnorm(2, 0, 1)

dchisq(x, 3, log = F)
pchisq(2, 2, lower.tail = T, log.p = F)
qchisq(0.3, 2, lower.tail = T, log.p = F)
rchisq(3, 2)

?dt
dt(3, 2, log = F)
pt(2, 2, lower.tail = T, log.p = F)
qt(0.2, 2, lower.tail = T, log.p = F)
rt(2, 3)

df(x, 2, 3, log = F)
pf(2, 2, 3, T, F)
qf(0.2, 2, 3, T, F)
rf(5, 2, 3)

# CLT
df = 4
niter = 100
xm <- rep(0, niter)
for (i in 1:niter) {
  X <- rchisq(100, df=4)
  xm[i] = (mean(X)-4)/(sqrt(2*4)/sqrt(100))
}
hist(X, breaks=20, main = expression(chi^2~(4)), col = 'lightblue')
x11()
hist(xm, breaks=20, main = expression(over(bar(X)-mu, sigma/sqrt(n))),col = 'gray', xlab='normalized sample mean')
