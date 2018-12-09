#Zhao Li, 1478184

import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.ensemble import RandomForestClassifier
from sklearn import svm
from sklearn.neural_network import MLPClassifier
from sklearn.model_selection import cross_val_score
from sklearn.preprocessing import MinMaxScaler

#read csv
sbdf=pd.read_csv("spambase_csv.csv")
X=sbdf.loc[:, :'capital_run_length_total'].astype(float)
y=sbdf['class']
mms=MinMaxScaler()
X=mms.fit_transform(X)

#neural network
print("===neural network===")
mpl=MLPClassifier(activation='relu', solver='adam', alpha=.0001)
#mpl=MLPClassifier(solver='lbfgs')
scores=cross_val_score(mpl, X, y, cv=10)
print(scores)
print("Mean: {}".format(scores.mean()))

#svm
print("===svm===")
svm=svm.SVC(kernel='rbf', degree=7, gamma='scale') #auto/scale, degree only in poly kernel
#svm=svm.SVC()
scores=cross_val_score(svm, X, y, cv=10)
print(scores)
print("Mean: {}".format(scores.mean()))

#random forest
print("===random forest===")
rdf=RandomForestClassifier(n_estimators=1000, criterion='gini', max_depth=None)
#rdf=RandomForestClassifier(n_estimators=10)
scores=cross_val_score(rdf, X, y, cv=10)
print(scores)
print("Mean: {}".format(scores.mean()))

#decision tree
print("===decision tree===")
dtc=DecisionTreeClassifier(criterion="entropy", splitter="best", max_depth=8)
#dtc=DecisionTreeClassifier()
scores=cross_val_score(dtc, X, y, cv=10)
print(scores)
print("Mean: {}".format(scores.mean()))
