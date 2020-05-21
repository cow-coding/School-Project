mat = expr_dat[,c(3,4,7,8)]
x11()
install.packages("gplots")
library(gplots)
boxplot(mat,col=rainbow(4,alpha=0.6))
res = boxplot(mat,plot=)
res$out[res$group==1]

pop_dat = read.csv(file = 'table_2_2.csv')
plot(pop_dat[,1],pop_dat[,2],type = 'l',xlab='연도',ylab = '인구수')
x11()
plot(pop_dat[,1],pop_dat[,2],type = 'b',xlab='연도',ylab = '인구수')


ind1=8; ind2=12
plot(expr_dat[,ind1], expr_dat[,ind2], type='p', pch=16, xlab=uq_names[ind1],ylab = uq_names[ind2])
cor_mat = cor(expr_dat)
which.max(cor_mat[ind1,-ind1])
ind1=8; ind2=200
plot(expr_dat[,ind1], expr_dat[,ind2], type='p', pch=16, xlab=uq_names[ind1],ylab = uq_names[ind2])

ind = c(2,8,12,200)
pairs(expr_dat[,ind])
pairs(expr_dat[,ind], "Expression Data", pch = 21, bg = c("red","blue")[gr_ind])

iris
pairs(iris[1:4], pch=21, bg=c("red","green3","blue")[as.numeric(iris$Species)])


x = c(1,2,3,1,2,5,5,3,3,3,2)
tb_x = table(x); tb_x
as.numeric(names(tb_x)[which.max(tb_x)])
Mode = function(vec) {
  tb = table(vec)
  return(as.numeric(names(tb)[which.max(tb)]))
}
Mode(x)

quantile(expr_dat[,1], 0.25, type = 2)
quantile(expr_dat[,1], c(0.25, 0.5, 0.75), type = 7)

height = c(72,74,68,76,74,69,72,79,70,69,77,73)
sd(height) / mean(height)*100

install.packages("moments")
library(moments)
skewness(expr_dat[,1])
kurtosis(expr_dat[,1])
hist(expr_dat[,1], freq = F)
x = seq(5.5,8.5,length=10)
lines(x, dnorm(x,mean = mean(expr_dat[,1]),sd(expr_dat[,1])))

table(mtcars$cyl)
table(mtcars$am)
table(mtcars$cyl, mtcars$am)
table(mtcars$cyl, mtcars$am, mtcars$gear)

cov(expr_dat[,1], expr_dat[,5])
cov(expr_dat[,c(1,5,8)])
var(expr_dat[,1])

cor(expr_dat[,1], expr_dat[,5])
