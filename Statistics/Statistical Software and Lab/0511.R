.Platform
setwd('Documents')
dir()
setwd('school/수업자료/통소실')
dir()

raw_dat = read.csv(file = "Ex_data.csv", header = T, stringsAsFactors = F)
head(raw_dat[,1:20])
dim(raw_dat)

gr_ind = gl(2, 221)
gr_ind

dat_mat <- t(as.matrix(raw_dat[,-1]))
dim(dat_mat)
rownames(dat_mat) <- paste0("s",1:nrow(dat_mat))
colnames(dat_mat) <- raw_dat[,1]
head(dat_mat[,1:20])

indx <- which(is.na(dat_mat),T)
indx
col_ind = indx[,2]
col_m = apply(dat_mat[,col_ind],2, mean, na.rm = T)
col_m
dat_mat[indx] = col_m
sum(is.na(dat_mat))
dim(dat_mat)

uq_names <- unique(colnames(dat_mat))
p <- length(uq_names); n <- dim(dat_mat)[1]
expr_dat <- matrix(0,n,p)
for (i in 1:p) {
  expr_dat[,i] = apply(as.matrix(dat_mat[,colnames(dat_mat) == uq_names[i]]),1,mean)
  cat("\n",i,"-th step")
}
colnames(expr_dat) < uq_names
rownames(expr_dat) < rownames(dat_mat)
head(expr_dat[,1:20])
dim(expr_dat); sum(is.na(expr_dat))
