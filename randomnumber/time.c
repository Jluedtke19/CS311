#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <sys/timeb.h>


int currenttime(){
    struct timeval GetTimeStamp() {
	struct timeval tv;
    	gettimeofday(&tv,NULL);
    	return tv;
    }
}
    
