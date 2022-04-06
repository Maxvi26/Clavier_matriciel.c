#include <stdio.h>
#include <stdlib.h>

void tempo10ms(unsigned short i);
unsigned char scrutation_clavier(void);
unsigned char Transcodage(unsigned char code_Touche);
unsigned char Saisie_Code_clavier (void);


void main(void)
{
	unsigned char la;
	while(1)
	{
    	la = Saisie_Code_clavier ();
    	printf("Le code est %hd\n",la);

	}
}


unsigned char scrutation_clavier(void)
{
	unsigned char i;
	unsigned char code_Touche = 0xFF;
	P4 = 0b11101111;
	for(i=0;((i<4)&&(code_Touche==0xFF));i++)
	{
		if ( ((P4&(1<<0)) == 0x00)||((P4&(1<<1)) == 0x00)||((P4&(1<<2)) == 0x00)||((P4&(1<<3)) == 0x00) )
		{
				code_Touche = P4;
				i=4;
		}
		else
		{
				P4 = P4 <<1;
				P4 = P4|(1<<0);
		}
	}
	return code_Touche;
}

unsigned char Transcodage(unsigned char code_Touche)
{
	unsigned char i;
	unsigned char code_reel = 0xFF;
	unsigned char Tab_Code_Touche[16]={0x7D,0xEE,0xED,0xEB,0xDE,0xDD,0xDB,0xBE,0xBD,0xBB,0x7E,0x7B,0x77,0xB7,0xD7,0xE7};

	for(i=0;((i<16)&&(code_reel==0xFF));i++)
	{
		if (Tab_Code_Touche[i]== code_Touche)
		{
				code_reel = i;
		}
		else
		{}
	}
	return code_reel;
}

void tempo10ms(unsigned short i)
{
		unsigned short k,j;
		for ( j=0 ; j<i;j++)
		{
			for(k=0; k<4950;k++)
			{
			}
		}
}

unsigned char Saisie_Code_clavier (void)
{
    unsigned char var,nb,i,code_saisi;
        for( i=0 ; i<4; i++)
    {
        printf("Saisir touche\n");
        var = scrutation_clavier();
        tempo10ms(50);
        nb = Transcodage (var);
        if (var == 0xFF)
		{}
		else
		{
				printf("Touche saisie %hd\n",nb);
		}
		code_saisi = var;
    }
return code_saisi;
}
