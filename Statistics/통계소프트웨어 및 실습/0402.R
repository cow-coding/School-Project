grade <- c("A", "A", "B", "C", "B", "B")
f.grade <- factor(grade)
f2.grade <- factor(grade, order = T)
lev <- c("C", "B", "A")
f3.grade <- factor(grade, levels = lev, order = T)
levels(f2.grade)
levels(f3.grade)

x1 = 1:4; x2 <- c("kim","lee","jung","park")
dat = data.frame(x1,x2)
dat2 = data.frame(num=x1, name=x2)
dat3 = data.frame(x1,x2,stringsAsFactors = F)

dat[1]; dat[2]
dat[[1]]; dat[[2]]

x1 <- array(1:24,dim=c(4,3,2))
x2 <- array(1:32, dim=c(,2,2,4,2))

x <-1:25
x_mat <- matrix(x,nrow=5,ncol=5)
x_mat <- as.matrix(x)
x_num <- as.vector(x_mat)

d <- data.frame(a=1:10,b=rep("A",10),c=rep(T,10))
m1 <- as.matrix(d)
m2 <- as.matrix(d[,1])

x <- 1:100; sum1 <- sum(x[13:100])
x <- c(1:5,10:20,30:45,2:5,11:30)
x > 12
sum2 < sum(x[x>12])

x <- 1:100
x[seq(2,100,by=2)]
x_mat <- matrix(x,20,5)
x[,c(1,3,5)]

x_mat <- matrix(rnorm(100),20,5)
apply(x_mat,2,mean)
apply(x_mat,1,sum)
