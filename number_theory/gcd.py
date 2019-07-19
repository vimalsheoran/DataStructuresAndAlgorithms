import time

# Simple GCD Algorithm
def simple_gcd(a, b):
	_min = min(a, b)
	while(_min > 0):
		if (a%_min == 0 and b%_min == 0):
			return _min
		_min -= 1
	return _min

# Basic Euclidean Algorithm
def basic_euclid_gcd(a, b):
	if b == 0:
		return a
	return basic_euclid_gcd(b, a%b)

def main():

	print("Enter both the numbers:")
	a = int(input())
	b = int(input())
	_time = time.time()
	num = simple_gcd(a,b)
	_time = time.time() - _time
	print("Time take for simple gcd algorithm: "+str(_time))
	_time = time.time()
	num = basic_euclid_gcd(a, b)
	_time = time.time() - _time
	print("Time taken for basic euclid gcd algorithm: "+str(_time))
	print("GCD: "+str(num))

if __name__ == "__main__":
	main()
