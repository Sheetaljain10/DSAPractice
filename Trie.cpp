#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node *links[26];
    bool flag;

    bool containsKey(char ch){
        return links[ch-'a'] != NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    void setFlag(){
        flag = true;
    }

    bool getFlag(){
        return flag;
    }
};

class Trie{
    private: Node* root;
    public: 
        Trie(){
         root = new Node();
        }

        void insert(string p){
            Node* temp = root;
            for(auto i:p){
                if(!temp->containsKey(i)){
                    temp->put(i, new Node());
                }
                temp = temp->get(i);
            }
            temp->setFlag();
        }

        bool search(string p){
            Node* temp = root;
            for(auto i:p){
                if(!temp->containsKey(i)){
                    return false;
                }
                temp = temp->get(i);
            }
            return temp->getFlag();
        }

        bool startWith(string p){
            Node* temp = root;
            for(auto i:p){
                if(!temp->containsKey(i)){
                    return false;
                }
                temp = temp->get(i);
            }
            return true;
        }

        void erase(string p){
            Node* temp = root;
            for(auto i:p){
                
            }
        }
};

int main(){
    Trie book;
    book.insert("teacher");
    book.insert("teach");
    book.insert("tear");
    book.insert("monopoly");
    book.insert("monster");
    cout<<"Word mono exists: "<<(book.search("mon") ? "True": "False")<<endl;
    book.insert("terror");
    cout<<"prefix tea exists: "<<(book.startWith("tea") ? "True": "False");
}