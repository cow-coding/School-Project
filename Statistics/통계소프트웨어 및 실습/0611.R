col.table <- function(cols, main=NULL, fg=NULL) {
  n <- length(cols)
  plot(seq(n), rep(1, n), xlim = c(0, n), ylim = c(0, 1),
       type = "n", xlab = "", ylab = "", axes = F)
  if(is.null(main)) {
    main = paste("Color Table by", deparse(substitute(cols)))
  }
  title(main=main)

  if(is.null(fg)) {
    fg = unlist(lapply(cols,
                       function(x)
                         ifelse(mean(col2rgb(x)) > 127 | toupper(x) %in% c("WHITE", "#FFFFFF"), "black", "white")))
  } else
      fg = rep(fg, n)

  for (i in 1:n) {
    polygon(c(i - 1, i - 1, i, i), c(0.05, 1, 1, 0.05), col = cols[i])
    text(mean(c(i - 1, i), 0.52, labels = cols[i], srt=90, adj=0.5, col=fg[i], cex=1.5))
  }
}
par(mfrow=c(2,1))
col.table(1:16)
col.table(5:20)

col.map <- function(cols=colors()) {
  n <- length(cols)
  cnt <- floor(sqrt(n))
  plot.new()
  plot.window(xlim = c(0, cnt), ylim = c(0, cnt))

  for (i in 1:cnt)
    for(j in 1:cnt)
      rect(i-1, j-1, i, j, col=cols[(i-1)*cnt + j], border=NA)
}
col.map(colors())

seqs <- seq(0, 255, length = 15)
seqs
hexs = toupper(as.character.hexmode(seqs))
hexs
red = paste0("#", hexs, "0000")
green = paste0("#00", hexs, "00")
blue = paste0("#0000", hexs)
mix1 = paste0("#", hexs, hexs, hexs)
mix2 = paste0("#", rev(hexs), hexs, rev(hexs))
par(mfrow=c(5, 1), mar=c(1, 1, 3, 1))
col.table(red)
col.table(green)
col.table(blue)
col.table(mix1)
col.table(mix2)

x = c (1, 1.3, 1.6)
y = c(1, 2, 1)
par(mar = c(4, 2, 3, 1), mfrow = c(1, 2))
x11()
plot(x, y, pch = 16, cex = 20, col = c("red", "green", "blue"), xlim = c(0,3), ylim = c(-2,5))
title(main = "col=c('red', 'green','blue')")
plot(x, y, pch = 16, cex = 20, col = c("#FF000077", "#00FF0077", "#0000FF77"), xlim = c(0,3), ylim = c(-2,5))
dev.off()

par(mfrow = c(2,2))
par(mar = c(0.1, 0.1, 1, 0.1))
hsv(0.5, 0.5, 0.5)
hsv1 = c(hsv(0.5, 0.5, 0.5), hsv(0.6, 0.5, 0.5),
         hsv(0.7, 0.5, 0.5), hsv(0.8, 0.5, 0.5))
hsv2 = c(hsv(0.5, 0.5, 0.5), hsv(0.5, 0.6, 0.5),
         hsv(0.5, 0.7, 0.5), hsv(0.5, 0.8, 0.5))
hsv3 = c(hsv(0.5, 0.5, 0.5), hsv(0.5, 0.5, 0.6),
         hsv(0.5, 0.5, 0.7), hsv(0.5, 0.5, 0.8))
col.map(hsv1)
col.map(hsv2)
