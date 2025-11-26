# from itertools import combinations

# def solution(num_buns, num_required):
#     # Initialize the list of keys
#     keyrings = [[] for num in range(num_buns)]
#     # Calculate how many copies are required
#     # per each key
#     copies_per_key = num_buns - num_required + 1
#     # Append keys in the list initialized above
#     for key, bunnies in enumerate(combinations(range(num_buns), copies_per_key)):
#         for bunny in bunnies:
#             keyrings[bunny].append(key)

#     return keyrings

from itertools import combinations

def solution(num_buns, num_required):
    # Initialize the list of keys
    kk = [[] for num in range(num_buns)]
    # Calculate how many copies are required
    # per each key
    now = num_buns - num_required + 1
    # Append keys in the list initialized above
    for was, has in enumerate(combinations(range(num_buns), now)):
        for cur in has:
            kk[cur].append(was)

    return kk
print(solution(5,3))

# If you have N bunnies, and M locks, distribute M distinct keys among the bunnies so that it will always require num_required bunnies to open
# the locks, and no bunny should have the same key twice


