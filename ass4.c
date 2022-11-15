#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
int buffer[10],size=10,index1=0;
sem_t full,empty;
pthread_t tidp[10],tidc[10];
pthread_mutex_t lock;
void insert1(int a);
void remove1();
void *producer()
{
int item = rand() % 100;
sem_wait(&full);
pthread_mutex_lock(&lock);
insert1(item);
pthread_mutex_unlock(&lock);
sem_post(&empty);
}
void *consumer()
{
sem_wait(&empty);
pthread_mutex_lock(&lock);
remove1();
pthread_mutex_unlock(&lock);
sem_post(&full);
}void insert1(int a)
{
int item=a;
if(index1<size)
{
buffer[index1]=item;
index1++;
printf("\n Element entered by producer is\t%d\n",item);
}
else printf("\nBuffer full\n");
}
void remove1()
{
if(index1>0)
{
index1--;
printf("\nRemoved item by consumer is\t %d\t",buffer[index1]);
}
else printf("\nBuffer is empty\n");
}
void main()
{
int i;
sem_init(&full,1,size);
sem_init(&empty,1,0);
pthread_mutex_init(&lock,NULL);for(i=0;i<size;i++)
{
pthread_create(&tidc[i],NULL,consumer,NULL);
pthread_create(&tidp[i],NULL,producer,NULL);
}
for(i=0;i<size;i++)
{
pthread_join(tidc[i],NULL);
pthread_join(tidp[i],NULL);
}
}
