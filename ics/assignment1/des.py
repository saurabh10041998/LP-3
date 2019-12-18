#!/usr/bin/python
import random
import time

# set the random seed
random.seed(time.time())

# p10 table(custom??)
p10 = {
	"input": [1 ,2, 3, 4, 5, 6, 7, 8, 9, 10],
	"output" : [3, 5, 7, 4, 10, 1, 9, 8, 6]
}

def KeyTrasform(key):
	pass

def pad(st, length, val):
	st = val*(length - len(st)) + st
	return st



if __name__ == "__main__":
	# generation of the initial data 
  	text = random.getrandbits(8)
	plain_text = "{0:b}".format(text)
	plain_text = pad(plain_text, 8, "1") 
	text = random.getrandbits(10)
	key = "{0:b}".format(text)
	key  = pad(key, 10, "1")
	print(plain_text)
	print(key)
		
	

