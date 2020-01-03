#include <cstdio>

template<class T>
struct segment_tree{
    struct node{
        T data=0;
        node *left=0, *right=0;
    };

    node *root;
    segment_tree(){
        root=new node;
    }

    T order_by_key(T key, node **tree_node, T tree_left=0, T tree_right=1<<30){
        if(!(*tree_node) || tree_left>key || tree_left>tree_right){
            return 0;
        }
        if(tree_right<=key){
            return (*tree_node)->data;
        }
        T tree_mid=(tree_left+tree_right)>>1;
        return order_by_key(key, &((*tree_node)->left), tree_left, tree_mid) +
               order_by_key(key, &((*tree_node)->right), tree_mid+1, tree_right);
    }

    T order_by_key(T key){
        return order_by_key(key, &root);
    }

    void insert_key(T key, node **tree_node, T tree_left=0, T tree_right=1<<30){
        if(key<tree_left || key>tree_right || tree_left>tree_right){
            return ;
        }
        if(!(*tree_node)){
            *tree_node=new node;
        }
        if(tree_left==tree_right){
            (*tree_node)->data=1;
            return;
        }
        T tree_mid=(tree_left+tree_right)>>1;
        insert_key(key, &((*tree_node)->left), tree_left, tree_mid);
        insert_key(key, &((*tree_node)->right), tree_mid+1, tree_right);
        (*tree_node)->data=0;
        if((*tree_node)->left){
            (*tree_node)->data+=(*tree_node)->left->data;
        }
        if((*tree_node)->right){
            (*tree_node)->data+=(*tree_node)->right->data;
        }
    }

    void insert_key(T key){
        insert_key(key, &root);
    }

    bool find_key(T key, node *tree_node, T tree_left=0, T tree_right=1<<30){
        if(!tree_node || key<tree_left || key>tree_right || tree_left>tree_right){
            return 0;
        }
        if(tree_left==tree_right){
            return tree_node->data;
        }
        T tree_mid=(tree_left+tree_right)>>1;
        return find_key(key, tree_node->left, tree_left, tree_mid) ||
               find_key(key, tree_node->right, tree_mid+1, tree_right);
    }

    bool find_key(T key){
        return find_key(key, root);
    }

    void traverse_tree(node *tree_node, T tree_left=0, T tree_right=1<<30){
        if(!tree_node || tree_left > tree_right){
            return;
        }
        T tree_mid=(tree_left+tree_right)>>1;
        traverse_tree(tree_node->left, tree_left, tree_mid);
        printf("Left: %d Right: %d Data: %d\n", tree_left, tree_right, tree_node->data);
        traverse_tree(tree_node->right, tree_mid+1, tree_right);
    }

    void traverse_tree(){
        traverse_tree(root);
    }

    void delete_subtree(node *tree_node){
        if(!tree_node){
            return;
        }
        delete_subtree(tree_node->left);
        delete_subtree(tree_node->right);
        node *tmp=tree_node;
        delete tmp;
    }

    ~segment_tree(){
       delete_subtree(root);
    }
};

template<class T>
T compute_true_id(T id, T n, segment_tree<T> &tree){
    T high=n, low=id;
    while(low<high){
        T mid=(low+high)>>1;
        T not_greater=tree.order_by_key(mid);
        T true_id=mid-not_greater;
        if(true_id>=id){
            high=mid;
        }
        else{
            low=mid+1;
        }
    }
    return low;
}

template<class T>
T compute_true_id_naively(T id, T n, segment_tree<T> &tree){
    T res=id;
    while(1){
        T true_id=res-tree.order_by_key(res);
        if(true_id==id){
            return res;
        }
        ++res;
    }
}

int main(){
    int n=0, m=0;
    scanf("%d %d", &n, &m);
    segment_tree<int> tree;
    for(int i=m; i; --i){
        char type=0;
        while(type!='D' && type!='L' && !feof(stdin)){
            type=getchar();
        }
        int room_id=0;
        scanf("%d", &room_id);
        int true_id=compute_true_id(room_id, n, tree);
        if(type=='D'){
            tree.insert_key(true_id);
        }
        else{
            printf("%d\n", true_id);
        }
    }
    return 0;
}
