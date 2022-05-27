import math
import time
import sys
import numpy as np
from sympy import numer
import csv


def main():
    print("Welcome to Crystal Feng's Evaluation Program.\n")
    dataset = int(input("Which data set would you like to use?\n"
                            "1. Small\n"
                            "2. Large\n"))
    
    if(dataset == 1):
        file = open('small-test-dataset.txt', 'r')
    elif(dataset == 2):
        file = open('Large-test-dataset.txt', 'r')

    x = input("\nEnter the features you want to use seperated by spaces\n")
        
    features = x.split(' ')

    for i in range(len(features)):
        features[i]= int(features[i])

    # print(features)

    printnorm(file)


    # accuracy(file, features)

def printnorm(file):
    data1 = []

    #source on how to convert txt data into matrix
    #https://stackoverflow.com/questions/48833873/turn-txt-file-into-matrix-of-ints-in-python
    for row in file:
        data1.append([float(x) for x in row.split()])

    data = normalize(data1)

    for i in range(len(data[0])):
        if i > 0:
            min = sys.maxsize
            max = -sys.maxsize -1

            for j in range(len(data)):
                if data[j][i] < min:
                    min = data[j][i]
                if data[j][i] > max:
                    max = data[j][i]
        
            print("for col " + str(i) + " the min is " +str(min) + " and the max is" + str(max) + "\n")


    with open("output.csv", "w") as f:
        writer = csv.writer(f)
        writer.writerows(data)

def accuracy(file, current_set):
    start_time = time.time()
    #open file
    number_correctly_classified = 0
    
    current_set.append(0)
    
    data1 = []

    #source on how to convert txt data into matrix
    #https://stackoverflow.com/questions/48833873/turn-txt-file-into-matrix-of-ints-in-python
    for row in file:
        data1.append([float(x) for x in row.split()])

    data = normalize(data1)
    
    
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

        print("object " + str(i+1) +"'s label is " + str(label_object_to_classify) +"\nits nearest neighbors is object " + str(nearest_neighbor_location+1)+ " with label " + str(nearest_neighbor_label))
        print("Time to compute = " + str(time.time() - start_time) + " seconds\n\n")
        if label_object_to_classify == nearest_neighbor_label:
            number_correctly_classified += 1
    
    accuracy = number_correctly_classified/len(data)
    print("\nAccuracy is " + str(accuracy) + "%")

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

def normalize(data):
    for i in range(len(data[0])):
        if i > 0:
            min = sys.maxsize
            max = -sys.maxsize -1

            for j in range(len(data)):
                if data[j][i] < min:
                    min = data[j][i]
                if data[j][i] > max:
                    max = data[j][i]
        
            denominator = max - min

            for k in range(len(data)):
                numerator = data[k][i] - min
                data[k][i] = numerator/denominator

    return data



if __name__ == '__main__':
    main()


