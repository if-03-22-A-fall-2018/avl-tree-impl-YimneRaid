#include <stdio.h>
#include "avl_tree.h"

Node insert(Node node, int key){
    if (node == 0){
      node=create_node(key);
    }

    if (key < get_key(node)){
        set_left(node, insert(get_left(node), key));
    } else if (key > get_key(node)){
      set_right(node, insert(get_right(node), key));
    } else {
        // no duplicate keys
        return node;
    }

    set_height(node, max(get_height(get_left(node)), get_height(get_right(node))) + 1);

    int balance = get_balance(node);
    if (balance > 1 && key < get_key(get_left(node))){
        // LL
		printf("Inserting %d, applying rotate right on %d\n", key, get_key(node));
        return rotate_right(node);
    }
    if (balance < -1 && key > get_key(get_right(node))){
        // RR
        printf("Inserting %d, applying rotate right on %d\n", key, get_key(node));
            return rotate_right(node);
      }
    if (balance > 1 && key > get_key(get_left(node))){
        // LR
        set_left(node, rotate_left(get_left(node)));
        return rotate_right(node);
    }
    if (balance < -1 && key < get_key(get_right(node))){
        // RL
        printf("Inserting %d, applying rotate right on %d\n", key, get_key(node));
            return rotate_left(node);
      }
    // balanced
    return node;
}

Node rotate_left(Node node){
    if (node == 0){
        return 0;
    }

    Node r = get_right(node);
    Node l = get_left(r);

    set_left(r, node);
    set_right(node, l);

    set_height(node, max(get_height(get_left(node)), get_height(get_right(node))) + 1);
    set_height(r, max(get_height(get_left(r)), get_height(get_right(r))) + 1);

    return r;
}
Node rotate_right(Node node){
    if (node == 0){
        return 0;
    }

    Node l = get_right(node);
    Node r = get_left(l);

    set_left(node, r);
    set_right(l, node);

    set_height(node, max(get_height(get_left(node)), get_height(get_left(node))) + 1);
    set_height(r, max(get_height(get_right(r)), get_height(get_left(r))) + 1);

    return r;
}
int max (int n1, int n2){
  if(n1>n2)
  {
    return n1;
  }
  return n2;
}
int 	get_balance(Node node){
  return 0;
}
Node unbalanced_insert(Node root, int key) {
  if(root==0)
  {
    root=create_node(key);
  }
  else if(key<root->key)
  {
    root->left=unbalanced_insert(root->left,key);
  }
  else if(key > root->key)
  {
    root->right=unbalanced_insert(root->right,key);
  }
  return root;
}
