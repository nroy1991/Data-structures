
#include<bits/stdc++.h> 
using namespace std; 
#define R 5 
#define C 4 


bool isValid(int x, int y1, int y2) 
{ 
	return (x >= 0 && x < R && y1 >=0 && 
			y1 < C && y2 >=0 && y2 < C); 
} 

int getMaxUtil(int arr[R][C], int mem[R][C][C], int x, int y1, int y2) 
{ 
	
	if (!isValid(x, y1, y2)) return INT_MIN; 


	if (x == R-1 && y1 == 0 && y2 == C-1) 
	return (y1 == y2)? arr[x][y1]: arr[x][y1] + arr[x][y2]; 

	
	if (x == R-1) return INT_MIN; 


	if (mem[x][y1][y2] != -1) return mem[x][y1][y2]; 

	
	int ans = INT_MIN; 

	
	int temp = (y1 == y2)? arr[x][y1]: arr[x][y1] + arr[x][y2]; 

	
	ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1, y2-1)); 
	ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1, y2+1)); 
	ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1, y2)); 

	ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1-1, y2)); 
	ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1-1, y2-1)); 
	ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1-1, y2+1)); 

	ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1+1, y2)); 
	ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1+1, y2-1)); 
	ans = max(ans, temp + getMaxUtil(arr, mem, x+1, y1+1, y2+1)); 

	return (mem[x][y1][y2] = ans); 
} 


int geMaxCollection(int arr[R][C]) 
{ 
	
	int mem[R][C][C]; 
	memset(mem, -1, sizeof(mem)); 

	return getMaxUtil(arr, mem, 0, 0, C-1); 
} 


int main() 
{ 
	int arr[R][C] = {{3, 6, 8, 2}, 
					{5, 2, 4, 3}, 
					{1, 1, 20, 10}, 
					{1, 1, 20, 10}, 
					{1, 1, 20, 10}, 
					}; 
	cout << "Maximum collection is " << geMaxCollection(arr); 
	return 0; 
} 
