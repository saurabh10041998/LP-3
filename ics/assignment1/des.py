import random
import time

# set the random seed
random.seed(time.time())

if __name__ == "__main__":
	# generation of the initial data 
  	hash  = random.getrandbits(65)
	plain_text = "{0:b}".format(hash)
	key = "{0:b}".format(random.getrandbits(65))
	
	#generation of key
	key = key[::-1]
	print(len(key))
	new_key = ""
	for i in range(8):
	  	new_key += key[8 * i : 8 * (i+1) -1]
	print(len(new_key))
	

