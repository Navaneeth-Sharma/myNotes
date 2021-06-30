#include<iostream>
#include<queue>

using namespace std;

// Breadth First Search => finish all childeren then grand
// childeren  ex: level order

// Depth First Search => first all grand childeren then next child
// ex: pre-order, post-order, in-order

class BstNode{
    private:
        int data;
        BstNode* left;
        BstNode* right;
    
    public:
        BstNode* GetNewNode(int data){
            BstNode* newNode = new BstNode();
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
        }

        BstNode* Insert(BstNode* root, int data){
            if(root==NULL){
                root = GetNewNode(data);
                return root;
            }
            else if(data <= root->data)
            {
                root->left = Insert(root->left, data);
            }
            // (data >= root->data)
            else{
                root->right = Insert(root->right, data);
            }
            return root;
        }

        void PreOrder(BstNode* root){
            if(root==NULL){
                return;
            }
            cout<<root->data<<" ";
            PreOrder(root->left);
            PreOrder(root->right);
        }

        void InOreder(BstNode* root){
            if(root==NULL){
                return;
            }
            InOreder(root->left);
            cout<<root->data<<" ";
            InOreder(root->right);
        }

        void PostOrder(BstNode* root){
            if(root==NULL){
                return;
            }
            PostOrder(root->left);
            PostOrder(root->right);
            cout<<root->data<<" ";
        }

        void LevelOrder(BstNode* root){
            if(root == NULL) return;
            queue<BstNode*> Q;
            Q.push(root);

            while (!Q.empty())
            {
                 BstNode* current = Q.front();
                 cout<<current->data<<" ";
                 if(current->left != NULL) Q.push(current->left);
                 if(current->right != NULL) Q.push(current->right);
                 Q.pop();
            }
            
        }

};

int main(){

    BstNode bst;

    BstNode* root=NULL;
    root = bst.Insert(root,1000);
    root = bst.Insert(root,50);
    root = bst.Insert(root,100);
    root = bst.Insert(root,70);
    root = bst.Insert(root, 5);
    root = bst.Insert(root, 10);
    root = bst.Insert(root, 2);
    root = bst.Insert(root, 9);

    bst.LevelOrder(root);
    cout<<endl;
    bst.InOreder(root);
    cout<<endl;
    bst.PreOrder(root);
    cout<<endl;
    bst.PostOrder(root);

    return 0;
}