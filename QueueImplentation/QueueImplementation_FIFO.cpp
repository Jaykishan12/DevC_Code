#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct __QUEUE {
  int8_t *Buffer; 
  uint32_t size;
  uint32_t readPos;
  uint32_t writePos;
  uint32_t overflow;
} QUEUE;

#define KEYBUFSIZE 100
QUEUE KeyInputQueue;
int8_t KeyBuf[KEYBUFSIZE];


int32_t QueueInit(QUEUE *Queue, uint32_t size, int8_t *ptr) {
	int32_t retval = 0;
	if (Queue != NULL) {
		Queue->Buffer = ptr;
		if (Queue->Buffer != NULL) {
			Queue->size = size;
			Queue->readPos = 0;
			Queue->writePos = 0;
			Queue->overflow = 0;
		} else {
			retval = -1;
		}
	} else {
		retval = -1;
	}
	return retval;
}

int32_t getQueueSize(QUEUE *Queue) {
	int32_t retval = 0;
	if (Queue != NULL) {
		if ((Queue->readPos <= Queue->writePos) && Queue->overflow == 0) {
			retval = (Queue->writePos) - Queue->readPos;
		} else if ((Queue->writePos == Queue->readPos)
				&& Queue->overflow == 1) {
			retval = Queue->size;
		} else {
			retval = (Queue->size - Queue->readPos) + Queue->writePos;
		}
	}

	return retval;
}

int32_t getQueueAvailableSize(QUEUE *Queue) {
	int32_t retval;
	if (Queue != NULL) {
		retval = Queue->size - getQueueSize(Queue);
	} else {
		retval = -1;
	}
	return retval;
}

int32_t pushToQueue(QUEUE *Queue, int8_t *buffer, uint32_t size) {
	int32_t retval = -1;
	uint32_t i;
	uint32_t BufSize = 0;
//	portENTER_CRITICAL();

	if (Queue != NULL) {
		BufSize = getQueueAvailableSize(Queue);
		if (BufSize >= size) {
			for (i = 0; i < size; i++) {
				Queue->Buffer[Queue->writePos] = buffer[i];
				if (Queue->writePos + 1 == Queue->size) {
					Queue->overflow = 1;
					Queue->writePos = 0;
				} else {
					Queue->writePos++;
				}
			}
			retval = size;
		} else if (BufSize < size) {
			retval = BufSize;
		}
	} else {
		retval = -1;
	}
//	portEXIT_CRITICAL();
	return retval;
}

int32_t peekFirstIntoQueue(QUEUE *Queue, int8_t *buffer, uint32_t size) {
	int32_t retval = -1;
	int32_t i, index;
	uint32_t readPosition = Queue->readPos;
	readPosition=readPosition;//to remove warning
	if (Queue != NULL) {
		if (getQueueSize(Queue) >= size) {
			for (i = 0; i < size; i++) {
				index = (Queue->writePos - size) + i;
				if (index < 0 && index > Queue->size)
					while (1)
						; //assert

				buffer[i] = Queue->Buffer[index];
			}

			retval = size;
		} else {
			retval = -1;
		}
	} else {
		retval = -1;
	}
	return retval;
}

int32_t popFirstFromQueue(QUEUE *Queue, int8_t *buffer, uint32_t size)
{
  int32_t retval= 0;
  uint32_t i;
  uint32_t BufSize;

  if ( Queue != NULL )	
  {
     BufSize = getQueueSize (Queue);
     if ( BufSize >= size )
     {
        for(i=0;i<size;i++) 
        {	
          buffer[i] = Queue->Buffer [ Queue->readPos ];
          if ( Queue->readPos+1 == Queue->size )
          {
            Queue->readPos = 0;
            Queue->overflow = 0 ;
          }
          else
          {
            Queue->readPos++ ;
          }
        }    
        retval = size ;
    }
    else if(BufSize < size )
    {
      retval = BufSize;
    }
  }
  else
  {
    retval = -1;
  }
  return retval;
}

void InitInputUtils(void)
{
	QueueInit(&KeyInputQueue,sizeof(KeyBuf),KeyBuf);
}

int main(){
	char PushBuffer[100], PopBuffer[200];
	InitInputUtils();
	memset(PushBuffer, 0x00, sizeof(PushBuffer));
	strcpy(PushBuffer, "HoneyWelleeeeeeeeeeeeeeeleeee");
	printf("Str Pushed is %s\n",PushBuffer);
	pushToQueue(&KeyInputQueue, (int8_t *)PushBuffer, 99);
	strcpy(PushBuffer, "GyyyyWelleeeeeeeeeeeeeeeleeee");
	pushToQueue(&KeyInputQueue, (int8_t *)PushBuffer, 25);
	memset(PopBuffer, 0x00, sizeof(PopBuffer));
	popFirstFromQueue(&KeyInputQueue,(int8_t *) PopBuffer,50);
	printf("Popped string1 %s\n",PopBuffer);
	memset(PopBuffer, 0x00, sizeof(PopBuffer));
	
	popFirstFromQueue(&KeyInputQueue, (int8_t *)PopBuffer,getQueueSize(&KeyInputQueue));
	//PopBuffer[] = '\0';
	printf("Popped string2 %s\n",PopBuffer);
}
