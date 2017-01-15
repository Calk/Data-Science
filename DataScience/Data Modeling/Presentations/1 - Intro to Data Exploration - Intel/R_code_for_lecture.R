##Basic ML course - Avrahami

## Uncomment if you are missing these packeges
#install.packages(c("infotheo", "e1071", "rpart", "outliers", "MASS"))

##uploading the cars data and packages
library(infotheo)
library(e1071)
library(rpart)
library(outliers)
library(MASS)
cars.data <- rpart::car90

## Data File location
## Change this to where your dataset is located!
adult_data_file = "~/Downloads/adult.data.txt"

##defining a fucntion I have written for evaluation
evaluation.based.vecotrs <- function(actual, prediction){
  SST <- sum((actual-mean(actual))^2)
  SSReg <- sum((prediction-mean(actual))^2)
  SSRes <- sum((prediction-actual)^2)
  
  R2 <- 1-SSRes/SST
  RMSE <- sqrt(SSRes/length(actual))
  return(list(R2 = R2, RMSE = RMSE))
}

######################################################################################################
######################################################################################################
##Example #1
##summary and general functions - data types example
head(cars.data)
summary(cars.data)
sapply(cars.data, FUN = class)

##Example #2
##distnaces measures - explain why the distance measure is important to care about
theta <- seq(-pi,pi,len=100)
x1 <- cbind(cos(theta),sin(theta)) + rnorm(100,sd=0.05)
x2 <- cbind(0.5*cos(theta),0.5*sin(theta)) + rnorm(100,sd=0.05)
x <- rbind(x1,x2)
plot(x1, pch=20)
points(x2, pch=20)

cl <- kmeans(x, 2)
plot(x, col = cl$cluster)
points(cl$centers, col = 1:2, pch = 8, cex=2)

##correlation and MI
##first - relation between correlation and R^2
##Example #3
subset <- cbind(cars.data$Price, cars.data$Weight)
subset <- as.data.frame(subset[complete.cases(subset),])
colnames(subset) <- c('Price', 'Weight')
lm.model <- lm(Price~Weight, data = subset)
summary(lm.model)
evaluation.based.vecotrs(subset$Price, lm.model$fitted.values)
cor(subset)^2


##other intresting R options related to correlation
##Example #4
cor(cars.data[,2:8],use = "complete.obs")
cor(cars.data[,2:8],use = "complete.obs", method="spearman")
cor(cars.data[,2:8],use = "complete.obs", method="kendall")
pairs(~Disp+Disp2+Eng.Rev+Front.Hd+Frt.Leg.Room+Frt.Shld+Gear.Ratio,data=cars.data, 
      main="Simple Scatterplot Matrix")


##Kendel's tau (from the web)
KendallExample <- function(n=20){
  X <- sample(n,n)
  Y <- sample(n,n)
  plot(X,Y, las=1,xlim=c(0,n+4),ylim=c(0,n+4))
  A <- matrix(0,n,n)
  for (i in 1:n) for (j in (1:n)[-i]) if ( ((Y[j]-Y[i])/(X[j]-X[i]))>0) A[i,j] <-    1
  for (i in 1:n) for (j in (1:n)[-i]) if ( ((Y[j]-Y[i])/(X[j]-X[i]))<0) A[i,j] <-   -1
  
  
  for (i in 1:n) for (j in (1:n)[-i]){
    if (A[i,j]== 1){col= 2;   lty=1}
    if (A[i,j]==-1){col= 4; lty=3}
    if (A[i,j] != 0) lines(c(X[i],X[j]),c(Y[i],Y[j]),col=col,lty=lty)
  }
  
  up <- (sum(A>0)/2)
  down <- (sum(A<0)/2)
  tau <- 2*(up-down)/(n*n-n)
  
  text(n-4,n+4,  paste(expression(Upward), up ))
  text(n-4,n+3,paste(expression(Downward), down ))
  text(n-4,n+1, expression( frac( 2*(up-down), n^2-n )) )
  text(n-2,n+1, adj=c(0,0.5), paste(rawToChar(as.raw(61)),round(tau,digits=3)) )
}

KendallExample(n=8)
##mutual informaion
mutinformation(cars.data$Country, cars.data$Type)

##Basic measures
##skewness + kurtosis - example #5
a <- rnorm(n=100000, m=3, sd=1)
hist(a)
b <- rchisq(n=100,df=2, ncp=1)
hist(b)
skewness(a)
skewness(b)
kurtosis(a)
kurtosis(b)

##qq plot - example #5
a <- rnorm(n=1000, mean = 4, sd=1) 
b <- rnorm(n=1000, mean=3, sd=1) 
##b <- rchisq(n=1000, df=2, ncp=0.1) 
qqplot(a,b, xlab="First variable", ylab = "Second variable",main = expression("Q-Q plot of two variables"),
       xlim=c(-5, 15), ylim=c(-5, 15))
abline(0,1,col = "red", lwd=3)

##kalmagornov smirnof test - example #6
a <- rnorm(n=1000, m=3, sd=1) 
b <- rnorm(n=1000, m=3.2, sd=1)

ecdf.a <- ecdf(a)
ecdf.b <- ecdf(b)

plot( ecdf.a, verticals=TRUE, col="black", lwd=2)
lines(ecdf.b, verticals=TRUE, col="red", lwd=2)
legend("topleft", legend = c("First CDF","Second CDF"),
       col = c("black","red"), pch=c(NA,NA), lty = c(1, 1),
       lwd=c(3,3),bty="n", pt.cex=2)

(ks.results <- ks.test(x=a, y=b))



##missing data - example #7
adult.data <- read.csv(adult_data_file, header=F)
colnames(adult.data) <- c(
'age',
'workclass',
'fnlwgt',
'education',
'education-num',
'marital-status',
'occupation',
'relationship',
'race',
'sex',
'capital-gain',
'capital-loss',
'hours-per-week',
'native-country',
'income')

adult.data <- adult.data[,-which(names(adult.data)=='education-num')]
summary(adult.data)
table(adult.data[,4], adult.data[,14])
idiots <- which(adult.data$education %in% c(' Some-college', ' HS-grad'))
amount.to.convert <- round(0.8*length(idiots))
adult.data$income[idiots[1:amount.to.convert]] <- ' <=50K'
table(adult.data[,4], adult.data[,14])
form <- 'income ~.'
rpart.model <- rpart(formula=form, adult.data)
rpart.model$cptable

##now, we'll remove many rows
amount.to.delete <- 0.75*length(idiots)
adult.data[idiots[sample(length(idiots), amount.to.delete, replace=FALSE)], 'education'] <- NA
summary(adult.data)
form <- 'income ~.'
rpart.model <- rpart(formula=form, adult.data[,-which(names(adult.data)=='education')])
rpart.model$cptable


##now the solution
##first one - filling the NULL values with the mode
summary(adult.data$education)
adult.data[which(is.na(adult.data$education)==TRUE),'education'] <- ' Bachelors'
form <- 'income ~.'
rpart.model <- rpart(formula=form, adult.data)
rpart.model$cptable

##last solution - create a varialbe
missing.education.data <- is.na(adult.data$education)
adult.data <- cbind(missing.education.data, adult.data)
table(missing.education.data, adult.data$income)
form <- 'income ~.'
rpart.model <- rpart(formula=form, adult.data)
rpart.model$cptable


##outliers analysis - example #8
##this is the data we have
x <- c(0.1, 0.25, 0.3, 1.5, 2.2, 3.4, 3.9, 5.1, 6.8, 6.9, 10.1,10.5,10.9, 12.7,15.0, 40.4)
y <- c(0.2, 0.56, 0.6, 3.2, 28.1, 6.9, 7.6, 10.4, 1.1, 14.1, 22.1,21.2,21.6, 25.4, 30.3, 80.7)

plot(x,y)
##basic model, without taking outliers out
lm.model <- lm(formula=y~x, data=as.data.frame(cbind(x,y)))
summary(lm.model)

##now, let's move 1-dim outliers
mean(x)
sd(x)
mean(x)+3*sd(x)
mean(x)-3*sd(x)

mean(y)
sd(y)
mean(y)+3*sd(y)
mean(y)-3*sd(y)
##we'll move the last observation
x <- c(0.1, 0.25, 0.3, 1.5, 2.2, 3.4, 3.9, 5.1, 6.8, 6.9, 10.1,10.5,10.9, 12.7,15.0)
y <- c(0.2, 0.56, 0.6, 3.2, 28.1, 6.9, 7.6, 10.4, 1.1, 14.1, 22.1,21.2,21.6, 25.4, 30.3)
lm.model <- lm(formula=y~x, data=as.data.frame(cbind(x,y)))
summary(lm.model)

##now, what about 2-dim outliers??
x <- c(0.1, 0.25, 0.3, 1.5, 2.2, 3.4, 3.9, 5.1, 6.8, 6.9, 10.1,10.5,10.9, 12.7,15.0, 40.4)
y <- c(0.2, 0.56, 0.6, 3.2, 28.1, 6.9, 7.6, 10.4, 1.1, 14.1, 22.1,21.2,21.6, 25.4, 30.3, 80.7)
plot((cbind(x,y)))
x <- x[-c(5,9)]
y <- y[-c(5,9)]
lm.model <- lm(formula=y~x, data=as.data.frame(cbind(x,y)))
summary(lm.model)


##outliers detection
library("outliers");
set.seed(1234)
x  <-  rnorm(1000, mean = 1, sd = 0.1);
boxplot(x);
grubbs.test(x)

y  <-  rnorm(1000, mean = 1, sd = 1);
boxplot(y);
grubbs.test(y)


##transformation example - example #9
##first, building a lm model
attach(mcycle)
mcycle.lm<-lm(accel~times, data=mcycle)
plot(mcycle$times, mcycle$accel, col="orange", cex=0.8, pch=20)
abline(a=mcycle.lm$coefficients[1], b=mcycle.lm$coefficients[2])

##now, building a rpart model
mcycle.tree<-rpart(accel~times, data=mcycle,method="anova")
plot(mcycle.tree)
text(mcycle.tree)

t <- seq(2,58,len=1000)
D <- data.frame(times=t)
lines(D$times, predict(mcycle.tree, newdata=D))
##now, with transformations
fit3<-lm(accel~times+I(times^2)+I(times^3))
fit5<-lm(accel~times+I(times^2)+I(times^3)+I(times^4)+I(times^5))
fit7<-lm(accel~times+I(times^2)+I(times^3)+I(times^4)+I(times^5)+I(times^6)+
             + I(times^7))
plot(times, accel, cex=0.8, pch=20, col="orange")
lines(times, fit3$fitted, col=1)
lines(times, fit5$fitted, col=2)
lines(times, fit7$fitted, col=3)
legend(40, -70, c("fit3", "fit5", "fit7"), lty=1, col=1:3)

######################################################################## PRACTICAL PART ########################
#################################################################################################################
##Create data for the Taglit project
##first - this is the data we have
adult.data <- read.csv(adult_data_file, header=F)
colnames(adult.data) <- c(
  'age',
  'workclass',
  'fnlwgt',
  'education',
  'education-num',
  'marital-status',
  'occupation',
  'relationship',
  'race',
  'sex',
  'capital-gain',
  'capital-loss',
  'hours-per-week',
  'native-country',
  'income');

##adult.data <- adult.data[,-which(names(adult.data)=='education-num')]
summary(adult.data)

##basic model performance
form <- 'income ~education'
rpart.model <- rpart(formula=form, adult.data)
rpart.model$cptable

##now we'll create 3 new features
socioeconomic.measure <- ((adult.data$income==levels(adult.data$income)[2])+1)*2.5;
socioeconomic.measure <- socioeconomic.measure * abs(rnorm(length(socioeconomic.measure),5,3));
socioeconomic.measure[which(socioeconomic.measure>50)] <- 999;

mortage <- adult.data$income==levels(adult.data$income)[2];
mortage[which(mortage==TRUE)[1:5543]] <- NA;
mortage[which(mortage==FALSE)[1:1232]] <- NA;
mortage[which(mortage==FALSE)[1200:1350]] <- TRUE;
mortage[which(mortage==FALSE)[1500:1667]] <- FALSE;
summary(mortage);

estimated.IQ.high <- rnorm(table(adult.data$income==levels(adult.data$income)[2])[2], 105, 10);
estimated.IQ.low <- rnorm(table(adult.data$income==levels(adult.data$income)[2])[1], 90, 10);
estimated.IQ <- adult.data$income==levels(adult.data$income)[2];
estimated.IQ[which(estimated.IQ==TRUE)] <- estimated.IQ.high;
estimated.IQ[which(estimated.IQ==FALSE)] <- estimated.IQ.low;
hist(estimated.IQ);
negative.places <- sample(length(estimated.IQ), size = length(estimated.IQ)/10, replace = FALSE);
estimated.IQ[negative.places] <- -estimated.IQ[negative.places]*12;

adult.data <- cbind(adult.data[,-15], 
                    socioeconomic.measure = socioeconomic.measure, 
                    mortage = mortage,
                    estimated.IQ = estimated.IQ,
                    income = adult.data[,15]);
write.csv(adult.data, "data_for_dataPrep_session_2016.csv")
