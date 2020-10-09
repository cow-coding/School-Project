getwd()
setwd('documents/school/수업자료/통소실')
dir()
dir.create('./datafile')
f_pre = './datafile/file_'
f_post = '.txt'
dat = mtcars
n = nrow(dat)
cut = 10
nfile = ceiling(n/cut)

for (i in 1:(nfile-1)) {
  idx = (cut * (i - 1) + 1):(cut * i)
  write.table(dat[idx,], file = paste0(f_pre, i, f_post), sep = '\t')
}
idx = (cut * i + 1):n
write.table(dat[idx,], file = paste0(f_pre,i + 1, f_post), sep = '\t')


setwd('datafile')
dir()
rdat = read.table(file = 'file_1.txt',header = T)
for (i in 2:4) {
  tmp = read.table(file=paste0('file_',i,'.txt'),header = T)
  rdat = rbind(rdat, tmp)
}
rdat
dim(rdat)


ch = c("A/B/C/D/F", "A/AA", "BB/B", "Quit", "CC/C")
xp = list()
i = 1
while (ch[i] != "Quit" & i <= length(ch)) {
  xp[[i]] = unlist(strsplit(ch[i],'/'))
  print(xp[[i]])
  i = i + 1
}
table(unlist(xp))


system.time({
  s = 0
  for (i in 1.1:1e8) {
    s = s + i
  }
})

y <- system.time(sum(1.1:1e8))
y[1];y[2];y[3]

tic = Sys.time()
s = 0
for (i in 1:1e6) {
  s = s+i
}
toc = Sys.time()
as.numeric(toc - tic, units = 'secs')
