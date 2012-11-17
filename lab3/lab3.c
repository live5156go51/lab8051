#include <REGX51.H>
/*
		* * * *
		* * * *
		* * * *
		* * * *
*/
unsigned char delay(unsigned char a);
unsigned char code LED[]={0x3F,0x06,0x5B,0x4F,
													0x66,0x6D,0x7D,0x07,
													0x7F,0x6F,0x77,0x7C,
													0x39,0x5E,0x79,0x7E};
int main(void)
{
	unsigned char havekey;
	P3=0x00;
	P2=0xf0;
	while(1){
		//P2=0xf7;
		havekey=(P2^0xf0);// 是否有按下
		if(havekey){
			P2=0xf7
		}
		else
			return 0;
	}
}

unsigned char delay(unsigned char a) //10ms <-> 12MHz
{
	unsigned int i;
	unsigned char b;
	for(b=0;b<a;b++){
		for(i=0;i<=1940;i++);
	}
	return 0;
}
