setwd('documents/school/수업자료/통소실')
dir()
load(file = 'expr_dat.rdata')
uq_names = colnames(expr_dat)

indy = 8
indx = 200
x = expr_dat[,indx]
y = expr_dat[,indy]
fit = lm(y~x)
summary(fit)
x11()
plot(x,y,pch=16)
abline(fit,col=2,lwd=1.5)

names(fit)

fit$coefficients
fit$fitted.values
cbind(fit$fitted.values,fit[[1]][1]+fit[[1]][2]*x)[1:5,]

coef(fit)
resid(fit)
fitted(fit)
result = summary(fit)
names(result)

result[4]
result[[3]]
confint(fit)

pred1 = predict(fit, newdata = data.frame(x=2.3))
est = coef(fit);x1 = 2.3
y1 = est[1] + est[2]*x1
pred2 = predict(fit, newdata = data.frame(x = c(1,2.2,6.7)))

x2 = c(1,2.2,6.7)
indx = c(10,30,200)
indxr = c(10,200)
y = est[1]+ est[2]*x2
xf = expr_dat[,indx]
xr = expr_dat[,indxr]
y = expr_dat[,indy]
fit1 = lm(y~xf)
fit2 = lm(y~xr)
anova(fit2, fit1)

ftxt = paste0(uq_names[indy], '~', paste0(uq_names[indx], collapse="+"))
ftxtr = paste0(uq_names[indy], '~', paste0(uq_names[indxr], collapse="+"))
ftxt
ftxtr
colnames(expr_dat) = gsub("[ .]","",uq_names)
lm_dat = data.frame(expr_dat)
fit1 = lm(as.formula(ftxt), data=lm_dat)
fit2 = lm(as.formula(ftxtr), data=lm_dat)
anova(fit2, fit1)

rsd = resid(fit2)
ft = fitted(fit2)
plot(ft, rsd, type = 'p', pch=16)
hist(rsd, breaks=20)

qqnorm(rsd)
qqline(rsd, col=2, lwd=2)
