setwd('Documents')
setwd('school/수업자료/통소실')
dat = read.table(file="Ex211_tab.txt", header = T, sep = '\t', fileEncoding = "CP949",encoding = "UTF-8")
head(dat)
dat$Job
attach(dat);Job
search()
quartz()
plot(Job, main="직업의 막대그림", ylab="인원수(명)",ylim=c(0,15), xlim=c(0,5))
box()
freq = table(dat[,6])
barplot(freq)
dev.off()

data("VADeaths")
install.packages("gplots")
library(gplots)
x11()
barplot2(t(VADeaths), beside = TRUE, col = gray(seq(0.4,0.9,length=5)), legend=colnames(VADeaths), ylim = c(0,100))
title(main = "Death Rates in Virginia", font.main=4)

hh <- t(VADeaths)[,5:1]
mybarcol <- "gray20"
cil <- hh * 0.85
ciu <- hh * 1.15
mp <- barplot2(hh, beside = T, col = gray(seq(0.4,0.9,length = 5)), legend = colnames(VADeaths), ylim = c(0,100), main = "Death Rates in Virginia", font.main = 4, sub = "Faked 95 percent error bars", cex.names = 1.5, plot.ci = T, ci.l = cil,ci.u = ciu,plot.grid = T)
box()

pie(freq, main = "직업의 원그림")
pie(rep(1,24), col = rainbow(24), radisu = 0.9)
pie.sales <- c(0.12,0.3,0.26,0.16,0.04,0.12)
lbl = c("Blueberry","Cherry","Apple","Boston Cream", "Other","Vanilla Cream")
names(pie.sales) = paste0(lbl, " (", pie.sales*100, "%)")
pie(pie.sales, col = rainbow(length(pie.sales)))

getwd()
load(file = 'expr_dat.Rdata')
x <- expr_dat[,10]
x11()
hist(x, breaks = 20, col = "gray", main = uq_names[10])
hist(x, breaks = 20, freq = F ,col = "lightblue", main = uq_names[10])

set.seed(7)
hist.data <- rnorm(100, 3, 2)
hist_info = hist(hist.data, breaks = "Sturges", plot=F)
hist_info
nbins = length(hist_info$mids)
col_vec = rep('white',nbins)
col_vec[hist_info$density > 0.15] = "lightblue"
x11()
hist(hist.data, breaks = "Sturges", col=col_vec)
