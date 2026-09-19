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
  Node dummy;
  dummy.next = NULL;
  Node *curr = &dummy;

  while (a != NULL && b != NULL) {
    // compare key attribute with strcmp
    if (strcmp(a->key, b->key) <= 0) {
      curr->next = a;
      a = a->next;
    }
    else {
      curr->next = b;
      b = b->next;
    }
    curr = curr->next;
  }

  // if any list is left, append it
  if (a != NULL) {
    curr->next = a;
  }
  else {
    curr->next = b;
  }

  return dummy.next;
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

void newline_char(char *buffer) {
  int len = strlen(buffer);
  while (len > 0 && buffer[len-1] == '\n') {
    buffer[--len] = '\0';
  }
}

int main() {
  FILE *ofile = fopen("hw1_input.txt", "r");
  if (ofile == NULL) return 1;
  char buffer[2048];

  // 1. n nodes
  int n;
  fscanf(ofile, "%d", &n);

  // 2. first $
  while (fgets(buffer, sizeof(buffer), ofile)) {
    if (strchr(buffer, '$')) break;
  }
  // 3. attributes & find key
  fgets(buffer, sizeof(buffer), ofile);
  // handling new line character
  newline_char(buffer);

  int key_idx = 0;
  int curr_idx = 0;
  for (int i = 0; buffer[i] != '\0'; i++) {
    if (buffer[i] == '*') {
      key_idx = curr_idx;
    }
    if (buffer[i] == ':') {
      curr_idx++;
    }
  }

  // 4. second $
  while (fgets(buffer, sizeof(buffer), ofile)) {
    if (strchr(buffer, '$')) break;
  }

  // 5. making linked list with real data
  Node *head = NULL;
  Node *tail = NULL;

  for (int i = 0; i < n; i++) {
    if (fgets(buffer, sizeof(buffer), ofile) == NULL) break;
    // handling new line character
    newline_char(buffer);

    Node *new_node = (Node *)malloc(sizeof(Node));

    // copy data
    new_node->data = (char *)malloc(strlen(buffer)+1);
    strcpy(new_node->data, buffer);
    new_node->next = NULL;

    // extract key attribute
    char key_buffer[256];
    int curr_attr = 0, k = 0;
    for (int i=0; buffer[i] != '\0'; i++) {
      if (buffer[i] == ':') {
        if (curr_attr == key_idx) break; // key: first attribute
        curr_attr++;
        k = 0;
      }
      else {
        if (curr_attr == key_idx) {
          key_buffer[k++] = buffer[i];
        }
      }
    }
    key_buffer[k] = '\0';
    
    new_node->key = (char *)malloc(strlen(key_buffer)+1);
    strcpy(new_node->key, key_buffer);

    if (head == NULL) {
      head = new_node;
      tail = new_node;
    }
    else {
      tail->next = new_node;
      tail = new_node;
    }
  }
  fclose(ofile);

  head = merge_sort(head);
  
  // 6. write results on file
  FILE *rfile = fopen("hw1_output.txt", "w");
  Node *curr = head;
  while (curr != NULL) {
    fprintf(rfile, "%s\n", curr->data);
    curr = curr->next;
  }
  fclose(rfile);

  return 0;
}
