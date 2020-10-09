# Monday-----------------------------
myname <- "Jason Bourne"
paste("My name is", myname, sep=" ")
file_id = 1533
paste("Dataset_",file_id,".txt", sep="")

paste("A","B",collapse = '/')
paste(c("A","B"), collapse = '/')
paste(c("A","B"), 1:2, collapse = '/')
paste(c("A","B"), 1:2, sep='?', collapse = '/')

test <- c("abcdefg", "AFFY1245820")
nchar(test)
f_name <- "AFFY1245820"
substr(f_name,5,nchar(f_name))
y = c("ax_1234", "ax_3456")
substr(y,4,7)

strtrim("ABCDEF",3)
strtrim(rep("abcdef",3), c(1,4,10))

x <- c(as = "asfef", qu = "qwerty", "yuiop[", "b", "stuff.blah.yech")
strsplit(x, "e")
strsplit(x, "[a-e]")
strsplit(x, "[aleu]")
unlist(strsplit("a.b.c", "."))
unlist(strsplit("a.b.c", "[.]"))
unlist(strsplit("a.b.c", ".", fixed = TRUE))

#Thursday--------------------------------
getwd()
setwd('Documents') #제가 맥북유저라 D드라이브가 없어요....ㅠㅠ
getwd()
dir.create("example2")
getwd()
unlink("example2",recursive = T)
dir()
?unlink

test = dir("/Users/kibeompark/Documents")
test
t1=grep("^[A-Ca-c][a-z]",test)
t1
t2=grep("[.]pkg$",test,value=T)
t3=grep("^[BbCc].+pkg$",test,value=T)
length(colors())
colors()[1:5]
cn=grep("white",colors(),value = T)
x11()
barplot(rep(3,length(cn)),col=cn)
x=c("010-3123-2134","032-860-7642","02-111-1234","010-123,5656")
grep("010-[0-9]{3,4}-[0-9]{4}",x,value = T)

getwd()
dir.create("example2")
setwd('/Users/kibeompark/Documents/example2')
for (i in 1:20) {
  write.table(1:10,file=paste0('data_',i,'.txt'))
}
fname=dir();fname
fname2=grep('data_[0-9][.]txt',fname,value=T); fname2
fanme3 = paste0(substr(fname2,1,5),"0",substr(fname2,6,nchar(fname2)))
fanme3
