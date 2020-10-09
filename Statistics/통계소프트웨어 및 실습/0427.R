wd_count = function(x, sep=" ") {
  temp = gsub("[(),.?!/]",sep,x)
  temp = unlist(strsplit(temp,sep))
  xrm = c("","a","an","the")
  temp = temp[!(temp %in% xrm)] # temp[temp!=""]
  return(table(tolower(temp)))
}

tx_data = c("Hello, I like statistics.",
            "I want to go out.",
            "You need to take a break.",
            "Your are so nice.")
res = wd_count(tx_data,sep=' ')
sort(res,decreasing = T)

googoo81 <- function(x){
  cat("\n")
  for (i in 1:9) {
    cat(x," * ",i," = ",x*i,"\n")
  }
  cat("\n")
}
googoo81(5)

fibona <- function(n) {
  if(n == 1) return(1)
  if(n == 2) return(rep(1,2))
  x <- rep(1,n)
  for (i in 3:n) {
    x[i] <- x[i - 1] + x[i - 2]
  return(n)
  }
}
fibona(1);fibona(2);fibona(3)

xlst = list(rnorm(10), b = 1:10)
plot_list = function(x, c = 1) {
  n = length(x)
  for (i in 1:n) {
    x11()
    plot(x[[i]], type = 'p', pch = c, main = paste0("Num-",i))
  }
}
plot_list(xlst, c=16)

a <- c(1,3,5,6)
mean.k <- function(x,k)
  return(mean(x^k))
mean.k(a,2)
mean.k2 <- function(x, k = 3)
  return(mean(x^k))
mean.k2(a,2); mean.k2(a)

a <- c(1,3,5,6)
m.k <- function(x,k,t)
  return(mean((x-t)^k))
m.k(a,2,1); m.k(a,1,2)
m.k(a, k = 2, t = 1)
m.k(a, t = 2, k = 1)
m.k
read.table

a <- c(1,3,5)
noact <- function(x) {
  loc <- 3
  return(loc)
}
noact(a); loc

noact <- function(x, type = 1) {
  if(type == 1) a[1] <- 3
  if(type == 2) a[1] <<- 3
  return(a)
}
noact(10)
a
noact(5,2);a
