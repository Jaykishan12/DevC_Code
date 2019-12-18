#include <stdio.h>
#include <stdint.h>

#define U32 uint32_t
#define S32 int32_t
#define S8 int8_t
#define U8 uint8_t

typedef struct Queue_st{
	U8 *ptr;
	U32 readpos;
	U32 writepos;
	U32 size;
	U32 Overflow;
}QUEUE;

#define QUEUEBUFFSIZE 100
U8 QueueBuffer[QUEUEBUFFSIZE];
QUEUE Queue;


S32 QueueInit(QUEUE *Queue, U8 *Ptr, U32 size){
	S8 retval = -1;
	
	do{
		if(Queue != NULL)
		{
			Queue->ptr = Ptr;
			if(Queue->ptr != NULL)
			{
				Queue->writepos = 0;
				Queue->readpos = 0;
				Queue->Overflow = 0;
				Queue->size = size;
				retval = size;
			}else{
				break;
			}
		}else
		{
			break;	
		}	
	}while(0);
	return retval;
}

void InitAppUtils(){
	QueueInit(&Queue,QueueBuffer,QUEUEBUFFSIZE);
}

S32 getQueueSize(QUEUE *Queue){
	S32 retval = -1;
	
	do
	{
		if(Queue != NULL)
		{
			if((Queue->writepos >= Queue->readpos) && (Queue->Overflow == 0))
			{
				retval = Queue->writepos - Queue->readpos;
				break;
			}else if((Queue->readpos == Queue->writepos) && (Queue->Overflow == 1))
			{
				retval = Queue->size;
				break;
			}else
			{
				retval = Queue->size - Queue->readpos + Queue->writepos;
				break;
			}
		}
	}while(0);	
}

S32 getQueueAvailableSize(QUEUE *Queue)
{
	S32 retval;
	if (Queue != NULL) {
		retval = Queue->size - getQueueSize(Queue);
	} else {
		retval = -1;
	}
	return retval;
}

S32 pushToQueue(QUEUE *Queue, U8 *Ptr, U32 Size)
{
	U32 i = 0;
	U32 BufSize;
	S32 retval = -1;
	
	do{
		if(Queue != NULL)
		{
			BufSize = getQueueAvailableSize(Queue);
			if(BufSize > Size){
				for(i = 0; i < Size; i++){
					Queue->ptr[Queue->writepos] = Ptr[i];
					if((Queue->writepos + 1) == Queue->size){
						Queue->Overflow = 1;
						Queue->writepos = 0;
					}else {
						Queue->writepos++;
					}
				}
			}else 
			retval = -1;
		}else
		retval = -1;
	}while(0);
	return retval;
}


S32 popfromQueue(QUEUE *Queue, U8 *Ptr, U32 Size)
{
	U32 i = 0;
	U32 BufSize;
	S32 retval = -1;
	do{
		if(Queue != NULL)
		{
			BufSize = getQueueAvailableSize(Queue);
			if(BufSize > Size){
				for(i = 0; i < Size; i++){
					Ptr[i] = Queue->ptr[Queue->readpos];
					if((Queue->readpos + 1) == Queue->size){
						Queue->Overflow = 0;
						Queue->writepos = 0;
					}else {
						Queue->readpos++;
					}
				}
			}else {
				retval = -1;
				break;
			}
		}else
		retval = -1;
	}while(0);
	return retval; 
}

S32 peekintoQueue(QUEUE *Queue, U8 *Ptr, U32 Size){
	U32 i = 0;
	U32 index, BufSize;
	
	do{
		if(Queue != NULL){
			BufSize = getQueueAvailableSize(Queue);
			if(BufSize > Size){
				for(i = 0; i < Size; i++){
					index = Queue->readpos;
					Ptr[i] = Queue->ptr[index];
					if((index + 1) == Queue->size){
						index = 0;
					}else{
						index++;
					}
				}
			}
		}
	}while(0);
}

int main(){
	return 0;
}
