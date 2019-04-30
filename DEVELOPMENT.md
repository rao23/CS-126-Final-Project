# **DEVELOPMENT PROGRESS**

## ***Code Review Week #1***

1. I intially tried using OpenCV's Principal Component Analysis library to calculate the linear aggression, but unfortunately it didn't work as it uses vectors and is used more for complex image-based regressions.
2. Then I looked into shark library and tested it to see how it works on Xcode.
3. I also studied how to calculate regression myself and found and understood code that doesn't use any library to calculate the regression.
4. I also found the data set that I would be using for my project.

## ***Code Review Week #2***
5. I came across some issues while trying to get shark to work - the file location in XCode for the shark file is not being able to be located so I had to change it manually in every hpp file the library contains. It is taking me too long, plus I do not have permission to write to a shark file, so I also need to manually change the accessibility for each file and folder. This is to tedious a process so I plan to change the library I intend on using for my project.
6. I found a list of numerical libraries I can use from this link - https://en.wikipedia.org/wiki/List_of_numerical_libraries. Many of these libraries can help me calculate linear regression. Currently I am looking into ALGLIB, which is an open source / commercial numerical analysis library. If ALGLIB doesn't work, I plan on trying out Armadillo or Dlib, both are included in the the list mentioned above.

## ***Code Review Week #3***
7. Encountered a linker command error while using library. Rectified it by adding all the library's files to my code and including the .h files of the files I needed to use.
8. The library I am using has a read_csv() method which reads the data of a csv file into a 2d array. Unfortunately right now when I am trying to read my data using this method I am getting caught in the error that all rows and columns are not of the same size. Still trying to find a solution to this problem.
9. The reason I found the above error is because this method was reading all the data into a 2d vector of doubles instead of strings. I have to create my own helper method to read the data into 2d vector of strings.
10. Created my own CSVDataReader class to read the data into a 2d vector of strings with the help of the boost library.
11. Began creating my training model.
12. I changed my idea of using multi-variable linear regression to calculate the probabilities as it was very tedious to go through with it and the predicitions do not turn out to be very accurate.
13. I decided to use Poisson distribution to calculate the probabilities instead as it is more simple to use it and it also gives a more accurate prediction.

## ***Code Review Final Week***
14. Started working on the trainer methods. Initially, while calculating the league averages, the values kept getting added up as I called the tuple function.
15. Managed to finish my trainer methods. Rectified the league avergages issue by resetting some important variables during the function call.
16. Managed to complete calculating the poisson distribution very easily with the help of boost library in my Predictor methods.
17. Also, completed printing the statistics of the selected match data.
18. Now, I have started working on ofxDatGui to present my project in a better way.
19. I got the two drop down menus to work to print out the league and team names.
20. Added a "Calculate" button which basically acts as an enter button and starts calculating the data with the given teams.
21. I intially had issues presenting my data as using labels to print out my matrix was not ideal. I then added ofTrueTypeFont which helps me print to the display window instead of the console.




