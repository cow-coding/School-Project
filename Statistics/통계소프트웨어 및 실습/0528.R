rm(list=ls())
getwd()
setwd('documents/school/수업자료/통소실')
load(file = 'expr_dat.Rdata')
gr_ind = gl(2,221)
uq_names = colnames(expr_dat)

t1 = t.test(expr_dat[,1], mu=7, conf.level = 0.95, alternative = "two.sided")

t2 = t.test(expr_dat[,1], mu=6.5, conf.level = 0.95, alternative = "less")
t2
t3 = t.test(expr_dat[,1], mu=6.5, conf.level = 0.95, alternative = "greater")

t1; t2; t3
names(t1); summary(t1)

x = expr_dat[gr_ind==1,1]
y = expr_dat[gr_ind==2,1]
t1 = t.test(x, y, mu=0, conf.level = 0.95, paired = F, alternative = "two.sided")

t2 = t.test(x, y, mu=0, conf.level = 0.95, paired = F, alternative = "less")

t3 = t.test(x, y, mu=0, conf.level = 0.95, paired = F, alternative = "greater")

t1;t2;t3


n=25
x=rnorm(n, mean=1, sd=1)
y=x+rnorm(n, mean = 0.5, sd=1)
t1 <- t.test(x,y,alternative = "two.sided",paired = T,var.equal = F)

t2 <- t.test(x,y,alternative = "less",paired = T,var.equal = F)

t3 <- t.test(x,y,alternative = "greater",paired = T,var.equal = F)

t1;t2;t3
