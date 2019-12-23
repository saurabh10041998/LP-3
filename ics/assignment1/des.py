#!/usr/bin/python3
import random
import time

# set the random seed
random.seed(time.time())

#cache the data in dictionary (key)
data = {}
# p10 table(custom??)
p10 = {
	"input": [1 ,2, 3, 4, 5, 6, 7, 8, 9, 10],
	"output" : [3, 5, 2, 7, 4, 10, 1, 9, 8, 6]
}

#p8 table(custom??)
p8 = {
	"input": [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
	"output": [6, 3, 7, 4, 8, 5, 10, 9] 
}


def rotate(input, d):
	Lfirst = input[0: d]
	Lsecond = input[d: ]
	return Lsecond + Lfirst

def KeyTransform(key, nshift = 1):
	n = len(key)
	lkey = key[:n//2]
	rkey = key[n//2: ]
	lkey = rotate(lkey,nshift)
	rkey = rotate(rkey,nshift)
	key = lkey + rkey
	# apply p8 permutation
	new_key = [0] * 8 
	i = 0
	for j in p8["output"]:
		new_key[i] = key[j-1]
		i += 1
	return "".join(new_key),lkey,rkey
	

def pad(st, length, val):
	st = val*(length - len(st)) + st
	return st



if __name__ == "__main__":
	#generation of the initial data 
	text = random.getrandbits(8)
	plain_text = "{0:b}".format(text)
	plain_text = pad(plain_text, 8, "1") 
	text = random.getrandbits(10)
	#key = "{0:b}".format(text)
	key = str(bin(text))[2:]
	key  = pad(key, 10, "1")
	print(key)
	K1,lkey, rkey = KeyTransform(key)
	data["K1"] = K1
	K2, _, _ = KeyTransform(lkey+rkey, 2)
	data["K2"] = K2
	print(data)
			
	
		
	
		
