import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn import metrics
import numpy as np
#from sklearn.externals import joblib
import joblib

##Step1: Load Dataset

dataframe = pd.read_csv("csv/dataset.csv")
#print(dataframe.head())

#Step2: Split into training and test data
x = dataframe.drop(["Label"],axis=1)
y = dataframe["Label"]
x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.2,random_state=42)

##Step3: Build a model

#train the model for one time only ,and save it.

#model = RandomForestClassifier(n_estimators=100,max_depth=5)
#model.fit(x_train,y_train)
#joblib.dump(model,"Model/rf_malaria_100_5")

# Load the model later whenever you want to use it,
model=joblib.load("Model/rf_malaria_100_5")

##Step4: Make predictions and get classification report

#you can make predictions on a supplied data as:
#a= np.array([[123.0,145.0,23.45,0,0],[7000,0,0,0,0]])
#predictions = model.predict(a)
#print(predictions)

predictions = model.predict(x_test)
print(metrics.classification_report(y_test,predictions))
print(model.score(x_test,y_test))





