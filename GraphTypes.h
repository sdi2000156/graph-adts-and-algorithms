#define MAXVERTEX 20

typedef enum {FALSE, TRUE} Boolean;

typedef int Vertex;

typedef struct edge {
   Vertex endpoint;
   struct edge *nextedge;
   struct edge *prevedge;
} Edge;

typedef struct graph {
   int n;     /* number of vertices in the graph */
   Edge *firstedge[MAXVERTEX];
   Edge *revedge[MAXVERTEX];
   Vertex *data[MAXVERTEX];
   int max_vertexes;
} Graph;


typedef struct list* List;
typedef struct list_node* ListNode;
