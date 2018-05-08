#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"aa_tree.h"

#define MAX 100

int main(){
  int32_t i;
  int32_t flag;
  int32_t count;
  aatree_val arr[MAX];
  aatree_node *tree = NULL;

  count = 0;
  for (i = 0 ; i < MAX ; i++){
    int32_t x;
    x = rand()%MAX;
    tree = aa_tree_insert(x, tree, &flag);
    count += flag;
  }
  for (i = 0 ; i < MAX ; i++){
    int32_t x;
    x = rand()%MAX;
    tree = aa_tree_delete(x, tree, &flag);
    count -= flag;
  }
  printf("count = %d\n", count);
  
  /* 以下3通りのprintはどれも同じ結果になる */
  printf("tree2vec-result\n");
  aa_tree2vec(tree, arr);
  for (i = 0 ; i < count; i++){
    printf("%d\n", arr[i]);
  }
  
  printf("tree-print\n");
  aa_tree_print(stdout, tree);
  
  printf("search\n");
  for (i = 0 ; i < MAX ; i++){
    if (aa_tree_search(tree, i)){
      printf("%d\n", i);
    }
  }
  
  aa_tree_free(tree);
  return 0;
}
