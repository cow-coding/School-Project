# practice6
# No.1
for (i in 1:5) {
  if (i <= 3) {
    cat(rep('*',2 * i - 1))
    cat(rep(' ',9 - 3 * i))
    cat(rep('*',2 * i - 1),"\n")
  }else {
    cat(rep('*',2 * (5-i) + 1))
    cat(rep(' ',-1 * (9 - 3 * i)))
    cat(rep('*',2 * (5-i) + 1),"\n")
  }
}

# No.2
for (i in 1:100) {
  sum = sum + i
  if (sum >= 3000) {
    idx = i
    print(i)
    break
  }
}

# No.3
nsum = 0
for (i in 1:200) {
  if(sum(i %% (1:i) == 0)==2)
    nsum = nsum + 1
}
print(nsum)

# No.4
ans = 0
for (i in 30:50) {
  if (sum(i %% (1:i) == 0) != 2)
    next()
  else
    ans = ans + i
}
print(ans)

# No.5
x = runif(1e7,0,100)
# 1)
looptime <- system.time({
  nsum = 0
  for (i in x) {
    if(i > 5 & i < 20)
      nsum = nsum + i
  }
  print(nsum)
}
)

idxtime <- system.time({
  nsum = sum(x[which(x > 5 & x < 20)])
  print(nsum)
})
idxtime
looptime
print(looptime - idxtime)
