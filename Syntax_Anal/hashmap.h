#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HASH_SIZE 10000

struct HashNode {
  char *key;
  int value;
  struct HashNode *next;
};

typedef struct HashNode* HashMap;

int hash(char *key) {
  unsigned long hash = 5381;
  int c;

  while (c = *key++)
      hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

  return hash % HASH_SIZE;
}

int hash_get(HashMap *mp, char *key, int d) {
  int i = hash(key);
  if (mp[i] == NULL) return d;
  struct HashNode* t = mp[i];
  while (t) {
    if (strcmp(t->key, key)) {
      return t->value;
    }
    t = t->next;
  }
  return d;
}

int hash_find(HashMap *mp, char *key) {
  int i = hash(key);
  if (mp[i] == NULL) return 0;
  struct HashNode* t = mp[i];
  while (t) {
    if (strcmp(t->key, key)) {
      return 1;
    }
    t = t->next;
  }
  return 0;
}

void hash_set(HashMap *mp, char *key, int value) {
  int i = hash(key);
  struct HashNode* t = mp[i];
  while (t) {
    if (strcmp(t->key, key)) {
      t->value = value;
    }
    t = t->next;
  }
  struct HashNode* p = (struct HashNode*)malloc(sizeof(struct HashNode));
  p->key = strdup(key);
  p->value = value;
  p->next = mp[i];
  mp[i] = p;
}

