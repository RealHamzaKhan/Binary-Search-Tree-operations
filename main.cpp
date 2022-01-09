#include <iostream>

using namespace std;
struct node
{
    int info;
    node *right;
    node *left;
};
class bst
{
     node *temp1;
    node *temp2;
    node* insist;
public:
    node *root;


    bst()
    {
        root=temp1=temp2=NULL;
    }
    void insertor(int key,node *& temp)
    {

        if(temp==NULL)
        {
            temp=new node;
            temp->info=key;
            temp->left=temp->right=NULL;

            return;
        }
        if(key==temp->info)
        {
            cout<<"Duplication is no allowed "<<endl;
            return;
        }
        if(key>temp->info)
        {
            insertor(key,temp->right);
            return;
        }
        if(key<temp->info)
        {
            insertor(key,temp->left);
            return;
        }

    }
    node* searchtree(int key,node *&temp)
    {
        if(temp==NULL)

        {
            cout<<"Value not found "<<endl;
            return NULL;
        }
        if(temp->info==key)
        {
            //cout<<"Adress of key : "<<temp<<endl;
            cout<<"Value of key : "<<temp->info<<endl;
            return temp;
        }
        if(key>temp->info)
        {
            searchtree(key,temp->right);
        }
        if(key<temp->info)
        {
            searchtree(key,temp->left);
        }

    }
    node* insistor(int key,node *&temp)
    {
        if(key<temp->info)
        {
            insist=temp;
        }
        if(key>temp->info)
        {
            insistor(key,temp->right);
        }
        if(key<temp->info)
        {
            insistor(key,temp->left);
        }
        return insist;
    }
    node* findsucessor(int key)
    {

        temp1=searchtree(key,root);
        if(temp1->right!=NULL)
        {
            if(temp1->right->left==NULL)
            {
                return temp1->right;
            }
            else
            {
               temp2=temp1->right;
               while(temp2->left!=NULL)
                {
                    temp2=temp2->left;
                }
                    return temp2;

            }


        }
        else
        {
            insistor(key,root);
        }



    }
    node* backsearch(int key,node *&temp)
    {
        if(temp->left!=NULL)
        {


        if(key ==temp->left->info)
        {

            return temp;
        }
        }
        if(temp->right!=NULL)
        {


        if(key==temp->right->info)
        {

            return temp;
        }
        }
        if(key>temp->info)
        {
            backsearch(key,temp->right);
        }
        if(key<temp->info)
        {
            backsearch(key,temp->left);
        }

    }
    void printtreee(node *&temp)
    {
        if(root==NULL)
        {
            cout<<"Tree is empty ";

        }
        if(temp->left!=NULL)
        {
            printtreee(temp->left);
        }
        cout<<temp->info<<"   ";
        if(temp->right!=NULL)
        {
            printtreee(temp->right);
        }
    }
    void delete_Elemeent(int key,node *&trump)
    {
        temp1=backsearch(key,root);
        if(key==root->info)
        {
            if(temp1->right==NULL && temp1->left==NULL)
            {
                delete root;
                root=NULL;
                return;
            }
            if(temp1->right==NULL && temp1->left!=NULL)
            {
                temp2=temp1->left;
                delete root;
                root=temp2;
                return;
            }
            if(temp1->right!=NULL && temp1->left==NULL)
            {
                temp2=temp1->right;
                delete root;
                root=temp2;
                return;
            }
            if(temp1->right!=NULL && temp1->left!=NULL)
            {
                temp2=findsucessor(key);
                temp2->right=temp1->right;
                temp2->left=temp1->left;
                delete root;
                root=temp2;
                return;
            }
        }


        if(key>temp1->info)
        {
            if(temp1->right->right==NULL && temp1->right->left==NULL)
            {


                temp2=temp1->right;
                temp1->right=NULL;
                delete temp2;
                temp2=NULL;
                return;
            }
            if(temp1->right->right!=NULL && temp1->right->left==NULL)
            {

                temp2=temp1->right;
                temp1->right=temp2->right;
                delete temp2;
                temp2=NULL;
                return;
            }
            if(temp1->right->right==NULL && temp1->right->left!=NULL)
            {

                temp2=temp1->right;
                temp1->right=temp2->left;
                delete temp2;
                temp2=NULL;
                return;
            }
            if(temp1->right->right!=NULL && temp1->right->left!=NULL)
            {
                temp2=findsucessor(key);
                temp2->right=temp1->right;
                temp2->left=temp1->left;
                delete temp1;
                temp1=temp2;
                return;
            }
        }
        if(key<temp1->info)
        {
            if(temp1->left->right==NULL && temp1->left->left==NULL)
            {

                temp2=temp1->left;
                delete temp2;

                temp1->left=NULL;
                return;

            }


            //
            if(temp1->left->right!=NULL && temp1->left->left==NULL)
            {

                temp2=temp1->left;
                temp1->left=temp2->right;
                delete temp2;
                temp2=NULL;
                return;
            }
            if(temp1->left->right==NULL && temp1->left->left!=NULL)
            {

                temp2=temp1->left;
                temp1->left=temp2->left;
                delete temp2;
                temp2=NULL;
                return;
            }
            if(temp1->left->right!=NULL && temp1->left->left!=NULL)
            {
                temp2=findsucessor(key);
                temp2->right=temp1->right;
                temp2->left=temp1->left;
                delete temp1;
                temp1=temp2;
                return;
            }
        }

    }
};

int main()
{

    bst b;
    b.insertor(100,b.root);
    b.insertor(105,b.root);
    b.insertor(115,b.root);
    cout<<"Before deletion : ";
    b.printtreee(b.root);
    b.delete_Elemeent(105,b.root);
    cout<<endl;
    cout<<"After deletion : ";
    b.printtreee(b.root);



    return 0;

}
