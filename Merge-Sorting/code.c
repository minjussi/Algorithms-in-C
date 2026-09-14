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
  Node empty;
  empty.next = NULL;

  while (a != NULL && b != NULL) {
    if (strcmp(a->key, b->key) <= 0) {

    }
    else {

    }
  }
}

// recursive sort
// find the midpoint and split it into two halves
Node *merge_sort(Node *head) {
  // the number of Node is 0 or 1 -> already sorted
  if (head == NULL || head->next == NULL) {
    return head;
  }

  // find midpoint
  Node *slow = head;
  Node *fast = head->next;

  while (fast != NULL && fast->next != NULL) {
    // slow moves forward by 1 node
    slow = slow->next;
    // fast moves forward by 2 nodes
    fast = fast->next->next;
    // fast reaches the end, slow points to the midpoint
  }

  Node *left = head;
  Node *right = slow->next;
  // split it into two halves (using NULL)
  slow->next = NULL;

  // recursive sort
  left = merge_sort(left);
  right = merge_sort(right);

  // combines two sorted lists
  return merge(left, right);
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
  }
  Node *head = NULL;

  head = merge_sort(head);
  
  // write results on file
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
