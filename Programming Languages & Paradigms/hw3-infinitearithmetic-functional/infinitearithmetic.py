import sys
sys.setrecursionlimit(10000)

def carry(term1, term2, dnp):
    newTerm = term1 + term2
    if newTerm < 10**dnp:
        return 0
    else:
        return 1

def addTerms(term1, term2, dnp):
    newTerm = term1 + term2
    if newTerm < 10**dnp:
        return newTerm
    else:
        return newTerm - (10**dnp)

def addList(list1, list2, dnp):
    if len(list1) > len(list2):
        listA = list1
        listB = [0]*(len(list1) - len(list2)) + list2
    elif len(list1) < len(list2):
        listB = list2
        listA = [0]*(len(list2) - len(list1)) + list1
    else:
        listA = list1
        listB = list2
    sumList = list(map(lambda x,y: addTerms(x,y,dnp), listA, listB))
    carryList = list(map(lambda x,y: carry(x,y,dnp), listA, listB)) + [0]
    if sum(carryList) == 0:
        return sumList
    elif carryList[0] == 0:
        alignedCarry = carryList[1::]
        return addList(sumList, alignedCarry, dnp)
    else:
        return addList(sumList, carryList, dnp)

def multList(list1, list2, product, depth1, depth2, dnp): #start product as a list only containing zero: [0] depths are the length of their respective lists
    if depth1 != 0:
        #print("Depth 1:")#
        #print(depth1)#
        if depth2 != 0:
            #print("Depth 2:")
            #print(depth2)#
            prod = str(list1[depth1 - 1] * list2[depth2 - 1])
            #print(prod)#
            if prod != 0:    
                if len(prod) <= dnp:
                    subProduct = [int(prod)] + [0]*((len(list1) - depth1) + (len(list2) - depth2))
                    #print("sub product:")#
                    #print(subProduct)#
                elif len(prod) > dnp:
                    subProduct = [int(prod[0:(len(prod) - dnp)])] + [int(prod[(len(prod) - dnp):])] + [0]*((len(list1) - depth1) + (len(list2) - depth2))
                    #print("sub product:")#
                    #print(subProduct)#
                newProduct = addList(product, subProduct, dnp)
                #print("new product:")#
                #print(newProduct)#
                return multList(list1, list2, newProduct, depth1, depth2 - 1, dnp)
            else:
                return multList(list1, list2, product, depth1, depth2 - 1, dnp)
        elif depth2 == 0:
            return multList(list1, list2, product, depth1 - 1, len(list2), dnp)
    return product

def toString(List, i, string, dnp): #start i at length of list minus one
    if i != 0:
        tStr = str(List[i]) #temporary string variable
        fStr = "0"*(dnp - len(tStr)) + tStr #formatted for leading zeroes
        newString = fStr + string #add new formatted string and previous strings
        return toString(List, i-1, newString, dnp) #continue with new string
    elif i == 0:
        newString = str(List[i]) + string #add leftmost node
        return newString

def createExpStack(exp):
    expcopy=exp
    tempstack=[]
    
    if not expcopy:
        return tempstack
    
    #checking for missing numbers
    if(expcopy.find(",)")!=-1):
        return -1
    elif(expcopy.find("(,")!=-1):
        return -1
    
    expstack=expcopy.replace("(", " ").replace(")", " ").replace(",", " ").split()
    return expstack

def align(num, nodes):
    result=[]
    
    for i in range(len(num), 0, nodes*-1):
        if(len(num)<nodes):
            temp=num
        else:
            temp=num[len(num)-nodes:len(num)]
        num=num[:nodes*-1]
        result.insert(0, int(temp))
    
    return result

def processStack(exp, oldtempstack, nodes):
    copy=exp
    tempstack=oldtempstack
    
    if not copy:
        return
    
    else:
        #print("stack", stack)
        #print("tempstack", tempstack)
        
        top=copy.pop()
        
        if(top.isdigit()):
            tempstack.append(top)
        
        elif(top=="add"):
            #pop and remove leading zeros
            num1=str(int(tempstack.pop()))
            num2=str(int(tempstack.pop()))

            temp=align(num1, nodes)
            temp2=align(num2, nodes)
            
            result=addList(temp, temp2, nodes)
            strresult=toString(result, len(result) - 1, "", nodes)
            tempstack.append(int(strresult))

        elif(top=="multiply"):
            #pop and remove leading zeros
            num1=str(int(tempstack.pop()))
            num2=str(int(tempstack.pop()))
            
            temp=align(num1, nodes)
            temp2=align(num2, nodes)
            
            result=multList(temp, temp2, [0], len(temp), len(temp2), nodes)
            strresult=toString(result, len(result) - 1, "", nodes)
            tempstack.append(int(strresult))
            
        if(len(copy)==0):
            return (tempstack.pop(0))
        
        return processStack(copy, tempstack, nodes)
    
def processExpression(fileInput, nodes):
    if not fileInput:
        return False
    
    else:
        exp=fileInput.pop(0).rstrip()
        expstack=createExpStack(exp)
        
        if(expstack==-1):
            print("{} = Invalid Expression, missing operand!".format(exp))
        elif(len(expstack)!=0):
            #print(expstack)
            templist=[]
            result=processStack(expstack, templist, nodes)
            print("{} = {}".format(exp, result))
        processExpression(fileInput, nodes)

#process command line input
#"input=<file name>;digitsPerNode=<number>"

filename='test.txt'
nodes=3
'''
cmdlineinput=str(sys.argv[1:])
argu=cmdlineinput.split(';')
filename=argu[0].replace('[\'input=', '')
nodes=argu[1].replace('digitsPerNode=', '')
nodes=nodes[:-2]
nodes=int(nodes)
'''

#read file
try:
    file=open(filename, 'r')
    fileinput=file.readlines()
    processExpression(fileinput, nodes)
    file.close()
except IOError:
    print('Error: Incorrect file name!')
