/*
 * queue.cpp
 *
 *  Created on: Feb 24, 2019
 *      Author: hasan
 */


#include "queue.h"




//pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t  cond = PTHREAD_COND_INITIALIZER;

char queue::buffer[BUFF_SIZE];

queue::queue() {
	head = tail = currSize=0;

	pthread_mutex_init(&lock, NULL);
	pthread_cond_init(&cond, NULL);
}

queue::~queue() {
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&cond);
}

void queue::add(const char * data, int len) {
	pthread_mutex_lock(&lock);
	while(1) {
		if(currSize+len < BUFF_SIZE) {
			for(int i=0; i<len; i++) {
				tail = (tail+1)%BUFF_SIZE;
				buffer[tail] = data[i];
			}
			currSize += len;
			break;
		}
		else {
			pthread_cond_wait(&cond, &lock);
		}
	}
	pthread_mutex_unlock(&lock);

}

int queue::remove(char *data) {

	int ret;
	pthread_mutex_lock(&lock);

	if(currSize == 0) {

		ret = 0;
	}
	else {
		for(int i=0; i<currSize; i++) {
			head = (head+1)%BUFF_SIZE;
			data[i] = buffer[head];
		}
		currSize = 0;
		ret = currSize;
		pthread_cond_signal(&cond);
	}

	pthread_mutex_unlock(&lock);

	return currSize;
}

