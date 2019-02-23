/*
 * queue.h
 *
 *  Created on: Feb 23, 2019
 *      Author: hasan
 */

#ifndef SRC_QUEUE_H_
#define SRC_QUEUE_H_

#include <pthread.h>

class queue {
	enum{BUFF_SIZE = 101};
	int head;
	int tail;
	int currSize;

	static char buffer[BUFF_SIZE];

	pthread_mutex_t lock;
	pthread_cond_t  cond;

	queue();
	~queue();
	void add(const char *data, int len);
	int remove(char *data);

};



#endif /* SRC_QUEUE_H_ */
