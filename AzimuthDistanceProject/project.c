#define _USE_MATH_DEFINES

#include <stdio.h>
#include <math.h>

#define EARTH_CIRCUM 40074.0

//http://www.krysstal.com/sphertrig.html

double findGreatCircle(double lat, double lon,char latD,char longD, double lat2, double lon2, char latD2, char longD2);
double findAzimuth(double lat, double lon,char latD,char longD, double lat2, double lon2, char latD2, char longD2,double distance);

int main()
{

    char line[256],name2[64];

    //Data
    char name[64];
    //City 1
    int lat_h, lat_m, lat_s,long_h, long_m, long_s;
    char lat_d,long_d;
    double lat, lon;

    //City 2
    int lat_h2, lat_m2, lat_s2,long_h2, long_m2, long_s2;
    char lat_d2,long_d2;
    double lat2, lon2;
    double distance,azimuth;

    FILE *fin = fopen("locations.txt", "r");
    FILE *fout = fopen("distances.txt","w");
    FILE *foutAzimuth = fopen("azimuth.txt","w");

    int n = 0;

    while (NULL != fgets(line, 256, fin)) {
        sscanf(line, "%[^=]=%*[ ]%d:%d:%d%*[ ]%c%*[ ]%d:%d:%d%*[ ]%c \
					  %[^=]=%*[ ]%d:%d:%d%*[ ]%c%*[ ]%d:%d:%d%*[ ]%c",
               name,
               &lat_h, &lat_m, &lat_s, &lat_d,
               &long_h, &long_m, &long_s, &long_d,
               name2,
               &lat_h2, &lat_m2, &lat_s2, &lat_d2,
               &long_h2, &long_m2, &long_s2, &long_d2
              );

        //Degree + (Minute/60) + (Seconds/3600)
        lat = lat_h+(lat_m/60.0)+(lat_s/3600.0);
        lon = long_h+(long_m/60.0)+(long_s/3600.0);

        lat2 = lat_h2+(lat_m2/60.0)+(lat_s2/3600.0);
        lon2 = long_h2+(long_m2/60.0)+(long_s2/3600.0);

        distance = findGreatCircle(lat,lon,lat_d,long_d,lat2,lon2,lat_d2,long_d2);
        azimuth = findAzimuth(lat,lon,lat_d,long_d,lat2,lon2,lat_d2,long_d2,distance);

        if (distance != 20014.0) {
            distance = EARTH_CIRCUM * distance/360.0;
        }

        fprintf(foutAzimuth,"[City 1: %s][City 2: %s][Azimuth: %f]\n",name,name2,azimuth);
        fprintf(fout,"%d %s %s %f\n",n++,name,name2,distance);

    }

    fclose(fin);
    fclose(fout);
    printf("\n");

    return 0;
}

//lat and lat2 are latitude
//lon and lon2 are longitude
double findGreatCircle(double lat, double lon,char latD,char longD, double lat2, double lon2, char latD2, char longD2)
{
    double A,b,c;
    double distRad,distDeg;

    if (lat == 90 && lon == 0 && lat2 == 90 && lon2 == 0 && latD != latD2) {
        return 20014.0;
    }

    if (longD != longD2) {
        A = lon2+lon;
    } else {
        A = lon2-lon;
    }

    if (latD == 'S') {
        b = 90.0+lat;
    } else {
        b = 90.0-lat;
    }

    if (latD2 == 'S') {
        c = 90.0+lat2;
    } else {
        c = 90.0-lat2;
    }


    //convert to radians for trig functions
    A = A * (M_PI/180.0);
    b = b * (M_PI/180.0);
    c = c * (M_PI/180.0);

    distRad = cos(b)*cos(c)+sin(b)*sin(c)*cos(A);
    distRad = acos(distRad);
    distDeg = distRad*(180/M_PI);

    return distDeg;
}

double findAzimuth(double lat, double lon,char latD,char longD, double lat2, double lon2, char latD2, char longD2,double distDeg) {

    double azimuth,distRad,A,c;

    if (longD != longD2) {
        A = lon2+lon;
    } else {
        A = lon2-lon;
    }
    if (latD == 'S') {
        c = 90+lat;
    } else {
        c = 90-lat;
    }

    //convert to radians for trig functions
    A = A * (M_PI/180.0);
    c = c * (M_PI/180.0);

    distRad = distDeg *(M_PI/180);

    azimuth = sin(A)*sin(c)/sin(distRad);
    azimuth= asin(azimuth);
    azimuth = azimuth * (180/M_PI);

    return azimuth;
}