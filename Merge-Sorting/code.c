#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
  char *key;
  char *data;
  struct Node *next;
} Node;

// combines two sorted lists
Node *merge(Node *a, Node *b) {
  
}

// recursive sort
// find the midpoint and split it into two halves
Node *merge_sort(Node *head) {
  if (head == NULL || head->next == NULL) {

    merge_sort();
    merge_sort();

    merge();
  }
}

int main() {
  FILE *ofile = fopen("hw1_input.txt", "r");
  if (ofile == NULL) return 1;
  // n nodes
  int n;
  fscanf(ofile, "%d", &n);
  // attributes & find key
  fgets(ofile, "%s", );
  // linked list
  while (fgets(, sizeof(), ofile) != NULL) {
    // strcspn
  }
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
