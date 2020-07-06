install.packages("ggplot2")
library(ggplot2)

p <- ggplot(data=mtcars, aes(x=wt, y=mpg))
p = p + geom_point(colour="orange", size=6)
p

p <- ggplot(data=mtcars, aes(x=wt, y=mpg))
p = p+ geom_point(aes(color=cyl, size=gear))
p

p <- ggplot(data=mtcars, aes(x=wt, y=mpg))
p + geom_line()
p2 <- ggplot(data=mtcars, aes(x=wt, y=mpg))
p2 + geom_line(aes(x=wt, y=mpg), linetype=2, size=1,color=2)

mw_coef = coef(lm(mpg~wt, mtcars))
p <- ggplot(data=mtcars, aes(x=wt,y=mpg))
p <- p + xlim(1, 5) + ylim(10, 35) + geom_point()
p + geom_abline(intercept = mw_coef[1], slope = mw_coef[2], color = 4)
p + geom_vline(xintercept = 3, color = 2) + geom_hline(yintercept = 20, color=2)

p <- ggplot(data=mtcars, aes(x=wt, y=mpg))
p = p + geom_point()
p + geom_smooth()
p + geom_smooth(aes(linetype=factor(cyl)))

p <- ggplot(data=mtcars, aes(factor(cyl)))
p + geom_bar(fill="stellblue", color="black")
p + geom_bar(aes(fill=factor(gear)), color='black')

huron <- data.frame(year = 1875:1972, level = as.vector(LakeHuron))
p = ggplot(data=huron, aes(x=year, y=level))
p + geom_area()
p + geom_area(fill='steelblue') + coord_cartesian(ylim=c(min(huron$level)-2, max(huron$level)+2))

p = ggplot(data=huron, aes(x=year, y=level, ymin=huron$level-2, ymax=huron$level+2))
p + geom_ribbon(fill='steelblue')

# practice
getwd()
setwd('documents/school/수업자료/통소실')
kospi = read.table(file = 'kospi_data.txt', sep='\t')
kospi_s = kospi
kospi_s[2:123,1] = as.Date(kospi_s[2:123,1])
colnames(kospi_s) <- kospi_s[1,]
kospi_s = kospi_s[-1,]
kospi=kospi_s
x11()
kpoint = ggplot(data=kospi)
kpoint = kpoint + geom_point(mapping = aes(x=Date, y=Highest), color = "red")
kpoint = kpoint + geom_point(mapping = aes(x=Date, y=Lowest), color="blue")
kpoint = kpoint + geom_point(mapping = aes(x=Date, y=CurrentIndex))
kpoint
k = kpoint + geom_line(mapping = aes(x=Date, y=Highest, group=1), color = "red") + geom_line(mapping = aes(x=Date, y=CurrentIndex, group=1)) + geom_line(mapping = aes(x=Date, y=Lowest, group=1), color = "blue")
k
dev.off()

p <- ggplot(mtcars, aes(factor(cyl), mpg))
p + geom_boxplot()
p + geom_boxplot(aes(fill=factor(carb)))

movies = read.csv(file = 'movies.csv', header = T)
 p <- ggplot(movies, aes(x = rating))
p+geom_density()
p+geom_density(aes(fill=factor(mpaa)), alpha=0.25)

install.packages(c("reshape2", "maps", "mapproj"))
library(reshape2)
library(maps)
library(mapproj)
crimes <- data.frame(state = tolower(rownames(USArrests)), USArrests)
head(crimes)

states_map <- map_data("state")
p <- ggplot(crimes, aes(map_id=state))
p <- p + geom_map(aes(fill=Murder), map=states_map)
p <- p + expand_limits(x=states_map$long, y=states_map$lat)
p + coord_map()

df <- data.frame(x = c(rnorm(100, 0, 2), rnorm(100,1,4)), g = gl(2,100))
p <- ggplot(df,aes(x, color=g))
p + stat_ecdf()
p + stat_ecdf(geom="line", size=1)

world <- map_data("world")
head(world)
korea <- world[grep("Korea$", world$region),]
p <- ggplot(korea, aes(x=long, y=lat, group=group))
p <- p + geom_polygon(fill="white", color="black")
p
p + coord_fixed(ratio = 1)
