// a room conatains n no of people and 


// 1 what is no of peaople required at least to make sure that 100% two people have bday on same date

//366

// the probability of  two people among group has same probbaility




// 1- (365/364);


/* Unsorted Array 
					Unlike other Coders No logic at all !
															Find and run 

*/
#include<bits/stdc++.h>
using namespace std;
void calculateProb(int i)
{
	double val=1;
	for(int j=0;j<i;j++)
	{
		val = val*(365-j)/365;
	}
	printf("%0.12f",1-val);
}
int main()
{

		for(int i=5;i<=75;i+=5)
		{
			printf("%d ",i );
			calculateProb(i);
			cout<<endl;

		}


}

/*Unsorted Array 
			signing out  all hail !
									may the judge have mercy on your code 
																p.s @unsorted array no rights 		reserved */