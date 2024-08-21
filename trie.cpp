// lets understand the concept of a Trie
// Trie is nothing but basically a tree data structure and is also known as 
// Prefix Tree

# include <unordered_map>
# include <string>

using std :: unordered_map;
using std :: string;

// lets define a class for TrieNode

class TrieNode {
    public:
        // now we will define a hashmap to store and look for values
        unordered_map<char, TrieNode* >children_;
        // and set the ending of the word to be false initially
        bool word = false;
};

// define another class which would perform all the operations to be performed on the prefix tree or Trie
class Trie {
    public:
        // now we define the root node
        TrieNode root_;

        // lets start with the insert function which takes in the values in the form of a string
        void insert(string word) {
            // we set the current pointer to the root
            TrieNode* curr = &root_;
            // now we just iterate through each character in the word
            for (char c : word) {
                // if the character is not in the hashmap then we will just add it  
                if (curr->children_.count(c) == 0) {
                    curr->children_[c] = new TrieNode();
                }
                // and set our current pointer to that character
                curr = curr->children_[c];
            }
            // here we will set the current pointer at word to be true once we reach the end
            curr->word = true;
        }

        // for searching the method is quite similar
        // we will have a function which takes in the word 
        bool search(string word) {
            // initially we set the current pointer to the root node
            TrieNode *curr = &root_;
            // we want to iterate through each character in the word
            for (char c : word) {
                // if the character does not exist in the hash map then
                // we know that it is not been added
                // so we return false
                if (curr->children_.count(c) == 0) {
                    return false;
                }
                // if the word is present then we set the current pointer 
                curr = curr->children_[c];
            }
            // and return the word
            return curr->word;
        }

        
        // for prefix the method is quite similar to searching
        // we will have a function which takes in the set of words not the entire word 

        bool startsWith(string prefix) {
            // we will set the current pointer to the root node
            TrieNode *curr = &root_;
            // now we will iterate through each character in the input 
            for (char c : prefix) {
                // if we don't find a match then we return false because it does not exist
                if (curr->children_.count(c) == 0) {
                    return false;
                }
                // if we find a match we will keep on shifting the pointer
                curr = curr->children_[c];
            }
            // and return true at the end
            return true;
        }
};



