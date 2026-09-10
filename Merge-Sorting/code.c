#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
  char *key;
  char *data;
  struct Node *next;
} Node;

// recursive sort
Node *merge_sort(Node *head) {}

// combines two sorted lists
Node *merge(Node *a, Node *b) {}

int main() {
  FILE *ofile = fopen("hw1_input.txt", "r");
  if (ofile == NULL) return 1;

  Node *head = NULL;

  head = merge_sort(head);
  
  FILE *rfile = fopen("hw1_output.txt", "w");
  Node *curr = head;
  while (curr != NULL) {
    fprintf(rfile, "%s\n", curr->data);
    curr = curr->next;
  }

  fclose(ofile);
  fclose(rfile);
  return 0;
}
