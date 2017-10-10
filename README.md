=
# Band Family Tree program

This is a win32 console application project from class EE273:Design of Software Development at University of Strathclyde. It has been assessed by the lecturer.


# What it dose

This program allows the user to store information about different bands and related artists whether from extracting a pre-saved database (pure text file) or from console input. It supports information mofidication&searching based on band, artist or instrument and is able to output new modified database files

*Modify stored band*

![Optional Text](../master/images/modify.png)

*Search information based on artist/band*

![Optional Text](../master/images/search.png)

*Search information based on instrument type*

![Optional Text](../master/images/search_instru.png)

# How to run program

`git clone https://github.com/Xfan1025/EE273.git`

or

Download the zip file. Using visual studio 2017 is recommended. (I developed it on both my labtop and the university's PC. The reason why the intents are not uniform is because the intention settings are different. It will display normally if load the code in Visual Studio)

After setting up the project, one change of setting needs to be done before running the program:

project **properties** -> **General** -> **Character Set** -> **Use multi-byte character set**

Then just follow the instructions of the user-menu

![Optional Text](../master/images/UI.png)


# Highlights

1. By wrapping mutilple levels of `while` , `switch` loops and `system("cls");`, this program provides a neat, user-friendly user interface regardless of the fact it is a console application.
2. With WindowsAPI integrated, it provides convenient dialog boxes when reading and saving files.


![reading database](../master/images/input.png)

*Saving out modified database as new files*

![saving out new database](../master/images/save.png)


# Note

## use bandDatabase.txt as the band database iput file

## use artistDatabase.txt as the artists database input file


# What needs to be improved

The program's database files were initially created using pure text files. It shall be improved by reformatting the database into csv files.


