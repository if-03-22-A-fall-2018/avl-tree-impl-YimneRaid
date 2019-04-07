#include "node.h"
#include <stdlib.h>

int 	get_key (Node node){
if (node!=0) {
  return node->key;
}
return 0;
}

Node 	get_left (Node node){
if (node!=0) {
  return node->left;
}
return 0;
}

void 	set_left (Node node, Node left_node){
  if (node==0) {
    return ;
  }
  node->left=left_node;
}

Node 	get_right (Node node){
if (node!=0) {
  return node->right;
}
return 0;
}

void 	set_right (Node node, Node right_node){
  if (node==0) {
    return ;
  }
node->right=right_node;
}

int get_height(Node node) {
  if (node==0) {
    return 0;
  }
    return node->height;
}

void 	set_height (Node node, int height){
  if (node==0) {
    return ;
  }
  node->height=height;
}

Node 	create_node (int key){
  Node newNode=(Node)malloc(sizeof(Node*));
  newNode->key=key;
  newNode->right=0;
  newNode->left=0;
  newNode->height=1;
  return newNode;
}
