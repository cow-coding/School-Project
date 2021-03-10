lottery = function(number=c(), num_game) {
  data <- list()
  
  if (length(number) == 0) {
    # if user do not input the number
    for (i in 1:num_game) {
      data[[i]] = sample(1:45, size = 6)
    }
  }else {
    # if user input the number
    for (i in 1:num_game) {
      data[[i]] = number
    }
  }
  
  for (j in 1:num_game) {
    if(j == 1)
      cat(j,'st set : ',data[[j]],'\n')
    else if(j == 2)
      cat(j,'nd set : ',data[[j]],'\n')
    else if(j == 3)
      cat(j,'rd set : ',data[[j]],'\n')
    else
      cat(j,'th set : ',data[[j]],'\n')
  }
  
  pick = sample(1:45, size=7)
  answer = pick[1:6]
  bonus = pick[7]
  result = vector()
  total_money = 0
  
  for (k in 1:num_game) {
    eq = 0
    for (l in 1:6) {
      for (m in 1:6) {
        if(answer[l] == data[[k]][m])
          eq = eq + 1
      }
    }
    
    # money calculate
    if (eq == 6) {
      # 1st prize
      total_money = total_money + 2e9
    }else if(eq == 5) {
        for (n in 1:6) {
          if (bonus == data[[k]][n]) {
            eq = eq + 1
            break
          }
        }
      if(eq == 6)
        # 2nd prize
        total_money = total_money + 6e7
      else
        # 3rd prize
        total_money = total_money + 1.5e6
    }else if(eq == 4)
      total_money = total_money + 5e4
    else if(eq == 5)
      total_money = total_money + 5e3
    
    result[k] = eq
  }
  total_money = total_money - num_game * 1000
  ret = c(result,total_money)
  return(ret)
}

set.seed(12191601)

total = 0
count = 0
for (i in 1:1040) {
  cat('<',i,'day result >\n')
  x=lottery(,5)
  cat(i,'day income : ',x[6],'won\n')
  total = x[6] + total
  cat('for',i,'days:',total,'\n')
}