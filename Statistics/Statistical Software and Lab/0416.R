getwd()
setwd('Documents')
setwd('school/수업자료/통소실')
dir()

Sys.getenv('JAVA_HOME')
Sys.setenv("JAVA_HOME"='/Library/Java/JavaVirtualMachines/jdk-14.0.1.jdk/Contents/Home')
system("java -version")
install.packages("xlsx")
library(xlsx)

dat = read.xlsx(file='food.xlsx', sheetIndex=1,as.data.frame=T,header=T,startRow=1)

head(dat)

x1 = data.frame(a = rnorm(10))
x1[2,1] = NA
head(x1)

write.xlsx(x1, file='test.xlsx', sheetName=as.character(1), col.names=T, row.names=F,append=F,showNA=F)

write.xlsx(x1, file = 'test.xlsx', sheetName = as.character(2), col.names = T, row.names = F, append = T, showNA = F)

for (i in 3:10) {
  write.xlsx(x1, file = 'test.xlsx', sheetName = as.character(i),col.names = T, row.names = F, append = T, showNA = F)
}

save(list = c("dat"),file="ex_dat1.Rdata")
save.image(file="ex_dat2.Rdata")
rm(list=ls())
load(file="ex_dat1.Rdata")
ls()
load(file="ex_dat2.Rdata")
ls()

dat = read.csv(file = "test3.csv")
length(dat[,1])
dim(dat)
dim(dat)[1]
dim(dat)[2]
nrow(dat); ncol(dat)

install.packages("dplyr")
library(dplyr)

x <- matrix(c(NA,1,3,NA,NA,2),3,2)
is.na(x)
sum(is.na(x))
which(is.na(x))
which(is.na(x),arr.ind = T)
which(is.na(x),T)
mean(x)
mean(x,na.rm=T)
apply(x, 2, mean)
apply(x,2,mean,na.rm=T)
x[which(is.na(x),T)]
x[which(is.na(x),T)]=0
x
