#Zhao Li, 1478184

import pandas as pd
import numpy as np
#import matplotlib
#matplotlib.use('Agg')
#import matplotlib.pylab as pylab
#import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
#import statsmodels.formula.api as sm
#import sklearn.datasets as ds

'''
from sklearn.externals.six import StringIO
from IPython.display import Image
from sklearn.tree import export_graphviz
import pydotplus
from sklearn.tree import DecisionTreeClassifier
'''

#read in both csvs
diadf=pd.read_csv('diabetes.csv')
cleandf=pd.read_csv('diabetes_cleaned.csv')
#print(diadf)
#0 computing mean/sd, remove 0's if necessary
#print(diadf.BloodPressure.mean())
gluc=diadf[diadf['Glucose']!=0]
bp=diadf[diadf['BloodPressure']!=0]
st=diadf[diadf['SkinThickness']!=0]
insul=diadf[diadf['Insulin']!=0]
bmi=diadf[diadf['BMI']!=0]

'''
print('1. Means:')
print('Glucose:', gluc.Glucose.mean())
print('Blood Pressure:', bp.BloodPressure.mean())
print('Skin Thickness:', st.SkinThickness.mean())
print('Insulin:', insul.Insulin.mean())
print('BMI:', bmi.BMI.mean(), '\n')

print('Standard Deviations: ')
print('Glucose:', gluc.Glucose.std())
print('Blood Pressure:', bp.BloodPressure.std())
print('Skin Thickness:', st.SkinThickness.std())
print('Insulin:', insul.Insulin.std())
print('BMI:', bmi.BMI.std(), '\n')
'''
'''
#1 covariance matrix and correlation
print('2. Covariance matrix:')
df=diadf[['Glucose', 'BloodPressure', 'SkinThickness', 'Insulin', 'BMI']]
df=df.replace(0, np.nan)
print(df.cov().to_string(), '\n')

print('Correlations: ')
print('Glucose, Blood Pressure:', df['Glucose'].corr(df['BloodPressure']))
print('Glucose, Skin Thickness:', df['Glucose'].corr(df['SkinThickness']))
print('Glucose, Insulin:', df['Glucose'].corr(df['Insulin']))
print('Glucose, BMI:', df['Glucose'].corr(df['BMI']))
print('Blood Pressure, Skin Thickness:', df['BloodPressure'].corr(df['SkinThickness']))
print('Blood Pressure, Insulin:', df['BloodPressure'].corr(df['Insulin']))
print('Blood Pressure, BMI:', df['BloodPressure'].corr(df['BMI']))
print('Skin Thickness, Insulin:', df['SkinThickness'].corr(df['Insulin']))
print('Skin Thickness, BMI:', df['SkinThickness'].corr(df['BMI']))
print('Insulin, BMI:', df['Insulin'].corr(df['BMI']))
'''
#2 scatter plot for attributes 3 and 6
#and attributes 2 and 7
'''
plt.scatter(diadf.BloodPressure, diadf.BMI)
plt.show()

plt.scatter(diadf.Glucose, diadf.DiabetesPedigreeFunction)
plt.show()
'''

#3 histograms of 2, 3, 6

#0 instances
df1=diadf[diadf['Outcome']==0]
#1 instances
df2=diadf[diadf['Outcome']==1]

#regular histograms
#plt.hist(diadf.Glucose)
#plt.hist(diadf.BloodPressure)
#plt.hist(diadf.BMI)
#plt.show()

#0 histogram
#plt.hist(df1.Glucose)
#plt.hist(df1.BloodPressure)
#plt.hist(df1.BMI)
#plt.show()

#1 histogram
#plt.hist(df2.Glucose)
#plt.hist(df2.BloodPressure)
#plt.hist(df2.BMI)
#plt.show()


#4 boxplots of 2, 7, 8, whole
#plt.boxplot(gluc.Glucose)
#plt.boxplot(diadf.DiabetesPedigreeFunction)
#plt.boxplot(diadf.Age)

#0 outcome
#plt.boxplot(df1.Glucose)
#plt.boxplot(df1.DiabetesPedigreeFunction)
#plt.boxplot(df1.Age)

#1 outcome
#plt.boxplot(df2.Glucose)
#plt.boxplot(df2.DiabetesPedigreeFunction)
#plt.boxplot(df2.Age)
#plt.show()

#5 
#2D scatterplots
cldf=diadf.replace(0, np.nan)
#plt.scatter(cldf.Glucose, cldf.BloodPressure)
#plt.scatter(cldf.Glucose, cldf.SkinThickness)

#plt.scatter(cldf.Glucose, cldf.Insulin)
#plt.scatter(cldf.Glucose, cldf.BMI)
#plt.scatter(cldf.BloodPressure, cldf.SkinThickness)
#plt.scatter(cldf.BloodPressure, cldf.Insulin)
#plt.scatter(cldf.BloodPressure, cldf.BMI)
#plt.scatter(cldf.SkinThickness, cldf.Insulin)
#plt.scatter(cldf.SkinThickness, cldf.BMI)
#plt.scatter(cldf.Insulin, cldf.BMI)

#plt.show()
#3D scatterplots
#fig=plt.figure()
#ax=Axes3D(fig)
#ax.scatter(cldf.Glucose, cldf.BloodPressure, cldf.BMI)
#ax.scatter(cldf.Glucose, cldf.SkinThickness, cldf.BMI)
#plt.show()

#6
cleandf.columns=['Pregnancies', 'Glucose', 'BloodPressure', 'SkinThickness', 'Insulin', 'BMI', 'DiabetesPedigreeFunction', 'Age', 'Outcome']



#7
'''
linreg=sm.ols(formula='Outcome ~ Pregnancies + Glucose + BloodPressure + SkinThickness + Insulin + BMI + DiabetesPedigreeFunction + Age', data=cleandf).fit()
print(linreg.summary())
print('\n')
linreg2=sm.ols(formula='Outcome ~ Pregnancies + Glucose + BloodPressure + BMI + DiabetesPedigreeFunction + Age', data=cleandf).fit()
print(linreg2.summary())
'''
#8
#rowdf=cleandf.head(20)
y=cleandf.Outcome
x=cleandf
#tree=DecisionTreeClassifier(criterion='entropy')
#tree=DecisionTreeClassifier(criterion='gini')
#tree.fit(x, y)
#dot=StringIO()
#export_graphviz(tree, out_file=dot, max_depth=20, filled=True, rounded=True, special_characters=True)
#graph=pydotplus.graph_from_dot_data(dot.getvalue())
#Image(graph.create_png())
#print(tree)