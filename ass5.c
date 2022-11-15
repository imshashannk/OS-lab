#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
pthread_mutex_t mutex,writeblock;
int data = 0,rcount = 0;
void *reader(void *arg)
{
int waittime;
waittime = rand() % 5;
printf("\nReader is trying to enter");
pthread_mutex_lock(&mutex);
rcount = rcount + 1;
if(rcount==1)
pthread_mutex_lock(&writeblock);
pthread_mutex_unlock(&mutex);
printf("\n Reader %d is inside ",rcount);
printf("\nData read by the reader%d is %d\n",rcount,data);
sleep(waittime);
pthread_mutex_lock(&mutex);
rcount = rcount - 1;
if(rcount==0)
pthread_mutex_unlock(&writeblock); //writer can enter
pthread_mutex_unlock(&mutex);
// reader leaves
printf("\nReader is Leaving");
}
void *writer(void *arg)
{
int waittime;
waittime=rand() % 3;
printf("\nWriter is trying to enter");
pthread_mutex_lock(&writeblock);
data++;
printf("\nData writen by the writer is %d\n",data);
sleep(waittime);
pthread_mutex_unlock(&writeblock);
printf("\nWriter is leaving");
sleep(30);
}
main()
{
int i,b;
pthread_mutex_init(&mutex,NULL);
pthread_mutex_init(&writeblock,NULL);
pthread_t rtid[5],wtid[5];for(i=0;i<=2;i++)
{
pthread_create(&wtid[i],NULL,writer,NULL);
pthread_create(&rtid[i],NULL,reader,NULL);
}
for(i=0;i<=2;i++)
{
pthread_join(wtid[i],NULL);
pthread_join(rtid[i],NULL);
}
}
