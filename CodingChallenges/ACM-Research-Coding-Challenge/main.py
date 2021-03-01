import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from sklearn.cluster import KMeans
from kneed import KneeLocator

#Create a panda data frame from the csv file
df = pd.read_csv('ClusterPlot.csv', usecols=['V1','V2'])

#Convert the panda data frame to a NumPy array
arr = df.to_numpy()

#Code used to visualise the data and check if the import worked correctly
#Now commented out but retained for debugging.
#plt.scatter(arr[:,0],arr[:,1], label='True Position')
#plt.show()

# Create an array to store the Sum of Squared Errors or the cluster inertia
# for the k-clusters in multiple runs of the K-Means algo with different
# number of clusters assumed

distortions = []

for i in range(1,11):
    km = KMeans(n_clusters=i, init='random',
                n_init=10, max_iter=300,
                tol=1e-04, random_state=0)
    km.fit(arr)
    distortions.append(km.inertia_)

# Find the elbow or knee from the plot of no. of clusters vs distortion for that
# number. This algorithm locates the knee and that is used to provide the Number
# of clusters to the main run of K-means algo.

kn = KneeLocator(range(1,11), distortions, curve='convex', direction='decreasing')
print('The number of clusters are: ' + str(kn.knee))

#plot the no. of clusters vs distortion graph and annotate the elbow point

plt.plot(range(1, 11), distortions, marker='o')
plt.xlabel('Number of clusters')
plt.ylabel('Distortion')
plt.vlines(kn.knee, plt.ylim()[0], plt.ylim()[1], linestyles='dashed')
plt.show()



#From the sciKitLearn clustering algorithms, the K-means clustering
#algorithm is used.
km = KMeans(
    n_clusters=kn.knee, init='random',
    n_init=10, max_iter=300,
    tol=1e-04, random_state=0
)

#Obtain the cluster labels by running the K-means algorithm with
# the parameters defined above.
y_km = km.fit_predict(arr)

#Color Array
colors = ['lightgreen','orange','lightblue','azure', 'crimson','lightpink','black','gold', 'coral', 'navy']

#Marker Array
markers = ['s','o','v', '^', '<', '>',  'h', 'H', 'D', 'd']

#Plot the clusters.
for i in range(0, 3):
    plt.scatter(
        arr[y_km == i, 0], arr[y_km == i, 1],
        s=50, c=colors[i],
        marker=markers[i], edgecolor='black',
        label='cluster ' + str(i+1)
)

# Plotting the centroids for all the clusters.
plt.scatter(
    km.cluster_centers_[:, 0], km.cluster_centers_[:, 1],
    s=250, marker='*',
    c='red', edgecolor='black',
    label='centroids'
)

plt.legend(scatterpoints=1)
plt.grid()
plt.show()
