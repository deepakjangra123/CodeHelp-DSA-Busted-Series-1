class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch){
        data = ch;
        for(int i=0; i<26; i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie{
    public:
    TrieNode* root;
    Trie(char ch){
        root = new TrieNode(ch);
    }

    void insertUtil(TrieNode* root, string word){
			//base case
			if(word.length() == 0){
				root->isTerminal = true;
				return;
			}
			
			//Assumption word will be in CAPS
			int index = word[0]-'a';
			TrieNode* child;
			
			//present 
			if(root->children[index] != NULL){
				child = root->children[index];
			}
			else{
				//absent
				child = new TrieNode(word[0]);
				root->children[index] = child;
			}
			
			//recursion
			insertUtil(child, word.substr(1));
		}
		
		void insertWord(string word){
			insertUtil(root, word);
		}

        void printSuggestions(TrieNode* curr, vector<string>&temp, string prefix){
            
            if(curr->isTerminal){
                temp.push_back(prefix);
            }
            for(char ch = 'a'; ch <= 'z'; ch++){

                TrieNode* next = curr->children[ch - 'a'];

                if(next != NULL){
                    prefix.push_back(ch);
                    printSuggestions(next, temp, prefix);
                    prefix.pop_back();
                }
            }
        }
        vector<vector<string>> getSuggestions(string str){
            TrieNode* prev = root;
            vector<vector<string>>output;
            string prefix = "";

            for(int i=0; i<str.length(); i++){
                char lastCh = str[i];
                prefix.push_back(lastCh);

                //check for last Character
                TrieNode* curr = prev->children[lastCh - 'a'];

                //if not found
                if(curr == NULL){
                    break;
                }

                // if found
                else {
                  vector<string> temp;
                  printSuggestions(curr, temp, prefix);

                  output.push_back(temp);
                  temp.clear();
                  prev = curr;
                }
            }
            return output;
        }
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //creation of trie
    Trie *t = new Trie('/0');

    //insert all contact int Trie
    for(int i=0; i<contactList.size(); i++){
        string str = contactList[i];
        t->insertWord(str);
    }

    //return ans
    return t->getSuggestions(queryStr);
}