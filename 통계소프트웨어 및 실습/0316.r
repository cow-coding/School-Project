
R version 3.6.3 (2020-02-29) -- "Holding the Windsock"
Copyright (C) 2020 The R Foundation for Statistical Computing
Platform: x86_64-apple-darwin15.6.0 (64-bit)

R is free software and comes with ABSOLUTELY NO WARRANTY.
You are welcome to redistribute it under certain conditions.
Type 'license()' or 'licence()' for distribution details.

  Natural language support but running in an English locale

R is a collaborative project with many contributors.
Type 'contributors()' for more information and
'citation()' on how to cite R or R packages in publications.

Type 'demo()' for some demos, 'help()' for on-line help, or
'help.start()' for an HTML browser interface to help.
Type 'q()' to quit R.

[R.app GUI 1.70 (7735) x86_64-apple-darwin15.6.0]

[Workspace restored from /Users/kibeompark/.RData]
[History restored from /Users/kibeompark/.Rapp.history]

> install.packages("caTools")
trying URL 'https://cran.seoul.go.kr/bin/macosx/el-capitan/contrib/3.6/caTools_1.18.0.tgz'
Content type 'application/x-gzip' length 245973 bytes (240 KB)
==================================================
downloaded 240 KB


The downloaded binary packages are in
	/var/folders/yf/_6blm_zx5tdg4mrfg5hrgwdm0000gn/T//RtmpTBkEaz/downloaded_packages
> library(caTools)
> search()
 [1] ".GlobalEnv"        "package:caTools"   "tools:RGUI"        "package:stats"    
 [5] "package:graphics"  "package:grDevices" "package:utils"     "package:datasets" 
 [9] "package:methods"   "Autoloads"         "package:base"     
> install.packages("dplyr")
trying URL 'https://cran.seoul.go.kr/bin/macosx/el-capitan/contrib/3.6/dplyr_0.8.5.tgz'
Content type 'application/x-gzip' length 6859111 bytes (6.5 MB)
==================================================
downloaded 6.5 MB


The downloaded binary packages are in
	/var/folders/yf/_6blm_zx5tdg4mrfg5hrgwdm0000gn/T//RtmpTBkEaz/downloaded_packages
> library(dplyr)

Attaching package: ‘dplyr’

The following objects are masked from ‘package:stats’:

    filter, lag

The following objects are masked from ‘package:base’:

    intersect, setdiff, setequal, union

> search
function () 
.Internal(search())
<bytecode: 0x7fb99f3f1a48>
<environment: namespace:base>
> search()
 [1] ".GlobalEnv"        "package:dplyr"     "package:caTools"   "tools:RGUI"       
 [5] "package:stats"     "package:graphics"  "package:grDevices" "package:utils"    
 [9] "package:datasets"  "package:methods"   "Autoloads"         "package:base"     
> 
