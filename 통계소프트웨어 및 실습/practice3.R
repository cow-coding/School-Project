#Practice3
# No.1
x <- seq(from=-10, to=10, length=30)
x

# No.2
y <- rep(c("S","T","A","T","S"), times=6)
y

# No.3
z <- rep(c(0, 7), each=15)
zm <- as.logical(z)
zm

# No.4
xmat <- matrix(x, 6, 5, byrow = T)
xmat

# No.5
xdat <- data.frame(x,y,zm)
xdat

# No.6
xlst <- list(data1=x, data2=y,data3=zm,data4=xdat)
xlst

# No.7
xdat
mat1 <- as.matrix(xdat[,c(1,2)])
mat1

# No.8
mat2 <- as.matrix(xdat[,c(1,3)])
mat2

# No.9
xsum <- sum(x[x > -2 & x <4])
xsum

# No.10
xmat
rsum <- apply(xmat, 1, sum)
rsum
cmean <- apply(xmat, 2, mean)
cmean
cvar <- apply(xmat, 2, var)
cvar
