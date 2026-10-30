#include"stdio.h"
#include"string.h"
#include"stdlib.h"
#include"ctype.h"
#include"math.h"
#define arm_a 1
#define arm_d 1
#define arm_ac 1
#define arm_t 1
#define bp3d 1
#define  total_cons 3

//#define LENGTH 73

int arma,armd,armac,armt,bp_3;

int no=1,LENGTH;

int check_bond1(char a, char b)
{
	
	int c=0;
	if((a=='a'&&b=='t')||(a=='t'&&b=='a')||(a=='g'&&b=='c')||(a=='c'&&b=='g'))c=1;
	else if((a=='t'&&b=='g')||(a=='g'&&b=='t')) c=1;
	else if((a=='a'&&b=='a')||(a=='g'&&b=='g')||(a=='t'&&b=='t')||(a=='c'&&b=='c'))c=2;
	else if((a=='c'&&b=='a')||(a=='a'&&b=='c')) c=2;
	else if((a=='c'&&b=='t')||(a=='t'&&b=='c')) c=2;
	else if((a=='g'&&b=='a')||(a=='a'&&b=='g')) c=2;
    return(c);
}




int math_1str_4th(char *p,char* q,char *p1,char *q1)
{
	int week_const;
	int i,l,j=8,k,flag;
    

    while(j<=12)
	
	{
		for(i=strlen(p)-1;i>=j-1;--i)
		{
		for(l=0;l<strlen(q)-j;++l)
		{
				week_const=1;flag=0;
			for(k=0;k<j;++k)
			{
				if(check_bond1(p[i-k],q[l+k])==0){flag=1;break;}
			if(check_bond1(p[i-k],q[l+k])==2)
			{
				week_const--;if(week_const<0){flag=1;break;}
			}
			}
			if(flag==0)
			{
				if(j<=9&&week_const==1)
				{ for (k=0;k<j;k++)
				{p1[j-k-1]=p[i-k];q1[k]=q[l+k];}
				p1[k]=q1[k]='\0';
					return 1;
				}
			if(j>9&&week_const==0)
				{ for (k=0;k<j;k++)
				{p1[j-k-1]=p[i-k];q1[k]=q[l+k];}
				p1[k]=q1[k]='\0';
					return 1;
				}
			}
		}
		}
		j++;
	}
	return 0;
}




int bh_loop(char *p,char *q)
{
	int week_const;
	int i,l,j=0,k,flag=0; 

	i=0;l=2;
	
	for(k=0;k<4;++k)
		{
			if(check_bond1(p[i+k],q[l+k])==1){flag++;}
			
		}
	
	if(flag<3)return 0;
	else
	{
		l=6;
		for(i=7;i<8;++i)
		{
			flag=0;
			for(k=0;k<4;++k)
		
			if(check_bond1(p[i+k],q[l+k])==1){flag++;}
			
		
			if(flag>=3)return 2;
		}
	}

return 0;
	
}	
	
	








int check_bond(char a, char b)
{
	
	int c=0;
	if((a=='a'&&b=='t')||(a=='t'&&b=='a')||(a=='g'&&b=='c')||(a=='c'&&b=='g'))c=1;
	else if((a=='t'&&b=='g')||(a=='g'&&b=='t')) c=1;
	else if((a=='a'&&b=='a')||(a=='g'&&b=='g')||(a=='t'&&b=='t')||(a=='c'&&b=='c'))c=2;
	else if((a=='c'&&b=='a')||(a=='a'&&b=='c')) c=2;
	else if((a=='c'&&b=='t')||(a=='t'&&b=='c')) c=2;
	else if((a=='g'&&b=='a')||(a=='a'&&b=='g')) c=2;
    return(c);
}


int check3dbp(char *bp,int a,int b,int c,int d)
{
	int bp3=bp3d;
	arma=armd=armac=armt=0;

	if(check_bond(bp[7],bp[13])==2)	bp3--;
	if(check_bond(bp[14],bp[47])==2)	bp3--;
	if(check_bond(bp[17],bp[54])==2)	bp3--;
	if(check_bond(bp[18],bp[55])==2)	bp3--;
	if(check_bond(bp[25],bp[43])==2)	bp3--;
	if(check_bond(bp[31],bp[37])==2)	bp3--;
	if(check_bond(bp[53],bp[57])==2)	bp3--;

	if(bp3<0)return 0;
	else 
	{
		if(a+b+c+d+(bp3d-bp3)<=total_cons)
		{
			arma=a;armd=b;armac=c;armt=d;bp_3=bp3d-bp3;;
			return 1;
		}
		else return 0;
	}
}





int check_first(char *p,int l)
{

int i,j,k,arm_for_a=arm_a,m,flag,c,n;
if(p[7]!='t')return 0;

//if(p[15]!='g'&&p[16]!='g'&&p[17]!='g'&&p[18]!='g')return 0;

//if(! ((p[15]!='g'&&p[16]!='g')||(p[15]!='g'&&p[16]!='a')||(p[15]!='g'&&p[16]!='c'))return 0;

//if(! ((p[16]!='g'&&p[17]!='g')||(p[16]!='g'&&p[17]!='a')||(p[16]!='g'&&p[17]!='c'))return 0;
//if(! ((p[17]!='g'&&p[18]!='g')||(p[17]!='g'&&p[18]!='a')||(p[17]!='g'&&p[18]!='c'))return 0;

//if(! ((p[18]!='g'&&p[19]!='g')||(p[18]!='g'&&p[19]!='a')||(p[18]!='g'&&p[19]!='c'))return 0;


//if(p[l-4]!='c'&&p[l-4]!='t')return 0;


//put j=0 if you want to take 9 absent position, otherwise put j=1;


for(j=1;j<2;++j)
{
	

	
		
		
		for(k=0;k<5;++k)
		{
		  
			m=0;flag=0;n=14;arm_for_a=arm_a;
		   for(i=8+j;i<8+j+4;++i)
		   {
				
			c= check_bond(p[i+n+k-m],p[i]);
			if(c==0){flag=0;break;};
		//	printf("c=%d\n",c);getch();
			flag=1;
			   if( c==2)
			   {		
				arm_for_a--;if(arm_for_a<0){flag=0;break;}
			   }
		  
			  m++;n--;
		   }
		   if(flag==1){//printf("OK k=%d\n",k);getch(); 
		   
			   
			   if(k<3)
			   
			   for(i=0;i<=k;++i)
			   
			   {
				   if((p[15+j+i]=='g'&&p[15+j+i+1]=='g'))
					   //if(p[k+11+8+j+14-3]=='t')return k+11+8+j+14+1;//32 position is 't' only

					   if(p[k+11+8+j+14-3]=='c'||p[k+11+8+j+14-3]=='t')return k+11+8+j+14+1+1;
				   
				   //remove // if 18 &19 position are 'ga' or 'gc'
				  // if(p[15+j+i]=='g'&&p[15+j+i+1]=='a')if(p[k+11+8+j+14-3]=='c'||p[k+11+8+j+14-3]=='t')return k+11+8+j+14+1+1;
				  // if((p[15+j+i]=='g'&&p[15+j+i+1]=='c'))if(p[k+11+8+j+14-3]=='c'||p[k+11+8+j+14-3]=='t')return k+11+8+j+14+1+1;
			   }

			   			  
			   else
			   {
				   for(i=k-2;i<3;++i)
			   {
				   if((p[15+j+i]=='g'&&p[15+j+i+1]=='g'))
					  // if(p[k+11+8+j+14-3]=='t')return k+11+8+j+14+1;//32 position is 't' only
					   if(p[k+11+8+j+14-3]=='c'||p[k+11+8+j+14-3]=='t')return k+11+8+j+14+1+1;
				   
				   //remove // if 18 &19 position are 'ga' or 'gc'
				    //if(p[15+j+i]=='g'&&p[15+j+i+1]=='a')if(p[k+11+8+j+14-3]=='c'||p[k+11+8+j+14-3]=='t')return k+11+8+j+14+1+1;
				    //if((p[15+j+i]=='g'&&p[15+j+i+1]=='c'))if(p[k+11+8+j+14-3]=='c'||p[k+11+8+j+14-3]=='t')return k+11+8+j+14+1+1;
				   
			   }
			   }


			   flag=0;
			   
			   }
}}



if(flag==0)return 0;



//return 1;

}


int check_2nd(char *p)
{
int i,j,arm_for_t=arm_t,c;

if(p[19]!='g')return 0;
if(p[18]!='a'&&p[18]!='t')return 0;
if(p[16]!='c')return 0;
if(p[11]!='c')return 0;

j=23;
for( i=7;i<12;++i)

{	
	c=check_bond(p[j],p[i]);
	if( c==0){return 0;};//T -arm
			
	if( c==2)
	{		
			arm_for_t--;if(arm_for_t<0){return 0;}
	}
j--;
}
		





return 1;
}








int build_trna_cg(char *p,int l1,char mat[32][80],char *anticodon, char *bp,char *a_arm,char *d_arm,char *ac_arm,char *t_arm)
{
	int i=0,j,k,m,n,u,v,w,x,l=0,flag=0,m1,u1,n1,w1,x1,i1,i2,m2,u2,n2,w2,x2;
	int  arm_for_a=arm_a,arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;
	u=0;j=0;
	//printf("%s\n",p); getch();
	while(i<7)
	{
		v=14;//printf("OK\n");printf("%c %c\n",p[i],p[l-i-1]);
		if( check_bond(p[i],p[l1-i-1])==0)return 0; // A - arm
		 
		mat[u][v++]=a_arm[j++]=p[i];
		
		if(check_bond(p[i],p[l1-i-1])==1)
		mat[u][v++]='-';
		else 
		{
			mat[u][v++]='+';
			arm_for_a--;if(arm_for_a<0)return 0;
		}
		mat[u++][v]=a_arm[j++]=p[l1-i-1];
		i++;
	}

	w=w1=w2=u-1;

	if(p[i]!='t')return 0;
	bp[7]=p[i];bp[8]=p[i+1];
	mat[u++][13]=p[i];
	mat[u++][12]=p[i+1];
	
	n=n1=n2=l1-i-1;

	x=x1=x2=i+5;
	u1=u2=u;
	m2=i;
    j=0;
	i=i1=18;
    
	/*i=n-16;
	printf("p[%d]=%c\n",i+4,p[i+4]);
	printf("p[%d]=%c\n",i+5,p[i+5]);
	printf("p[%d]=%c\n",i+7,p[i+7]);
	printf("p[%d]=%c\n",i+12,p[i+12]);

		printf("p[%d]=%c\n",m+8,p[m+8]); getch();*/
	
	
	
	while(i1>15)

{	
		
		i=i1;u=u1=u2;w=w1=w2;m=m1=m2;n=n1=n2;x=x1=x2;l=0;v=11;
		arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;
		
		
		
		
		
		if((p[i+1]=='c')&&p[i]=='g')//17='g' does not exist 
		{
			
		
			//printf("i=%d\n",i);getch();
			for(i2=u;i2<32;i2++)
for(j=0;j<80;++j)
mat[i2][j]=' ';	

//bp[17]=p[i];bp[18]=p[i+1];
	
	//if(j==3)return 0;
	m=m1=i;
	i+=7;//rintf("%d\n",i);
	

	j=0;k=m2+2;//v=11;u1=u;
	//printf("Ok %d \n",i); getch();
	while(j<4)
	{
	
		//printf("OK\n");printf("%c %c\n",p[i],p[k]);
		

		if( check_bond(p[k],p[i])==0){flag=1;break;} // D - arm with 20
		
		mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else {
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0){flag=1;break;}
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		
		i--;k++;j++;
	
	}


if(flag!=1)
{
bp[20]=p[i];

j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];bp[17]=p[i1];bp[18]=p[i1+1];
   
   
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;//printf("i=%d\n",i);getch();
	j=0;
	k=n;


	if(p[i+4]!='g'){flag=1;}
	if(p[i+5]!='t'&&p[i+5]!='a'){flag=1;}
	if(p[i+7]!='c'){flag=1;}
	if(p[i+12]!='c'){flag=1;}

	
//printf("p[%d]=%c\n",i+4,p[i+4]);
//	printf("p[%d]=%c\n",i+5,p[i+5]);
//	printf("p[%d]=%c\n",i+7,p[i+7]);
//	printf("p[%d]=%c\n",i+12,p[i+12]);
//getch();


if(flag!=1)
{
    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0){flag=1;break;};//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0){flag=1;break;}
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
}
if(flag!=1)
{
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   


x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%c %c\n",p[i],p[k]);
		
		if( check_bond(p[k],p[i])==0){flag=1;break;}//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0){flag=1;break;}
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	}
	


	mat[u++][v-1]=bp[31]=p[i++];
	//printf("m=%d\n",m);getch();
	
	if(p[m+8]!='t'&&p[m+8]!='c'){flag=1;}
	//printf("p[%d]=%c\n",m+8,p[m+8]); getch();

}
	if(flag!=1)
	{
		bp[32]=p[m+8];

	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{if(u<0)flag=1;
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}

	
//printf("17 a\n");





if(flag!=1)

if(check3dbp(bp,arm_a-arm_for_a,arm_d-arm_for_d,arm_ac-arm_for_ac,arm_t-arm_for_t))	return 1;
else return 0;

}
	}



if(flag==1)
{
	  
	arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;
	u=u1;w=w1;m=m1;n=n1;x=x1;l=0;

	
	
	for(i=u;i<32;i++)
for(j=0;j<80;++j)
mat[i][j]=' ';


	i=m+8;v=11;	
	    j=0;k=m2+2;l=0;
	     while(j<4)
	{
	
		//printf("OK\n");printf("%c %c\n",p[i],p[k]);
		

		if( check_bond(p[k],p[i])==0){flag=2;break;} // D - arm with 20A
		
		mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else {
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0){flag=2;break;}
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		
		i--;k++;j++;
	
	}

	



if(flag!=2)
{
bp[20]=p[i];
j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];//bp[17]=bp[18]='g';
   
   bp[17]=p[i1];bp[18]=p[i1+1];
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;
	j=0;
	k=n;


	if(p[i+4]!='g'){flag=2;}
	if(p[i+5]!='t'&&p[i+5]!='a'){flag=2;}
	if(p[i+7]!='c'){flag=2;}
	if(p[i+12]!='c'){flag=2;}

if(flag!=2)
{
    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0){flag=2;break;};//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0){flag=2;break;}
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
}
if(flag!=2)
{
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   
//printf("%d %c  flag=%d\n",m+8,p[m+8],flag);getch();

x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%c %c\n",p[i],p[k]);
		
		if( check_bond(p[k],p[i])==0){flag=2;break;}//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0){flag=2;break;}
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	}
	


	mat[u++][v-1]=bp[31]=p[i++];
	
	//printf("%d %c  flag=%d\n",m+8,p[m+8],flag);getch();
	//if(p[m+8]!='t'){flag=2;}
	if(p[m+8]!='t'&&p[m+8]!='c'){flag=2;}

//printf("%d %c  flag=%d\n",m+8,p[m+8],flag);getch();
}

	if(flag!=2)
	{
	bp[32]=p[m+8];
	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{if(u<0)flag=2;
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}

	
//printf("17 \n");
if(flag!=2)	
if(check3dbp(bp,arm_a-arm_for_a,arm_d-arm_for_d,arm_ac-arm_for_ac,arm_t-arm_for_t))	return 1;
else return 0;

//return 1;
}
	}
	}
















	
	if(flag==2)
	{
		
		u=u1;w=w1;m=m1;n=n1;x=x1;l=0;flag=0;

		for(i=u;i<32;i++)
for(j=0;j<80;++j)
mat[i][j]=' ';

		
		i=m+9;v=11;	arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;

	    j=0;k=m2+2;l=0;
	   
		   /*if( check_bond(p[k],p[i])==0)return 0; // D - arm having 20A & 20B
		    
		   
		   mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else
		{
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0)return 0;
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		   
		   i--;k++;j++;
		 }
	}


	


   j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];bp[17]=bp[18]='g';
   
   
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;
	j=0;
	k=n;


	if(p[i+4]!='g')return 0;
	if(p[i+5]!='t'&&p[i+5]!='a')return 0;
	if(p[i+7]!='c')return 0;
	if(p[i+12]!='c')return 0;


    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0)return 0;//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0)return 0;
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
   
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   


x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%c %c\n",p[i],p[k]);
		
		if( check_bond(p[k],p[i])==0)return 0;//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0)return 0;
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	}
	

	mat[u++][v-1]=bp[31]=p[i++];
	
	
	if(p[m+8]!='t')return 0;

	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}



	return 1;*/



 while(j<4)
		 {

if( check_bond(p[k],p[i])==0){flag=2;break;} // D - arm with 20A&20B
		
		mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else {
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0){flag=2;break;}
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		
		i--;k++;j++;
	
	}

	



if(flag!=2)
{
bp[20]=p[i];
j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];//bp[17]=bp[18]='g';
   bp[17]=p[i1];bp[18]=p[i1+1];
   
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;
	j=0;
	k=n;


	if(p[i+4]!='g'){flag=2;}
	if(p[i+5]!='t'&&p[i+5]!='a'){flag=2;}
	if(p[i+7]!='c'){flag=2;}
	if(p[i+12]!='c'){flag=2;}

if(flag!=2)
{
    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0){flag=2;break;};//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0){flag=2;break;}
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
}
if(flag!=2)
{
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   


x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%d  %d  %c %c\n",i,k,p[i],p[k]);getch();
		
		if( check_bond(p[k],p[i])==0){flag=2;break;}//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0){flag=2;break;}
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	//printf("%d  %c   flag=%d\n",m+8,p[m+8],flag);getch();

	}
	


	mat[u++][v-1]=bp[31]=p[i++];
	//printf("%d  %c   flag=%d\n",m+8,p[m+8],flag);getch();

	
	//if(p[m+8]!='t'){flag=2;}
	if(p[m+8]!='t'&&p[m+8]!='c'){flag=2;}
	//printf("%d  %c   flag=%d\n",m+8,p[m+8],flag);getch();

}

	if(flag!=2)
	{
	bp[32]=p[m+8];
	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{if(u<0)flag=2;
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}

	
//printf("17a exists\n");
if(flag!=2)
	if(check3dbp(bp,arm_a-arm_for_a,arm_d-arm_for_d,arm_ac-arm_for_ac,arm_t-arm_for_t))	return 1;
else return 0;
//return 1;
}
	}
}


}
i1--;
}


return 0;

}















int build_trna_gg(char *p,int l1,char mat[32][80],char *anticodon, char *bp,char *a_arm,char *d_arm,char *ac_arm,char *t_arm)
{
	int i=0,j,k,m,n,u,v,w,x,l=0,flag=0,m1,u1,n1,w1,x1,i1,i2,m2,u2,n2,w2,x2;
	int  arm_for_a=arm_a,arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;
	u=0;j=0;
	//printf("%s\n",p); getch();
	while(i<7)
	{
		v=14;//printf("OK\n");printf("%c %c\n",p[i],p[l-i-1]);
		if( check_bond(p[i],p[l1-i-1])==0)return 0; // A - arm
		 
		mat[u][v++]=a_arm[j++]=p[i];
		
		if(check_bond(p[i],p[l1-i-1])==1)
		mat[u][v++]='-';
		else 
		{
			mat[u][v++]='+';
			arm_for_a--;if(arm_for_a<0)return 0;
		}
		mat[u++][v]=a_arm[j++]=p[l1-i-1];
		i++;
	}

	w=w1=w2=u-1;

	if(p[i]!='t')return 0;
	bp[7]=p[i];bp[8]=p[i+1];
	mat[u++][13]=p[i];
	mat[u++][12]=p[i+1];
	
	n=n1=n2=l1-i-1;

	x=x1=x2=i+5;
	u1=u2=u;
	m2=i;
    j=0;
	i=i1=18;
    while(i1>15)

{	
		
		i=i1;u=u1=u2;w=w1=w2;m=m1=m2;n=n1=n2;x=x1=x2;l=0;v=11;
		arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;
		
		
		
		
		
		if((p[i+1]=='g')&&p[i]=='g')//17='g' does not exist 
		{
			
		
			//printf("i=%d\n",i);getch();
			for(i2=u;i2<32;i2++)
for(j=0;j<80;++j)
mat[i2][j]=' ';	

//bp[17]=p[i];bp[18]=p[i+1];
	
	//if(j==3)return 0;
	m=m1=i;
	i+=7;//rintf("%d\n",i);
	

	j=0;k=m2+2;//v=11;u1=u;
	//printf("Ok %d \n",i); getch();
	while(j<4)
	{
	
		//printf("OK\n");printf("%c %c\n",p[i],p[k]);
		

		if( check_bond(p[k],p[i])==0){flag=1;break;} // D - arm with 20
		
		mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else {
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0){flag=1;break;}
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		
		i--;k++;j++;
	
	}


if(flag!=1)
{
bp[20]=p[i];

j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];bp[17]=p[i1];bp[18]=p[i1+1];
   
   
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;//printf("i=%d\n",i);getch();
	j=0;
	k=n;


	if(p[i+4]!='g'){flag=1;}
	if(p[i+5]!='t'&&p[i+5]!='a'){flag=1;}
	if(p[i+7]!='c'){flag=1;}
	if(p[i+12]!='c'){flag=1;}


if(flag!=1)
{
    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0){flag=1;break;};//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0){flag=1;break;}
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
}
if(flag!=1)
{
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   


x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%c %c\n",p[i],p[k]);
		
		if( check_bond(p[k],p[i])==0){flag=1;break;}//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0){flag=1;break;}
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	}
	


	mat[u++][v-1]=bp[31]=p[i++];
	//printf("m=%d\n",m);getch();
	
	if(p[m+8]!='t'&&p[m+8]!='c'){flag=1;}
//printf("p[%d]=%c\n",m+8,p[m+8]); getch();
}
	if(flag!=1)
	{
		bp[32]=p[m+8];

	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{if(u<0)flag=1;
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}

	
//printf("17 a\n");





if(flag!=1)

if(check3dbp(bp,arm_a-arm_for_a,arm_d-arm_for_d,arm_ac-arm_for_ac,arm_t-arm_for_t))	return 1;
else return 0;

}
	}



if(flag==1)
{
	  
	arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;
	u=u1;w=w1;m=m1;n=n1;x=x1;l=0;

	
	
	for(i=u;i<32;i++)
for(j=0;j<80;++j)
mat[i][j]=' ';


	i=m+8;v=11;	
	    j=0;k=m2+2;l=0;
	     while(j<4)
	{
	
		//printf("OK\n");printf("%c %c\n",p[i],p[k]);
		

		if( check_bond(p[k],p[i])==0){flag=2;break;} // D - arm with 20A
		
		mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else {
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0){flag=2;break;}
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		
		i--;k++;j++;
	
	}

	



if(flag!=2)
{
bp[20]=p[i];
j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];//bp[17]=bp[18]='g';
   
   bp[17]=p[i1];bp[18]=p[i1+1];
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;
	j=0;
	k=n;


	if(p[i+4]!='g'){flag=2;}
	if(p[i+5]!='t'&&p[i+5]!='a'){flag=2;}
	if(p[i+7]!='c'){flag=2;}
	if(p[i+12]!='c'){flag=2;}

if(flag!=2)
{
    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0){flag=2;break;};//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0){flag=2;break;}
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
}
if(flag!=2)
{
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   
//printf("%d %c  flag=%d\n",m+8,p[m+8],flag);getch();

x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%c %c\n",p[i],p[k]);
		
		if( check_bond(p[k],p[i])==0){flag=2;break;}//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0){flag=2;break;}
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	}
	


	mat[u++][v-1]=bp[31]=p[i++];
	
	//printf("%d %c  flag=%d\n",m+8,p[m+8],flag);getch();
	//if(p[m+8]!='t'){flag=2;}
	if(p[m+8]!='t'&&p[m+8]!='c'){flag=2;}

//printf("%d %c  flag=%d\n",m+8,p[m+8],flag);getch();
}

	if(flag!=2)
	{
	bp[32]=p[m+8];
	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{if(u<0)flag=2;
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}

	
//printf("17 \n");
if(flag!=2)	
if(check3dbp(bp,arm_a-arm_for_a,arm_d-arm_for_d,arm_ac-arm_for_ac,arm_t-arm_for_t))	return 1;
else return 0;

//return 1;
}
	}
	}
















	
	if(flag==2)
	{
		
		u=u1;w=w1;m=m1;n=n1;x=x1;l=0;flag=0;

		for(i=u;i<32;i++)
for(j=0;j<80;++j)
mat[i][j]=' ';

		
		i=m+9;v=11;	arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;

	    j=0;k=m2+2;l=0;
	   
		   /*if( check_bond(p[k],p[i])==0)return 0; // D - arm having 20A & 20B
		    
		   
		   mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else
		{
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0)return 0;
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		   
		   i--;k++;j++;
		 }
	}


	


   j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];bp[17]=bp[18]='g';
   
   
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;
	j=0;
	k=n;


	if(p[i+4]!='g')return 0;
	if(p[i+5]!='t'&&p[i+5]!='a')return 0;
	if(p[i+7]!='c')return 0;
	if(p[i+12]!='c')return 0;


    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0)return 0;//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0)return 0;
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
   
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   


x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%c %c\n",p[i],p[k]);
		
		if( check_bond(p[k],p[i])==0)return 0;//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0)return 0;
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	}
	

	mat[u++][v-1]=bp[31]=p[i++];
	
	
	if(p[m+8]!='t')return 0;

	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}



	return 1;*/



 while(j<4)
		 {

if( check_bond(p[k],p[i])==0){flag=2;break;} // D - arm with 20A&20B
		
		mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else {
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0){flag=2;break;}
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		
		i--;k++;j++;
	
	}

	



if(flag!=2)
{
bp[20]=p[i];
j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];//bp[17]=bp[18]='g';
   bp[17]=p[i1];bp[18]=p[i1+1];
   
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;
	j=0;
	k=n;


	if(p[i+4]!='g'){flag=2;}
	if(p[i+5]!='t'&&p[i+5]!='a'){flag=2;}
	if(p[i+7]!='c'){flag=2;}
	if(p[i+12]!='c'){flag=2;}

if(flag!=2)
{
    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0){flag=2;break;};//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0){flag=2;break;}
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
}
if(flag!=2)
{
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   


x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%d  %d  %c %c\n",i,k,p[i],p[k]);getch();
		
		if( check_bond(p[k],p[i])==0){flag=2;break;}//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0){flag=2;break;}
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	//printf("%d  %c   flag=%d\n",m+8,p[m+8],flag);getch();

	}
	


	mat[u++][v-1]=bp[31]=p[i++];
	//printf("%d  %c   flag=%d\n",m+8,p[m+8],flag);getch();

	
	//if(p[m+8]!='t'){flag=2;}
	if(p[m+8]!='t'&&p[m+8]!='c'){flag=2;}
	//printf("%d  %c   flag=%d\n",m+8,p[m+8],flag);getch();

}

	if(flag!=2)
	{
	bp[32]=p[m+8];
	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{if(u<0)flag=2;
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}

	
//printf("17a exists\n");
if(flag!=2)
	if(check3dbp(bp,arm_a-arm_for_a,arm_d-arm_for_d,arm_ac-arm_for_ac,arm_t-arm_for_t))	return 1;
else return 0;
//return 1;
}
	}
}


}
i1--;
}


return 0;

}








int build_trna_ag(char *p,int l1,char mat[32][80],char *anticodon, char *bp,char *a_arm,char *d_arm,char *ac_arm,char *t_arm)
{
	int i=0,j,k,m,n,u,v,w,x,l=0,flag=0,m1,u1,n1,w1,x1,i1,i2,m2,u2,n2,w2,x2;
	int  arm_for_a=arm_a,arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;
	u=0;j=0;
	//printf("%s\n",p); getch();
	while(i<7)
	{
		v=14;//printf("OK\n");printf("%c %c\n",p[i],p[l-i-1]);
		if( check_bond(p[i],p[l1-i-1])==0)return 0; // A - arm
		 
		mat[u][v++]=a_arm[j++]=p[i];
		
		if(check_bond(p[i],p[l1-i-1])==1)
		mat[u][v++]='-';
		else 
		{
			mat[u][v++]='+';
			arm_for_a--;if(arm_for_a<0)return 0;
		}
		mat[u++][v]=a_arm[j++]=p[l1-i-1];
		i++;
	}

	w=w1=w2=u-1;

	if(p[i]!='t')return 0;
	bp[7]=p[i];bp[8]=p[i+1];
	mat[u++][13]=p[i];
	mat[u++][12]=p[i+1];
	
	n=n1=n2=l1-i-1;

	x=x1=x2=i+5;
	u1=u2=u;
	m2=i;
    j=0;
	i=i1=18;
    while(i1>15)

{	
		
		i=i1;u=u1=u2;w=w1=w2;m=m1=m2;n=n1=n2;x=x1=x2;l=0;v=11;
		arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;
		
		
		
		
		
		if((p[i+1]=='a')&&p[i]=='g')//17='g' does not exist 
		{
			
		
			//printf("i=%d\n",i);getch();
			for(i2=u;i2<32;i2++)
for(j=0;j<80;++j)
mat[i2][j]=' ';	

//bp[17]=p[i];bp[18]=p[i+1];
	
	//if(j==3)return 0;
	m=m1=i;
	i+=7;//rintf("%d\n",i);

	j=0;k=m2+2;//v=11;u1=u;
	//printf("Ok %d \n",i); getch();
	while(j<4)
	{
	
		//printf("OK\n");printf("%c %c\n",p[i],p[k]);
		

		if( check_bond(p[k],p[i])==0){flag=1;break;} // D - arm with 20
		
		mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else {
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0){flag=1;break;}
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		
		i--;k++;j++;
	
	}


if(flag!=1)
{
bp[20]=p[i];
j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];bp[17]=p[i1];bp[18]=p[i1+1];
   
   
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;//printf("i=%d\n",i);getch();
	j=0;
	k=n;


	if(p[i+4]!='g'){flag=1;}
	if(p[i+5]!='t'&&p[i+5]!='a'){flag=1;}
	if(p[i+7]!='c'){flag=1;}
	if(p[i+12]!='c'){flag=1;}


if(flag!=1)
{
    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0){flag=1;break;};//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0){flag=1;break;}
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
}
if(flag!=1)
{
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   


x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%c %c\n",p[i],p[k]);
		
		if( check_bond(p[k],p[i])==0){flag=1;break;}//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0){flag=1;break;}
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	}
	


	mat[u++][v-1]=bp[31]=p[i++];
	//printf("m=%d\n",m);getch();
	
	if(p[m+8]!='t'&&p[m+8]!='c'){flag=1;}

}
	if(flag!=1)
	{bp[32]=p[m+8];

	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{if(u<0)flag=1;
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}

	
//printf("17 a\n");






if(flag!=1)
if(check3dbp(bp,arm_a-arm_for_a,arm_d-arm_for_d,arm_ac-arm_for_ac,arm_t-arm_for_t))	return 1;
else return 0;

}
	}



if(flag==1)
{
	  
	arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;
	u=u1;w=w1;m=m1;n=n1;x=x1;l=0;

	
	
	for(i=u;i<32;i++)
for(j=0;j<80;++j)
mat[i][j]=' ';


	i=m+8;v=11;	
	    j=0;k=m2+2;l=0;
	     while(j<4)
	{
	
		//printf("OK\n");printf("%c %c\n",p[i],p[k]);
		

		if( check_bond(p[k],p[i])==0){flag=2;break;} // D - arm with 20A
		
		mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else {
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0){flag=2;break;}
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		
		i--;k++;j++;
	
	}

	



if(flag!=2)
{
bp[20]=p[i];
j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];//bp[17]=bp[18]='g';
   
   bp[17]=p[i1];bp[18]=p[i1+1];
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;
	j=0;
	k=n;


	if(p[i+4]!='g'){flag=2;}
	if(p[i+5]!='t'&&p[i+5]!='a'){flag=2;}
	if(p[i+7]!='c'){flag=2;}
	if(p[i+12]!='c'){flag=2;}

if(flag!=2)
{
    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0){flag=2;break;};//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0){flag=2;break;}
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
}
if(flag!=2)
{
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   
//printf("%d %c  flag=%d\n",m+8,p[m+8],flag);getch();

x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%c %c\n",p[i],p[k]);
		
		if( check_bond(p[k],p[i])==0){flag=2;break;}//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0){flag=2;break;}
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	}
	


	mat[u++][v-1]=bp[31]=p[i++];
	
	//printf("%d %c  flag=%d\n",m+8,p[m+8],flag);getch();
	//if(p[m+8]!='t'){flag=2;}
	if(p[m+8]!='t'&&p[m+8]!='c'){flag=2;}

//printf("%d %c  flag=%d\n",m+8,p[m+8],flag);getch();
}

	if(flag!=2)
	{
bp[32]=p[m+8];
	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{if(u<0)flag=2;
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}

	
//printf("17 \n");
if(flag!=2)	
if(check3dbp(bp,arm_a-arm_for_a,arm_d-arm_for_d,arm_ac-arm_for_ac,arm_t-arm_for_t))	return 1;
else return 0;

//return 1;
}
	}
	}
















	
	if(flag==2)
	{
		
		u=u1;w=w1;m=m1;n=n1;x=x1;l=0;flag=0;

		for(i=u;i<32;i++)
for(j=0;j<80;++j)
mat[i][j]=' ';

		
		i=m+9;v=11;	arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;

	    j=0;k=m2+2;l=0;
	   
		   /*if( check_bond(p[k],p[i])==0)return 0; // D - arm having 20A & 20B
		    
		   
		   mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else
		{
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0)return 0;
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		   
		   i--;k++;j++;
		 }
	}


	


   j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];bp[17]=bp[18]='g';
   
   
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;
	j=0;
	k=n;


	if(p[i+4]!='g')return 0;
	if(p[i+5]!='t'&&p[i+5]!='a')return 0;
	if(p[i+7]!='c')return 0;
	if(p[i+12]!='c')return 0;


    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0)return 0;//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0)return 0;
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
   
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   


x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%c %c\n",p[i],p[k]);
		
		if( check_bond(p[k],p[i])==0)return 0;//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0)return 0;
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	}
	

	mat[u++][v-1]=bp[31]=p[i++];
	
	
	if(p[m+8]!='t')return 0;

	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}



	return 1;*/



 while(j<4)
		 {

if( check_bond(p[k],p[i])==0){flag=2;break;} // D - arm with 20A&20B
		
		mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else {
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0){flag=2;break;}
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		
		i--;k++;j++;
	
	}

	



if(flag!=2)
{
bp[20]=p[i];
j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];//bp[17]=bp[18]='g';
   bp[17]=p[i1];bp[18]=p[i1+1];
   
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;
	j=0;
	k=n;


	if(p[i+4]!='g'){flag=2;}
	if(p[i+5]!='t'&&p[i+5]!='a'){flag=2;}
	if(p[i+7]!='c'){flag=2;}
	if(p[i+12]!='c'){flag=2;}

if(flag!=2)
{
    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0){flag=2;break;};//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0){flag=2;break;}
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
}
if(flag!=2)
{
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   


x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%d  %d  %c %c\n",i,k,p[i],p[k]);getch();
		
		if( check_bond(p[k],p[i])==0){flag=2;break;}//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0){flag=2;break;}
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	//printf("%d  %c   flag=%d\n",m+8,p[m+8],flag);getch();

	}
	


	mat[u++][v-1]=bp[31]=p[i++];
	//printf("%d  %c   flag=%d\n",m+8,p[m+8],flag);getch();

	
	//if(p[m+8]!='t'){flag=2;}
	if(p[m+8]!='t'&&p[m+8]!='c'){flag=2;}
	//printf("%d  %c   flag=%d\n",m+8,p[m+8],flag);getch();

}

	if(flag!=2)
	{
bp[32]=p[m+8];
	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{if(u<0)flag=2;
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}

	
//printf("17a exists\n");
if(flag!=2)	
if(check3dbp(bp,arm_a-arm_for_a,arm_d-arm_for_d,arm_ac-arm_for_ac,arm_t-arm_for_t))	return 1;
else return 0;
//return 1;
}
	}
}


}
i1--;
}


return 0;

}

















int build_trna9abs(char *p,int l1,char mat[32][80],char *anticodon, char *bp,char *a_arm,char *d_arm,char *ac_arm,char *t_arm)
{
	int i=0,j,k,m,n,u,v,w,x,l=0,flag=0,m1,u1,n1,w1,x1,i1,i2,m2,u2,n2,w2,x2;
	int  arm_for_a=arm_a,arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;
	u=0;j=0;
	//printf("%s\n",p); getch();
	while(i<7)
	{
		v=14;//printf("OK\n");printf("%c %c\n",p[i],p[l-i-1]);
		if( check_bond(p[i],p[l1-i-1])==0)return 0; // A - arm
		 
		mat[u][v++]=a_arm[j++]=p[i];
		
		if(check_bond(p[i],p[l1-i-1])==1)
		mat[u][v++]='-';
		else 
		{
			mat[u][v++]='+';
			arm_for_a--;if(arm_for_a<0)return 0;
		}
		mat[u++][v]=a_arm[j++]=p[l1-i-1];
		i++;
	}

	w=w1=w2=u-1;

	if(p[i]!='t')return 0;
	bp[7]=p[i];bp[8]='-';
	mat[u++][13]=p[i];

	//mat[u++][12]=p[i+1];
	
	n=n1=n2=l1-i-1;

	x=x1=x2=i+4;
	u1=u2=u;
	m2=i-1;
    j=0;
	i=i1=17;
    while(i1>14)

{	
		
		i=i1;u=u1=u2;w=w1=w2;m=m1=m2;n=n1=n2;x=x1=x2;l=0;v=11;
		arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;
		
		
		
		
		
		if((p[i+1]=='g'||p[i+1]=='a')&&p[i]=='g')//17='g' does not exist 
		{
			
		
			//printf("i=%d\n",i);getch();
			for(i2=u;i2<32;i2++)
for(j=0;j<80;++j)
mat[i2][j]=' ';	

//bp[17]=p[i];bp[18]=p[i+1];
	
	//if(j==3)return 0;
	m=m1=i;
	i+=7;//rintf("%d\n",i);

	j=0;k=m2+2;//v=11;u1=u;
	//printf("Ok %d \n",i); getch();
	while(j<4)
	{
	
		//printf("OK\n");printf("%c %c\n",p[i],p[k]);
		

		if( check_bond(p[k],p[i])==0){flag=1;break;} // D - arm with 20
		
		mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else {
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0){flag=1;break;}
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		
		i--;k++;j++;
	
	}


if(flag!=1)
{
bp[20]=p[i];
j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];bp[17]=p[i1];bp[18]=p[i1+1];
   
   
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;//printf("i=%d\n",i);getch();
	j=0;
	k=n;


	if(p[i+4]!='g'){flag=1;}
	if(p[i+5]!='t'&&p[i+5]!='a'){flag=1;}
	if(p[i+7]!='c'){flag=1;}
	if(p[i+12]!='c'){flag=1;}


if(flag!=1)
{
    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0){flag=1;break;};//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0){flag=1;break;}
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
}
if(flag!=1)
{
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   


x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%c %c\n",p[i],p[k]);
		
		if( check_bond(p[k],p[i])==0){flag=1;break;}//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0){flag=1;break;}
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	}
	


	mat[u++][v-1]=bp[31]=p[i++];
	//printf("m=%d\n",m);getch();
	
	//if(p[m+8]!='t'&&p[m+8]!='c'){flag=1;}
	if(p[m+8]!='t'){flag=1;}

}
	if(flag!=1)
	{
bp[32]=p[m+8];
	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{if(u<0)flag=1;
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}

	
//printf("17 a\n");






if(flag!=1)
if(check3dbp(bp,arm_a-arm_for_a,arm_d-arm_for_d,arm_ac-arm_for_ac,arm_t-arm_for_t))	return 1;
else return 0;
}
	}



if(flag==1)
{
	  
	arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;
	u=u1;w=w1;m=m1;n=n1;x=x1;l=0;

	
	
	for(i=u;i<32;i++)
for(j=0;j<80;++j)
mat[i][j]=' ';


	i=m+8;v=11;	
	    j=0;k=m2+2;l=0;
	     while(j<4)
	{
	
		//printf("OK\n");printf("%c %c\n",p[i],p[k]);
		

		if( check_bond(p[k],p[i])==0){flag=2;break;} // D - arm with 20A
		
		mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else {
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0){flag=2;break;}
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		
		i--;k++;j++;
	
	}

	



if(flag!=2)
{
bp[20]=p[i];
j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];//bp[17]=bp[18]='g';
   
   bp[17]=p[i1];bp[18]=p[i1+1];
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;
	j=0;
	k=n;


	if(p[i+4]!='g'){flag=2;}
	if(p[i+5]!='t'&&p[i+5]!='a'){flag=2;}
	if(p[i+7]!='c'){flag=2;}
	if(p[i+12]!='c'){flag=2;}

if(flag!=2)
{
    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0){flag=2;break;};//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0){flag=2;break;}
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
}
if(flag!=2)
{
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   
//printf("%d %c  flag=%d\n",m+8,p[m+8],flag);getch();

x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%c %c\n",p[i],p[k]);
		
		if( check_bond(p[k],p[i])==0){flag=2;break;}//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0){flag=2;break;}
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	}
	


	mat[u++][v-1]=bp[31]=p[i++];
	
	//printf("%d %c  flag=%d\n",m+8,p[m+8],flag);getch();
	//if(p[m+8]!='t'){flag=2;}
	//if(p[m+8]!='t'&&p[m+8]!='c'){flag=2;}
	if(p[m+8]!='t'){flag=2;}

//printf("%d %c  flag=%d\n",m+8,p[m+8],flag);getch();
}

	if(flag!=2)
	{
bp[32]=p[m+8];
	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{if(u<0)flag=2;
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}

	
//printf("17 \n");
if(flag!=2)	
if(check3dbp(bp,arm_a-arm_for_a,arm_d-arm_for_d,arm_ac-arm_for_ac,arm_t-arm_for_t))	return 1;
else return 0;

//return 1;
}
	}
	}
















	
	if(flag==2)
	{
		
		u=u1;w=w1;m=m1;n=n1;x=x1;l=0;flag=0;

		for(i=u;i<32;i++)
for(j=0;j<80;++j)
mat[i][j]=' ';

		
		i=m+9;v=11;	arm_for_d=arm_d,arm_for_ac=arm_ac,arm_for_t=arm_t;

	    j=0;k=m2+2;l=0;
	   
		   /*if( check_bond(p[k],p[i])==0)return 0; // D - arm having 20A & 20B
		    
		   
		   mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else
		{
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0)return 0;
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		   
		   i--;k++;j++;
		 }
	}


	


   j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];bp[17]=bp[18]='g';
   
   
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;
	j=0;
	k=n;


	if(p[i+4]!='g')return 0;
	if(p[i+5]!='t'&&p[i+5]!='a')return 0;
	if(p[i+7]!='c')return 0;
	if(p[i+12]!='c')return 0;


    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0)return 0;//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0)return 0;
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
   
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   


x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%c %c\n",p[i],p[k]);
		
		if( check_bond(p[k],p[i])==0)return 0;//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0)return 0;
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	}
	

	mat[u++][v-1]=bp[31]=p[i++];
	
	
	if(p[m+8]!='t')return 0;

	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}



	return 1;*/



 while(j<4)
		 {

if( check_bond(p[k],p[i])==0){flag=2;break;} // D - arm with 20A&20B
		
		mat[u++][v]=d_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[u++][v]='|';
		else {
			mat[u++][v]='+';
			arm_for_d--;
			if(arm_for_d<0){flag=2;break;}
		}
		mat[u++][v]=d_arm[l++]=p[i];v--;u-=3;
		
		i--;k++;j++;
	
	}

	



if(flag!=2)
{
bp[20]=p[i];
j=0;k=x++;//printf("%d %d\n",i,k);getch();
  
   bp[13]=p[x];bp[14]=p[x+1];//bp[17]=bp[18]='g';
   bp[17]=p[i1];bp[18]=p[i1+1];
   
   while(j<(i-k-2)/2)
   {
	   mat[w+2][v]=p[x++];v--;j++;//printf("OK\n");
   }
   mat[w+3][v]=p[x++];
   mat[w+4][v]=p[x++];
   mat[w+5][v]=p[x++];

   
   while(x<=i)
   
	   mat[w+6][++v]=p[x++];

  
   i=n-16;
	j=0;
	k=n;


	if(p[i+4]!='g'){flag=2;}
	if(p[i+5]!='t'&&p[i+5]!='a'){flag=2;}
	if(p[i+7]!='c'){flag=2;}
	if(p[i+12]!='c'){flag=2;}

if(flag!=2)
{
    mat[w][22]=p[k-5];mat[w][23]=p[k-6];v=17;w++;l=0;

	while(j<5)
	{
		if( check_bond(p[k],p[i])==0){flag=2;break;};//T -arm
		
		
		mat[w++][v]=t_arm[l++]=p[k];
		
		if(check_bond(p[i],p[k])==1)
		mat[w++][v]='|';
		else
		{
			mat[w++][v]='+';
			arm_for_t--;if(arm_for_t<0){flag=2;break;}
		}
		mat[w++][v]=t_arm[l++]=p[i];v++;w-=3;
		
		j++;k--;i++;
	}
}
if(flag!=2)
{
   mat[w+3][v++]=bp[53]=p[i++];mat[w+3][v++]=bp[54]=p[i++];
   mat[w+2][v]=bp[55]=p[i++];
   mat[w+1][v]=p[i++];
   mat[w][v]=bp[57]=p[i++];
   
   
   
   
   u=w+6;v=12;
   


x--;

	m=x+4;mat[--u][v++]=bp[25]=p[m+1];u++;
	i=m+2;
	w=u;l=0;

	j=0;k=i+16;x=k+1;//printf("%d %d\n",i,k);
	while(j<5)
	{
		
		//printf("OK\n");
		//printf("%d  %d  %c %c\n",i,k,p[i],p[k]);getch();
		
		if( check_bond(p[k],p[i])==0){flag=2;break;}//AC -arm
		
		mat[u][v++]=ac_arm[l++]=p[i];
		
		if(check_bond(p[i],p[k])==1)
		mat[u][v++]='-';
		else 
		{
				mat[u][v++]='+';
			arm_for_ac--;if(arm_for_ac<0){flag=2;break;}
		}
		mat[u++][v]=ac_arm[l++]=p[k];v-=2;
		
		
		j++;k--;i++;
	//printf("%d  %c   flag=%d\n",m+8,p[m+8],flag);getch();

	}
	


	mat[u++][v-1]=bp[31]=p[i++];
	//printf("%d  %c   flag=%d\n",m+8,p[m+8],flag);getch();

	
	//if(p[m+8]!='t'){flag=2;}
	//if(p[m+8]!='t'&&p[m+8]!='c'){flag=2;}
	if(p[m+8]!='t'){flag=2;}
	//printf("%d  %c   flag=%d\n",m+8,p[m+8],flag);getch();

}

	if(flag!=2)
	{
bp[32]=p[m+8];
	mat[u++][v-1]=p[i++];j=0;
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];
	mat[u][v++]=anticodon[j++]=p[i++];anticodon[j]='\0';

	while(i<=k)
	mat[--u][v]=p[i++];

	bp[37]=p[k];



	v=16;
k=n-17;
j=0;
i=x;
bp[43]=p[i];bp[47]=p[k];
u=ceil((k-x+1)/2.0)-2;//printf("%d %d % d\n",k,x, u);
if(u>0){
while(j<=u){mat[w++][v++]=p[i++];j++;}

w--;
j=0;
while(j<=u/2+1)
{
  mat[--w][v]=p[i++];j++;
}
v--;
if(j<=u)
{
while(j<=u)
{
   mat[--w][v]=p[i++];
   j++;
}
v--;
}
else v+=1;
while(i<=k)
mat[--w][v--]=p[i++];

}
else
{if(u<0)flag=2;
	mat[w][v++]=p[i++];
	mat[w][v++]=p[i++];

while(i<=k)
mat[--w][v--]=p[i++];
}

	
//printf("17a exists\n");
	
if(flag!=2)
if(check3dbp(bp,arm_a-arm_for_a,arm_d-arm_for_d,arm_ac-arm_for_ac,arm_t-arm_for_t))	return 1;
else return 0;
//return 1;
}
	}
}


}
i1--;
}


return 0;

}











int display(char mat[32][80],char *anti,char *bp,char *a_arm,char *d_arm,char *ac_arm,char *t_arm,FILE *f,FILE *f1,int start,int end,int start1,int end1,char *p2,char *p4,char *p3,char *sp1,char *sp2,char *sp3,char *sp4,char *p,int add,char *st1,char *st2,char *bh1,char *bh2,char *top)

{
	//static int k=1;
	
	char acid[64][5]={"Phe","Phe","Leu","Leu","Ser","Ser","Ser","Ser","Cys","Cys",
		"Trp","Sec","Tyr","Tyr","Stop","Stop","Leu","Leu","Leu","Leu","Pro","Pro","Pro",
		"Pro","Arg","Arg","Arg","Arg","His","His","Gln","Gln","Val","Val","Val","Val",
		"Ala","Ala","Ala","Ala","Gly","Gly","Gly","Gly","Asp","Asp","Glu","Glu","Ile",
		"Ile","Met","Ile","Thr","Thr","Thr","Thr","Ser","Ser","Arg","Arg","Asn","Asn",
		"Lys","Lys"};

	char anticodon[64][5]={
		"aaa","gaa","caa","taa","aga","gga","cga","tga","aca","gca","cca","tca","ata","gta",
		"cta","tta","aag","gag","cag","tag","agg","ggg","cgg","tgg","acg","gcg","ccg","tcg",
		"atg","gtg","ctg","ttg","aac","gac","cac","tac","agc","ggc","cgc","tgc","acc","gcc",
		"ccc","tcc","atc","gtc","ctc","ttc","aat","gat","cat","tat","agt","ggt","cgt","tgt",
		"act","gct","cct","tct","att","gtt","ctt","ttt"};

	int i,j,k,total;


if(start1<=end&&start1>=start)return 0;
if(start<=end1&&start>=start1)return 0;	
	fprintf(f,"%d.\n",no++);

	j=strlen(top);
	
for(i=j-1;i>=0;--i)
{
for(k=0;k<16;++k)
fprintf(f," ");
fprintf(f,"%c\n",top[i]);
}
	for(i=0;i<32;++i)
	{	for(j=0;j<80;++j)
			fprintf(f,"%c",mat[i][j]);
	fprintf(f,"\n");
	}


	for(i=0;i<64;++i)
		if(strcmp(anti,anticodon[i])==0)
		{
			fprintf(f,"trna - %s ( %s )\n",acid[i],anticodon[i]);fprintf(f,"trna length - %d\n",LENGTH);

			fprintf(f1,"%s\t%s\t%d\t\t",acid[i],anticodon[i],LENGTH);
		}

if(start1-1==end)
	fprintf(f,"trna sequence (%d -  %d)\n\n\n",start,end1);
else	
	fprintf(f,"trna sequence (%d - %d,%d - %d)\n\n\n",start,end,start1,end1);

fprintf(f1,"%s\t%c-%c\t%c-%c\t%c-%c\t%c-%c\t%c-%c\t%c-%c\t%c-%c\t ",p4,a_arm[0],a_arm[1],a_arm[2],a_arm[3],a_arm[4],a_arm[5],a_arm[6],a_arm[7],a_arm[8],a_arm[9],a_arm[10],a_arm[11],a_arm[12],a_arm[13]);
fprintf(f1,"%c-%c\t %c-%c\t %c-%c\t %c-%c\t ",d_arm[0],d_arm[1],d_arm[2],d_arm[3],d_arm[4],d_arm[5],d_arm[6],d_arm[7]);
fprintf(f1,"%c-%c\t %c-%c\t %c-%c\t %c-%c\t %c-%c\t ",ac_arm[0],ac_arm[1],ac_arm[2],ac_arm[3],ac_arm[4],ac_arm[5],ac_arm[6],ac_arm[7],ac_arm[8],ac_arm[9]);
fprintf(f1,"%c-%c\t %c-%c\t %c-%c\t %c-%c\t %c-%c\t ",t_arm[1],t_arm[0],t_arm[3],t_arm[2],t_arm[5],t_arm[4],t_arm[7],t_arm[6],t_arm[9],t_arm[8]);


fprintf(f1,"%c-%c\t %c-%c\t %c-%c\t %c-%c\t %c-%c\t %c-%c\t %c-%c\t%c\t%c\t%c\t%s\t%40s\t",bp[7],bp[13],bp[14],bp[47],bp[17],bp[54],bp[18],bp[55],bp[25],bp[43],bp[31],bp[37],bp[53],bp[57],bp[8],bp[20],bp[32],p2,p3);

if(start1-1==end)
{
	for(i=0;i<20;i++)
	sp2[i]=sp3[i]='-';sp2[i]=sp3[i]='\0';
}


fprintf(f1,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sp1,sp2,sp3,sp4,p,st1,st2,bh1,bh2);
total=arma+armd+armac+armt;


fprintf(f1,"%d\t%d\t%d\t",total,bp_3,total_cons);

if(add==1)fprintf(f1,"%s\n","Mathing 1st and 4th");
else if(add==2)fprintf(f1,"%s\n","Exists bh loop");
else if (add==3)fprintf(f1,"%s\n","Mathing 1st and 4th AND Exists bh loop");
else if (add==4)fprintf(f1,"%s\n","Mathing 1st and 4th AND  bh loop does not exist");


fflush(f);
fflush(f1);
}









int  cdisplay(char mat[32][80],char *anti,char *bp,char *a_arm,char *d_arm,char *ac_arm,char *t_arm,FILE *f,FILE *f1,int start,int end,int start1,int end1,char *p2,char *p4,char *p3,char *sp1,char *sp2,char *sp3,char *sp4,char *p,int add,char *st1,char *st2,char *bh1,char *bh2,char *top)
{
	//static int k=1;
	
	char acid[64][5]={"Phe","Phe","Leu","Leu","Ser","Ser","Ser","Ser","Cys","Cys",
		"Trp","Sec","Tyr","Tyr","Stop","Stop","Leu","Leu","Leu","Leu","Pro","Pro","Pro",
		"Pro","Arg","Arg","Arg","Arg","His","His","Gln","Gln","Val","Val","Val","Val",
		"Ala","Ala","Ala","Ala","Gly","Gly","Gly","Gly","Asp","Asp","Glu","Glu","Ile",
		"Ile","Met","Ile","Thr","Thr","Thr","Thr","Ser","Ser","Arg","Arg","Asn","Asn",
		"Lys","Lys"};

	char anticodon[64][5]={
		"aaa","gaa","caa","taa","aga","gga","cga","tga","aca","gca","cca","tca","ata","gta",
		"cta","tta","aag","gag","cag","tag","agg","ggg","cgg","tgg","acg","gcg","ccg","tcg",
		"atg","gtg","ctg","ttg","aac","gac","cac","tac","agc","ggc","cgc","tgc","acc","gcc",
		"ccc","tcc","atc","gtc","ctc","ttc","aat","gat","cat","tat","agt","ggt","cgt","tgt",
		"act","gct","cct","tct","att","gtt","ctt","ttt"};

	int i,j,k,total;

if(end<=end1&&start1<=end)return 0;
if(start<=end1&&start1<=start)return 0;	
fprintf(f,"%d.\n",no++);

j=strlen(top);
	
for(i=j-1;i>=0;--i)
{
for(k=0;k<16;++k)
fprintf(f," ");
fprintf(f,"%c\n",top[i]);
}


	for(i=0;i<32;++i)
	{	for(j=0;j<80;++j)
			fprintf(f,"%c",mat[i][j]);
	fprintf(f,"\n");
	}


	for(i=0;i<64;++i)
		if(strcmp(anti,anticodon[i])==0)
		{
			fprintf(f,"trna - %s ( %s )\n",acid[i],anticodon[i]);fprintf(f,"trna length - %d\n",LENGTH);

			fprintf(f1,"%s\t%s\t%d\t\t",acid[i],anticodon[i],LENGTH);
		}


if(start-1==end1)
	fprintf(f,"trna sequence complement(%d -  %d)\n\n\n",start1,end);	
else
	fprintf(f,"trna sequence complement(%d - %d,%d - %d)\n\n\n",start1,end1,start,end);


fprintf(f1,"%s\t%c-%c\t%c-%c\t%c-%c\t%c-%c\t%c-%c\t%c-%c\t%c-%c\t ",p4,a_arm[0],a_arm[1],a_arm[2],a_arm[3],a_arm[4],a_arm[5],a_arm[6],a_arm[7],a_arm[8],a_arm[9],a_arm[10],a_arm[11],a_arm[12],a_arm[13]);
fprintf(f1,"%c-%c\t %c-%c\t %c-%c\t %c-%c\t ",d_arm[0],d_arm[1],d_arm[2],d_arm[3],d_arm[4],d_arm[5],d_arm[6],d_arm[7]);
fprintf(f1,"%c-%c\t %c-%c\t %c-%c\t %c-%c\t %c-%c\t ",ac_arm[0],ac_arm[1],ac_arm[2],ac_arm[3],ac_arm[4],ac_arm[5],ac_arm[6],ac_arm[7],ac_arm[8],ac_arm[9]);
fprintf(f1,"%c-%c\t %c-%c\t %c-%c\t %c-%c\t %c-%c\t ",t_arm[1],t_arm[0],t_arm[3],t_arm[2],t_arm[5],t_arm[4],t_arm[7],t_arm[6],t_arm[9],t_arm[8]);


fprintf(f1,"%c-%c\t %c-%c\t %c-%c\t %c-%c\t %c-%c\t %c-%c\t %c-%c\t%c\t%c\t%c\t%s\t%40s\t",bp[7],bp[13],bp[14],bp[47],bp[17],bp[54],bp[18],bp[55],bp[25],bp[43],bp[31],bp[37],bp[53],bp[57],bp[8],bp[20],bp[32],p2,p3);

if(start-1==end1)
{
	for(i=0;i<20;i++)
	sp2[i]=sp3[i]='-';sp2[i]=sp3[i]='\0';
}


fprintf(f1,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t",sp1,sp2,sp3,sp4,p,st1,st2,bh1,bh2);
total=arma+armd+armac+armt;


fprintf(f1,"%d\t%d\t%d\t",total,bp_3,total_cons);
if(add==2)fprintf(f1,"%s\n","Mathing 1st and 4th");
else if(add==1)fprintf(f1,"%s\n","Exists bh loop");
else if (add==3)fprintf(f1,"%s\n","Mathing 1st and 4th AND Exists bh loop");
else if (add==4)fprintf(f1,"%s\n","Mathing 1st and 4th AND  bh loop does not exist");


fflush(f);
fflush(f1);
}



/*promo(char *p,int l,char *p4)
{
	int i,j,k;
	for(i=0;i<6;++i)p4[i]='-';
	p4[i]='\0';
	for(i=0;i<l-6;i++)
	{
		if(p[i]=='a'||p[i]=='t')
		
		if(p[i+1]!='g'&&p[i+1]!='c')

			if(p[i+2]!='g'&&p[i+2]!='c')
				if(p[i+3]!='g'&&p[i+3]!='c')
					if(p[i+4]!='g'&&p[i+4]!='c')
						if(p[i+5]=='c'||p[i+5]=='t')
						{
							k=0;
							for(j=i+5;j>=i;--j)p4[k++]=p[j];
								p4[k]='\0';
								return 0;
						
						}
	}
return 0;
}

*/







void main()
{


	

	char mat[32][80],*p,anti[5],c,bp[64],p2[7]={'\0'},p3[41]={'\0'},p4[7]={'\0'},*q,*r,*q1;
char a_arm[14],d_arm[8],ac_arm[10],t_arm[10];
	FILE *f2,*f1,*f,*f3,*f4;
	int n=0,n1=0,i=0,j,l,total=0,k,l1,end,flag=0,l2,total1=0,k1,flag2=0,total2=0,to,m;
	int pflag=0,o_n,o_n1;
char sp1[61],sp2[21],sp3[21],sp4[61],*cq;
char bh1[16],bh2[16],st1[15],st2[15],top[5];
int add;

FILE *f_h,*s_h,*cf_h,*cs_h;

	
	f1=fopen("out.txt","a+");
	f=fopen("3d_bp.txt","a+");
   
	fprintf(f,"Type\tAnticodon\tpromo\t1-72\t2-71\t3-70\t4-69\t5-68\t6-67\t7-66\t10-25\t11-24\t12-23\t13-22\t27-43\t28-42\t29-41\t30-40\t31-39\t49-65\t50-64\t51-63\t52-62\t53-61\t8-14\t15-48\t18-55\t19-56\t26-44\t32-38\t54-58\t9\t21\t33\tEND  \t\t\tSTART\t\t\t 1st\t\t 2nd\t\t3rd\t\t4th\t\tlength\t\t 11st string\t\t2nd string\t\t bh1\t\tbh2\t\tstatus\n");
	
	printf("Enter range :");
	scanf("%d%d",&LENGTH,&end);




	
	
	
	
	
//f2=fopen("input.txt","r+b");
//	if(f2==NULL)printf("file not open\n");


//	while(!feof(f2))
//	{
//		c=fgetc(f2);
//		if(c>='a'&&c<='z')break;
//	}



  // l=ftell(f2);l--;fseek(f2,l*sizeof(char),SEEK_SET);
	
   
f4=fopen("input.txt","r+b");
	if(f4==NULL)printf("file not open\n");
while(!feof(f4))
	{
		c=	fgetc(f4);
		if(c>='a'&&c<='z'){//fprintf(f3,"%c",c);
		total2++;}
	}

	//fflush(f3);
	
	
	
	//k=ftell(f4);
//	k--;
	//total1=k;
	 
    //f3=fopen("temp.txt","r+b");f2=fopen("input.txt","w+b");

		// fseek(f4,k*sizeof(char),SEEK_SET);


fseek(f4,0*sizeof(char),SEEK_SET);
   
   to=total2;
   
   q=(char*)malloc((to+1)*sizeof(char));
   cq=(char*)malloc((to+1)*sizeof(char));
   
   //printf("Total2=%d\n",total2);
   
fclose(f4);



f4=fopen("input.txt","r+b");
	if(f4==NULL)printf("file not open\n");
	   
	   i=0;
   while(!feof(f4))

	{
		c=fgetc(f4);//if(feof(f2))break;;
		
		if(c>='a'&&c<='z')
		{
			q[i++]=c;//n++;//l2=ftell(f2);

		}

   }
		//if(i>=38)
	//	{	

			q[i]='\0';




if(flag==0)
	{
f3=fopen("temp.txt","w+b");
	fseek(f4,0*sizeof(char),SEEK_SET);
	while(!feof(f4))
	{
		c=	fgetc(f4);
		if(c>='a'&&c<='z'){//fprintf(f3,"%c",c);
		total++;}
	}

	//fflush(f3);
	
	
	
	k=ftell(f4);//printf("k=%d\n",k);getch();
	 
	//fclose(f3);fclose(f2);
	l1=0;
	 k--;
	
	 
    //f3=fopen("temp.txt","r+b");f2=fopen("input.txt","w+b");

		 fseek(f4,k*sizeof(char),SEEK_SET);

		 
		
		 
		 do{
		 c=fgetc(f4);//printf("%c\n",c);getch();
		         
		 
		 if(c>='a'&&c<='z')
		 {
		 if(c=='a')
					c='t';
				else if(c=='t')
					c='a';
				else if(c=='c')
					c='g';
				else if(c=='g')
					c='c';

				fprintf(f3,"%c",c);
		 }
				k--;
				fseek(f4,k*sizeof(char),SEEK_SET);
		 }while(k>=l1);
	
	fflush(f3);

	flag=1;
	}
	fclose(f4);
	//f2=fopen("temp.txt","r+b");
	//fclose(f4);
	
	f4=fopen("temp.txt","r+b");

	
//total2=0;

//while(!feof(f4))
//	{
///		c=	fgetc(f4);
//		if(c>='a'&&c<='z'){//fprintf(f3,"%c",c);
//		total2++;}
//	}

	//fflush(f3);
	
	
//	fseek(f4,0*sizeof(char),SEEK_SET);
   
   //to=total2;
   
   //q=(char*)malloc((to)*sizeof(char));
   
   
   //printf("Total2=%d\n",total2);
   
   i=0;
   while(!feof(f4))

	{
		c=fgetc(f4);//if(feof(f2))break;;
		
		if(c>='a'&&c<='z')
		{
			cq[i++]=c;//n++;//l2=ftell(f2);

		}

   }
		//if(i>=38)
	//	{	

			cq[i]='\0';



q1=(char*)malloc((41)*sizeof(char));
r=(char*)malloc((LENGTH-40+6)*sizeof(char));



f_h=fopen("first_half.txt","w+");
cf_h=fopen("comp_first_half.txt","w+");
s_h=fopen("second_half.txt","w+");
cs_h=fopen("comp_second_half.txt","w+");

for(n=0;n<=to-39;n++)
		{
			j=0;
			
			//printf(" n=%d\n",n+1);
			
			for(i=n;i<n+40;++i)
				q1[j++]=q[i];q1[j]='\0';
			//total2=to;
			//flag2=0;
			for(i=5;i>=0;--i)
			if((l=check_first(q1,j-i))!=0)
			{
				//flag2=1;
				fprintf(f_h,"%d\t%d\n",n,l);
					
				break;
			}
		}


		for(n1=to-1;n1>=LENGTH-40;n1--)
			{
				
				j=0;//flag=0;
				for(i=n1;j<LENGTH-40;--i)
				r[j++]=q[i];
				
					r[j]='\0';//total2=i+1;

					if(check_2nd(r)==1)
					{
							fprintf(s_h,"%d\n",n1);
					}
		}








for(n=0;n<=to-40;n++)
		{
			j=0;
			
			//printf(" n=%d\n",n+1);
			
			for(i=n;i<n+40;++i)
				q1[j++]=cq[i];q1[j]='\0';
			//total2=to;
			//flag2=0;
			for(i=5;i>=0;--i)
			if((l=check_first(q1,j-i))!=0)
			{
				//flag2=1;
				fprintf(cf_h,"%d\t%d\n",n,l);
					
				break;
			}
		}


		for(n1=to-1;n1>=LENGTH-40;n1--)
			{
				
				j=0;//flag=0;
				for(i=n1;j<LENGTH-40;--i)
				r[j++]=cq[i];
				
					r[j]='\0';//total2=i+1;

					if(check_2nd(r)==1)
					{
							fprintf(cs_h,"%d\n",n1);
					}
		}


fflush(f_h);
fflush(s_h);
fflush(cf_h);
fflush(cs_h);

fclose(f_h);
fclose(s_h);
fclose(cf_h);
fclose(cs_h);


f_h=fopen("first_half.txt","r+");
cf_h=fopen("comp_first_half.txt","r+");
s_h=fopen("second_half.txt","r+");
cs_h=fopen("comp_second_half.txt","r+");





   while(LENGTH<=end)
{
   
   
	  o_n=-1;
	   p=(char*)malloc((LENGTH+1)*sizeof(char));

q1=(char*)malloc((41)*sizeof(char));
r=(char*)malloc((LENGTH-40+6)*sizeof(char));

rewind(f_h);
	
        
while(!feof(f_h))
{
	fscanf(f_h,"%d%d",&n,&l);if(n==o_n)break;else o_n=n;

			j=0;
			
			//printf(" n=%d\n",n+1);
			
			for(i=n;i<n+l;++i)
				q1[j++]=q[i];q1[j]='\0';rewind(s_h);o_n1=-1;


			//if(q1[j-4]=='t')
			//{
							

			while(!feof(s_h))
			{
			fscanf(s_h,"%d",&n1);if(n1==o_n1)break;else o_n1=n1;
			j=0;//flag=0;
				for(i=n1;j<LENGTH-l;--i)
				r[j++]=q[i];
				
					r[j]='\0';total2=i+1;

				
				
			pflag=0;
	
			//for(m=0;m<=5;++m)
			//{
				for(i=0,j=0;i<strlen(q1);i++)
				p[j++]=q1[i];
			  //p[j]='\0';

			
			  for(i=strlen(r)-1;i>=0;--i)
				  p[j++]=r[i];
			  p[j]='\0';
			  //strcat(p,q);
			//printf("q=%d\n",strlen(q)-m);
			//printf("r=%d\n",strlen(r)-4+m);
			//printf("p=%d\n",strlen(p));getch();
			



			//printf("OK %s  %d\n",p,strlen(p));getch();
			
			
			for(i=0;i<32;++i)
				for(j=0;j<80;++j)mat[i][j]=' ';
				for(i=0;i<64;++i)bp[i]=' ';



		//	if(pflag==0)
		//	{

			if(build_trna_gg(p,LENGTH,mat,anti,bp,a_arm,d_arm,ac_arm,t_arm)==1)
			{


				for(i=n-1,j=0;i>=0&&j<60;--i)
					sp1[j++]=q[i];
				sp1[j]='\0';

				for(i=total2-1,j=0;i>=0&&j<20;--i)
					sp3[j++]=q[i];
				sp3[j]='\0';

				for(i=n+l+1-1,j=0;i<to&&j<20;++i)
					sp2[j++]=q[i];
				sp2[j]='\0';

				for(i=total2+LENGTH-l,j=0;i<to&&j<60;++i)
					{sp4[j]=q[i];if(j<4)top[j]=q[i];
				j++;}
				sp4[j]='\0';j=0;while(top[j++]>='a');top[--j]='\0';


				for(i=n+l+1-1-6,j=0;i<to&&j<12;++i)
					if(n+l==total2)bh1[j++]='-';
					else
					bh1[j++]=q[i];
				bh1[j]='\0';

				for(i=total2-1,j=0;i>=0&&j<10;--i)
					if(n+l==total2)bh2[j++]='-';
					else
					bh2[j++]=q[i];
				bh2[j]='\0';
				add=0;


				if(n+l==total2)add=math_1str_4th(sp1,sp4,st1,st2)>0?4:0;

					else
					
				add=bh_loop(bh1,bh2)+math_1str_4th(sp1,sp4,st1,st2);


				
				
				

				pflag=1;

//printf("OK1\n"); getch(); 
				if(add>1)

				display(mat,anti,bp,a_arm,d_arm,ac_arm,t_arm,f1,f,n+1,n+l,total2+1,total2+LENGTH-l,p2,p4,p3,sp1,sp2,sp3,sp4,p,add,st1,st2,bh1,bh2,top);
			}
/*else if(build_trna_ag(p,LENGTH,mat,anti,bp,a_arm,d_arm,ac_arm,t_arm)==1)
			{

				for(i=n-1,j=0;i>=0&&j<60;--i)
					sp1[j++]=q[i];
				sp1[j]='\0';

				for(i=total2-1,j=0;i>=0&&j<20;--i)
					sp3[j++]=q[i];
				sp3[j]='\0';

				for(i=n+l+1-1,j=0;i<to&&j<20;++i)
					sp2[j++]=q[i];
				sp2[j]='\0';

				for(i=total2+LENGTH-l,j=0;i<to&&j<60;++i)
					sp4[j++]=q[i];
				sp4[j]='\0';


				for(i=n+l+1-1-10,j=0;i<to&&j<15;++i)
					if(n+l==total2)bh1[j++]='-';
					else
					bh1[j++]=q[i];
				bh1[j]='\0';

				for(i=total2-1+5,j=0;i>=0&&j<15;--i)
					if(n+l==total2)bh2[j++]='-';
					else
					bh2[j++]=q[i];
				bh2[j]='\0';
				add=0;


				if(n+l==total2)add=math_1str_4th(sp1,sp4,st1,st2);

					else
					
				add=bh_loop(bh1,bh2)+math_1str_4th(sp1,sp4,st1,st2);


				
				
				

				pflag=1;

//printf("OK1\n"); getch();
				if(add>0)

				display(mat,anti,bp,a_arm,d_arm,ac_arm,t_arm,f1,f,n+1,n+l,total2+1,total2+LENGTH-l,p2,p4,p3,sp1,sp2,sp3,sp4,p,add,st1,st2,bh1,bh2);
				}


else if(build_trna_cg(p,LENGTH,mat,anti,bp,a_arm,d_arm,ac_arm,t_arm)==1)
			{


			for(i=n-1,j=0;i>=0&&j<60;--i)
					sp1[j++]=q[i];
				sp1[j]='\0';

				for(i=total2-1,j=0;i>=0&&j<20;--i)
					sp3[j++]=q[i];
				sp3[j]='\0';

				for(i=n+l+1-1,j=0;i<to&&j<20;++i)
					sp2[j++]=q[i];
				sp2[j]='\0';

				for(i=total2+LENGTH-l,j=0;i<to&&j<60;++i)
					sp4[j++]=q[i];
				sp4[j]='\0';


				

			for(i=n+l+1-1-10,j=0;i<to&&j<15;++i)
					if(n+l==total2)bh1[j++]='-';
					else
					bh1[j++]=q[i];
				bh1[j]='\0';

				for(i=total2-1+5,j=0;i>=0&&j<15;--i)
					if(n+l==total2)bh2[j++]='-';
					else
					bh2[j++]=q[i];
				bh2[j]='\0';
				add=0;


				if(n+l==total2)add=math_1str_4th(sp1,sp4,st1,st2);

					else
					
				add=bh_loop(bh1,bh2)+math_1str_4th(sp1,sp4,st1,st2);


				
				
				

				pflag=1;

//printf("OK1\n"); getch();
				if(add>0)

				display(mat,anti,bp,a_arm,d_arm,ac_arm,t_arm,f1,f,n+1,n+l,total2+1,total2+LENGTH-l,p2,p4,p3,sp1,sp2,sp3,sp4,p,add,st1,st2,bh1,bh2);
			}





else if(build_trna9abs(p,LENGTH,mat,anti,bp,a_arm,d_arm,ac_arm,t_arm)==1)
			{

			for(i=n-1,j=0;i>=0&&j<60;--i)
					sp1[j++]=q[i];
				sp1[j]='\0';

				for(i=total2-1,j=0;i>=0&&j<20;--i)
					sp3[j++]=q[i];
				sp3[j]='\0';

				for(i=n+l+1-1,j=0;i<to&&j<20;++i)
					sp2[j++]=q[i];
				sp2[j]='\0';

				for(i=total2+LENGTH-l,j=0;i<to&&j<60;++i)
					sp4[j++]=q[i];
				sp4[j]='\0';


				

			for(i=n+l+1-1-10,j=0;i<to&&j<15;++i)
					if(n+l==total2)bh1[j++]='-';
					else
					bh1[j++]=q[i];
				bh1[j]='\0';

				for(i=total2-1+5,j=0;i>=0&&j<15;--i)
					if(n+l==total2)bh2[j++]='-';
					else
					bh2[j++]=q[i];
				bh2[j]='\0';
				add=0;


				if(n+l==total2)add=math_1str_4th(sp1,sp4,st1,st2);

					else
					
				add=bh_loop(bh1,bh2)+math_1str_4th(sp1,sp4,st1,st2);


				
				
				

				pflag=1;

//printf("OK1\n"); getch();
				if(add>0)

				display(mat,anti,bp,a_arm,d_arm,ac_arm,t_arm,f1,f,n+1,n+l,total2+1,total2+LENGTH-l,p2,p4,p3,sp1,sp2,sp3,sp4,p,add,st1,st2,bh1,bh2);
			}*/
			
			}
			}
			
					
		





rewind(cf_h);
		
o_n=-1;
		while(!feof(cf_h))
		{
				fscanf(cf_h,"%d%d",&n,&l);if(n==o_n)break;else o_n=n;

        
			j=0;
			//printf("complemented n=%d\n",n+1);
			for(i=n;i<n+l;++i)
				q1[j++]=cq[i];q1[j]='\0';
			//total2=to;
			rewind(cs_h);o_n1=-1;
			
			while(!feof(cs_h))
			{
			fscanf(cs_h,"%d",&n1);if(n1==o_n1)break;else o_n1=n1;
			
				

				
				j=0;//flag=0;
				for(i=n1;j<LENGTH-l;--i)
				r[j++]=cq[i];
				
					r[j]='\0';total2=i+1;

					
			
			
			
			
	
		
			  pflag=0;//k=--k1;fseek(f4,k*sizeof(char),SEEK_SET);


	//	for(m=0;m<=5;++m)
		//{
			for(i=0,j=0;i<strlen(q1);i++)
				p[j++]=q1[i];
			  //p[j]='\0';

			
			  for(i=strlen(r)-1;i>=0;--i)
				  p[j++]=r[i];
			  p[j]='\0';
			  //strcat(p,q);
			
			
	
			
			for(i=0;i<32;++i)
				for(j=0;j<80;++j)mat[i][j]=' ';
				for(i=0;i<64;++i)bp[i]=' ';

			//if(pflag==0)
		//	{
			if(build_trna_gg(p,LENGTH,mat,anti,bp,a_arm,d_arm,ac_arm,t_arm)==1)
			{

				
			
				pflag=1;


				for(i=n-1,j=0;i>=0&&j<60;--i)
					sp1[j++]=cq[i];
				sp1[j]='\0';

				for(i=total2-1,j=0;i>=0&&j<20;--i)
					sp3[j++]=cq[i];
				sp3[j]='\0';

				for(i=n+l,j=0;i<to&&j<20;++i)
					sp2[j++]=cq[i];
				sp2[j]='\0';

				for(i=total2+LENGTH-l,j=0;i<to&&j<60;++i)
				{sp4[j]=cq[i];if(j<4)top[j]=cq[i];j++;}
				sp4[j]='\0';j=0;while(top[j++]>='a');top[--j]='\0';



				for(i=n+l+1-1-6,j=0;i<to&&j<12;++i)
					if(n+l==total2)bh1[j++]='-';
					else
					bh1[j++]=cq[i];
				bh1[j]='\0';

				for(i=total2-1,j=0;i>=0&&j<10;--i)
					if(n+l==total2)bh2[j++]='-';
					else
					bh2[j++]=cq[i];
				bh2[j]='\0';
				add=0;


				if(n+l==total2)add=math_1str_4th(sp1,sp4,st1,st2)>0?4:0;

					else
					
				add=bh_loop(bh1,bh2)+math_1str_4th(sp1,sp4,st1,st2);











                if(add>1)

				cdisplay(mat,anti,bp,a_arm,d_arm,ac_arm,t_arm,f1,f,total-(n+l)+1,total-(n+1)+1,total-(total2+LENGTH-l)+1,total-(total2),p2,p4,p3,sp1,sp2,sp3,sp4,p,add,st1,st2,bh1,bh2,top);
			}


/*else if(build_trna_ag(p,LENGTH,mat,anti,bp,a_arm,d_arm,ac_arm,t_arm)==1)
			{

			pflag=1;


				for(i=n-1,j=0;i>=0&&j<60;--i)
					sp1[j++]=cq[i];
				sp1[j]='\0';

				for(i=total2-1,j=0;i>=0&&j<20;--i)
					sp3[j++]=cq[i];
				sp3[j]='\0';

				for(i=n+l,j=0;i<to&&j<20;++i)
					sp2[j++]=cq[i];
				sp2[j]='\0';

				for(i=total2+LENGTH-l,j=0;i<to&&j<60;++i)
					sp4[j++]=cq[i];
				sp4[j]='\0';



				for(i=n+l+1-1-10,j=0;i<to&&j<15;++i)
					if(n+l==total2)bh1[j++]='-';
					else
					bh1[j++]=cq[i];
				bh1[j]='\0';

				for(i=total2-1+5,j=0;i>=0&&j<15;--i)
					if(n+l==total2)bh2[j++]='-';
					else
					bh2[j++]=cq[i];
				bh2[j]='\0';
				add=0;


				if(n+l==total2)add=math_1str_4th(sp1,sp4,st1,st2);

					else
					
				add=bh_loop(bh1,bh2)+math_1str_4th(sp1,sp4,st1,st2);


				if(add>0)
				cdisplay(mat,anti,bp,a_arm,d_arm,ac_arm,t_arm,f1,f,total-(n+l)+1,total-(n+1)+1,total-(total2+LENGTH-l)+1,total-(total2),p2,p4,p3,sp1,sp2,sp3,sp4,p,add,st1,st2,bh1,bh2);
			}



else if(build_trna_cg(p,LENGTH,mat,anti,bp,a_arm,d_arm,ac_arm,t_arm)==1)
			{

				
			pflag=1;


			for(i=n-1,j=0;i>=0&&j<60;--i)
					sp1[j++]=cq[i];
				sp1[j]='\0';

				for(i=total2-1,j=0;i>=0&&j<20;--i)
					sp3[j++]=cq[i];
				sp3[j]='\0';

				for(i=n+l,j=0;i<to&&j<20;++i)
					sp2[j++]=cq[i];
				sp2[j]='\0';

				for(i=total2+LENGTH-l,j=0;i<to&&j<60;++i)
					sp4[j++]=cq[i];
				sp4[j]='\0';



				for(i=n+l+1-1-10,j=0;i<to&&j<15;++i)
					if(n+l==total2)bh1[j++]='-';
					else
					bh1[j++]=cq[i];
				bh1[j]='\0';

				for(i=total2-1+5,j=0;i>=0&&j<15;--i)
					if(n+l==total2)bh2[j++]='-';
					else
					bh2[j++]=cq[i];
				bh2[j]='\0';
				add=0;


				if(n+l==total2)add=math_1str_4th(sp1,sp4,st1,st2);

					else
					
				add=bh_loop(bh1,bh2)+math_1str_4th(sp1,sp4,st1,st2);



				if(add>0)
				cdisplay(mat,anti,bp,a_arm,d_arm,ac_arm,t_arm,f1,f,total-(n+l)+1,total-(n+1)+1,total-(total2+LENGTH-l)+1,total-(total2),p2,p4,p3,sp1,sp2,sp3,sp4,p,add,st1,st2,bh1,bh2);
			}




else if(build_trna9abs(p,LENGTH,mat,anti,bp,a_arm,d_arm,ac_arm,t_arm)==1)
			{





				
			 pflag=1;


				for(i=n-1,j=0;i>=0&&j<60;--i)
					sp1[j++]=cq[i];
				sp1[j]='\0';

				for(i=total2-1,j=0;i>=0&&j<20;--i)
					sp3[j++]=cq[i];
				sp3[j]='\0';

				for(i=n+l,j=0;i<to&&j<20;++i)
					sp2[j++]=cq[i];
				sp2[j]='\0';

				for(i=total2+LENGTH-l,j=0;i<to&&j<60;++i)
					sp4[j++]=cq[i];
				sp4[j]='\0';



				for(i=n+l+1-1-10,j=0;i<to&&j<15;++i)
					if(n+l==total2)bh1[j++]='-';
					else
					bh1[j++]=cq[i];
				bh1[j]='\0';

				for(i=total2-1+5,j=0;i>=0&&j<15;--i)
					if(n+l==total2)bh2[j++]='-';
					else
					bh2[j++]=cq[i];
				bh2[j]='\0';
				add=0;


				if(n+l==total2)add=math_1str_4th(sp1,sp4,st1,st2);

					else
					
				add=bh_loop(bh1,bh2)+math_1str_4th(sp1,sp4,st1,st2);


				if(add>0)
				cdisplay(mat,anti,bp,a_arm,d_arm,ac_arm,t_arm,f1,f,total-(n+l)+1,total-(n+1)+1,total-(total2+LENGTH-l)+1,total-(total2),p2,p4,p3,sp1,sp2,sp3,sp4,p,add,st1,st2,bh1,bh2);
			}*/
		
			}
			}

		

//fclose(f4);	
printf("Length=%d completed\n",LENGTH);
LENGTH++;
}











	
	
	printf("Completed\n");getch();






}






