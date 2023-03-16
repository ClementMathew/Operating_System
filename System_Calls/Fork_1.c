
/* 
	Q2. Predict the output of the given C program: # include<stdio.h> # include<unistd.h> main() { int a=10; if(fork()==0) { a++; } printf("%d \n", a); } 
*/

 # include<stdio.h> 
 # include<unistd.h> 
 
 int main() 
 { 
 	int a=10; 
 	if(fork()==0) 
 	{ 
 		a++; 
 	} 
 	printf("%d \n", a); 
 } 
