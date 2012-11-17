#include <REGX51.H>
unsigned char delay(unsigned char a);
sbit ADD_LED=P3^2;
sbit DEC_LED=P3^3;
unsigned char i=0;

unsigned char code LED[]={0xC0, 0xF9, 0xA4, 0xB0,//;0, 1, 2, 3 
										 0x99,  0x92,  0x82, 0xF8, //;4, 5, 6, 7
										 0x80,  0x90,  0x88,  0x83, //;8, 9, A, B
										 0xC6, 0xA1,  0x86,  0x8E};//;C, D, E, F
void main(void)
{
	P1=0x01;
	P2=0xff;
	P2=LED[i];
	while(1){
    P1=0x01;
		if(ADD_LED==0){
			delay(15);
			if(ADD_LED==0){
				P2=LED[(i++)+1];
				if(i>=15){
					P2=LED[15];
					i=14;
				}
			}
		}
		else if(DEC_LED==0){
			delay(15);
			if(DEC_LED==0){
				if(i==0){
					P2=LED[i];
					i=0;
				}
				else
					P2=LED[i--];
			}
		}
	}
}

unsigned char delay(unsigned char a) // 10ms <-> 12Mhz
{
	unsigned int i;
	unsigned char b;
	for(b=0;b<a;b++){
		for(i=0;i<=1940;i++);
	}
	return 0;
}