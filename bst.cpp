#include<iostream>

using namespace std;

class BstNode{
    
    public:
        int data;
        BstNode* left;
        BstNode* right;

        BstNode *GetNewNode(int data){
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
            else if(data < root->data)
            {
                root->left = Insert(root->left, data);
            }
            else{
                root->right = Insert(root->right, data);
            }
            return root;
        }

        
        BstNode* inorderPredecessor(BstNode* root){
            root = root->left;
            while(root->right != NULL){
                root = root->right;
            }
            return root;
        }

        BstNode* Delete(BstNode* root, int data){
            // Search for the node to be deleted
            BstNode* iPre;
            if (root==NULL){
                return NULL;
            }
            if ((root->data==data) &&(root->right==NULL) && (root->left==NULL)){
                // root = NULL;
                free(root);
                return NULL;
            }
            else if(data < root->data){
                root->left = Delete(root->left, data);
            }
            else if(data > root->data){
                root->right = Delete(root->right, data);
            }
            
            // Deletion Strategy when node found
            else{
                iPre = inorderPredecessor(root);
                root->data = iPre->data;
                root->left = Delete(root->left, iPre->data);
            }

            return root;
        }

        bool Search(BstNode* root, int data){
            if(root==NULL) return false;
            else if(root->data ==  data) return true;
            else if(data<=root->data) return Search(root->left, data);
            else return Search(root->right, data);
        }

        int Maximum(BstNode* root){
            if(root==NULL){
                throw std::invalid_argument( "received invalid root! root must not be empty" );
                return -1;
            }
            BstNode* temp = root;
            while (temp->right!=NULL)
            {
                temp = temp->right;
            }
            return temp->data;
        }

        int Minimum(BstNode* root){
            if(root==NULL){
                throw std::invalid_argument( "received invalid root! root must not be empty" );
                return -1;
            }
            BstNode* temp = root;
            while (temp->left!=NULL)
            {
                temp = temp->left;
            }
            return temp->data;
        }

        // Maxdepth or height
        int Maxdepth(BstNode* root){
            if(root==NULL){
                return -1;
            }
            int leftHeight = Maxdepth(root->left);
            // cout<<leftHeight<<" ";
            int rightHeight = Maxdepth(root->right);
            // cout<<rightHeight<<" ";
            return max(leftHeight,rightHeight)+1;
        }

};


int main(){

    BstNode bst;

    BstNode* root=NULL;
    root = bst.Insert(root, 5);
    root = bst.Insert(root, 10);
    root = bst.Insert(root, 2);
    root = bst.Insert(root, 9);

    cout<<bst.Search(root, 1)<<endl;

    cout<<"The Max_Depth/Height of the BST is : "<<bst.Maxdepth(root)<<endl;

    cout<<"The Max value is : "<<bst.Maximum(root)<<endl;
    cout<<"The Min value is : "<<bst.Minimum(root)<<endl;

    root = bst.Delete(root, 3);

    cout<<"The Min value is : "<<bst.Minimum(root)<<endl;
        
    return 0;
}