import requests
import json

problems = requests.get("https://codeforces.com/api/problemset.problems").json()
dic = {}

for problem in problems['result']['problems']:
    if 'rating' in problem: 
        if problem['rating'] >= 2100 and problem['rating'] <= 2400:
            for tag in problem['tags']:
                if tag in dic:
                    dic[tag] += 1
                else:
                    dic[tag] = 1

for tag in sorted(dic, key=dic.get, reverse=True):
    print(tag, dic[tag])
