import copy
from gc import set_debug
import heapq as hp
from queue import PriorityQueue
import time
import random
from sklearn.preprocessing import StandardScaler
import math


def main():

    accuracy()

def accuracy():
    #open file
    file = open('small-test-dataset.txt', 'r')
    number_correctly_classified = 0
    current_set = [3,5,7]
    
    current_set.append(0)
    
    data = []

    #source on how to convert txt data into matrix
    #https://stackoverflow.com/questions/48833873/turn-txt-file-into-matrix-of-ints-in-python
    for row in file:
        data.append([float(x) for x in row.split()])

    
    
    for i in range(len(data)):
        #source on how to 0 out columns
        #https://stackoverflow.com/questions/36338927/how-to-zero-specific-column-of-2d-array
        for j in range(len(data[i])):
            if not j in current_set:
                data[i][j] = 0 
        
    for i in range(len(data)):

        object_to_clasify = []
        for j in range(len(data[i])):
            if(j != 0):
                object_to_clasify.append(data[i][j])

        label_object_to_classify = data[i][0]
        
        # print("Looping over i, at the " + str(i+1) + " location\n")
        # print("The " + str(i+1) + "th object is in class " + str(label) + "\n")
        
        nearest_neighbor_distance = float('inf')
        nearest_neighbor_location = float('inf')
        nearest_neighbor_label = None
        for j in range(len(data)):
            
            if i != j :
                # print("Ask if " + str(i+1) + " is nearest neighbor with " + str(j+1))
                compare = []
                for k in range(len(data[i])):
                    if(k != 0):
                        compare.append(data[j][k])
                
                distance = euclidean(object_to_clasify, compare)
                
                if distance < nearest_neighbor_distance:
                    # print("euclidean distance " + str(distance))
                    nearest_neighbor_distance = distance
                    nearest_neighbor_location = j
                    nearest_neighbor_label = data[nearest_neighbor_location][0]

        # print("object " + str(i+1) +"'s label is " + str(label_object_to_classify) +" and its nearest neighbors is at location " + str(nearest_neighbor_location+1)+ " with label " + str(nearest_neighbor_label))

        if label_object_to_classify == nearest_neighbor_label:
            number_correctly_classified += 1
    
    accuracy = number_correctly_classified/len(data)
    print(str(accuracy))

def euclidean(x, y):
    sum = 0
    # print(x)
    # print(y)
    for i in range(len(x)):
        dif = x[i] -y[i]
        square = pow(dif,2)
        sum += square
    dist = math.sqrt(sum)
    return dist

   



if __name__ == '__main__':
    main()


