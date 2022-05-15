import copy
from gc import set_debug
import heapq as hp
from queue import PriorityQueue
import time
import random
import math

def main():
    print("Welcome to Crystal Feng Feature Selection Algorithm.\n")
    featureNum = int(input("Please enter total number of features: "))
    
    searchAlgo = int(input('\nType the number of the algorithm you want to run\n'
                          '1. Forward Search\n'
                          '2. Backward Search\n'
                          '3. Bertie\'s Search Algorithm\n'))
    
    if searchAlgo == 1:
        forward(featureNum)
    elif searchAlgo == 2:
        backward(featureNum)
    else:
        print("Berite's not implemented yet\n")
    
    
def forward(num):
    fset = []
    realbest = 0
    print("Beginning Search\n")
    
    for i in range(1,num+1):
        # print("on the " + str(i) + "th level of the search tree\n")
        best = 0
        curr = []
        for j in range(1,num+1):
            
            if not j in fset:
                curr = [j]
                curr.extend(fset)
                    
                # print("++Consider adding the " + str(j) + " feature\n")
                accuracy = calcAccuracy()
                
                print("Using features(s) " + str(curr) + " accuracy is " + str(accuracy) + "%\n")
                
                if accuracy > best:
                    best = accuracy
                    bestset = curr
                    
        if(best < realbest):
            print("\n(Warning, Accuracy has decreased!!)\n")
            print("Finished search!! The best feature sebset is "+ str(fset) + " which has an accuracy of " + str(realbest) + "%\n")
            break;
        fset = bestset
        realbest = best
        print("\nFeature set " + str(bestset) + " was best, accuracy is " + str(best) + "%\n\n")
        
def backward(num):
    fset=[]
    
    for i in range(1,num+1):
        fset.append(i)
    
    accuracy = calcAccuracy()
    realbest = accuracy
    
    print("Using all features(s) " + str(fset) + " accuracy is " + str(accuracy) + "%\n")
        
    print("Beginning Search\n")

    for i in range(1,num+1):
        best = 0
        curr = []
        for j in range(1,num+1):
            if j in fset:
                curr = copy.deepcopy(fset)
            
                # print(str(curr) + "\n" + str(j) + "\n")
            
                curr.remove(j)
                # print(str(curr) + "\n" )
                accuracy = calcAccuracy()
                
                print("Using features(s) " + str(curr) + " accuracy is " + str(accuracy) + "%\n")
            
                if accuracy > best:
                    best = accuracy
                    bestset = curr
                    
        if(best < realbest):
            print("\n(Warning, Accuracy has decreased!!)\n")
            print("Finished search!! The best feature sebset is "+ str(fset) + " which has an accuracy of " + str(realbest) + "%\n")
            break;
            
        fset = bestset
        realbest = best
        print("\nFeature set " + str(bestset) + " was best, accuracy is " + str(best) + "%\n\n")              
        
    
            
def calcAccuracy():
    accuracy = round(random.uniform(0, 100), 2)
    return accuracy
    
    
class Node:
    def __init__(self, features, accuracy):
            self.features = features
            self.accuracy = accuracy
    def __lt__(self, other):
        return other.feature + other.accuracy > self.feature + self.accuracy
    
if __name__ == '__main__':
    main()