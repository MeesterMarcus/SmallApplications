import re
f = open("dates",'r')
mon = {'01': 'January', '02': 'February', '03': 'March',
           '04': 'April',   '05': 'May',      '06': 'June', 
           '07': 'July',    '08': 'August',   '09': 'September', 
           '10': 'October', '11': 'November', '12': 'December'}

r1 = re.compile("(\d*)-(\d*)-(\d*)\s*(\d*):(\d*):(\d*)")

def convert(line):
	m = r1.match(line)

        if m != None:
		year = int(m.group(1))
		month = m.group(2)
		day = int(m.group(3))
		hour = int(m.group(4))
		minute = int(m.group(5))
		seconds = int(m.group(6))

		if (hour >= 12):
			time = "pm"
		else:
			time = "am"
		if (hour == 0):
			hour = 12; 
		if (hour != 12):
			hour = hour % 12; 
		
		#10:03 pm, April 20, 2004
		print '%d:%02d %s, %s %d, %d' %  (hour,minute,time, mon[month],day,year)

while True:
	line = f.readline()
	convert(line)
	if not line:
		break
	
