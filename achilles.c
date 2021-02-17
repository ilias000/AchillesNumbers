
/*Douleuei swsta mazi me rand alla kanei 4.5 lepta gia thn fitra tou takh*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define COMPUTATIONS 10000000

int main()
{	
	printf("Program Started:\n");
	int count = 0;

	long curtime;
	curtime = 1572712634;//time(NULL);
	printf("Current time is %ld\n\n", curtime);
	srand((unsigned int) curtime);

	for(int i = 0; i < COMPUTATIONS ; i++)
	{
		int z,y,n;
		z = rand();
		y = rand();

		int x = ((y % 32768) + 1) * ((z % 32768) + 1) + 1;	
		n = x;

		int flagContinue = 0;
		int countFactors = 0; // count how many factors
		int hasFactor2 = 0;	// if the number has the factor 2
		int prPower = 0;	// the previus power that holds the gcd (gcd=MKD)
		int powerFactor2 = 0;	// the power of the factor 2
		int num = n ;
		//int n = num; //becsause we change the value of num later
		int m = num;




		

		while (n % 2 == 0)	// check if the n has the factor 2
		{  
			n /= 2; 
			powerFactor2++;
		}

		if (powerFactor2 == 1)	continue; // go to the next num cause power 1 canot be achilles
		if (powerFactor2 > 1)
		{
			countFactors++;
			hasFactor2 = 1;
		}

		int g = 1, result = 1; 
	    while (result <= n) 
	    { 
	      g++; 
	      result = g * g; 
	    } 
	    m = g - 1; 

		for (int factor = 3; factor <= m; factor += 2)	// check for all the factor from 3 AYTO ELEGXEI GIA OLOYS TOYS ARITHMOY KAI OXI MONO GIA PRWTOYS
		{ 
			int power = 0; 
			while (n % factor == 0)
			{ 
				n /= factor; 
				power++;
			}
			if (power == 0) 
			{ 
				continue;	// go to the next num cause power 1 canot be achilles
			}
			if (power == 1)
			{
				flagContinue = 1;	
				break;				// break the for so we can continue without checking the other factors  SPAI SIGOURA TH FOR AYTO 
			}
			countFactors++;	// if we reach till here it means that this factor exists
			if(hasFactor2 == 1)
			{							// if the hasFactor2 is 1 means we havent been here before so the prPower does not have a value so we put the power of the factor 2
				hasFactor2 =-1;
				prPower = powerFactor2;
			}else if (hasFactor2 == 0 && countFactors == 1)	//means there is no factor 2 and only one factor od the others so we keep his power
			{
				prPower = power;
			}
			if(countFactors >= 2) // IF ITS TRUE N COULD BE AN ACHILLES
			{
				int temp;
				int a = power;
				int b = prPower;
				while(b != 0) // AYTO TI VRISKEI
				{
					temp = a % b;
					a = b;
					b = temp;
				}
				prPower = a;
			} 
		} 

		if (flagContinue) continue;
		if (n != 1)	continue; // if (flagContinue || (n != 1) ) continue;
		if(prPower == 1){

			printf("%d is achilles \n",num);
			count++;
		}
	}
	printf("Found %d achilles numbers up to %d :\n",count,COMPUTATIONS);
	printf("Program Ended:\n");
	return 0;
}
