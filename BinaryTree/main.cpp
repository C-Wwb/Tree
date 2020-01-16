#include <iostream>
#include <stack>

using namespace std;
typedef struct Node{
    char data;//结点里存的信息
    struct Node* lchild,*rchild;//创建左右孩子
}
Tree;
Tree* createBinTree(){//创建一个二叉树
    char ch;
    Tree* root;//树根
    if ((ch = getchar()) != '#'){//以“#”做结
        root = (Tree*)malloc(sizeof(Tree));//创建一个节点
        if (root == NULL){//判断根节点是否为空，若根节点为空，返回空；若根节点不为空输出根节点
            return NULL;
        }
        root->data = ch;
        root->lchild = createBinTree();
        root->rchild = createBinTree();
    }
    else{
        return NULL;
    }
    return root;
}
void createBinTree(Tree* &t){
    char ch;
    if ((ch = getchar()) != '#'){
        t = (Tree*)malloc(sizeof(Tree));//创建一个节点
        t->data = ch;
        createBinTree(t->lchild);
        createBinTree(t->rchild);
    }
    else{
        t = NULL;
    }
}
void preOrderTraverse(Tree* &t){//前序遍历根左右,递归算法
    if (t != NULL){
        cout << t->data;
        preOrderTraverse(t->lchild);//先访问根节点，再遍历左孩子
        preOrderTraverse(t->rchild);//最后遍历右孩子
    }
}
void preOrderTraverseNonRecur(Tree* t){//非递归算法
    stack<Tree*> stack;
    Tree* p = t;
    while (p != NULL || !stack.empty()){//有根节点且堆栈不为空，先将头节点压入堆栈
        while (p != NULL){//有根节点时，先把根节点的左孩子压入堆栈
            cout << p->data << " ";
            stack.push(p);
            p = p->lchild;
        }
        if (!stack.empty()){//当堆栈不为空时，先把栈顶孩子弹出，并打印，若栈顶孩子的右孩子不为空，再把右孩子压入堆栈
            p = stack.top();//如果栈顶孩子的左孩子不为空，则将左孩子压入堆栈中
            stack.pop();
            p = p->rchild;
        }
    }
}
void ExchangeTree(Tree* t)//交换二叉树的左右子树
{
    if (t == NULL)
    {
        return;
    }
    swap((t)->lchild, (t)->rchild);//直接用swap函数交换根节点的左右孩子
    ExchangeTree(t->lchild);
    ExchangeTree(t->rchild);
}
int main(){
    Tree* t = NULL;
    createBinTree(t);
    cout << "Preorder Traversal: ";
    preOrderTraverseNonRecur(t);
    cout << "\nExchanged Preorder Traversal: ";
    ExchangeTree(t);
    preOrderTraverseNonRecur(t);
}

