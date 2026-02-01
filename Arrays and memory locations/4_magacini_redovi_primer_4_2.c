#include <stdio.h>
#include <stdlib.h>
#define QUEUESIZE 20
typedef int info_t;

typedef struct s {
	info_t Q[QUEUESIZE];
	int f, r; // info_t f,r; 
} queue;

void QueueOverflow(void) {
	fprintf(stderr, "ERROR: QueueOverflow\n");
	exit(-1);
}

void QueueUnderflow(void) {
	fprintf(stderr, "ERROR: QueueUnderflow\n");
	exit(-1);
}

//void Put(queue * m, info_t x) { // за линеарен ред
//	if (m->r >= QUEUESIZE - 1)
//		QueueOverflow();
//	else {
//		if (m->f == -1) m->f = 0;
//		m->Q[++(m->r)] = x;
//	}
//} // end Put
//
//info_t Pull(queue * m) { // за линеарен ред
//	int x;
//	if (m->f == -1) QueueUnderflow();
//	else {
//		x = m->Q[m->f];
//		if (m->f == m->r)
//			m->f = m->r = -1;
//		else m->f++;
//	}
//	return x;
//} // end Pull

void Put(queue * m, info_t x) {
	if (m->r >= QUEUESIZE - 1)
		m->r = 0;
	else
		m->r++;
	if (m->r == m->f) 	QueueOverflow();
	else {
		m->Q[m->r] = x;
		if (m->f == -1)
			m->f = m->r;
	}
} // end Put

info_t Pull(queue * m) {
	info_t x;
	if (m->r == -1) 	QueueUnderflow();
	else {
		x = m->Q[m->f];
		if (m->f == m->r)
			m->f = m->r = -1;
		else
			if (m->f >= QUEUESIZE - 1)
				m->f = 0;
			else
				m->f++;
	}
	return(x);
} // Pull

info_t Peek(queue * m) {
	if (m->f == -1)
		QueueUnderflow();
	return (m->Q[m->f]);
} // end Peek
void Init(queue * m) {
	m->f = m->r = -1;
} // end Init
int isEmpty(queue * m) {
	return((m->f)<0);
} // end isEmpty
int QueueLen(queue * m) {
	if (m->r == -1)
		return(0);
	else if (m->r >= m->f)
		return m->r - m->f + 1;
	else
		return (QUEUESIZE - (m->f - m->r));
} // end QueueLen

int main() {
	return(0);
} //end main

