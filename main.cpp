#include <iostream>
#include <stdio.h>

using namespace std;

typedef union{
	float value;
	struct{
		unsigned long Mantissa: 23;
		unsigned int Expo: 8;
		unsigned int Sign: 1;
	};
	unsigned long dWord;
	unsigned short Word[2];
	unsigned char Bytes[4];
}floatStruct;

void floatDump(floatStruct *fstr){
	int i;
	if(fstr==NULL) return;
	cout<<"-------------------------"<<endl;
	printf(" +value: %f\n", fstr->value);
	printf(" +store dword: 0x%lX\n", fstr->dWord);
	printf(" +store word: 0x%04X 0x%04X\n", fstr->Word[0], fstr->Word[1]);
	printf(" +store bytes:");
	for(i=0;i<4;i++){
		printf("0x%02X ", fstr->Bytes[i]);
	}
	cout<<endl;
	cout<<" +IEEE store parts:"<<endl;
	printf("	Sign: %d\n", fstr->Sign);
	printf("	Expo: 0x%X\n", fstr->Expo);
	printf("	Mantissa: 0x%lX\n", fstr->Mantissa);
} 
int main(void) {
	floatStruct a;
	a.value = 4.345;
	for(int i=0;i<4;i++){
		printf("0x%02X ", a.Bytes[i]);
	}	
	floatStruct *pfloat;
	float x = 15.576;
	unsigned char bytes[] = {0x89, 0x01, 0x46, 0xC1};
	pfloat = (floatStruct*)(&x);
	floatDump(pfloat);
	pfloat = (floatStruct*)bytes;
	floatDump(pfloat);
	return 0;
}
