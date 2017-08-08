/* Unsorted Array 
		Unlike other Coders No logic at all !
											Find and run 

															*/
#include <bits/stdc++.h>
using namespace std;
void permute(string str, int l, int r)
{
   int i;
   if (l == r)
     cout<<"\n"<<str;
 	 // for(strig :: iterator = it.begin()=str.rbegin();)
   else
   {
       for (i = l; i <= r; i++)
       {
          swap(str[l],str[i]) ;//(swap((a+l), (a+i));
          permute(str, l+1, r);
          swap(str[l],str[i]);
       }
   }
}

void allpalindrome(string str)
{
	int l = str.length();
	char mid ;
	if(l%2)
	{
		mid = str[l/2];
	}
	str.resize(str.length() /2);

	
	sort(str.begin(),str.end());
	cout<<str;
	if(mid)
	{
		cout<<mid;
	}

	//permuations of  a string 
	permute(str,0,l/2-1);

}
int main()
{

	string s;
	cin>>s;

	allpalindrome(s);


}

/*Unsorted Array 
			signing out  all hail !
									may the judge have mercy on your code 
																p.s @unsorted array no rights 		reserved */