#include <stdio.h>
#include <math.h>
int main()
{
 const int IP1[64]={58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7};
 const  int IP2[64]={40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25};
  const int EX[48] ={32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1};
  const int P[32] ={16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};
  const int PC1[56]= {57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4};
  const int PC2[48] ={14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32};
  const int S1[4][16]= {
                   {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
				   {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
				   {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
				   {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
                  };
  const int S2[4][16] ={
				   {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
				   {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
				   {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
				   {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
				  };
  const int S3[4][16] ={
				  {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
				  {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
				  {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
				  {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
				  };
  const int S4[4][16] ={
				  {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
				  {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
				  {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
				  {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
				  };
  const int S5[4][16] ={
				  {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
				  {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
				  {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
				  {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
				  };
  const int S6[4][16] ={
				  {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
				  {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
				  {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
				  {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
                  };
 const  int S7[4][16] ={
				  {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
				  {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
				  {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
				  {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
				  };
  const int S8[4][16] ={
				  {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
				  {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
				  {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
				  {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
				  };
int ming[64] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 int M[18][64]={0};
 int J[64]={0};
 int K[17][56]={0};
 int Key[17][48]={0};
 int i;
 int j;
 int ex[48]={0};
 int b[48]={0};
 int x[8]={0};
 int mid[32]={0};
 int mid1[32]={0};
 int KEY[64]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  for (i=0;i<=63;i++)
  {
	  M[0][i]=ming[IP1[i]-1];
	  printf("%d",M[0][i]);
  }
  printf("\n");
  for (i=0;i<=55;i++)
  K[0][i]=KEY[PC1[i]-1];
  for(i=1;i<=16;i++)
      if (i==1||i==2||i==9||i==16)
	{
		for (j=0;j<=55;j++)
			K[i][j]=K[i-1][(j-1+56)%56];
		for (j=0;j<=47;j++)
			Key[i][j]=K[i][PC2[j]-1];
	}
	else
	{
		for (j=0;j<=55;j++)
			K[i][j]=K[i-1][(j-2+56)%56];
		for (j=0;j<=47;j++)
			Key[i][j]=K[i][PC2[j]-1];
	}
   for (i=1;i<=6;i++)
   {
	for (j=0;j<=47;j++)
		ex[j]=M[i-1][EX[j]-1+32];
	for (j=0;j<=47;j++)
         b[j]=(ex[j]+Key[i][j])%2;
    for (j=0;j<=42;j=j+6)
	  switch (j/6+1)
	  {
	  case 1:
		  x[0]=S1[2*b[j]+b[j+5]][8*b[j+1]+4*b[j+2]+2*b[j+3]+b[j+4]]; break;
	  case 2:
		  x[1]=S2[2*b[j]+b[j+5]][8*b[j+1]+4*b[j+2]+2*b[j+3]+b[j+4]]; break;
	  case 3:
		  x[2]=S3[2*b[j]+b[j+5]][8*b[j+1]+4*b[j+2]+2*b[j+3]+b[j+4]]; break;
	  case 4:
		  x[3]=S4[2*b[j]+b[j+5]][8*b[j+1]+4*b[j+2]+2*b[j+3]+b[j+4]]; break;
	  case 5:
		  x[4]=S5[2*b[j]+b[j+5]][8*b[j+1]+4*b[j+2]+2*b[j+3]+b[j+4]]; break;
	  case 6:
		  x[5]=S6[2*b[j]+b[j+5]][8*b[j+1]+4*b[j+2]+2*b[j+3]+b[j+4]]; break;
      case 7:
		  x[6]=S7[2*b[j]+b[j+5]][8*b[j+1]+4*b[j+2]+2*b[j+3]+b[j+4]]; break;
	  case 8:
		  x[7]=S8[2*b[j]+b[j+5]][8*b[j+1]+4*b[j+2]+2*b[j+3]+b[j+4]]; break;
	  }
     for (j=0;j<=28;j=j+4)
	 {
	  mid[j+3]=x[j/4]%2;
      mid[j+2]=((x[j/4]-mid[j+3])%4)/2;
	  mid[j+1]=((x[j/4]-2*mid[j+2]-mid[j+3])%8)/4;
	  mid[j]=(x[j/4]-4*mid[j+1]-2*mid[j+2]-mid[j+3])/8;
	 }
      for (j=0;j<=31;j++)
	  mid1[j]=mid[j];
	 for (j=0;j<=31;j++)
        M[i-1][j]=(M[i-1][j]+mid1[j])%2;
        if (i!=16)
     for (j=0;j<=63;j++)
	 {
	 	 M[i][j]=M[i-1][(j+32)%64];
         printf("%d",M[i][j]);
	 }
	 else
        for (j=0;j<=63;j++)
	 {
	 	 M[16][j]=M[15][j];
         printf("%d",M[16][j]);
	 }
	 printf("\n");
   }
   getchar();
   return 0;
}
