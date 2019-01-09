# AUC
**AUC** (Ab Urbe condita) is a command-line Roman calendar tool. Currently it shows the specified date in the format of the Ancient Romans. 

# Synopsis
auc [-d d/m/y] [-c]

# Parameters
Optional parameter -d allows to specify a date to print in the Roman format (the current date is printed by default). The only supported format for date is d/m/y, d and m could have leading zeros but it is not required. Examples: 1/1/2019, 01/01/2019.

Parameter -c allows to print year in the Christian epoch, not original Roman.
# Output details
The months' names are from the Empire ages (i.e. Quintilis called Iulius and Sextilis called Augustus). 

During the leap year the 24th of February is reckoned to last 48 hours because Romans did not add an additional day (the 29th of Feb.).

The tool makes only formatting in the Ancient Romans' style, usual Gregorian calendar is used.

# Example of output
  $ ./auc

  Non. Ian., MMDCCLXXII AUC

  $ ./auc -d 24/2/2000
  
  a.d. VI Kal. Mar., MMDCCLIII AUC

  $ ./auc -d 25/2/2000
  
  a.d. VI Kal. Mar., MMDCCLIII AUC

  $ ./auc -d 24/2/2001

  a.d. VI Kal. Mar., MMDCCLIV AUC

  $ ./auc -d 25/2/2001
  
  a.d. V Kal. Mar., MMDCCLIV AUC

  $ ./auc -d 1/1/2019 -c

  Kal. Ian., MMXIX p. Chr. n

