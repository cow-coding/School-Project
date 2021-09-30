x <- 1:5
y <- -2:2
if(any(x<0)) print(x)

if (any(y<0)) {
  print(abs(y))
  cat("\n y contains negative values")
}

if (pi>3) cat("\n expr(T)") else cat("\n expr(F)")

x <- 1:5
if(length(x)==5) {
  if (sum(x)==15) {
    cat("\n Vector x length=",length(x),", sum = ",sum(x))
  }else {
    cat("\n Vector x length !=",length(x))
  }
}

a = 1; b = 2; c=-3
D=b^2-4*a*c
if (D>0) {
  rt=c((-b-sqrt(D))/(2*a),(-b+sqrt(D))/(2*a))
} else if(D==0) {
  rt = -b/(2*a)
} else {
  cat("\n No roots")
}

x = c(10,3,6,9)
y=c(1,5,4,12)
ifelse(x>y,x,y)
score = c(80,75,40,98)
grade=ifelse(score >= 50,"pass","fail")
data.frame(score,grade)

x<-c(1,3,2,5,2)
i <- 2
switch (i,mean(x),median(x),sd(x),var(x))
type <- "mean"
switch(type, mean=mean(x),sd=sd(x),var=var(x))

x = runif(10)

# No.1
if(sum(x) > 5){
  cat("sum(x) is greater than 5")
}else if(sum(x)<5){
  cat("sum(x) is less than 5")
}else {
  cat("sum(x) is equal to 5")
}

# No.2
y=ifelse(x<0.5,x,x-0.3)
print(y)

# No.3
i =3
i=1
switch (i,x+y,x-y,x*y)

# No.4
score = 65

if(score >= 90){
  print("A")
}else if(score >=75){
  print("B")
}else if(score >= 50){
  print("C")
}else
  print("D")

# No.5
type = "sqrt"

switch (type,
  "sqrt" = sqrt(score),
  "square" = score^2,
  "log" = log(score)
)
