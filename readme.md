This was my solution to the Advent of Code Day1 Challenge 2019
The input.txt file is the input data provided by the challenge
Day1.c uses the fgets function to read the file and get the data. It is then converted to integers using the atoi function.
In an attempt to imporve performance I changed this to use fscanf in the Day1_fscanf.c program. The performance of this program was
actually worse than using fgets. There was some variation between runs, but both consistently ran in approximately .00007-.00008 seconds.
