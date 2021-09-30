x <- c(1,2,3, 1); y <- c(1,2,3,4)
v <- 2 * x + y + 1
print(v)

3 ^ 2 %% 4
3 * 2 %% 4

log(exp(1))

range(x)
sum(x)
prod(x)

var(x)
vari <- sum((x-mean(x))^2)/(length(x)-1)
print(vari)

complex(real=-17,imaginary = 0)
complex(3,1)
complex(3,10,-2)

#practice2
#1
x <- c("0","21","12","16")
#2
x <- as.integer(x)
sort(x)
#3
x <- as.logical(x)
#4
y <- seq(0,30,10)
#5
answer <- x < y & x <= y
#6
ans <- rep(c(TRUE,FALSE),times = 10)
