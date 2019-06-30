N, K = raw_input().split(' ')
N = int(N)
K = int(K)
s = raw_input().split(' ')

for x in range(0, len(s)):
    s[x] = int(s[x])

tree = {}
# init root node
tree[1] = {}
tree[1]["data"] = s[0]
tree[1]["children"] = []
tree[1]["parent"] = "root"
i = 0
while i < N - 1:
	U, V = raw_input().split(' ')
	U = int(U)
	V = int(V)
	tree[U]["children"].append(V)
	tree[V] = {}
	tree[V]["data"] = s[V-1]
	tree[V]["children"] = []
	tree[V]["parent"] = U
	i += 1

def sum_of_tree(parent_node):
	node = tree[parent_node]
	if(not len(node["children"])):
		return node["data"]
	sum = node["data"]
	for x in node["children"]:
		sum += sum_of_tree(x)
	return sum

deletion = 0

def check_for_deletion(parent_node):
	global deletion
	curr_node = tree[parent_node]
	for child in curr_node["children"]:
		sum_sub_tree = sum_of_tree(child)
		total_sum = sum_sub_tree + curr_node["data"]
		if(total_sum > K):
			deletion += 1
	for child in curr_node["children"]:
		check_for_deletion(child)

check_for_deletion(1)
print(deletion)