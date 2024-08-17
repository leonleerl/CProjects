#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//  THE FOLLOWING 3 LINES ARE REQUIRED TO GET ACCESS TO  M_PI  UNDER Linux
#if defined(__linux__)
#define __USE_XOPEN
#endif

#include <math.h>

//  written by Chris.McDonald@uwa.edu.au
//
//  compile:  cc -std=c11 -Wall -Werror -o haversine haversine.c -lm
//  run:      ./haversine lat0 lon0 lat1 lon1
//  e.g.      ./haversine -31.977537 115.816509 -31.982831 115.818898

#define EARTH_RADIUS_IN_METRES 6372797

#define MIN_LAT -90.0
#define MAX_LAT 90.0
#define MIN_LON -180.0
#define MAX_LON 180.0

struct point
{
    double lat;
    double lon;
};

double degrees_to_radians(double degrees)
{
    return (degrees * M_PI / 180.0);
}

bool valid_location(struct point location)
{
    if (location.lat >= MIN_LAT && location.lat <= MAX_LAT &&
        location.lon >= MIN_LON && location.lon <= MAX_LON)
    {
        return true;
    }
    printf("location %f,%f is invalid!\n", location.lat, location.lon);
    return false;
}

double haversine(struct point location1, struct point location2)
{
    double deltalat = (location2.lat - location1.lat) / 2.0;
    double deltalon = (location2.lon - location1.lon) / 2.0;

    double sin1 = sin(degrees_to_radians(deltalat));

    double cos1 = cos(degrees_to_radians(location1.lat));
    double cos2 = cos(degrees_to_radians(location2.lat));

    double sin2 = sin(degrees_to_radians(deltalon));

    double x = sin1 * sin1 + cos1 * cos2 * sin2 * sin2;

    return (2.0 * EARTH_RADIUS_IN_METRES * asin(sqrt(x))); // in metres
}

int main(int argc, char *argv[])
{
    int result = EXIT_FAILURE;

    //  CHECK THE NUMBER OF ARGUMENTS
    if (argc != 5)
    {
        printf("Usage: %s lat1 lon1 lat2 lon2\n", argv[0]);
    }
    else
    {
        //  CONVERT EACH COMMAND-LINE ARGUMENT TO A FLOATING-POINT (double) NUMBER
        struct point location1;
        struct point location2;

        location1.lat = atof(argv[1]);
        location1.lon = atof(argv[2]);

        location2.lat = atof(argv[3]);
        location2.lon = atof(argv[4]);

        //  ENSURE THAT THE 2 PROVIDED LOCATIONS ARE EACH VALID
        if (valid_location(location1) && valid_location(location1))
        {
            printf("haversine distance = %im\n", (int)haversine(location1, location2));
            result = EXIT_SUCCESS;
        }
    }
    return result;
}
