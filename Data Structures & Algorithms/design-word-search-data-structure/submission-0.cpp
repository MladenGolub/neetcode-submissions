class WordDictionary {

    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        bool isEnd;

        TrieNode(bool val = false) : isEnd(val) {}
    };

    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        
        TrieNode* curr = root;

        for(char i : word) {

            if(curr->children.find(i) == curr->children.end()) {
                curr->children[i] = new TrieNode();
            }

            curr = curr->children[i];

        }

        curr->isEnd = true;

    }
    
    bool search(string word) {
        
        TrieNode* curr = root;
        queue<TrieNode*> toVisit;
        toVisit.push(curr);

        for(char i : word) {
            queue<TrieNode*> nextToVisit;

            while(toVisit.size() > 0) {
                TrieNode* current = toVisit.front();
                toVisit.pop();

                if(i == '.') {
                    for (const auto& child : current->children) {
                        nextToVisit.push(child.second);//dodajem svu njegovu decu da budu sledeca za obilazak
                    }
                } else {
                    if(current->children.find(i) != current->children.end()) {
                        nextToVisit.push(current->children[i]);
                    }
                }
            }

            if(nextToVisit.empty()) {
                return false;
            }

            toVisit = nextToVisit;

        }

        while(!toVisit.empty()) {
            TrieNode* pom = toVisit.front();
            toVisit.pop();
            if(pom->isEnd) {
                return true;
            }
        }

        return false;

    }
};
