#include<iostream>
#include<queue>

using namespace std;

class node{
    public: 
        int data;
        node* left;
        node* right;

        node(int data ){
            this->data = data;
            this->left = NULL;
            this->right = NULL;
        }

};

node* buildTree(node* root){

        cout<<"Enter Node data  ";
        int data;
        cin>> data;

        root = new node(data);
        //root->data  = data;
        if(data == -1){
            return NULL;
        }
        cout<< "Enter Left Node data- \n";
        root->left = buildTree(root->left);

        cout<< " Enter Right Node data - \n";
        root->right = buildTree(root->right);
}

void buildfromlevelorder(node* &root){
    queue<node*> q;

    cout<<"Enter node data  ";
    int data;
    cin>> data;
    
    root = new node(data);
    q.push(root);

    while(!q.empty()){

        node* temp = q.front();
        q.pop();

        cout<<"Enter left data of "<< temp->data<<" ";
        int ldata;
        cin>> ldata;
         
        if(ldata != -1){
            temp->left = new node(ldata);
            q.push(temp->left);
        }

        cout<<"Enter right data of "<< temp->data<<" ";
        int rdata;
        cin>> rdata;
         
        if(rdata != -1){
            temp->right = new node(rdata);
            q.push(temp->right);
        }
    }

}
void leverOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
       
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}


void reverseleverOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
       
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<< temp->data<<" ";
            if(temp->right){
                q.push(temp->right);
            }
            
            if(temp->left){
                q.push(temp->left);
            }
        }
    }
}
void inOrder(node* root){
    if(root == NULL){
        return ;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

void preOrder(node* root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

void postorder(node* root){
    if(root == NULL){
        return ;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main(){

    node* root = NULL;
    //1 3 5 7 11 17 -1 - 1 -1 - 1 -1 - 1 -1
    buildfromlevelorder(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // Create Tree
    //root = buildTree(root);

    //Level order treversal
    cout<<"\nLevel order traversal \n";
    leverOrderTraversal(root);

    cout<<"\nLevel order traversal \n";
    reverseleverOrderTraversal(root);

    cout<<"\nINOrder traversal \n";
    inOrder(root);

    cout<<"\nPREOrder traversal \n";
    preOrder(root);

    cout<<"\nPOSTOrder traversal \n";
    postorder(root);
    return 0;
}