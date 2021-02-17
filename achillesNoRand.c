#include <stdio.h>
#include <stdlib.h>      /* Header file for srand and rand functions */
#include <time.h>        /* Header file for time function */
#define COMPUTATIONS 10000000

int main()
{	
	printf("Program Started with your sqrt:\n");
	int achillesCounter = 0;

	long curtime;
	curtime = 1572712634;//time(NULL); // Current time (in seconds since 1/1/1970)
  	printf("Current time is %ld\n\n", curtime);
  	srand((unsigned int) curtime); // Seed for random number generator

	for(int i=0; i < COMPUTATIONS; i++)
	{

		int num,y,z;
		y = rand();
		z = rand();
		num =  ((y % 32768) + 1) * ((z % 32768) + 1) + 1;

		// countFactors : count how many factors
		// hasFactor2 : if the number has the factor 2
		// prPower : the previus power that holds the gcd (gcd=MKD)
		// powerFactor2 : the power of the factor 2
		// n = num : becsause we want to use the value of num with out losing it 
		int flagContinue = 0, countFactors = 0, hasFactor2 = 0, prPower = 0, powerFactor2 = 0, n = num;

		while (n % 2 == 0)	// check if the n has the factor 2
		{  
			n /= 2; 
			powerFactor2++; // the power of factor 2
		}
		if (powerFactor2 == 1)	continue; // go to the next num cause power 1 canot be achilles
		if (powerFactor2 > 1)
		{
			countFactors++;	// because num has 2 as a factor powerFactor2 times
			hasFactor2 = 1;
		}
		//finding the number that the square of that number is equal to num
		int temp=1, sqrtOfNum = 1; 
		do // num is >= 1 so we dont have any problem
		{ 
		  sqrtOfNum++; 
		  temp = sqrtOfNum * sqrtOfNum; 
		} while (temp < n);
		for (int factor = 3; factor <= sqrtOfNum; factor += 2)	// check for all the factor from 3
		{ 
			int power = 0; 
			while (n % factor == 0) // check if the num has the factor variable:factor  
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
				break;				// break (end) the for so we can continue without checking the other factors to the next number
									// because if the number has a factor that has not power>1 it is not achilles 
			}
			countFactors++;	// if we reach till here it means that this factor exists
			if(hasFactor2 == 1)
			{							// if the hasFactor2 is 1 means we havent been here before so the prPower does not have a value so we put the power of the factor 2
				hasFactor2 =-1;
				prPower = powerFactor2;
			}else if (hasFactor2 == 0 && countFactors == 1)	// means there is no factor 2 and only one factor od the others so we keep his power
			{
				prPower = power;
			}
			if(countFactors >= 2) // if its true num could be an achilles
			{
				int temp;
				int p = power;
				int pr = prPower;
				while(pr != 0) // MKD 
				{
					temp = p % pr;
					p = pr;
					pr = temp;
				}
				prPower = p;
			} 
		} 
		if (flagContinue || (n != 1) ) continue; // because if flagContinue its true it means that power of the factor was 1 so it is not achille
		if(prPower == 1) // MKD=1
		{
			printf("%d is achilles \n",num);
			achillesCounter++;
		}
	}
	printf("Found %d Achilles out of %d tested numbers\n",achillesCounter,COMPUTATIONS);
	printf("Program Ended\n");
	return 0;
}
