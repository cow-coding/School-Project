# No.1
m = 1000
y = runif(m,0,1)
i = seq(0.1, 0.9, 0.1)
b = 1/beta(3,3)
g <- function(x) {x^2*(1-x)^2}
beta.hat <- function(x , a) {x * mean(g(a)) * b}

beta_mc = mean(beta.hat(i, y))
beta_origin = mean(pbeta(i, 3, 3))

beta_mc
beta_origin

# No.2
x = runif(m,0,0.5)
theta.hat = 0.5*mean(exp(-x))
print(1-exp(-0.5))
theta.hat

hat.var = mean(x - theta.hat^2)

x.star = rexp(m)
theta.star = 0.5*mean(exp(-(x.star < 0.5)))
theta.star
star.var = mean((x.star < 0.5) - theta.star^2)

hat.var
star.var

# No.3
y = rnorm(m)
IS = y^2*(y > 1)
mean(IS)
