#include <iostream>
#include <vector>
#include <stack>
#include <deque>
#include <queue>
using namespace std;

//  ���Կ���
#ifdef DEBUG

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain




//#define __ISFIRST_FOR_POSTPRDER



class TreeNode
{
public :
    int val;
    TreeNode *left;
    TreeNode *right;
#ifdef __ISFIRST_FOR_POSTPRDER
    int    isFirst;          //  �ǵݹ���������б������Ƿ��״α�����


#endif // __ISFIRST_FOR_POSTPRDER

    TreeNode(int x)
    : val(x), left(NULL), right(NULL)
    {   
    }

    static void PreOrder(TreeNode *root);
    static void PreOrderDev(TreeNode *root);
    static void PreOrderDFS(TreeNode *root);

    static void InOrder(TreeNode *root);
    static void InOrderDev(TreeNode *root);

    static void PostOrder(TreeNode *root);
    static void PostOrderDev(TreeNode *root);

    static int  PrintLevel(TreeNode *root, int level = 0);
    static void LevelOrder(TreeNode *root);
    static void LevelOrderDev(TreeNode *root);
    static void LevelOrderUsePoint(TreeNode *root);
    static void LevelOrderUseSize(TreeNode *root);
    static void LevelOrderUseEnd(TreeNode *root);


};

//
void TreeNode::PreOrder(TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    cout <<root->val;
    PreOrder(root->left);
    PreOrder(root->right);
}

void TreeNode::InOrder(TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    InOrder(root->left);
    cout <<root->val;
    InOrder(root->right);
}

void TreeNode::PostOrder(TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout <<root->val;
}

//    �ǵݹ�ʵ��
//
//    ����ǰ��������ʵ�˳�����ȷ��ʸ���㣬Ȼ���ٷֱ�������Ӻ��Һ��ӡ�
//
//    ��������һ��㣬��ɿ����Ǹ���㣬��˿���ֱ�ӷ��ʣ�������֮���������Ӳ�Ϊ�գ�����ͬ�������������������
//    ��������������ʱ���ٷ�������������������䴦��������£�
//
//     ������һ���P��
//
//     1)���ʽ��P���������P��ջ;
//
//     2)�жϽ��P�������Ƿ�Ϊ�գ���Ϊ�գ���ȡջ����㲢���г�ջ����������ջ�������Һ�����Ϊ��ǰ�Ľ��P��ѭ����1);����Ϊ�գ���P��������Ϊ��ǰ�Ľ��P;
//
//     3)ֱ��PΪNULL����ջΪ�գ������������
void TreeNode::PreOrderDev(TreeNode *root)
{
    if(root == NULL)
    {
        debug <<"The tree is NULL..." <<endl;
    }

    stack<TreeNode *> nstack;


    TreeNode *node = root;
    //  ��ʼ��������������
    while(node != NULL || nstack.empty( ) != true)
    {
        //  �����ǰ�����ĸ��ڵ㣬Ȼ��ݹ�ֱ������
        while(node != NULL)
        {
            cout <<node->val;
            nstack.push(node);
            node = node->left;
        }

        //  ��ʱѭ������ʱ����ǰջ���ڵ��Ѿ�������ڵ�
        //  ��ʱ�ݹ鿪ʼ���أ���ʼ��ջ��������ڵ���ҽڵ�
        if(nstack.empty() != true)
        {
            node = nstack.top( );
            nstack.pop( );
            node = node->right;
        }
    }
}

//
//  ǰ������ķ�������������ջ�����ԣ����Ǵ˷�����ͨ��
//  �˹����൱��һ��������ȱ���
//
void TreeNode::PreOrderDFS(TreeNode *root)
{
    if(root == NULL)
    {
        return;
    }
    stack<TreeNode *> nstack;
    nstack.push(root);

    TreeNode *node = root;
    while(nstack.empty() != true)
    {
        node = nstack.top( );
        nstack.pop( );
        cout <<node->val;

        if(node->right != NULL)
        {
            nstack.push(node->right);
        }
        if(node->left != NULL)
        {
            nstack.push(node->left);
        }
    }
}

//  ������ǰ�����������
//  ǰ���ڵݹ��������ʱ��ͻ�����ݹ�Ľڵ�, ������������Ȼ������
//  ���������ڵݹ�������ʱ����ջʱ�����, �������������������
void TreeNode::InOrderDev(TreeNode *root)
{
    if(root == NULL)
    {
        debug <<"The tree is NULL..." <<endl;
    }

    stack<TreeNode *> nstack;
    TreeNode *node = root;

    //  ��ʼ��������������
    while(node != NULL || nstack.empty() != true)
    {
        // �������ǰ���ڵ㣬���ǵݹ�ֱ����ǰ���ڵ�node�������
        while(node != NULL)
        {
            nstack.push(node);
            node = node->left;
        }

        //  ��ʱջ����Ԫ���ǵ�ǰ����Ԫ��
        //  ��Ӧ�ñ����
        if(nstack.empty( ) != true)
        {
            node = nstack.top( );
            cout <<node->val;
            nstack.pop( );
            node = node->right;
        }
    }
}


#ifdef __ISFIRST_FOR_POSTPRDER
//  ������һ���P��������ջ��
//  Ȼ������������һֱ����������ֱ��������û�����ӵĽ�㣬
//  ��ʱ�ý�������ջ�������Ǵ�ʱ���ܽ����ջ�����ʣ�������Һ��ӻ�Ϊ�����ʡ�
//
//  ���Խ�����������ͬ�Ĺ������������������ͬ�Ĵ��������������Һ���ʱ���ý���ֳ�����ջ����
//  ��ʱ���Խ����ջ�����ʡ������ͱ�֤����ȷ�ķ���˳��
//  ���Կ���������������У�ÿ����㶼���γ�����ջ����ֻ���ڵڶ��γ�����ջ��ʱ�����ܷ������������Ҫ������һ��������ʶ�ý���Ƿ��ǵ�һ�γ�����ջ����
void TreeNode::PostOrderDev(TreeNode *root)
{
    if(root == NULL)
    {
        debug <<"The tree is NULL..." <<endl;
    }

    stack<TreeNode *> nstack;
    TreeNode *node = root;

    while(node != NULL || nstack.empty( ) != true)
    {
        //  ����ֱ������ڵ�
        while(node != NULL)
        {
            node->isFirst = 1;       // ��ǰ�ڵ��״α�����
            nstack.push(node);
            node = node->left;

        }

        if(nstack.empty() != true)
        {
            node = nstack.top( );
            nstack.pop( );

            if(node->isFirst == 1)   // ��һ�γ�����ջ��
            {
                node->isFirst++;
                nstack.push(node);

                node = node->right;
            }
            else if(node->isFirst == 2)
            {
                cout <<node->val;
                node = NULL;
            }
        }
    }
}
#else           //
void TreeNode::PostOrderDev(TreeNode *root)
{
    if(root == NULL)
    {
        debug <<"The tree is NULL..." <<endl;
    }
    stack<TreeNode *> nstack;

    TreeNode *cur;                      //��ǰ���
    TreeNode *pre = NULL;                 //ǰһ�η��ʵĽ��
    nstack.push(root);

    while(nstack.empty( ) != true)
    {
        cur = nstack.top( );

        if((cur->left == NULL && cur->right == NULL)                     //  ���һ��Ǿ�ΪNULL, ���Ա����
        || (pre != NULL && ((pre == cur->left /*&& cur->right == NULL*/) || pre == cur->right)))     //  ���һ��Ǳ������, �ݹ鷵��
        //  ��ʵ��ǰ�ڵ�Ҫ���뱻���, Ҫô
        //  1--�����Һ��Ӿ�ΪNULL
        //  2--�����Ӹձ�����������Һ���ΪNULL
        //  3--���Һ��Ӹձ����
        //
        //  ����������һ���Ż�, ��ջʱ��, ���Ǹ���ջ�� Ȼ�����Һ���, Ȼ��������,
        //  ��˵���Ԫ��λ��ջ����ʱ��, �����Һ��ӱ�Ȼ�Ѿ��������������,
        //  Ҳ����˵, ��ǰ
        {
            cout<<cur->val;  //�����ǰ���û�к��ӽ����ߺ��ӽڵ㶼�ѱ����ʹ�
            nstack.pop( );
            pre = cur;
        }
        else
        {
            // ����ջ���Ƚ����������������, �����ӿ��Ա�֤�ݹ鷵��ʱ�ȱ�������
            if(cur->right != NULL)
            {
                nstack.push(cur->right);
            }

            if(cur->left != NULL)
            {
                nstack.push(cur->left);
            }
        }
    }
}
#endif // __ISFIRST_FOR_POSTPRDER




int TreeNode::PrintLevel(TreeNode *root, int level)
{
    if(root == NULL || level < 0)
    {
        return 0;
    }
    else if(level == 0)
    {
        cout <<root->val;
        return 1;
    }
    else
    {
        return PrintLevel(root->left, level - 1) + PrintLevel(root->right, level - 1);
    }
}

void TreeNode::LevelOrder(TreeNode *root)
{
    for(int level = 0; ; level++)
    {
        if(PrintLevel(root, level) == 0)
        {
            break;
        }
        cout <<endl;
    }
}

void TreeNode::LevelOrderDev(TreeNode *root)
{
    /// deque˫�˶��У�
    /// ֧�ֵ���������push_back()������
    /// ��vector��࣬��vector���˸�pop_front,push_front����

    deque<TreeNode *> qFirst, qSecond;
    qFirst.push_back(root);

    while(qFirst.empty( ) != true)
    {
        while (qFirst.empty( ) != true)
        {
            TreeNode *temp = qFirst.front( );
            qFirst.pop_front( );

            cout << temp->val;

            if (temp->left != NULL)
            {
                qSecond.push_back(temp->left);
            }
            if (temp->right != NULL)
            {
                qSecond.push_back(temp->right);
            }
        }
        cout << endl;
        qFirst.swap(qSecond);

    }
}


void TreeNode::LevelOrderUsePoint(TreeNode *root)
{
    vector<TreeNode*> vec;
    vec.push_back(root);

    int cur = 0;
    int end = 1;

    while (cur < vec.size())
    {
        end = vec.size();       ///  �µ�һ�з��ʿ�ʼ�����¶�λlast�ڵ�ǰ�����һ���ڵ����һ��λ��

        while (cur < end)
        {
            cout << vec[cur]->val;  ///  ���ʽڵ�

            if (vec[cur]->left != NULL) ///  ѹ����ڵ�
            {
                vec.push_back(vec[cur]->left);

            }
            if (vec[cur]->right != NULL)    ///  ѹ���ҽڵ�
            {
                vec.push_back(vec[cur]->right);
            }
            cur++;
        }
        cout << endl;
    }
}

void TreeNode::LevelOrderUseSize(TreeNode *root)
{
    int parentSize = 1, childSize = 0;
    TreeNode *temp = NULL;

    queue<TreeNode *> q;
    q.push(root);
    while(q.empty( ) != true)
    {
        temp = q.front( );
        cout <<temp->val;

        q.pop( );

        if (temp->left != NULL)
        {
            q.push(temp->left);

            childSize++;
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
            childSize++;
        }

        parentSize--;
        if (parentSize == 0)
        {
            parentSize = childSize;
            childSize = 0;
            cout << endl;
        }

    }
}

void TreeNode::LevelOrderUseEnd(TreeNode *root)
{
    queue<TreeNode *> q;

    q.push(root);
    q.push(NULL);

    while(q.empty( ) != true)
    {
        TreeNode* node = q.front();
        q.pop();

        if (node)
        {
            cout << node->val;

            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        else if (q.empty( ) != true)
        {
            q.push(NULL);
            cout << endl;
        }
    }
}


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in)
    {
        //  ǰ������ĳ��ȸ���������ĳ���Ӧ����ͬ
        if(pre.size( ) != in.size( ))
        {
            debug <<"the length of PRE and IN should be smae" <<endl;
            return NULL;
        }

        // ���Ȳ���Ϊ0
        int size = pre.size( );
        if(size == 0)
        {
            debug <<"it's a NULL tree(length = 0)" <<endl;
            return NULL;
        }

        int length = pre.size( );
        debug <<"the length of your tree = " <<length <<endl;
        int value = pre[0];      //  ǰ������ĵ�һ������Ǹ��ڵ�
        TreeNode *root = new TreeNode(value);

        debug <<"the root is" <<root->val <<endl;
        //  ����������в��ҵ�����λ��
        int rootIndex = 0;
        for(rootIndex = 0; rootIndex < length; rootIndex++)
        {
            if(in[rootIndex] == value)
            {
                debug <<"find the root at " <<rootIndex <<" in IN" <<endl;
                break;
            }
        }
        if(rootIndex >= length)
        {
            debug <<"can't find root (value = " <<value <<") in IN" <<endl;
            return NULL;
        }

        ///  ������������������
        ///  ���������, ����ߵľ���������, �ұߵľ���������
        ///  ǰ�������, ���������ȱ���������, Ȼ����������

        ///  ����ȷ�����������ĳ���, ���������in��ȷ��
        int leftLength = rootIndex;
        int rightLength = length - 1 - rootIndex;
        debug <<"left length = " <<leftLength <<", rightLength = " <<rightLength <<endl;
        vector<int> preLeft(leftLength), inLeft(leftLength);
        vector<int> preRight(rightLength), inRight(rightLength);
        for(int i = 0; i < length; i++)
        {
            if(i < rootIndex)
            {
                //  ǰ������ĵ�һ���Ǹ��ڵ�, �������(leftLegnth = rootIndex) - 1���ڵ���������, �����i+1
                preLeft[i] = pre[i + 1];
                //  �������ǰ(leftLength = rootIndex) - 1���ڵ���������, ��rootIndex���ڵ��Ǹ�
                inLeft[i] = in[i];
                debug <<preLeft[i] <<inLeft[i] <<" ";

            }
            else if(i > rootIndex)
            {
                //  ǰ������ĵ�һ���Ǹ��ڵ�, �������(leftLegnth = rootIndex) - 1���ڵ���������, ������������
                preRight[i - rootIndex - 1] = pre[i];
                //  �������ǰ(leftLength = rootIndex) - 1���ڵ���������, ��rootIndex���ڵ��Ǹ�, Ȼ����������
                inRight[i - rootIndex - 1] = in[i];
                debug <<preRight[i - rootIndex - 1] <<inRight[i - rootIndex - 1] <<" ";

            }
        }
        debug <<endl <<"the left tree" <<endl;
        for(int i = 0; i < leftLength; i++)
        {
            debug <<preLeft[i] <<inLeft[i] <<" ";
        }
        debug <<endl;
        debug <<"the right tree" <<endl;
        for(int i = 0; i < rightLength; i++)
        {
            debug <<preRight[i] <<inRight[i] <<" ";
        }
        debug <<endl;


        root->left = reConstructBinaryTree(preLeft, inLeft);
        root->right = reConstructBinaryTree(preRight, inRight);

        return root;
    }

};





int main( )
{
    int pre[] = { 1, 2, 4, 7, 3, 5, 6, 8 };
    int in[] = { 4, 7, 2, 1, 5, 3, 8, 6 };

    vector<int> preOrder(pre, pre + 8);
    vector<int>  inOrder( in,  in + 8);

    Solution solu;
    TreeNode *root = solu.reConstructBinaryTree(preOrder, inOrder);

    cout <<"PreOrder" <<endl;   //  12345678
    TreeNode::PreOrder(root);
    cout <<endl;
    TreeNode::PreOrderDev(root);
    cout <<endl;
    TreeNode::PreOrderDFS(root);
    cout <<endl;

    cout <<"InOrder " <<endl;   //  47215386
    TreeNode::InOrder(root);
    cout <<endl;
    TreeNode::InOrderDev(root);
    cout <<endl;


    cout <<"PostOrder " <<endl; //
    TreeNode::PostOrder(root);
    cout <<endl;
    TreeNode::PostOrderDev(root);
    cout <<endl;


    cout <<"LevelOrder " <<endl;
    TreeNode::LevelOrder(root);
    cout <<endl;
    TreeNode::LevelOrderDev(root);
    cout <<endl;
    TreeNode::LevelOrderUsePoint(root);
    cout <<endl;
    TreeNode::LevelOrderUseSize(root);
    cout <<endl;
    TreeNode::LevelOrderUseEnd(root);
    cout <<endl;

    return 0;
}
