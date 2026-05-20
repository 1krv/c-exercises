/*
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * containts a single ditit. Add the two numbers and return the sum as a linked
 * list.
 *
 * You may assume the two numbers do not contain any leading zero,
 * except the number 0 itself.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
  int val;
  struct ListNode *next;
} ListNode;

ListNode *createNode(int val) {
  ListNode *node = malloc(sizeof(ListNode));
  if (!node) {
    perror("Malloc");
    exit(EXIT_FAILURE);
  }
  node->val = val;
  node->next = NULL;
  return node;
}

void freeList(ListNode *node) {
  while (node != NULL) {
    ListNode *next = node->next;
    free(node);
    node = next;
  }
}

void printList(ListNode *node) {
  while (node != NULL) {
    printf("%d ", node->val);
    node = node->next;
  }
  printf("\n");
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
  ListNode dummy;
  dummy.val = 0;
  dummy.next = NULL;

  ListNode *current = &dummy;
  int carry = 0;

  while (l1 != NULL || l2 != NULL || carry != 0) {
    int sum = carry;

    if (l1 != NULL) {
      sum += l1->val;
      l1 = l1->next;
    }

    if (l2 != NULL) {
      sum += l2->val;
      l2 = l2->next;
    }

    carry = sum / 10;

    current->next = createNode(sum % 10);
    current = current->next;
  }

  return dummy.next;
}

int main(void) {
  ListNode *n1 = createNode(2);
  ListNode *n2 = createNode(4);
  ListNode *n3 = createNode(3);
  n1->next = n2;
  n2->next = n3;
  printf("l1:\t");
  printList(n1);

  ListNode *m1 = createNode(5);
  ListNode *m2 = createNode(6);
  ListNode *m3 = createNode(4);
  m1->next = m2;
  m2->next = m3;
  printf("l2:\t");
  printList(m1);

  ListNode *result = addTwoNumbers(n1, m1);
  printf("Result:\t");
  printList(result);

  freeList(n1);
  freeList(m1);
  freeList(result);
  return 0;
}
