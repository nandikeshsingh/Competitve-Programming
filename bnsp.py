import numpy as np
import pandas as pd
import datetime

df=pd.read_csv('/content/NIFTY 50-01-06-2023-to-01-06-2024.csv')

# display(df)

print(df.columns)

max_price=df['High '].tolist()
close_price=df['Close '].tolist()
min_price=df['Low '].tolist()
open_price=df['Open '].tolist()
date=df['Date '].tolist()

print(max_price)
print(close_price)
print(date)
def get_weekday(s):
  x=s[0]+s[1]
  y=s[3]+s[4]+s[5]
  z=s[7]+s[8]+s[9]+s[10]
  # print("s=",s," x=",x," y=",y," z=",z)
  month = {'JAN':'01',
		'FEB':'02',
		'MAR':'03',
		'APR':'04',
		'MAY':'05',
		'JUN':'06',
		'JUL':'07',
		'AUG':'08',
		'SEP':'09',
		'OCT':'10',
		'NOV':'11',
		'DEC':'12'}
  intDay = datetime.date(year=int(z), month=int(month[y]), day=int(x)).weekday()
  days = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
  # print("return day : ",days[intDay])
  return (days[intDay])

n=len(max_price)
error_list=[]
front_error_list=[]
back_error_list=[]
days_list=[]
# i=1
for i in range(n):
  if(i+11>=n):
    break
  if(get_weekday(date[i])=="Friday"):
    j=i+1
    f=0
    while f<2:
     while(get_weekday(date[j])!="Thursday" and j<n):
        j+=1
     f+=1
     j+=1
    if(max_price[i]-close_price[j]>=100):
      # error_list.append(i)
      front_error_list.append(i)
      back_error_list.append(j)
  # days_list.append(date[i])
print(front_error_list)
print(back_error_list)
print("total days = ",len(front_error_list))
# print(days_list)


n=len(front_error_list)
for index in range(n):
  print(date[front_error_list[index]]," ",date[back_error_list[index]],max_price[front_error_list[index]]-close_price[back_error_list[index]])