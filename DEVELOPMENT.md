# **DEVELOPMENT PROGRESS**

1. I intially tried using OpenCV's Principal Component Analysis library to calculate the linear aggression, but unfortunately it didn't work as it uses vectors and is used more for complex image-based regressions.
2. Then I looked into shark library and tested it to see how it works on Xcode.
3. I also studied how to calculate regression myself and found and understood code that doesn't use any library to calculate the regression.
4. I also found the data set that I would be using for my project.

5. I came across some issues while trying to get shark to work - the file location in XCode for the shark file is not being able to be located so I had to change it manually in every hpp file the library contains. It is taking me too long, plus I do not have permission to write to a shark file, so I also need to manually change the accessibility for each file and folder. This is to tedious a process so I plan to change the library I intend on using for my project.
6. I found a list of numerical libraries I can use from this link - https://en.wikipedia.org/wiki/List_of_numerical_libraries. Many of these libraries can help me calculate linear regression. Currently I am looking into ALGLIB, which is an open source / commercial numerical analysis library. If ALGLIB doesn't work, I plan on trying out Armadillo or Dlib, both are included in the the list mentioned above.
