BEGIN{
print "\t\t\tIncoming News Feed Summary\n"
print "\t\taccepted\trejected\tcanceled\n"
}

NR == 1 {date1 = $1 " " $2 " " $3}

$5 == "swrinde"{

	if ($4 == "+" || $4 == "j"){
		accepted[1]++;
	}else if ($4 == "c"){
		cancelled[1]++; 
		accepted[1]++;
	}else{
		rejected[1]++; 
	}
}

$5 == "news.cais.net"{
        if ($4 == "+" || $4 == "j"){
                accepted[2]++;
        }else if ($4 == "c"){
                cancelled[2]++; 
		accepted[2]++;
        }else{
                rejected[2]++; 
        }
}

$5 == "?"{
        if ($4 == "+" || $4 == "j"){
                accepted[3]++;
        }else if ($4 == "c"){
                cancelled[3]++;
		accepted[3]++; 
        }else{
                rejected[3]++; 
        }
}

END{
	date2 = $1 " " $2 " " $3
	printf("swrinde \t %-10d \t %-10d \t %-10d\n",accepted[1],rejected[1],cancelled[1]);
	printf("news.cais.net \t %-10d \t %-10d \t %-10d\n",accepted[2],rejected[2],cancelled[2]);
	printf("? \t\t %-10d \t %-10d \t %-10d\n\n",accepted[3],rejected[3],cancelled[3]);
	printf("Start Time = %s\tEnd Time = %s\n",date1,date2); 

}
