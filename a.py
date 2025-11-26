alphabet = []
start = ord('a')
for i in range(26):
    alphabet.append(chr(start + i))
# for i in range(26):
#     char.append('a'+i)
alphabet.reverse()
ans=""
y="abcdW"
x=list(y)
print(x)
for i in range(len(x)):
    if (x[i]<='z' and x[i]>='a'):
        # ans.append(alphabet[ord(x[i])-97])
        ans+=alphabet[ord(x[i])-97]
    else:
        ans+=x[i]
        # ans.append(x[i])

print(ans)
# for i in range(len(x)):
#     if(x[i]<='z' and x[i]>='a'):
#         x[i]=alphabet[int(x[i]-'a')]
# print(x)
# import string

# def main():
#     print("inside main")
#     s=solution("aaasfd")
#     print(s)

# def solution(x):
#     ch=list(string.ascii_lowercase)
#     # for i in range(26):
#     #     char.append('a'+i)
#     ch.reverse()
#     ans=""
#     for i in range(len(x)):
#         if(x[i]<='z' and x[i]>='a'):
#             x[i]=ch[int(x[i]-'a')]
#     return x


