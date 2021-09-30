# Practice 7
# No.1
x = 1:10

func1 = function(x) {
  size = length(x)
  summage = sum(x)
  mul = prod(x)
  maxi = max(x)
  mini = min(x)
  
  return (list(size, summage, mul, mini, maxi))
}

func1(x)

# No.2
x = 1:10

func2 = function(x, opt) {
  if (opt == 1) {
    func1(x)[1]
  }else if (opt == 2) {
    func1(x)[2]
  }else if (opt == 3) {
    func1(x)[3]
  }else if (opt == 4) {
    func1(x)[4]
  }else if (opt == 5) {
    func1(x)[5]
  }
}

func2(x, 1)    # length
func2(x, 2)    # summage
func2(x, 3)    # product
func2(x, 4)    # minimum
func2(x, 5)    # maximum

# No.3
x = 1:10

func2 = function(x, opt=3) {
  if (opt == 1) {
    func1(x)[1]
  }else if (opt == 2) {
    func1(x)[2]
  }else if (opt == 3) {
    func1(x)[3]
  }else if (opt == 4) {
    func1(x)[4]
  }else if (opt == 5) {
    func1(x)[5]
  }
}

func2(x)

# No.4
geungong = function(a, b, c) {
  if(a == 0) {
    return (-c / b)
  }else {
    up1 = -b
    up2 = -b
    down = 2 * a
    d = b**2- 4*a*c
    
    if (d < 0) {
      up1 = up1 + sqrt(as.complex(d))
      up2 = up2 - sqrt(as.complex(d))
    }else {
      up1 = up1 + d
      up2 = up2 - d
    }
    
    x1 = up1 / down
    x2 = up2 / down
    
    return (list(x1, x2))
  }
}

geungong(2, -5, 3)
geungong(2, -3, 3)
geungong(0, 4, 3)
