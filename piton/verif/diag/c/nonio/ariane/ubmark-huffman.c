 //========================================================================
 // huffman encoding
 //======================================================================== 

//#include "ubmark.h"
#include <string.h>
 
typedef struct node_t {
	struct node_t *left, *right;
	int freq;
	char c;
} *node;
 
struct node_t pool[256] = {{0}};
node qqq[255], *q = qqq - 1;
int n_nodes = 0, qend = 1;
char *code[128] = {0}, buf[1024];
 
node new_node(int freq, char c, node a, node b)
{
	node n = pool + n_nodes++;
	if (freq) n->c = c, n->freq = freq;
	else {
		n->left = a, n->right = b;
		n->freq = a->freq + b->freq;
	}
	return n;
}
 
/* priority queue */
void qinsert(node n)
{
	int j, i = qend++;
	while ((j = i / 2)) {
		if (q[j]->freq <= n->freq) break;
		q[i] = q[j], i = j;
	}
	q[i] = n;
}
 
node qremove()
{
	int i, l;
	node n = q[i = 1];
 
	if (qend < 2) return 0;
	qend--;
	while ((l = i * 2) < qend) {
		if (l + 1 < qend && q[l + 1]->freq < q[l]->freq) l++;
		q[i] = q[l], i = l;
	}
	q[i] = q[qend];
	return n;
}
 
/* walk the tree and put 0s and 1s */
void build_code(node n, char *s, int len)
{
	static char *out = buf;
	if (n->c) {
		s[len] = 0;
		strcpy(out, s);
		code[(unsigned int)n->c] = out;
		out += len + 1;
		return;
	}
 
	s[len] = '0'; build_code(n->left,  s, len + 1);
	s[len] = '1'; build_code(n->right, s, len + 1);
}
 
void init(const char *s)
{
	int i, freq[128] = {0};
	char c[16];
 
	while (*s) freq[(int)*s++]++;
 
	for (i = 0; i < 128; i++)
		if (freq[i]) qinsert(new_node(freq[i], i, 0, 0));
 
	while (qend > 2) 
		qinsert(new_node(0, 0, qremove(), qremove()));
 
	build_code(q[1], c, 0);
}
 
void encode(const char *s, char *out)
{
	while (*s) {
		strcpy(out, code[(unsigned int)*s]);
		out += strlen(code[(unsigned int)*s++]);
	}
}
 
void decode(const char *s, char *out, node t)
{
	node n = t;
	int i = 0;
	while (*s) {
		if (*s++ == '0') n = n->left;
		else n = n->right;
 
		if (n->c)
		{
			out[i] = n->c;
			i++;
			n = t;
		}
	}
}
 
int main(void)
{
	int i;

	//test_stats_on( 0 );

	const char *str = "this is an example for huffman encoding";
	char buf[1024], out[1024];

	init(str);
	for (i = 0; i < 128; i++);
 
	encode(str, buf);
 
	decode(buf, out, q[1]);

	//test_stats_off( 0 );
	
	//test_pass(0); 
    pass();
	return 0;
}
