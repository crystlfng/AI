import math
import time
import copy
import sys
import csv


def main():
    print("Welcome to Crystal Feng's Evaluation Program.\n")
    dataset = int(input("Which data set would you like to use?\n"
                            "1. Small\n"
                            "2. Large\n"))
    
    if(dataset == 1):
        file = open('CS170_Spring_2022_Small_data__22.txt', 'r')
    elif(dataset == 2):
        file = open('CS170_Spring_2022_Large_data__22.txt', 'r')


    searchAlgo = int(input('\nType the number of the algorithm you want to run\n'
                          '1. Forward Search\n'
                          '2. Backward Search\n'
                          '3. Bertie\'s Search Algorithm\n'))
    
    if searchAlgo == 1:
        forward(file)
    elif searchAlgo == 2:
        backward(file)

def emptyfs(data):
    class1 = 0
    class2 = 0

    for i in range(len(data)):
        if data[i][0] >1:
            class2+= 1
        else:
            class1+= 1
    
    if class1 > class2:
        accuracy = class1/len(data[0])
        c = "class1"
    else:
        accuracy = class2/len(data)
        c = 'class2'
    print("Running nearest neighbor with no features (default rate), using \"leave on out\" evaluation, I get an accuracy of " + str(accuracy*100) + "%\n")

    return accuracy

    

def matrix(file):
    data = []

    #source on how to convert txt data into matrix
    #https://stackoverflow.com/questions/48833873/turn-txt-file-into-matrix-of-ints-in-python
    for row in file:
        data.append([float(x) for x in row.split()])

    print("This dataset has " + str(len(data[0])-1) + " features (not including the class attribute), with " + str(len(data)) + " instances.\n\n")

    data = normalize(data)

    return data

def forward(file):
    fset = []
    realbest = 0
    print("Beginning Search\n")

    data = matrix(file)

    realbest = emptyfs(data)

    
    for i in range(1,len(data[0])):
        # print("on the " + str(i) + "th level of the search tree\n")
        best = 0
        curr = []
        for j in range(1,len(data[0])):
            
            if not j in fset:
                curr = [j]
                curr.extend(fset)
                    
                # print("++Consider adding the " + str(j) + " feature\n")
                accuracy = calcaccuracy(data, curr)
                
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
        
def backward(file):
    fset=[]

    data = matrix(file)
    
    for i in range(1,len(data[0])):
        fset.append(i)
    
    accuracy = calcaccuracy(data, None)
    realbest = accuracy
    
    print("Using all features(s) " + str(fset) + " accuracy is " + str(accuracy) + "%\n")
        
    print("Beginning Search\n")

    for i in range(1,len(data[0])):
        best = 0
        curr = []
        for j in range(1,len(data[0])):
            if j in fset:
                curr = copy.deepcopy(fset)
            
                # print(str(curr) + "\n" + str(j) + "\n")
            
                curr.remove(j)
                # print(str(curr) + "\n" )
                accuracy = calcaccuracy(data, curr)
                
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
        
def calcaccuracy(matrix, current_set):
    # start_time = time.time()
    #open file
    number_correctly_classified = 0
    
    data = copy.deepcopy(matrix)
    
    for i in range(len(data)):
        #source on how to 0 out columns
        #https://stackoverflow.com/questions/36338927/how-to-zero-specific-column-of-2d-array
        if(current_set):
            for j in range(len(data[i])):
                if not j in current_set and j != 0:
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

        # print("object " + str(i+1) +"'s label is " + str(label_object_to_classify) +"\nits nearest neighbors is object " + str(nearest_neighbor_location+1)+ " with label " + str(nearest_neighbor_label))
        # print("Time to compute = " + str(time.time() - start_time) + " seconds\n\n")
        if label_object_to_classify == nearest_neighbor_label:
            number_correctly_classified += 1
    
    accuracy = number_correctly_classified/len(data)
    # print("\nAccuracy is " + str(accuracy*100) + "%")
    return accuracy*100

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
    print("Please wait while I normalize the data ...")
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
    
    print("Done!\n")

    return data

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

if __name__ == '__main__':
    main()


