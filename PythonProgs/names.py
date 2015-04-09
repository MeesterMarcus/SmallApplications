import re
f = open("names",'r')
r1 = re.compile("(\d\d)\s*(\w*)\s*([A-Z]\. |)\s*(\w*)\s*@0*(\d*)")
while True:
	line = f.readline()
	m = r1.match(line)
        if m != None:
		g = m.groups()
		print (m.group(5)+" "+m.group(4)+", "+m.group(2)+" "+m.group(3))
	else:
		print "No Match"
		break;
