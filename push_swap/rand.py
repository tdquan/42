import random
a = range(1,1000)
for i in xrange(20):
	b = a[random.randint(0, len(a)-i)]
	a.remove(b)
	print b