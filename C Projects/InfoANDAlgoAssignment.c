#include <stdio.h>

int main() {
    float prA, prB, prC;	
	float prevA, prevB, prevC;

	int cA, cB, cC; //number of outlinks of each web page
	
	int N = 3; 		// number of web pages
	float d = 0.85; // constant value
	
	prA = prB = prC = 1.0/N;
	prevA = prevB = prevC = 0.0;
	
	cA = 2; 
	cB = 1; 
	cC = 2;

	for(int i = 0; i < 10; ++i)
	{
		prevA = prA;
		prevB = prB;
		prevC = prC;
		prA = (1-d)/N + d * (prevB/cB + prevC/cC); 
		prB = (1-d)/N + d * (prevA/cA + prevC/cC);
		prC = (1-d)/N + d * (prevA/cA);
	}
	
	printf("Values after 10 Iterations: A: %.3f \n B: %.3f \n C: %.3f \n", prA, prB, prC);

}