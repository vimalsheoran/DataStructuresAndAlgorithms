import time

# Simple exponentiation
def simple_exp(number, power):
	if power == 0:
		return 1
	return number * simple_exp(number, power-1)

# Binary exponentiation
def binary_exp(number, power):
	if power == 0:
		return 1
	if power%2 == 0:
		return binary_exp(number*number, power/2)
	else:
		return number*binary_exp(number*number, (power-1)/2)

def main():
	print("Enter the number:")
	number = int(input())
	print("Enter the power:")
	power = int(input())

	_time = time.time()
	num = simple_exp(number, power)
	_time = time.time() - _time
	print("Time taken for simple exponetiation: "+str(_time))

	_time = time.time()
	num = binary_exp(number, power)
	_time = time.time() - _time
	print("Time taken for binary exponetiation: "+str(_time))

	print("Resultant: "+str(num))

if __name__ == "__main__":
	main()