BEGIN{
print "\t\t\tNews Reader Summary\n\n"
printf("               %-15s%-15s%-15s%-15s\n\n","lonestar","runner","ringer","rings"); 
}

NR == 1 {date1 = $1 " " $2 " " $3}

$6 == "lonestar.jpl.utsa.edu"{
	if ($7=="group"){
		articles[1]+=$9;
		if ($8=="utsa.cs.2413"){
			cs2413[1]+=$9;
		}
		if ($8=="utsa.cs.2413.d"){
			cs2413d[1]+=$9;
		}
	}else if ($7 == "exit"){
		groups[1]+=$11;
	}else {
		times[1]+=$13;
	}
}

$6 == "runner.jpl.utsa.edu"{
	if ($7=="group"){
                articles[2]+=$9;
		 if ($8=="utsa.cs.2413"){
                        cs2413[2]+=$9;
                }
                if ($8=="utsa.cs.2413.d"){ 
                        cs2413d[2]+=$9;
                }

        }else if ($7 == "exit"){
                groups[2]+=$11;
        }else {
                times[2]+=$13;
        }

}

$6 == "ringer.cs.utsa.edu"{
	if ($7=="group"){
                articles[3]+=$9;
		 if ($8=="utsa.cs.2413"){
                        cs2413[3]+=$9;
                }
                if ($8=="utsa.cs.2413.d"){ 
                        cs2413d[3]+=$9;
                }

        }else if ($7 == "exit"){
                groups[3]+=$11;
        }else {
                times[3]+=$13;
        }

}

$6 ~ /^ring..\.cs\.utsa\.edu$/{
	if ($7=="group"){
                articles[4]+=$9;
		 if ($8=="utsa.cs.2413"){
                        cs2413[4]+=$9;
                }
                if ($8=="utsa.cs.2413.d"){ 
                        cs2413d[4]+=$9;
                }

        }else if ($7 == "exit"){
                groups[4]+=$11;
        }else {
                times[4]+=$13;
        }

}
END{
	date2 = $1 " " $2 " " $3
	printf("Articles:      %-15d%-15d%-15d%-15d\n",articles[1],articles[2],articles[3],articles[4]); 
	printf("Groups:        %-15d%-15d%-15d%-15d\n",groups[1],groups[2],groups[3],groups[4]); 
	printf("Cs2413:        %-15d%-15d%-15d%-15d\n",cs2413[1],cs2413[2],cs2413[3],cs2413[4]); 
	printf("Cs2413.d:      %-15d%-15d%-15d%-15d\n",cs2413d[1],cs2413d[2],cs2413d[3],cs2413d[4]); 
	printf("User Time:     %-15.2f%-15.2f%-15.2f%-15.2f\n",times[1],times[2],times[3],times[4]);  
	printf("\nStart Time = %s\tEnd Time = %s\n",date1,date2); 

}

