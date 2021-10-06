    #include <stdio.h>
    #include <stdlib.h>

    struct node {
    int k;
    struct node *left, *right;
    };

    struct node *newNode(int item) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->k = item;
    temp->left = temp->right = NULL;
    return temp;
    }

    void inorder(struct node *r) {
    if (r != NULL) 
    {
        inorder(r->left);
        printf("%d ", r->k);  
        inorder(r->right);
    }
    }

    struct node *insertion(struct node *node, int k) {

    if (node == NULL) return newNode(k);
    if (k < node->k)
    {
        node->left = insertion(node->left, k);
    }
    else
        {
            node->right = insertion(node->right, k);
        }
    return node;
    }

    
    void insert(struct node *r, int k) {
    struct node *tempNode = (struct node*) malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;
    tempNode->right = NULL;
    tempNode->left = NULL;
    tempNode->k = k;

    
    if(r == NULL) {
        r = tempNode;
    } else {
        current = r;
        parent = NULL;

        while(1) {                
            parent = current;
                
            
            if(k < parent->k) {
                current = current->left;                
                
                    
                if(current == NULL) {
                parent->left= tempNode;
                return;
                }
            }  
            else {
                current = current->right;
                
            
                if(current == NULL) {
                parent->right = tempNode;
                return;
                }
            }
        }            
    }
    }




 void search(struct node *p)
{
    int value;
    printf("Enter value to search: ");
    scanf("%d", &value);
    if (value == p->k)
    {
        printf("**");
        printf("It is a root node\n");
        printf("**");
        printf("Element: %d\n", p->k);
        if (p->left != NULL)
        {
            printf("Left child: %d\n", p->left->k);
        }
        else
        {
            printf("No Left child\n");
            printf("**");
        }

        if (p->right != NULL)
        {
            printf("Right child: %d\n", p->right->k);
            printf("**");
        }
        else
        {
            printf("No Right child\n");
            printf("**");
        }
    }
    
    else if (value < p->k || value > p->k)
    {
        struct node *r = NULL;
        while (p != NULL)
        {
            r = p;
            if (value > p->k)
            {
                p = p->right;
            }
            else if (value < p->k)
            {
                p = p->left;
            }
            else
            {
                return;
            }
        }
        
        if (value == r->k)
        {
            printf("Element: %d", r->k);
            printf("**");
            if (r->left != NULL)
            {
                printf("Left child: %d", r->left->k);
                printf("**");
            }
            else
            {
                printf("No Left child");
                printf("**");
            }
            if (r->right != NULL)
            {
                printf("Right child: %d", r->right->k);
            }
            else
            {
                printf("No Right child");
                printf("**");
            }
        }
        else
        {
            printf("Element dosen't exist");
            printf("**");
        }
    }
}
    int main() 
    {
        struct node *r = NULL;
        r = insertion(r, 8);
        r = insertion(r, 10);
        r = insertion(r, 9);
        r = insertion(r, 5);
        r = insertion(r, 2);
        r = insertion(r, 7);
        r = insertion(r, 1);
        r = insertion(r, 6);
        r = insertion(r, 3);
        r = insertion(r, 4);
        printf("\n\n");
        printf("*****************\n");
        printf("BST Formed: \n");
        inorder(r);
        printf("\n");
        int choice=0;
        while(choice!=4)
        {
            printf("\n");
            
            printf("Enter choice: \n");
            printf("1. Deletion\n2. Search\n3. Insertion\n4. Exit");
            int ch;
            printf("\n");
            scanf("%d",&ch);
                switch(ch)
                {
                    case 1:
                    printf("Enter number to be deleted: ");
                    int num;
                    scanf("%d",&num);
                    printf("\nAfter deleting : \n");
                    
                    inorder(r);
                    printf("\n");
                    
                    break;
                    case 2:
                    search(r);
                    printf("\n");
                    break;
                    case 3:
                     printf("Enter number to be inserted: ");
                    int nu;
                    scanf("%d",&nu);
                    
                    insert(r,nu);
                    inorder(r);
                    printf("\n");
                    break;
                    case 4:
                    printf("****END****");
                    exit(0);
                    break;
                    default: printf("Invalid choice.");
                }

            }
        }