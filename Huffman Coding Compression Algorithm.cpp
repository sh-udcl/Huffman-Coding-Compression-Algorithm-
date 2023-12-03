#include <iostream>
#include <queue>
#include <vector>

// Node structure of the Huffman tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) : ch(ch), freq(freq), left(nullptr), right(nullptr) {}
};

// Function to compare two nodes (for the priority queue)
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print the Huffman codes from the root of the Huffman tree
void printHuffmanCodes(Node* root, std::string str) {
    if (root == nullptr) return;

    if (root->ch != '$') {
        std::cout << root->ch << ": " << str << std::endl;
    }

    printHuffmanCodes(root->left, str + "0");
    printHuffmanCodes(root->right, str + "1");
}

// Main function to build the Huffman Tree and print codes
void buildAndPrintHuffmanCodes(char arr[], int freq[], int size) {
    Node *left, *right, *top;
    std::priority_queue<Node*, std::vector<Node*>, Compare> minHeap;

    for (int i = 0; i < size; ++i) {
        minHeap.push(new Node(arr[i], freq[i]));
    }

    while (minHeap.size() != 1) {
        left = minHeap.top();
        minHeap.pop();
        right = minHeap.top();
        minHeap.pop();

        top = new Node('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    printHuffmanCodes(minHeap.top(), "");
}

int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);
    buildAndPrintHuffmanCodes(arr, freq, size);

    return 0;
}
