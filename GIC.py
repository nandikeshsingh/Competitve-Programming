import numpy as np

def random_lat_lon(n=2, lat_min=-90., lat_max=90., lon_min=-180., lon_max=180.):
    """
    this code produces an array with pairs lat, lon
    """
    lat = np.random.uniform(lat_min, lat_max, n)
    lon = np.random.uniform(lon_min, lon_max, n)

    return np.array(tuple(zip(lat, lon)))

arr =random_lat_lon()
y=arr[0]
print("y=",y)
# print("before")
# print(arr[0])
for x in arr:
    print(x)
    # print(x[0]," ",x[1])

for x in range(0,100):
    # print("insice")
    arr=np.append(arr,y,axis=1)
    print(len(arr))

print("Printing arr")
for x in arr:
    print(x)

