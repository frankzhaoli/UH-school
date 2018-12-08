#Zhao Li, 1478184

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
import sklearn.cluster as cluster
import time
import csv
import math
import statsmodels.formula.api as sm
#from skimage.util import unique
from scipy.spatial import distance_matrix
from scipy.stats.stats import zscore
from scipy import stats
from sklearn.cluster import KMeans
from sklearn.cluster.tests.test_affinity_propagation import n_clusters
from sklearn.cluster import DBSCAN
from sklearn.preprocessing.data import StandardScaler
from sklearn.svm import SVR

wwq=pd.read_csv('winequality-white.csv')
wwq["class"]=-1
wwq.loc[(wwq['quality'] == 10) | (wwq['quality'] == 9) | (wwq['quality'] == 8), "class"] = "A"
wwq.loc[(wwq['quality'] == 7) , "class"] = "B"
wwq.loc[(wwq['quality'] == 6) , "class"] = "C"
wwq.loc[(wwq['quality'] == 5) , "class"] = "D"
wwq.loc[(wwq['quality'] == 4) | (wwq['quality'] == 3) | (wwq['quality'] == 2) | (wwq['quality'] == 1) | (wwq['quality'] == 0), "class"] = "E"

#1
A="A"
B="B"
C="C"
D="D"
E="E"

#case 1
a=(0,1,1,1,1,2,2,3)
b=(A,A,A,E,E,D,D,C)
c=(8,8,8,4,4,5,5,6)
#case 2
a=(1,1,1,0,0,2,2,2)
b=(A,A,A,E,E,D,D,C)

def entropy(a, b):
    a=list(a)
    b=list(b)
    #remove outliers
    ind=[i for i in range(len(a)) if a[i]>0]
    a=[a[i] for i in ind]
    b=[b[i] for i in ind]
    
    uniquea, countsa=np.unique(a, return_counts=True)
    entsum=0
    
    for ele in countsa:
        templist=[]
        ratio=ele/sum(countsa)
        
        for i in range(0, ele):
            templist.append(b[i])
            
        b=b[ele:]
        uniquelist, listcount=np.unique(templist, return_counts=True)
        tempsum=0
        
        for i in listcount:
            r=i/sum(listcount)
            l=(-1*r)*math.log(r, 2)
            tempsum=tempsum+l
            
        entsum=entsum+(ratio*tempsum)
    return entsum
    
#ent=entropy(a, b)
#print("Entropy:", ent)

#2
def ordinal_variation(a,b):
    a=list(a)
    b=list(b)
    #remove outliers
    ind=[i for i in range(len(a)) if a[i]>0]
    a=[a[i] for i in ind]
    b=[b[i] for i in ind]
    c=[]
    
    for i in b:
        if i == "A":
            c.append(4)
        elif i=="B":
            c.append(3)
        elif i=="C":
            c.append(2)
        elif i=="D":
            c.append(1)
        elif i=="E":
            c.append(0)
            
    uniquea, acount=np.unique(a, return_counts=True)
    ordvar=0
    
    for ele in acount:
        templist=[]
        ratio=ele/sum(acount)
        #print(ele)
        #ordinal variance
        d=c[0:ele]
        c=c[ele:len(c)]
        #print(d)
        summ=0
        
        for ele in d:
            for ele2 in d:
                if ele!=ele2:
                    try:
                        summ+=abs(ele-ele2)/(math.pow(abs(ele), 2)-abs(ele))
                    except Exception as e:
                        summ+=0
        #print(summ, ratio)
        ordvar+=(summ*ratio)
    return ordvar;

#ov=ordinal_variation(a, b)
#print("Ordinal Variation:",ov)

#3
def variance(a,b):
    a=list(a)
    b=list(b)
    #remove outliers
    ind=[i for i in range(len(a)) if a[i]>0]
    a=[a[i] for i in ind]
    b=[b[i] for i in ind]
    
    uniquea, acount=np.unique(a, return_counts=True)
    varsum=0
    
    for ele in acount:
        templist=[]
        ratio=ele/sum(acount)
        
        for i in range(0, ele):
            templist.append(b[i])
               
        b=b[ele:]
        #print(ratio, templist)
        v=ratio*np.var(templist)
        varsum=varsum+v
    return varsum

#v=variance(a, c)
#print("Variance:",v)

#4
inp=[[1, 5], [2, 6], [3, 7], [4, 8]]
df=pd.DataFrame(inp)

def mdist(d):
    d=d.apply(zscore)
    dismat=pd.DataFrame(distance_matrix(d.values, d.values), index=d.index, columns=d.index)
    return dismat

#dismat=mdist(df)
#print(dismat)

#5
'''
c9=pd.read_csv("Complex9_RN32.csv")
f1=c9["X"].values
f2=c9["Y"].values

X=np.array(list(zip(f1, f2)))
kmeans=KMeans(n_clusters=9).fit(X)
#kmeans=KMeans(n_clusters=18).fit(X)
y=kmeans.predict(X)
#plt.scatter(f1, f2, c='black', s=5)
plt.scatter(X[:, 0], X[:, 1], c=y, s=10)
plt.show()

#ent=entropy(f1, f2)
#print("Entropy:",ent)
'''

#6
'''
wwqc=wwq.loc[:, "fixed.acidity": "quality"]
X=stats.zscore(wwqc)
kmeans=KMeans(n_clusters=5, random_state=4335, n_init=15).fit(X)
#kmeans=KMeans(n_clusters=10, random_state=4335, n_init=15).fit(X)
labels=kmeans.labels_
wwq["clusters"]=labels
print(wwq.groupby(['clusters']).mean())
'''

'''
wwq2=wwq.loc[:, "fixed.acidity":"alcohol"]
dismat=mdist(wwq2)
print(dismat)
'''

'''
#SSE, Entropy, Ordinal, Variance
a=wwq["quality"]
b=wwq["class"]
c=wwq["clusters"]
ent=entropy(c, b)
oa=ordinal_variation(c, b)
v=variance(a, c)
print("Entropy:", ent)
print("Ordinal Agreement:", oa)
print("Variance:", v)
'''

#7
c9=pd.read_csv("Complex9_RN32.csv")
f1=c9["X"].values
f2=c9["Y"].values

X=np.array(list(zip(f1, f2)))

X=StandardScaler().fit(X).transform(X)
dbs=DBSCAN(eps=5, min_samples=50).fit(X)
labels=dbs.labels_
coresamples=np.zeros_like(labels,dtype=bool)
coresamples[dbs.core_sample_indices_]=True
print(coresamples)

c9["clusters"]=labels
print(c9.groupby(["clusters"]).mean())


wwqc=wwq.loc[:, "fixed.acidity": "quality"]
X=stats.zscore(wwqc)
dbs=DBSCAN(eps=5, min_samples=50).fit(X)
labels=dbs.labels_
coresamples=np.zeros_like(labels,dtype=bool)
coresamples[dbs.core_sample_indices_]=True
print(coresamples)
wwq["clusters"]=labels
print(wwq.groupby(['clusters']).mean())

a=c9['X']
b=c9['Y']
c=c9["clusters"]
ent=entropy(a, c)
print("Entropy:", ent)

a=wwq["quality"]
b=wwq["class"]
c=wwq["clusters"]
ent=entropy(c, b)
ov=ordinal_variation(c, b)
print("Entropy:", ent)
print("Ordinal Variation:", ov)
#9
'''
#linreg=sm.ols(formula="quality ~ Q(\"fixed.acidity\") + Q(\"volatile.acidity\") + Q(\"citric.acid\") + Q(\"residual.sugar\") + chlorides + Q(\"free.sulfur.dioxide\") + Q(\"total.sulfur.dioxide\") + density + pH + sulphates + alcohol", data=wwq).fit()
#print(linreg.summary())

X=wwq.loc[:, "fixed.acidity": "quality"]
y=wwq.loc[:, "quality"]
svr=SVR(kernel='linear', C=1.0, epsilon=0.2, verbose=True)
svr.fit(X, y)
print(svr)
'''
