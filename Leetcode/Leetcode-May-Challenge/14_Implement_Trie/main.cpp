/* ---------------------- Problem Statement -----------------------
Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();

trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true
Note:

You may assume that all inputs are consist of lowercase letters a-z.
All inputs are guaranteed to be non-empty strings.
---------------------------------------------------------------------*/

class Trie {
public:
    /** Initialize your data structure here. */
 
        unordered_map<char, Trie*> _map;
        bool endofword;
     
    Trie()
    {
        endofword=false;
    }
    
    
    /** Inserts a word into the trie. */
    
    void insert(string word) 
    {
        Trie* curr = this;
        for(char c : word)
        {
            if(curr->_map.find(c) == curr->_map.end())
            {
                curr->_map[c] = new Trie();
            }
            curr = curr->_map[c];
        }
        curr->endofword = true;
    }
    
    
    /** Returns if the word is in the trie. */
    
    bool search(string word) 
    {
        Trie* curr = this;
        for(char c : word)
        {
            if(curr->_map.find(c) == curr->_map.end())
            {
                return false;
            } 
            
            curr = curr->_map[c];
        }
        return curr->endofword;
    }
    
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    
    bool startsWith(string prefix) 
    {
        Trie* curr = this;
        for(char c : prefix)
        {
            if(curr->_map.find(c) != curr->_map.end())
            {
                curr = curr->_map[c];
            }
            else
                return false;
            
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */