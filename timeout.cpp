#include <iostream>
#include <ctime>
#include <windows.h>
#include <conio.h>
using namespace std;

int main(){
	
	double timeout = 5;
	char a;
	int cicles = 0;
	
	while (true){
		
		cout << "cicle n " << cicles << endl;
		
		clock_t start;
		start = clock();
	
		while ((( std::clock() - start ) / (double) CLOCKS_PER_SEC) <= timeout){
			
			if(kbhit()){
				
				a = _getch();
				cout << a << endl;
				break;
				
			}
			
		}
		
		cicles++;
		
	}
	
}
