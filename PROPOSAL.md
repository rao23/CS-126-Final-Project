# **REGRESSION BASED SOCCER MATCH PREDICTOR**


## *INTRODUCTION:*
Soccer is played by 250 million players in over 200 countries, making it the world's most popular sport. No one knows exactly when soccer was created, but the earliest versions of the game can be traced back 3,000 years. The game is played on a rectangular field called a pitch with a goal at each end. The objective of the game is to score by moving the ball beyond the goal line into the opposing goal. Soccer is governed internationally by the International Federation of Association Football (FIFA), which organises World Cups for both men and women every four years.

## *GOAL:*
This project performs a machine learning algorthim to predict the outcome of a soccer match. 

## *DATA:*
I will be making use of the data from kaggle - https://www.kaggle.com/hugomathien/soccer
This data from kaggle is sourced from 3 websites -
    1. http://football-data.mx-api.enetscores.com/: this website contains data pertaining to the scores, lineups, team formations and events of each team.
    2. http://www.football-data.co.uk/ : this website contains data pertaining to the betting odds for a match between two teams. 
    3. http://sofifa.com/ : this website contains data pertaining to players and team attributes sourced from EA Sports FIFA games.

## *LIBRARY:*
I will be making use of a library to form a linear regression graph whose line of best fit will help me predict the outcome of the match.
As of now, I have been looking into **shark** as the library to use for this purpose. I may change this later.

## *ADDONS:*
I may add data from another website to take into account international team and internatinal club and country competiton statistics as the current data only provides club-level data and domestic competition statistics.

## *PROCESS:* 
1. Firstly, I will read the data from the soccer data set library that I will be making use of as I mentioned above.
2. Then, I will divide the obtained data into three parts to be used for regression. The first part will hold the player attributes for each team. The second part will hold the overall team attributes. The third part will combine the data of odds, team formations, scores, etc.
3. I will then perform regression on each of these divided data set parts to obtain a line of best fit. The divided data sets of the teams will be compared to eachother to form the line of best fit.
4. Finally, the three lines of best fits will be combined (maybe by taking the average or by assigning a weightage system - I have't yet decided this) to give a final line which clearly reveals the prediction to be given.
5. The prediction will be given in this format - the team which wins and the score by which the teams is expected to win.
