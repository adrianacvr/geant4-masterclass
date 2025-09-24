# Geant4 Masterclass: From ROOT to Python
> Author: Adriana Vásquez Ramírez adrianacvr67@gmail.com

Here you have an example of how you can use `uproot` in Python to open your root files and convert the histograms in arrays. 

## Create a new notebook and plot your data in Python
            
            import numpy as np
            import uproot
            import pandas as pd
            import matplotlib.pyplot as plt
            
            rootname = 'name.root' #name of your file
            
            #####Import histograms 
            file = uproot.open(rootname)
            histname = "histo_name" #Check the name of the histogram you want to convert to arrays

            #array in x
            xval = file[histname].axis().edges() #x values from the histogram
            xval = xval[:-1] #to remove the last extra x value so x and y have the same length

            #array in y
            yval = file[histname].values() #y values from the histogram

            #array with the error of y
            y_err = file[histname].errors() #y error values from the histogram
            
            # Create scatter plot with error bars
            plt.errorbar(xval, yval, yerr=y_err, fmt='o', capsize=5, label="label")

            # Labels and title
            plt.xlabel("X values")
            plt.ylabel("Y values")
            plt.title("Title")
            plt.legend()
            plt.show()
## Now you can use `xval`, `yval` and `y_err` for your data analysis in Python. 
## You can open and convert as many histograms you want changing the "histo_name". 
