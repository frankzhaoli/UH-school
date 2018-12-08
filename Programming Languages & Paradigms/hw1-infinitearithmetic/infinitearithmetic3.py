
import sys
sys.setrecursionlimit(10000)

class Node:
    val = 0
    
    def __init__(self, newVal):
        self.val = newVal
        self.next = None

class List:
    head = None

def addNode(thisList, node, val):
    if thisList.head == None:
        thisList.head = Node(val)
    elif node.next != None:
        addNode(thisList, node.next, val)
    elif node.next == None:
        node.next = Node(val)

def printList(node, digitsPerNode):
    if node.next != None:
        printList(node.next, digitsPerNode)
    nodeString = str(node.val)
    if node.next != None:
        length = len(nodeString)
        if length < digitsPerNode:
            for i in range(length, digitsPerNode):
                nodeString = "0" + nodeString
            
        sys.stdout.write(nodeString)
    else:
        sys.stdout.write(nodeString)

def addList(num1, num2, carry, sumList, digitsPerNode):
    if num1 != None and num2 != None:
        #print("num1 ", num1.val)#
        #print("num2 ", num2.val)#
        #print("carry is ", carry)#
        sval = num1.val + num2.val + carry
        #print("sum value = ", sval)#
        if sval >= (10**digitsPerNode):
            carry = 1
            sval = sval - (10**digitsPerNode)
        else:
            carry = 0
        #print("carry is now ", carry)#
        addNode(sumList, sumList.head, sval)
        #printList(sumList.head)#
        addList(num1.next, num2.next, carry, sumList, digitsPerNode)

    elif num1 == None and num2 != None:
        #print("num2 ", num2.val)#
        #print("carry is ", carry)#
        sval = num2.val + carry
        #print("sum value = ", sval)#
        if sval >= (10**digitsPerNode):
            carry = 1
            sval = sval - (10**digitsPerNode)
        else:
            carry = 0
        #print("carry is now ", carry)#
        addNode(sumList, sumList.head, sval)
        #printList(sumList.head)#
        addList(num1, num2.next, carry, sumList, digitsPerNode)

    elif num2 == None and num1 != None:
        #print("num1 ", num1.val)#
        #print("carry is ", carry)#
        sval = num1.val + carry
        #print("sum value = ", sval)#
        if sval >= (10**digitsPerNode):
            carry = 1
            sval = sval - (10**digitsPerNode)
        else:
            carry = 0
        #print("carry is now ", carry)#
        addNode(sumList, sumList.head, sval)
        #printList(sumList.head)#
        addList(num1.next, num2, carry, sumList, digitsPerNode)
    elif carry == 1:
        addNode(sumList, sumList.head, carry)
'''
def multList(num1, num2, head1, head2, prList, depth1, depth2, digitsPerNode):
    if num1 != None:
        #print("A")
        if num2 != None:
            #print("B")
            prod = str(num1.val * num2.val)
            if prod != 0:
                #print(prod)
                #print(len(prod))
                """if len(prod) == 1:
                    primeNode = prod
                    print(primeNode)
                elif len(prod) <= digitsPerNode):
                    primeNode = prod[0:(len(prod)-1)]
                    print(primeNode)"""
                if len(prod) <= digitsPerNode:
                    primeNode = prod
                    #print(primeNode)
                elif len(prod) > digitsPerNode:
                    primeNode = prod[(len(prod) - digitsPerNode):(len(prod))]
                    carryNode = prod[0:(len(prod) - digitsPerNode)]
                    #print(primeNode)
                    #print(carryNode)
                #print("C")
                prTerm = List()
                i = depth1 + depth2
                while i > 0:
                    prTerm.addNode(0)
                    i = i-1
                #print("D")
                prTerm.addNode(int(primeNode))
                if len(prod) > digitsPerNode:
                    prTerm.addNode(int(carryNode))
                
                #print("E")
                tempList = List()
                addList (prList.head, prTerm.head, 0, tempList, digitsPerNode)
                prList = tempList

                #print("F")
            prList = multList(num1, num2.next, head1, head2, prList, depth1, depth2 + 1, digitsPerNode)

        if num2 == None:
            #print("G")
            prList = multList(num1.next, head2, head1, head2, prList, depth1 + 1, 0, digitsPerNode)
    return prList
'''

def depthListAssemble(prTerm, depth):
    if depth > 0:
        addNode(prTerm, prTerm.head, 0)
        depthListAssemble(prTerm, depth-1)
        
def multList(num1, num2, head1, head2, prList, depth1, depth2, digitsPerNode):
    if num1 != None:
        #print("A")
        if num2 != None:
            #print("B")
            prod = str(num1.val * num2.val)
            if prod != 0:
                #print(prod)
                #print(len(prod))
                
                if len(prod) <= digitsPerNode:
                    primeNode = prod
                    #print(primeNode)
                elif len(prod) > digitsPerNode:
                    primeNode = prod[(len(prod) - digitsPerNode):(len(prod))]
                    carryNode = prod[0:(len(prod) - digitsPerNode)]
                    #print(primeNode)
                    #print(carryNode)
                #print("C")
                prTerm = List()
                if depth1 + depth2 > 0:
                    depthListAssemble(prTerm, depth1 + depth2)
                
                #print("D")
                addNode(prTerm, prTerm.head, int(primeNode))
                if len(prod) > digitsPerNode:
                    addNode(prTerm, prTerm.head, int(carryNode))
                
                #print("E")
                tempList = List()
                addList(prList.head, prTerm.head, 0, tempList, digitsPerNode)
                prList = tempList

                #print("F")
            prList = multList(num1, num2.next, head1, head2, prList, depth1, depth2 + 1, digitsPerNode)

        if num2 == None:
            #print("G")
            prList = multList(num1.next, head2, head1, head2, prList, depth1 + 1, 0, digitsPerNode)
    return prList
def addToList(num, list1):
    if not num:
        return list1
    else:
        tempNum=int(num.pop())
        addNode(list1, list1.head, tempNum)
        addToList(num, list1)
    

def align(num1, result1, nodes):
    
    '''
    if(len(num1)<nodes):
        temp=num1
        
    else:
        temp=num1[len(num1)-nodes:len(num1)]
    num1=num1[:nodes*-1]
    result1.insert(0, temp)
    align(num1, result1, nodes)
    '''
    
    for i in range(len(num1), 0, nodes*-1):
        if(len(num1)<nodes):
            temp=num1
            #print(temp)
        else:
            temp=num1[len(num1)-nodes:len(num1)]
        num1=num1[:nodes*-1]
        result1.insert(0, temp)
            
#process input file
def process(fileInput, nodes):
    if not fileInput:
        return False
    else:
        #remove trailing characters and all spaces
        tempList=fileInput.pop(0).rstrip().replace(" ","")
        
        num1=''
        num2=''
        op=''
        
        if(tempList!='' and len(tempList)>1):
            #split string at operation
            if '+' in tempList:
                op='+'
                tempList=tempList.split('+')
            elif '*' in tempList:
                op='*'
                tempList=tempList.split('*')
                
            else:
                print('Error: invalid operation!')
            
            #store string to respective numbers
            num1=tempList[0]
            num2=tempList[1]
            
            
        if(len(num1)==0 or len(num2)==0):
            print('Error: invalid expression!')
        
        else:
            #remove leading zeros
            num1=num1.lstrip('0') or '0'
            num2=num2.lstrip('0') or '0'
            
            #print(num1)
            #print(num2)
            
            result1=[]
            result2=[]
            
            
            list1=List()
            list2=List()
            
            #align #s
            align(num1, result1, nodes)
            align(num2, result2, nodes)
            
            '''
            for i in range(len(num1), 0, nodes*-1):
                if(len(num1)<nodes):
                    temp=num1
                else:
                    temp=num1[len(num1)-nodes:len(num1)]
                num1=num1[:nodes*-1]
                result1.insert(0, temp)
                
            for i in range(len(num2), 0, nodes*-1):
                if(len(num2)<nodes):
                    temp=num2
                else:
                    temp=num2[len(num2)-nodes:len(num2)]
                num2=num2[:nodes*-1]
                result2.insert(0, temp)
            '''
            num1=result1
            num2=result2
            
            #print(num1)
            #print(num2)
            
            #add to lists
            addToList(num1, list1)
            addToList(num2, list2)
            
            #printList(list1.head)
            #print()
            #printList(list2.head)
            #print(num1)
            #print(num2)
            
            #Note:make sure special cases are handled
            #ex. missing integers, all zeros
            
            carry=0
            sumList=List()
            prList=List()
            
            #operation
            if op=='+':
                #add
                addList(list1.head, list2.head, carry, sumList, nodes)
                #format and print answer
                sys.stdout.write(tempList[0]+'+'+tempList[1]+'=')
                printList(sumList.head, nodes)
                print()
                
            elif op=='*':
                #multiply
                prList=multList(list1.head, list2.head, list1.head, list2.head, prList, 0, 0, nodes)
                #format and print answer
                sys.stdout.write(tempList[0]+'*'+tempList[1]+'=')
                
                printList(prList.head, nodes)
                print()
        
        process(fileInput, nodes)
        
#process command line input
#"input=<file name>;digitsPerNode=<number>"

filename='sampletests.txt'
nodes=3

'''
cmdlineinput=str(sys.argv[1:])
print(cmdlineinput)
argu=cmdlineinput.split(';')

filename=argu[0].replace('[\'input=', '')
nodes=argu[1].replace('digitsPerNode=', '')
nodes=nodes[:-2]

#print(filename)
#print(nodes)

nodes=int(nodes)
'''

#read file

try:
    file=open(filename, 'r')
    fileinput=file.readlines()
    process(fileinput, nodes)
    file.close()
except IOError:
    print('Error: Incorrect file name!')

#print(fileinput)

print("DONE")
