getwd()
setwd("Documents")
setwd("school")
setwd("수업자료")
setwd("통소실")
getwd()

dat = data.frame()
dat = edit(dat)
dat
fix(dat)

a = readline("Input any integer: ")
a
b = readline("Input two integer with comma (ex: 1,2) : ")
strsplit(b,"[,]")
as.numeric(unlist(strsplit(b,"[,]")))

dir()
x1 = scan(file = "input_noh.txt", what = numeric());x1[1:5]
x2 = scan(file = "input_noh.txt", what = character());x2[2:5]
x3 = scan(file = "input_noh.txt");x3[1:5]
x4 = scan(file = "input_h.txt", what = character());x4[1:5]
x = matrix(as.numeric(x4[-(1:2)]),ncol = 2,byrow = T)
x[1:3,]

dir()
dat = read.table(file = "input_noh.txt")
dat2 = read.table(file = "input_noh.txt",header=T)
dat3 = read.table(file = "input_h.txt",header = F)
dat4 = read.table(file = "input_h.txt",header = T)
dat5 = read.table(file = "input_h.txt",header = F, stringsAsFactors = F)
dat3[1:6,1]
dat5[1:6,1]
head(dat)
head(dat2)
head(dat3,4)
head(dat4)
tail(dat)
options()$stringAsFactors

x <- 1:10
cat(x, file="x.txt", sep="\n", append=F)
cat('\t',file = "x.txt",sep = "",append = T)
cat(x,file = "x.txt",sep = "\t",append = T)
cat(x,sep="\t")
cat("\n",1,"st element of x = ",x[1])

x1 <- 1:20
x2 <- rep(c("A","B","B","A"),5)
x3 <- rep(c(T,F),each=10)
dat <- cbind(x1,x2,x3)
dat <- data.frame(x1,x2,x3)
head(dat)
write.table(dat,file = "test1.txt",row.names = T, col.names = T,quote = T,sep = "\t")
write.table(dat,file = "test2.txt",row.names = F, col.names = F,quote = F,sep = "\n")
write.table(dat,file = "test3.csv", sep=",")
write.table(dat, file = "test4.txt", row.names = T,col.names = T,quote = T,sep = " ")
