vec <- vector()
vec <- 1:10
vec2 <- c("abc", "def")
vec3 <- c(T,F,T,F)
names(vec2) <- c("first","second")
vec2["first"]

x1 <- matrix(1:20,nrow=5,ncol=2,byrow=T)
x2 <- matrix(1:10,5,2,byrow = F)
print(x1)
print(x2)
cbind(x1,x2)
rbind(x1,x2)

A <- matrix(1:12,4,3)
rownames(A) <- c(paste0("n", 1:4))
colnames(A) <- c(paste0("x", 1:3))
print(A)
A[1,]
A[,2]
A[,-3]
B <- matrix(1,4,3)
A + B

a <- matrix(1:6,2,3); b <- matrix(1,3,2)
a%*%b
A <- matrix(1:4,2,2)
solve(A)

A <- matrix(1:12,4,3)
t(A)
A <- matrix(1:9,3,3)
sum(diag(A))

A <- matrix(1:4,2,2)
det(A)
eigen(A)$values

lst1 = list(a = 1:10, b =matrix(1:4,2,2))
lst2 <- list()
lst2[[1]] <- matrix(1:10,5,2)
lst2[[2]] <- lst1

lst1$a
lst1$b

lst1[1]
lst1[[1]]
lst2[[1]]
lst2[[1]][3]
lst1[[2]]
lst1[2]
lst2[2]
lst2[1]
lst2[[2]][[1]]
