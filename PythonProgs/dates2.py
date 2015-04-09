import re
f = open("dates2",'r')
mon = {'01': 'January', '02': 'February', '03': 'March',
           '04': 'April',   '05': 'May',      '06': 'June', 
           '07': 'July',    '08': 'August',   '09': 'September', 
           '10': 'October', '11': 'November', '12': 'December'}
mon_inv = {}
for (k,v) in mon.items():
	mon_inv[v]=k

#10:03 pm, April 20, 2004
r1 = re.compile("(\d*):(\d*) (\w*), (\w*) (\d*), (\d*)")

def convert(line):
	
	m = r1.match(line)
	
        if m != None:
		#2004-04-20 22:03:00
		year = m.group(6)
		day = int(m.group(5))
		month = m.group(4)
		time = m.group(3)
		minute = int(m.group(2))
		hour = int(m.group(1))

		if (time == 'pm'):
			if (hour == 12):
				hour = 12;
			else:
				hour=hour+12;
		elif (time == 'am'):
			if (hour == 12):
				hour = 0; 
		g = m.groups()
		print '%s-%s-%02d %d:%02d:00' %  (year,mon_inv[month],day,hour,minute)

while True:
	line = f.readline()
	convert(line)
	if not line:
		break

