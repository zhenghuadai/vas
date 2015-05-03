/**
 * =====================================================================================
 *       @file    vastree.h
 *
 *       @brief   define the node of gramma tree
 *
 *       @author  DAI ZHENGHUA (), djx.zhenghua@gmail.com
 *       @version 1.0
 *       @date    01/25/2011 09:13:24 PM
 *
 *       Revision none
 *       Compiler gcc
 *       Company  
 * =====================================================================================
 */

#include <iostream>
class node
{
    public:
    private:
        node* prev;
        node* next;
        node* subgraph;
    protected:
        int type;
    public:
};
