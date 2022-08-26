`import numpy as np`

`import uproot`

`import pandas as pd`

`rootname = 'name.root'`

#####Import histograms 

            file = uproot.open(rootname)
            
            histname = "histo_name"
            
            xval = file[histname].axis().edges() #x values from the histogram
            
            xval = xval[:-1] #to remove the last extra x value
            
            yval = file[histname].values() #y values from the histogram
            
            y_err = file[histname].errors() #y error values from the histogram
            
            
            pulse = []
            for k in range(len(xval)):
            
                npulse = [xval[k], yval[k], y_err[k]]
                
                pulse.append(npulse)
        
        
            arraytest = np.array(pulse)
            
            pulse_c = arraytest[np.all(arraytest != 0.0, axis=1)] #to get non zero values
            
            pulsex = pulse_c[:,0] #x values 
            
            pulsey = pulse_c[:,1] #y values 
            
            errory = pulse_c[:,2] #y error values 
            
