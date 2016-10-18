#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "convolve.h"

/**

Implements the convolution operation in C.
AUthor: Rajat Vadiraj Dwaraknath EE16B033.

*/

// Puts the output of f convolved with g into fcg. 
void convolve(double *f, double *g, double *fcg, int lenF, int lenG){
	
	// If f is smaller than g, call g convolve f instead.
	if(lenF<lenG){
		convolve(g,f,fcg,lenG,lenF);
		return;
	}
	
	int i,j;
	double sum = 0;
	
	for(i=0;i<lenF;i++){
		
		if(i<lenG/2 || i>lenF-lenG/2){
			fcg[i] = f[i];
		}
		else{
			sum = 0;
			for(j = 0;j<lenG;j++){
				sum += g[j]*f[i-lenG/2+j];
			}
			fcg[i] = sum;
		}

	}
	
	return;

}
