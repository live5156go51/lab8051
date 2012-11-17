#include <REGX51.H>

sbit key=P1^0;

unsigned char delay(unsigned char a);

unsigned char num_led;
unsigned char P_tmp0,P_tmp1;
	
void main(void)
{
	P0=0xff;

	while(1){
		if(key==0){
			delay(1);//10ms
			if(key==0){
				P0=~P0;
			}
			delay(50);
			if(key==0){
				P0=0xfe;
				delay(50);
				for(num_led=0;num_led<7;num_led++){
							P_tmp0=(P0<<1);
							P_tmp1=(P0>>(7-num_led)); 
							P0=(P_tmp0 | P_tmp1);// left shift 1bit
							delay(50);
				}
				delay(50);
				P0=0xff;
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