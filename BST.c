#include<stdio.h>
#include<malloc.h>
struct BST
{
    int info;
    struct BST *left;
    struct BST *right;
}*root=NULL,*parent,*loc,*temp,*new_node,*child,*suc,*parsuc;
void searching(int);
void insertion(int);
void deletion(int);
void deletion_case_1_2(struct BST*, struct BST*);
void inorder_traversal(struct BST *);
int main()
{
    int choice,ch,key;
    do
    {
        printf("\n1.Searching");
        printf("\n2.Insertion");
        printf("\n3.Traversing\n4. Deletion");
        printf("\nCHOICE(?):");
        scanf("%d",&choice);
        switch(choice)
        {

            case 1:printf("\nEnter key to be searched:");
                    scanf("%d",&key);
                    searching(key);
                    break;
            case 2: printf("\nEnter key to be inserted:");
                    scanf("%d",&key);
                    insertion(key);
                    break;
            case 3: printf("\nThe Inoreder Traversal:\n");
                    inorder_traversal(root);
                    break;
            case 4: printf("\nEnter the node to be deleted:");
                    scanf("%d",&key);
                    deletion(key);

        }
        printf("\nPress 1 to continue:");
        scanf("%d",&ch);
    }while(ch);
return 0;
}

void searching(int key)
{
    loc=NULL;
    parent=NULL;
    temp=root;
    while(temp!=NULL)
    {
        if(temp->info==key)
        {
            loc=temp;
            printf("\nSUCCESSFUL SEARCH");
            return;
        }
        else if(temp->info>key)
            {
                parent=temp;
                temp=temp->left;

            }
        else
        {
            parent=temp;
            temp=temp->right;
        }
    }
    printf("\nUNSUCCESSFUL SEARCH");
}


void insertion(int key)
{
    searching(key);
    if(loc!=NULL)
    {
        printf("\nElement already exist");
        return;
    }
    else
    {
        new_node=(struct BST *)malloc(sizeof(struct BST));
        new_node->info=key;
        new_node->left=NULL;
        new_node->right=NULL;
        if(parent!=NULL)
        {
        if(parent->info>key)
            parent->left=new_node;
        else
            parent->right=new_node;
        }
        else
        root=new_node;
    }
}

void inorder_traversal(struct BST *temp)
{
    if(temp!=NULL)
    {
        inorder_traversal(temp->left);
        printf("%d\t",temp->info);
        inorder_traversal(temp->right);
    }
}
void deletion(int key)
{
    searching(key);
    if(loc->left!=NULL && loc->right!=NULL)
    {
        parsuc=loc;;
        suc=loc->right;
        while(suc->left!=NULL)
        {
            parsuc=suc;
            suc=suc->left;
        }
    deletion_case_1_2(suc,parsuc);
    suc->left=loc->left;
    suc->right=loc->right;
    if(parent==NULL)
        root=suc;
    else
    {
    if(loc==parent->left)
        parent->left=suc;
    else
        parent->right=suc;

    }
    }
    else
    {
        deletion_case_1_2(loc,parent);
    }
}

void deletion_case_1_2(struct BST *loc, struct BST* parent)
{
    if(loc->left==NULL && loc->right==NULL)
    {
        child=NULL;
    }
    else if(loc->left!=NULL)
        child=loc->left;
    else
        child=loc->right;
    if(parent!=NULL)
    {
        if(loc==parent->left)
            parent->left=child;
        else
            parent->right=child;
    }
    else
        root=child;
}

