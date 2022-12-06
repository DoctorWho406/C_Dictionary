typedef struct list_node list_node_t;

#ifdef INIT_LIST_NODE
struct list_node {
    struct list_node *next;
};

#undef INIT_LIST_NODE
#endif