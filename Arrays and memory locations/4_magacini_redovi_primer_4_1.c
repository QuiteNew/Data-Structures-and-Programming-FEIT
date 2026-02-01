#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 20

typedef char info_t;

typedef struct s {
	info_t S[STACKSIZE];
	int top;
} stack;

void Init(stack * m) {
	m->top = -1;
}

void StackOverflow(void) {
	fprintf(stderr, "ERROR: StackOverflow\n");
	exit(-1);
}

void StackUnderflow(void) {
	fprintf(stderr, "ERROR: StackUnderflow\n");
	exit(-1);
}

void Push(stack * m, info_t x) {
	if (m->top >= STACKSIZE - 1)
		StackOverflow();
	m->S[++(m->top)] = x;
}

info_t Peek(stack * m) {
	if (m->top<0)
		StackUnderflow();
	return (m->S[(m->top)]);
}

info_t Pop(stack *m) {
	if (m->top<0)
		StackUnderflow();
	return(m->S[(m->top)--]);
}

int isEmpty(stack *m) {
	return((m->top)<0);
}

void ExprError(char * n, char * s) {
	int i;
	printf("Error in expresion:\n%s\n", n);
	//printf(" ");
	for (i = 0; i<(s - n); i++)
		putchar(' ');
	putchar('^');
	exit(-1);
} /* ()()[](([{()()}()[{()()}()]])) */

int main() {
	stack mag, *m = &mag;
	char niza[80], *s = niza;
	Init(m);
	printf("->");
	scanf("%s", niza);

	while (*s) {
		switch (*s) {
		case '(':
		case '[':
		case '{':Push(m, *s); break;
		case ')':if (isEmpty(m) || Pop(m) != '(')  					ExprError(niza, s); break;
		case ']':if (isEmpty(m) || Pop(m) != '[') 					ExprError(niza, s); break;
		case '}':if (isEmpty(m) || Pop(m) != '{') 					ExprError(niza, s); break;
		} // case
		s++;
	} // while

	if (!isEmpty(m))
		ExprError(niza, s);
	else
		printf("Expression OK\n");
	return(0);
} //end main
