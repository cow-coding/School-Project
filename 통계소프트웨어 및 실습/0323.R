real <- 3.5
as.integer(real)
intg <- 3
is.integer(intg)

ch <- c("red","blue","yellow")
ch[1]
ch[3]


test <- c(TRUE,FALSE,TRUE)
is.logical(test)
as.numeric(test)

vec <- c(1,3,4,2,5)
vec
vec[7] = 5
vec


rm(list = ls())
assign("x",1:10)
x
name=paste0("x",1:200)
name
for (i in 1:200) {
  assign(name[i],1:10)
}
ls()
rm(list=name)
ls()