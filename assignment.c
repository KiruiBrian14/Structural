#include <stdio.h>

void print_array(int arr[], int n) {
  printf("[");
  for (int i = 0; i < n; i++) {
    printf("%d", arr[i]);
    if (i < n - 1) {
      printf(", ");
    }
  }
  printf("]\n");
}

void sort_array(int arr[], int n) {
 
  for (int i = 1; i < n; i++) {
    int element = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > element) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = element;
  }
}

int remove_element(int arr[], int n, int index) {
  if (index < 0 || index >= n) {
    printf("Invalid index\n");
    return -1;
  }

  int element = arr[index];

  for (int i = index; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }

  return element;
}

void insert_element(int arr[], int n, int element) {

  int pos = 0;
  while (pos < n && arr[pos] < element) {
    pos++;
  }

 
  for (int i = n - 1; i > pos; i--) {
    arr[i] = arr[i - 1];
  }


  arr[pos] = element;
}


int main() {
  int arr[10] = {45, 68, 67, 89, 37, 47, 56, 63, 64, 79};
  int n = 10;

  printf("Original array: ");
  print_array(arr, n);

  int index;
  printf("Enter the index to remove (0 to 9): ");
  scanf("%d", &index);

  int removed = remove_element(arr, n, index);
  n--;
  printf("Removed element: %d\n", removed);


  printf("Array after removal: ");
  print_array(arr, n);

  int element;
  printf("Enter the element to insert: ");
  scanf("%d", &element);

  insert_element(arr, n, element);
  n++;
  printf("Inserted element: %d\n", element);

  printf("Array after insertion: ");
  print_array(arr, n);

  sort_array(arr, n);
  printf("Array after sorting: ");
  print_array(arr, n);

  return 0;
}
