#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <sstream>
#include <string>

constexpr int  max_height {100} ;

struct min_heap_node{
    char data;
    unsigned freq;
    min_heap_node *left, *right;
};

struct min_heap{
    unsigned size;
    unsigned capacity;
    min_heap_node **array;
};

min_heap_node *new_node(char data, unsigned freq){
    min_heap_node *temp = ( min_heap_node *)malloc(sizeof(min_heap_node));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

min_heap *create_min_heap(unsigned capacity){

    min_heap *heap = (min_heap *)malloc(sizeof(min_heap));
    heap->size = 0;
    heap->capacity = capacity;

    heap->array = (min_heap_node **)malloc(heap->capacity * sizeof(min_heap_node *));
    return heap;
}

void swap_min_heap_node(min_heap_node **a, min_heap_node **b){
    min_heap_node *t = *a;
    *a = *b;
    *b = t;
}

void heapify(min_heap *heap, int i){
    int minimum = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heap->size && heap->array[left]->freq < heap->array[minimum]->freq)
        minimum = left;

    if (right < heap->size && heap->array[right]->freq < heap->array[minimum]->freq)
        minimum = right;

    if (minimum != i)
    {
        swap_min_heap_node(&heap->array[minimum], &heap->array[i]);
        heapify(heap, minimum);
    }
}

int is_size_one(min_heap *heap){
    return (heap->size == 1);
}

min_heap_node *extract_min(min_heap *heap){

    min_heap_node *temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    heapify(heap, 0);

    return temp;
}

void insert_min_heap(min_heap *heap, min_heap_node *heap_node)
{
    ++heap->size;
    int i = heap->size - 1;
    while (i && heap_node->freq < heap->array[(i - 1) / 2]->freq){

        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    heap->array[i] = heap_node;
}

std::string print_array(int arr[], int n)
{
    std::stringstream string;
    std::string code;
    for (size_t i {}; i < n; ++i)
        string << arr[i];
    string >> code;
    return code;
}

void build_min_heap( min_heap *heap){
    int n = heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        heapify(heap, i);
}

int is_leaf_node( min_heap_node *root){
    return !(root->left) && !(root->right);
}

min_heap *create_and_build_min_heap(char data[], int freq[], int size){
    min_heap *heap = create_min_heap(size);
    for (int i = 0; i < size; ++i)
        heap->array[i] = new_node(data[i], freq[i]);

    heap->size = size;
    build_min_heap(heap);

    return heap;
}

min_heap_node *build_huffman_tree(char data[], int freq[], int size){
    
    min_heap_node *left, *right, *top;
    min_heap *heap = create_and_build_min_heap(data, freq, size);
    
    while (!is_size_one(heap)){
        left = extract_min(heap);
        right = extract_min(heap);
        top = new_node('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insert_min_heap(heap, top);
    }
    
    return extract_min(heap);
}

void print_codes(  min_heap_node *root, int arr[], int top , int &sum){
    if (root->left)
    {
        arr[top] = 0;
        print_codes(root->left, arr, top + 1 ,sum);
    }
    if (root->right)
    {
        arr[top] = 1;
        print_codes(root->right, arr, top + 1,sum);
    }
    if (is_leaf_node(root))
    {
        std::cout << std::right << std::setw(10) << root->data << std::setw(20) << print_array(arr , top)
        << std::setw(20) << root->freq << std::setw(20) << (root->freq * top) << std::endl;   
        sum += root->freq * top;
    }
}

void huffman_code(char data[], int freq[], int size){
    
    min_heap_node *root = build_huffman_tree(data, freq, size);
    int arr[ max_height], top {} , sum {};
    
    std::cout << std::setw(80) << std::setfill('=') << "" << std::endl << std::setfill(' ');
    std::cout << std::right << std::setw(10) << "Letter" << std::setw(20) << "code" 
    << std::setw(20) << "frequency" << std::setw(20) << "Total bits" << std::endl;
    std::cout << std::setw(80) << std::setfill('=') << "" << std::endl << std::setfill(' ');
    
    print_codes(root, arr, top , sum);
    
    std::cout << std::setw(80) << std::setfill('=') << "" << std::endl << std::setfill(' ');
    std::cout << std::right << std::setw(10) << "Total" <<  std::setw(40) << "" 
    << std::setw(20) << sum << std::endl;
    std::cout << std::setw(80) << std::setfill('=') << "" << std::endl << std::setfill(' ');
}

int main(){
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {12, 2, 7, 13, 14, 85};
    int size = sizeof(arr) / sizeof(arr[0]);
    huffman_code(arr, freq, size);
    return 0;
}