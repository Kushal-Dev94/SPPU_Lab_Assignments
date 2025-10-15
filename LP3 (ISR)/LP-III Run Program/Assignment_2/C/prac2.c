#include <stdio.h>
//#include<conio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
/***********************************************************************/
int no=0,i=0,k=0,j=0,flag=0;
char filename[10][20];
char kw[30][30],token[30];
int doc[150],dummy;
float centroid[150],temp=0,temp1=0,temp2=0;
float temp3[10];
char cl1[15][3];
FILE *fp;
/***********************************************************************/
void keywords()
{
k=0;
for(i=1;i<=no;i++)
{
fp=fopen(filename[i],"r");
if(fp==NULL)
{
printf("\nCant read input file");
}
else
{
while(!feof(fp))
{
fscanf(fp,"%s",token);
fscanf(fp,"%d",&dummy);
flag=0;
for(j=0;j<k;j++)
{
if(strcmp(kw[j],token)==0)
{
flag=1;
break;
}
}
if(flag==0)
{
strcpy(kw[k],token);
k++;
}
}
}
fclose(fp);
}
for(i=1;i<=no;i++)
{
fp=fopen(filename[i],"r");
if(fp!=NULL)
{
while(!feof(fp))
{
fscanf(fp,"%s",token);
fscanf(fp,"%d",&dummy);
for(j=0;j<k;j++)
{
if(strcmp(kw[j],token)==0)
{
doc[k*(i-1)+j]=dummy;
break;
}
}
}
}
fclose(fp);
}
}
/***********************************************************************/
void clustering()
{
int l=0,cluster,pri=0,m=0,c=0;
char ctemp[3]="C1",ctemp1[3]="D1";
float temp31;
for(i=0;i<k;i++)
{
centroid[i]=doc[i];
}
strcpy(cl1[0],ctemp);
strcpy(cl1[1],ctemp1);
printf("\n%s = { %s }",cl1[0],cl1[1]);
pri=2;
cluster=0;
for(j=1;j<no;j++)
{
m=0;
printf("\n\n\n\nConsider D%d,",j+1);
while(m<=cluster)
{
temp=0;temp1=0;temp2=0;
for(i=0;i<k;i++)
{
temp=temp+(centroid[m*k+i]*doc[j*k+i]);
temp1=temp1+(pow(centroid[m*k+i],2));
temp2=temp2+(pow(doc[j*k+i],2));
}
temp3[m]=(float)(2*temp)/(temp1+temp2);
printf("\n\nSim( D%d , C%d )= %.2f ",j+1,m+1,temp3[m]);
m++;
}
temp31=temp3[0];
c=0;
for(m=1;m<=cluster;m++)
{
if(temp31<temp3[m])
{
temp31=temp3[m];
c=m;
}
}
if(temp31>0.60)
{
printf("\n\n\nSmax( D%d , C%d )= %.2f",j+1,c+1,temp31);
printf("\n\nThreshold Value = 0.60");
printf("\n\n Smax < Threshold Value (0.60)");
printf("\n\nNew Clusters ,");
if(c!=cluster)
{
for(m=0;strcmp(cl1[m],"\0")!=0;m++)
{
}
ctemp[1]=c+2+48;
for(i=m;strcmp(cl1[i],ctemp)!=0;i--)
{
strcpy(cl1[i],cl1[i-1]);
}
strcpy(cl1[i],cl1[i-1]);
ctemp1[1]=j+1+48;
strcpy(cl1[i],ctemp1);
pri++;
}
else
{
ctemp1[1]=j+1+48;
strcpy(cl1[pri++],ctemp1);
}
for(i=0;i<k;i++)
{
centroid[c*k+i]=(centroid[c*k+i]+doc[j*k+i])/2;
}
}
else
{
printf("\n\n\nSmax( D%d , C%d )= %.2f",j+1,c+1,temp31);
printf("\n\nThreshold Value = 0.60");
printf("\n\n Smax < Threshold Value (0.60)");
printf("\n\nNew Clusters ,");
cluster++;
ctemp[1]=cluster+1+48;
strcpy(cl1[pri++],ctemp);
ctemp1[1]=j+1+48;
strcpy(cl1[pri++],ctemp1);
for(i=0;i<k;i++)
{
centroid[cluster*k+i]=doc[j*k+i];
}
}
printf("\n\n\n");
for(i=0;strcmp(cl1[i],"\0")!=0;i++)
{
if(cl1[i][0]=='C')
{
printf("%s = { ",cl1[i]);
l=i+1;
while(cl1[l][0]!='C'&&strcmp(cl1[l],"\0")!=0)
{
printf("%s ",cl1[l]);
l++;
}
printf("}   ");
}
}
//getch();
}
}
/***********************************************************************/
void main()
{
//clrscr();
system("clear");
printf("\nEnter no. of Documents for Clustering:-  ");
scanf("%d",&no);
printf("\nEnter documents name one by one:- ");
for(i=1;i<=no;i++)
{
scanf("%s",filename[i]);
}
//clrscr();
system("clear");
for(i=1;i<=no;i++)
{
strcat(filename[i],".txt");
}
if(no<=1)
{
printf("\nNo. of documents should be greater than 1!!!!");
//getch();
exit(0);
}
else
{
keywords();
clustering();
}
}


