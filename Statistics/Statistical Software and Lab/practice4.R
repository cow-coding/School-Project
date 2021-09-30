# No.1
getwd()
setwd("school/수업자료/통소실")
dir()
raw_dat = read.csv(file="Ex_data.csv")

# No.2
head(raw_dat,5)

# No.3
dim(raw_dat)

# No.4
install.packages("dplyr")
library(dplyr)
gene_name = select(raw_dat,Gene.Symbol)
write.table(gene_name, file="gene_name.txt", row.names = F, sep = '\t')

# No.5
select_col = raw_dat[,c(3,9,10)]
write.table(select_col, file = "sub_data.txt", row.names = F, sep = '\t')

# No.6
many_dat = raw_dat[c(31:100),seq(from=21,to=40,by=2)]
write.csv(many_dat,file = "sub_data2.csv")

# No.7
sum(is.na(raw_dat))

# No.8
which(is.na(raw_dat))

# No.9
which(is.na(raw_dat),T)

# No.10
NA_pos = which(is.na(raw_dat),T)
replace_col = apply(NA_pos, 2, mean,na.rm=T)[2]
replace_col
raw_dat[NA_pos] = replace_col
sum(is.na(raw_dat))
