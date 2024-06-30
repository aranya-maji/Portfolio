import matplotlib.pyplot as plt
import random as random

def expander(radius,point_chart,cluster_start_points,step_size):
    while(True):
        flag = -1
        for i in range (0,len(cluster_start_points)-1):
            for j in range (i+1,len(cluster_start_points)):
                if(disp(cluster_start_points[i][0],cluster_start_points[i][1],cluster_start_points[j][0],cluster_start_points[j][1]) <= 2 * radius):
                    cluster_start_points,flag = shifter(cluster_start_points,point_chart,radius)
                    if(flag == 0):
                        break
                    elif(flag == 1):
                        return radius,cluster_start_points
            if(flag == 0):
                break
        radius = radius + step_size

def disp(cl_start_points0,cl_start_points1,cl_end_points0,cl_end_points1):
    x = (((cl_start_points0-cl_end_points0)**2) + ((cl_start_points1-cl_end_points1)**2))**0.5
    return x

def collision_resolver(point,cl1,cl2,cluster_start_points,radius):
    flag = 0
    for i in range (0,len(cluster_start_points)):
        if(cluster_start_points[i] != cl1):
            if(disp(cluster_start_points[i][0],cluster_start_points[i][1],point[0],point[1]) <= 2 * radius):
                flag = 1
                break
    if(flag == 0):
        cl1 = point
        return cl1,cl2,0
    flag = 0
    for i in range (0,len(cluster_start_points)):
        if(cluster_start_points[i] != cl2):
            if(disp(cluster_start_points[i][0],cluster_start_points[i][1],point[0],point[1]) <= 2 * radius):
                flag = 1
                break
    if(flag == 0):
        cl2 = point
        return cl1,cl2,0
    else:
        return cl1,cl2,1

def shifter(cluster_start_points,point_chart,radius):
    flag = -1
    for i in range (0,len(cluster_start_points)-1):
        for j in range (i+1,len(cluster_start_points)):
            flag = -1
            if(disp(cluster_start_points[i][0],cluster_start_points[i][1],cluster_start_points[j][0],cluster_start_points[j][1]) <= 2 * radius):
                for k in range (0,len(point_chart)):
                    if(point_chart[k] not in cluster_start_points):
                        cluster_start_points[i],cluster_start_points[j],flag = collision_resolver(point_chart[k],cluster_start_points[i],cluster_start_points[j],cluster_start_points,radius)
                        if(flag == 0):
                            break
                if(flag == 1):
                    return cluster_start_points,1
    return cluster_start_points,0

def confirmer(cluster_start_points,radius):
    for i in range (0,len(cluster_start_points)-1):
        for j in range (i+1,len(cluster_start_points)):
            if(disp(cluster_start_points[i][0],cluster_start_points[i][1],cluster_start_points[j][0],cluster_start_points[j][1]) <= 2 * radius):
                return 0
    return 1

def assigner(point_chart,cluster_start_points,radius,cluster_box):
    for i in range (0,len(cluster_start_points)):
        cluster_box.append([])
    for j in range (0,len(cluster_start_points)):
        cluster_points_remove = []
        for i in range (0,len(point_chart)):
            if(disp(point_chart[i][0],point_chart[i][1],cluster_start_points[j][0],cluster_start_points[j][1]) <= radius):
                cluster_box[j].append(point_chart[i])
                cluster_points_remove.append(point_chart[i])
        for i in range (0,len(cluster_points_remove)):
            point_chart.remove(cluster_points_remove[i])
    return point_chart,cluster_box

def gulper(point_chart,cluster_start_points,radius,step_size,cluster_box):
    noise_box = []
    while(len(point_chart) != 0):
        points_remove = []
        for i in range (0,len(point_chart)):
            noise_checker = []
            for j in range (0,len(cluster_start_points)):
                if(disp(point_chart[i][0],point_chart[i][1],cluster_start_points[j][0],cluster_start_points[j][1]) <= radius):
                    noise_checker.append(j)
            if(len(noise_checker) == 1):
                cluster_box[noise_checker[0]].append(point_chart[i])
                points_remove.append(point_chart[i])
            elif(len(noise_checker) > 1):
                noise_box.append(point_chart[i])
                points_remove.append(point_chart[i])
        for i in range (0,len(points_remove)):
            point_chart.remove(points_remove[i])
        radius = radius + step_size
    return noise_box,cluster_box,point_chart,radius

print("Enter the point coordinates in the format (x1,y1,x2,y2,.....xn,yn) without the braces:- ")
inp = input()
inp = inp.split(",")
for i in range (len(inp)):
    inp[i] = float(inp[i].strip())
if(len(inp)%2 == 1):
    print("Invalid Entry")
else:
    point_chart = []
    for i in range(0,len(inp),2):
        temp1 = [];
        temp1.append(inp[i])
        temp1.append(inp[i+1])
        point_chart.append(temp1)
    inp1 = int(input("Enter number of clusters:- "))
    if(inp1 > len(point_chart) or inp1 < 2):
        print("Invalid Entry: Cluster count can never be more than number of points or less than 2")
    else:
        cluster_box = []
        cluster_start_points = []
        step_size = float(input("Enter step size:- "))
        if(step_size <= 0):
            print("Step size is none or invalid")
        else:
            radius = 0.00;
            for i in range (inp1):
                cluster_start_points.append(point_chart[i])
            print("\n\n")
            print("-------------------- Initialization --------------------")
            print("\n")
            print("Points")
            for i in point_chart:
                print(i)
            print("\n")
            print("Cluster starting points")
            print(cluster_start_points)
            print("\n")
            print("Radius")
            print(radius)
            print("\n")
            print("Step size")
            print(step_size)
            print("\n\n")
            radius,cluster_start_points = expander(radius,point_chart,cluster_start_points,step_size)
            point_chart,cluster_box = assigner(point_chart,cluster_start_points,radius,cluster_box)
            print("-------------------- After Kingdom Expansion (Phase I) --------------------")
            print("\n")
            print("Final capital points")
            print(cluster_start_points)
            print("\n")
            print("Updated clusters")
            for i in cluster_box:
                print(i)
                print("\n")
            print("\n")
            print("Neutral points (unassigned points)")
            for i in point_chart:
                print(i)
            print("\n")
            print("Radius")
            print(radius)
            print("\n")
            print("Step size")
            print(step_size)
            print("\n\n")
            noise_box,cluster_box,point_chart,radius = gulper(point_chart,cluster_start_points,radius,step_size,cluster_box)
            print("-------------------- After Conquering Neutral Points (Phase II) --------------------")
            print("\n")
            print("Final capital points")
            print(cluster_start_points)
            print("\n")
            xpoints = []
            ypoints = []
            colors = []
            print("Updated clusters")
            for i in cluster_box:
                print(i)
                r = random.random()
                g = random.random()
                b = random.random()
                rgb = (r,g,b)
                for j in i:
                    xpoints.append(j[0])
                    ypoints.append(j[1])
                    colors.append(rgb)
                print("\n")
            print("\n")
            print("Noise points")
            for i in noise_box:
                print(i)
            print("\n")
            print("Radius")
            print(radius)
            print("\n")
            print("Step size")
            print(step_size)
            print("\n\n")
            figure,axes = plt.subplots(figsize=[5,5], dpi=100)
            plt.scatter(xpoints, ypoints, c=colors)
            for i in cluster_start_points:
                circle = plt.Circle((i[0],i[1]),radius,fill=False)
                axes.set_aspect( 1 )
                axes.add_artist(circle)
            plt.tight_layout()
            plt.show()

#-1,-1,-2,-2,-3,-3,1,1,2,2,3,3,-1,1,-2,2,-3,3,1,-1,2,-2,3,-3 symmetric points (may lead to noise points existence)
#2,5,5,3,-2,-2,9,-4,9,-3,-4,-5,6,7,12,14,-12,-9,6,-8 unsymmetric points leading to negligible probabilities of noise point existence

#32,-7,-45,23,18,-56,7,15,-22,49,56,-33,12,-11,23,41,-34,18,5,-27,44,32,-28,-15,9,8,-16,24,36,-9,48,3,27,-42,-7,-39,15,27,-50,50,19,-22,34,-47,0,0,8,14,-19,31,22,-8,11,38,-25,-10,42,-21,4,13,-10,17,35,-30,6,21,24,-12,-38,36,10,5,49,-44,-14,28,33,-6,21,-19,-3,7,29,40,46,-26,-29,19,13,33,39,-17,-5,-20,26,11,17,-34,2,18,-40,-24,31,4,25,-5,45,6,-6,30,3,23,41,-28,28,-16,-18,20,47,-37,14,12,38,26,-33,-7,30,9,50,-25,-8,32,1,37,20,-13,37,-3,-13,6,16,29,43,-18,9,-45,-20,13,12,-36,6,35,27,16,-12,-5,40,2,22,-32,5,48,32,-23,11,-8,48,24,7,-4,-26,22,3,-41,24,0,18,10,-35,5,14,47,19,-38,2,25,37,6,45,-12,8,-14,-4,28,33,-29,20,46,13,-50 (AI Generated points)
