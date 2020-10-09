install.packages("ggplot2")
library(ggplot2)
head(mtcars)

p <- ggplot(mtcars, aes(wt, mpg, color=cyl))
x11()
p
p = p + geom_point()

names(p)
head(p$data)
p$layers
p$scales
p$mapping
p$theme
p$coordinates
p$facet
p$labels
p$labels$x = 'Weight'
p$labels$y = 'MPG'
p$labels$colour = "Cylinder"
p


attributes(p)
summary(p)

p <-ggplot(mtcars, aes(factor(cyl), fill=factor(cyl)))
p <- p + geom_bar(width = .5)
p <- p + facet_grid(. ~ gear)
p

p5 = p + facet_grid(rows=vars(am), cols = vars(gear))
p5

p <- ggplot(data = iris, aes(x=Sepal.Length, y=Sepal.Width))
p + geom_point(aes(color=Species))
p2 <- p + geom_point(mapping = aes(x=Petal.Length, y=Petal.Width, color=Species), pch=17)
p2

p <- ggplot(data=iris)
p <- p + xlab("Length") + ylab("Width")
p

p2 <- p + geom_point(mapping = aes(x=Sepal.Length, y=Sepal.Width), colour="blue", pch=19)
p2

p3 <- p + geom_point(mapping = aes(x=Petal.Length, y=Petal.Width), colour="red", pch=17)
p3

p2+geom_point(mapping = aes(x=Petal.Length, y=Petal.Width), colour="red", pch=17)
