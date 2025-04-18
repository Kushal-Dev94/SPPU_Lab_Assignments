#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#define maxsize 20
typedef struct 
{
	int in,out;
	int list[maxsize];
	sem_t full;
	sem_t emp;
	pthread_mutex_t lock;
}Itemlist;
Itemlist A;
int item,size;
void *prod(void *arg);
void *cust(void *arg);
void init();
void main()
{
	int np,nc,i;
	init();
	pthread_t pd[5],cus[5];
	printf("\nEnter no of producers :");
	scanf("%d",&np);
	printf("\nEnter no of customers: ");
	scanf("%d",&nc);
	printf("\nhow many items to be produced :");
	scanf("%d",&size);
	for(i=0;i<np;i++)
	{
		int *arg=malloc(sizeof(int *));
		*arg=i;
		pthread_create(&pd[i],NULL,prod,arg);
		printf("\nproducer thread %d is created",i+1);
	}
	for(i=0;i<nc;i++)
	{
		int *arg=malloc(sizeof(int *));
		*arg=i;
		pthread_create(&cus[i],NULL,cust,arg);
		printf("\ncustomer thread %d is created",i+1);
	}
	for(i=0;i<np;i++)
	{
		pthread_join(pd[i],NULL);
		printf("\nproducer thread %d is finished",i+1);
	}
	for(i=0;i<nc;i++)
	{
		pthread_join(cus[i],NULL);
		printf("\ncustomer thread %d is finished",i+1);
	}
}
void *prod(void *arg)
{
	int i=*(int *)arg;
	while(item<size+1)
	{
		sem_wait(&A.emp);
		pthread_mutex_lock(&A.lock);
		printf("\nproducer %d has produced item %d ",i+1,item);
		A.list[(A.in++)%maxsize]=item++;
		pthread_mutex_unlock(&A.lock);
		sem_post(&A.full);
		sleep(1);
	}

}
void *cust(void *arg)
{
	int i=*(int *)arg;
	while(1)
	{
		sem_wait(&A.full);
		pthread_mutex_lock(&A.lock);
		printf("\ncustomer %d purchased item %d ",i+1,A.list[(A.out++)%maxsize]);
		pthread_mutex_unlock(&A.lock);
		sem_post(&A.emp);
	}

}
void init()
{
	A.in=0;A.out=0;
	sem_init(&A.full,0,0);
	sem_init(&A.emp,0,maxsize);
	item=1;
	pthread_mutex_init(&A.lock,NULL);
}


