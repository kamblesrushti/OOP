#include<iostream>
using namespace std;

int main()
{
	int num1=5;
	int num2=6;
	int num3=3;
	
    
    if(num1>num2 && num1>num3)
    {
    	printf("The largest number is %d\n",num1);
	}
      if(num2>num1&& num2>num3)
	  {
      	printf("The largest number is %d\n",num2);
	  }
	  else {
	  	printf("The largest number is %d\n",num3);
	  }
    
}
