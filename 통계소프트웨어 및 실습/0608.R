library(lattice)
x11()
trellis.par.set(theme = col.whitebg())
dotplot(variety ~ yield | site, data = barley,
        groups = year, key = simpleKey(levels(barley$year),space  = "bottom", columns = 2),
        xlab = "Barley yield (bushels/acre) ", ylab = "Variety",
        aspect=0.5, layout = c(2,3),
        scales=list(alternating = FALSE, y = list(abbreviate=T, minlength=5),
                    font=4, col="blue"),
        main = "dotplot(variety ~ yield | site, data = barley, groups = year)",
        sub = list("arguments = key, aspect, scales, etc", col = "gray"))

summ = matrix(0,4,4)
cname=paste(paste("x",1:4,sep=''),paste("y",1:4,sep=''),sep=' vs. ')

x11()
par(mfrow=c(2,2))
for (i in 1:4) {
  plot(anscombe[,i], anscombe[,i+4], pch=16, col=2,
       main=cname[i], xlab=paste("x",i,sep=''),
       ylab=paste("y",i,sep=''),
       xlim=c(4,20),ylim = c(3,13))
  abline(summ[1:2,i],col=4,lwd=2)
}
