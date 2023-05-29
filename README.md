# CS 2341 (Data Structures)
## Project 1: Sentiment Analyzer

This repository holds a sentiment analyzer project, the first project given in the Data
Structures class of Fall 2020 at SMU. I redid the project, still limited by the original rules and constraints
when the project was first assigned. 

Given several files, the program runs in three phases:
<br><br>
**Training phase**:
Given a dataset of tweets, the program makes a word classifier, in which words
are given some positive or negative value
<br><br>
**Testing phase**:
After creating a word classifier, and given a new dataset of tweets, the program
predicts whether a tweet is positive or negative using the word classifier
and the associated positive or negative value associated with the words in the tweet
<br><br>
**Accuracy phase**:
After creating predictions for the testing dataset, the program reads in the answer key
files for the test dataset and compares its predictions with the correct answers. It prints out its accuracy
and the IDs of the tweets it predicted wrong to an output file.

## Files
data(folder):
- output.txt: a text file where the program outputs its accuracy and the IDs of tweets it predicted wrong
- test_dataset_10k.csv: a csv file that holds 10,000 tweets to be used in the testing phase
- test_dataset_sentiment.csv: a csv file that holds the actual sentiment of the tweet and the tweet ID
- train_dataset_20k.csv: a csv file that holds 20,000 tweets to be used in the training phase
<br>

src(folder):
<br>
- DSString.cpp/DSString.h: a .cpp and .h file used to implement a custom string class
- Sentiment_Analyzer.cpp/Sentiment_Analyzer.h: a .cpp and .h file used to implement the program and the different phases
- Tweet.cpp/Tweet.h: a .cpp and .h file used to house and manipulate tweets
- main.cpp: a .cpp file used to house the entire program

src/test(folder):
<br>
- catch.hpp: file used for implemented CATCH2 tests
- testDSString.cpp: .cpp file used to run unit tests on the DSString class
<br>

## Highest Accuracy Achieved
The highest accuracy this program has achieved is **0.696**, or **69.6**%